//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
protected int MaxX = 25;
protected int MaxY = 10;
protected string RegionName = 0;
protected string RegionType = 0;

protected mapping grid = ([ ]);
protected mapping *rooms = ({ });
protected int *entry = ({ });

protected string *availableDirections = ({ "north", "south", "east", "west" });
protected mapping oppositeDirection = ([
    "north": "south",
    "south": "north",
    "west": "east",
    "east": "west"
]);

protected object Dictionary = load_object("/lib/dictionaries/regionDictionary.c");

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
