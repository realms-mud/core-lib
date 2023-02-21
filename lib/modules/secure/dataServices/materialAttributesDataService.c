//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/secure/dataServices/dataService.c";

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
        sanitizeString(playerData["title"] || ""),
        sanitizeString(playerData["pretitle"] || ""),
        sanitizeString(playerData["messageIn"] || ""),
        sanitizeString(playerData["messageOut"] || ""),
        sanitizeString(playerData["magicalMessageIn"] || ""),
        sanitizeString(playerData["magicalMessageOut"] || ""),
        sanitizeString(playerData["messageHome"] || ""),
        sanitizeString(playerData["messageClone"] || ""),
        sanitizeString(playerData["shortDescription"] || ""),
        sanitizeString(playerData["longDescription"] || ""));

    db_exec(dbHandle, query);
    mixed result = db_fetch(dbHandle);
}
