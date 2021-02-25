//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/secure/dataServices/dataService.c";

/////////////////////////////////////////////////////////////////////////////
protected nomask mapping getResearch(int playerId, int dbHandle)
{
    mapping ret = (["research":([])]);

    string query = sprintf("select r.*, s.sustainedActive, "
        "s.activeCount, s.ModifierFQN from research r "
        "left outer join sustainedEffects s on r.id = s.researchId "
        "where r.playerid = '%d'", playerId);
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
                "cooldown": to_int(result[8]),
                "sustained active": to_int(result[9]),
                "active count": to_int(result[10]),
                "active modifier object": result[11]
            ]);

            if (!ret["research"][result[2]]["sustained active"])
            {
                m_delete(ret["research"][result[2]], "sustained active");
            }
            if (!ret["research"][result[2]]["active count"])
            {
                m_delete(ret["research"][result[2]], "active count");
            }
            if (!ret["research"][result[2]]["active modifier object"])
            {
                m_delete(ret["research"][result[2]], "active modifier object");
            }
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
protected nomask mapping *getCompositeResearchElements(int compositeResearchId, 
    int dbHandle)
{
    mapping *ret = ({ });

    string query = sprintf("select research.path, "
            "compositeResearchElements.type, "
            "compositeResearchElements.description, "
            "compositeResearchElements.orderInSequence "
        "from compositeResearchElements "
        "inner join research on compositeResearchElements.researchid = research.id "
        "where compositeresearchid = '%d' "
        "order by compositeResearchElements.orderInSequence, "
        "compositeResearchElements.type;", 
        compositeResearchId);
    db_exec(dbHandle, query);

    mixed result;
    do
    {
        result = db_fetch(dbHandle);

        if (result)
        {
            ret += ({ ([
                "research": convertString(result[0]),
                "type": convertString(result[1]),
                "description": convertString(result[2]),
                "order in sequence": to_int(result[3])
            ]) });
        }
    } while (result);

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask mapping getCompositeResearch(int playerId, int dbHandle)
{
    mapping ret = (["compositeResearch":([]) ]);

    string query = sprintf("select id, `name`, `alias`, `constraint`, `type` "
        "from compositeResearch where playerid = '%d'", playerId);
    db_exec(dbHandle, query);

    mixed result;

    do
    {
        result = db_fetch(dbHandle);
        if (result)
        {
            ret["compositeResearch"][convertString(result[1])] = ([
                "alias": convertString(result[2]),
                "constraint": convertString(result[3]),
                "type": convertString(result[4]),
                "elements": 
                    getCompositeResearchElements(to_int(result[0]), dbHandle)
            ]);
        }
    } while (result);

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
                sanitizeString(research),
                playerData["research"][research]["when research began"],
                playerData["research"][research]["when research complete"],
                playerData["research"][research]["time spent learning"],
                playerData["research"][research]["research complete"],
                playerData["research"][research]["time to complete learning"],
                playerData["research"][research]["cooldown"]);

            db_exec(dbHandle, query);
            mixed result = db_fetch(dbHandle);

            if (member(playerData["research"][research], "sustained active"))
            {
                query = sprintf("call saveSustainedEffect("
                    "%d,'%s',%d,%d,'%s');",
                    playerId,
                    sanitizeString(research),
                    playerData["research"][research]["sustained active"],
                    playerData["research"][research]["active count"],
                    sanitizeString(playerData["research"][research]["active modifier object"]));

                db_exec(dbHandle, query);
                result = db_fetch(dbHandle);
            }
            else
            {
                query = sprintf("call deleteSustainedEffect("
                    "%d,'%s');",
                    playerId,
                    sanitizeString(research));

                db_exec(dbHandle, query);
                result = db_fetch(dbHandle);
            }
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
                playerId, sanitizeString(choice));

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
                        sanitizeString(option),
                        sanitizeString(optionMap["type"]),
                        sanitizeString(optionMap["name"]),
                        sanitizeString(optionMap["description"]),
                        sanitizeString(optionMap["key"]));

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
                playerId, sanitizeString(tree));
            db_exec(dbHandle, query);
            mixed result = db_fetch(dbHandle);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void saveCompositeResearchElements(int dbHandle, 
    string playerName, string compositeResearch, mapping *researchData)
{
    string query = sprintf("delete from compositeResearchElements "
        "where compositeresearchid = (select id from compositeResearch "
        "where name = '%s' and playerid = (select id from players "
        "where name = '%s'));", compositeResearch, playerName);

    db_exec(dbHandle, query);
    mixed result = db_fetch(dbHandle);

    foreach(mapping element in researchData)
    {
        query = sprintf("call saveCompositeResearchElement('%s','%s',"
            "'%s','%s','%s',%d);",
            sanitizeString(playerName),
            sanitizeString(compositeResearch),
            sanitizeString(element["research"]),
            sanitizeString(element["type"]),
            sanitizeString(element["description"]),
            element["order in sequence"]);

        db_exec(dbHandle, query);
        result = db_fetch(dbHandle);
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void saveCompositeResearch(int dbHandle, string playerName, 
    mapping playerData)
{
    if (member(playerData, "compositeResearch") &&
        sizeof(playerData["compositeResearch"]))
    {
        mapping data = playerData["compositeResearch"];
        foreach(string compositeResearch in m_indices(data))
        {
            string query =
                sprintf("call saveCompositeResearch('%s','%s','%s','%s','%s');",
                    sanitizeString(playerData["name"]),
                    sanitizeString(compositeResearch),
                    sanitizeString(data[compositeResearch]["alias"]),
                    sanitizeString(data[compositeResearch]["constraint"]),
                    sanitizeString(data[compositeResearch]["type"]));
            db_exec(dbHandle, query);
            mixed result = db_fetch(dbHandle);

            if (sizeof(data[compositeResearch]["elements"]))
            {
                saveCompositeResearchElements(dbHandle, playerData["name"],
                    compositeResearch, data[compositeResearch]["elements"]);
            }
        }
    }
}
