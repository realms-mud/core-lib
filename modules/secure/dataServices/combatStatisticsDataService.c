//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

/////////////////////////////////////////////////////////////////////////////
public nomask void saveCombatStatistics(string playerName,
                                        string foeKey,
                                        string foeName,
                                        int foeLevel)
{
    string query = sprintf("call saveCombatStatistics('%s','%s','%s',%d);",
        db_conv_string(playerName), 
        db_conv_string(foeKey), 
        db_conv_string(foeName), 
        foeLevel);

    int dbHandle = db_connect(RealmsDatabase());
    db_exec(dbHandle, query);
    mixed result = db_fetch(dbHandle);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void saveCombatStatisticsForRace(string playerName, string race)
{
    string query = sprintf("call saveCombatStatisticsForRace('%s','%s');",
        db_conv_string(playerName), db_conv_string(race));

    int dbHandle = db_connect(RealmsDatabase());
    db_exec(dbHandle, query);
    mixed result = db_fetch(dbHandle);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int bestKillMeetsLevel(string name, int level)
{
    int ret = 0;

    string query = sprintf("select id from combatStatistics "
        "where (playerid = (select id from players where name = '%s')) "
        "and (isBestKill = 1) and (level >= %d)",
        db_conv_string(name), level);

    int dbHandle = db_connect(RealmsDatabase());
    db_exec(dbHandle, query);
    mixed result = db_fetch(dbHandle);
    db_close(dbHandle);

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
        db_conv_string(name), db_conv_string(race), timesKilled);

    int dbHandle = db_connect(RealmsDatabase());
    db_exec(dbHandle, query);
    mixed result = db_fetch(dbHandle);
    db_close(dbHandle);

    if (result)
    {
        ret = result[0];
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getBestKill(string player)
{
    mapping ret = 0;

    string query = sprintf("select name, level, foeKey, timesKilled "
        "from combatStatistics "
        "where playerid = (select id from players where name = '%s') "
        "and isBestKill = 1",
        db_conv_string(player));

    int dbHandle = db_connect(RealmsDatabase());
    db_exec(dbHandle, query);
    mixed result = db_fetch(dbHandle);
    db_close(dbHandle);

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
    mapping ret = 0;

    string query = sprintf("select name, level, foeKey, timesKilled "
        "from combatStatistics "
        "where playerid = (select id from players where name = '%s') "
        "and isNemesis = 1",
        db_conv_string(player));

    int dbHandle = db_connect(RealmsDatabase());
    db_exec(dbHandle, query);
    mixed result = db_fetch(dbHandle);
    db_close(dbHandle);

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