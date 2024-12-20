//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Researcher;
object Prerequisite;

/////////////////////////////////////////////////////////////////////////////
void PopulatePrerequisites()
{
    ExpectTrue(Prerequisite.AddTestPrerequisite("level", (["type":"level", "guild" : "mage", "value" : 10])));
    ExpectTrue(Prerequisite.AddTestPrerequisite("long sword", (["type":"skill", "value" : 10])));
    ExpectTrue(Prerequisite.AddTestPrerequisite("strength", (["type":"attribute", "value" : 10])));
    ExpectTrue(Prerequisite.AddTestPrerequisite("fetch a pencil", (["type":"quest"])));
    ExpectTrue(Prerequisite.AddTestPrerequisite("test research", (["type":"research"])));
    ExpectTrue(Prerequisite.AddTestPrerequisite("race", (["type":"race", "value" : ({ "elf", "high elf", "half elf" })])));
    ExpectTrue(Prerequisite.AddTestPrerequisite("guild", (["type":"guild", "value" : ({ "mage" })])));
    ExpectTrue(Prerequisite.AddTestPrerequisite("best kill", (["type":"combat statistic", "value" : 10])));
    ExpectTrue(Prerequisite.AddTestPrerequisite("orc", (["type":"combat statistic", "value" : 10])));
    ExpectTrue(Prerequisite.AddTestPrerequisite("annoying", (["type":"trait", "value" : ({ "boorish", "loutish" })])));
    ExpectTrue(Prerequisite.AddTestPrerequisite("nifty", (["type":"trait", "value" : ({ "spiffy" })])));
    ExpectTrue(Prerequisite.AddTestPrerequisite("background", (["type":"background", "value" : ({ "test" })])));
    ExpectTrue(Prerequisite.AddTestPrerequisite("faction", (["type":"faction", "value" : ({ "test" })])));
}

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    ignoreList += ({ "PopulatePrerequisites" });
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    setRestoreCaller(this_object());
    object database = clone_object("/lib/tests/modules/secure/fakeDatabase.c");
    database.PrepDatabase();

    object dataAccess = clone_object("/lib/modules/secure/dataAccess.c");
    dataAccess.savePlayerData(database.Gorthaur());

    destruct(dataAccess);
    destruct(database);

    Researcher = clone_object("/lib/realizations/player.c");
    Researcher.restore("gorthaur");

    Prerequisite = clone_object("/lib/tests/support/research/prerequisiteItem");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Prerequisite);
    destruct(Researcher);
}

/////////////////////////////////////////////////////////////////////////////
void CheckPrerequsistesCorrectlyHandlesBestKillChecks()
{
    ExpectTrue(Prerequisite.AddTestPrerequisite("best kill", (["type":"combat statistic", "value" : 10])));
    ExpectFalse(Prerequisite.checkPrerequisites(Researcher), "check initially fails");

    object foe = clone_object("/lib/realizations/monster.c");
    foe.Name("Rargh!");
    foe.Race("orc");
    foe.effectiveLevel(8);
    Researcher.generateCombatStatistics(foe);
    ExpectFalse(Prerequisite.checkPrerequisites(Researcher), "target has proper level");

    foe.Name("Grog!");
    foe.effectiveLevel(18);
    Researcher.generateCombatStatistics(foe);
    ExpectTrue(Prerequisite.checkPrerequisites(Researcher), "target has proper level");
}

/////////////////////////////////////////////////////////////////////////////
void CheckPrerequsistesCorrectlyHandlesRaceKillChecks()
{
    ExpectTrue(Prerequisite.AddTestPrerequisite("orc", (["type":"combat statistic", "value" : 2])));
    ExpectFalse(Prerequisite.checkPrerequisites(Researcher), "check initially fails");

    object foe = clone_object("/lib/realizations/monster.c");
    foe.Name("Rargh!");
    foe.Race("orc");
    foe.effectiveLevel(8);
    Researcher.generateCombatStatistics(foe);
    ExpectFalse(Prerequisite.checkPrerequisites(Researcher), "one orc killed");

    foe.Name("Grog!");
    foe.effectiveLevel(18);
    Researcher.generateCombatStatistics(foe);
    ExpectTrue(Prerequisite.checkPrerequisites(Researcher), "two orcs killed");
}
