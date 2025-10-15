//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/environment/modules/regions/core.c";

private mapping roomTypes = ([
    0: ([ "name": "empty", "icon": "none" ]),
    1: ([ "name": "wall", "icon": "wall" ]),
    2: ([ "name": "room", "icon": "generated" ]),
    3: ([ "name": "special", "icon": "generated" ]),
    4: ([ "name": "entry", "icon": "generated" ]),
    5: ([ "name": "courtyard", "icon": "base+name" ]),
    6: ([ "name": "throne", "icon": "generated" ]),
    7: ([ "name": "garden", "icon": "base+name" ])
]);

// Building generation parameters by type
private mapping buildingParameters = ([
    "temple": ([
        "base type": "temple interior",
        "room types": roomTypes,
        "min width": 8,
        "max width": 25,
        "min height": 7,
        "max height": 10,
        "complexity": 2,
        "special room": 3,
        "outdoor room": 5,
        "has courtyard": 1,
        "corridor style": "wide"
    ]),
    "keep": ([
        "base type": "keep interior",
        "room types": roomTypes,
        "min width": 8,
        "max width": 25,
        "min height": 7,
        "max height": 10,
        "complexity": 3,
        "special room": 6,
        "outdoor room": 5,
        "secondary outdoor": 7,
        "has courtyard": 1,
        "corridor style": "grand"
    ]),
    "crypt": ([
        "base type": "crypt interior",
        "room types": roomTypes,
        "min width": 8,
        "max width": 25,
        "min height": 7,
        "max height": 10,
        "complexity": 1,
        "special room": 3,
        "outdoor room": 5,
        "has courtyard": 0,
        "corridor style": "narrow"
    ]),
    "ruins": ([
        "base type": "ruined interior",
        "room types": roomTypes,
        "min width": 8,
        "max width": 25,
        "min height": 7,
        "max height": 10,
        "complexity": 2,
        "special room": 3,
        "outdoor room": 5,
        "secondary special": 6,
        "has courtyard": 1,
        "corridor style": "wide",
        "ruined": 1
    ])
]);

