//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/secure/dataServices/dataService.c";

private object regionDictionary =
    load_object("/lib/dictionaries/regionDictionary.c");

/////////////////////////////////////////////////////////////////////////////
private nomask mapping loadEnvironmentObjects(int dbHandle, int environmentId)
{
    mapping ret = ([]);

    string query = sprintf("select state, path, isRandom, probability, "
        "type, quantity "
        "from environmentalObjects "
        "where environmentId = %d;", environmentId);

    db_exec(dbHandle, query);

    mixed result;
    do
    {
        result = db_fetch(dbHandle);
        if (result)
        {
            ret[convertString(result[1])]= ([
                "state": convertString(result[0]),
                "is random": to_int(result[2]),
                "probability": to_int(result[3]),
                "type" : convertString(result[4]),
                "quantity": to_int(result[5])
            ]);
        }
    } while (result);

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping loadEnvironmentElements(int dbHandle, int environmentId)
{
    mapping ret = ([]);

    string query = sprintf("select type, value, state, location, "
        "`x-coordinate`, `y-coordinate`, `z-coordinate`, "
        "`x-rotation`, `y-rotation`, `z-rotation` "
        "from environmentalElements "
        "where environmentId = %d;", environmentId);

    db_exec(dbHandle, query);

    mixed result;
    do
    {
        result = db_fetch(dbHandle);
        if (result)
        {
            string location = convertString(result[3]);

            string key = sprintf("%s%s", convertString(result[1]),
                (location != "") ? "," + location : "");

            ret[key] = ([
                "type": convertString(result[0]),
                "state": convertString(result[2]),
                "x-coordinate": to_int(result[4]),
                "y-coordinate": to_int(result[5]),
                "z-coordinate" : to_int(result[6]),
                "x-rotation" : to_int(result[7]),
                "y-rotation" : to_int(result[8]),
                "z-rotation" : to_int(result[9])
            ]);
        }
    } while (result);

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping loadEnvironmentExits(int dbHandle, int environmentId)
{
    mapping ret = ([]);

    string query = sprintf("select direction, location "
        "from environmentExits "
        "where environmentId = %d;", environmentId);

    db_exec(dbHandle, query);

    mixed result;
    do
    {
        result = db_fetch(dbHandle);
        if (result)
        {
            ret[convertString(result[0])] = convertString(result[1]);
        }
    } while (result);

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping loadRegionExits(int dbHandle, mapping room,
    int regionId, int environmentId)
{
    mapping ret = room;

    string query = sprintf("select direction, location, state, "
        "`x-coordinate`, `y-coordinate` "
        "from regionExits "
        "where regionId = %d and environmentId = %d;", regionId, environmentId);

    db_exec(dbHandle, query);

    mixed result;
    do
    {
        result = db_fetch(dbHandle);
        if (result)
        {
            ret["exit to"] = convertString(result[0]);
            ret["name"] = convertString(result[1]);
            ret["state"] = convertString(result[2]);
            ret["exit coordinates"] = 
                ({ to_int(result[3]), to_int(result[4]) });
        }
    } while (result);

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping loadRegionMapDecorator(int dbHandle, int regionId, 
    int x, int y)
{
    mapping ret = 0;

    string query = sprintf("select class, size, type, color "
        "from regionMapDecorators "
        "where regionId = %d and `x-coordinate` = %d and "
        "`y-coordinate` = %d;", regionId, x, y);

    db_exec(dbHandle, query);

    mixed result = db_fetch(dbHandle);
    if (result)
    {   
        ret = regionDictionary->getMapDecorator(
            convertString(result[0]),
            convertString(result[1]),
            convertString(result[2]),
            convertString(result[3]));
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping loadRegionGrid(int dbHandle, int regionId, mapping grid)
{
    mapping ret = grid + ([]);

    string query = sprintf("select * from environmentView "
        "where regionId = %d;", regionId);

    db_exec(dbHandle, query);

    mapping environments = ([]);

    mixed result;
    do
    {
        result = db_fetch(dbHandle);
        if (result)
        {
            environments[to_int(result[0])] = ([
                "x-coordinate": to_int(result[2]),
                "y-coordinate": to_int(result[3]),
                "room type": convertString(result[4]),
                "identifier": convertString(result[5]),
                "name": convertString(result[6]),
                "is cloned": to_int(result[7]),
                "description": convertString(result[8]),
                "shop": convertString(result[9]),
                "region id": to_int(result[1])
            ]);
        }
    } while (result);

    foreach(int environmentId in m_indices(environments))
    {
        mapping environment = environments[environmentId];
        int x = environment["x-coordinate"];
        int y = environment["y-coordinate"];
        ret[x][y] = ([
            "x": x,
            "y": y,
            "room type": environment["room type"],
            "is placed": 1,
            "identifier": environment["identifier"],
            "name": environment["name"],
            "is cloned": environment["is cloned"],
            "description": environment["description"],
            "shop": environment["shop"]
        ]);

        ret[x][y]["exits"] = loadEnvironmentExits(dbHandle, environmentId);
        ret[x][y]["elements"] = 
            loadEnvironmentElements(dbHandle, environmentId);

        ret[x][y]["room objects"] =        
            loadEnvironmentObjects(dbHandle, environmentId);

        if (ret[x][y]["room type"] == "exit")
        {
            ret[x][y] = loadRegionExits(dbHandle, ret[x][y], 
                environment["region id"], environmentId);
        }

        if (ret[x][y]["room type"] == "building")
        {
            ret[x][y]["icon"] = loadRegionMapDecorator(dbHandle,
                regionId, x, y);
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping createEmptyGrid(int x, int y)
{
    mapping ret = ([]);
    for (int i = 0; i < x; i++)
    {
        ret[i] = ([]);
        for (int j = 0; j < y; j++)
        {
            ret[i][j] = ([
                "x":i,
                "y" : j,
                "room type" : "none",
                "exits": ([ ])
            ]);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping loadRegion(string enterFrom, string location)
{
    mapping ret = 0;

    if(stringp(enterFrom) && stringp(location))
    {
        string query = sprintf("select * from regions "
            "where entryPoint = '%s' and entryDirection = '%s';", 
            location, enterFrom);

        int dbHandle = connect();
        db_exec(dbHandle, query);
        mixed result = db_fetch(dbHandle);

        if (sizeof(result))
        {
            // The entry point/direction pair is unique
            ret = ([
                "name": convertString(result[1]),
                "type": convertString(result[2]),
                "x-dimension": to_int(result[3]),
                "y-dimension": to_int(result[4]),
                "entry point": convertString(result[5]),
                "entry direction": convertString(result[6]),
            ]);

            mapping grid = createEmptyGrid(to_int(result[3]),
                to_int(result[4]));

            ret["grid"] = loadRegionGrid(dbHandle, to_int(result[0]), grid);
        }
        disconnect(dbHandle);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask void saveEnvironmentalObjects(int dbHandle, int environmentId,
    mapping items)
{
    string query;
    mixed result;
    string *ids = ({});

    if (sizeof(items))
    {
        foreach(string item in m_indices(items))
        {
            query = sprintf("select saveEnvironmentalObject("
                "%d,'%s','%s',%d,%d,%d,'%s');",
                environmentId,
                sanitizeString(items[item]["state"]),
                sanitizeString(item),
                items[item]["is random"],
                items[item]["probability"],
                items[item]["quantity"],
                sanitizeString(items[item]["type"]));

            db_exec(dbHandle, query);
            result = db_fetch(dbHandle);

            ids += ({ sanitizeString(result[0]) });
        }
    }

    query = sprintf("delete from environmentalObjects "
        "where environmentId = %d and id not in (%s);",
        environmentId, implode(ids, ","));

    db_exec(dbHandle, query);
    result = db_fetch(dbHandle);
}

/////////////////////////////////////////////////////////////////////////////
private nomask void saveEnvironmentalElements(int dbHandle, int environmentId,
    mapping elements)
{
    string query;
    mixed result;
    string *ids = ({});

    if (sizeof(elements))
    {
        foreach(string element in m_indices(elements))
        {
            string value = regreplace(element, "([^,]+),*.*", "\\1", 1);
            string location = (value != element) ?
                regreplace(element, "[^,]+,(.*)", "\\1", 1) : "";

            query = sprintf("select saveEnvironmentalElement("
                "%d,'%s','%s','%s','%s',%d,%d,%d,%d,%d,%d);",
                environmentId,
                sanitizeString(elements[element]["type"]),
                sanitizeString(value),
                sanitizeString(elements[element]["state"]),
                sanitizeString(location),
                elements[element]["x-coordinate"],
                elements[element]["y-coordinate"],
                elements[element]["z-coordinate"],
                elements[element]["x-rotation"],
                elements[element]["y-rotation"],
                elements[element]["z-rotation"]);

            db_exec(dbHandle, query);
            result = db_fetch(dbHandle);

            ids += ({ sanitizeString(result[0]) });
        }
    }

    query = sprintf("delete from environmentalElements "
        "where environmentId = %d and id not in (%s);",
        environmentId, implode(ids, ","));

    db_exec(dbHandle, query);
    result = db_fetch(dbHandle);
}

/////////////////////////////////////////////////////////////////////////////
private nomask void saveEnvironmentExits(int dbHandle, int environmentId,
    mapping exits)
{
    string query = sprintf("delete from environmentExits "
        "where environmentId = %d", environmentId);

    if (sizeof(exits))
    {
        query += " and direction not in ('" +
            implode(m_indices(exits), "','") + "')";
    }
    query += ";";

    db_exec(dbHandle, query);
    mixed result = db_fetch(dbHandle);

    if (sizeof(exits))
    {
        foreach(string exit in m_indices(exits))
        {
            query = sprintf("call saveEnvironmentExit(%d,'%s','%s');",
                environmentId, exit, exits[exit]);

            db_exec(dbHandle, query);
            result = db_fetch(dbHandle);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void saveRegionMapDecorator(int dbHandle, int regionId,
    mapping building)
{
    string query;
    mixed result;

    if (sizeof(building) && member(building, "icon"))
    {
        query = sprintf("call saveRegionMapDecorators(%d,'%s','%s','%s','%s',%d,%d);",
            regionId,
            sanitizeString(building["icon"]["class"]),
            sanitizeString(building["icon"]["type"]),
            sanitizeString(building["icon"]["size"]),
            sanitizeString(building["icon"]["color"]),
            building["x"],
            building["y"]);

        db_exec(dbHandle, query);
        result = db_fetch(dbHandle);
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void saveRegionExitPoint(int dbHandle, int regionId, 
    int environmentId, mapping exit)
{
    string query;
    mixed result;

    if (sizeof(exit))
    {
        query = sprintf("call saveRegionExit(%d,%d,'%s','%s','%s',%d,%d);",
            regionId,
            environmentId,
            sanitizeString(exit["exit to"]),
            sanitizeString(exit["name"]),
            sanitizeString(member(exit, "state") ? exit["state"] : "default"),
            exit["exit coordinates"][0],
            exit["exit coordinates"][1]);

        db_exec(dbHandle, query);
        result = db_fetch(dbHandle);
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void saveEnvironmentData(int dbHandle, int regionId,
    mapping *rooms)
{
    if (sizeof(rooms))
    {
        foreach(mapping room in rooms)
        {
            string query = sprintf("select saveEnvironmentInstance("
                "%d,%d,%d,'%s','%s','%s',%d,'%s','%s','%s');",
                regionId,
                room["x"],
                room["y"],
                sanitizeString(room["room type"]),
                sanitizeString(room["identifier"]),
                sanitizeString(room["name"]),
                room["is cloned"],
                sanitizeString(room["description"]),
                sanitizeString(room["shop"]),
                sanitizeString("default"));

            db_exec(dbHandle, query);
            mixed result = db_fetch(dbHandle);

            if (result && result[0])
            {
                int environmentId = to_int(result[0]);
                saveEnvironmentExits(dbHandle, environmentId, room["exits"]);
                saveEnvironmentalElements(dbHandle, environmentId, 
                    room["elements"]);
                saveEnvironmentalObjects(dbHandle, environmentId,
                    room["room objects"]);

                if (room["room type"] == "exit")
                {
                    saveRegionExitPoint(dbHandle, regionId, environmentId,
                        room);
                }

                if (room["room type"] == "building")
                {
                    saveRegionMapDecorator(dbHandle, regionId, room);
                }
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void saveRegion(string name, string type, int x, int y,
    string entryPoint, string entryDirection, mapping *rooms)
{
    string query = sprintf("select saveRegion('%s','%s',%d,%d,'%s','%s');",
        sanitizeString(name), 
        sanitizeString(type), 
        x, 
        y, 
        sanitizeString(entryPoint),
        sanitizeString(entryDirection));

    int dbHandle = connect();
    db_exec(dbHandle, query);
    mixed result = db_fetch(dbHandle);

    if (result && result[0])
    {
        saveEnvironmentData(dbHandle, to_int(result[0]), rooms);
    }
    disconnect(dbHandle);
}
