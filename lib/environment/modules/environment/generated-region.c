//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/environment/modules/environment/core.c";
virtual inherit "/lib/environment/modules/environment/elements.c";
virtual inherit "/lib/environment/modules/environment/exits.c";
virtual inherit "/lib/environment/modules/environment/state.c";

private int SettlementChance = -1;

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
