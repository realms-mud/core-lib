//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private mapping environmentalElements = ([
    "terrain":([]),
    "interior": ([]),
    "feature": ([]),
    "building": ([]),
    "item": ([]),
    "objects": ([]),
    "shop": 0,
    "cloned": 0,
    "description": ([]),
    "location text": ({ " is " })
]);

private mapping aliasesToElements = ([]);

private mapping exits = ([]);
private string State = "default";
private string RegionPath = 0;
private int xCoordinate = 0;
private int yCoordinate = 0;
private nosave string ShortDescription = "";

protected nosave object StateMachine = 0;
protected nosave string StateMachinePath = 0;

private nosave int SetupCompleted = 0;
private object configuration = 
    load_object("/lib/dictionaries/configurationDictionary.c");

protected object StateMachineDictionary = 
    load_object("/lib/dictionaries/stateMachineDictionary.c");

private mapping instances = ([]);

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
            "objects" : ([]),
            "shop" : 0,
            "cloned" : 0,
            "description" : ([]),
            "location text" : ({ " is " })
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
private nomask varargs int addEnvironmentalElement(string element, string type, mixed location)
{
    int ret = 1;
    if (!environmentDictionary()->isValidEnvironmentItem(element))
    {
        ret = environmentDictionary()->registerElement(element, type);
        if (ret)
        {
            object elementObj = load_object(element);
            element = elementObj->Name();

            if (location && !elementObj->description())
            {
                raise_error(sprintf("ERROR in environment.c: You cannot specify a "
                    "direction for '%s' as it has no description.\n", element));
            }
        }
        else if((file_size(element) > 0) &&
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
protected nomask varargs void addBuilding(string feature, mixed location, string path, string state)
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
protected nomask void setCoordinates(string region, int x, int y)
{
    if (environmentDictionary()->coordinatesValidForRegion(region, x, y))
    {
        RegionPath = region;
        xCoordinate = x;
        yCoordinate = y;
    }
    else
    {
        raise_error(sprintf("ERROR in environment.c: coordinates(%d,%d) are "
            "not valid for this region: '%s'.\n", x, y, region));
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
                    elementObj->description(currentState(), illuminationLevel);

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
            ret = base->description(currentState(), illuminationLevel);
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
private string getExitDescription()
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

    int showUnicode = this_player() ? 
        this_player()->charsetConfiguration() == "unicode" : 0;
    string colorConfiguration = this_player() ?
        this_player()->colorConfiguration() : "none";

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
private string getInventoryDescription(int illuminationLevel)
{
    string ret = "";
    object *environmentInventory = all_inventory(this_object());
    if (sizeof(environmentInventory))
    {
        string colorConfiguration = this_player() ?
            this_player()->colorConfiguration() : "none";

        object *infraInventory = ({});
        if ((illuminationLevel < 7) && this_player() &&
            this_player()->hasTraitOfRoot("infravision"))
        {
            infraInventory = filter(environmentInventory,
                (: $1->isRealizationOfLiving() &&
                    !$1->hasTraitOfRoot("ethereal") &&
                    !$1->hasTraitOfRoot("undead") :));

            environmentInventory -= ({ this_player() });
            infraInventory -= ({ this_player() });

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
private nomask int getElementLighting()
{
    int ret = 0;

    foreach(string elementType in({ "terrain", "feature", "building", "item" }))
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
                    ret += elementObj->isSourceOfLight(currentState());
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
public varargs string long(string item)
{
    int illuminationLevel = isIlluminated();

    if (this_player() && this_player()->hasTraitOfRoot("darkvision"))
    {
        illuminationLevel = 10;
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
        ret += getElementDescriptions("feature", illuminationLevel) +
            getElementDescriptions("item", illuminationLevel) +
            getElementDescriptions("building", illuminationLevel);

        if (member(environmentalElements["description"], currentState()))
        {
            ret += " " + environmentalElements["description"][currentState()];
        }
        ret = format(ret, 78);
        ret = regreplace(ret,
            "##([^:]+)::(key|filename|room)::([^:]+)::([a-zA-Z0-9_\n]+)::",
            #'parseEfunCall,1);
    }
    else
    {
        raise_error("ERROR in environment.c: Either a valid terrain or "
            "interior must be set.\n");
    }

    string colorConfiguration = this_player() ?
        this_player()->colorConfiguration() : "none";

    return configuration->decorate(capitalizeSentences(ret),
        "description", "environment", colorConfiguration) +
        (isOutside ? 
            environmentDictionary()->timeOfDayMessage(colorConfiguration) :
            "") +
        getExitDescription() + 
        getInventoryDescription(illuminationLevel) + "\n";
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
public nomask int move(string str)
{
    string direction = query_verb();
    string destination = 0;

    if (member(exits, currentState()) && 
        member(exits[currentState()], direction))
    {
        destination = exits[currentState()][direction];
    }
    else if (member(exits, "default") &&
        member(exits["default"], direction))
    {
        destination = exits["default"][direction];
    }
    if (destination)
    {
        this_player()->move(destination, direction);
    }

    return destination && stringp(destination);
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
public nomask string overheadMap()
{
    string ret = 0;

    object region = environmentDictionary()->getRegion(RegionPath);
    if (region)
    {
        ret = region->getRelativeOverheadMap(xCoordinate, yCoordinate);
    }
    return ret;
}
