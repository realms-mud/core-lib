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
protected nomask mapping getQuestData(int playerId, int dbHandle)
{
    mapping ret = (["quests":([])]);

    string query = sprintf("select * from quests "
        "where playerid = '%d'", playerId);
    db_exec(dbHandle, query);

    mixed result;

    do
    {
        result = db_fetch(dbHandle);
        if (result)
        {
            ret["quests"][result[2]] = ([
                "name":convertString(result[3]),
                "state" : convertString(result[4]),
                "states completed" : convertString(result[5]),
                "is active" : to_int(result[6]),
                "is completed" : to_int(result[7])
            ]);
        }
    } while (result);

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void saveQuestData(int dbHandle, int playerId, mapping playerData)
{
    if (member(playerData, "quests") &&
        sizeof(playerData["quests"]))
    {
        string *quests = m_indices(playerData["quests"]);
        foreach(string quest in quests)
        {
            string query = sprintf("call saveQuest("
                "%d,'%s','%s','%s','%s',%d,%d);",
                playerId,
                db_conv_string(quest),
                db_conv_string(playerData["quests"][quest]["name"]),
                db_conv_string(playerData["quests"][quest]["state"]),
                db_conv_string(playerData["quests"][quest]["states completed"]),
                playerData["quests"][quest]["is active"],
                playerData["quests"][quest]["is completed"]);
            db_exec(dbHandle, query);
            mixed result = db_fetch(dbHandle);
        }
    }
}
