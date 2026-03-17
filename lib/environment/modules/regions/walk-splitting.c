//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/environment/modules/regions/core.c";

private mapping neighborRegions = ([]);

/////////////////////////////////////////////////////////////////////////////
public nomask object getNeighborRegion(string direction)
{
    object ret = 0;

    if (member(neighborRegions, direction))
    {
        ret = neighborRegions[direction];
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping neighborRegionData()
{
    return neighborRegions + ([]);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setNeighborRegion(string direction, object region)
{
    if (stringp(direction) && objectp(region) &&
        member(oppositeDirection, direction))
    {
        neighborRegions[direction] = region;
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isAtBoundary(int x, int y)
{
    return (x == 0 || x == MaxX - 1 || y == 0 || y == MaxY - 1);
}

/////////////////////////////////////////////////////////////////////////////
public nomask string getBoundaryDirection(int x, int y)
{
    if (x >= MaxX)
    {
        return "east";
    }
    if (x < 0)
    {
        return "west";
    }
    if (y >= MaxY)
    {
        return "north";
    }
    if (y < 0)
    {
        return "south";
    }
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int *translateToNeighborCoords(int x, int y)
{
    int localX = x;
    int localY = y;

    if (x >= MaxX)
    {
        localX = x - MaxX;
    }
    else if (x < 0)
    {
        localX = MaxX + x;
    }

    if (y >= MaxY)
    {
        localY = y - MaxY;
    }
    else if (y < 0)
    {
        localY = MaxY + y;
    }

    return ({ localX, localY });
}

/////////////////////////////////////////////////////////////////////////////
public nomask void linkNeighborRegions(object neighbor, string direction)
{
    if (!objectp(neighbor) || !member(oppositeDirection, direction))
    {
        return;
    }

    setNeighborRegion(direction, neighbor);
    neighbor->setNeighborRegion(oppositeDirection[direction], this_object());
}
