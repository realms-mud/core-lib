//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/secure/dataServices/dataService.c";
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
virtual inherit "/lib/modules/secure/dataServices/stateDataService.c";
virtual inherit "/lib/modules/secure/dataServices/settingsDataService.c";
virtual inherit "/lib/modules/secure/dataServices/domainsDataService.c";

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getPlayerData(string name)
{
    mapping data = (["name": name]);
    if (name == "guest")
    {
        data["is guest"] = 1;
        data["location"] = StartLocation();
    }
    else
    {
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
                data += getCompositeResearch(data["playerId"], dbHandle);
                data += getSkills(data["playerId"], dbHandle);
                data += getTraits(data["playerId"], dbHandle);
                data += getTemporaryTraits(data["playerId"], dbHandle);
                data += getFactions(data["playerId"], dbHandle);
                data += getWizardLevel(data["playerId"], dbHandle);
                data += getPlayerSettings(dbHandle, name);
                // data += getPlayerDomains(data["playerId"], dbHandle);
                data += getInventory(data["playerId"], dbHandle);
            }

            disconnect(dbHandle);
        }
        else
        {
            write("This is where a stern message about trying to circumvent "
                "security should probably go: " + program_name(previous_object()) + "\n");
        }
    }
    return data + ([]);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void savePlayerData(mapping playerData)
{
    if (canAccessDatabase(previous_object()))
    {
        if (member(playerData, "name") && (playerData["name"] != "") &&
            (!member(playerData, "is guest") || !playerData["is guest"]))
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
            saveCompositeResearch(dbHandle, playerId, playerData);
            saveSkills(dbHandle, playerId, playerData);
            saveTraits(dbHandle, playerId, playerData);
            saveFactions(dbHandle, playerId, playerData);
            saveWizardLevel(dbHandle, playerId, playerData);
            saveSettings(dbHandle, playerData);
//            saveDomains(dbHandle, playerId, playerData);
            saveInventory(dbHandle, playerId, playerData);
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
private nomask void checkInitialization(string name)
{
    string query = "select count(id) from users";

    int dbHandle = connect();
    db_exec(dbHandle, query);

    mixed result = db_fetch(dbHandle);

    if (result)
    {
        if (to_int(result[0]) <= 1)
        {
            query = sprintf("insert into players (name) values ('%s');", name);
            db_exec(dbHandle, query);
            result = db_fetch(dbHandle);

            query = sprintf("insert into wizards (playerId, typeId) "
                "values ((select id from players where name = '%s'), "
                "(select id from wizardTypes where type = 'owner'));", name);
            db_exec(dbHandle, query);
            result = db_fetch(dbHandle);

            printf(format("\n\n\x1b0;37;1mNOTICE: Since you are the first "
                "character to log on to this MUD, the owner account has "
                "been set up with your information. After you have gone "
                "through the player creation process, you must log out and "
                "log back in to use your wizardly powers.\x1b[0m\n\n", 78));
        }
    }
    disconnect(dbHandle);
}

/////////////////////////////////////////////////////////////////////////////
public nomask string playerType(string name)
{
    string ret = "player";

    checkInitialization(name);
    string query = sprintf("select wizardTypes.type from wizards "
        "inner join wizardTypes on wizards.typeId = wizardTypes.id "
        "inner join players on wizards.playerid = players.id "
        "where players.name = '%s'", sanitizeString(name));

    int dbHandle = connect();

    db_exec(dbHandle, query);

    mixed result = db_fetch(dbHandle);
    disconnect(dbHandle);

    if (result)
    {
        ret = result[0];
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int playerExists(string name)
{
    int ret = 0;

    string query = sprintf("select players.id from players "
        "where players.name = '%s'", sanitizeString(name));

    int dbHandle = connect();

    db_exec(dbHandle, query);

    mixed result = db_fetch(dbHandle);
    disconnect(dbHandle);

    if (result)
    {
        ret = 1;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public void savePlayerDomains(string player, mapping data)
{
    int dbHandle = connect();
    savePlayerDomainData(dbHandle, player, data);
    disconnect(dbHandle);
}

/////////////////////////////////////////////////////////////////////////////
public mapping getPlayerDomains(string player)
{
    int dbHandle = connect();
    mapping ret = getPlayerDomainData(player, dbHandle);
    disconnect(dbHandle);

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public void removeCompositeResearch(string player, string name,
    string constraint)
{
    int dbHandle = connect();
    removeCompositeResearchData(dbHandle, player, name, constraint);
    disconnect(dbHandle);
}
