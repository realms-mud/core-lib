//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/secure/dataServices/dataService.c";

/////////////////////////////////////////////////////////////////////////////
private nomask mapping getDomainList(string name, int dbHandle)
{
    mapping ret = ([]);

    string query = sprintf("select domains.* from domains "
        "inner join players on domains.playerId = players.id "
        "where players.name = '%s'", name);
    db_exec(dbHandle, query);

    mixed result;
    do
    {
        result = db_fetch(dbHandle);
        if (result)
        {
            ret[convertString(result[2])] = ([
                "id": to_int(result[0])
            ]);
        }
    } while (result);
    
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping getHenchmanSkills(int henchmanId, int dbHandle)
{
    mapping ret = ([]);

    string query = sprintf("select * "
        "from `domainHenchmanSkills` "
        "where henchmanId = '%d'", henchmanId);

    db_exec(dbHandle, query);

    mixed result;
    do
    {
        result = db_fetch(dbHandle);
        if (result)
        {
            ret[convertString(result[2])] = to_int(result[3]);
        }
    } while (result);

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string *getHenchmanTraits(int henchmanId, int dbHandle)
{
    string *ret = ({});

    string query = sprintf("select * "
        "from `domainHenchmanTraits` "
        "where henchmanId = '%d'", henchmanId);

    db_exec(dbHandle, query);

    mixed result;
    do
    {
        result = db_fetch(dbHandle);
        if (result)
        {
            ret += ({ convertString(result[2]) });
        }
    } while (result);

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping getHenchmen(int componentId, int dbHandle)
{
    mapping ret = ([]);

    string query = sprintf("select * "
        "from `domainHenchmen` "
        "left outer join `domainUnits` on "
        "`domainHenchmen`.`id` = `domainUnits`.`leaderId`"
        "where originatingLocationId = '%d'", componentId);

    db_exec(dbHandle, query);

    mixed result;
    do
    {
        result = db_fetch(dbHandle);

        if (result)
        {
            string key = sprintf("%d - %s",
                to_int(result[0]), convertString(result[3]));

            ret[key] = ([
                "id": to_int(result[0]),
                "originating location": to_int(result[1]),
                "current location": convertString(result[2]),
                "name": convertString(result[3]),
                "gender": to_int(result[4]),
                "race": convertString(result[5]),
                "age": to_int(result[6]),
                "activity": convertString(result[7]),
                "persona": convertString(result[8]),
                "level": to_int(result[9]),
                "experience": to_int(result[10]),
                "opinion": to_int(result[11]),
                "opinion type": convertString(result[12])
            ]);

            if (ret[key]["activity"] == "leading troops")
            {
                ret[key]["unit id"] = to_int(result[13]);

                if (!ret[key]["unit id"])
                {
                    m_delete(ret[key], "unit id");
                    ret[key]["activity"] = "idle";
                }
            }
        }
    } while (result);

    if (sizeof(ret))
    {
        foreach(string henchman in m_indices(ret))
        {
            ret[henchman]["skills"] =
                getHenchmanSkills(ret[henchman]["id"], dbHandle);
            ret[henchman]["traits"] =
                getHenchmanTraits(ret[henchman]["id"], dbHandle);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping getUnits(int componentId, int dbHandle)
{
    mapping ret = ([]);

    string query = sprintf("select * "
        "from `domainUnits` "
        "where locationId = '%d'", componentId);

    db_exec(dbHandle, query);

    mixed result;
    do
    {
        result = db_fetch(dbHandle);
        if (result)
        {
            string key = sprintf("%d - %s",
                to_int(result[0]), convertString(result[2]));

            ret[key] = ([
                "id": to_int(result[0]),
                "type": convertString(result[1]),
                "name": convertString(result[2]),
                "morale": to_int(result[3]),
                "unit capacity": to_int(result[4]),
                "current unit size": to_int(result[5]),
                "movement": to_int(result[6]),
                "skill": to_int(result[7]),
                "current location": convertString(result[9]),
            ]);

            if (to_int(result[10]))
            {
                ret[key]["leader ID"] = to_int(result[10]);
            }
            if (to_int(result[11]))
            {
                ret[key]["led by owner"] = to_int(result[11]);
            }
        }
    } while (result);

    if (sizeof(ret))
    {
        foreach(string unit in m_indices(ret))
        {
            query = sprintf("select name "
                "from `domainUnitTraits` "
                "where unitId = '%d'", ret[unit]["id"]);

            db_exec(dbHandle, query);
            string *traits = ({});
            do
            {
                result = db_fetch(dbHandle);
                if (result)
                {
                    traits += ({ convertString(result[0]) });
                }
            } while (result);
            if (sizeof(traits))
            {
                ret[unit]["traits"] = traits;
            }
        }
    }
    return ret;
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
                getUnits(ret[component]["units"], dbHandle);
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
        "`domainSections`.`id` AS `sectionId` "
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
                "construction time left": to_int(result[4]),
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
protected nomask mapping getPlayerDomainData(string player, int dbHandle)
{
    mapping ret = getDomainList(player, dbHandle);

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
private nomask void saveUnitTraits(int dbHandle, int unitId,
    string *traits)
{
    if (sizeof(traits))
    {
        string query = sprintf("delete from domainUnitTraits "
            "where unitId = %d and name not in ('%s');",
            unitId, implode(traits, "','"));

        db_exec(dbHandle, query);
        mixed result = db_fetch(dbHandle);

        foreach(string trait in traits)
        {
            query = sprintf("call saveUnitTraits"
                "(%d,'%s');",
                unitId,
                sanitizeString(trait));

            db_exec(dbHandle, query);
            result = db_fetch(dbHandle);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void saveDomainUnits(int dbHandle, int componentId, 
    mapping data)
{
    if (sizeof(data))
    {
        string *units = sort_array(m_indices(data), (: $1 > $2 :));
        foreach(string unit in units)
        {
            string query = sprintf("select saveDomainUnit(%d,'%s',"
                "'%s',%d,%d,%d,%d,%d,%d,%d,'%s');",
                componentId,
                sanitizeString(data[unit]["type"]),
                sanitizeString(data[unit]["name"]),
                data[unit]["morale"],
                data[unit]["unit capacity"],
                data[unit]["current unit size"],
                data[unit]["movement"],
                data[unit]["skill"],
                data[unit]["leader ID"],
                data[unit]["led by owner"],
                sanitizeString(data[unit]["current location"]));

            db_exec(dbHandle, query);
            mixed result = db_fetch(dbHandle);

            if (result)
            {
                saveUnitTraits(dbHandle, to_int(result[0]),
                    data[unit]["traits"]);
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void saveHenchmanSkills(int dbHandle, int henchmanId,
    mapping data)
{
    if (sizeof(data))
    {
        string *skills = m_indices(data);
        foreach(string skill in skills)
        {
            string query = sprintf("call saveHenchmanSkills"
                "(%d,'%s',%d);",
                henchmanId,
                sanitizeString(skill),
                data[skill]);

            db_exec(dbHandle, query);
            mixed result = db_fetch(dbHandle);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void saveHenchmanTraits(int dbHandle, int henchmanId,
    string *traits)
{
    if (sizeof(traits))
    {
        string query = sprintf("delete from domainHenchmanTraits "
            "where henchmanId = %d and path not in ('%s');",
            henchmanId, implode(traits, "','"));

        db_exec(dbHandle, query);
        mixed result = db_fetch(dbHandle);

        foreach(string trait in traits)
        {
            query = sprintf("call saveHenchmanTraits"
                "(%d,'%s');",
                henchmanId,
                sanitizeString(trait));

            db_exec(dbHandle, query);
            result = db_fetch(dbHandle);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void saveDomainHenchmen(int dbHandle, mapping data)
{
    if (sizeof(data))
    {
        string *henchmen = sort_array(m_indices(data), (: $1 > $2 :));
        foreach(string henchman in henchmen)
        {
            string query = sprintf("select saveDomainHenchman(%d,'%s',"
                "%d,'%s',%d,'%s','%s','%s',%d,%d,%d,'%s');",
                data[henchman]["originating location"],
                sanitizeString(data[henchman]["name"]),
                data[henchman]["gender"],
                sanitizeString(data[henchman]["race"]),
                data[henchman]["age"],
                sanitizeString(data[henchman]["current location"]),
                sanitizeString(data[henchman]["activity"]),
                sanitizeString(data[henchman]["persona"]),
                data[henchman]["level"],
                data[henchman]["experience"],
                data[henchman]["opinion"],
                sanitizeString(data[henchman]["opinion type"]));

            db_exec(dbHandle, query);
            mixed result = db_fetch(dbHandle);

            if (result)
            {
                saveHenchmanSkills(dbHandle, to_int(result[0]),
                    data[henchman]["skills"]);

                saveHenchmanTraits(dbHandle, to_int(result[0]),
                    data[henchman]["traits"]);
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void saveDomainComponentMaterials(int dbHandle, int componentId,
    mapping data)
{
    if (sizeof(data))
    {
        string *materials = m_indices(data);
        foreach(string material in materials)
        {
            string query = sprintf("call saveDomainComponentMaterials"
                "(%d,'%s','%s');",
                componentId,
                sanitizeString(material),
                sanitizeString(data[material]));

            db_exec(dbHandle, query);
            mixed result = db_fetch(dbHandle);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void saveDomainComponents(int dbHandle, int sectionId, mapping data)
{
    if (sizeof(data))
    {
        string *components = m_indices(data);
        foreach(string component in components)
        {
            string query = sprintf("select saveDomainComponent(%d,'%s',"
                "'%s',%d,%d,%d);",
                sectionId,
                sanitizeString(component),
                sanitizeString(data[component]["name"]),
                data[component]["maximum structure"],
                data[component]["current structure"],
                data[component]["time until repaired"]);

            db_exec(dbHandle, query);
            mixed result = db_fetch(dbHandle);

            if (result)
            {
                saveDomainComponentMaterials(dbHandle, to_int(result[0]),
                    data[component]["materials"]);

                saveDomainHenchmen(dbHandle, data[component]["henchmen"]);

                saveDomainUnits(dbHandle, to_int(result[0]),
                    data[component]["units"]);
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void saveDomainSections(int dbHandle, int domainId, mapping data)
{
    if (sizeof(data))
    {
        string *sections = m_indices(data);
        foreach(string section in sections)
        {
            string query = sprintf("select saveDomainSection(%d,'%s',"
                "'%s',%d,%d,%d);",
                domainId,
                sanitizeString(section),
                sanitizeString(data[section]["name"]),
                data[section]["construction start"],
                data[section]["construction completion"],
                data[section]["construction time left"]);

            db_exec(dbHandle, query);
            mixed result = db_fetch(dbHandle);

            if (result)
            {
                saveDomainComponents(dbHandle, to_int(result[0]),
                    data[section]["components"]);
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void savePlayerDomainData(int dbHandle, string player, 
    mapping playerData)
{
    if (member(playerData, "domains") && sizeof(playerData["domains"]))
    {
        string *domains = m_indices(playerData["domains"]);
        foreach(string domain in domains)
        {
            string query = sprintf("select savePlayerDomain('%s','%s');",
                player, sanitizeString(domain));

            db_exec(dbHandle, query);
            mixed result = db_fetch(dbHandle);

            if (result && result[0])
            {
                saveDomainSections(dbHandle, to_int(result[0]), 
                    playerData["domains"][domain]);
            }
        }
    }
}
