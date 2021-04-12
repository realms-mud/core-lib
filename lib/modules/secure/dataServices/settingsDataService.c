//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
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
private nomask mapping getPlayerRoles(int dbHandle, string playerName)
{
    mapping ret = ([]);
    string query = sprintf("select roles.name, roleTypes.type "
        "from playerRoles "
        "inner join roles on playerRoles.id = roles.id "
        "inner join roleTypes on roles.typeid = roleTypes.id "
        "inner join players on players.id = playerRoles.playerid "
        "where players.name = '%s';",
        sanitizeString(playerName));

    db_exec(dbHandle, query);
    mixed result;

    while (result = db_fetch(dbHandle))
    {
        ret[result[0]] = result[1];
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
    ret["roles"] = getPlayerRoles(dbHandle, playerName);

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
                "display mini map", "display level comparison",
                "combat verbosity" }), $1) > -1) :));

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

/////////////////////////////////////////////////////////////////////////////
public nomask int addRole(string newRole, string type)
{
    int ret = 0;
    string *inherits = this_player() ? inherit_list(this_player()) : 0;

    if (inherits && 
        (member(inherits, "/lib/realizations/wizard.c") > -1) &&
        (member(this_player()->groups(), "elder") > -1))
    {
        int dbHandle = connect();

        string query = sprintf("select createRole('%s','%s');",
            sanitizeString(newRole),
            sanitizeString(type));

        db_exec(dbHandle, query);
        mixed result = db_fetch(dbHandle);
        ret = result ? to_int(result[0]) : 0;
        disconnect(dbHandle);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private string isValidLevelForRole(int dbHandle, string role)
{
    string ret = 0;

    string query = sprintf("select wizardTypes.type, roleTypes.type "
        "from roles "
        "inner join roleTypes on roleTypes.id = roles.typeId "
        "inner join wizardTypes on roleTypes.level = wizardTypes.id "
        "where roles.name = '%s';",
        sanitizeString(role));

    db_exec(dbHandle, query);
    mixed result = db_fetch(dbHandle);
    string level = result ? convertString(result[0]) : 0;

    if (level && (member(this_player()->groups(), level) > -1))
    {
        ret = result ? convertString(result[1]) : 0;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string addRoleToPlayer(object character, string newRole)
{
    string ret = 0;
    string *inherits = this_player() ? inherit_list(this_player()) : 0;

    if (inherits && objectp(character) && 
        (member(inherits, "/lib/realizations/wizard.c") > -1))
    {
        int dbHandle = connect();
        ret = isValidLevelForRole(dbHandle, newRole);

        if (ret)
        {
            string query = sprintf("call saveRoles('%s','%s');",
                sanitizeString(character->RealName()),
                sanitizeString(newRole));

            db_exec(dbHandle, query);
            mixed result = db_fetch(dbHandle);
        }
        disconnect(dbHandle);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int removeRoleFromPlayer(object character, string roleToRemove)
{
    int ret = 0;
    string *inherits = this_player() ? inherit_list(this_player()) : 0;

    if (inherits && objectp(character) && 
        (member(inherits, "/lib/realizations/wizard.c") > -1))
    {
        int dbHandle = connect();
        ret = isValidLevelForRole(dbHandle, roleToRemove) ? 1 : 0;

        if (ret)
        {
            string query = sprintf("delete from playerRoles "
                "where playerid = (select id from players where name = '%s') and "
                "roleid = (select id from roles where name = '%s');",
                sanitizeString(character->RealName()),
                sanitizeString(roleToRemove));

            db_exec(dbHandle, query);
            mixed result = db_fetch(dbHandle);
        }
        disconnect(dbHandle);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping availableRoles()
{
    mapping ret = ([]);
    int dbHandle = connect();

    string query = "select roles.name, wizardTypes.type, "
        "roleTypes.type from roles "
        "inner join roleTypes on roleTypes.id = roles.typeId "
        "inner join wizardTypes on roleTypes.level = wizardTypes.id;";

    db_exec(dbHandle, query);
    mixed result;

    do
    {
        result = db_fetch(dbHandle);
        if (result)
        {
            ret[result[0]] = ([
                "add level": convertString(result[1]),
                "type": convertString(result[2])
            ]);
        }
    } while (result);
    disconnect(dbHandle);

    return ret;
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
