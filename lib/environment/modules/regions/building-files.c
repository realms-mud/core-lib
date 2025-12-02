//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/environment/modules/regions/building-decorators.c";

/////////////////////////////////////////////////////////////////////////////
protected nomask mapping generateRoomExits(int x, int y, mixed *layout)
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
private nomask string getOppositeDirection(string direction)
{
    string ret = "";
    
    if (direction == "north")
    {
        ret = "south";
    }
    else if (direction == "south")
    {
        ret = "north";
    }
    else if (direction == "east")
    {
        ret = "west";
    }
    else if (direction == "west")
    {
        ret = "east";
    }
    
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int checkDoorInDirection(int x, int y, int tx, int ty, 
    mapping **doorData, string direction)
{
    int hasDoor = hasDoorInDirection(x, y, doorData, direction);
    
    if (!hasDoor)
    {
        string opposite = getOppositeDirection(direction);
        hasDoor = hasDoorInDirection(tx, ty, doorData, opposite);
    }
    
    return hasDoor;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string generateSingleExit(string direction, int tx, int ty, 
    string path, int hasDoor)
{
    string ret = "";
    
    if (hasDoor)
    {
        ret = sprintf("    addExitWithDoor(\"%s\", \"%sroom_%d_%d.c\");\n",
            direction, path, tx, ty);
    }
    else
    {
        ret = sprintf("    addExit(\"%s\", \"%sroom_%d_%d.c\");\n",
            direction, path, tx, ty);
    }
    
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string generateExitCode(mapping exits, mapping **doorData,
    int x, int y, string path)
{
    string ret = "";
    
    foreach (string direction in m_indices(exits))
    {
        mapping target = exits[direction];
        int tx = target["x"];
        int ty = target["y"];
        
        int hasDoor = checkDoorInDirection(x, y, tx, ty, doorData, direction);
        ret += generateSingleExit(direction, tx, ty, path, hasDoor);
    }
    
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string generateFileHeader()
{
    string ret = "";
    
    ret += "//*****************************************************************************\n";
    ret += "// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See\n";
    ret += "//                      the accompanying LICENSE file for details.\n";
    ret += "//*****************************************************************************\n";
    ret += "inherit \"/lib/environment/environment.c\";\n\n";
    ret += "/////////////////////////////////////////////////////////////////////////////\n";
    ret += "public void Setup()\n";
    ret += "{\n";
    
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string generateRoomFile(string path, int x, int y, 
    string interiorPath, string iconKey, mapping exits, mapping **doorData)
{
    string filename = sprintf("room_%d_%d.c", x, y);
    
    string content = generateFileHeader();
    content += sprintf("    setInterior(\"%s\");\n", interiorPath);
    content += sprintf("    addDecorator(\"%s\");\n\n", iconKey);
    content += generateExitCode(exits, doorData, x, y, path);
    content += "}\n";
    
    write_file(path + filename, content);
    
    return filename;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string generateRegionFileHeader()
{
    string ret = "";
    
    ret += "//*****************************************************************************\n";
    ret += "// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See\n";
    ret += "//                      the accompanying LICENSE file for details.\n";
    ret += "//*****************************************************************************\n";
    ret += "inherit \"/lib/environment/region.c\";\n\n";
    ret += "/////////////////////////////////////////////////////////////////////////////\n";
    ret += "public void Setup()\n";
    ret += "{\n";
    
    return ret;
}
