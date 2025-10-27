//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/environment/modules/regions/building-doors.c";

/////////////////////////////////////////////////////////////////////////////
private nomask int *scanHorizontalBounds(int x, int y, mixed *layout, 
    int **roomIds)
{
    int myRoomId = roomIds[y][x];
    int layoutMaxX = sizeof(layout[0]);
    int minX = x;
    int maxX = x;
    
    for (int sx = x - 1; sx >= 0 && layout[y][sx] >= 2 && 
         roomIds[y][sx] == myRoomId; sx--)
    {
        minX = sx;
    }
    
    for (int sx = x + 1; sx < layoutMaxX && layout[y][sx] >= 2 && 
         roomIds[y][sx] == myRoomId; sx++)
    {
        maxX = sx;
    }
    
    return ({ minX, maxX });
}

/////////////////////////////////////////////////////////////////////////////
private nomask int *scanVerticalBounds(int x, int y, mixed *layout, 
    int **roomIds)
{
    int myRoomId = roomIds[y][x];
    int layoutMaxY = sizeof(layout);
    int minY = y;
    int maxY = y;
    
    for (int sy = y - 1; sy >= 0 && layout[sy][x] >= 2 && 
         roomIds[sy][x] == myRoomId; sy--)
    {
        minY = sy;
    }
    
    for (int sy = y + 1; sy < layoutMaxY && layout[sy][x] >= 2 && 
         roomIds[sy][x] == myRoomId; sy++)
    {
        maxY = sy;
    }
    
    return ({ minY, maxY });
}

