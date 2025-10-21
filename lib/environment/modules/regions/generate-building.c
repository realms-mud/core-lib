//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/environment/modules/regions/core.c";
virtual inherit "/lib/environment/modules/regions/building-files.c";

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
protected nomask mapping *tryPlaceSideRoom(mixed *layout, int **roomIds, 
    mapping *rooms, int width, int height)
{
    int roomWidth = 1 + random(2);
    int roomHeight = 1 + random(2);
    
    if (roomWidth == 2 && roomHeight == 2 && random(3))
    {
        if (random(2))
        {
            roomWidth = 1;
        }
        else
        {
            roomHeight = 1;
        }
    }
    
    int roomX = 2 + random(width - roomWidth - 4);
    int roomY = 2 + random(height - roomHeight - 4);
    
    if (!checkRoomOverlap(layout, roomX, roomY, roomWidth, roomHeight))
    {
        int roomId = sizeof(rooms) + 1;
        fillRoomCells(layout, roomIds, roomX, roomY, roomWidth, roomHeight, 
            roomId);
        
        rooms += ({ ([
            "x": roomX,
            "y": roomY,
            "width": roomWidth,
            "height": roomHeight,
            "id": roomId
        ]) });
    }
    return rooms;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask mapping *placeSideRooms(mixed *layout, int **roomIds, 
    mapping *rooms, int width, int height, int sideRoomCount)
{
    for (int i = 0; i < sideRoomCount; i++)
    {
        int attempts = 0;
        int placed = sizeof(rooms);
        
        while (sizeof(rooms) == placed && attempts < 50)
        {
            rooms = tryPlaceSideRoom(layout, roomIds, rooms, width, height);
            attempts++;
        }
    }
    return rooms;
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
        
        if (centerX >= 0 && centerX < width && centerY >= 0 && centerY < height)
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
    
    mixed *layout = createEmptyLayout(width, height);
    
    mixed *tracking = initializeRoomTracking(height, width);
    int **roomIds = tracking[0];
    mapping **doorData = tracking[1];   
    mapping *rooms = ({});
    
    int hallWidth = 2 + random(2);
    int hallHeight = 2 + random(2);
    int hallX = (width - hallWidth) / 2;
    int hallY = (height - hallHeight) / 2;
    
    rooms = placeMainHall(layout, roomIds, rooms, hallX, hallY, hallWidth, 
        hallHeight);
    
    int sideRoomCount = 5 + random(4);
    rooms = placeSideRooms(layout, roomIds, rooms, width, height, sideRoomCount);
    
    addWalls(layout);
    connectRoomsWithDoors(layout, roomIds, doorData, rooms);
    placeEntry(layout, enterFrom);
    placeSpecialRoom(layout, params, rooms);
    
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
