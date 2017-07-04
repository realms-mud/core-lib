//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

/////////////////////////////////////////////////////////////////////////////
private nomask void purgeCursors(int handle)
{
    while (db_fetch(handle));
}

/////////////////////////////////////////////////////////////////////////////
private nomask int connect()
{
    return db_connect("TestDB");
}

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
private mapping getBasicPlayerData(string name, int dbHandle)
{
    mapping ret = ([]);

    string query = sprintf("select * from basicPlayerData "
                           "where name = '%s'", db_conv_string(name));
    db_exec(dbHandle, query);
    mixed result = db_fetch(dbHandle);

    // Yuck... they seriously didn't implement DB support better?
    // Task 59 was created in the Realms Driver project to improve this.
    // In the meantime, let me reiterate: Yuck.
    if (result)
    {
        ret["race"] = convertString(result[1]);
        ret["age"] = to_int(result[2]);
        ret["gender"] = to_int(result[3]);
        ret["ghost"] = to_int(result[4]);
        ret["strength"] = to_int(result[5]);
        ret["intelligence"] = to_int(result[6]);
        ret["dexterity"] = to_int(result[7]);
        ret["wisdom"] = to_int(result[8]);
        ret["constitution"] = to_int(result[9]);
        ret["charisma"] = to_int(result[10]);
        ret["invisible"] = to_int(result[11]);
        ret["intoxicated"] = to_int(result[12]);
        ret["stuffed"] = to_int(result[13]);
        ret["drugged"] = to_int(result[14]);
        ret["soaked"] = to_int(result[15]);
        ret["headache"] = to_int(result[16]);
        ret["hitPoints"] = to_int(result[17]);
        ret["maxHitPoints"] = to_int(result[18]);
        ret["spellPoints"] = to_int(result[19]);
        ret["maxSpellPoints"] = to_int(result[20]);
        ret["staminaPoints"] = to_int(result[21]);
        ret["maxStaminaPoints"] = to_int(result[22]);
        ret["wimpy"] = to_int(result[23]);
        ret["onKillList"] = to_int(result[24]);
        ret["timeToHealHP"] = to_int(result[25]);
        ret["timeToHealSP"] = to_int(result[26]);
        ret["timeToHealST"] = to_int(result[27]);
        ret["whenCreated"] = result[28];
        ret["availableAttributePoints"] = to_int(result[29]);
        ret["availableSkillPoints"] = to_int(result[30]);
        ret["availableResearchPoints"] = to_int(result[31]);
        ret["unassignedExperience"] = to_int(result[32]);
        ret["playerId"] = to_int(result[33]);
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private mapping getMaterialAttributes(int playerId, int dbHandle)
{
    mapping ret = ([ ]);

    string query = sprintf("select * from materialAttributes "
        "where playerid = '%d'", playerId);
    db_exec(dbHandle, query);

    mixed result;

    do
    {
        result = db_fetch(dbHandle);
        if (result)
        {
            ret[result[2]] = result[3];
        }
    } while (result);

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private mapping getGuildData(int playerId, int dbHandle)
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
private mapping getQuestData(int playerId, int dbHandle)
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
private mapping getResearch(int playerId, int dbHandle)
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
private mapping getResearchChoices(int playerId, int dbHandle)
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
private mapping getOpenResearchTrees(int playerId, int dbHandle)
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
private mapping getSkills(int playerId, int dbHandle)
{
    mapping ret = (["skills": ([]) ]);

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
private mapping getTraits(int playerId, int dbHandle)
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
                "name": convertString(result[2]),
                "added": to_int(result[3])
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
private mapping getTemporaryTraits(int playerId, int dbHandle)
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
public nomask mapping getPlayerData(string name)
{
    mapping data = (["name":name]);

    int dbHandle = connect();

    data += getBasicPlayerData(name, dbHandle);

    if (member(data, "playerId"))
    {
        data += getGuildData(data["playerId"], dbHandle);
        data += getMaterialAttributes(data["playerId"], dbHandle);
        data += getQuestData(data["playerId"], dbHandle);
        data += getResearch(data["playerId"], dbHandle);
        data += getResearchChoices(data["playerId"], dbHandle);
        data += getOpenResearchTrees(data["playerId"], dbHandle);
        data += getSkills(data["playerId"], dbHandle);
        data += getTraits(data["playerId"], dbHandle);
        data += getTemporaryTraits(data["playerId"], dbHandle);
    }

    db_close(dbHandle);
    return data + ([]);
}

/////////////////////////////////////////////////////////////////////////////
public nomask string playerType(string name)
{
    string ret = "player";

    string query = sprintf("select wizardTypes.type from wizards "
        "inner join wizardTypes on wizards.typeId = wizardTypes.id "
        "inner join players on wizards.playerid = players.id "
        "where players.name = '%s'", db_conv_string(name));

    int dbHandle = connect();

    db_exec(dbHandle, query);

    mixed result = db_fetch(dbHandle);
    db_close(dbHandle);

    if (result)
    {
        ret = result[0];
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int saveInventoryItems(int playerId, string itemPath, string data, int equipped)
{
    string query = sprintf("insert into inventory "
        "(playerid,filename,data,isEquipped) "
        "values ('%d', '%s', '%s', '%d')", 
        playerId, 
        db_conv_string(itemPath),
        db_conv_string(data), 
        equipped);

    int dbHandle = connect();

    db_exec(dbHandle, query);

    mixed result = db_fetch(dbHandle);
    db_close(dbHandle);

    return 1;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void weaponStuff()
{
    string query = sprintf("select data from inventory where playerid = '2'");

    int dbHandle = connect();

    db_exec(dbHandle, query);

    mixed result = db_fetch(dbHandle);
    db_close(dbHandle);

    if (result)
    {
        write("Got a result = " + result[0]);
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask int saveBasicPlayerData(int dbHandle, mapping playerData)
{
    string query = sprintf("select saveBasicPlayerInformation("
        "'%s','%s',%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d);",
        db_conv_string(playerData["name"]),
        db_conv_string(playerData["race"]),
        playerData["age"],
        playerData["gender"],
        playerData["ghost"],
        playerData["strength"],
        playerData["intelligence"],
        playerData["dexterity"],
        playerData["wisdom"],
        playerData["constitution"],
        playerData["charisma"],
        playerData["invisible"],
        playerData["availableAttributePoints"],
        playerData["availableSkillPoints"],
        playerData["availableResearchPoints"],
        playerData["unassignedExperience"]);

    db_exec(dbHandle, query);
    mixed result = db_fetch(dbHandle);

    int ret = 0;
    if (sizeof(result))
    {
        ret = to_int(result[0]);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask void saveBiologicalData(int dbHandle, int playerId, mapping playerData)
{
    string query = sprintf("call saveBiologicalInformation("
        "%d,%d,%d,%d,%d,%d);",
        playerId,
        playerData["intoxicated"],
        playerData["stuffed"],
        playerData["drugged"],
        playerData["soaked"],
        playerData["headache"]);

    db_exec(dbHandle, query);
    mixed result = db_fetch(dbHandle);
}

/////////////////////////////////////////////////////////////////////////////
private nomask void saveCombatData(int dbHandle, int playerId, mapping playerData)
{
    string query = sprintf("call saveCombatInformation("
        "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d);",
        playerId,
        playerData["hitPoints"],
        playerData["maxHitPoints"],
        playerData["spellPoints"],
        playerData["maxSpellPoints"],
        playerData["staminaPoints"],
        playerData["maxStaminaPoints"],
        playerData["wimpy"],
        playerData["onKillList"],
        playerData["timeToHealHP"],
        playerData["timeToHealSP"],
        playerData["timeToHealST"]);

    db_exec(dbHandle, query);
    mixed result = db_fetch(dbHandle);
}

/////////////////////////////////////////////////////////////////////////////
private nomask void saveMaterialAttributes(int dbHandle, int playerId, mapping playerData)
{
    string query = sprintf("call saveMaterialAttributes("
        "%d,'%s','%s','%s','%s','%s','%s','%s','%s','%s','%s');",
        playerId,
        db_conv_string(playerData["title"]),
        db_conv_string(playerData["pretitle"]),
        db_conv_string(playerData["messageIn"]),
        db_conv_string(playerData["messageOut"]),
        db_conv_string(playerData["magicalMessageIn"]),
        db_conv_string(playerData["magicalMessageOut"]),
        db_conv_string(playerData["messageHome"]),
        db_conv_string(playerData["messageClone"]),
        db_conv_string(playerData["shortDescription"]),
        db_conv_string(playerData["longDescription"]));

    db_exec(dbHandle, query);
    mixed result = db_fetch(dbHandle);
}

/////////////////////////////////////////////////////////////////////////////
private nomask void saveGuildData(int dbHandle, int playerId, mapping playerData)
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
                db_conv_string(playerData["guilds"][guild]["title"]),
                db_conv_string(playerData["guilds"][guild]["pretitle"]),
                db_conv_string(playerData["guilds"][guild]["rank"]),
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

/////////////////////////////////////////////////////////////////////////////
private nomask void saveQuestData(int dbHandle, int playerId, mapping playerData)
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

/////////////////////////////////////////////////////////////////////////////
private nomask void saveResearch(int dbHandle, int playerId, mapping playerData)
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
private nomask void saveResearchChoices(int dbHandle, int playerId, mapping playerData)
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
private nomask void saveOpenResearchTrees(int dbHandle, int playerId, mapping playerData)
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

/////////////////////////////////////////////////////////////////////////////
private nomask void saveSkills(int dbHandle, int playerId, mapping playerData)
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

/////////////////////////////////////////////////////////////////////////////
private nomask void saveTraits(int dbHandle, int playerId, mapping playerData)
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
                db_conv_string(playerData["traits"][trait]["expire message"]||""),
                db_conv_string(playerData["traits"][trait]["triggering research"]||""));
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

/////////////////////////////////////////////////////////////////////////////
public nomask void savePlayerData(mapping playerData)
{
    if (member(playerData, "name"))
    {
        int dbHandle = connect();
        int playerId = saveBasicPlayerData(dbHandle, playerData);
        saveBiologicalData(dbHandle, playerId, playerData);
        saveCombatData(dbHandle, playerId, playerData);
        saveMaterialAttributes(dbHandle, playerId, playerData);
        saveGuildData(dbHandle, playerId, playerData);
        saveQuestData(dbHandle, playerId, playerData);
        saveResearch(dbHandle, playerId, playerData);
        saveResearchChoices(dbHandle, playerId, playerData);
        saveOpenResearchTrees(dbHandle, playerId, playerData);
        saveSkills(dbHandle, playerId, playerData);
        saveTraits(dbHandle, playerId, playerData);
        db_close(dbHandle);
    }
}