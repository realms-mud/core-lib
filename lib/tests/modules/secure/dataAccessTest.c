//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object DataAccess;
object Database;

/////////////////////////////////////////////////////////////////////////////
private mapping SetupDomain()
{
    return ([
        "domains":([
            "argalach castle":([
                "keep":([
                    "name": "stone keep",
                    "construction start": 1,
                    "construction completion": 5,
                    "construction time left": 4,
                    "components": ([
                        "main stone keep":([
                            "name": "Large Square Stone Keep",
                            "maximum structure": 500,
                            "current structure": 500,
                            "time until repaired": 0,
                            "materials": ([ 
                                "metal": "iron",
                                "stone" : "limestone",
                                "textile" : "linen",
                                "wood" : "pine",
                            ]),
                            "henchmen": ([
                                "2 - Lana the Lascivious": ([
                                    "id": 2,
                                    "originating location": 3,
                                    "name": "Lana the Lascivious",
                                    "age": 21,
                                    "gender": 1,
                                    "race": "maegenstryd",
                                    "current location": "/some/path/to/room.c",
                                    "activity": "leading troops",
                                    "unit id": 3,
                                    "persona": "swordsman",
                                    "level": 6,
                                    "experience": 222,
                                    "opinion": 94,
                                    "opinion type": "romance",
                                    "skills": ([
                                        "diplomacy": 10,
                                        "long sword": 16,
                                        "metal crafting": 12,
                                    ]),
                                    "traits": ({
                                        "/lib/instances/traits/domains/apprentice-blacksmith.c",
                                        "/lib/instances/traits/personality/lascivious.c"
                                    })
                                ]),
                                "3 - Tantor the Unclean": ([
                                    "id": 3,
                                    "originating location": 3,
                                    "name": "Tantor the Unclean",
                                    "age": 26,
                                    "gender": 1,
                                    "race": "maegenstryd",
                                    "current location": "/some/path/to/room.c",
                                    "activity": "building",
                                    "persona": "swordsman",
                                    "level": 16,
                                    "experience": 992,
                                    "opinion": 86,
                                    "opinion type": "friendly",
                                    "skills": ([
                                        "engineering": 10,
                                        "long sword": 16,
                                        "metal crafting": 12,
                                        "stonemasonry": 14,
                                    ]),
                                    "traits": ({
                                        "/lib/instances/traits/domains/journeyman-stonemason.c",
                                        "/lib/instances/traits/personality/boorish.c"
                                    })
                                ]),
                            ]),
                            "units": ([
                                "3 - Weasel Brigade":([
                                    "id": 3,
                                    "type": "archer",
                                    "name": "Weasel Brigade",
                                    "morale": 1,
                                    "unit capacity": 50,
                                    "current unit size": 46,
                                    "movement": 3,
                                    "skill": 1,
                                    "current location": "/path/to/nowhere.c",
                                    "leader ID": 2,
                                    "traits": ({ "magic armor", "afraid" })
                                ])
                            ]),
                        ]),
                        "central stone tower": ([
                            "name":"Stone Bergfriede",
                            "maximum structure": 400,
                            "current structure": 400,
                            "time until repaired": 0,
                            "materials": ([ 
                                "metal": "bronze",
                                "stone" : "granite",
                                "textile" : "silk",
                                "wood" : "oak",
                            ]),
                            "henchmen": ([
                            ]),
                            "units": ([
                            ]),
                        ]),
                        "stone battlement": ([
                            "name":"Enbrasured Stone Parapet",
                            "maximum structure": 200,
                            "current structure": 200,
                            "time until repaired": 0,
                            "materials": ([ 
                                "metal": "iron",
                                "stone" : "limestone",
                                "textile" : "linen",
                                "wood" : "pine",
                            ]),
                            "henchmen": ([
                                "1 - Vaire the Vole-Hearted": ([
                                    "id": 1,
                                    "originating location": 1,
                                    "name": "Vaire the Vole-Hearted",
                                    "age": 22,
                                    "gender": 2,
                                    "race": "high elf",
                                    "current location": "/some/path/to/room.c",
                                    "activity": "building",
                                    "persona": "swordsman",
                                    "level": 16,
                                    "experience": 992,
                                    "opinion": 86,
                                    "opinion type": "romance",
                                    "skills": ([
                                        "long sword": 16,
                                        "engineering": 10,
                                        "metal crafting": 12,
                                        "stonemasonry": 14,
                                    ]),
                                    "traits": ({
                                        "/lib/instances/traits/personality/insecure.c",
                                        "/lib/instances/traits/personality/coward.c"
                                    })
                                ]),
                            ]),
                            "units": ([
                                "1 - Llama Brigade":([
                                    "id": 1,
                                    "type": "swordsman",
                                    "name": "Llama Brigade",
                                    "morale": 5,
                                    "unit capacity": 75,
                                    "current unit size": 62,
                                    "movement": 4,
                                    "skill": 3,
                                    "current location": "/path/to/nowhere.c",
                                    "led by owner": 1
                                ]),
                                "2 - Grebe Brigade":([
                                    "id": 2,
                                    "type": "axeman",
                                    "name": "Grebe Brigade",
                                    "morale": 4,
                                    "unit capacity": 25,
                                    "current unit size": 22,
                                    "movement": 5,
                                    "skill": 5,
                                    "current location": "/path/to/nowhere.c"
                                ]),
                            ]),
                        ]),
                    ]),
                ]),
            ]),
        ]),
    ]);
}

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    ignoreList += ({ "SetupDomain" });

    setRestoreCaller(this_object());
    Database = clone_object("/lib/tests/modules/secure/fakeDatabase.c");
    Database.PrepDatabase();

    object dataAccess = 
        clone_object("/lib/modules/secure/dataServices/authenticationDataService.c");
    dataAccess.saveUser("maeglin", "maeglin", "127.0.0.1");
    dataAccess.saveUser("gorthaur", "gorthaur", "127.0.0.1");
    dataAccess.saveUser("earl", "earl", "127.0.0.1");
    destruct(dataAccess);

    dataAccess = clone_object("/lib/modules/secure/dataAccess.c");
    dataAccess.savePlayerData(Database.GetWizardOfLevel("owner", "maeglin"));
    destruct(dataAccess);
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    DataAccess = clone_object("/lib/modules/secure/dataAccess.c");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(DataAccess);
}

