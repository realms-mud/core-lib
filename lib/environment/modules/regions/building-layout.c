//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/environment/modules/regions/building-coordinates.c";

/////////////////////////////////////////////////////////////////////////////
protected nomask mixed *createEmptyLayout(int width, int height)
{
    mixed *layout = ({});
    
    for (int y = 0; y < height; y++)
    {
        layout += ({ allocate(width) });
    }
    return layout;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int shouldPlaceWall(int x, int y, mixed *layout)
{
    int maxY = sizeof(layout);
    int maxX = sizeof(layout[0]);
    
    for (int dy = -1; dy <= 1; dy++)
    {
        for (int dx = -1; dx <= 1; dx++)
        {
            int ny = y + dy;
            int nx = x + dx;
            
            if (ny >= 0 && ny < maxY && nx >= 0 && nx < maxX && 
                layout[ny][nx] == 2)
            {
                return 1;
            }
        }
    }
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
private nomask void copyLayoutCell(mixed *source, mixed *dest, int x, int y)
{
    dest[y][x] = source[y][x];
}

/////////////////////////////////////////////////////////////////////////////
private nomask void copyLayout(mixed *source, mixed *dest)
{
    int maxY = sizeof(source);
    int maxX = sizeof(source[0]);
    
    for (int y = 0; y < maxY; y++)
    {
        for (int x = 0; x < maxX; x++)
        {
            copyLayoutCell(source, dest, x, y);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void addWalls(mixed *layout)
{
    int maxY = sizeof(layout);
    int maxX = sizeof(layout[0]);
    mixed *tempLayout = createEmptyLayout(maxX, maxY);
    
    copyLayout(layout, tempLayout);
    
    for (int y = 0; y < maxY; y++)
    {
        for (int x = 0; x < maxX; x++)
        {
            if (layout[y][x] == 0 && shouldPlaceWall(x, y, layout))
            {
                tempLayout[y][x] = 1;
            }
        }
    }
    
    copyLayout(tempLayout, layout);
}

/////////////////////////////////////////////////////////////////////////////
private nomask int canPlaceEntry(mixed *layout, int x, int y)
{
    return (layout[y][x] == 2 || layout[y][x] == 1);
}

/////////////////////////////////////////////////////////////////////////////
private nomask void markEntryAt(mixed *layout, int x, int y)
{
    layout[y][x] = 4;
}

/////////////////////////////////////////////////////////////////////////////
private nomask void markAdjacentEntry(mixed *layout, int x, int y, int dx, 
    int dy)
{
    int maxY = sizeof(layout);
    int maxX = sizeof(layout[0]);
    int nextY = y + dy;
    int nextX = x + dx;
    
    if (nextY >= 0 && nextY < maxY && nextX >= 0 && nextX < maxX &&
        layout[nextY][nextX] == 2)
    {
        markEntryAt(layout, nextX, nextY);
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask int tryPlaceEntry(mixed *layout, int x, int y, int dx, int dy)
{
    int placed = 0;
    
    if (canPlaceEntry(layout, x, y))
    {
        markEntryAt(layout, x, y);
        markAdjacentEntry(layout, x, y, dx, dy);
        placed = 1;
    }
    return placed;
}

/////////////////////////////////////////////////////////////////////////////
private nomask void placeEntryFromSouth(mixed *layout, int entryX)
{
    int placed = 0;
    
    for (int y = sizeof(layout) - 1; y >= 0 && !placed; y--)
    {
        placed = tryPlaceEntry(layout, entryX, y, 0, -1);
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void placeEntryFromNorth(mixed *layout, int entryX)
{
    int placed = 0;
    
    for (int y = 0; y < sizeof(layout) && !placed; y++)
    {
        placed = tryPlaceEntry(layout, entryX, y, 0, 1);
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void placeEntryFromEast(mixed *layout, int entryY)
{
    int placed = 0;
    
    for (int x = sizeof(layout[0]) - 1; x >= 0 && !placed; x--)
    {
        placed = tryPlaceEntry(layout, x, entryY, -1, 0);
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void placeEntryFromWest(mixed *layout, int entryY)
{
    int placed = 0;
    
    for (int x = 0; x < sizeof(layout[0]) && !placed; x++)
    {
        placed = tryPlaceEntry(layout, x, entryY, 1, 0);
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void placeEntry(mixed *layout, string enterFrom)
{
    int maxX = sizeof(layout[0]);
    int maxY = sizeof(layout);
    
    if (enterFrom == "south")
    {
        placeEntryFromSouth(layout, maxX / 2);
    }
    else if (enterFrom == "north")
    {
        placeEntryFromNorth(layout, maxX / 2);
    }
    else if (enterFrom == "east")
    {
        placeEntryFromEast(layout, maxY / 2);
    }
    else if (enterFrom == "west")
    {
        placeEntryFromWest(layout, maxY / 2);
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask mixed *initializeRoomTracking(int height, int width)
{
    int **roomIds = allocate(height);
    mapping **doorData = allocate(height);
    
    for (int y = 0; y < height; y++)
    {
        roomIds[y] = allocate(width);
        doorData[y] = allocate(width);
        
        for (int x = 0; x < width; x++)
        {
            doorData[y][x] = ([]);
        }
    }
    
    return ({ roomIds, doorData });
}

/////////////////////////////////////////////////////////////////////////////
protected nomask mapping *placeMainHall(mixed *layout, int **roomIds, 
    mapping *rooms, int hallX, int hallY, int hallWidth, int hallHeight)
{
    int height = sizeof(layout);
    
    for (int y = hallY; y < hallY + hallHeight && y < height; y++)
    {
        for (int x = hallX; x < hallX + hallWidth; x++)
        {
            if (x >= 0 && y >= 0)
            {
                layout[y][x] = 2;
                roomIds[y][x] = 1;
            }
        }
    }
    
    rooms += ({ ([
        "x": hallX,
        "y": hallY,
        "width": hallWidth,
        "height": hallHeight,
        "id": 1
    ]) });
    
    return rooms;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int checkRoomOverlap(mixed *layout, int roomX, int roomY, 
    int roomWidth, int roomHeight)
{
    int height = sizeof(layout);
    int width = sizeof(layout[0]);
    int overlaps = 0;
    
    for (int y = roomY - 2; y < roomY + roomHeight + 2 && y < height && 
         !overlaps; y++)
    {
        for (int x = roomX - 2; x < roomX + roomWidth + 2 && x < width && 
             !overlaps; x++)
        {
            if (x >= 0 && y >= 0 && layout[y][x] != 0)
            {
                overlaps = 1;
            }
        }
    }
    return overlaps;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void fillRoomCells(mixed *layout, int **roomIds, int roomX, 
    int roomY, int roomWidth, int roomHeight, int roomId)
{
    int height = sizeof(layout);
    
    for (int y = roomY; y < roomY + roomHeight && y < height; y++)
    {
        for (int x = roomX; x < roomX + roomWidth; x++)
        {
            if (x >= 0 && y >= 0)
            {
                layout[y][x] = 2;
                roomIds[y][x] = roomId;
            }
        }
    }
}
