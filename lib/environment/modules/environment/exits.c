//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/environment/modules/environment/core.c";
virtual inherit "/lib/environment/modules/environment/elements.c";
virtual inherit "/lib/environment/modules/environment/state.c";

/////////////////////////////////////////////////////////////////////////////
public nomask varargs mapping getExitDirections()
{
    return exits + ([]);
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *exits()
{
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

    return exitList;
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
protected nomask void addDoor(string direction, string path, string door, 
    string key, string state)
{
    if (!stringp(door))
    {
        door = "/lib/environment/doors/door.c";
    }

    object doorObj = getDictionary("environment")->getDoor(door);
    if (doorObj)
    {
        if (!member(environmentalElements["doors"], state))
        {
            environmentalElements["doors"][state] = ([]);
        }
        environmentalElements["doors"][state][path] = doorObj;
        if (getDictionary("environment")->isValidKey(key))
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
