//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
protected int MaxX = 25;
protected int MaxY = 10;
protected int roomCount = 0;

protected string RegionName = 0;
protected string RegionType = 0;
protected string EnterFrom = 0;
protected string EntryPoint = 0;
protected int RegionLevel = 0;

protected mapping grid = ([ ]);
protected mapping *rooms = ({ });
protected mapping *decorators = ({ });
protected int *entry = ({ });

protected string *availableDirections = ({ "north", "south", "east", "west" });
protected mapping oppositeDirection = ([
    "north": "south",
    "south": "north",
    "west": "east",
    "east": "west",
    "northwest": "southeast",
    "northeast": "southwest",
    "southeast": "northwest",
    "southwest": "northeast"
]);

protected object Dictionary = getDictionary("region");

/////////////////////////////////////////////////////////////////////////////
protected nomask varargs string getDirectionOfEntry(string enterFrom)
{
    string exitTo = 0;
    if (sizeof(entry))
    {
        if (entry[0] == 0)
        {
            exitTo = "east";
        }
        else if (entry[0] == (MaxX - 1))
        {
            exitTo = "west";
        }
        else if (entry[1] == 0)
        {
            exitTo = "north";
        }
        else if (entry[1] == (MaxY - 1))
        {
            exitTo = "south";
        }

        if (enterFrom)
        {
            exitTo = oppositeDirection[enterFrom];
        }
    }
    return exitTo;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string getEnterFromDirection(string direction)
{
    string ret = 0;
    if (member(oppositeDirection, direction))
    {
        ret = oppositeDirection[direction];
    }
    else
    {
        raise_error("The specified direction must be one of: north, south "
            "east, or west.\n");
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string getEntryCoordinates()
{
    string ret = 0;
    if (sizeof(entry))
    {
        ret = sprintf("%dx%d", entry[0], entry[1]);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public string regionIdentifier()
{
    return regreplace(sprintf("%s-%s", RegionName, 
        EntryPoint ? EntryPoint : getEntryCoordinates()), 
        "[^A-Za-z0-9-_]", "-", 1);
}
