//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/secure/dataServices/dataService.c";

/////////////////////////////////////////////////////////////////////////////
protected nomask mapping getBasicPlayerData(string name, int dbHandle)
{
    mapping ret = ([]);

    string query = sprintf("select * from basicPlayerData "
        "where name = '%s'", sanitizeString(name));
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
        ret["location"] = result[29];
        ret["availableAttributePoints"] = to_int(result[30]);
        ret["availableSkillPoints"] = to_int(result[31]);
        ret["availableResearchPoints"] = to_int(result[32]);
        ret["unassignedExperience"] = to_int(result[33]);
        ret["money"] = to_int(result[34]);
        ret["playerId"] = to_int(result[35]);
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int saveBasicPlayerData(int dbHandle, mapping playerData)
{
    string query = sprintf("select saveBasicPlayerInformation("
        "'%s','%s',%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,'%s',%d);",
        sanitizeString(playerData["name"]),
        sanitizeString(playerData["race"]),
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
        playerData["unassignedExperience"],
        playerData["location"],
        playerData["money"]);

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
protected nomask void saveBiologicalData(int dbHandle, int playerId, mapping playerData)
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
protected nomask void saveCombatData(int dbHandle, int playerId, mapping playerData)
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
