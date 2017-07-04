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
protected nomask mapping getResearch(int playerId, int dbHandle)
{
    mapping ret = (["research":([])]);

    string query = sprintf("select * from research "
        "where playerid = '%d'", playerId);
    db_exec(dbHandle, query);

    mixed result;

    do
    {
        result = db_fetch(dbHandle);
        if (result)
        {
            ret["research"][result[2]] = ([
                "when research began":to_int(result[3]),
                "when research complete": to_int(result[4]),
                "time spent learning": to_int(result[5]),
                "research complete": to_int(result[6]),
                "time to complete learning": to_int(result[7]),
                "cooldown": to_int(result[8])
            ]);
        }
    } while (result);

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask mapping getResearchChoices(int playerId, int dbHandle)
{
    mapping ret = (["researchChoices":([])]);

    string query = sprintf("select * from researchChoicesView "
        "where playerid = '%d'", playerId);
    db_exec(dbHandle, query);

    mixed result;

    do
    {
        result = db_fetch(dbHandle);
        if (result)
        {
            if(!member(ret["researchChoices"], result[1]))
            {
                ret["researchChoices"][result[1]] = ([]);
            }

            ret["researchChoices"][result[1]][convertString(result[2])] = ([
                "type": convertString(result[3]),
                "name": convertString(result[4]),
                "description": convertString(result[5]),
                "key": convertString(result[6]),
                "choice": convertString(result[1])
            ]);
        }
    } while (result);

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask mapping getOpenResearchTrees(int playerId, int dbHandle)
{
    mapping ret = (["openResearchTrees":({}) ]);

    string query = sprintf("select researchTree from openResearchTrees "
        "where playerid = '%d'", playerId);
    db_exec(dbHandle, query);

    mixed result;

    do
    {
        result = db_fetch(dbHandle);
        if (result)
        {
            ret["openResearchTrees"] += ({ convertString(result[0]) });
        }
    } while (result);

    ret["openResearchTrees"] -= ({ "" });
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void saveResearch(int dbHandle, int playerId, mapping playerData)
{
    if (member(playerData, "research") &&
        sizeof(playerData["research"]))
    {
        string *researchItems = m_indices(playerData["research"]);
        foreach(string research in researchItems)
        {
            string query = sprintf("call saveResearch("
                "%d,'%s',%d,%d,%d,%d,%d,%d);",
                playerId,
                db_conv_string(research),
                playerData["research"][research]["when research began"],
                playerData["research"][research]["when research complete"],
                playerData["research"][research]["time spent learning"],
                playerData["research"][research]["research complete"],
                playerData["research"][research]["time to complete learning"],
                playerData["research"][research]["cooldown"]);
            db_exec(dbHandle, query);
            mixed result = db_fetch(dbHandle);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void saveResearchChoices(int dbHandle, int playerId, mapping playerData)
{
    string query = sprintf("call pruneResearchChoices(%d);", playerId);
    db_exec(dbHandle, query);
    mixed result = db_fetch(dbHandle);

    if (member(playerData, "researchChoices") &&
        sizeof(playerData["researchChoices"]))
    {
        string *choices = m_indices(playerData["researchChoices"]);
        foreach(string choice in choices)
        {
            query = sprintf("select saveResearchChoice(%d,'%s');",
                playerId, db_conv_string(choice));

            db_exec(dbHandle, query);
            result = db_fetch(dbHandle);

            if (sizeof(result))
            {
                int id = to_int(result[0]);
                string *options = m_indices(playerData["researchChoices"][choice]);
                foreach(string option in options)
                {
                    mapping optionMap = playerData["researchChoices"][choice][option];
                    query = sprintf("call saveResearchChoiceOption("
                        "%d,'%s','%s','%s','%s','%s');", id,
                        db_conv_string(option),
                        db_conv_string(optionMap["type"]),
                        db_conv_string(optionMap["name"]),
                        db_conv_string(optionMap["description"]),
                        db_conv_string(optionMap["key"]));

                    db_exec(dbHandle, query);
                    result = db_fetch(dbHandle);
                }
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void saveOpenResearchTrees(int dbHandle, int playerId, mapping playerData)
{
    if (member(playerData, "openResearchTrees") &&
        sizeof(playerData["openResearchTrees"]))
    {
        foreach(string tree in playerData["openResearchTrees"])
        {
            string query = sprintf("call saveOpenResearchTrees(%d,'%s');",
                playerId, db_conv_string(tree));
            db_exec(dbHandle, query);
            mixed result = db_fetch(dbHandle);
        }
    }
}
