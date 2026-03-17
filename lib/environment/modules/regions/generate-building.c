//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/environment/modules/regions/core.c";
virtual inherit "/lib/environment/modules/regions/building-files.c";
virtual inherit "/lib/environment/modules/regions/generate-tunneling.c";

#include "/lib/services/regions/region-types.h"
#include "/lib/environment/modules/regions/building-parameters.h"

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
private nomask int shouldUseTunnelingAlgorithm(string regionType)
{
    int ret = 0;
    
    ret = (member(({ "crypt", "cave", "mine", "catacomb", "dungeon" }), 
        regionType) > -1);
    
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string getInteriorPath(string regionType)
{
    string ret = "/lib/environment/interiors/ruin.c";
    
    if (member(RegionTypes, regionType) && 
        member(RegionTypes[regionType], "interior"))
    {
        ret = RegionTypes[regionType]["interior"];
    }
    
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask void placeDoorInVerticalWall(mixed *layout, 
    mapping **doorData, int wallX, int py, int ph, int width, int height)
{
    int *valid = ({});

    for (int y = py; y < py + ph; y++)
    {
        if (wallX > 0 && wallX < width - 1 &&
            layout[y][wallX - 1] >= 2 && layout[y][wallX + 1] >= 2)
        {
            valid += ({ y });
        }
    }

    if (!sizeof(valid))
    {
        return;
    }

    int doorCount = (sizeof(valid) > 5) ? 2 : 1;

    for (int d = 0; d < doorCount; d++)
    {
        int idx = (d * sizeof(valid) / doorCount) + 
            random(sizeof(valid) / doorCount || 1);
        if (idx >= sizeof(valid))
        {
            idx = sizeof(valid) - 1;
        }
        int doorY = valid[idx];

        layout[doorY][wallX] = 2;
        doorData[doorY][wallX] = ([ "east": 1, "west": 1 ]);
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void placeDoorInHorizontalWall(mixed *layout, 
    mapping **doorData, int wallY, int px, int pw, int width, int height)
{
    int *valid = ({});

    for (int x = px; x < px + pw; x++)
    {
        if (wallY > 0 && wallY < height - 1 &&
            layout[wallY - 1][x] >= 2 && layout[wallY + 1][x] >= 2)
        {
            valid += ({ x });
        }
    }

    if (!sizeof(valid))
    {
        return;
    }

    int doorCount = (sizeof(valid) > 5) ? 2 : 1;

    for (int d = 0; d < doorCount; d++)
    {
        int idx = (d * sizeof(valid) / doorCount) + 
            random(sizeof(valid) / doorCount || 1);
        if (idx >= sizeof(valid))
        {
            idx = sizeof(valid) - 1;
        }
        int doorX = valid[idx];

        layout[wallY][doorX] = 2;
        doorData[wallY][doorX] = ([ "north": 1, "south": 1 ]);
    }
}

/////////////////////////////////////////////////////////////////////////////
// Returns ({ rooms_array, next_room_id })
private nomask mixed *bspPartition(mixed *layout, int **roomIds,
    mapping **doorData, int px, int py, int pw, int ph,
    int depth, int minSize, int nextId, int width, int height)
{
    int canSplitV = (pw >= minSize * 2 + 1);
    int canSplitH = (ph >= minSize * 2 + 1);

    if (depth <= 0 || (!canSplitV && !canSplitH))
    {
        int roomId = nextId;
        nextId++;

        for (int y = py; y < py + ph; y++)
        {
            for (int x = px; x < px + pw; x++)
            {
                if (layout[y][x] >= 2)
                {
                    roomIds[y][x] = roomId;
                }
            }
        }

        return ({ ({ ([
            "x": px,
            "y": py,
            "width": pw,
            "height": ph,
            "id": roomId
        ]) }), nextId });
    }

    int splitV;
    if (!canSplitH)
    {
        splitV = 1;
    }
    else if (!canSplitV)
    {
        splitV = 0;
    }
    else if (pw > ph + 2)
    {
        splitV = 1;
    }
    else if (ph > pw + 2)
    {
        splitV = 0;
    }
    else
    {
        splitV = random(2);
    }

    mixed *leftResult;
    mixed *rightResult;

    if (splitV)
    {
        int rangeV = pw - minSize * 2;
        int split = minSize + rangeV / 4 + random(rangeV / 2 + 1);
        int wallX = px + split;

        // Recurse children FIRST so their walls are placed
        leftResult = bspPartition(layout, roomIds, doorData,
            px, py, split, ph, depth - 1, minSize, nextId, 
            width, height);
        nextId = leftResult[1];

        rightResult = bspPartition(layout, roomIds, doorData,
            wallX + 1, py, pw - split - 1, ph, depth - 1, minSize,
            nextId, width, height);
        nextId = rightResult[1];

        // THEN place parent wall
        for (int y = py; y < py + ph; y++)
        {
            layout[y][wallX] = 1;
        }

        // THEN place doors, validating adjacent cells are rooms
        placeDoorInVerticalWall(layout, doorData, wallX, py, ph,
            width, height);
    }
    else
    {
        int rangeH = ph - minSize * 2;
        int split = minSize + rangeH / 4 + random(rangeH / 2 + 1);
        int wallY = py + split;

        leftResult = bspPartition(layout, roomIds, doorData,
            px, py, pw, split, depth - 1, minSize, nextId,
            width, height);
        nextId = leftResult[1];

        rightResult = bspPartition(layout, roomIds, doorData,
            px, wallY + 1, pw, ph - split - 1, depth - 1, minSize,
            nextId, width, height);
        nextId = rightResult[1];

        for (int x = px; x < px + pw; x++)
        {
            layout[wallY][x] = 1;
        }

        placeDoorInHorizontalWall(layout, doorData, wallY, px, pw,
            width, height);
    }

    return ({ leftResult[0] + rightResult[0], nextId });
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void placeSpecialRoom(mixed *layout, mapping params, 
    mapping *rooms)
{
    if (member(params, "special room"))
    {
        int width = sizeof(layout[0]);
        int height = sizeof(layout);
        mapping hall = rooms[0];
        int centerX = hall["x"] + hall["width"] / 2;
        int centerY = hall["y"] + hall["height"] / 2;

        if (centerX >= 0 && centerX < width && centerY >= 0 && 
            centerY < height)
        {
            layout[centerY][centerX] = params["special room"];
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask mixed *generateBuildingLayout(string enterFrom)
{
    mapping params = buildingParameters[RegionType];

    int width = params["min width"] + random(params["max width"] - 
        params["min width"] + 1);
    int height = params["min height"] + random(params["max height"] - 
        params["min height"] + 1);
    int complexity = member(params, "complexity") ? 
        params["complexity"] : 3;

    mixed *layout = createEmptyLayout(width, height);

    mixed *tracking = initializeRoomTracking(height, width);
    int **roomIds = tracking[0];
    mapping **doorData = tracking[1];

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            if (x == 0 || x == width - 1 || y == 0 || y == height - 1)
            {
                layout[y][x] = 1;
            }
            else
            {
                layout[y][x] = 2;
            }
        }
    }

    mixed *bspResult = bspPartition(layout, roomIds, doorData,
        1, 1, width - 2, height - 2, complexity, 3, 1, 
        width, height);
    mapping *rooms = bspResult[0];

    placeEntry(layout, enterFrom);

    if (sizeof(rooms) > 0)
    {
        placeSpecialRoom(layout, params, rooms);
    }

    if (member(params, "outdoor room") && 
        member(params, "has courtyard") && params["has courtyard"] &&
        sizeof(rooms) > 1)
    {
        mapping wing = rooms[1 + random(sizeof(rooms) - 1)];
        int cx = wing["x"] + wing["width"] / 2;
        int cy = wing["y"] + wing["height"] / 2;

        if (cx >= 0 && cx < width && cy >= 0 && cy < height &&
            layout[cy][cx] == 2)
        {
            layout[cy][cx] = params["outdoor room"];
        }
    }

    return ({ layout, roomIds, doorData });
}

/////////////////////////////////////////////////////////////////////////////
public nomask string generateRoomIconKey(int x, int y, mixed *layout, 
    int **roomIds, mapping **doorData, string regionType)
{
    string ret = 0;
    mapping template = getBuildingTemplate(regionType);
    
    if (template)
    {
        string baseType = member(template, "base type") ? 
            template["base type"] : (regionType + " interior");
        
        int roomType = layout[y][x];
        
        if ((roomType > 0) && (roomType != 1))
        {
            string roomLayout = determineRoomLayoutType(x, y, layout, 
                roomIds, doorData);
            ret = baseType + " " + roomLayout;
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping generateBuildingTemplate(string enterFrom)
{
    // Check if we should use tunneling algorithm
    if (shouldUseTunnelingAlgorithm(RegionType))
    {
        return generateTunnelingDungeon(enterFrom, RegionType);
    }
    
    // Otherwise use BSP algorithm (existing code)
    mapping params = buildingParameters[RegionType];
    mixed *layoutData = generateBuildingLayout(enterFrom);
    
    mixed *layout = layoutData[0];
    int **roomIds = layoutData[1];
    mapping **doorData = layoutData[2];
    
    int width = sizeof(layout[0]);
    int height = sizeof(layout);
    
    return ([
        "dimensions": ([ "x": width, "y": height ]),
        "base type": params["base type"],
        "room types": params["room types"],
        "layout": layout,
        "roomIds": roomIds,
        "doorData": doorData
    ]);
}

/////////////////////////////////////////////////////////////////////////////
private nomask void processRoomInLayout(string path, int x, int y, 
    mixed *layout, int **roomIds, mapping **doorData, string interiorPath)
{
    int roomType = layout[y][x];
    
    if ((roomType > 0) && (roomType != 1))
    {
        string iconKey = generateRoomIconKey(x, y, layout, roomIds, doorData,
            RegionType);
        mapping exits = generateRoomExits(x, y, layout);
        string filename = generateRoomFile(path, x, y, interiorPath, iconKey, 
            exits, doorData);
        
        string roomTypeStr = "none";

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
private nomask string generateRegionSetup(mapping template)
{
    string ret = "";
    
    ret += sprintf("    setRegionName(\"%s\");\n", RegionName);
    ret += sprintf("    setRegionType(\"%s\");\n", RegionType);
    ret += sprintf("    setDimensions(%d, %d);\n", 
        template["dimensions"]["x"], template["dimensions"]["y"]);
    ret += sprintf("    setRegionLevel(%d);\n", RegionLevel || 1);
    ret += "    asManualRegion();\n\n";
    
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void generateBuildingRegion(string path)
{
    mapping template = generateBuildingTemplate("south");
    mixed *layout = template["layout"];
    int **roomIds = template["roomIds"];
    mapping **doorData = template["doorData"];
    int maxY = sizeof(layout);
    int maxX = sizeof(layout[0]);
    
    string regionPath = path + RegionName + "/";
    string interiorPath = getInteriorPath(RegionType);
    
    string regionContent = generateRegionFileHeader();
    regionContent += generateRegionSetup(template);
    
    write_file(regionPath + "region.c", regionContent);
    
    for (int y = 0; y < maxY; y++)
    {
        for (int x = 0; x < maxX; x++)
        {
            processRoomInLayout(regionPath, x, y, layout, roomIds, doorData,
                interiorPath);
        }
    }
    
    write_file(regionPath + "region.c", "}\n");
}
