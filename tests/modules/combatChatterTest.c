//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Attacker;
object Target;
object Room;

/////////////////////////////////////////////////////////////////////////////
void SetUpAttacker()
{
    Attacker = clone_object("/lib/tests/support/services/mockPlayer.c");
    Attacker->Name("Bob");
    Attacker->Str(20);
    Attacker->Dex(20);
    Attacker->Con(20);
    Attacker->Int(20);
    Attacker->Wis(20);
}

/////////////////////////////////////////////////////////////////////////////
void SetUpTarget()
{
    Target = clone_object("/lib/realizations/monster.c");
    Target->Name("Nukulevee");
    Target->Race("undead horse");
    Target->SetUpPersonaOfLevel("nukulevee", 20);
    Target->setUpRandomEquipment(100);
}

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    ignoreList += ({ "SetUpAttacker", "SetUpTarget" });
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    SetUpAttacker();
    SetUpTarget();
    Room = clone_object("/lib/tests/support/environment/fakeCombatRoom");
    move_object(Attacker, Room);
    move_object(Target, Room);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Room);
    destruct(Target);
    destruct(Attacker);
}

/////////////////////////////////////////////////////////////////////////////
void CombatChatterNotAvailableOnPlayers()
{
    ExpectEq(-1, member(inherit_list(Attacker), "lib/modules/combatChatter.c"));
}

/////////////////////////////////////////////////////////////////////////////
void CombatChatterAvailableOnMonsters()
{
    ExpectNotEq(-1, member(inherit_list(Target), "lib/modules/combatChatter.c"));
}

/////////////////////////////////////////////////////////////////////////////
void CanSeeDeathMessage()
{
    Target->addDeathMessage("##InitiatorName## ##Infinitive::look## at ##TargetName## "
        "and ##Infinitive::gasp##, `I just wanted a jar of dried beef.'");
    Target->hit(20000, "fire", Attacker);
    ExpectSubStringMatch("Nukulevee looks at you and gasps, `I just wanted a jar of dried beef",
        Attacker->caughtMessages()[0]);
}