/////////////////////////////////////////////////////////////////////////////
protected nomask mapping findRoomBounds(int x, int y, mixed *layout, 
    int **roomIds)
{
    mapping ret = 0;
    
    if (layout[y][x] >= 2)
    {
        int *horizontal = scanHorizontalBounds(x, y, layout, roomIds);
        int *vertical = scanVerticalBounds(x, y, layout, roomIds);
        
        int minX = horizontal[0];
        int maxX = horizontal[1];
        int minY = vertical[0];
        int maxY = vertical[1];
        
        ret = ([
            "minX": minX,
            "maxX": maxX,
            "minY": minY,
            "maxY": maxY,
            "width": maxX - minX + 1,
            "height": maxY - minY + 1
        ]);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int isRoomLargeEnough(int x, int y, mixed *layout, 
    int **roomIds)
{
    mapping bounds = findRoomBounds(x, y, layout, roomIds);
    int isLarge = 0;
    
    if (bounds)
    {
        isLarge = (bounds["width"] >= 2 && bounds["height"] >= 2);
    }
    return isLarge;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int hasDoorInDirection(int x, int y, mapping **doorData, 
    string direction)
{
    int maxY = sizeof(doorData);
    int maxX = sizeof(doorData[0]);
    int hasDoor = 0;
    
    if (x >= 0 && x < maxX && y >= 0 && y < maxY && 
        member(doorData[y][x], direction))
    {
        hasDoor = doorData[y][x][direction];
    }
    return hasDoor;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int checkAdjacentDoor(int x, int y, mapping **doorData, 
    string direction, string opposite)
{
    int hasDoor = hasDoorInDirection(x, y, doorData, direction);
    
    if (!hasDoor)
    {
        int *target = getTargetCoordinates(x, y, direction);
        int maxY = sizeof(doorData);
        int maxX = sizeof(doorData[0]);
        
        if (target[0] >= 0 && target[0] < maxX && 
            target[1] >= 0 && target[1] < maxY)
        {
            hasDoor = hasDoorInDirection(target[0], target[1], doorData, 
                opposite);
        }
    }
    return hasDoor;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string selectCornerDecorator(int northWall, int southWall, 
    int eastWall, int westWall)
{
    string ret = "floor";
    
    if (northWall && eastWall)
    {
        ret = "northeast corner";
    }
    else if (northWall && westWall)
    {
        ret = "northwest corner";
    }
    else if (southWall && eastWall)
    {
        ret = "southeast corner";
    }
    else if (southWall && westWall)
    {
        ret = "southwest corner";
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string selectWallDecorator(int northWall, int southWall, 
    int eastWall, int westWall)
{
    string ret = "floor";
    
    if (northWall)
    {
        ret = "north wall";
    }
    else if (southWall)
    {
        ret = "south wall";
    }
    else if (eastWall)
    {
        ret = "east wall";
    }
    else if (westWall)
    {
        ret = "west wall";
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string determineRoomWallDecor(int northWall, int southWall, 
    int eastWall, int westWall)
{
    string ret = "floor";
    int wallCount = northWall + southWall + eastWall + westWall;
    
    if (wallCount >= 2)
    {
        ret = selectCornerDecorator(northWall, southWall, eastWall, westWall);
        if (ret == "floor")
        {
            ret = selectWallDecorator(northWall, southWall, eastWall, 
                westWall);
        }
    }
    else if (wallCount == 1)
    {
        ret = selectWallDecorator(northWall, southWall, eastWall, westWall);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string *collectDoorEntries(int northDoor, int southDoor, 
    int eastDoor, int westDoor)
{
    string *entries = ({});
    
    if (northDoor)
    {
        entries += ({ "north" });
    }
    if (southDoor)
    {
        entries += ({ "south" });
    }
    if (eastDoor)
    {
        entries += ({ "east" });
    }
    if (westDoor)
    {
        entries += ({ "west" });
    }
    return entries;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string addDoorEntriesToDecor(string baseDecor, 
    string *entries)
{
    string ret = baseDecor;
    
    if (sizeof(entries) && ret != "floor")
    {
        ret += " " + implode(entries, "-") + " entry";
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string determineLargeRoomDecor(int x, int y, mixed *layout, 
    mapping **doorData)
{
    int northWall = isAgainstWall(x, y, layout, "north");
    int southWall = isAgainstWall(x, y, layout, "south");
    int eastWall = isAgainstWall(x, y, layout, "east");
    int westWall = isAgainstWall(x, y, layout, "west");
    
    string baseDecor = determineRoomWallDecor(northWall, southWall, 
        eastWall, westWall);
    
    int northDoor = checkAdjacentDoor(x, y, doorData, "north", "south");
    int southDoor = checkAdjacentDoor(x, y, doorData, "south", "north");
    int eastDoor = checkAdjacentDoor(x, y, doorData, "east", "west");
    int westDoor = checkAdjacentDoor(x, y, doorData, "west", "east");
    
    string *entries = collectDoorEntries(northDoor, southDoor, eastDoor, 
        westDoor);
    
    return addDoorEntriesToDecor(baseDecor, entries);
}

/////////////////////////////////////////////////////////////////////////////
private nomask string *collectAlcoveDoors(int northDoor, int southDoor, 
    int eastDoor, int westDoor, int north, int south, int east, int west)
{
    string *entries = ({});
    
    if (!north && northDoor)
    {
        entries += ({ "north" });
    }
    if (!south && southDoor)
    {
        entries += ({ "south" });
    }
    if (!east && eastDoor)
    {
        entries += ({ "east" });
    }
    if (!west && westDoor)
    {
        entries += ({ "west" });
    }
    return entries;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string determineAlcoveDecor(int north, int south, int east, 
    int west, int northDoor, int southDoor, int eastDoor, int westDoor)
{
    string ret = "floor";
    
    // Name alcove for wall opposite the single exit
    if (east)
    {
        ret = "west alcove";
    }
    else if (west)
    {
        ret = "east alcove";
    }
    else if (north)
    {
        ret = "south alcove";
    }
    else if (south)
    {
        ret = "north alcove";
    }
    
    string *entries = collectAlcoveDoors(northDoor, southDoor, eastDoor, 
        westDoor, north, south, east, west);
    
    if (sizeof(entries))
    {
        ret = implode(entries, "-") + " entry " + ret;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string *collectPerpendicularDoors(int door1, int door2)
{
    string *entries = ({});
    
    if (door1)
    {
        entries += ({ "east" });
    }
    if (door2)
    {
        entries += ({ "west" });
    }
    return entries;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string determineStraightHallway(string orientation, 
    int door1, int door2)
{
    string ret = orientation + " hallway";
    string *entries = collectPerpendicularDoors(door1, door2);
    
    if (sizeof(entries))
    {
        ret += " " + implode(entries, "-") + " entry";
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string *collectCornerDoors(int door1, int door2)
{
    string *entries = ({});
    
    if (door1)
    {
        entries += ({ "south" });
    }
    if (door2)
    {
        entries += ({ "west" });
    }
    return entries;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string determineCornerHallway(string corner, int door1, 
    int door2)
{
    string ret = corner + " corner hallway";
    string *entries = collectCornerDoors(door1, door2);
    
    if (sizeof(entries))
    {
        ret += " " + implode(entries, "-") + " entry";
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string determineTwoExitDecor(int north, int south, int east, 
    int west, int northDoor, int southDoor, int eastDoor, int westDoor)
{
    string ret = "floor";
    
    if (north && south)
    {
        ret = determineStraightHallway("north-south", eastDoor, westDoor);
    }
    else if (east && west)
    {
        ret = determineStraightHallway("east-west", northDoor, southDoor);
    }
    else if (north && east)
    {
        ret = determineCornerHallway("north-east", southDoor, westDoor);
    }
    else if (north && west)
    {
        ret = determineCornerHallway("north-west", southDoor, eastDoor);
    }
    else if (south && east)
    {
        ret = determineCornerHallway("south-east", northDoor, westDoor);
    }
    else if (south && west)
    {
        ret = determineCornerHallway("south-west", northDoor, eastDoor);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string determineTIntersection(int north, int south, int east, 
    int west, int northDoor, int southDoor, int eastDoor, int westDoor)
{
    string ret = "floor";
    
    if (!south)
    {
        ret = "north T-intersection";
        if (southDoor)
        {
            ret += " south entry";
        }
    }
    else if (!north)
    {
        ret = "south T-intersection";
        if (northDoor)
        {
            ret += " north entry";
        }
    }
    else if (!west)
    {
        ret = "east T-intersection";
        if (westDoor)
        {
            ret += " west entry";
        }
    }
    else if (!east)
    {
        ret = "west T-intersection";
        if (eastDoor)
        {
            ret += " east entry";
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string determineCorridorDecor(int north, int south, int east, 
    int west, int northDoor, int southDoor, int eastDoor, int westDoor, 
    int exitCount)
{
    string ret = "floor";
    
    if (exitCount == 1)
    {
        ret = determineAlcoveDecor(north, south, east, west, northDoor, 
            southDoor, eastDoor, westDoor);
    }
    else if (exitCount == 2)
    {
        ret = determineTwoExitDecor(north, south, east, west, northDoor, 
            southDoor, eastDoor, westDoor);
    }
    else if (exitCount == 3)
    {
        ret = determineTIntersection(north, south, east, west, northDoor, 
            southDoor, eastDoor, westDoor);
    }
    else if (exitCount == 4)
    {
        ret = "4-way hallway";
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string determineSmallRoomDecor(int x, int y, mixed *layout, 
    mapping **doorData)
{
    int north = hasConnectionInDirection(x, y, layout, "north");
    int south = hasConnectionInDirection(x, y, layout, "south");
    int east = hasConnectionInDirection(x, y, layout, "east");
    int west = hasConnectionInDirection(x, y, layout, "west");
    int exitCount = north + south + east + west;
    
    int northDoor = checkAdjacentDoor(x, y, doorData, "north", "south");
    int southDoor = checkAdjacentDoor(x, y, doorData, "south", "north");
    int eastDoor = checkAdjacentDoor(x, y, doorData, "east", "west");
    int westDoor = checkAdjacentDoor(x, y, doorData, "west", "east");
    
    return determineCorridorDecor(north, south, east, west, northDoor, 
        southDoor, eastDoor, westDoor, exitCount);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string determineRoomLayoutType(int x, int y, mixed *layout, 
    int **roomIds, mapping **doorData)
{
    string ret = "floor";
    
    if (isRoomLargeEnough(x, y, layout, roomIds))
    {
        ret = determineLargeRoomDecor(x, y, layout, doorData);
    }
    else
    {
        ret = determineSmallRoomDecor(x, y, layout, doorData);
    }
    return ret;
}
