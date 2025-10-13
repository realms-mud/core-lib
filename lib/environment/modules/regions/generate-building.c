//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/environment/modules/regions/core.c";

private mapping buildingTemplates = ([
    "temple": ([
        "dimensions": ([ "x": 7, "y": 9 ]),
        "layout": ({
            ({ 1, 1, 1, 1, 1, 1, 1 }),
            ({ 1, 2, 2, 2, 2, 2, 1 }),
            ({ 1, 2, 2, 2, 2, 2, 1 }),
            ({ 1, 2, 2, 3, 2, 2, 1 }),
            ({ 1, 2, 2, 2, 2, 2, 1 }),
            ({ 1, 2, 2, 2, 2, 2, 1 }),
            ({ 1, 2, 2, 2, 2, 2, 1 }),
            ({ 1, 1, 1, 4, 1, 1, 1 }),
            ({ 0, 0, 0, 5, 0, 0, 0 })
        })
    ]),
    "keep": ([
        "dimensions": ([ "x": 9, "y": 11 ]),
        "layout": ({
            ({ 1, 1, 1, 1, 1, 1, 1, 1, 1 }),
            ({ 1, 2, 2, 2, 2, 2, 2, 2, 1 }),
            ({ 1, 2, 3, 3, 3, 3, 3, 2, 1 }),
            ({ 1, 2, 3, 2, 2, 2, 3, 2, 1 }),
            ({ 1, 2, 3, 2, 6, 2, 3, 2, 1 }),
            ({ 1, 2, 3, 2, 2, 2, 3, 2, 1 }),
            ({ 1, 2, 3, 3, 3, 3, 3, 2, 1 }),
            ({ 1, 2, 2, 2, 2, 2, 2, 2, 1 }),
            ({ 1, 1, 1, 1, 4, 1, 1, 1, 1 }),
            ({ 0, 0, 0, 0, 5, 0, 0, 0, 0 }),
            ({ 0, 0, 0, 0, 7, 0, 0, 0, 0 })
        })
    ]),
    "crypt": ([
        "dimensions": ([ "x": 5, "y": 7 ]),
        "layout": ({
            ({ 1, 1, 1, 1, 1 }),
            ({ 1, 2, 2, 2, 1 }),
            ({ 1, 2, 3, 2, 1 }),
            ({ 1, 2, 2, 2, 1 }),
            ({ 1, 2, 2, 2, 1 }),
            ({ 1, 1, 4, 1, 1 }),
            ({ 0, 0, 5, 0, 0 })
        })
    ]),
    "ruins": ([
        "dimensions": ([ "x": 6, "y": 8 ]),
        "layout": ({
            ({ 1, 1, 0, 1, 1, 1 }),
            ({ 1, 2, 2, 2, 0, 1 }),
            ({ 0, 2, 3, 2, 2, 1 }),
            ({ 1, 2, 2, 2, 2, 1 }),
            ({ 1, 0, 2, 2, 2, 1 }),
            ({ 1, 1, 1, 4, 1, 1 }),
            ({ 0, 0, 0, 5, 0, 0 }),
            ({ 0, 0, 0, 6, 0, 0 })
        })
    ])
]);

/////////////////////////////////////////////////////////////////////////////
public nomask int isBuildingRegionType()
{
    int ret = 0;
    
    if (member(buildingTemplates, RegionType))
    {
        ret = 1;
    }
    
    return ret;
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
    
    if ((north && south) && (!east && !west))
    {
        ret = "north-south hallway";
        string entryDir = detectSideEntries(x, y, layout, "north-south");
        if (entryDir)
        {
            ret += " " + entryDir + " entry";
        }
    }
    else if ((east && west) && (!north && !south))
    {
        ret = "east-west hallway";
        string entryDir = detectSideEntries(x, y, layout, "east-west");
        if (entryDir)
        {
            ret += " " + entryDir + " entry";
        }
    }
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
        ret = determineTwoExitLayoutWithEntries(x, y, layout, north, south, 
            east, west);
    }
    
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string generateRoomIconKey(int x, int y, mixed *layout, 
    string regionType)
{
    string ret = 0;
    string baseType = "ruined interior";
    
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
    
    ret += "//***********************************************************"
        "******************\n";
    ret += "// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights "
        "reserved. See\n";
    ret += "//                      the accompanying LICENSE file for "
        "details.\n";
    ret += "//***********************************************************"
        "******************\n";
    ret += "inherit \"/lib/environment/generatedRoomTemplate.c\";\n\n";
    ret += "///////////////////////////////////////////////////////////"
        "//////////\n";
    ret += "public void Setup()\n";
    ret += "{\n";
    ret += sprintf("    setInterior(\"%s\");\n", regionType + " interior");
    ret += sprintf("    setDecoratorType(\"%s\");\n", iconKey);
    ret += sprintf("    setCoordinates(load_object(\"%sregion.c\"), %d, "
        "%d);\n", path, x, y);
    
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
    mapping template = buildingTemplates[RegionType];
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

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getBuildingTemplate(string regionType)
{
    mapping ret = 0;
    
    if (member(buildingTemplates, regionType))
    {
        ret = buildingTemplates[regionType];
    }
    
    return ret;
}
