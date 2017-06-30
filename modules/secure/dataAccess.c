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
    return db_connect(RealmsDatabase());
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

    string query = sprintf("select * from materialAttributeItems "
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