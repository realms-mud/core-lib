//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";
#include "/lib/include/inventory.h"

object Effect;
object User;
object Target;
object Room;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Effect = clone_object("/lib/tests/support/research/testInstantaneousActiveResearchItem");
    Effect->testAddSpecification("command template", "throw turnip at ##Target##");
    Effect->testAddSpecification("scope", "targeted");
    Effect->testAddSpecification("damage type", "magical");

    User = clone_object("/lib/tests/support/services/combatWithMockServices");
    User->Name("Bob");
    User->addAlias("bob");
    User->Str(20);
    User->Int(20);
    User->Dex(20);
    User->Con(20);
    User->Wis(20);
    User->Chr(20);
    User->hitPoints(User->maxHitPoints());
    User->spellPoints(User->maxSpellPoints());
    User->staminaPoints(User->maxStaminaPoints());
    User->addSkillPoints(200);
    User->advanceSkill("long sword", 16);
    User->toggleKillList();
    User->ToggleMockResearch();

    Target = clone_object("/lib/realizations/monster");
    Target->Name("Frank");
    Target->addAlias("frank");
    Target->Str(20);
    Target->Int(20);
    Target->Dex(20);
    Target->Con(20);
    Target->Wis(20);
    Target->Chr(20);
    Target->hitPoints(50);
    Target->spellPoints(50);
    Target->staminaPoints(50);

    Room = clone_object("/lib/environment/environment");
    move_object(User, Room);
    move_object(Target, Room);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Target);
    destruct(User);
    destruct(Effect);
    destruct(Room);
}

/////////////////////////////////////////////////////////////////////////////
void DamageHitPointsWillExecuteAttack()
{
    mapping formula = ([
        "probability": 100,
        "base damage": 25,
        "range": 0
    ]);

    ExpectTrue(Effect->testAddSpecification("damage hit points", ({ formula })));

    // This proves that Bob is not one of Frank's attackers
    ExpectFalse(Target->unregisterAttacker(User));

    ExpectEq(50, Target->hitPoints(), "Frank's initial HP");
    ExpectTrue(Effect->execute("throw turnip at frank", User));
    ExpectEq(29, Target->hitPoints(), "Frank has taken damage");

    // Proof that Bob and Frank are now fighting
    ExpectTrue(Target->unregisterAttacker(User));
}

/////////////////////////////////////////////////////////////////////////////
void IncreaseHitPointsWillNotExecuteAttack()
{
    mapping formula = ([
        "probability":100,
        "base damage" : 25,
        "range" : 0
    ]);

    ExpectTrue(Effect->testAddSpecification("increase hit points", ({ formula })));

    // This proves that Bob is not one of Frank's attackers
    ExpectFalse(Target->unregisterAttacker(User));

    ExpectEq(50, Target->hitPoints(), "Frank's initial HP");
    ExpectTrue(Effect->execute("throw turnip at frank", User));
    ExpectEq(75, Target->hitPoints(), "Frank has been healed");

    // Proof that Bob and Frank are now fighting
    ExpectFalse(Target->unregisterAttacker(User));
}

/////////////////////////////////////////////////////////////////////////////
void CannotDamageIfTargetNotOnKillList()
{
    mapping formula = ([
        "probability":100,
        "base damage" : 25,
        "range" : 0
    ]);
    destruct(Target);
    Target = clone_object("/lib/tests/support/services/combatWithMockServices");
    Target->Name("Frank");
    Target->addAlias("frank");
    move_object(Target, Room);

    ExpectTrue(Effect->testAddSpecification("damage hit points", ({ formula })));
    ExpectFalse(Effect->execute("throw turnip at frank", User));
}

/////////////////////////////////////////////////////////////////////////////
void CannotDamageIfTargetPlayerOnKillListButInitiatorIsNot()
{
    mapping formula = ([
        "probability":100,
        "base damage" : 25,
        "range" : 0
    ]);
    destruct(Target);
    Target = clone_object("/lib/tests/support/services/combatWithMockServices");
    Target->Name("Frank");
    Target->addAlias("frank");
    Target->toggleKillList();

    User->toggleKillList();
    ExpectFalse(Effect->execute("throw turnip at frank", User));
}

