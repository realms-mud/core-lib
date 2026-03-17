//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/environment/modules/regions/core.c";

private int PersistInterval = 300;
private int PersistActive = 0;
private string PersistPath = 0;
private int PersistDirty = 0;

/////////////////////////////////////////////////////////////////////////////
public nomask void setPersistPath(string path)
{
    if (stringp(path) && sizeof(path))
    {
        PersistPath = path;
        if (PersistPath[<1..] != "/")
        {
            PersistPath += "/";
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask string persistPath()
{
    return PersistPath;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setPersistInterval(int seconds)
{
    if (seconds >= 30 && seconds <= 3600)
    {
        PersistInterval = seconds;
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void markDirty()
{
    PersistDirty = 1;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void startPersistence()
{
    if (!PersistActive && PersistPath)
    {
        PersistActive = 1;
        call_out("persistTick", PersistInterval);
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void stopPersistence()
{
    if (PersistActive)
    {
        remove_call_out("persistTick");
        PersistActive = 0;
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask string generateFileHeader()
{
    return
        "//****************************************************"
        "***************************\n"
        "// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD"
        ", All rights reserved. See\n"
        "//                      the accompanying LICENSE file "
        "for details.\n"
        "//****************************************************"
        "***************************\n";
}

/////////////////////////////////////////////////////////////////////////////
private nomask string generateRoomFileContent(mapping room, 
    string interiorPath, string decoratorType)
{
    string content = generateFileHeader();
    content += "inherit \"/lib/environment/environment.c\";\n\n";
    content += "//////////////////////////////////////////////"
        "///////////////\n";
    content += "public void Setup()\n{\n";
    content += "    cloneEnvironment();\n";

    if (stringp(interiorPath))
    {
        content += sprintf("    setInterior(\"%s\");\n", interiorPath);
    }

    if (stringp(decoratorType))
    {
        content += sprintf("    addDecorator(\"%s\");\n", decoratorType);
    }

    if (mappingp(room["exits"]))
    {
        foreach(string direction in m_indices(room["exits"]))
        {
            string dest = room["exits"][direction];
            content += sprintf("    addExit(\"%s\",\n"
                "        \"%s%s.c\");\n", 
                direction, PersistPath, dest);
        }
    }

    content += "}\n";
    return content;
}

/////////////////////////////////////////////////////////////////////////////
private nomask void writeRegionFile()
{
    string regionFile = PersistPath + "region.c";
    string content = generateFileHeader();
    content += "inherit \"/lib/environment/region.c\";\n\n";
    content += "//////////////////////////////////////////////"
        "///////////////\n";
    content += "public void Setup()\n{\n";
    content += sprintf("    setRegionName(\"%s\");\n", RegionName);
    content += sprintf("    setRegionType(\"%s\");\n", RegionType);
    content += sprintf("    setDimensions(%d, %d);\n", MaxX, MaxY);

    if (RegionLevel > 0)
    {
        content += sprintf("    setRegionLevel(%d);\n", RegionLevel);
    }

    content += "    asManualRegion();\n\n";

    for (int x = 0; x < MaxX; x++)
    {
        for (int y = 0; y < MaxY; y++)
        {
            if (sizeof(grid) > x && sizeof(grid[x]) > y &&
                mappingp(grid[x][y]) && grid[x][y]["is placed"])
            {
                content += sprintf("    setCoordinate(%d, %d,\n"
                    "        \"%s%dx%d.c\", \"none\");\n",
                    x, y, PersistPath, x, y);
            }
        }
    }

    content += "}\n";
    write_file(regionFile, content, 1);
}

/////////////////////////////////////////////////////////////////////////////
private nomask void writeRoomFiles()
{
    string interiorPath = 0;

    if (RegionService && stringp(RegionType))
    {
        mapping roomData = RegionService->generateRoomData(
            this_object(), ([
                "x": 0, "y": 0, "exits": ([]),
                "room type": "room"
            ]));
        if (mappingp(roomData) && member(roomData, "terrain"))
        {
            interiorPath = roomData["terrain"];
        }
        else if (mappingp(roomData) && member(roomData, "interior"))
        {
            interiorPath = roomData["interior"];
        }
    }

    for (int x = 0; x < MaxX; x++)
    {
        for (int y = 0; y < MaxY; y++)
        {
            if (sizeof(grid) > x && sizeof(grid[x]) > y &&
                mappingp(grid[x][y]) && grid[x][y]["is placed"])
            {
                string decoratorType = member(grid[x][y], "decorator type") ?
                    grid[x][y]["decorator type"] : 0;

                string roomContent = generateRoomFileContent(
                    grid[x][y], interiorPath, decoratorType);

                string roomFile = sprintf("%s%dx%d.c", PersistPath, x, y);
                write_file(roomFile, roomContent, 1);
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void persistToFiles()
{
    if (!PersistPath || !sizeof(grid) || !PersistDirty)
    {
        return;
    }

    writeRoomFiles();
    writeRegionFile();
    PersistDirty = 0;
}

/////////////////////////////////////////////////////////////////////////////
public void persistTick()
{
    persistToFiles();
    call_out("persistTick", PersistInterval);
}
