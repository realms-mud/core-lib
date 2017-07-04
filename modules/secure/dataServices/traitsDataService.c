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
protected nomask mapping getTraits(int playerId, int dbHandle)
{
    mapping ret = (["traits":([])]);

    string query = sprintf("select * from traitsView "
        "where playerid = '%d'", playerId);
    db_exec(dbHandle, query);

    mixed result;

    do
    {
        result = db_fetch(dbHandle);
        if (result)
        {
            ret["traits"][result[1]] = ([
                "name":convertString(result[2]),
                "added" : to_int(result[3])
            ]);

            if (stringp(result[4]))
            {
                ret["traits"][result[1]]["end time"] = to_int(result[4]);
            }
            if (stringp(result[5]))
            {
                ret["traits"][result[1]]["expire message"] = convertString(result[5]);
            }
            if (stringp(result[6]))
            {
                ret["traits"][result[1]]["triggering research"] = convertString(result[6]);
            }
        }
    } while (result);

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask mapping getTemporaryTraits(int playerId, int dbHandle)
{
    mapping ret = ([]);

    string query = sprintf("select traitList from temporaryTraits "
        "where playerid = '%d'", playerId);

    db_exec(dbHandle, query);
    mixed result = db_fetch(dbHandle);

    if (result)
    {
        ret["temporaryTraits"] = convertString(result[0]);
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void saveTraits(int dbHandle, int playerId, mapping playerData)
{
    if (member(playerData, "traits") &&
        sizeof(playerData["traits"]))
    {
        string *traits = m_indices(playerData["traits"]);
        foreach(string trait in traits)
        {
            string query = sprintf("call saveTraits("
                "%d,'%s','%s',%d,%d,'%s','%s');",
                playerId,
                db_conv_string(trait),
                db_conv_string(playerData["traits"][trait]["name"]),
                playerData["traits"][trait]["added"],
                playerData["traits"][trait]["end time"],
                db_conv_string(playerData["traits"][trait]["expire message"] || ""),
                db_conv_string(playerData["traits"][trait]["triggering research"] || ""));
            db_exec(dbHandle, query);
            mixed result = db_fetch(dbHandle);
        }
    }

    if (member(playerData, "temporaryTraits") &&
        sizeof(playerData["temporaryTraits"]))
    {
        string query = sprintf("call saveTemporaryTraits(%d,'%s');",
            playerId, db_conv_string(playerData["temporaryTraits"]));

        db_exec(dbHandle, query);
        mixed result = db_fetch(dbHandle);
    }
}
