//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

/////////////////////////////////////////////////////////////////////////////
protected nomask int *getTargetCoordinates(int x, int y, string direction)
{
    int targetX = x;
    int targetY = y;
    
    if (direction == "north")
    {
        targetY++;  // North is UP, which is LOWER Y in the array
    }
    else if (direction == "south")
    {
        targetY--;  // South is DOWN, which is HIGHER Y in the array
    }
    else if (direction == "east")
    {
        targetX++;  // East is RIGHT, which is HIGHER X
    }
    else if (direction == "west")
    {
        targetX--;  // West is LEFT, which is LOWER X
    }
    
    return ({ targetX, targetY });
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int isValidCoordinate(int x, int y, int maxX, int maxY)
{
    return (x >= 0) && (x < maxX) && (y >= 0) && (y < maxY);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int hasConnectionInDirection(int x, int y, mixed *layout, 
    string direction)
{
    int maxY = sizeof(layout);
    int maxX = sizeof(layout[0]);
    int *target = getTargetCoordinates(x, y, direction);
    int connected = 0;
    
    if (isValidCoordinate(target[0], target[1], maxX, maxY))
    {
        connected = (layout[target[1]][target[0]] > 1);
    }
    return connected;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int isAgainstWall(int x, int y, mixed *layout, 
    string direction)
{
    int maxY = sizeof(layout);
    int maxX = sizeof(layout[0]);
    int *target = getTargetCoordinates(x, y, direction);
    int isWall = 0;
    
    if (!isValidCoordinate(target[0], target[1], maxX, maxY))
    {
        isWall = 1;
    }
    else
    {
        isWall = (layout[target[1]][target[0]] <= 1);
    }
    return isWall;
}
