//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/secure/dataServices/dataService.c";

/////////////////////////////////////////////////////////////////////////////
public nomask mapping loadEnvironmentData()
{
    mapping ret = 0;
    string query = "select currentTime, currentDay, currentYear "
        "from environment where id=1;";

    int dbHandle = connect();
    db_exec(dbHandle, query);
    mixed result = db_fetch(dbHandle);
    disconnect(dbHandle);

    if (sizeof(result))
    {
        ret = ([]);
        ret["time"] = to_int(result[0]);
        ret["day"] = to_int(result[1]);
        ret["year"] = to_int(result[2]);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void saveEnvironmentData(int currentTime, int currentDay,
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
