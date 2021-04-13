//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/environment/modules/regions/core.c";
virtual inherit "/lib/environment/modules/regions/domain.c";
virtual inherit "/lib/environment/modules/regions/generate-region.c";
virtual inherit "/lib/environment/modules/regions/persist-region.c";
virtual inherit "/lib/environment/modules/regions/map.c";

private int setupCompleted = 0;
private int manualRegion = 0;

/////////////////////////////////////////////////////////////////////////////
public nomask void asManualRegion()
{
    manualRegion = 1;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setDimensions(int x, int y)
{
    if ((x > 25) || (y > 25))
    {
        raise_error("Region: The largest area that can be generated is 25x25.\n");
    }
    else if (!manualRegion && ((x < 5) || (y < 5)))
    {
        raise_error("Region: The smallest area that can be generated is 5x5.\n");
    }
    else
    {
        MaxX = x;
        MaxY = y;
        roomCount = 0;
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
public nomask void setRegionName(string name)
{
    RegionName = name;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setRegionType(string type)
{
    if (Dictionary->isValidRegionType(type))
    {
        RegionType = type;
    }
    else
    {
        raise_error("ERROR - region: The region must be a valid type as defined in "
            "/lib/dictionaries/regions/region-types.h\n");
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setRegionLevel(int level)
{
    if (level > 0)
    {
        RegionLevel = level;
    }
    else
    {
        raise_error("ERROR - region: The region must be an integer greater "
            "than 1.\n");
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask object getEnvironment(string location)
{
    int x = to_int(regreplace(location, "([0-9]+)x[0-9]+,*.*", "\\1", 1));
    int y = to_int(regreplace(location, "[0-9]+x([0-9]+),*.*", "\\1", 1));

    if (!objectp(grid[x][y]["environment"]))
    {
        generateRoomDetails(grid[x][y]);
    }

    return grid[x][y]["environment"];
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
public mapping *rooms()
{
    mapping *ret = rooms + ({});

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public mapping *decorators()
{
    mapping *ret = decorators + ({});

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public void setEntryExit(string entryPoint, object region, string state)
{
    if (sizeof(entry))
    {
        grid[entry[0]][entry[1]]["environment"]->updateEntryPoint(
            EnterFrom, entryPoint, region, state);
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs void setCoordinate(int x, int y, string path,
    string roomType)
{
    PersistRegion = 0;

    if ((x < 0) || (y < 0) || (x > MaxX) || (y > MaxY))
    {
        raise_error(sprintf("Error in region.c: The coordinate provided "
            "(%d,%d) is not valid for this region.\n", x, y));
    }
    
    object environment;
    string loadFailed = catch (environment = load_object(path));
    if(loadFailed || (member(inherit_list(environment), 
        "/lib/environment/environment.c") < 0))
    {
        raise_error(sprintf("Error in region.c: The provided path "
            "(%O) is not a valid environment.\n", path));
    }

    if (!roomType)
    {
        roomType = "room";
    }

    if (sizeof(grid) < MaxX)
    {
        createEmptyGrid(MaxX, MaxY);
    }

    string decoratorType = environment->decoratorType();

    grid[x][y] = ([
        "is placed": 1,
        "room type": roomType,
        "name": path,
        "environment": environment,
        "state exits": environment->getExitDirections(),
    ]);

    if (decoratorType)
    {
        grid[x][y]["icon"] = Dictionary->getMapDecorator(decoratorType);
    }

    environment->setCoordinates(this_object(), x, y);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setEntryCoordinate(int x, int y, string path,
    string enterFrom, string entryPoint)
{
    EntryPoint = entryPoint;
    EnterFrom = enterFrom;
    setCoordinate(x, y, path, "entry");

    grid[x][y]["exit to"] = enterFrom;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setExitCoordinate(int x, int y, string path,
    string exitTo)
{
    setCoordinate(x, y, path, "exit");

    grid[x][y]["exit to"] = exitTo;
    grid[x][y]["exit coordinates"] = ({ });
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