/////////////////////////////////////////////////////////////////////////////
void DatabaseVersionIsCorrect()
{
    ExpectEq(DatabaseVersion(), DatabaseVersionFromDatabase());
}

/////////////////////////////////////////////////////////////////////////////
void PlayerTypeReturnsCorrectWizardValueFromDatabase()
{
    ExpectEq("owner", DataAccess.playerType("maeglin"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerTypeReturnsPlayerWhenNotWizard()
{
    ExpectEq("player", DataAccess.playerType("gorthaur"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerTypeReturnsPlayerWhenNotInDatabase()
{
    ExpectEq("player", DataAccess.playerType("fake player"));
}

/////////////////////////////////////////////////////////////////////////////
void GetPlayerDataReturnsDataFromDatabase()
{
    mapping expected = Database.Gorthaur();

    DataAccess.savePlayerData(expected);
    mapping result = DataAccess.getPlayerData("gorthaur");

    // whenCreated uses "now()" and it's not feasible (without adding a test-only hack)
    // to add a static, testable value. For now, simply test its existance and
    // remove it before testing the rest of the mapping. Same for LastLogin.
    ExpectTrue(member(result, "whenCreated"));
    ExpectTrue(member(result, "LastLogin"));
    m_delete(result, "whenCreated");
    m_delete(result, "LastLogin");

    ExpectEq(expected, result);
}

/////////////////////////////////////////////////////////////////////////////
void GetPlayerDataForGuestReturnsSimpleMap()
{
    mapping expected = ([ 
        "name": "guest", 
        "is guest": 1,
        "location": StartLocation() ]);

    mapping result = DataAccess.getPlayerData("guest");

    ExpectEq(expected, result);
}

/////////////////////////////////////////////////////////////////////////////
void GetPlayerDataForWizardReturnsDataFromDatabase()
{
    mapping expected = Database.GetWizardOfLevel("creator");

    DataAccess.savePlayerData(expected);
    mapping result = DataAccess.getPlayerData("earl");

    // whenCreated uses "now()" and it's not feasible (without adding a test-only hack)
    // to add a static, testable value. For now, simply test its existance and
    // remove it before testing the rest of the mapping. Same for LastLogin.
    ExpectTrue(member(result, "whenCreated"));
    ExpectTrue(member(result, "LastLogin"));
    m_delete(result, "whenCreated");
    m_delete(result, "LastLogin");

    ExpectEq(expected, result);
}

/////////////////////////////////////////////////////////////////////////////
void CanSaveDataMultipleTimes()
{
    DataAccess.savePlayerData(Database.Gorthaur());
    mapping result = DataAccess.getPlayerData("gorthaur");
    ExpectEq(100, result["hitPoints"]);

    result["hitPoints"] = 120;
    DataAccess.savePlayerData(result);

    result = DataAccess.getPlayerData("gorthaur");
    ExpectEq(120, result["hitPoints"]);
}

/////////////////////////////////////////////////////////////////////////////
void SavingSameCombatStatisticMultipleTimesIncrementsTimesKilled()
{
    DataAccess.saveCombatStatistics("gorthaur",
        "/lib/realizations/monster.c#bob", "bob", 10);

    int dbHandle = db_connect(RealmsDatabase());
    db_exec(dbHandle, "select * from combatStatistics");
    mixed result = db_fetch(dbHandle);
    while(db_fetch(dbHandle));

    db_close(dbHandle);
    ExpectEq(1, result[0], "stat id");
    ExpectEq("bob", result[1], "name");
    ExpectEq(10, result[2], "level");
    ExpectEq("/lib/realizations/monster.c#bob", result[3], "key");
    ExpectEq(1, result[4], "times killed");
    ExpectEq(2, result[5], "player id");
    ExpectEq(1, result[6], "is nemesis");
    ExpectEq(1, result[7], "is best kill");

    DataAccess.saveCombatStatistics("gorthaur",
        "/lib/realizations/monster.c#bob", "bob", 10);

    dbHandle = db_connect(RealmsDatabase());
    db_exec(dbHandle, "select * from combatStatistics");
    result = db_fetch(dbHandle);
    while(db_fetch(dbHandle));
    db_close(dbHandle);

    ExpectEq(2, result[4], "times killed has incremented");
}

/////////////////////////////////////////////////////////////////////////////
void SavingUpdatesNemesisToMostFrequentKillWithHighestLevel()
{
    DataAccess.saveCombatStatistics("gorthaur",
        "/lib/realizations/monster.c#fred", "fred", 12);

    int dbHandle = db_connect(RealmsDatabase());
    db_exec(dbHandle, "select * from combatStatistics");
    mixed result = db_fetch(dbHandle);
    ExpectEq("bob", result[1], "name");
    ExpectEq(1, result[6], "is nemesis");

    result = db_fetch(dbHandle);
    ExpectEq("fred", result[1], "name");
    ExpectEq(0, result[6], "is nemesis");

    while(db_fetch(dbHandle));
    db_close(dbHandle);

    DataAccess.saveCombatStatistics("gorthaur",
        "/lib/realizations/monster.c#fred", "fred", 12);

    dbHandle = db_connect(RealmsDatabase());
    db_exec(dbHandle, "select * from combatStatistics");
    result = db_fetch(dbHandle);
    ExpectEq("bob", result[1], "name");
    ExpectEq(0, result[6], "is nemesis");

    result = db_fetch(dbHandle);
    ExpectEq("fred", result[1], "name");
    ExpectEq(1, result[6], "is nemesis");

    while(db_fetch(dbHandle));
    db_close(dbHandle);
}

/////////////////////////////////////////////////////////////////////////////
void SavingUpdatesBestKillToKillWithHighestLevel()
{
    int dbHandle = db_connect(RealmsDatabase());
    db_exec(dbHandle, "select * from combatStatistics");
    db_fetch(dbHandle);
    mixed result = db_fetch(dbHandle);
    ExpectEq("fred", result[1], "name");
    ExpectEq(1, result[7], "is best kill");
    while(db_fetch(dbHandle));
    db_close(dbHandle);

    DataAccess.saveCombatStatistics("gorthaur",
        "/lib/realizations/monster.c#dwight", "dwight", 14);

    dbHandle = db_connect(RealmsDatabase());
    db_exec(dbHandle, "select * from combatStatistics");
    db_fetch(dbHandle);
    result = db_fetch(dbHandle);
    ExpectEq("fred", result[1], "name");
    ExpectEq(0, result[7], "is best kill");

    result = db_fetch(dbHandle);
    ExpectEq("dwight", result[1], "name");
    ExpectEq(1, result[7], "is best kill");

    while(db_fetch(dbHandle));
    db_close(dbHandle);
}

/////////////////////////////////////////////////////////////////////////////
void BestKillMeetsLevelReturnsTrueWhenLevelMet()
{
    ExpectTrue(DataAccess.bestKillMeetsLevel("gorthaur", 10));
}

/////////////////////////////////////////////////////////////////////////////
void BestKillMeetsLevelReturnsFalseWhenLevelNotMet()
{
    ExpectFalse(DataAccess.bestKillMeetsLevel("gorthaur", 20));
}

/////////////////////////////////////////////////////////////////////////////
void RacialKillsMeetCountCorrectlyReturns()
{
    ExpectFalse(DataAccess.racialKillsMeetCount("gorthaur", "orc", 2));
    DataAccess.saveCombatStatisticsForRace("gorthaur", "orc");

    ExpectFalse(DataAccess.racialKillsMeetCount("gorthaur", "orc", 2));
    DataAccess.saveCombatStatisticsForRace("gorthaur", "orc");

    ExpectTrue(DataAccess.racialKillsMeetCount("gorthaur", "orc", 2));
}

/////////////////////////////////////////////////////////////////////////////
void GetBestKillReturnsBestKill()
{
    DataAccess.saveCombatStatistics("gorthaur",
        "/lib/realizations/monster.c#dwight", "dwight", 14);

    ExpectEq(([ "name": "dwight",
                "level": 14,
                "key": "/lib/realizations/monster.c#dwight",
                "times killed": 2 ]),
        DataAccess.getBestKill("gorthaur"));
}

/////////////////////////////////////////////////////////////////////////////
void GetNemesisKillReturnsNemesis()
{
    DataAccess.saveCombatStatistics("gorthaur",
        "/lib/realizations/monster.c#fred", "fred", 12);

    ExpectEq((["name":"fred",
        "level" : 12,
        "key" : "/lib/realizations/monster.c#fred",
        "times killed" : 3]),
        DataAccess.getNemesis("gorthaur"));
}

/////////////////////////////////////////////////////////////////////////////
void GetOpinionOfCharacterReturnsCorrectValue()
{
    DataAccess.setOpinionOfCharacter("gorthaur",
        "/lib/realizations/monster.c#fred", 6);

    ExpectEq(6, DataAccess.getOpinionOfCharacter("gorthaur", "/lib/realizations/monster.c#fred"));
}

/////////////////////////////////////////////////////////////////////////////
void GetCharacterStateReturnsCorrectValue()
{
    DataAccess.setCharacterState("gorthaur",
        "/lib/realizations/monster.c#fred", "first state");

    ExpectEq("first state", DataAccess.getCharacterState("gorthaur", "/lib/realizations/monster.c#fred"));
}

/////////////////////////////////////////////////////////////////////////////
void GetPlayerDomainsReturnsCorrectValue()
{
    mapping data = SetupDomain();

    DataAccess.savePlayerDomains("gorthaur", data);
    DataAccess.savePlayerDomains("gorthaur", data);

    mapping loadedData = DataAccess.getPlayerDomains("gorthaur");

    ExpectEq(data["domains"], loadedData);
}

/////////////////////////////////////////////////////////////////////////////
void UpdatesToHenchmanTraitsSavedCorrectly()
{
    mapping data = SetupDomain();

    DataAccess.savePlayerDomains("gorthaur", data);
    mapping loadedData = DataAccess.getPlayerDomains("gorthaur");

    ExpectEq(data["domains"]["argalach castle"]["keep"]["components"]["main stone keep"]["henchmen"],
        loadedData["argalach castle"]["keep"]["components"]["main stone keep"]["henchmen"]);

    data["domains"]["argalach castle"]["keep"]["components"]["main stone keep"]["henchmen"]
        ["3 - Tantor the Unclean"]["traits"] = ({
            "/lib/instances/traits/domains/master-stonemason.c",
            "/lib/instances/traits/personality/boorish.c",
            "/lib/instances/traits/personality/drunkard.c"
            });

    DataAccess.savePlayerDomains("gorthaur", data);
    loadedData = DataAccess.getPlayerDomains("gorthaur");

    ExpectEq(data["domains"]["argalach castle"]["keep"]["components"]["main stone keep"]["henchmen"],
        loadedData["argalach castle"]["keep"]["components"]["main stone keep"]["henchmen"]);
}

/////////////////////////////////////////////////////////////////////////////
void HenchmanResetsLeadingTroopsToIdleWhenIdNotSet()
{
    mapping data = SetupDomain();

    data["domains"]["argalach castle"]["keep"]["components"]["main stone keep"]["henchmen"]
        ["3 - Tantor the Unclean"]["activity"] = "leading troops";

    DataAccess.savePlayerDomains("gorthaur", data);
    mapping loadedData = DataAccess.getPlayerDomains("gorthaur");

    ExpectEq("idle", loadedData["argalach castle"]["keep"]["components"]
        ["main stone keep"]["henchmen"]["3 - Tantor the Unclean"]["activity"]);
}

/////////////////////////////////////////////////////////////////////////////
void UpdatesToUnitTraitsSavedCorrectly()
{
    mapping data = SetupDomain();

    DataAccess.savePlayerDomains("gorthaur", data);
    mapping loadedData = DataAccess.getPlayerDomains("gorthaur");

    ExpectEq(data["domains"]["argalach castle"]["keep"]["components"]["main stone keep"]["units"],
        loadedData["argalach castle"]["keep"]["components"]["main stone keep"]["units"]);

    data["domains"]["argalach castle"]["keep"]["components"]["main stone keep"]["units"]
        ["3 - Weasel Brigade"]["traits"] = ({
            "magic armor",
            "confident",
            "well-rested"
            });

    DataAccess.savePlayerDomains("gorthaur", data);
    loadedData = DataAccess.getPlayerDomains("gorthaur");

    ExpectEq(data["domains"]["argalach castle"]["keep"]["components"]["main stone keep"]["units"],
        loadedData["argalach castle"]["keep"]["components"]["main stone keep"]["units"]);
}
