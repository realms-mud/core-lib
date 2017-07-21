//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

/////////////////////////////////////////////////////////////////////////////
private string convertString(string input)
{
    string ret = input;
    if (!stringp(input))
    {
        ret = "";
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask mapping getGuildData(int playerId, int dbHandle)
{
    mapping ret = ([ "guilds": ([]) ]);

    string query = sprintf("select * from guilds "
        "where playerid = '%d'", playerId);
    db_exec(dbHandle, query);

    mixed result;
    
    do
    {
        result = db_fetch(dbHandle);
        if (result)
        {
            ret["guilds"][result[2]] = ([
                "level": to_int(result[3]),
                "experience": to_int(result[4]),
                "rank": convertString(result[5]),
                "title": convertString(result[6]),
                "pretitle": convertString(result[7]),
                "left guild": to_int(result[8]),
                "anathema": to_int(result[9]),
                "rank advanced at": to_int(result[10])
            ]);
        }
    } while (result);

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void saveGuildData(int dbHandle, int playerId, mapping playerData)
{
    if (member(playerData, "guilds") &&
        sizeof(playerData["guilds"]))
    {
        string *guilds = m_indices(playerData["guilds"]);
        foreach(string guild in guilds)
        {
            string query = sprintf("call saveGuild("
                "%d,'%s','%s','%s','%s',%d,%d,%d,%d,%d);",
                playerId,
                db_conv_string(guild),
                db_conv_string(convertString(playerData["guilds"][guild]["title"])),
                db_conv_string(convertString(playerData["guilds"][guild]["pretitle"])),
                db_conv_string(convertString(playerData["guilds"][guild]["rank"])),
                playerData["guilds"][guild]["level"],
                playerData["guilds"][guild]["experience"],
                playerData["guilds"][guild]["left guild"],
                playerData["guilds"][guild]["anathema"],
                playerData["guilds"][guild]["rank advanced at"]);
            db_exec(dbHandle, query);
            mixed result = db_fetch(dbHandle);
        }
    }
}
