//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

/////////////////////////////////////////////////////////////////////////////
protected nomask mapping getMaterialAttributes(int playerId, int dbHandle)
{
    mapping ret = ([]);

    string query = sprintf("select * from materialAttributes "
        "where playerid = '%d'", playerId);
    db_exec(dbHandle, query);

    mixed result;

    do
    {
        result = db_fetch(dbHandle);
        if (result)
        {
            ret[result[2]] = result[3];
        }
    } while (result);

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void saveMaterialAttributes(int dbHandle, int playerId, mapping playerData)
{
    string query = sprintf("call saveMaterialAttributes("
        "%d,'%s','%s','%s','%s','%s','%s','%s','%s','%s','%s');",
        playerId,
        db_conv_string(playerData["title"]),
        db_conv_string(playerData["pretitle"]),
        db_conv_string(playerData["messageIn"]),
        db_conv_string(playerData["messageOut"]),
        db_conv_string(playerData["magicalMessageIn"]),
        db_conv_string(playerData["magicalMessageOut"]),
        db_conv_string(playerData["messageHome"]),
        db_conv_string(playerData["messageClone"]),
        db_conv_string(playerData["shortDescription"]),
        db_conv_string(playerData["longDescription"]));

    db_exec(dbHandle, query);
    mixed result = db_fetch(dbHandle);
}
