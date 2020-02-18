//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

protected mapping environmentalElements = ([
    "terrain":([]),
    "interior": ([]),
    "feature": ([]),
    "building": ([]),
    "item": ([]),
    "door": ([]),
    "objects": ([]),
    "shop": 0,
    "cloned": 0,
    "description": ([]),
    "location text": ({ " is " }),
    "doors": ([]),
    "regions": ([])
]);

private mapping aliasesToElements = ([]);

protected mapping exits = ([]);
private string State = "default";
protected object Region = 0;

private string uniqueIdentifier = 0;
protected int xCoordinate = 0;
protected int yCoordinate = 0;
private nosave string ShortDescription = "";

protected nosave object StateMachine = 0;
protected nosave string StateMachinePath = 0;

private nosave int SetupCompleted = 0;
private int SettlementChance = -1;

protected mapping instances = ([]);

protected object configuration = 
    load_object("/lib/dictionaries/configurationDictionary.c");

protected object StateMachineDictionary = 
    load_object("/lib/dictionaries/stateMachineDictionary.c");

private mapping harvestData = ([]);

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{

}

/////////////////////////////////////////////////////////////////////////////
private object environmentDictionary()
{
    return load_object("/lib/dictionaries/environmentDictionary.c");
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs string currentState(string newState)
{
    if (newState && stringp(newState))
    {
        State = newState;
    }
    return State;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string capitalizeSentences(string message)
{
    string ret = regreplace(message, "^[a-z]", #'upper_case, 1);
        ret = regreplace(ret, "[.!?] +[a-z]", #'upper_case, 1);
            ret = regreplace(ret, "  ", " ");
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask void setUpAliases(string element)
{
    object environmentalObj = environmentDictionary()->environmentalObject(element);
    foreach(string state in environmentalObj->states())
    {
        if (!member(aliasesToElements, state))
        {
            aliasesToElements[state] = ([]);
        }
        foreach(string alias in environmentalObj->aliases(state))
        {
            aliasesToElements[state][alias] = program_name(environmentalObj);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void pruneStateObjects()
{
    if (member(environmentalElements["objects"], currentState()) &&
        sizeof(environmentalElements["objects"][currentState()]))
    {
        foreach(string stateObjectBlueprint in 
            environmentalElements["objects"][currentState()])
        {
            object stateObject = present_clone(stateObjectBlueprint);
            if (stateObject)
            {
                if (StateMachine)
                {
                    StateMachine->unregisterStateActor(stateObject);
                }

                object *stateObjectItems = deep_inventory(stateObject);
                if (sizeof(stateObjectItems))
                {
                    foreach(object item in stateObjectItems)
                    {
                        destruct(item);
                    }
                }
                destruct(stateObject);
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void createStateObjects()
{
    string *stateObjects = ({});
    if (member(environmentalElements["objects"], currentState()) && 
        sizeof(environmentalElements["objects"][currentState()]))
    {
        stateObjects += environmentalElements["objects"][currentState()];
    }
    if (member(environmentalElements["objects"], "default") && 
        sizeof(environmentalElements["objects"]["default"]))
    {
        stateObjects += environmentalElements["objects"]["default"];
    }

    if (sizeof(stateObjects))
    {
        stateObjects = filter(m_indices(mkmapping(stateObjects)),
            (: return !present_clone($1); :));
        foreach(string stateObjectBlueprint in stateObjects)
        {
            object stateObject = clone_object(stateObjectBlueprint);
            if (StateMachine)
            {
                StateMachine->registerStateActor(stateObject);
            }
            move_object(stateObject, this_object());
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public void resetData()
{
    pruneStateObjects();

    environmentalElements = ([
        "terrain":([]),
        "interior" : ([]),
        "feature" : ([]),
        "building" : ([]),
        "item" : ([]),
        "door": ([]),
        "objects" : ([]),
        "shop" : 0,
        "cloned" : 0,
        "description" : ([]),
        "location text" : ({ " is " }),
        "doors" : ([])
    ]);
    aliasesToElements = ([]);
    exits = ([]);
    instances = ([]);

    Setup();
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping getLocation(mixed location)
{
    mapping elementLocation = 0;
    if (stringp(location))
    {
        elementLocation = environmentDictionary()->getLocation(location);
    }
    else if (environmentDictionary()->isValidLocation(location))
    {
        elementLocation = location;
    }

    if(location && !elementLocation)
    {
        raise_error(sprintf("ERROR in environment.c: '%O' is not a valid "
            "location.\n", location));
    }
    return elementLocation;
}

/////////////////////////////////////////////////////////////////////////////
private nomask void addHarvestInformation(object environmentalElement)
{
    string *resources = environmentalElement->harvestableResources();
    if (sizeof(resources))
    {
        foreach(string resource in resources)
        {
            if (!member(harvestData, resource))
            {
                harvestData[resource] = ({});
            }
            harvestData[resource] += ({ environmentalElement });
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask varargs int addEnvironmentalElement(string element, string type, mixed location)
{
    int ret = 1;
    if (!environmentDictionary()->isValidEnvironmentItem(element))
    {
        ret = environmentDictionary()->registerElement(element, type);
        if (ret)
        {
            object elementObj = load_object(element);
            elementObj->setUpForEnvironment(currentState(), this_object());
            addHarvestInformation(elementObj);

            element = elementObj->Name();

            if (location && !elementObj->description())
            {
                raise_error(sprintf("ERROR in environment.c: You cannot specify a "
                    "direction for '%s' as it has no description.\n", element));
            }
        }
        else if(element && (file_size(element) > 0) &&
            environmentDictionary()->isValidEnvironmentItem(load_object(element)->Name(), type))
        {
            raise_error(sprintf("ERROR in environment.c: Unable to register '%s'. "
                "A conflicting item with that name already exists.\n", element));
        }
        else
        {
            raise_error(sprintf("ERROR in environment.c: Unable to register '%s'. "
                "Be sure that the file exists and inherits a valid environmental "
                "element.\n", element));
        }
    }

    ret &&= environmentDictionary()->isValidEnvironmentItem(element, type);
    if (ret)
    {
        if (!member(environmentalElements[type], element))
        {
            environmentalElements[type][element] = ({});
        }

        environmentalElements[type][element] =
            m_indices(mkmapping(environmentalElements[type][element] +
                ({ getLocation(location) }) - ({ 0 })));
        setUpAliases(element);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask varargs void addFeature(string feature, mixed location)
{
    if (!addEnvironmentalElement(feature, "feature", location))
    {
        raise_error(sprintf("ERROR in environment.c: '%s' is not a "
            "valid feature.\n", feature));
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask string environmentName()
{
    return regreplace(object_name(this_object()), "([^#]*)(#[0-9]+|)",
        "/\\1");
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void cloneEnvironment()
{
    environmentalElements["cloned"] = 1;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string cloneOwner()
{
    return member(environmentalElements, "clone owner") ?
        environmentalElements["clone owner"] : 0;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask varargs void addLegacyItem(string item, string description)
{
    if (sizeof(environmentalElements["terrain"]) &&
        member(environmentalElements["terrain"], "legacy"))
    {
        if (!member(aliasesToElements, "default"))
        {
            aliasesToElements["default"] = ([]);
        }
        aliasesToElements["default"][item] = description;
    }
    else
    {
        raise_error("ERROR in environment.c: addLegacyItem is only "
            "usable when the terrain is in legacy mode.\n");
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask varargs void addItem(string item, mixed location)
{
    if (!addEnvironmentalElement(item, "item", location))
    {
        raise_error(sprintf("ERROR in environment.c: '%s' is not a "
            "valid item.\n", item));
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void addShop(string shop)
{
    object dictionary = load_object("/lib/dictionaries/shopDictionary.c");
    object shopObj = dictionary->getShopObject(shop);
    if (shopObj)
    {
        if (!environmentalElements["shop"])
        {
            shopObj->Setup();
            dictionary->generateInventory(shopObj);
            environmentalElements["shop"] = shopObj;
        }
        else
        {
            raise_error("ERROR in environment.c: a shop has already been "
                "assigned to this environment.\n");
        }
    }
    else
    {
        raise_error(sprintf("ERROR in environment.c: '%s' is not a "
            "valid shop.\n", shop));
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask object getShop()
{
    return environmentalElements["shop"];
}

/////////////////////////////////////////////////////////////////////////////
protected nomask varargs void addObject(string file, string state)
{
    if (!state)
    {
        state = "default";
    }

    if (stringp(file) && (file_size(file) > 0))
    {
        if (!member(environmentalElements["objects"], state))
        {
            environmentalElements["objects"][state] = ({});
        }
        environmentalElements["objects"][state] += ({ file });
    }
    else
    {
        raise_error(sprintf("ERROR in environment.c: '%s' is not a "
            "valid file.\n", file));
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask varargs void addExit(string direction, string path, string state)
{
    if (!state)
    {
        state = "default";
    }
    if (!stringp(direction) || !stringp(path))
    {
        raise_error(sprintf("ERROR in environment.c: '%s' must be a string and "
            "'%s' must be a valid destination file.\n", to_string(direction),
            to_string(path)));
    }
    if (!member(exits, state))
    {
        exits[state] = ([]);
    }
    exits[state][direction] = path;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask varargs void addGeneratedExit(string direction, string location, 
    object region, string state)
{
    if (!state)
    {
        state = "default";
    }
    if (!stringp(direction) || !stringp(location) || !objectp(region))
    {
        raise_error(sprintf("ERROR in environment.c: '%s' must be a string, "
            "'%s' must be a valid destination, and '%s' must be a valid "
            "object.\n", to_string(direction), to_string(location),
            object_name(region)));
    }
    if (!member(exits, state))
    {
        exits[state] = ([]);
    }

    exits[state][direction] = ([
        "destination": location,
        "region": region
    ]);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setIdentifier(string newIdentifier)
{
    uniqueIdentifier = newIdentifier;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string identifiedBy()
{
    return uniqueIdentifier ? uniqueIdentifier :
        sprintf("%s-%s", object_name(this_object()), currentState());
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setGeneratedSettlementChance(int chance)
{
    SettlementChance = chance;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs object addGeneratedRegion(string direction, string type,
    int x, int y, int *entryCoordinate, string name, string state)
{
    object ret = 0;
    if (!member(environmentalElements["regions"], direction))
    {
        ret = clone_object("/lib/environment/region.c");

        if (SettlementChance >= 0)
        {
            ret->setSettlementChance(SettlementChance);
        }

        if (x && y)
        {
            ret->setDimensions(x, y);
        }

        ret->setRegionName(name ? name : 
            sprintf("%s-%s", identifiedBy(), direction));

        ret->setRegionType(type);

        ret->createRegion(ret->getEnterFromDirection(direction),
            regreplace(object_name(this_object()), "([^#]+)#*.*", "/\\1.c", 1),
            entryCoordinate);

        addGeneratedExit(direction, ret->getEntryCoordinates(), ret, state);

        environmentalElements["regions"][direction] = ret;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask void addDoor(string direction, string path, string door, 
    string key, string state)
{
    if (!stringp(door))
    {
        door = "/lib/environment/doors/door.c";
    }

    object doorObj = environmentDictionary()->getDoor(door);
    if (doorObj)
    {
        if (!member(environmentalElements["doors"], state))
        {
            environmentalElements["doors"][state] = ([]);
        }
        environmentalElements["doors"][state][path] = doorObj;
        if (environmentDictionary()->isValidKey(key))
        {
            doorObj->setKey(key);
        }

        if (!addEnvironmentalElement(door, "door", direction))
        {
            raise_error(sprintf("ERROR in environment.c: '%s' is not a "
                "valid door.\n", door));
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask varargs void addExitWithDoor(string direction, string path, 
    string door, string key, string state)
{
    if (!state)
    {
        state = "default";
    }

    addExit(direction, path, state);
    addDoor(direction, path, door, key, state);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask varargs void addGeneratedExitWithDoor(string direction, 
    string location, object region, string door, string key, string state)
{
    if (!state)
    {
        state = "default";
    }

    addGeneratedExit(direction, location, region, state);
    addDoor(direction, location, door, key, state);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask varargs void addBuilding(string feature, mixed location, 
    string path, string state)
{
    if (addEnvironmentalElement(feature, "building", location) && stringp(location))
    {
        if (stringp(path))
        {
            addExit(location, path, state);
        }
    }
    else
    {
        raise_error(sprintf("ERROR in environment.c: '%s' is not a "
            "valid building with a valid location.\n", feature));
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask varargs void addBuildingWithDoor(string feature, mixed location,
    string path, string door, string key, string state)
{
    addBuilding(feature, location, path, state);
    addExitWithDoor(location, path, door, key, state);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask varargs void addGeneratedBuilding(string feature, mixed location,
    string path, object region, string door, string key, string state)
{
    if (addEnvironmentalElement(feature, "building", location) && 
        stringp(location))
    {
        if (stringp(path))
        {
            addGeneratedExitWithDoor(location, path, region, door, key, state);
        }
    }
    else
    {
        raise_error(sprintf("ERROR in environment.c: '%s' is not a "
            "valid building with a valid location.\n", feature));
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setTerrain(string terrain)
{
    if (sizeof(environmentalElements["terrain"]) ||
        sizeof(environmentalElements["interior"]))
    {
        raise_error("ERROR in environment.c: Only one terrain OR one "
            "interior can be set.\n");
    }
    else if (!addEnvironmentalElement(terrain, "terrain", "none"))
    {
        raise_error(sprintf("ERROR in environment.c: '%s' is not a "
            "valid terrain.\n", terrain));
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setInterior(string interior)
{
    if (sizeof(environmentalElements["terrain"]) ||
        sizeof(environmentalElements["interior"]))
    {
        raise_error("ERROR in environment.c: Only one terrain OR one "
            "interior can be set.\n");
    }
    else if (!addEnvironmentalElement(interior, "interior", "none"))
    {
        raise_error(sprintf("ERROR in environment.c: '%s' is not a "
            "valid interior.\n", interior));
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask string getCoordinates()
{
    return sprintf("%dx%d", xCoordinate, yCoordinate);
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs mapping getExitDirections()
{
    return exits + ([ ]);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setCoordinates(object region, int x, int y)
{
    if (objectp(region) && 
        (member(inherit_list(region), "lib/environment/region.c") > -1))
    {
        Region = region;
        xCoordinate = x;
        yCoordinate = y;
    }
    else
    {
        raise_error("ERROR in environment.c: You must specify a valid region "
            "when setting coordinates.\n");
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask varargs void setAdditionalLongDescription(
    string description, string state)
{
    if (!state)
    {
        state = "default";
    }

    if (stringp(description))
    {
        environmentalElements["description"][state] = description;
    }
    else
    {
        raise_error("ERROR in environment.c: The description must be a string.\n");
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask string parseEfunCall(string match)
{
    string ret = "ERROR";
    // This match was found to be of the form efun::type::obj::function
    // the only supported efun right now is call_other
    // type can be any of: room, key (present object), OR filename.
    // obj is either this OR a file path.
    // function is a method on the called object. That method MUST return a
    // string. 
    match = regreplace(match, "\n", "", 1);

    string *arguments = explode(match, "::");
    if (sizeof(arguments) >= 4)
    {
        switch (arguments[0])
        {
            case "##call_other":
            {
                switch (arguments[1])
                {
                    case "key":
                    {
                        object stateObj = present_clone(arguments[2]);
                        if (stateObj)
                        {
                            ret = call_other(stateObj, arguments[3]) + "\x1b[0;33m";
                        }
                        else
                        {
                            ret = "";
                        }
                        break;
                    }
                    case "filename":
                    {
                        if (file_size(arguments[2]) > 0)
                        {
                            ret = call_other(arguments[2], arguments[3]) + "\x1b[0;33m";
                        }
                        break;
                    }
                    case "room":
                    {
                        ret = call_other(this_object(), arguments[3]) + "\x1b[0;33m";
                        break;
                    }
                    default:
                    {
                        break;
                    }
                }
                break;
            }
            default:
            {
                break;
            }
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private string getlocationText()
{
    return environmentalElements["location text"][
        random(sizeof(environmentalElements["location text"]))];
}

/////////////////////////////////////////////////////////////////////////////
private string getElementDescriptions(string type, int illuminationLevel)
{
    string ret = "";

    if (member(environmentalElements, type) &&
        sizeof(environmentalElements[type]))
    {
        string *elements = sort_array(
            m_indices(environmentalElements[type]), (: $1 > $2 :));
        foreach(string element in elements)
        {
            string directions = "";

            if (sizeof(environmentalElements[type][element]))
            {
                string *locations = ({});
                foreach(mapping location in environmentalElements[type][element])
                {
                    locations += ({ location["description"] });
                }
                directions = " to the " + 
                    implode(sort_array(locations,
                        (: $1 > $2 :)), ", ");
                directions = regreplace(directions, ",([^,]+)$", " and\\1");
            }

            object elementObj = 
                environmentDictionary()->environmentalObject(element);
            if (elementObj)
            {
                string elementDescription =
                    elementObj->description(currentState(), illuminationLevel,
                        this_object());

                if (elementDescription && (elementDescription != ""))
                {
                    ret += directions +
                        (elementObj->displayActionText() ? getlocationText() : " ") +
                        elementDescription + ".";
                }
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private varargs string getBaseDescriptionForType(string type, 
    int illuminationLevel, int doNotRecurse)
{
    string ret = 0;
    if (member(environmentalElements, type) && sizeof(environmentalElements[type]))
    {
        string element = m_indices(environmentalElements[type])[0];
        object base = environmentDictionary()->environmentalObject(element);
        if (base)
        {
            ret = base->description(currentState(), illuminationLevel,
                this_object());
        }
        else if (!doNotRecurse)
        {
            // This will re-load the environment's data in the event that
            // the dictionary has been reset.
            resetData();
            ret = getBaseDescriptionForType(type, illuminationLevel, 1);
        }
        else
        {
            raise_error(sprintf("ERROR in environment.c: Failed to load "
                "%s '%s'.\n", type, element));
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private string getExitDescription(object viewer)
{
    string ret = "";

    string *exitList = ({});
   
    if (member(exits, currentState()))
    {
        exitList += m_indices(exits[currentState()]);
    }
    if (member(exits, "default"))
    {
        exitList += m_indices(exits["default"]);
    }
    exitList = sort_array(m_indices(mkmapping(exitList)), (: $1 > $2 :));

    int showUnicode = viewer ?
        viewer->charsetConfiguration() == "unicode" : 0;
    string colorConfiguration = viewer ?
        viewer->colorConfiguration() : "none";

    int numExits = sizeof(exitList);

    ret = configuration->decorate(sprintf(" %s There %s %s obvious exit%s%s %s\n",
        (showUnicode ? "\xe2\x95\x98\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x9b" : 
            "-=-=-"), numExits == 1 ? "is" : "are",
        environmentDictionary()->convertNumberToString(numExits),
        (numExits == 1 ? "" : "s"), (numExits ? ":" : "."),
        implode(exitList, ", ")),
        "exits", "environment", colorConfiguration);

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private string getInventoryDescription(int illuminationLevel, object viewer)
{
    string ret = "";
    object *environmentInventory = all_inventory(this_object());
    if (sizeof(environmentInventory))
    {
        string colorConfiguration = viewer ?
            viewer->colorConfiguration() : "none";

        object *infraInventory = ({});
        if ((illuminationLevel < 7) && viewer &&
            viewer->hasTraitOfRoot("infravision"))
        {
            infraInventory = filter(environmentInventory,
                (: $1->isRealizationOfLiving() &&
                    !$1->hasTraitOfRoot("ethereal") &&
                    !$1->hasTraitOfRoot("undead") :));

            environmentInventory -= ({ viewer });
            infraInventory -= ({ viewer });

            if (sizeof(infraInventory))
            {
                ret += configuration->decorate(
                    "You can see objects faintly glowing in red:",
                    "infravision", "environment", colorConfiguration) + "\n";
            }
        }
        foreach(object environmentItem in environmentInventory)
        {
            string shortDesc = environmentItem->short();
            if (shortDesc && (shortDesc != "") && 
                (environmentItem != this_player()))
            {
                ret += configuration->decorate(capitalize(shortDesc),
                    ((member(infraInventory, environmentItem) > -1) ? 
                        "infravision": "inventory"), 
                    "environment", colorConfiguration) + "\n";
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public void setShortDescription(string newShort)
{
    ShortDescription = newShort;
}

/////////////////////////////////////////////////////////////////////////////
public string short()
{
    return (ShortDescription != "") ? ShortDescription : 
        regreplace(program_name(this_object()), ".*/([^./]+).c$", "\\1", 1);
}

/////////////////////////////////////////////////////////////////////////////
private nomask int getElementLighting()
{
    int ret = 0;

    foreach(string elementType in({ "terrain", "feature", "building", 
        "item", "door" }))
    {
        if (sizeof(environmentalElements[elementType]))
        {
            string *elements = m_indices(environmentalElements[elementType]);
            foreach(string element in elements)
            {
                object elementObj =
                    environmentDictionary()->environmentalObject(element);
                if (elementObj)
                {
                    ret += elementObj->isSourceOfLight(currentState(),
                        this_object());
                }
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected int alwaysLight()
{
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int minimumNeededLightLevel()
{
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isIlluminated()
{
    int ret = alwaysLight();
    if (!ret)
    {
        ret = sizeof(environmentalElements["terrain"]) ?
            environmentDictionary()->ambientLight() : 0;

        int otherLight = getElementLighting();
        if (otherLight > ret)
        {
            ret = otherLight;
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask object getRegion()
{
    return Region;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string displayMap(string description, string *map,
    string colorConfiguration)
{
    string ret = "";
    string *splitDesc = explode(description, "\n");

    int shortest = sizeof(map) < sizeof(splitDesc) ? 
        sizeof(map) : sizeof(splitDesc);

    int count = 0;
    for (int i = 0; i < shortest; i++)
    {
        ret += map[i] + " " + 
            configuration->decorate(splitDesc[i],
                "description", "environment", colorConfiguration) + "\n";
        count++;
    }

    if (sizeof(map) > sizeof(splitDesc))
    {
        ret += implode(map[count..(sizeof(map) - 1)], "\n");
    }
    else
    {
        for (int i = count; i < sizeof(splitDesc); i++)
        {
            ret += sprintf("%18s %s\n", "", 
                configuration->decorate(splitDesc[i],
                    "description", "environment", colorConfiguration));
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string displayLongDetails(string description, string *map,
    int illuminationLevel, int descriptionWidth,
    string colorConfiguration)
{
    string ret = description;

    ret += getElementDescriptions("feature", illuminationLevel) +
        getElementDescriptions("item", illuminationLevel) +
        getElementDescriptions("building", illuminationLevel) +
        getElementDescriptions("door", illuminationLevel);

    if (member(environmentalElements["description"], currentState()))
    {
        ret += " " + environmentalElements["description"][currentState()];
    }

    ret = regreplace(ret,
        "##([^:]+)::(key|filename|room)::([^:]+)::([a-zA-Z0-9_\n]+)::",
        #'parseEfunCall,1);
    ret = capitalizeSentences(ret);
    ret = format(ret, descriptionWidth);

    if(map)
    {
        ret = displayMap(ret, map, colorConfiguration);
    }
    else
    {
        ret = sprintf(configuration->decorate(ret,
            "description", "environment", colorConfiguration));
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public varargs string long(string item, object viewer)
{
    int illuminationLevel = isIlluminated();
    int descriptionWidth = 78;
    string *map = 0;

    string colorConfiguration = "none";

    if (!viewer)
    {
        viewer = this_player();
    }

    if (viewer)
    {
        colorConfiguration = viewer->colorConfiguration();
        if (viewer->hasTraitOfRoot("darkvision"))
        {
            illuminationLevel = 10;
        }
        if (viewer->displayMiniMap() && getRegion())
        {
            descriptionWidth = 66;
            map = getRegion()->getMiniMap(this_object(), viewer,
                currentState());
        }
    }

    string ret = getBaseDescriptionForType("terrain", illuminationLevel);
    int isOutside = 1;

    if (!ret)
    {
        ret = getBaseDescriptionForType("interior", illuminationLevel);
        isOutside = 0;
    }

    if (ret)
    {
        ret = displayLongDetails(ret, map, illuminationLevel,
            descriptionWidth, colorConfiguration);
    }
    else
    {
        raise_error("ERROR in environment.c: Either a valid terrain or "
            "interior must be set.\n");
    }

    return ret + (isOutside ? 
            environmentDictionary()->timeOfDayMessage(colorConfiguration) :
            "") +
        getExitDescription(viewer) +
        getInventoryDescription(illuminationLevel, viewer) + "\n";
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isEnvironmentalElement(string item)
{
    return member(aliasesToElements, currentState()) &&
        member(aliasesToElements[currentState()], item);
}

/////////////////////////////////////////////////////////////////////////////
public nomask object getEnvironmentalElement(string item)
{
    object ret = 0;

    if (isEnvironmentalElement(item))
    {
        if (sizeof(environmentalElements["terrain"]) &&
            member(environmentalElements["terrain"], "legacy"))
        {
            ret = load_object("/lib/environment/items/legacyItem.c");
            ret->setItemData(item, aliasesToElements["default"][item]);
            ret->currentState("default");
        }
        else
        {
            ret = load_object(aliasesToElements[currentState()][item]);
            ret->currentState(currentState());
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public int id(string item)
{
    return isEnvironmentalElement(item);
}

/////////////////////////////////////////////////////////////////////////////
private nomask int moveToDestination(object player, string direction,
    string destination, object region, string state)
{
    int canMove = 1;
    if (destination)
    {
        object door = 0;
        object originalLocation = environment(this_player());

        if (member(environmentalElements["doors"], state) &&
            member(environmentalElements["doors"][state], destination))
        {
            door = environmentalElements["doors"][state][destination];

            if (door->isLocked())
            {
                canMove = 0;
                door->displayLockedMessage(this_player());
            }
            else
            {
                door->displayMoveMessage(this_player(), direction);
            }
        }

        if (canMove)
        {
            this_player()->move(destination, direction, objectp(door), region);

            object party = this_player()->getParty();
            if (party)
            {
                party->moveFollowers(this_player(), destination, direction, region);
            }

            if (door)
            {
                door->displayOpenMessage(this_player());
                door->displayCloseMessage(this_player(), originalLocation);
            }
        }
    }

    return destination && stringp(destination);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int move(string str)
{
    string direction = query_verb();
    string destination = 0;
    object region = 0;

    string state = currentState();
    if (member(exits, state) && member(exits[state], direction) &&
        stringp(exits[state][direction]))
    {
        destination = exits[state][direction];
    }
    else if (member(exits, state) && member(exits[state], direction) &&
        mappingp(exits[state][direction]))
    {
        destination = exits[state][direction]["destination"];
        region = exits[state][direction]["region"];
    }
    else if (member(exits, "default") && member(exits["default"], direction) &&
        stringp(exits["default"][direction]))
    {
        destination = exits["default"][direction];
        state = "default";
    }
    else if (member(exits, "default") && member(exits["default"], direction) &&
        mappingp(exits["default"][direction]))
    {
        state = "default";
        destination = exits[state][direction]["destination"];
        region = exits[state][direction]["region"];
    }

    return moveToDestination(this_player(), direction, destination, 
        region, state);
}

/////////////////////////////////////////////////////////////////////////////
private nomask void setUpActiveLighting()
{
    int haveActiveLights = 0;
    foreach(string elementType in({ "terrain", "feature", "building", "item" }))
    {
        if (sizeof(environmentalElements[elementType]))
        {
            string *elements = filter(
                m_indices(environmentalElements[elementType]),
                (: $3->environmentalObject($1) &&
                    $3->environmentalObject($1)->canActivateLightSource($2) :),
                currentState(), environmentDictionary());

            haveActiveLights ||= sizeof(elements);
        }
    }

    if(haveActiveLights)
    {
        add_action("activateLights", "light");
        add_action("activateLights", "ignite");
        add_action("deactivateLights", "extinguish");
        add_action("deactivateLights", "put out");
    }
}

/////////////////////////////////////////////////////////////////////////////
protected void setUpEncounter(object player)
{

}

/////////////////////////////////////////////////////////////////////////////
public void init()
{
    if (objectp(this_player()) && present(this_player()))
    {
        if (objectp(StateMachine))
        {
            currentState(StateMachine->getCurrentState());
        }
        if (this_player())
        {
            remove_action(1);
        }
        string *directions = ({});
        if (member(exits, currentState()) && sizeof(exits[currentState()]))
        {
            directions += m_indices(exits[currentState()]);
        }
        if (member(exits, "default") && sizeof(exits["default"]))
        {
            directions += m_indices(exits["default"]);
        }

        if (sizeof(directions))
        {
            directions = m_indices(mkmapping(directions));
            foreach(string direction in directions)
            {
                add_action("move", direction);
            }
        }

        setUpActiveLighting();
        setUpEncounter(this_player());
    }
}

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        if (!SetupCompleted)
        {
            Setup();
            SetupCompleted = 1;
        }

    }
    object shopObj = getShop();
    if (objectp(shopObj))
    {
        shopObj->updateShopInventory();
    }
    createStateObjects();
}

/////////////////////////////////////////////////////////////////////////////
public int moveFromIsAllowed(object user, object fromLocation)
{
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
public int moveToIsAllowed(object user, object toLocation)
{
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string getCloneOwner(object actor, object party)
{
    string owner = party ? party->partyName() : actor->RealName();
    if (!owner)
    {
        owner = "default";
    }
    return owner;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs void setupStateMachine(string owner)
{
    object newSM = StateMachineDictionary->getStateMachine(
        StateMachinePath, owner);

    if (objectp(newSM) && (newSM != StateMachine))
    {
        if (StateMachine)
        {
            StateMachine->unregisterStateActor(this_object());
        }
        StateMachine = newSM;
        StateMachine->registerStateActor(this_object());
        pruneStateObjects();
        currentState(StateMachine->getCurrentState());
        createStateObjects();
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs void enterEnvironment(object actor, object party)
{
    object location = this_object();

    string owner = getCloneOwner(actor, party);
    if (environmentalElements["cloned"])
    {
        if (member(instances, owner) && objectp(instances[owner]))
        {
            location = instances[owner];
        }
        else if(!clonep(this_object()))
        {
            environmentalElements["clone owner"] = owner;
            location = clone_object(object_name(this_object()));
            instances[owner] = location;

            if (Region)
            {
                location->setCoordinates(Region, xCoordinate, yCoordinate);
            }
        }
    }

    if (StateMachinePath)
    {
        location->setupStateMachine(owner);
    }

    move_object(actor, location);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void onStateChanged(object caller, string newState)
{
    if (caller == StateMachine)
    {
        pruneStateObjects();
        currentState(newState);
        init();
        createStateObjects();
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs void setStateMachine(string machinePath, 
    int useSingleStateMachine)
{
    StateMachinePath = machinePath;

    if (useSingleStateMachine)
    {
        setupStateMachine();
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask object stateMachine()
{
    return StateMachine;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string *getActiveLightElements(string filter)
{
    string *ret = ({});
    foreach(string elementType in({ "terrain", "feature", "building", "item" }))
    {
        if (sizeof(environmentalElements[elementType]))
        {
            string *elements = filter(
                m_indices(environmentalElements[elementType]),
                (: ($4->environmentalObject($1) &&
                    $4->environmentalObject($1)->canActivateLightSource($2) &&
                    (!$3 || (member($4->environmentalObject($1)->aliases($2), 
                        $3) > -1))) :),
                currentState(), filter, environmentDictionary());
            if (sizeof(elements))
            {
                ret += elements;
            }
        }
    }
    return sort_array(ret, (: $1 > $2 :));
}

/////////////////////////////////////////////////////////////////////////////
private nomask int displayLightMessage(string *elements, object initiator,
    string messageTemplate)
{
    int ret = 0;

    if (sizeof(elements))
    {
        ret = 1;
        string itemList;
        if (sizeof(elements) > 1)
        {
            itemList = implode(
                elements[0..(sizeof(elements) - 2)], ", ") +
                ((sizeof(elements) == 2) ? " and " : ", and ") +
                elements[sizeof(elements) - 1];
        }
        else
        {
            itemList = elements[0];
        }

        object parser = load_object("/lib/core/messageParser.c");
        parser->displayMessage(messageTemplate + itemList, initiator, 0,
            "action", "environment", 1);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int manipulateLights(string whichLights, string action,
    string verb)
{
    string *activatedItems = ({});
    string *elements = getActiveLightElements(whichLights);

    if (sizeof(elements))
    {
        activatedItems += elements;
        foreach(string element in elements)
        {
            object elementObj =
                environmentDictionary()->environmentalObject(element);

            if (elementObj)
            {
                call_direct(elementObj, sprintf("%sLightSource", action),
                    currentState(), this_object());
            }
        }
    }

    return displayLightMessage(activatedItems, this_player(),
        sprintf("##InitiatorName## ##Infinitive::%s## the following: ", verb));
}

/////////////////////////////////////////////////////////////////////////////
public nomask int activateLights(string whichLights)
{
    return manipulateLights(whichLights, "activate", "light");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int deactivateLights(string whichLights)
{
    return manipulateLights(whichLights, "deactivate", "extinguish");
}

/////////////////////////////////////////////////////////////////////////////
public nomask void addDecorator(string decorator)
{
    environmentalElements["decorator"] = decorator;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string decoratorType()
{
    return member(environmentalElements, "decorator") ?
        environmentalElements["decorator"] : 0;
}

/////////////////////////////////////////////////////////////////////////////
public nomask object harvestResource(string resource)
{
    object ret = 0;

    if (member(harvestData, resource) && sizeof(harvestData[resource]))
    {
        foreach(object element in harvestData[resource])
        {
            if (objectp(element) &&
                element->isHarvestableResource(resource, this_object()))
            {
                ret = element->harvestResource(resource, this_object());
                break;
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string harvestStatistics()
{
    return "";
}
