//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/secure/dataServices/dataService.c";

/////////////////////////////////////////////////////////////////////////////
public nomask int getOpinionOfCharacter(string playerName,
                                        string targetKey)
{
    int ret = 0;
    string query = sprintf("select opinion from opinions "
        "inner join players on opinions.playerId = players.id and "
        "players.name = '%s' "
        "where targetKey = '%s';",
        sanitizeString(playerName), 
        sanitizeString(targetKey));

    int dbHandle = connect();
    db_exec(dbHandle, query);
    mixed result = db_fetch(dbHandle);
    disconnect(dbHandle);

    if (sizeof(result))
    {
        ret = to_int(result[0]);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setOpinionOfCharacter(string playerName,
    string targetKey, int value)
{
    string query = sprintf("call saveOpinionOfCharacter('%s','%s', %d, %d);",
        sanitizeString(playerName), sanitizeString(targetKey),
        value, time());

    int dbHandle = connect();
    db_exec(dbHandle, query);
    mixed result = db_fetch(dbHandle);
    disconnect(dbHandle);
}
