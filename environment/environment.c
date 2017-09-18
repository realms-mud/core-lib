//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private mapping environmentalElements = ([
    "terrain":([]),
    "interior": ([]),
    "feature": ([]),
    "building": ([]),
    "item": ([])
]);

private mapping aliasesToElements = ([]);

private mapping exits = ([]);
private string State = "default";

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
        aliasesToElements[state] = ([]);
        foreach(string alias in environmentalObj->aliases(state))
        {
            aliasesToElements[state][alias] = program_name(environmentalObj);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask int addEnvironmentalElement(string element, string type, string location)
{
    int ret = 1;
    if (!environmentDictionary()->isValidEnvironmentItem(element))
    {
        ret = environmentDictionary()->registerElement(element, type);
        if (ret)
        {
            element = load_object(element)->Name();
        }
        else if(environmentDictionary()->isValidEnvironmentItem(element))
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

    if (ret && environmentDictionary()->isValidEnvironmentItem(element, type))
    {
        if (!member(environmentalElements[type], element))
        {
            environmentalElements[type][element] = ({});
        }
        environmentalElements[type][element] =
            m_indices(mkmapping(environmentalElements[type][element] +
                ({ location }) - ({ 0 })));
        setUpAliases(element);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask varargs void addFeature(string feature, string location)
{
    if (!addEnvironmentalElement(feature, "feature", location))
    {
        raise_error(sprintf("ERROR in environment.c: '%s' is not a "
            "valid feature.\n", feature));
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void addExit(string direction, string path)
{

}

/////////////////////////////////////////////////////////////////////////////
protected nomask void addBuilding(string feature, string location, string path)
{
    if (addEnvironmentalElement(feature, "building", location))
    {
        addExit(location, path);
    }
    else
    {
        raise_error(sprintf("ERROR in environment.c: '%s' is not a "
            "valid building.\n", feature));
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
private string getFeatureDescriptions()
{
    string ret = "";

    if (sizeof(environmentalElements["feature"]))
    {
        string *features = sort_array(
            m_indices(environmentalElements["feature"]), (: $1 > $2 :));
        foreach(string feature in features)
        {
            string directions = "";

            if (sizeof(environmentalElements["feature"][feature]))
            {
                directions = " to the " + 
                    implode(environmentalElements["feature"][feature], ", ");
                directions = regreplace(directions, ",([^,]+)$", " and\\1");
            }

            object featureObj = 
                environmentDictionary()->environmentalObject(feature);
            if (featureObj)
            {
                ret += directions + " you see " +
                    featureObj->description(currentState()) + ".";
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private string getBaseDescriptionForType(string type)
{
    string ret = 0;
    if (member(environmentalElements, type) && sizeof(environmentalElements[type]))
    {
        string element = m_indices(environmentalElements[type])[0];
        object base = environmentDictionary()->environmentalObject(element);
        if (base)
        {
            ret = base->description(currentState());
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
public string long(string item)
{
    string ret = getBaseDescriptionForType("terrain");
    if (!ret)
    {
        ret = getBaseDescriptionForType("interior");
    }

    if (ret)
    {
        ret += getFeatureDescriptions();
    }
    else
    {
        raise_error("ERROR in environment.c: Either a valid terrain or "
            "interior must be set.\n");
    }
    return capitalizeSentences(ret);
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
        ret = load_object(aliasesToElements[currentState()][item]);
    }
    return ret;
}