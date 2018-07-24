//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/secure/dataServices/dataService.c";

/////////////////////////////////////////////////////////////////////////////
public nomask void saveCombatStatistics(string playerName,
                                        string foeKey,
                                        string foeName,
                                        int foeLevel)
{
    string query = sprintf("call saveCombatStatistics('%s','%s','%s',%d);",
        sanitizeString(playerName), 
        sanitizeString(foeKey), 
        sanitizeString(foeName), 
        foeLevel);

    int dbHandle = connect();
    db_exec(dbHandle, query);
    mixed result = db_fetch(dbHandle);
    disconnect(dbHandle);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void saveCombatStatisticsForRace(string playerName, string race)
{
    string query = sprintf("call saveCombatStatisticsForRace('%s','%s');",
        sanitizeString(playerName), sanitizeString(race));

    int dbHandle = connect();
    db_exec(dbHandle, query);
    mixed result = db_fetch(dbHandle);
    disconnect(dbHandle);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int bestKillMeetsLevel(string name, int level)
{
    int ret = 0;

    string query = sprintf("select id from combatStatistics "
        "where (playerid = (select id from players where name = '%s')) "
        "and (isBestKill = 1) and (level >= %d)",
        sanitizeString(name), level);

    int dbHandle = connect();
    db_exec(dbHandle, query);
    mixed result = db_fetch(dbHandle);
    disconnect(dbHandle);

    if (result)
    {
        ret = result[0];
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int racialKillsMeetCount(string name, string race, int timesKilled)
{
    int ret = 0;

    string query = sprintf("select id from combatStatisticsForRace "
        "where (playerid = (select id from players where name = '%s')) "
        "and (race = '%s') and (timesKilled >= %d)",
        sanitizeString(name), sanitizeString(race), timesKilled);

    int dbHandle = connect();
    db_exec(dbHandle, query);
    mixed result = db_fetch(dbHandle);
    disconnect(dbHandle);

    if (result)
    {
        ret = result[0];
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getBestKill(string player)
{
    mapping ret = ([]);

    string query = sprintf("select name, level, foeKey, timesKilled "
        "from combatStatistics "
        "where playerid = (select id from players where name = '%s') "
        "and isBestKill = 1",
        sanitizeString(player));

    int dbHandle = connect();
    db_exec(dbHandle, query);
    mixed result = db_fetch(dbHandle);
    disconnect(dbHandle);

    if (result)
    {
        ret = ([
            "name": result[0],
            "level": result[1],
            "key": result[2],
            "times killed": result[3]
        ]);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getNemesis(string player)
{
    mapping ret = ([]);

    string query = sprintf("select name, level, foeKey, timesKilled "
        "from combatStatistics "
        "where playerid = (select id from players where name = '%s') "
        "and isNemesis = 1",
        sanitizeString(player));

    int dbHandle = connect();
    db_exec(dbHandle, query);
    mixed result = db_fetch(dbHandle);
    disconnect(dbHandle);

    if (result)
    {
        ret = ([
            "name":result[0],
            "level": result[1],
            "key": result[2],
            "times killed": result[3]
        ]);
    }
    return ret;
}
