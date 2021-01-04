//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/environment/modules/regions/core.c";
virtual inherit "/lib/environment/modules/regions/generate-room.c"; 

protected int PersistRegion = 1;

/////////////////////////////////////////////////////////////////////////////
public nomask int persistRegion()
{
    return PersistRegion;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setPersistRegion(int persist)
{
    PersistRegion = persist;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int setRegionDetails(mapping regionData)
{
    EnterFrom = regionData["entry direction"];
    EntryPoint = regionData["entry point"];
    MaxX = regionData["x-dimension"];
    MaxY = regionData["y-dimension"];
    RegionName = regionData["name"];
    RegionType = regionData["type"];

    return stringp(EnterFrom) && stringp(EntryPoint) && stringp(RegionType);
}

/////////////////////////////////////////////////////////////////////////////
private nomask int setRegionGrid(mapping regionData)
{
    int ret = 0;

    grid = regionData["grid"] + ([]);

    if (sizeof(grid))
    {
        int count = 0;
        foreach(int x in m_indices(grid))
        {
            foreach(string y in m_indices(grid[x]))
            {
                if (grid[x][y]["room type"] != "none")
                {
                    rooms += ({ grid[x][y] });
                }
                count++;
                if (grid[x][y]["room type"] == "entry")
                {
                    entry = ({ x, y });
                }
            }
        }

        ret = 1;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int buildExistingRegion(mapping regionData)
{
    return setRegionDetails(regionData) && setRegionGrid(regionData);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int load(string enterFrom, string location)
{
    int ret = 0;

    if (PersistRegion && stringp(enterFrom) && stringp(location))
    {
        mapping data = Dictionary->loadRegion(enterFrom, location);

        if (mappingp(data) && sizeof(data))
        {
            ret = buildExistingRegion(data);

            if (sizeof(rooms))
            {
                foreach(mapping room in rooms)
                {
                    generateRoomDetails(room);
                }
            }

            grid[entry[0]][entry[1]]["exit to"] = enterFrom;
            grid[entry[0]][entry[1]]["environment"]->addEntryExit(
                enterFrom, location);
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void save()
{
    if (PersistRegion)
    {
        Dictionary->saveRegion(this_object());
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask string generateStaticTerrain(mapping room, string fileTemplate)
{
    string type = 0;
    if (member(room, "terrain"))
    {
        type = "terrain";
    }
    else if (member(room, "interior"))
    {
        type = "interior";
    }

    string functionName = sprintf("set%s", capitalize(type));

    string terrainText = sprintf("set%s(\"%s\");", capitalize(type),
        room[type]);

    return regreplace(fileTemplate, "// SetTerrain", terrainText);
}

/////////////////////////////////////////////////////////////////////////////
private nomask string generateElementsOfType(string type, mapping elements)
{
    string ret = "";
    string key = sprintf("%ss", type);
    if (member(elements, key) && sizeof(elements[key]))
    {
        foreach(string element in m_indices(elements[key]))
        {
            if (sizeof(elements[key][element]))
            {
                foreach(string direction in elements[key][element])
                {
                    ret += sprintf("    add%s(\"%s\", \"%s\");\n", 
                        capitalize(type), element, direction);
                }
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string generateStaticBuildings(mapping buildings)
{
    string buildingText = "";

    return buildingText;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string generateStaticElements(mapping room, string fileTemplate)
{
    string elementText = generateElementsOfType("feature", room) +
        generateElementsOfType("item", room);

    if (member(room, "buildings"))
    {
        elementText += generateStaticBuildings(room["buildings"]);
    }

    return regreplace(fileTemplate, "    // AddItems", elementText);
}

/////////////////////////////////////////////////////////////////////////////
private nomask string generateStaticExits(mapping room, string fileTemplate,
    string roomPath)
{
    string exitText = "";
    
    if (member(room, "exits") && sizeof(room["exits"]))
    {
        string pathType = "";
        foreach(string direction in m_indices(room["exits"]))
        {
            exitText += sprintf("    addExit(\"%s\", \"%s%s.c\");\n",
                direction, roomPath, room["exits"][direction]["exit to"]);

            if (member(room["exits"][direction], "path type"))
            {
                pathType = room["exits"][direction]["path type"];
                exitText += sprintf("    addFeature(\"%s\", \"%s\");\n",
                    room["exits"][direction]["path type"], direction);
            }
        }

        if (sizeof(entry) && (room["room type"] == "entry") && EnterFrom &&
            EntryPoint)
        {
            exitText += sprintf("    addExit(\"%s\", \"%s\");\n",
                EnterFrom, EntryPoint);

            if (pathType)
            {
                exitText += sprintf("    addFeature(\"%s\", \"%s\");\n",
                    pathType, EnterFrom);
            }
        }
    }
    return regreplace(fileTemplate, "    // AddExits", exitText);
}

/////////////////////////////////////////////////////////////////////////////
private nomask string generateStaticObjects(mapping room, string fileTemplate)
{
    string objectText = "";

    if (member(room, "room objects") && sizeof(room["room objects"]))
    {
        mapping roomItems = filter(room["room objects"],
            (: $2["type"] == "object" :));
        if (sizeof(roomItems))
        {
            foreach(string item in m_indices(roomItems))
            {
                objectText += sprintf("    addObject(\"%s\");\n",
                    roomItems[item]);
            }
        }

        mapping creatures = filter(room["room objects"],
            (: $2["type"] == "creature" :));
        if (sizeof(creatures))
        {
            objectText += sprintf("    addRandomCreature(({\"%s\"}));\n",
                implode(m_indices(creatures), "\",\""));
        }
    }
    return regreplace(fileTemplate, "    // AddObjects", objectText);
}

/////////////////////////////////////////////////////////////////////////////
private nomask string *generateStaticRoomFiles(string roomPath)
{
    string *ret = ({});

    string fileTemplate = 
        read_file("/lib/environment/generatedRoomTemplate.c");

    foreach(mapping room in rooms)
    {
        mapping roomData = Dictionary->generateRoomData(this_object(), room);

        string file = generateStaticTerrain(roomData, fileTemplate);
        file = generateStaticElements(roomData, file);
        file = generateStaticExits(roomData, file, roomPath);
        file = generateStaticObjects(roomData, file);

        file = regreplace(file, "\r\n", "\n", 1);
        file = regreplace(file, "(\r*\n)+}", "\n}", 1);
        file += "\n";

        string roomFile = roomPath + room["name"] + ".c";
        write_file(roomFile, file);
        load_object(roomFile);

        ret += ({ roomFile });
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string generateSetEntryCoordinate(string fileTemplate,
    string roomPath)
{
    string ret = fileTemplate;

    if (sizeof(entry) && EnterFrom && EntryPoint)
    {
        ret = regreplace(ret, "// EntryCoordinate",
            sprintf("setEntryCoordinate(%d, %d,\n"
                "        \"%s\", \"%s\",\n"
                "        \"%s\");", entry[0], entry[1],
                sprintf("%s%s.c", roomPath, getEntryCoordinates()),
                EnterFrom, EntryPoint));
    }
    else
    {
        ret = regreplace(ret, "// EntryCoordiante", "");
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string generateSettlementChance(string fileTemplate)
{
    return regreplace(fileTemplate, "// SettlementChance",
        sprintf("setSettlementChance(%d);", 
            this_object()->settlementChance()));
}

/////////////////////////////////////////////////////////////////////////////
private nomask string generateSetRegionLevel(string fileTemplate)
{
    string ret = fileTemplate;

    if (RegionLevel)
    {
        ret = regreplace(ret, "// RegionLevel",
            sprintf("setRegionLevel(%d);", RegionLevel));
    }
    else
    {
        ret = regreplace(ret, "    // RegionLevel\r*\n", "");
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string generateSetRoomCount(string fileTemplate)
{
    string ret = fileTemplate;

    if (roomCount)
    {
        ret = regreplace(ret, "// RoomCount",
            sprintf("setRoomCount(%d);", roomCount));
    }
    else
    {
        ret = regreplace(ret, "    // RoomCount\r*\n", "");
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask void generateStaticRegionFile(string roomPath, 
    string *coordinateList)
{
    string file = 
        read_file("/lib/environment/generatedRegionTemplate.c");

    file = regreplace(file, "// RegionName",
        sprintf("setRegionName(\"%s\");", RegionName));
    file = regreplace(file, "// RegionType",
        sprintf("setRegionType(\"%s\");", RegionType));
    file = regreplace(file, "// Dimensions",
        sprintf("setDimensions(%d, %d);", MaxX, MaxY));

    file = generateSetEntryCoordinate(file, roomPath);
    file = generateSettlementChance(file);
    file = generateSetRegionLevel(file);
    file = generateSetRoomCount(file);

    string rooms = "";
    foreach(string roomFile in coordinateList)
    {
        int x = to_int(regreplace(roomFile, ".*/([0-9]+)x[0-9]+.c$", "\\1"));
        int y = to_int(regreplace(roomFile, ".*/[0-9]+x([0-9]+).c$", "\\1"));
        rooms += sprintf("    setCoordinate(%d, %d,\n"
            "        \"%s\", \"%s\");\n", x, y, roomFile, grid[x][y]["room type"]);
    }
    file = regreplace(file, "    // Rooms", rooms) + "\n";
    file = regreplace(file, "\r\n", "\n", 1);
    file = regreplace(file, "(\r*\n)+}", "\n}", 1);

    write_file(roomPath + "region.c", file);
    load_object(roomPath + "region.c");
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs void generateStaticFiles(string rootPath, 
    int useRootPath)
{
    if (file_size(rootPath) == -2)
    {
        string regionPath = useRootPath ? rootPath :
            sprintf("%s%s%s/", rootPath, 
                (rootPath[sizeof(rootPath) - 1] == '/') ? "" : "/",
                regionIdentifier());

        if (file_size(regionPath) == -1)
        {
            mkdir(regionPath);
        }

        string *rooms = sort_array(generateStaticRoomFiles(regionPath), (: $1 > $2 :));
        generateStaticRegionFile(regionPath, rooms);
    }
    else
    {
        raise_error(sprintf("ERROR in region.c: %s must be a valid directory.\n",
            rootPath));
    }
}
