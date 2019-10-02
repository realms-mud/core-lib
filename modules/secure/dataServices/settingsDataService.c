//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/secure/dataServices/dataService.c";

/////////////////////////////////////////////////////////////////////////////
private nomask mapping getPlayerBlockList(int dbHandle, string playerName)
{
    mapping ret = ([]);
    string query = sprintf("select player.name, blocked.name from blockedUsers "
        "inner join players player on player.id = blockedUsers.playerId "
        "inner join players blocked on blocked.id = blockedUsers.blockedPlayerId "
        "where player.name = '%s';",
        sanitizeString(playerName));

    db_exec(dbHandle, query);
    mixed result;

    while (result = db_fetch(dbHandle))
    {
        ret[result[1]] = "block";
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getPlayerSettings(int dbHandle, string playerName)
{
    mapping ret = ([]);
    string query = sprintf("select settings.* from settings "
        "inner join players on settings.playerId = players.id "
        "where players.name = '%s';",
        sanitizeString(playerName));

    db_exec(dbHandle, query);
    mixed result;

    while (result = db_fetch(dbHandle))
    {
        ret[result[2]] = result[3];
    }

    ret["blocks"] = getPlayerBlockList(dbHandle, playerName);

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask void saveBlockedUsers(int dbHandle, string playerName,
    mapping blockData)
{
    if (sizeof(blockData))
    {
        foreach(string blockedUser in m_indices(blockData))
        {
            string query = sprintf("call saveBlockedUser('%s','%s','%s');",
                sanitizeString(lower_case(playerName)),
                sanitizeString(blockedUser),
                sanitizeString(blockData[blockedUser]));

            db_exec(dbHandle, query);
            mixed result = db_fetch(dbHandle);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void saveSettings(int dbHandle, mapping playerData)
{
    if (sizeof(playerData) && member(playerData, "name"))
    {
        string playerName = playerData["name"];

        string *keys = filter(m_indices(playerData),
            (: (member(({ "blocks", "busy", "earmuffs", "page size",
                "color setting", "character set", "safety teleport",
                "display mini map", "display level comparison" }), $1) > -1) :));

        if (sizeof(keys))
        {
            foreach(string key in keys)
            {
                if (key == "blocks")
                {
                    saveBlockedUsers(dbHandle, playerName, playerData[key]);
                }
                else
                {
                    string query = sprintf("call saveSetting('%s','%s','%s');",
                        sanitizeString(lower_case(playerName)),
                        sanitizeString(key),
                        sanitizeString(to_string(playerData[key])));

                    db_exec(dbHandle, query);
                    mixed result = db_fetch(dbHandle);
                }
            }
        }
    }
}

/*
/////////////////////////////////////////////////////////////////////////////
public nomask int canSafetyTeleport()
{
    return lastSafetyTeleport <= time();
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setLastSafetyTeleport()
{
    lastSafetyTeleport = time() + 3600;
}
*/