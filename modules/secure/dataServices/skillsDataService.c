//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

/////////////////////////////////////////////////////////////////////////////
protected nomask mapping getSkills(int playerId, int dbHandle)
{
    mapping ret = (["skills":([])]);

    string query = sprintf("select * from skills "
        "where playerid = '%d'", playerId);
    db_exec(dbHandle, query);

    mixed result;

    do
    {
        result = db_fetch(dbHandle);
        if (result)
        {
            ret["skills"][result[2]] = to_int(result[3]);
        }
    } while (result);

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void saveSkills(int dbHandle, int playerId, mapping playerData)
{
    if (member(playerData, "skills") &&
        sizeof(playerData["skills"]))
    {
        string *skills = m_indices(playerData["skills"]);
        foreach(string skill in skills)
        {
            string query = sprintf("call saveSkills(%d,'%s',%d);",
                playerId,
                db_conv_string(skill),
                playerData["skills"][skill]);
            db_exec(dbHandle, query);
            mixed result = db_fetch(dbHandle);
        }
    }
}