/////////////////////////////////////////////////////////////////////////////
void DamageSpellPointsWillExecuteAttack()
{
    mapping formula = ([
        "probability": 100,
        "base damage": 25,
        "range": 0
    ]);

    ExpectTrue(Effect->testAddSpecification("damage spell points", ({ formula })));

    // This proves that Bob is not one of Frank's attackers
    ExpectFalse(Target->unregisterAttacker(User));

    ExpectEq(50, Target->spellPoints(), "Frank's initial SP");
    ExpectTrue(Effect->execute("throw turnip at frank", User));
    ExpectEq(25, Target->spellPoints(), "Frank has taken damage");

    // Proof that Bob and Frank are now fighting
    ExpectTrue(Target->unregisterAttacker(User));
}

/////////////////////////////////////////////////////////////////////////////
void IncreaseSpellPointsWillNotExecuteAttack()
{
    mapping formula = ([
        "probability":100,
        "base damage" : 25,
        "range" : 0
    ]);

    ExpectTrue(Effect->testAddSpecification("increase spell points", ({ formula })));

    // This proves that Bob is not one of Frank's attackers
    ExpectFalse(Target->unregisterAttacker(User));

    ExpectEq(50, Target->spellPoints(), "Frank's initial SP");
    ExpectTrue(Effect->execute("throw turnip at frank", User));
    ExpectEq(75, Target->spellPoints(), "Frank has been healed");

    // Proof that Bob and Frank are now fighting
    ExpectFalse(Target->unregisterAttacker(User));
}

/////////////////////////////////////////////////////////////////////////////
void DamageStaminaPointsWillExecuteAttack()
{
    mapping formula = ([
        "probability": 100,
        "base damage": 25,
        "range": 0
    ]);

    ExpectTrue(Effect->testAddSpecification("damage stamina points", ({ formula })));

    // This proves that Bob is not one of Frank's attackers
    ExpectFalse(Target->unregisterAttacker(User));

    ExpectEq(50, Target->staminaPoints(), "Frank's initial stamina");
    ExpectTrue(Effect->execute("throw turnip at frank", User));
    ExpectEq(25, Target->staminaPoints(), "Frank has taken damage");

    // Proof that Bob and Frank are now fighting
    ExpectTrue(Target->unregisterAttacker(User));
}

/////////////////////////////////////////////////////////////////////////////
void IncreaseStaminaPointsWillNotExecuteAttack()
{
    mapping formula = ([
        "probability":100,
        "base damage" : 25,
        "range" : 0
    ]);

    ExpectTrue(Effect->testAddSpecification("increase stamina points", ({ formula })));

    // This proves that Bob is not one of Frank's attackers
    ExpectFalse(Target->unregisterAttacker(User));

    ExpectEq(50, Target->staminaPoints(), "Frank's initial stamina");
    ExpectTrue(Effect->execute("throw turnip at frank", User));
    ExpectEq(75, Target->staminaPoints(), "Frank has been healed");

    // Proof that Bob and Frank are now fighting
    ExpectFalse(Target->unregisterAttacker(User));
}

/////////////////////////////////////////////////////////////////////////////
void IncreaseIntoxicationWillExecuteAttack()
{
    mapping formula = ([
        "probability":100,
        "base damage" : 20,
        "range" : 0
    ]);

    ExpectTrue(Effect->testAddSpecification("increase intoxication", ({ formula })));

    // This proves that Bob is not one of Frank's attackers
    ExpectFalse(Target->unregisterAttacker(User));

    ExpectEq(0, Target->Intoxicated(), "Frank's initial intoxication");
    ExpectTrue(Effect->execute("throw turnip at frank", User));
    ExpectEq(20, Target->Intoxicated(), "Frank has taken damage");

    // Proof that Bob and Frank are now fighting
    ExpectTrue(Target->unregisterAttacker(User));
}

/////////////////////////////////////////////////////////////////////////////
void IncreaseDruggednessWillExecuteAttack()
{
    mapping formula = ([
        "probability":100,
        "base damage" : 20,
        "range" : 0
    ]);

    ExpectTrue(Effect->testAddSpecification("increase druggedness", ({ formula })));

    // This proves that Bob is not one of Frank's attackers
    ExpectFalse(Target->unregisterAttacker(User));

    ExpectEq(0, Target->Drugged(), "Frank's initial druggedness");
    ExpectTrue(Effect->execute("throw turnip at frank", User));
    ExpectEq(20, Target->Drugged(), "Frank has taken damage");

    // Proof that Bob and Frank are now fighting
    ExpectTrue(Target->unregisterAttacker(User));
}

