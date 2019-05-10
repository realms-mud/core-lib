//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/secure/dataServices/dataService.c";

/////////////////////////////////////////////////////////////////////////////
protected nomask mapping getPlayerDomains(int playerId, int dbHandle)
{
    mapping ret = ([
    ]);

/*    string query = sprintf("select * from domains "
        "where playerid = '%d'", playerId);
    db_exec(dbHandle, query);

    mixed result;

    do
    {
        result = db_fetch(dbHandle);
        if (result)
        {
            ret["factions"][result[2]] = ([
                "disposition":convertString(result[3]),
                "reputation": to_int(result[4]),
                "last interaction": to_int(result[5]),
                "last interaction reputation": to_int(result[6]),
                "number of interactions": to_int(result[7]),
                "disposition time": to_int(result[8]),
            ]);

            if (stringp(result[9]) && (to_int(result[9]) == 1))
            {
                ret["memberOfFactions"] += ({ result[2] });
            }
        }
    } while (result);
*/
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void saveDomains(int dbHandle, int playerId, mapping playerData)
{
    if (member(playerData, "domains") && sizeof(playerData["domains"]))
    {
        string *domains = m_indices(playerData["domains"]);
        foreach(string domain in domains)
        {
         /*   string query = sprintf("call saveFaction("
                "%d,'%s','%s',%d,%d,%d,%d,%d,%d);",
                playerId,
                sanitizeString(faction),
                sanitizeString(playerData["factions"][faction]["disposition"]),
                playerData["factions"][faction]["reputation"],
                playerData["factions"][faction]["last interaction"],
                playerData["factions"][faction]["last interaction reputation"],
                playerData["factions"][faction]["number of interactions"],
                playerData["factions"][faction]["disposition time"],
                (member(playerData["memberOfFactions"], faction) > -1)
            );
            db_exec(dbHandle, query);
            mixed result = db_fetch(dbHandle);
            */
        }
    }
}
