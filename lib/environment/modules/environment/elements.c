//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/environment/modules/environment/core.c";
virtual inherit "/lib/environment/modules/environment/legacy.c";
virtual inherit "/lib/environment/modules/environment/state.c";
virtual inherit "/lib/environment/modules/environment/harvest.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{

}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping getLocation(mixed location)
{
    mapping elementLocation = 0;
    if (stringp(location))
    {
        elementLocation = getDictionary("environment")->getLocation(location);
    }
    else if (getDictionary("environment")->isValidLocation(location))
    {
        elementLocation = location;
    }

    if (location && !elementLocation)
    {
        raise_error(sprintf("ERROR in environment.c: '%O' is not a valid "
            "location.\n", location));
    }
    return elementLocation;
}

/////////////////////////////////////////////////////////////////////////////
private nomask void setUpAliases(string element)
{
    object environmentalObj =
        getDictionary("environment")->environmentalObject(element);

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
protected nomask varargs int addEnvironmentalElement(string element, string type, mixed location)
{
    int ret = 1;
    if (!getDictionary("environment")->isValidEnvironmentItem(element))
    {
        ret = getDictionary("environment")->registerElement(element, type);
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
            getDictionary("environment")->isValidEnvironmentItem(load_object(element)->Name(), type))
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

    ret &&= getDictionary("environment")->isValidEnvironmentItem(element, type);
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
protected nomask varargs void addFeature(string feature, mixed location)
{
    if (!addEnvironmentalElement(feature, "feature", location))
    {
        raise_error(sprintf("ERROR in environment.c: '%s' is not a "
            "valid feature.\n", feature));
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
        if (isLegacyEnvironment())
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
private string getlocationText()
{
    return environmentalElements["location text"][
        random(sizeof(environmentalElements["location text"]))];
}

/////////////////////////////////////////////////////////////////////////////
protected string getElementDescriptions(string type, int illuminationLevel)
{
    string ret = "";

    if (member(environmentalElements, type) &&
        sizeof(environmentalElements[type]))
    {
        string *elements = sort_array(
            m_indices(environmentalElements[type]), (: $1 > $2 :));
        foreach(string element in elements)
        {
            string directions = " there";

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
                getDictionary("environment")->environmentalObject(element);
            if (elementObj && 
                (!this_player() || elementObj->elementIsAvailable(this_player())))
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
public void resetData()
{
    pruneStateObjects();
    resetEnvironmentData();

    Setup();
}

/////////////////////////////////////////////////////////////////////////////
protected varargs string getBaseDescriptionForType(string type,
    int illuminationLevel, int doNotRecurse)
{
    string ret = 0;
    if (member(environmentalElements, type) && sizeof(environmentalElements[type]))
    {
        string element = m_indices(environmentalElements[type])[0];
        object base = getDictionary("environment")->environmentalObject(element);
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
