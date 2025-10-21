//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/environment/modules/regions/core.c";
virtual inherit "/lib/environment/modules/regions/entries-and-exits.c";
virtual inherit "/lib/environment/modules/regions/generate-path.c";
virtual inherit "/lib/environment/modules/regions/generate-room.c";
virtual inherit "/lib/environment/modules/regions/generate-settlement.c";
virtual inherit "/lib/environment/modules/regions/generate-building.c";

/////////////////////////////////////////////////////////////////////////////
protected int getRoomCount()
{
    return roomCount ? roomCount : (MaxX + random(MaxX));
}

/////////////////////////////////////////////////////////////////////////////
public void setRoomCount(int count)
{
    int min = (MaxX > MaxY) ? MaxX : MaxY;
    int max = to_int(sqrt(MaxX * MaxY) * 3.0);

    if ((count >= min) && (count <= max))
    {
        roomCount = count;
    }
    else
    {
        raise_error(format(sprintf("Region: The room count (%d) must be in "
            "the range of %d to %d. This range is calculated based on the "
            "values of x (%d) and y (%d). Values outside of this range can "
            "adversely affect the performance of the pathing algorithm or "
            "lead to poorly-devised regions.\n",
            count, min, max, MaxX, MaxY), 78));
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void createEmptyGrid(int x, int y)
{
    for (int i = 0; i < x; i++)
    {
        grid[i] = ([]);
        for (int j = 0; j < y; j++)
        {
            grid[i][j] = ([
                "x": i,
                "y": j,
                "room type": "none",
                "is placed": 0,
                "exits": ([]),
                "environment": 0
            ]);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask int canGenerateRegion()
{
    int ret = 0;
    if (!RegionType)
    {
        raise_error("ERROR - region: The region type must be set before it is "
            "generated.\n");
    }
    else if (!RegionName)
    {
        raise_error("ERROR - region: The region name must be set before it is "
            "generated.\n");
    }
    else
    {
        ret = 1;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask void populateBuildingGrid(string enterFrom, string location,
    int *coordinates)
{
    EntryPoint = location;
    EnterFrom = enterFrom;
    
    // Generate a procedural building template
    mapping template = generateBuildingTemplate(enterFrom);
    if (template)
    {
        mixed *layout = template["layout"];
        int **roomIds = template["roomIds"];
        mapping **doorData = template["doorData"];
        int maxY = sizeof(layout);
        int maxX = sizeof(layout[0]);
        
        MaxX = template["dimensions"]["x"];
        MaxY = template["dimensions"]["y"];
        
        createEmptyGrid(MaxX, MaxY);
        
        string baseType = member(template, "base type") ? 
            template["base type"] : 
            (RegionType + " interior");
        
        mapping roomTypeDefs = template["room types"];
        
        for (int layoutY = 0; layoutY < maxY; layoutY++)
        {
            for (int layoutX = 0; layoutX < maxX; layoutX++)
            {
                int *row = layout[layoutY];
                int roomType = row[layoutX];
                
                if (roomType > 0 && member(roomTypeDefs, roomType))
                {
                    mapping typeInfo = roomTypeDefs[roomType];
                    string roomTypeStr = typeInfo["name"];
                    string iconStrategy = typeInfo["icon"];
                    string iconKey = "none";
                    
                    if (iconStrategy == "wall")
                    {
                        iconKey = "wall";
                    }
                    else if (iconStrategy == "base+name")
                    {
                        iconKey = baseType + " " + roomTypeStr;
                    }
                    else if (iconStrategy == "generated")
                    {
                        iconKey = generateRoomIconKey(layoutX, layoutY, layout, 
                            roomIds, doorData, RegionType);
                    }
                    
                    // Map layout Y to grid Y with proper inversion
                    // Layout Y=0 (top of array) -> Grid Y=MaxY-1 (top of display)
                    int gridY = layoutY;
                    
                    if (roomType == 4)
                    {
                        entry = ({ layoutX, gridY });
                    }
                    
                    grid[layoutX][gridY] = ([
                        "x": layoutX,
                        "y": gridY,
                        "room type": roomTypeStr,
                        "is placed": (roomType > 1) ? 1 : 0,
                        "exits": ([]),
                        "environment": 0,
                        "decorator type": iconKey
                    ]);
                }
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void generateStandardRegion(string enterFrom, string location,
    int *coordinates)
{
    EntryPoint = location;
    EnterFrom = enterFrom;

    if ((MaxX > 9) && (MaxY > 9) && 
        RegionService->canConstructSettlement(this_object()))
    {
        generateSettlement();
    }

    // Create entry point
    createRoom(1, enterFrom, coordinates);

    int numberOfRooms = getRoomCount();
    for (int i = 0; i < numberOfRooms; i++)
    {
        createRoom();
    }

    while (sizeof(filter(rooms, (: $1["is placed"] == 0 :))))
    {
        foreach(mapping room in rooms)
        {
            constructPath(room);
        }
    }
    mapping exit = createExit();
    if (sizeof(exit))
    {
        rooms += ({ exit });
        constructPath(exit);
    }

    foreach(mapping room in rooms)
    {
        generateRoomDetails(room);
    }

    if (location)
    {
        grid[entry[0]][entry[1]]["exit to"] = enterFrom;
        grid[entry[0]][entry[1]]["environment"]->addEntryExit(
            enterFrom, location);
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void generateRegion(string enterFrom, string location,
    int *coordinates)
{
    if (isBuildingRegionType())
    {
        populateBuildingGrid(enterFrom, location, coordinates);
    }
    else
    {
        generateStandardRegion(enterFrom, location, coordinates);
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs string createRegion(string enterFrom, string location,
    int *coordinates)
{
    string ret = 0;

    int loaded = call_direct(this_object(), "load", enterFrom, location);
    if (!loaded && canGenerateRegion())
    {
        if (!isBuildingRegionType())
        {
            createEmptyGrid(MaxX, MaxY);
        }
        generateRegion(enterFrom, location, coordinates);

        ret = getDirectionOfEntry(enterFrom);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void createRegionFromTemplate(mapping data, 
    object connectedRegion)
{
    MaxX = data["x dimension"];
    MaxY = data["y dimension"];
    RegionName = data["name"];
    RegionType = data["type"];
    EnterFrom = data["enter from"];
    EntryPoint = data["entry point"];
    RegionLevel = data["level"];

    createEmptyGrid(MaxX, MaxY);

    entry = data["entry coordinate"];
    decorators = data["decorators"];
    rooms = data["rooms"];

    foreach(mapping room in data["rooms"])
    {
        room["room type"] = "room";
        room["identifier"] = sprintf("%s-%dx%d", RegionName, room["x"], 
            room["y"]);

        if (member(data, "terrain"))
        {
            room["terrain"] = data["terrain"];
        }
        else
        {
            room["interior"] = data["interior"];
        }

        grid[room["x"]][room["y"]] = room;
    }

    if (!member(grid[entry[0]][entry[1]], "exits"))
    {
        grid[entry[0]][entry[1]]["exits"] = ([]);
    }
    grid[entry[0]][entry[1]]["exits"][EnterFrom] = ([
        "exit to": EntryPoint,
        "door": data["door"],
        "key": data["key"],
        "region": connectedRegion
    ]);
}
