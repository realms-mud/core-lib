//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

virtual inherit "/lib/modules/secure/dataServices/basicPlayerDataService.c";
virtual inherit "/lib/modules/secure/dataServices/materialAttributesDataService.c";
virtual inherit "/lib/modules/secure/dataServices/guildDataService.c";
virtual inherit "/lib/modules/secure/dataServices/questDataService.c";
virtual inherit "/lib/modules/secure/dataServices/researchDataService.c";
virtual inherit "/lib/modules/secure/dataServices/skillsDataService.c";
virtual inherit "/lib/modules/secure/dataServices/traitsDataService.c";

/////////////////////////////////////////////////////////////////////////////
private nomask int connect()
{
    return db_connect(RealmsDatabase());
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