/////////////////////////////////////////////////////////////////////////////
public nomask int isBuildingRegionType()
{
    return member(buildingParameters, RegionType);
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getBuildingTemplate(string regionType)
{
    mapping ret = 0;
    
    if (member(buildingParameters, regionType))
    {
        ret = buildingParameters[regionType];
    }
    
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask mixed *createEmptyLayout(int width, int height)
{
    mixed *layout = ({});
    for (int y = 0; y < height; y++)
    {
        int *row = allocate(width);
        layout += ({ row });
    }
    return layout;
}

/////////////////////////////////////////////////////////////////////////////
private nomask void placeRoom(mixed *layout, int x, int y, int width, 
    int height, int roomType)
{
    // Place walls around perimeter
    for (int dx = 0; dx < width; dx++)
    {
        layout[y][x + dx] = 1;  // Top wall
        layout[y + height - 1][x + dx] = 1;  // Bottom wall
    }
    
    for (int dy = 0; dy < height; dy++)
    {
        layout[y + dy][x] = 1;  // Left wall
        layout[y + dy][x + width - 1] = 1;  // Right wall
    }
    
    // Fill interior with room type
    for (int dy = 1; dy < height - 1; dy++)
    {
        for (int dx = 1; dx < width - 1; dx++)
        {
            layout[y + dy][x + dx] = roomType;
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void createDoorway(mixed *layout, int x, int y)
{
    int maxY = sizeof(layout);
    int maxX = sizeof(layout[0]);
    
    if (x >= 0 && x < maxX && y >= 0 && y < maxY)
    {
        if (layout[y][x] == 1)  // Only punch through walls
        {
            layout[y][x] = 2;  // Make it a hallway
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void addInternalWalls(mixed *layout, int x1, int y1, 
    int x2, int y2, string orientation)
{
    if (orientation == "horizontal")
    {
        int wallY = y1 + (y2 - y1) / 2;
        for (int x = x1; x <= x2; x++)
        {
            if (layout[wallY][x] == 2)
            {
                layout[wallY][x] = 1;
            }
        }
        
        // Add doorway
        int doorX = x1 + (x2 - x1) / 2 + (random(3) - 1);
        if (doorX >= x1 && doorX <= x2)
        {
            createDoorway(layout, doorX, wallY);
        }
    }
    else  // vertical
    {
        int wallX = x1 + (x2 - x1) / 2;
        for (int y = y1; y <= y2; y++)
        {
            if (layout[y][wallX] == 2)
            {
                layout[y][wallX] = 1;
            }
        }
        
        // Add doorway
        int doorY = y1 + (y2 - y1) / 2 + (random(3) - 1);
        if (doorY >= y1 && doorY <= y2)
        {
            createDoorway(layout, wallX, doorY);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void subdivideSpace(mixed *layout, int x1, int y1, int x2, 
    int y2, int depth, int maxDepth)
{
    // Stop subdividing if space too small or depth reached
    int width = x2 - x1;
    int height = y2 - y1;
    
    if (depth >= maxDepth || width < 5 || height < 5)
    {
        return;
    }
    
    // Decide whether to split horizontally or vertically
    int horizontal = (height > width) ? 1 : 0;
    if (height == width)
    {
        horizontal = random(2);
    }
    
    if (horizontal && height >= 8)
    {
        addInternalWalls(layout, x1 + 1, y1 + 1, x2 - 1, y2 - 1, "horizontal");
        
        int midY = y1 + height / 2;
        subdivideSpace(layout, x1, y1, x2, midY, depth + 1, maxDepth);
        subdivideSpace(layout, x1, midY, x2, y2, depth + 1, maxDepth);
    }
    else if (!horizontal && width >= 8)
    {
        addInternalWalls(layout, x1 + 1, y1 + 1, x2 - 1, y2 - 1, "vertical");
        
        int midX = x1 + width / 2;
        subdivideSpace(layout, x1, y1, midX, y2, depth + 1, maxDepth);
        subdivideSpace(layout, midX, y1, x2, y2, depth + 1, maxDepth);
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void createAlcove(mixed *layout, int x, int y, string direction,
    int depth)
{
    int maxY = sizeof(layout);
    int maxX = sizeof(layout[0]);
    
    if (direction == "north")
    {
        for (int d = 0; d < depth; d++)
        {
            int alcY = y - d;
            if (alcY >= 0)
            {
                layout[alcY][x] = 2;
                if (d < depth - 1 && x > 0)
                {
                    layout[alcY][x - 1] = 1;
                }
                if (d < depth - 1 && x < maxX - 1)
                {
                    layout[alcY][x + 1] = 1;
                }
            }
        }
    }
    else if (direction == "south")
    {
        for (int d = 0; d < depth; d++)
        {
            int alcY = y + d;
            if (alcY < maxY)
            {
                layout[alcY][x] = 2;
                if (d < depth - 1 && x > 0)
                {
                    layout[alcY][x - 1] = 1;
                }
                if (d < depth - 1 && x < maxX - 1)
                {
                    layout[alcY][x + 1] = 1;
                }
            }
        }
    }
    else if (direction == "east")
    {
        for (int d = 0; d < depth; d++)
        {
            int alcX = x + d;
            if (alcX < maxX)
            {
                layout[y][alcX] = 2;
                if (d < depth - 1 && y > 0)
                {
                    layout[y - 1][alcX] = 1;
                }
                if (d < depth - 1 && y < maxY - 1)
                {
                    layout[y + 1][alcX] = 1;
                }
            }
        }
    }
    else if (direction == "west")
    {
        for (int d = 0; d < depth; d++)
        {
            int alcX = x - d;
            if (alcX >= 0)
            {
                layout[y][alcX] = 2;
                if (d < depth - 1 && y > 0)
                {
                    layout[y - 1][alcX] = 1;
                }
                if (d < depth - 1 && y < maxY - 1)
                {
                    layout[y + 1][alcX] = 1;
                }
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void addAlcoves(mixed *layout, int count)
{
    int maxY = sizeof(layout);
    int maxX = sizeof(layout[0]);
    
    for (int i = 0; i < count; i++)
    {
        // Find a wall location
        int attempts = 0;
        while (attempts < 20)
        {
            int x = 2 + random(maxX - 4);
            int y = 2 + random(maxY - 4);
            
            if (layout[y][x] == 2)
            {
                // Check which direction has a wall
                if (x > 1 && layout[y][x - 1] == 1)
                {
                    createAlcove(layout, x, y, "west", 2 + random(2));
                    break;
                }
                else if (x < maxX - 2 && layout[y][x + 1] == 1)
                {
                    createAlcove(layout, x, y, "east", 2 + random(2));
                    break;
                }
                else if (y > 1 && layout[y - 1][x] == 1)
                {
                    createAlcove(layout, x, y, "north", 2 + random(2));
                    break;
                }
                else if (y < maxY - 2 && layout[y + 1][x] == 1)
                {
                    createAlcove(layout, x, y, "south", 2 + random(2));
                    break;
                }
            }
            attempts++;
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void placeSpecialRoom(mixed *layout, int specialType)
{
    int maxY = sizeof(layout);
    int maxX = sizeof(layout[0]);
    
    // Find center area rooms
    int centerX = maxX / 2;
    int centerY = maxY / 2;
    int searchRadius = 2;
    
    for (int dy = -searchRadius; dy <= searchRadius; dy++)
    {
        for (int dx = -searchRadius; dx <= searchRadius; dx++)
        {
            int x = centerX + dx;
            int y = centerY + dy;
            
            if (x >= 0 && x < maxX && y >= 0 && y < maxY)
            {
                if (layout[y][x] == 2)
                {
                    layout[y][x] = specialType;
                    return;
                }
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void placeEntry(mixed *layout, string enterFrom)
{
    int maxY = sizeof(layout);
    int maxX = sizeof(layout[0]);
    int entryX = maxX / 2;
    int entryY = maxY - 2;
    
    // Determine entry position based on direction
    if (enterFrom == "north")
    {
        entryY = 1;
    }
    else if (enterFrom == "south")
    {
        entryY = maxY - 2;
    }
    else if (enterFrom == "east")
    {
        entryX = maxX - 2;
        entryY = maxY / 2;
    }
    else if (enterFrom == "west")
    {
        entryX = 1;
        entryY = maxY / 2;
    }
    
    // Find nearest room cell
    for (int radius = 0; radius < 5; radius++)
    {
        for (int dy = -radius; dy <= radius; dy++)
        {
            for (int dx = -radius; dx <= radius; dx++)
            {
                int x = entryX + dx;
                int y = entryY + dy;
                
                if (x >= 0 && x < maxX && y >= 0 && y < maxY)
                {
                    if (layout[y][x] == 2)
                    {
                        layout[y][x] = 4;
                        return;
                    }
                }
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void addCourtyard(mixed *layout, int courtyardType)
{
    int maxY = sizeof(layout);
    int maxX = sizeof(layout[0]);
    
    // Place courtyard at bottom center
    int x = maxX / 2;
    int y = maxY - 1;
    
    if (y >= 0 && x >= 0 && x < maxX)
    {
        layout[y][x] = courtyardType;
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void addRuinedSections(mixed *layout)
{
    int maxY = sizeof(layout);
    int maxX = sizeof(layout[0]);
    
    // Randomly remove some walls/corners for ruined effect
    int ruinCount = 2 + random(4);
    
    for (int i = 0; i < ruinCount; i++)
    {
        int x = random(maxX);
        int y = random(maxY);
        
        if (layout[y][x] == 1)
        {
            layout[y][x] = 0;
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
// Architectural chunk templates define pre-designed room groups
private mapping architecturalChunks = ([
    "great_hall": ([
        "width": 4,
        "height": 10,
        "pattern": ({
            ({ 1, 1, 1, 1 }),  // Top wall
            ({ 1, 2, 2, 1 }),  // Open interior
            ({ 1, 2, 2, 1 }),
            ({ 1, 2, 2, 1 }),
            ({ 1, 2, 6, 1 }),  // Throne area
            ({ 1, 2, 2, 1 }),
            ({ 1, 2, 2, 1 }),
            ({ 1, 2, 2, 1 }),
            ({ 1, 2, 2, 1 }),
            ({ 1, 1, 1, 1 })   // Bottom wall
        }),
        "entry_points": ({ "west", "east" })  // Where this can connect
    ]),
    "side_chambers": ([
        "width": 7,
        "height": 5,
        "pattern": ({
            ({ 1, 1, 1, 1, 1, 1, 1 }),
            ({ 1, 2, 2, 2, 2, 2, 1 }),
            ({ 1, 2, 2, 2, 2, 2, 1 }),
            ({ 1, 2, 2, 2, 2, 2, 1 }),
            ({ 1, 1, 1, 4, 1, 1, 1 })  // Entry at bottom center
        }),
        "entry_points": ({ "south" })
    ]),
    "courtyard": ([
        "width": 3,
        "height": 3,
        "pattern": ({
            ({ 5, 5, 5 }),
            ({ 5, 5, 5 }),
            ({ 5, 5, 5 })
        }),
        "entry_points": ({ "north", "south", "east", "west" })
    ])
]);

/////////////////////////////////////////////////////////////////////////////
private nomask void placeChunk(mixed *layout, mapping chunk, int startX, 
    int startY)
{
    mixed *pattern = chunk["pattern"];
    int chunkHeight = sizeof(pattern);
    int chunkWidth = sizeof(pattern[0]);
    
    for (int y = 0; y < chunkHeight; y++)
    {
        for (int x = 0; x < chunkWidth; x++)
        {
            int layoutX = startX + x;
            int layoutY = startY + y;
            
            if (layoutY >= 0 && layoutY < sizeof(layout) &&
                layoutX >= 0 && layoutX < sizeof(layout[0]))
            {
                layout[layoutY][layoutX] = pattern[y][x];
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask mixed *generateBuildingLayout(string enterFrom)
{
    mapping params = buildingParameters[RegionType];
    
    int width = params["min width"] + random(params["max width"] - 
        params["min width"] + 1);
    int height = params["min height"] + random(params["max height"] - 
        params["min height"] + 1);
    
    mixed *layout = createEmptyLayout(width, height);
    
    int complexity = params["complexity"];
    
    // Place architectural chunks based on complexity
    if (complexity == 3)  // Keep - great hall + side chambers
    {
        // Place great hall in center-left
        if (width >= 12 && height >= 10)
        {
            placeChunk(layout, architecturalChunks["great_hall"], 
                1, 0);
            
            // Add side chambers
            if (width >= 15)
            {
                placeChunk(layout, architecturalChunks["side_chambers"],
                    width - 8, 0);
            }
        }
    }
    else if (complexity == 2)  // Temple - courtyard + chambers
    {
        // Create main rectangular structure
        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                if (x == 0 || x == width - 1 || y == 0 || y == height - 1)
                {
                    layout[y][x] = 1;  // Walls
                }
                else
                {
                    layout[y][x] = 2;  // Open space
                }
            }
        }
        
        // Place courtyard if there's room
        if (width >= 8 && height >= 8)
        {
            int courtyardX = width / 2 - 1;
            int courtyardY = height / 2 - 1;
            placeChunk(layout, architecturalChunks["courtyard"],
                courtyardX, courtyardY);
        }
        
        // Add altar/special room
        if (member(params, "special room"))
        {
            int specialX = width / 3;
            int specialY = height / 4;
            if (layout[specialY][specialX] == 2)
            {
                layout[specialY][specialX] = params["special room"];
            }
        }
    }
    else  // Crypt - simple corridors
    {
        // Create basic corridor structure
        for (int x = 0; x < width; x++)
        {
            layout[0][x] = 1;
            layout[height-1][x] = 1;
        }
        for (int y = 0; y < height; y++)
        {
            layout[y][0] = 1;
            layout[y][width-1] = 1;
        }
        
        // Central corridor
        int midY = height / 2;
        for (int x = 1; x < width - 1; x++)
        {
            layout[midY][x] = 2;
        }
        
        // Side chambers
        for (int y = 1; y < height - 1; y++)
        {
            if (y != midY)
            {
                int leftChamberX = width / 4;
                int rightChamberX = 3 * width / 4;
                layout[y][leftChamberX] = 2;
                layout[y][rightChamberX] = 2;
            }
        }
    }
    
    // Place entry point
    int entryX = width / 2;
    int entryY = 0;
    
    if (enterFrom == "south")
    {
        entryY = height - 1;
    }
    else if (enterFrom == "east")
    {
        entryX = width - 1;
        entryY = height / 2;
    }
    else if (enterFrom == "west")
    {
        entryX = 0;
        entryY = height / 2;
    }
    
    // Mark entry and adjacent cells
    if (entryY > 0 && entryY < height - 1)
    {
        layout[entryY][entryX] = 4;
        if (enterFrom == "north" || enterFrom == "south")
        {
            int adjacentY = (enterFrom == "north") ? entryY + 1 : entryY - 1;
            layout[adjacentY][entryX] = 4;
        }
        else
        {
            int adjacentX = (enterFrom == "west") ? entryX + 1 : entryX - 1;
            if (adjacentX >= 0 && adjacentX < width)
            {
                layout[entryY][adjacentX] = 4;
            }
        }
    }
    
    // Add ruined sections
    if (member(params, "ruined"))
    {
        addRuinedSections(layout);
    }
    
    return layout;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int hasConnectionInDirection(int x, int y, mixed *layout, 
    string direction)
{
    int ret = 0;
    int maxY = sizeof(layout);
    int maxX = sizeof(layout[0]);
    int targetX = x;
    int targetY = y;
    
    if (direction == "north")
    {
        targetY--;
    }
    else if (direction == "south")
    {
        targetY++;
    }
    else if (direction == "east")
    {
        targetX++;
    }
    else if (direction == "west")
    {
        targetX--;
    }
    
    if ((targetX >= 0) && (targetX < maxX) && 
        (targetY >= 0) && (targetY < maxY))
    {
        int *row = layout[targetY];
        if (row[targetX] > 1)
        {
            ret = 1;
        }
    }
    
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int hasRoomForEntry(int x, int y, mixed *layout, string direction)
{
    int ret = 0;
    int maxY = sizeof(layout);
    int maxX = sizeof(layout[0]);
    int targetX = x;
    int targetY = y;
    
    if (direction == "north")
    {
        targetY--;
    }
    else if (direction == "south")
    {
        targetY++;
    }
    else if (direction == "east")
    {
        targetX++;
    }
    else if (direction == "west")
    {
        targetX--;
    }
    
    if ((targetX >= 0) && (targetX < maxX) && 
        (targetY >= 0) && (targetY < maxY))
    {
        int *row = layout[targetY];
        if (row[targetX] >= 2)
        {
            ret = 1;
        }
    }
    
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string detectSideEntries(int x, int y, mixed *layout, 
    string hallwayType)
{
    string ret = "";
    
    if (hallwayType == "north-south")
    {
        int eastEntry = hasRoomForEntry(x, y, layout, "east");
        int westEntry = hasRoomForEntry(x, y, layout, "west");
        
        if (eastEntry && westEntry)
        {
            ret = "east-west";
        }
        else if (eastEntry)
        {
            ret = "east";
        }
        else if (westEntry)
        {
            ret = "west";
        }
    }
    else if (hallwayType == "east-west")
    {
        int northEntry = hasRoomForEntry(x, y, layout, "north");
        int southEntry = hasRoomForEntry(x, y, layout, "south");
        
        if (northEntry && southEntry)
        {
            ret = "north-south";
        }
        else if (northEntry)
        {
            ret = "north";
        }
        else if (southEntry)
        {
            ret = "south";
        }
    }
    
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string determineSingleExitLayoutWithEntries(int x, int y, 
    mixed *layout, int north, int south, int east, int west)
{
    string ret = "floor";
    string *entries = ({});
    
    if (north)
    {
        ret = "north alcove";
    }
    else if (south)
    {
        ret = "south alcove";
    }
    else if (east)
    {
        ret = "east alcove";
    }
    else if (west)
    {
        ret = "west alcove";
    }
    
    if (!north && hasRoomForEntry(x, y, layout, "north"))
    {
        entries += ({ "north" });
    }
    if (!south && hasRoomForEntry(x, y, layout, "south"))
    {
        entries += ({ "south" });
    }
    if (!east && hasRoomForEntry(x, y, layout, "east"))
    {
        entries += ({ "east" });
    }
    if (!west && hasRoomForEntry(x, y, layout, "west"))
    {
        entries += ({ "west" });
    }
    
    if (sizeof(entries))
    {
        ret = implode(entries, "-") + " entry " + ret;
    }
    
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string determineCornerLayout(int north, int south, 
    int east, int west)
{
    string ret = "floor";
    
    if (north && east)
    {
        ret = "north-east corner hallway";
    }
    else if (north && west)
    {
        ret = "north-west corner hallway";
    }
    else if (south && east)
    {
        ret = "south-east corner hallway";
    }
    else if (south && west)
    {
        ret = "south-west corner hallway";
    }
    
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string determineTwoExitLayoutWithEntries(int x, int y, 
    mixed *layout, int north, int south, int east, int west)
{
    string ret = "floor";
    
    if ((north && east) || (north && west) || 
        (south && east) || (south && west))
    {
        ret = determineCornerLayout(north, south, east, west);
        string *entries = ({});
        
        if (!north && hasRoomForEntry(x, y, layout, "north"))
        {
            entries += ({ "north" });
        }
        if (!south && hasRoomForEntry(x, y, layout, "south"))
        {
            entries += ({ "south" });
        }
        if (!east && hasRoomForEntry(x, y, layout, "east"))
        {
            entries += ({ "east" });
        }
        if (!west && hasRoomForEntry(x, y, layout, "west"))
        {
            entries += ({ "west" });
        }
        
        if (sizeof(entries))
        {
            ret += " " + implode(entries, "-") + " entry";
        }
    }
    else
    {
        if (north && south)
        {
            ret = "north-south hallway";
            string entryDir = detectSideEntries(x, y, layout, "north-south");
            if (entryDir)
            {
                ret += " " + entryDir + " entry";
            }
        }
        else if (east && west)
        {
            ret = "east-west hallway";
            string entryDir = detectSideEntries(x, y, layout, "east-west");
            if (entryDir)
            {
                ret += " " + entryDir + " entry";
            }
        }
    }
    
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string determineThreeExitLayoutWithEntries(int x, int y, 
    mixed *layout, int north, int south, int east, int west)
{
    string ret = "floor";
    
    if (!north)
    {
        ret = "south T-intersection";
        if (hasRoomForEntry(x, y, layout, "north"))
        {
            ret += " north entry";
        }
    }
    else if (!south)
    {
        ret = "north T-intersection";
        if (hasRoomForEntry(x, y, layout, "south"))
        {
            ret += " south entry";
        }
    }
    else if (!east)
    {
        ret = "west T-intersection";
        if (hasRoomForEntry(x, y, layout, "east"))
        {
            ret += " east entry";
        }
    }
    else if (!west)
    {
        ret = "east T-intersection";
        if (hasRoomForEntry(x, y, layout, "west"))
        {
            ret += " west entry";
        }
    }
    
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string determineRoomLayoutType(int x, int y, mixed *layout)
{
    string ret = "floor";
    
    int north = hasConnectionInDirection(x, y, layout, "north");
    int south = hasConnectionInDirection(x, y, layout, "south");
    int east = hasConnectionInDirection(x, y, layout, "east");
    int west = hasConnectionInDirection(x, y, layout, "west");
    
    int exitCount = north + south + east + west;
    
    // Check if this is a corridor (straight hallway with exactly 2 opposite exits)
    int isCorridor = 0;
    if ((north && south) && (!east && !west))
    {
        ret = "north-south hallway";
        isCorridor = 1;
        string entryDir = detectSideEntries(x, y, layout, "north-south");
        if (entryDir)
        {
            ret += " " + entryDir + " entry";
        }
    }
    else if ((east && west) && (!north && !south))
    {
        ret = "east-west hallway";
        isCorridor = 1;
        string entryDir = detectSideEntries(x, y, layout, "east-west");
        if (entryDir)
        {
            ret += " " + entryDir + " entry";
        }
    }
    // If not a corridor, check for T-intersections and corners
    else if (exitCount == 1)
    {
        ret = determineSingleExitLayoutWithEntries(x, y, layout, north, south, 
            east, west);
    }
    else if (exitCount == 3)
    {
        ret = determineThreeExitLayoutWithEntries(x, y, layout, north, south, 
            east, west);
    }
    else if (exitCount == 4)
    {
        ret = "4-way hallway";
    }
    else if (exitCount == 2)
    {
        // Two exits but NOT opposite = corner or room
        ret = determineTwoExitLayoutWithEntries(x, y, layout, north, south, 
            east, west);
    }
    else if (exitCount == 0)
    {
        // Isolated room with no exits
        ret = "floor";
    }
    
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string generateRoomIconKey(int x, int y, mixed *layout, 
    string regionType)
{
    string ret = 0;
    
    mapping template = getBuildingTemplate(regionType);
    string baseType = member(template, "base type") ? 
        template["base type"] : 
        (regionType + " interior");
    
    int *row = layout[y];
    int roomType = row[x];
    
    if ((roomType > 0) && (roomType != 1))
    {
        string roomLayout = determineRoomLayoutType(x, y, layout);
        ret = baseType + " " + roomLayout;
    }
    
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping generateBuildingTemplate(string enterFrom)
{
    mapping params = buildingParameters[RegionType];
    mixed *layout = generateBuildingLayout(enterFrom);
    
    int width = sizeof(layout[0]);
    int height = sizeof(layout);
    
    return ([
        "dimensions": ([ "x": width, "y": height ]),
        "base type": params["base type"],
        "room types": params["room types"],
        "layout": layout
    ]);
}

/////////////////////////////////////////////////////////////////////////////
private nomask string generateSpecialRoomFeatures(string regionType)
{
    string ret = "";
    
    if (regionType == "temple")
    {
        ret += "    addFeature(\"/lib/environment/features/altar.c\", "
            "\"center\");\n";
        ret += "    addFeature(\"/lib/environment/features/brazier.c\", "
            "\"northeast\");\n";
        ret += "    addFeature(\"/lib/environment/features/brazier.c\", "
            "\"northwest\");\n";
    }
    else if (regionType == "keep")
    {
        ret += "    addFeature(\"/lib/environment/features/throne.c\", "
            "\"center\");\n";
        ret += "    addFeature(\"/lib/environment/features/tapestry.c\", "
            "\"north\");\n";
    }
    else if (regionType == "crypt")
    {
        ret += "    addFeature(\"/lib/environment/features/tomb.c\", "
            "\"center\");\n";
        ret += "    addFeature(\"/lib/environment/features/candle.c\", "
            "\"northeast\");\n";
        ret += "    addFeature(\"/lib/environment/features/candle.c\", "
            "\"northwest\");\n";
    }
    else if (regionType == "ruins")
    {
        ret += "    addFeature(\"/lib/environment/features/debris.c\", "
            "\"center\");\n";
        ret += "    addFeature(\"/lib/environment/features/broken-pillar.c\", "
            "\"northeast\");\n";
    }
    
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string generateEntryRoomFeatures(string regionType)
{
    string ret = "";
    
    if (regionType == "temple")
    {
        ret += "    addFeature(\"/lib/environment/features/doorway.c\", "
            "\"center\");\n";
        ret += "    addFeature(\"/lib/environment/features/holy-symbol.c\", "
            "\"north\");\n";
    }
    else if (regionType == "keep")
    {
        ret += "    addFeature(\"/lib/environment/features/portcullis.c\", "
            "\"center\");\n";
        ret += "    addFeature(\"/lib/environment/features/guard-post.c\", "
            "\"east\");\n";
    }
    else if (regionType == "crypt")
    {
        ret += "    addFeature(\"/lib/environment/features/sarcophagus.c\", "
            "\"center\");\n";
    }
    else
    {
        ret += "    addFeature(\"/lib/environment/features/doorway.c\", "
            "\"center\");\n";
    }
    
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string generateCourtyardFeatures(string regionType)
{
    string ret = "";
    
    ret += "    addFeature(\"/lib/environment/features/fountain.c\", "
        "\"center\");\n";
    ret += "    addFeature(\"/lib/environment/features/bench.c\", "
        "\"north\");\n";
    ret += "    addFeature(\"/lib/environment/features/bench.c\", "
        "\"south\");\n";
    
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string generateStandardRoomFeatures(string regionType)
{
    string ret = "";
    
    ret += "    addFeature(\"/lib/environment/features/torch-sconce.c\", "
        "\"north\");\n";
    
    if (random(3))
    {
        ret += "    addFeature(\"/lib/environment/features/debris.c\", "
            "\"corner\");\n";
    }
    
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string generateRoomFeatures(int roomType, string regionType)
{
    string ret = "";
    
    if (roomType == 3)
    {
        ret = generateSpecialRoomFeatures(regionType);
    }
    else if (roomType == 4)
    {
        ret = generateEntryRoomFeatures(regionType);
    }
    else if (roomType == 5)
    {
        ret = generateCourtyardFeatures(regionType);
    }
    else if (roomType == 6)
    {
        ret = generateSpecialRoomFeatures(regionType);
    }
    else if (roomType == 7)
    {
        ret = generateCourtyardFeatures(regionType);
    }
    else
    {
        ret = generateStandardRoomFeatures(regionType);
    }
    
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping generateRoomExits(int x, int y, mixed *layout)
{
    mapping ret = ([]);
    
    if (hasConnectionInDirection(x, y, layout, "north"))
    {
        ret["north"] = ([ "x": x, "y": y - 1 ]);
    }
    if (hasConnectionInDirection(x, y, layout, "south"))
    {
        ret["south"] = ([ "x": x, "y": y + 1 ]);
    }
    if (hasConnectionInDirection(x, y, layout, "east"))
    {
        ret["east"] = ([ "x": x + 1, "y": y ]);
    }
    if (hasConnectionInDirection(x, y, layout, "west"))
    {
        ret["west"] = ([ "x": x - 1, "y": y ]);
    }
    
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string generateExitCode(mapping exits, string path)
{
    string ret = "";
    
    foreach (string direction in m_indices(exits))
    {
        mapping target = exits[direction];
        ret += sprintf("    addExit(\"%s\", \"%sroom_%d_%d.c\");\n",
            direction, path, target["x"], target["y"]);
    }
    
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string generateRoomFile(string path, int x, int y, 
    int roomType, string regionType, string iconKey, mapping exits)
{
    string ret = "";
    string filename = sprintf("room_%d_%d.c", x, y);
    
    // Determine environment type based on room type and decorator
    string envType = "interior";
    string envPath = "ruin-room.c";
    
    if (roomType == 5 || roomType == 7)  // Courtyard or garden
    {
        envType = "terrain";
        envPath = "ruin-exterior.c";
    }
    else if (roomType == 6)  // Throne room
    {
        envPath = "ruin-great-hall.c";
    }
    else if (sizeof(regexp(({ iconKey }), "hallway")) ||
             sizeof(regexp(({ iconKey }), "T-intersection")) ||
             sizeof(regexp(({ iconKey }), "corner")))
    {
        envPath = "ruin-hallway.c";
    }
    else if (sizeof(regexp(({ iconKey }), "alcove")))
    {
        envPath = "ruin.c";
    }
    
    ret += "//***********************************************************"
        "******************\n";
    ret += "// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights "
        "reserved. See\n";
    ret += "//                      the accompanying LICENSE file for "
        "details.\n";
    ret += "//***********************************************************"
        "******************\n";
    ret += "inherit \"/lib/environment/environment.c\";\n\n";
    ret += "///////////////////////////////////////////////////////////"
        "//////////\n";
    ret += "public void Setup()\n";
    ret += "{\n";
    ret += "    cloneEnvironment();\n";
    
    if (envType == "terrain")
    {
        ret += sprintf("    setTerrain(\"/lib/environment/terrain/%s\");\n", 
            envPath);
    }
    else
    {
        ret += sprintf("    setInterior(\"/lib/environment/interiors/%s\");\n", 
            envPath);
        
        // Add floor for non-terrain rooms
        if (roomType != 5 && roomType != 7)
        {
            ret += "    addFeature(\"/lib/environment/features/floors/ruined-marble-floor.c\");\n";
        }
    }
    
    ret += sprintf("    addDecorator(\"%s\");\n\n", iconKey);
    
    ret += generateExitCode(exits, path);
    ret += generateRoomFeatures(roomType, regionType);
    
    ret += "}\n";
    
    write_file(path + filename, ret);
    
    return filename;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string generateRegionFile(string path, mapping template)
{
    string ret = "";
    
    ret += "//***********************************************************"
        "******************\n";
    ret += "// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights "
        "reserved. See\n";
    ret += "//                      the accompanying LICENSE file for "
        "details.\n";
    ret += "//***********************************************************"
        "******************\n";
    ret += "inherit \"/lib/environment/region.c\";\n\n";
    ret += "///////////////////////////////////////////////////////////"
        "//////////\n";
    ret += "public void Setup()\n";
    ret += "{\n";
    ret += sprintf("    setRegionName(\"%s\");\n", RegionName);
    ret += sprintf("    setRegionType(\"%s\");\n", RegionType);
    ret += sprintf("    setDimensions(%d, %d);\n", 
        template["dimensions"]["x"], template["dimensions"]["y"]);
    ret += sprintf("    setRegionLevel(%d);\n", RegionLevel || 1);
    ret += "    asManualRegion();\n\n";
    
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask void processRoomInLayout(string path, int x, int y, 
    mixed *layout, mapping template)
{
    int *row = layout[y];
    int roomType = row[x];
    
    if ((roomType > 0) && (roomType != 1))
    {
        string iconKey = generateRoomIconKey(x, y, layout, RegionType);
        mapping exits = generateRoomExits(x, y, layout);
        string filename = generateRoomFile(path, x, y, roomType, RegionType, 
            iconKey, exits);
        
        string roomTypeStr = (roomType == 4) ? "entry" : "room";
        
        string coordinateCode = sprintf("    setCoordinate(%d, %d, \"%s%s\", "
            "\"%s\");\n", x, y, path, filename, roomTypeStr);
        
        write_file(path + "region.c", coordinateCode);
        
        grid[x][y] = ([
            "x": x,
            "y": y,
            "room type": roomTypeStr,
            "is placed": 1,
            "exits": exits,
            "environment": 0,
            "icon": iconKey
        ]);
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void generateBuildingRegion(string path)
{
    mapping template = generateBuildingTemplate("south");
    mixed *layout = template["layout"];
    int maxY = sizeof(layout);
    int maxX = sizeof(layout[0]);
    
    string regionPath = path + RegionName + "/";
    string regionContent = generateRegionFile(regionPath, template);
    
    write_file(regionPath + "region.c", regionContent);
    
    for (int y = 0; y < maxY; y++)
    {
        for (int x = 0; x < maxX; x++)
        {
            processRoomInLayout(regionPath, x, y, layout, template);
        }
    }
    
    write_file(regionPath + "region.c", "}\n");
}
