//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/environment/regions/core.c";
virtual inherit "/lib/environment/regions/entries-and-exits.c";
virtual inherit "/lib/environment/regions/generate-path.c";
virtual inherit "/lib/environment/regions/generate-room.c";
virtual inherit "/lib/environment/regions/generate-settlement.c";

/////////////////////////////////////////////////////////////////////////////
protected int getRoomCount()
{
    return roomCount ? roomCount : (MaxX + random(MaxX));
}

/////////////////////////////////////////////////////////////////////////////
public void setRoomCount(int count)
{
    int min = (MaxX > MaxY) ? MaxX : MaxY;
    int max = to_int(sqrt(MaxX * MaxY) * 3.0);

    if ((count >= min) && (count <= max))
    {
        roomCount = count;
    }
    else
    {
        raise_error(format(sprintf("Region: The room count (%d) must be in "
            "the range of %d to %d. This range is calculated based on the "
            "values of x (%d) and y (%d). Values outside of this range can "
            "adversely affect the performance of the pathing algorithm or "
            "lead to poorly-devised regions.\n",
            count, min, max, MaxX, MaxY), 78));
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void createEmptyGrid(int x, int y)
{
    for (int i = 0; i < x; i++)
    {
        grid[i] = ([]);
        for (int j = 0; j < y; j++)
        {
            grid[i][j] = ([
                "x": i,
                "y": j,
                "room type": "none",
                "is placed": 0,
                "exits": ([]),
                "environment": 0
            ]);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask int canGenerateRegion()
{
    int ret = 0;
    if (!RegionType)
    {
        raise_error("ERROR - region: The region type must be set before it is "
            "generated.\n");
    }
    else if (!RegionName)
    {
        raise_error("ERROR - region: The region name must be set before it is "
            "generated.\n");
    }
    else
    {
        ret = 1;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask void generateRegion(string enterFrom, string location,
    int *coordinates)
{
    EntryPoint = location;
    EnterFrom = enterFrom;

    if ((MaxX > 9) && (MaxY > 9) && 
        Dictionary->canConstructSettlement(this_object()))
    {
        generateSettlement();
    }

    // Create entry point
    createRoom(1, enterFrom, coordinates);

    int numberOfRooms = getRoomCount();
    for (int i = 0; i < numberOfRooms; i++)
    {
        createRoom();
    }

    while (sizeof(filter(rooms, (: $1["is placed"] == 0 :))))
    {
        foreach(mapping room in rooms)
        {
            constructPath(room);
        }
    }
    mapping exit = createExit();
    if (sizeof(exit))
    {
        rooms += ({ exit });
        constructPath(exit);
    }

    foreach(mapping room in rooms)
    {
        generateRoomDetails(room);
    }

    if (location)
    {
        grid[entry[0]][entry[1]]["exit to"] = enterFrom;
        grid[entry[0]][entry[1]]["environment"]->addEntryExit(
            enterFrom, location);
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs string createRegion(string enterFrom, string location,
    int *coordinates)
{
    string ret = 0;

    int loaded = call_direct(this_object(), "load", enterFrom, location);
    if (!loaded && canGenerateRegion())
    {
        createEmptyGrid(MaxX, MaxY);
        generateRegion(enterFrom, location, coordinates);

        ret = getDirectionOfEntry(enterFrom);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void createRegionFromTemplate(mapping data, 
    object connectedRegion)
{
    MaxX = data["x dimension"];
    MaxY = data["y dimension"];
    RegionName = data["name"];
    RegionType = data["type"];
    EnterFrom = data["enter from"];
    EntryPoint = data["entry point"];
    RegionLevel = data["level"];

    createEmptyGrid(MaxX, MaxY);

    entry = data["entry coordinate"];
    decorators = data["decorators"];
    rooms = data["rooms"];

    foreach(mapping room in data["rooms"])
    {
        room["room type"] = "room";
        room["identifier"] = sprintf("%s-%dx%d", RegionName, room["x"], 
            room["y"]);

        if (member(data, "terrain"))
        {
            room["terrain"] = data["terrain"];
        }
        else
        {
            room["interior"] = data["interior"];
        }

        grid[room["x"]][room["y"]] = room;
    }

    if (!member(grid[entry[0]][entry[1]], "exits"))
    {
        grid[entry[0]][entry[1]]["exits"] = ([]);
    }
    grid[entry[0]][entry[1]]["exits"][EnterFrom] = ([
        "exit to": EntryPoint,
        "door": data["door"],
        "key": data["key"],
        "region": connectedRegion
    ]);
}
