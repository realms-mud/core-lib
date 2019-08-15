//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/secure/dataServices/dataService.c";

/////////////////////////////////////////////////////////////////////////////
private nomask mapping getDomainList(int playerId, int dbHandle)
{
    mapping ret = ([]);

    string query = sprintf("select * from domains "
        "where playerid = '%d'", playerId);
    db_exec(dbHandle, query);

    mixed result;
    do
    {
        result = db_fetch(dbHandle);
        if (result)
        {
            ret[convertString(result[2])] = ([
                "id": result[1]
            ]);
        }
    } while (result);
    
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping getHenchmen(int sectionId, int dbHandle)
{
    return ([]);
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping getUnits(int sectionId, int dbHandle)
{
    return ([]);
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping getSectionDetails(int sectionId, int dbHandle)
{
    mapping ret = ([]);

    string query = sprintf("select * "
        "from `componentsView` "
        "where sectionId = '%d'", sectionId);

    db_exec(dbHandle, query);

    mixed result;
    do
    {
        result = db_fetch(dbHandle);
        if (result)
        {
            int componentId = to_int(result[1]);
            string key = convertString(result[2]);
            ret[key] = ([
                "name": convertString(result[3]),
                "maximum structure": to_int(result[4]),
                "current structure": to_int(result[5]),
                "time until repaired": to_int(result[6]),
                "materials": ([ ]),
                "henchmen": componentId,
                "units": componentId
            ]);

            if (result[7])
            {
                ret[key]["materials"]["metal"] = convertString(result[7]);
            }
            if (result[8])
            {
                ret[key]["materials"]["stone"] = convertString(result[8]);
            }
            if (result[9])
            {
                ret[key]["materials"]["textile"] = convertString(result[9]);
            }
            if (result[10])
            {
                ret[key]["materials"]["wood"] = convertString(result[10]);
            }
        }
    } while (result);

    if (sizeof(ret))
    {
        foreach(string component in m_indices(ret))
        {
            ret[component]["henchmen"] =
                getHenchmen(ret[component]["henchmen"], dbHandle);

            ret[component]["units"] =
                getUnits(ret[component]["henchmen"], dbHandle);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping getDomainDetails(int domainId, int dbHandle)
{
    mapping ret = ([]);

    string query = sprintf("select `domainSections`.`type` AS `sectionType`, "
        "`domainSections`.`name` AS `sectionName`, "
        "`domainSections`.`constructionStart` AS `constructionStart`, "
        "`domainSections`.`completionTime` AS `completionTime`, "
        "`domainSections`.`timeLeft` AS `timeLeft`, "
        "`domainSections`.`id` AS `sectionId`, "
        "from `domainSections` "
        "where domainId = '%d'", domainId);

    db_exec(dbHandle, query);

    mixed result;
    do
    {
        result = db_fetch(dbHandle);
        if (result)
        {
            ret[convertString(result[0])] = ([
                "name": convertString(result[1]),
                "construction start": to_int(result[2]),
                "construction completion": to_int(result[3]),
                "construction start": to_int(result[4]),
                "components": to_int(result[5])
            ]);
        }
    } while (result);

    if (sizeof(ret))
    {
        foreach(string section in m_indices(ret))
        {
            ret[section]["components"] =
                getSectionDetails(ret[section]["components"], dbHandle);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask mapping getPlayerDomains(int playerId, int dbHandle)
{
    mapping ret = getDomainList(playerId, dbHandle);

    if (sizeof(ret))
    {
        foreach(string key in m_indices(ret))
        {
            ret[key] = getDomainDetails(ret[key]["id"], dbHandle);
        }
    }

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
