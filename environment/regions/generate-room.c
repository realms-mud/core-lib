//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/environment/regions/core.c";
virtual inherit "/lib/environment/regions/entries-and-exits.c";

/////////////////////////////////////////////////////////////////////////////
protected nomask void generateRoomDetails(mapping room)
{
    room["environment"] =
        clone_object("/lib/environment/generatedEnvironment");

    room += room["environment"]->generateEnvironment(room, this_object());
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

        string name = sprintf("%dx%d", x, y);
        grid[x][y]["identifier"] = sprintf("%s,%s-%s", EntryPoint || "none", 
            EnterFrom || "no exit", name);
        grid[x][y]["name"] = name;

        rooms += ({ grid[x][y] });
    }
    else
    {
        createRoom(isEntry);
    }
}
