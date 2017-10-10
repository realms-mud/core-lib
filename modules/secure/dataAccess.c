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
virtual inherit "/lib/modules/secure/dataServices/inventoryDataService.c";
virtual inherit "/lib/modules/secure/dataServices/factionsDataService.c";
virtual inherit "/lib/modules/secure/dataServices/combatStatisticsDataService.c";
virtual inherit "/lib/modules/secure/dataServices/wizardDataService.c";
virtual inherit "/lib/modules/secure/dataServices/conversationsDataService.c";

/////////////////////////////////////////////////////////////////////////////
private nomask int connect()
{
    return db_connect(RealmsDatabase());
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getPlayerData(string name)
{
    mapping data = (["name":name]);

    if (canAccessDatabase(previous_object()))
    {
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
            data += getInventory(data["playerId"], dbHandle);
            data += getFactions(data["playerId"], dbHandle);
            data += getWizardLevel(data["playerId"], dbHandle);
        }

        db_close(dbHandle);
    }
    else
    {
        write("This is where a stern message about trying to circumvent "
            "security should probably go: " + program_name(previous_object()) + "\n");
    }
    return data + ([]);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void savePlayerData(mapping playerData)
{
    if (canAccessDatabase(previous_object()))
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
            saveInventory(dbHandle, playerId, playerData);
            saveFactions(dbHandle, playerId, playerData);
            saveWizardLevel(dbHandle, playerId, playerData);
            db_close(dbHandle);
        }
    }
    else
    {
        write("This is where a stern message about trying to circumvent "
            "security should probably go: " + program_name(previous_object()) + "\n");
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
