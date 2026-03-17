//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/environment/modules/regions/core.c";
virtual inherit "/lib/environment/modules/regions/map.c";
virtual inherit "/lib/environment/modules/regions/generate-room.c";
virtual inherit "/lib/environment/modules/regions/walk-generation.c";
virtual inherit "/lib/environment/modules/regions/walk-splitting.c";
virtual inherit "/lib/environment/modules/regions/walk-persistence.c";
virtual inherit "/lib/environment/modules/regions/walk-settlement.c";

private int setupCompleted = 0;

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
public nomask void setDimensions(int x, int y)
{
    if (x >= 5 && x <= 25 && y >= 5 && y <= 25)
    {
        MaxX = x;
        MaxY = y;
    }
    else
    {
        raise_error("walkableRegion: Dimensions must be between 5 and 25.\n");
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setRegionName(string name)
{
    RegionName = name;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setRegionType(string type)
{
    if (RegionService->isValidRegionType(type))
    {
        RegionType = type;
    }
    else
    {
        raise_error("ERROR - walkableRegion: The region must be a valid "
            "type as defined in /lib/services/regions/region-types.h\n");
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setRegionLevel(int level)
{
    if (level > 0)
    {
        RegionLevel = level;
    }
}

/////////////////////////////////////////////////////////////////////////////
public string regionName()
{
    return RegionName;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string regionType()
{
    return RegionType;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int regionLevel()
{
    return RegionLevel;
}

/////////////////////////////////////////////////////////////////////////////
public int xDimension()
{
    return MaxX;
}

/////////////////////////////////////////////////////////////////////////////
public int yDimension()
{
    return MaxY;
}

/////////////////////////////////////////////////////////////////////////////
public string entryPoint()
{
    return EntryPoint;
}

/////////////////////////////////////////////////////////////////////////////
public string entryDirection()
{
    return EnterFrom;
}

/////////////////////////////////////////////////////////////////////////////
public nomask object getEnvironment(string location)
{
    int x = to_int(regreplace(location, "([0-9]+)x[0-9]+,*.*", "\\1", 1));
    int y = to_int(regreplace(location, "[0-9]+x([0-9]+),*.*", "\\1", 1));
    object ret = 0;

    string boundaryDir = getBoundaryDirection(x, y);
    if (boundaryDir)
    {
        object neighbor = getNeighborRegion(boundaryDir);

        if (objectp(neighbor))
        {
            int *local = translateToNeighborCoords(x, y);
            return neighbor->getEnvironment(
                sprintf("%dx%d", local[0], local[1]));
        }
        return 0;
    }

    expandAroundPoint(x, y, 0);
    markDirty();

    if ((x >= 0 && y >= 0 && x < MaxX && y < MaxY) &&
        (sizeof(grid) > x && sizeof(grid[x]) > y) &&
        mappingp(grid[x][y]) && grid[x][y]["is placed"])
    {
        if (!objectp(grid[x][y]["environment"]))
        {
            generateRoomDetails(grid[x][y]);
        }
        ret = grid[x][y]["environment"];
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs string initialize(string enterFrom, string location,
    int startX, int startY)
{
    if (!RegionType || !RegionName)
    {
        raise_error("ERROR - walkableRegion: Type and name must be set "
            "before initialization.\n");
    }

    if (!MaxX || !MaxY)
    {
        setDimensions(25, 10);
    }

    createEmptyGrid(MaxX, MaxY);

    EntryPoint = location;
    EnterFrom = enterFrom;

    if (startX < 0 || startX >= MaxX)
    {
        startX = MaxX / 2;
    }
    if (startY < 0 || startY >= MaxY)
    {
        startY = (enterFrom == "south") ? 0 :
            (enterFrom == "north") ? MaxY - 1 :
            MaxY / 2;
    }

    entry = ({ startX, startY });
    expandAroundPoint(startX, startY, 0);

    if (isCellGenerated(startX, startY))
    {
        grid[startX][startY]["room type"] = "entry";
        grid[startX][startY]["exit to"] = enterFrom;

        generateRoomDetailsAsync(grid[startX][startY]);

        if (location)
        {
            grid[startX][startY]["environment"]->addEntryExit(
                enterFrom, location);
        }
    }

    markDirty();
    decideSettlement();
    return oppositeDirection[enterFrom];
}

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{

}

/////////////////////////////////////////////////////////////////////////////
public nomask void create()
{
    if (!setupCompleted)
    {
        Setup();
        setupCompleted = 1;
    }
}
