//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/environment/modules/regions/building-layout.c";

/////////////////////////////////////////////////////////////////////////////
private nomask int scanForRoomLeft(int x, int y, mixed *layout, 
    int **roomIds)
{
    int maxX = sizeof(layout[0]);
    int foundId = 0;
    
    for (int sx = x - 1; sx >= 0 && !foundId; sx--)
    {
        if (layout[y][sx] == 2 && roomIds[y][sx] > 0)
        {
            foundId = roomIds[y][sx];
        }
        else if (layout[y][sx] != 2)
        {
            break;
        }
    }
    return foundId;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int scanForRoomRight(int x, int y, mixed *layout, 
    int **roomIds)
{
    int maxX = sizeof(layout[0]);
    int foundId = 0;
    
    for (int sx = x + 1; sx < maxX && !foundId; sx++)
    {
        if (layout[y][sx] == 2 && roomIds[y][sx] > 0)
        {
            foundId = roomIds[y][sx];
        }
        else if (layout[y][sx] != 2)
        {
            break;
        }
    }
    return foundId;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int scanForRoomUp(int x, int y, mixed *layout, int **roomIds)
{
    int maxY = sizeof(layout);
    int foundId = 0;
    
    for (int sy = y - 1; sy >= 0 && !foundId; sy--)
    {
        if (layout[sy][x] == 2 && roomIds[sy][x] > 0)
        {
            foundId = roomIds[sy][x];
        }
        else if (layout[sy][x] != 2)
        {
            break;
        }
    }
    return foundId;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int scanForRoomDown(int x, int y, mixed *layout, 
    int **roomIds)
{
    int maxY = sizeof(layout);
    int foundId = 0;
    
    for (int sy = y + 1; sy < maxY && !foundId; sy++)
    {
        if (layout[sy][x] == 2 && roomIds[sy][x] > 0)
        {
            foundId = roomIds[sy][x];
        }
        else if (layout[sy][x] != 2)
        {
            break;
        }
    }
    return foundId;
}

/////////////////////////////////////////////////////////////////////////////
private nomask void markDoorInCell(mapping **doorData, int x, int y, 
    string dir)
{
    doorData[y][x][dir] = 1;
}

/////////////////////////////////////////////////////////////////////////////
private nomask void markAdjacentDoorWest(mapping **doorData, int x, int y, 
    int **roomIds, int leftId)
{
    int maxX = sizeof(doorData[0]);
    
    for (int sx = x - 1; sx >= 0; sx--)
    {
        if (doorData[y][sx] && roomIds[y][sx] == leftId)
        {
            markDoorInCell(doorData, sx, y, "east");
            break;
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void markAdjacentDoorEast(mapping **doorData, int x, int y, 
    int **roomIds, int rightId)
{
    int maxX = sizeof(doorData[0]);
    
    for (int sx = x + 1; sx < maxX; sx++)
    {
        if (doorData[y][sx] && roomIds[y][sx] == rightId)
        {
            markDoorInCell(doorData, sx, y, "west");
            break;
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void markAdjacentDoorNorth(mapping **doorData, int x, int y, 
    int **roomIds, int topId)
{
    int maxY = sizeof(doorData);
    
    for (int sy = y - 1; sy >= 0; sy--)
    {
        if (doorData[sy][x] && roomIds[sy][x] == topId)
        {
            markDoorInCell(doorData, x, sy, "south");
            break;
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void markAdjacentDoorSouth(mapping **doorData, int x, int y, 
    int **roomIds, int bottomId)
{
    int maxY = sizeof(doorData);
    
    for (int sy = y + 1; sy < maxY; sy++)
    {
        if (doorData[sy][x] && roomIds[sy][x] == bottomId)
        {
            markDoorInCell(doorData, x, sy, "north");
            break;
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask int placeHorizontalDoorAt(mixed *layout, int **roomIds, 
    mapping **doorData, int x, int y, int fallbackId)
{
    int placed = 0;
    int maxX = sizeof(layout[0]);
    
    if (x >= 0 && x < maxX && layout[y][x] == 1)
    {
        layout[y][x] = 2;
        
        int leftId = scanForRoomLeft(x, y, layout, roomIds);
        int rightId = scanForRoomRight(x, y, layout, roomIds);
        
        if (leftId)
        {
            roomIds[y][x] = leftId;
        }
        else if (rightId)
        {
            roomIds[y][x] = rightId;
        }
        else
        {
            roomIds[y][x] = fallbackId;
        }
        
        if (leftId && rightId)
        {
            markDoorInCell(doorData, x, y, "west");
            markDoorInCell(doorData, x, y, "east");
            markAdjacentDoorWest(doorData, x, y, roomIds, leftId);
            markAdjacentDoorEast(doorData, x, y, roomIds, rightId);
        }
        placed = 1;
    }
    return placed;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int placeHorizontalDoor(mixed *layout, int **roomIds, 
    mapping **doorData, int x1, int x2, int y, int fallbackId)
{
    int doorPlaced = 0;
    int startX = (x1 < x2) ? x1 : x2;
    int endX = (x1 > x2) ? x1 : x2;
    
    for (int x = startX; x <= endX && !doorPlaced; x++)
    {
        doorPlaced = placeHorizontalDoorAt(layout, roomIds, doorData, x, y, 
            fallbackId);
    }
    return doorPlaced;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int placeVerticalDoorAt(mixed *layout, int **roomIds, 
    mapping **doorData, int x, int y, int fallbackId)
{
    int placed = 0;
    int maxY = sizeof(layout);
    
    if (y >= 0 && y < maxY && layout[y][x] == 1)
    {
        layout[y][x] = 2;
        
        int topId = scanForRoomUp(x, y, layout, roomIds);
        int bottomId = scanForRoomDown(x, y, layout, roomIds);
        
        if (topId)
        {
            roomIds[y][x] = topId;
        }
        else if (bottomId)
        {
            roomIds[y][x] = bottomId;
        }
        else
        {
            roomIds[y][x] = fallbackId;
        }
        
        if (topId && bottomId)
        {
            markDoorInCell(doorData, x, y, "north");
            markDoorInCell(doorData, x, y, "south");
            markAdjacentDoorNorth(doorData, x, y, roomIds, topId);
            markAdjacentDoorSouth(doorData, x, y, roomIds, bottomId);
        }
        placed = 1;
    }
    return placed;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int placeVerticalDoor(mixed *layout, int **roomIds, 
    mapping **doorData, int y1, int y2, int x, int fallbackId)
{
    int doorPlaced = 0;
    int startY = (y1 < y2) ? y1 : y2;
    int endY = (y1 > y2) ? y1 : y2;
    
    for (int y = startY; y <= endY && !doorPlaced; y++)
    {
        doorPlaced = placeVerticalDoorAt(layout, roomIds, doorData, x, y, 
            fallbackId);
    }
    return doorPlaced;
}

/////////////////////////////////////////////////////////////////////////////
private nomask void createHorizontalCorridor(mixed* layout, int** roomIds,
    int x1, int x2, int y, int roomId)
{
    int maxX = sizeof(layout[0]);
    int startX = (x1 < x2) ? x1 : x2;
    int endX = (x1 > x2) ? x1 : x2;

    for (int x = startX; x <= endX; x++)
    {
        if (x >= 0 && x < maxX)
        {
            if (layout[y][x] < 2)
            {
                layout[y][x] = 2;
            }
            roomIds[y][x] = roomId;
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void createVerticalCorridor(mixed* layout, int** roomIds,
    int y1, int y2, int x, int roomId)
{
    int maxY = sizeof(layout);
    int startY = (y1 < y2) ? y1 : y2;
    int endY = (y1 > y2) ? y1 : y2;

    for (int y = startY; y <= endY; y++)
    {
        if (y >= 0 && y < maxY)
        {
            if (layout[y][x] < 2)
            {
                layout[y][x] = 2;
            }
            roomIds[y][x] = roomId;
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void addDoorBetweenRooms(mixed *layout, int **roomIds, 
    mapping **doorData, mapping room1, mapping room2)
{
    int r1_left = room1["x"];
    int r1_right = room1["x"] + room1["width"] - 1;
    int r1_top = room1["y"];
    int r1_bottom = room1["y"] + room1["height"] - 1;
    
    int r2_left = room2["x"];
    int r2_right = room2["x"] + room2["width"] - 1;
    int r2_top = room2["y"];
    int r2_bottom = room2["y"] + room2["height"] - 1;
    
    int center_x1 = room1["x"] + room1["width"] / 2;
    int center_y1 = room1["y"] + room1["height"] / 2;
    int center_x2 = room2["x"] + room2["width"] / 2;
    int center_y2 = room2["y"] + room2["height"] / 2;
    
    int dx = center_x2 - center_x1;
    int dy = center_y2 - center_y1;
    
    if (abs(dx) > abs(dy))
    {
        int corridor_y = center_y1;
        int start_x = (dx > 0) ? r1_right : r1_left;
        int end_x = (dx > 0) ? r2_left : r2_right;
        
        createHorizontalCorridor(layout, roomIds, start_x, center_x2, corridor_y, room1["id"]);
        
        if (dy != 0)
        {
            int start_y = corridor_y;
            int end_y = (dy > 0) ? r2_top : r2_bottom;
            createVerticalCorridor(layout, roomIds, start_y, end_y, center_x2, room2["id"]);
        }
    }
    else
    {
        int corridor_x = center_x1;
        int start_y = (dy > 0) ? r1_bottom : r1_top;
        int end_y = (dy > 0) ? r2_top : r2_bottom;
        
        createVerticalCorridor(layout, roomIds, start_y, center_y2, corridor_x, room1["id"]);
        
        if (dx != 0)
        {
            int start_x = corridor_x;
            int end_x = (dx > 0) ? r2_left : r2_right;
            createHorizontalCorridor(layout, roomIds, start_x, end_x, center_y2, room2["id"]);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void connectRoomsWithDoors(mixed *layout, int **roomIds, 
    mapping **doorData, mapping *rooms)
{
    for (int i = 1; i < sizeof(rooms); i++)
    {
        addDoorBetweenRooms(layout, roomIds, doorData, rooms[i], rooms[0]);
    }
}
