//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/environment/modules/regions/core.c";
virtual inherit "/lib/environment/modules/regions/entries-and-exits.c";

/////////////////////////////////////////////////////////////////////////////
public nomask void generateRoomDetailsAsync(mapping room)
{
    room["environment"] =
        clone_object("/lib/environment/generatedEnvironment");

    room += room["environment"]->generateEnvironment(room, this_object());
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void generateRoomDetails(mapping room)
{
    if ((room["room type"] == "entry") || (sizeof(entry) &&
        (room["x"] == entry[0]) && (room["y"] == entry[1])))
    {
        generateRoomDetailsAsync(room);
    }
    else
    {
        call_out("generateRoomDetailsAsync", 0, room);
    }
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

    if (grid[x][y]["room type"] == "none")
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