/////////////////////////////////////////////////////////////////////////////
void IncreaseSoakedWillExecuteAttack()
{
    mapping formula = ([
        "probability":100,
        "base damage" : 20,
        "range" : 0
    ]);

    ExpectTrue(Effect->testAddSpecification("increase soaked", ({ formula })));

    // This proves that Bob is not one of Frank's attackers
    ExpectFalse(Target->unregisterAttacker(User));

    ExpectEq(0, Target->Soaked(), "Frank's initial soaked");
    ExpectTrue(Effect->execute("throw turnip at frank", User));
    ExpectEq(20, Target->Soaked(), "Frank has taken damage");

    // Proof that Bob and Frank are now fighting
    ExpectTrue(Target->unregisterAttacker(User));
}

/////////////////////////////////////////////////////////////////////////////
void IncreaseStuffedWillExecuteAttack()
{
    mapping formula = ([
        "probability":100,
        "base damage" : 20,
        "range" : 0
    ]);

    ExpectTrue(Effect->testAddSpecification("increase stuffed", ({ formula })));

    // This proves that Bob is not one of Frank's attackers
    ExpectFalse(Target->unregisterAttacker(User));

    ExpectEq(0, Target->Stuffed(), "Frank's initial stuffed");
    ExpectTrue(Effect->execute("throw turnip at frank", User));
    ExpectEq(20, Target->Stuffed(), "Frank has taken damage");

    // Proof that Bob and Frank are now fighting
    ExpectTrue(Target->unregisterAttacker(User));
}

/////////////////////////////////////////////////////////////////////////////
void DecreaseIntoxicationWillNotExecuteAttack()
{
    mapping formula = ([
        "probability":100,
        "base damage" : 20,
        "range" : 0
    ]);

    ExpectTrue(Effect->testAddSpecification("decrease intoxication", ({ formula })));

    // This proves that Bob is not one of Frank's attackers
    ExpectFalse(Target->unregisterAttacker(User));

    ExpectEq(25, Target->Intoxicated(25), "Frank's initial intoxication");
    ExpectTrue(Effect->execute("throw turnip at frank", User));
    ExpectEq(5, Target->Intoxicated(), "Frank has taken damage");

    // Proof that Bob and Frank are now fighting
    ExpectFalse(Target->unregisterAttacker(User));
}

/////////////////////////////////////////////////////////////////////////////
void DecreaseDruggednessWillNotExecuteAttack()
{
    mapping formula = ([
        "probability":100,
        "base damage" : 20,
        "range" : 0
    ]);

    ExpectTrue(Effect->testAddSpecification("decrease druggedness", ({ formula })));

    // This proves that Bob is not one of Frank's attackers
    ExpectFalse(Target->unregisterAttacker(User));

    ExpectEq(25, Target->Drugged(25), "Frank's initial druggedness");
    ExpectTrue(Effect->execute("throw turnip at frank", User));
    ExpectEq(5, Target->Drugged(), "Frank has taken damage");

    // Proof that Bob and Frank are now fighting
    ExpectFalse(Target->unregisterAttacker(User));
}

/////////////////////////////////////////////////////////////////////////////
void DecreaseSoakedWillNotExecuteAttack()
{
    mapping formula = ([
        "probability":100,
        "base damage" : 20,
        "range" : 0
    ]);

    ExpectTrue(Effect->testAddSpecification("decrease soaked", ({ formula })));

    // This proves that Bob is not one of Frank's attackers
    ExpectFalse(Target->unregisterAttacker(User));

    ExpectEq(25, Target->Soaked(25), "Frank's initial soaked");
    ExpectTrue(Effect->execute("throw turnip at frank", User));
    ExpectEq(5, Target->Soaked(), "Frank has taken damage");

    // Proof that Bob and Frank are now fighting
    ExpectFalse(Target->unregisterAttacker(User));
}

/////////////////////////////////////////////////////////////////////////////
void DecreaseStuffedWillNotExecuteAttack()
{
    mapping formula = ([
        "probability":100,
        "base damage" : 20,
        "range" : 0
    ]);

    ExpectTrue(Effect->testAddSpecification("decrease stuffed", ({ formula })));

    // This proves that Bob is not one of Frank's attackers
    ExpectFalse(Target->unregisterAttacker(User));

    ExpectEq(25, Target->Stuffed(25), "Frank's initial stuffed");
    ExpectTrue(Effect->execute("throw turnip at frank", User));
    ExpectEq(5, Target->Stuffed(), "Frank has taken damage");

    // Proof that Bob and Frank are now fighting
    ExpectFalse(Target->unregisterAttacker(User));
}

