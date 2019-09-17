//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/environment/regions/core.c";
virtual inherit "/lib/environment/regions/generate-region.c";
virtual inherit "/lib/environment/regions/persist-region.c";
virtual inherit "/lib/environment/regions/map.c";

/////////////////////////////////////////////////////////////////////////////
public nomask void setDimensions(int x, int y)
{
    if ((x > 25) || (y > 25))
    {
        raise_error("Region: The largest area that can be generated is 25x25.\n");
    }
    else if ((x < 5) || (y < 5))
    {
        raise_error("Region: The smallest area that can be generated is 5x5.\n");
    }
    else
    {
        MaxX = x;
        MaxY = y;
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
