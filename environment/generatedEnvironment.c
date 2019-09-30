//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

private object regionDictionary = 
    load_object("/lib/dictionaries/regionDictionary.c");

private string *possibleEncounters = ({});
private object *currentEncounters = ({});
private int timeUntilNextEncounter;
private mapping deferredRegion = 0;
private string PathType = 0;

/////////////////////////////////////////////////////////////////////////////
private nomask mapping getElementMapping(string type, string name, 
    string location, mapping element, string state)
{
    object elementObj = load_object(name);
    string elementName = elementObj->Name();

    mapping *instance = filter(element[elementName], 
        (: $1["description"] == $2 :), location);

    return ([ sprintf("%s%s", name, (location ? "," + location : "")) :
    ([
        "type": type,
        "state": state || "default",
        "x-coordinate": instance[0]["x"],
        "y-coordinate": instance[0]["y"],
        "z-coordinate": instance[0]["z"],
        "x-rotation": instance[0]["x-rotation"],
        "y-rotation": instance[0]["y-rotation"],
        "z-rotation": instance[0]["z-rotation"],
    ]) ]);
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping addRandomEnvironmentalElements(mapping elements, 
    string state)
{
    mapping ret = ([]);

    foreach(string feature in m_indices(elements["features"]))
    {
        foreach(string direction in elements["features"][feature])
        {
            addFeature(feature, direction, state);

            ret += getElementMapping("feature", feature, direction,
                 environmentalElements["feature"], state);
        }
    }

    foreach(string item in m_indices(elements["items"]))
    {
        foreach(string direction in elements["items"][item])
        {
            addItem(item, direction, state);

            ret += getElementMapping("item", item, direction,
                 environmentalElements["item"], state);
        }
    }

    if (member(elements, "shop"))
    {
        addShop(elements["shop"]);
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask varargs void addRandomObjects(mapping items, string state)
{
    foreach(string item in m_indices(items))
    {
        addObject(items[item], state);
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask varargs void addRandomCreature(string *creatures, 
    string state)
{
    if (sizeof(creatures))
    {
        possibleEncounters = creatures + ({});
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void addGeneratedExits(mapping exits, object region, 
    string state)
{
    if (mappingp(exits) && sizeof(exits))
    {
        foreach(string direction in m_indices(exits))
        {
            mapping exit = exits[direction];
            PathType = exit["path type"];

            if (member(exit, "building"))
            {
                addGeneratedBuilding(exit["building"], direction,
                    exit["exit to"], region, exit["door"], exit["key"], state);
                addFeature(exit["path type"], direction, state);
            }
            else
            {
                addGeneratedExit(direction, exit["exit to"], region, state);
                addFeature(exit["path type"], direction, state);
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping addGeneratedFeatures(mapping features, object region,
    string state)
{
    mapping ret = ([]);

    if (mappingp(features) && member(features, "features"))
    {
        foreach(string direction in m_indices(features["features"]))
        {
            addFeature(features["features"][direction], direction, state);

            ret += getElementMapping("feature", 
                features["features"][direction],
                direction, 
                environmentalElements["feature"], 
                state);
        }
    }

    if (mappingp(features) && member(features, "buildings"))
    {
        foreach(string direction in m_indices(features["buildings"]))
        {
            addBuilding(features["buildings"][direction], 
                direction,
                regionDictionary->getBuildingEntrance(
                    features["buildings"][direction]), 
                state);

            ret += getElementMapping("building", 
                features["buildings"][direction],
                direction, 
                environmentalElements["building"], 
                state);
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask void deferGenerateRegion(string direction, object region,
    int *entryCoordinate, string exitCoordinate, string name, string state)
{
    deferredRegion = ([
        "direction": direction,
        "type": region->regionType(),
        "x": region->xDimension(),
        "y": region->yDimension(),
        "exit coordinate": exitCoordinate,
        "entry coordinate": entryCoordinate,
        "name": name,
        "state": state,
        "source": region,
    ]);
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs mapping generateEnvironment(mapping data, object region, 
    string state)
{
    mapping ret = ([
        "elements": ([])
    ]);

    if (!state)
    {
        state = "default";
    }

    if (mappingp(data))
    {
        mapping roomData = regionDictionary->generateRoomData(region, data);

        if (roomData)
        {
            Region = region;
            if (member(roomData, "terrain"))
            {
                setTerrain(roomData["terrain"]);

                ret["elements"] += getElementMapping("terrain", 
                    roomData["terrain"], "", environmentalElements["terrain"], 
                    state);
            }
            else
            {
                setInterior(roomData["interior"]);

                ret["elements"] += getElementMapping("interior", 
                    roomData["interior"], "", environmentalElements["interior"],
                    state);
            }

            setCoordinates(region, data["x"], data["y"]);
            addGeneratedExits(roomData["exits"], region, state);

            ret["elements"] += (member(data, "features") || 
                member(data, "buildings")) ?
                addGeneratedFeatures(data, region, state) :
                addRandomEnvironmentalElements(roomData, state);

            addRandomObjects(filter(roomData["room objects"],
                (: $2["type"] == "object"  :)), state);

            addRandomCreature(roomData["creatures"], state);

            if (data["room type"] == "exit")
            {
                deferGenerateRegion(data["exit to"], 
                    region,
                    data["exit coordinates"],
                    data["name"],
                    sprintf("%s-%s-%s", 
                        region->regionName(), 
                        data["name"] || "none",
                        data["exit to"] || "none"),
                    state);

                if (PathType)
                {
                    addFeature(PathType, data["exit to"], state);
                }
            }

            ret["room objects"] = roomData["room objects"];
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void addEntryExit(string direction, string location)
{
    addExit(direction, location);

    if (PathType)
    {
        addFeature(PathType, direction);
    }
}

/////////////////////////////////////////////////////////////////////////////
protected void setUpEncounter(object player)
{
    if (objectp(player) && (time() > timeUntilNextEncounter) && 
        sizeof(possibleEncounters) &&
        !sizeof(filter(currentEncounters, (: (objectp($1) && present($1)) :))))
    {
        timeUntilNextEncounter = time() + 300;

        object personaDictionary = 
            load_object("/lib/dictionaries/personaDictionary.c");

        string name = possibleEncounters[random(sizeof(possibleEncounters))];

        int count = 1;
        if (member(({ "outlaw", "ruffian", "undead", "timber wolf", "gray wolf",
            "red wolf", "coyote", "zombie", "skeleton" }), name) > -1)
        {
            count = 1 + random(3);
        }

        for (int i = 0; i < count; i++)
        {
            object encounter = clone_object("/lib/realizations/monster.c");
            encounter->SetUpPersonaOfLevel(
                personaDictionary->getRandomPersona(name),
                (player->effectiveLevel() - 5 + random(10)), 1);
            encounter->Gender(1 + random(2));
            encounter->addAlias(name);

            if (encounter->Race() == "deity")
            {
                encounter->apparentRace("human");
            }
            string realName = name;
            if (encounter->apparentRace() &&
                (member(({ "outlaw", "ruffian", "skeleton", "zombie" }), name) > -1))
            {
                realName = sprintf("%s (%s)", name, 
                    capitalize(encounter->apparentRace()));
            }
            encounter->Name(realName);
            encounter->addAlias(name);
            encounter->setUpRandomEquipment(5 + (encounter->effectiveLevel() * 3));

            move_object(encounter, this_object());
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public void init()
{
    if (deferredRegion)
    {
        if (this_player())
        {
            tell_object(this_player(), configuration->decorate(
                "Loading a new region into memory. Please wait...\n",
                "exits", "environment", 
                this_player()->colorConfiguration()));
        }
        object previousRegion = deferredRegion["source"];
        string destinationDirection =
            previousRegion->getEnterFromDirection(deferredRegion["direction"]);

        object newRegion = addGeneratedRegion(deferredRegion["direction"],
            deferredRegion["type"],
            deferredRegion["x"],
            deferredRegion["y"],
            deferredRegion["entry coordinate"],
            deferredRegion["name"],
            deferredRegion["state"]);

        newRegion->setEntryExit(deferredRegion["exit coordinate"],
            previousRegion, deferredRegion["state"]);

        newRegion->setPersistRegion(previousRegion->persistRegion());

        deferredRegion = 0;
    }

    "environment"::init();
}

/////////////////////////////////////////////////////////////////////////////
public void updateEntryPoint(string direction, string entryPoint,
    object region, string state)
{
    if (member(exits, state))
    {
        exits[state][direction] = ([
            "region": region,
            "destination": entryPoint
        ]);
    }
}
