//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/secure/dataServices/dataService.c";

/////////////////////////////////////////////////////////////////////////////
private nomask mapping *loadEnvironmentObjects(int dbHandle, int environmentId)
{
    mapping *ret = ({});

    string query = sprintf("select state, path, isRandom, probability "
        "from environmentalObjects "
        "where environmentId = %d;", environmentId);

    db_exec(dbHandle, query);

    mixed result;
    do
    {
        result = db_fetch(dbHandle);
        if (result)
        {
            ret += ({ ([
                "state": convertString(result[0]),
                "path": convertString(result[1]),
                "is random": to_int(result[2]),
                "probability": to_int(result[3])
            ]) });
        }
    } while (result);

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping *loadEnvironmentElements(int dbHandle, int environmentId)
{
    mapping *ret = ({});

    string query = sprintf("select type, value, state, location, "
        "x-coordinate, y-coordinate, z-coordinate "
        "from environmentalElements "
        "where environmentId = %d;", environmentId);

    db_exec(dbHandle, query);

    mixed result;
    do
    {
        result = db_fetch(dbHandle);
        if (result)
        {
            ret += ({ ([
                "element type": convertString(result[0]),
                "value": convertString(result[1]),
                "state": convertString(result[2]),
                "location": convertString(result[3]),
                "x-coordinate": to_int(result[4]),
                "y-coordinate": to_int(result[5]),
                "z-coordinate" : to_int(result[6])
            ]) });
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
private nomask mapping loadRegionGrid(int regionId, mapping grid)
{
    mapping ret = grid + ([]);

    string query = sprintf("select * from environmentView "
        "where regionId = %d;", regionId);

    int dbHandle = connect();
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
                "shop": convertString(result[9])
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
        ret[x][y]["elements"] = loadEnvironmentElements(dbHandle, environmentId);
        ret[x][y]["objects"] = loadEnvironmentObjects(dbHandle, environmentId);
    }
    disconnect(dbHandle);

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping loadRegion(string enterFrom, string location,
    mapping grid)
{
    mapping ret = 0;
    string query = sprintf("select * from regions "
        "where entryPoint = '%s' and entryDirection = '%s';", 
        enterFrom, location);

    int dbHandle = connect();
    db_exec(dbHandle, query);
    mixed result = db_fetch(dbHandle);
    disconnect(dbHandle);

    if (sizeof(result))
    {
        // The entry point/direction pair is unique
        ret = ([
            "name": convertString(result[1]),
            "type" : convertString(result[2]),
            "x-dimension" : to_int(result[3]),
            "y-dimension" : to_int(result[4]),
            "entry point" : convertString(result[5]),
            "entry direction" : convertString(result[6]),
        ]);
        ret["grid"] = loadRegionGrid(to_int(result[0]), grid);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void saveRegion(int currentTime, int currentDay,
    int currentYear)
{
    string query = sprintf("update environment set "
        "currentTime = %d, currentDay = %d, currentYear = %d "
        "where id = 1;", currentTime, currentDay, currentYear);

    int dbHandle = connect();
    db_exec(dbHandle, query);
    mixed result = db_fetch(dbHandle);
    disconnect(dbHandle);
}
