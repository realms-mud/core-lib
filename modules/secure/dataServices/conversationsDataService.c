//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

/////////////////////////////////////////////////////////////////////////////
public nomask int getOpinionOfCharacter(string playerName,
                                        string targetKey)
{
    int ret = 0;
    string query = sprintf("select opinion from opinions "
        "inner join players on opinions.playerId = players.id and "
        "players.name = '%s' "
        "where targetKey = '%s';",
        db_conv_string(playerName), 
        db_conv_string(targetKey));

    int dbHandle = db_connect(RealmsDatabase());
    db_exec(dbHandle, query);
    mixed result = db_fetch(dbHandle);

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
    string query = sprintf("call saveOpinionOfCharacter('%s','%s', %d);",
        db_conv_string(playerName), db_conv_string(targetKey), value);

    int dbHandle = db_connect(RealmsDatabase());
    db_exec(dbHandle, query);
    mixed result = db_fetch(dbHandle);
}
