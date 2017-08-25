//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object DataAccess;
object Database;

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    setRestoreCaller(this_object());
    Database = clone_object("/lib/tests/modules/secure/fakeDatabase.c");
    Database->PrepDatabase();
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
void PlayerTypeReturnsCorrectWizardValueFromDatabase()
{
    ExpectEq("owner", DataAccess->playerType("maeglin"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerTypeReturnsPlayerWhenNotWizard()
{
    ExpectEq("player", DataAccess->playerType("gorthaur"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerTypeReturnsPlayerWhenNotInDatabase()
{
    ExpectEq("player", DataAccess->playerType("fake player"));
}

/////////////////////////////////////////////////////////////////////////////
void GetPlayerDataReturnsDataFromDatabase()
{
    mapping expected = Database->Gorthaur();

    DataAccess->savePlayerData(expected);
    mapping result = DataAccess->getPlayerData("gorthaur");

    // whenCreated uses "now()" and it's not feasible (without adding a test-only hack)
    // to add a static, testable value. For now, simply test its existance and
    // remove it before testing the rest of the mapping.
    ExpectTrue(member(result, "whenCreated"));
    m_delete(result, "whenCreated");

    ExpectEq(expected, result);
}

/////////////////////////////////////////////////////////////////////////////
void CanSaveDataMultipleTimes()
{
    DataAccess->savePlayerData(Database->Gorthaur());
    mapping result = DataAccess->getPlayerData("gorthaur");
    ExpectEq(100, result["hitPoints"]);

    result["hitPoints"] = 120;
    DataAccess->savePlayerData(result);

    result = DataAccess->getPlayerData("gorthaur");
    ExpectEq(120, result["hitPoints"]);
}

/////////////////////////////////////////////////////////////////////////////
void SavingSameCombatStatisticMultipleTimesIncrementsTimesKilled()
{
    DataAccess->saveCombatStatistics("gorthaur",
        "lib/realizations/monster.c#bob", "bob", 10);

    int dbHandle = db_connect(RealmsDatabase());
    db_exec(dbHandle, "select * from combatStatistics");
    mixed result = db_fetch(dbHandle);
    db_close(dbHandle);
    ExpectEq(1, result[0], "stat id");
    ExpectEq("bob", result[1], "name");
    ExpectEq(10, result[2], "level");
    ExpectEq("lib/realizations/monster.c#bob", result[3], "key");
    ExpectEq(1, result[4], "times killed");
    ExpectEq(2, result[5], "player id");
    ExpectEq(1, result[6], "is nemesis");
    ExpectEq(1, result[7], "is best kill");

    DataAccess->saveCombatStatistics("gorthaur",
        "lib/realizations/monster.c#bob", "bob", 10);

    dbHandle = db_connect(RealmsDatabase());
    db_exec(dbHandle, "select * from combatStatistics");
    result = db_fetch(dbHandle);
    db_close(dbHandle);
    ExpectEq(2, result[4], "times killed has incremented");
}

/////////////////////////////////////////////////////////////////////////////
void SavingUpdatesNemesisToMostFrequentKillWithHighestLevel()
{
    DataAccess->saveCombatStatistics("gorthaur",
        "lib/realizations/monster.c#fred", "fred", 12);

    int dbHandle = db_connect(RealmsDatabase());
    db_exec(dbHandle, "select * from combatStatistics");
    mixed result = db_fetch(dbHandle);
    ExpectEq("bob", result[1], "name");
    ExpectEq(1, result[6], "is nemesis");

    result = db_fetch(dbHandle);
    ExpectEq("fred", result[1], "name");
    ExpectEq(0, result[6], "is nemesis");

    db_close(dbHandle);

    DataAccess->saveCombatStatistics("gorthaur",
        "lib/realizations/monster.c#fred", "fred", 12);

    dbHandle = db_connect(RealmsDatabase());
    db_exec(dbHandle, "select * from combatStatistics");
    result = db_fetch(dbHandle);
    ExpectEq("bob", result[1], "name");
    ExpectEq(0, result[6], "is nemesis");

    result = db_fetch(dbHandle);
    ExpectEq("fred", result[1], "name");
    ExpectEq(1, result[6], "is nemesis");

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
    db_close(dbHandle);

    DataAccess->saveCombatStatistics("gorthaur",
        "lib/realizations/monster.c#dwight", "dwight", 14);

    dbHandle = db_connect(RealmsDatabase());
    db_exec(dbHandle, "select * from combatStatistics");
    db_fetch(dbHandle);
    result = db_fetch(dbHandle);
    ExpectEq("fred", result[1], "name");
    ExpectEq(0, result[7], "is best kill");

    result = db_fetch(dbHandle);
    ExpectEq("dwight", result[1], "name");
    ExpectEq(1, result[7], "is best kill");

    db_close(dbHandle);
}

/////////////////////////////////////////////////////////////////////////////
void BestKillMeetsLevelReturnsTrueWhenLevelMet()
{
    ExpectTrue(DataAccess->bestKillMeetsLevel("gorthaur", 10));
}

/////////////////////////////////////////////////////////////////////////////
void BestKillMeetsLevelReturnsFalseWhenLevelNotMet()
{
    ExpectFalse(DataAccess->bestKillMeetsLevel("gorthaur", 20));
}

/////////////////////////////////////////////////////////////////////////////
void RacialKillsMeetCountCorrectlyReturns()
{
    ExpectFalse(DataAccess->racialKillsMeetCount("gorthaur", "orc", 2));
    DataAccess->saveCombatStatisticsForRace("gorthaur", "orc");

    ExpectFalse(DataAccess->racialKillsMeetCount("gorthaur", "orc", 2));
    DataAccess->saveCombatStatisticsForRace("gorthaur", "orc");

    ExpectTrue(DataAccess->racialKillsMeetCount("gorthaur", "orc", 2));
}

/////////////////////////////////////////////////////////////////////////////
void GetBestKillReturnsBestKill()
{
    DataAccess->saveCombatStatistics("gorthaur",
        "lib/realizations/monster.c#dwight", "dwight", 14);

    ExpectEq(([ "name": "dwight",
                "level": 14,
                "key": "lib/realizations/monster.c#dwight",
                "times killed": 2 ]),
        DataAccess->getBestKill("gorthaur"));
}

/////////////////////////////////////////////////////////////////////////////
void GetNemesisKillReturnsNemesis()
{
    DataAccess->saveCombatStatistics("gorthaur",
        "lib/realizations/monster.c#fred", "fred", 12);

    ExpectEq((["name":"fred",
        "level" : 12,
        "key" : "lib/realizations/monster.c#fred",
        "times killed" : 3]),
        DataAccess->getNemesis("gorthaur"));
}