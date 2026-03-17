//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/environment/modules/regions/core.c";

private int ExpansionRadius = 4;
private int WorldOffsetX = 0;
private int WorldOffsetY = 0;

/////////////////////////////////////////////////////////////////////////////
public nomask void setExpansionRadius(int radius)
{
    if (radius >= 1 && radius <= 8)
    {
        ExpansionRadius = radius;
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int expansionRadius()
{
    return ExpansionRadius;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setWorldOffset(int x, int y)
{
    WorldOffsetX = x;
    WorldOffsetY = y;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int worldOffsetX()
{
    return WorldOffsetX;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int worldOffsetY()
{
    return WorldOffsetY;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int isWithinBounds(int x, int y)
{
    return (x >= 0 && y >= 0 && x < MaxX && y < MaxY);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isCellGenerated(int x, int y)
{
    return (isWithinBounds(x, y) &&
        sizeof(grid) > x && sizeof(grid[x]) > y &&
        mappingp(grid[x][y]) && 
        grid[x][y]["is placed"]);
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping generateExitsForCell(int x, int y)
{
    mapping cellExits = ([]);

    if (y + 1 < MaxY)
    {
        cellExits["north"] = sprintf("%dx%d", x, y + 1);
    }
    if (y - 1 >= 0)
    {
        cellExits["south"] = sprintf("%dx%d", x, y - 1);
    }
    if (x + 1 < MaxX)
    {
        cellExits["east"] = sprintf("%dx%d", x + 1, y);
    }
    if (x - 1 >= 0)
    {
        cellExits["west"] = sprintf("%dx%d", x - 1, y);
    }

    return cellExits;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void generateCell(int x, int y)
{
    if (!isWithinBounds(x, y) || isCellGenerated(x, y))
    {
        return;
    }

    string name = sprintf("%dx%d", x, y);

    grid[x][y] = ([
        "x": x,
        "y": y,
        "room type": "path",
        "is placed": 1,
        "exits": generateExitsForCell(x, y),
        "environment": 0,
        "identifier": sprintf("%s-%s", RegionName || "walk", name),
        "name": name
    ]);

    rooms += ({ grid[x][y] });
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void expandAroundPoint(int cx, int cy, int radius)
{
    if (!radius)
    {
        radius = ExpansionRadius;
    }

    for (int dy = -radius; dy <= radius; dy++)
    {
        for (int dx = -radius; dx <= radius; dx++)
        {
            int x = cx + dx;
            int y = cy + dy;

            if (isWithinBounds(x, y) && !isCellGenerated(x, y))
            {
                generateCell(x, y);
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void addBoundaryExit(int x, int y, string direction, 
    string destination, object targetRegion)
{
    if (isWithinBounds(x, y) && isCellGenerated(x, y))
    {
        grid[x][y]["exits"][direction] = destination;
        grid[x][y]["boundary exit"] = ([
            "direction": direction,
            "region": targetRegion,
            "destination": destination
        ]);
    }
}
