//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

/////////////////////////////////////////////////////////////////////////////
private nomask mapping getTunnelingParameters(string dungeonType)
{
    mapping ret = ([
        "width": 25,
        "height": 10,
        "tunnels": 10,  
        "min_length": 12, 
        "max_length": 25, 
        "room_chance": 25,
        "winding": 15,   
    ]);
    
    mapping typeParams = ([
        "crypt":([
            "width": 25,
            "height": 10,
            "tunnels": 10,    
            "min_length": 15,   
            "max_length": 25, 
            "room_chance": 25,
            "winding": 15,   
        ]),
        "cave": ([
            "width": 25,
            "height": 10,
            "tunnels": 10,   
            "min_length": 12,
            "max_length": 30, 
            "room_chance": 10,
            "winding": 25,     
        ]),
        "mine": ([
            "width": 25,
            "height": 10,
            "tunnels": 8,    
            "min_length": 10,
            "max_length": 22, 
            "room_chance": 20,
            "winding": 8,   
        ]),
        "dungeon": ([
            "width": 25,
            "height": 10,
            "tunnels": 7,   
            "min_length": 10,
            "max_length": 20,
            "room_chance": 30,
            "winding": 12, 
        ]),
    ]);
    
    if (member(typeParams, dungeonType))
    {
        ret = typeParams[dungeonType];
    }
    
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int *getEntrancePosition(int width, int height, string direction)
{
    int *ret = allocate(2);
    int x = width / 2;
    int y = height / 2;
    
    switch (direction)
    {
        case "north":
        {
            x = width / 2;
            y = 2;
            break;
        }
        case "south":
        {
            x = width / 2;
            y = height - 3;
            break;
        }
        case "east":
        {
            x = width - 3;
            y = height / 2;
            break;
        }
        case "west":
        {
            x = 2;
            y = height / 2;
            break;
        }
    }
    
    ret[0] = x;
    ret[1] = y;
    
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask void carveRoom(mapping grid, int centerX, int centerY, 
    int width, int height)
{
    int roomWidth = 1 + random(3);
    int roomHeight = 1 + random(3);
    int shape = random(3);
    
    for (int dy = -(roomHeight / 2); dy <= roomHeight / 2; dy++)
    {
        for (int dx = -(roomWidth / 2); dx <= roomWidth / 2; dx++)
        {
            int x = centerX + dx;
            int y = centerY + dy;
            
            if (x >= 1 && x < width - 1 && y >= 1 && y < height - 1)
            {
                int carve = 0;
                
                if (shape == 0)
                {
                    carve = 1;
                }
                else if (shape == 1)
                {
                    if (dx * dx + dy * dy <= (roomWidth * roomHeight) / 4)
                    {
                        carve = 1;
                    }
                }
                else if (shape == 2)
                {
                    if (dx == 0 || dy == 0)
                    {
                        carve = 1;
                    }
                }
                
                if (carve)
                {
                    int currentValue = grid[x][y];
                    if (currentValue == 0 || !currentValue)
                    {
                        grid[x][y] = 2;
                    }
                }
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void carveTunnel(mapping grid, int startX, int startY, 
    int length, int windingFactor, int roomChance, int width, int height,
    int preferredDirection) 
{
    int x = startX;
    int y = startY;
    int direction = preferredDirection; 
    
    for (int i = 0; i < length; i++)
    {
        if (x >= 1 && x < width - 1 && y >= 1 && y < height - 1)
        {
            int currentValue = grid[x][y];
            
            if (currentValue == 0 || !currentValue)
            {
                grid[x][y] = 2;
                
                if (random(100) < roomChance && i > 3)
                {
                    carveRoom(grid, x, y, width, height);
                }
            }
            
            if (random(100) < windingFactor)
            {
                int turnChoice = random(3);
                if (turnChoice == 0)
                {
                    direction = (direction + 1) % 4;
                }
                else if (turnChoice == 1)
                {
                    direction = (direction + 3) % 4;
                }
            }
            
            if (direction == 0)
            {
                y--;
            }
            else if (direction == 1)
            {
                x++;
            }
            else if (direction == 2)
            {
                y++;
            }
            else if (direction == 3)
            {
                x--;
            }
        }
        else
        {
            break;
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void floodFillSection(mapping grid, mapping visited, int x, 
    int y, int width, int height, mixed *section)
{
    if (x >= 0 && x < width && y >= 0 && y < height)
    {
        int gridValue = grid[x][y];
        int visitedValue = visited[x][y];
        
        if (gridValue && gridValue > 0 && !visitedValue)
        {
            visited[x][y] = 1;
            section += ({ ({ x, y }) });
            
            floodFillSection(grid, visited, x + 1, y, width, height, section);
            floodFillSection(grid, visited, x - 1, y, width, height, section);
            floodFillSection(grid, visited, x, y + 1, width, height, section);
            floodFillSection(grid, visited, x, y - 1, width, height, section);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping *findIsolatedSections(mapping grid, int width, 
    int height)
{
    mapping *ret = ({});
    mapping visited = ([]);
    
    for (int x = 0; x < width; x++)
    {
        visited[x] = ([]);
        for (int y = 0; y < height; y++)
        {
            visited[x][y] = 0;
        }
    }
    
    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            int gridValue = grid[x][y];
            int visitedValue = visited[x][y];
            
            if (gridValue && gridValue > 0 && !visitedValue)
            {
                mixed *section = ({});
                floodFillSection(grid, visited, x, y, width, height, section);
                ret += ({ ([ "tiles": section ]) });
            }
        }
    }
    
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask void carveLShapedCorridor(mapping grid, int x1, int y1, 
    int x2, int y2, int width, int height)
{
    int x = x1;
    while (x != x2)
    {
        if (x >= 0 && x < width && y1 >= 0 && y1 < height)
        {
            int currentValue = grid[x][y1];
            if (currentValue == 0 || !currentValue)
            {
                grid[x][y1] = 2;
            }
        }
        
        if (x2 > x1)
        {
            x++;
        }
        else
        {
            x--;
        }
    }
    
    int y = y1;
    while (y != y2)
    {
        if (x2 >= 0 && x2 < width && y >= 0 && y < height)
        {
            int currentValue = grid[x2][y];
            if (currentValue == 0 || !currentValue)
            {
                grid[x2][y] = 2;
            }
        }
        
        if (y2 > y1)
        {
            y++;
        }
        else
        {
            y--;
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void connectTwoSections(mapping grid, mapping section1, 
    mapping section2, int width, int height)
{
    mixed *tiles1 = section1["tiles"];
    mixed *tiles2 = section2["tiles"];
    
    if (sizeof(tiles1) > 0 && sizeof(tiles2) > 0)
    {
        mixed *closest1 = tiles1[0];
        mixed *closest2 = tiles2[0];
        int minDist = 999999;
        
        foreach (mixed *tile1 in tiles1)
        {
            foreach (mixed *tile2 in tiles2)
            {
                int dx = tile1[0] - tile2[0];
                int dy = tile1[1] - tile2[1];
                int dist = dx * dx + dy * dy;
                
                if (dist < minDist)
                {
                    minDist = dist;
                    closest1 = tile1;
                    closest2 = tile2;
                }
            }
        }
        
        carveLShapedCorridor(grid, closest1[0], closest1[1], 
            closest2[0], closest2[1], width, height);
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void connectIsolatedSections(mapping grid, int width, int height)
{
    mapping *sections = findIsolatedSections(grid, width, height);
    
    if (sizeof(sections) > 1)
    {
        for (int i = 1; i < sizeof(sections); i++)
        {
            connectTwoSections(grid, sections[0], sections[i], width, height);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void placeSpecialRooms(mapping grid, int width, int height, 
    string dungeonType)
{
    mixed *rooms = ({});
    
    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            int gridValue = grid[x][y];
            if (gridValue == 2)
            {
                rooms += ({ ({ x, y }) });
            }
        }
    }
    
    if (sizeof(rooms) > 0)
    {
        int randomIndex = random(sizeof(rooms));
        mixed *specialRoom = rooms[randomIndex];
        grid[specialRoom[0]][specialRoom[1]] = 3;
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask mixed *convertGridToLayout(mapping grid, int width, int height)
{
    mixed *ret = allocate(height);
    
    for (int y = 0; y < height; y++)
    {
        ret[y] = allocate(width);
        for (int x = 0; x < width; x++)
        {
            int gridValue = grid[x][y];
            if (gridValue)
            {
                ret[y][x] = gridValue;
            }
            else
            {
                ret[y][x] = 1;
            }
        }
    }
    
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping generateTunnelingDungeon(string entranceDirection, 
    string dungeonType)
{
    mapping ret = 0;
    mapping params = getTunnelingParameters(dungeonType);
    
    int width = params["width"];
    int height = params["height"];
    int numTunnels = params["tunnels"];
    int minTunnelLength = params["min_length"];
    int maxTunnelLength = params["max_length"];
    int roomChance = params["room_chance"];
    int windingFactor = params["winding"];
    
    mapping grid = ([]);
    for (int x = 0; x < width; x++)
    {
        grid[x] = ([]);
        for (int y = 0; y < height; y++)
        {
            grid[x][y] = 0;
        }
    }
    
    int *startPos = getEntrancePosition(width, height, entranceDirection);
    int startX = startPos[0];
    int startY = startPos[1];
    
    // Carve main tunnels with directional bias to spread horizontally
    for (int t = 0; t < numTunnels; t++)
    {
        int tunnelLength = random(maxTunnelLength - minTunnelLength) + minTunnelLength;
        
        // Alternate between east (1) and west (3) to spread horizontally
        int preferredDirection = (t % 2) ? 1 : 3;
        
        // Sometimes use north (0) or south (2) for variety
        if (t % 3 == 0)
        {
            preferredDirection = random(2) ? 0 : 2;
        }
        
        carveTunnel(grid, startX, startY, tunnelLength, windingFactor, 
            roomChance, width, height, preferredDirection);
    }
    
    connectIsolatedSections(grid, width, height);
    placeSpecialRooms(grid, width, height, dungeonType);
    
    grid[startX][startY] = 4;
    
    mixed *layout = convertGridToLayout(grid, width, height);
    
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
    
    mapping roomTypes = ([
        0: ([ "name": "wall", "icon": "wall" ]),
        1: ([ "name": "wall", "icon": "wall" ]),
        2: ([ "name": "room", "icon": "generated" ]),
        3: ([ "name": "room", "icon": "generated" ]),
        4: ([ "name": "entry", "icon": "base+name" ]),
    ]);
    
    ret = ([
        "layout": layout,
        "dimensions": ([ "x": width, "y": height ]),
        "room types": roomTypes,
        "base type": dungeonType + " interior",
        "roomIds": roomIds,
        "doorData": doorData,
    ]);
    
    return ret;
}
