//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, Realms MUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/secure/dataServices/dataService.c";

/////////////////////////////////////////////////////////////////////////////
public nomask string getCharacterState(string playerName, string targetKey)
{
    string ret = 0;
    string query = sprintf("select state from characterStates "
        "inner join players on characterStates.playerId = players.id and "
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
        ret = to_string(result[0]);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setCharacterState(string playerName,
    string targetKey, string value)
{
    string query = sprintf("call saveCharacterState('%s','%s','%s');",
        sanitizeString(lower_case(playerName)), 
        sanitizeString(targetKey), 
        sanitizeString(value));

    int dbHandle = connect();
    db_exec(dbHandle, query);
    mixed result = db_fetch(dbHandle);
    disconnect(dbHandle);
}
