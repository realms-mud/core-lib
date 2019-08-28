//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/environment/regions/core.c";
virtual inherit "/lib/environment/regions/entries-and-exits.c";

/////////////////////////////////////////////////////////////////////////////
private nomask void addRandomEnvironmentalElements()
{

}

/////////////////////////////////////////////////////////////////////////////
private nomask void addRandomObjects()
{

}

/////////////////////////////////////////////////////////////////////////////
private nomask void addRandomCreature()
{

}

/////////////////////////////////////////////////////////////////////////////
protected nomask varargs void createRoom(int isEntry, string enterFrom,
    int *coordinates)
{
    int x;
    int y;
    if (isEntry)
    {
        if (sizeof(coordinates) != 2)
        {
            int *entryLocation = getRandomEntryCoordinates(enterFrom);
            x = entryLocation[0];
            y = entryLocation[1];
        }
        else
        {
            x = coordinates[0];
            y = coordinates[1];
        }
        entry = ({ x, y });
    }
    else
    {
        x = random(MaxX);
        y = random(MaxY);
    }

    if (!grid[x][y]["is placed"])
    {
        grid[x][y]["is placed"] = isEntry;
        grid[x][y]["room type"] = isEntry ? "entry" : "room";

        addRandomEnvironmentalElements();
        addRandomObjects();
        addRandomCreature();

        rooms += ({ grid[x][y] });
    }
    else
    {
        createRoom(isEntry);
    }
}
