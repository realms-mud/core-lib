//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";
#include "/lib/include/inventory.h"

object Attacker;
object Target;

/////////////////////////////////////////////////////////////////////////////
void SetUpAttacker()
{
    Attacker = clone_object("/lib/realizations/player.c");
    Attacker.restore("gorthaur");
}

/////////////////////////////////////////////////////////////////////////////
void SetUpTarget()
{
    Target = clone_object("/lib/realizations/monster");
    Target.Name("Nukulevee");
    Target.Race("undead horse");
    Target.effectiveLevel(20);
    Target.Str(20);
    Target.Dex(20);
    Target.Con(20);
    Target.Int(20);
    Target.Wis(20);
}


/////////////////////////////////////////////////////////////////////////////
void Init()
{
    ignoreList += ({ "SetUpAttacker", "SetUpTarget" });
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

    SetUpAttacker();
    SetUpTarget();
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Target);
    destruct(Attacker);
}

/////////////////////////////////////////////////////////////////////////////
void CombatStatisticsAreGenerated()
{
    Attacker.generateCombatStatistics(Target);

    ExpectEq((["name":"Nukulevee",
        "level" : 20,
        "key" : "/lib/realizations/monster.c#Nukulevee",
        "times killed" : 1]),
        Attacker.getBestKill());

    ExpectEq((["name":"Nukulevee",
        "level" : 20,
        "key" : "/lib/realizations/monster.c#Nukulevee",
        "times killed" : 1]),
        Attacker.getNemesis());
    ExpectTrue(Attacker.racialKillsMeetCount("undead horse", 1), "One undead horse has been killed");
}

/////////////////////////////////////////////////////////////////////////////
void CombatStatisticsNemesisIsMostFrequestKill()
{
    object foe = clone_object("/lib/tests/support/services/combatWithMockServices");
    foe.Name("Earl");
    foe.Race("orc");
    foe.effectiveLevel(25);

    Attacker.generateCombatStatistics(foe);
    Attacker.generateCombatStatistics(Target);
    Attacker.generateCombatStatistics(Target);

    ExpectEq((["name":"Nukulevee",
        "level" : 20,
        "key" : "/lib/realizations/monster.c#Nukulevee",
        "times killed" : 2]),
        Attacker.getNemesis());
}

/////////////////////////////////////////////////////////////////////////////
void CombatStatisticsRaceUpdatesCorrectly()
{
    object foe = clone_object("/lib/realizations/monster");
    foe.Name("Earl");
    foe.Race("orc");
    foe.effectiveLevel(25);

    ExpectFalse(Attacker.racialKillsMeetCount("orc", 1), "One orc has not been killed");
    ExpectFalse(Attacker.racialKillsMeetCount("undead horse", 2), "Two undead horses have not been killed");

    Attacker.generateCombatStatistics(foe);
    Attacker.generateCombatStatistics(Target);

    ExpectTrue(Attacker.racialKillsMeetCount("orc", 1), "One orc has been killed");
    ExpectFalse(Attacker.racialKillsMeetCount("undead horse", 2), "Two undead horses still have not been killed");

    Attacker.generateCombatStatistics(Target);
    ExpectTrue(Attacker.racialKillsMeetCount("undead horse", 2), "Two undead horses have been killed");
}

/////////////////////////////////////////////////////////////////////////////
void CombatStatisticsBestKillUpdatesCorrectly()
{
    object foe = clone_object("/lib/realizations/monster");
    foe.Name("Earl");
    foe.Race("orc");
    foe.effectiveLevel(25);

    ExpectFalse(Attacker.bestKillMeetsLevel(20), "nothing killed yet.");
    Attacker.generateCombatStatistics(Target);
    ExpectTrue(Attacker.bestKillMeetsLevel(20), "Level 20 thing killed");
    ExpectFalse(Attacker.bestKillMeetsLevel(25), "Level 25 thing not killed");
    Attacker.generateCombatStatistics(foe);
    Attacker.generateCombatStatistics(Target);

    ExpectTrue(Attacker.bestKillMeetsLevel(25), "Level 25 thing not killed");
}
