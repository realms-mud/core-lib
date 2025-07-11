//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
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
    Effect.testAddSpecification("command template", "throw turnip [at ##Target##]");
    Effect.testAddSpecification("scope", "targeted");
    Effect.testAddSpecification("damage type", "magical");

    User = clone_object("/lib/tests/support/services/combatWithMockServices");
    User.Name("Bob");
    User.addAlias("bob");
    User.Str(20);
    User.Int(20);
    User.Dex(20);
    User.Con(20);
    User.Wis(20);
    User.Chr(20);
    User.hitPoints(User.maxHitPoints());
    User.spellPoints(User.maxSpellPoints());
    User.staminaPoints(User.maxStaminaPoints());
    User.addSkillPoints(200);
    User.advanceSkill("long sword", 16);
    User.toggleKillList();
    User.ToggleMockResearch();

    Target = clone_object("/lib/realizations/monster");
    Target.Name("Frank");
    Target.addAlias("frank");
    Target.Str(20);
    Target.Int(20);
    Target.Dex(20);
    Target.Con(20);
    Target.Wis(20);
    Target.Chr(20);
    Target.hitPoints(50);
    Target.spellPoints(50);
    Target.staminaPoints(50);

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

    ExpectTrue(Effect.testAddSpecification("damage hit points", ({ formula })));

    // This proves that Bob is not one of Frank's attackers
    ExpectFalse(Target.unregisterAttacker(User));

    ExpectEq(50, Target.hitPoints(), "Frank's initial HP");
    ExpectTrue(Effect.execute("throw turnip at frank", User));
    ExpectEq(29, Target.hitPoints(), "Frank has taken damage");

    // Proof that Bob and Frank are now fighting
    ExpectTrue(Target.unregisterAttacker(User));
}

/////////////////////////////////////////////////////////////////////////////
void IncreaseHitPointsWillNotExecuteAttack()
{
    mapping formula = ([
        "probability": 100,
        "base damage": 25,
        "range": 0
    ]);

    ExpectTrue(Effect.testAddSpecification("increase hit points", ({ formula })));

    // This proves that Bob is not one of Frank's attackers
    ExpectFalse(Target.unregisterAttacker(User));

    ExpectEq(50, Target.hitPoints(), "Frank's initial HP");
    ExpectTrue(Effect.execute("throw turnip at frank", User));
    ExpectEq(75, Target.hitPoints(), "Frank has been healed");

    // Proof that Bob and Frank are now fighting
    ExpectFalse(Target.unregisterAttacker(User));
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteOnSelfAppliesEffect()
{
    mapping* heal = ({
        (["probability":100, "base damage" : 10, "range" : 0])
        });
    Effect.testAddSpecification("increase hit points", heal);

    int before = User.hitPoints();
    ExpectEq(150, User.hitPoints(), "user healed");

    ExpectTrue(Effect.execute("throw turnip at bob", User));

    ExpectEq(before + 10, User.hitPoints(), "user healed");
}

/////////////////////////////////////////////////////////////////////////////
void CannotDamageIfTargetNotOnKillList()
{
    mapping formula = ([
        "probability": 100,
        "base damage": 25,
        "range": 0
    ]);
    destruct(Target);
    Target = clone_object("/lib/tests/support/services/combatWithMockServices");
    Target.Name("Frank");
    Target.addAlias("frank");
    move_object(Target, Room);

    ExpectTrue(Effect.testAddSpecification("damage hit points", ({ formula })));
    ExpectFalse(Effect.execute("throw turnip at frank", User));
}

/////////////////////////////////////////////////////////////////////////////
void CannotDamageIfTargetPlayerOnKillListButInitiatorIsNot()
{
    mapping formula = ([
        "probability": 100,
        "base damage": 25,
        "range": 0
    ]);
    destruct(Target);
    Target = clone_object("/lib/tests/support/services/combatWithMockServices");
    Target.Name("Frank");
    Target.addAlias("frank");
    Target.toggleKillList();

    User.toggleKillList();
    ExpectFalse(Effect.execute("throw turnip at frank", User));
}

/////////////////////////////////////////////////////////////////////////////
void DamageSpellPointsWillExecuteAttack()
{
    mapping formula = ([
        "probability": 100,
        "base damage": 25,
        "range": 0
    ]);

    ExpectTrue(Effect.testAddSpecification("damage spell points", ({ formula })));

    // This proves that Bob is not one of Frank's attackers
    ExpectFalse(Target.unregisterAttacker(User));

    ExpectEq(50, Target.spellPoints(), "Frank's initial SP");
    ExpectTrue(Effect.execute("throw turnip at frank", User));
    ExpectEq(25, Target.spellPoints(), "Frank has taken damage");

    // Proof that Bob and Frank are now fighting
    ExpectTrue(Target.unregisterAttacker(User));
}

/////////////////////////////////////////////////////////////////////////////
void IncreaseSpellPointsWillNotExecuteAttack()
{
    mapping formula = ([
        "probability": 100,
        "base damage": 25,
        "range": 0
    ]);

    ExpectTrue(Effect.testAddSpecification("increase spell points", ({ formula })));

    // This proves that Bob is not one of Frank's attackers
    ExpectFalse(Target.unregisterAttacker(User));

    ExpectEq(50, Target.spellPoints(), "Frank's initial SP");
    ExpectTrue(Effect.execute("throw turnip at frank", User));
    ExpectEq(75, Target.spellPoints(), "Frank has been healed");

    // Proof that Bob and Frank are now fighting
    ExpectFalse(Target.unregisterAttacker(User));
}

/////////////////////////////////////////////////////////////////////////////
void DamageStaminaPointsWillExecuteAttack()
{
    mapping formula = ([
        "probability": 100,
        "base damage": 25,
        "range": 0
    ]);

    ExpectTrue(Effect.testAddSpecification("damage stamina points", ({ formula })));

    // This proves that Bob is not one of Frank's attackers
    ExpectFalse(Target.unregisterAttacker(User));

    ExpectEq(50, Target.staminaPoints(), "Frank's initial stamina");
    ExpectTrue(Effect.execute("throw turnip at frank", User));
    ExpectEq(25, Target.staminaPoints(), "Frank has taken damage");

    // Proof that Bob and Frank are now fighting
    ExpectTrue(Target.unregisterAttacker(User));
}

/////////////////////////////////////////////////////////////////////////////
void IncreaseStaminaPointsWillNotExecuteAttack()
{
    mapping formula = ([
        "probability": 100,
        "base damage": 25,
        "range": 0
    ]);

    ExpectTrue(Effect.testAddSpecification("increase stamina points", ({ formula })));

    // This proves that Bob is not one of Frank's attackers
    ExpectFalse(Target.unregisterAttacker(User));

    ExpectEq(50, Target.staminaPoints(), "Frank's initial stamina");
    ExpectTrue(Effect.execute("throw turnip at frank", User));
    ExpectEq(75, Target.staminaPoints(), "Frank has been healed");

    // Proof that Bob and Frank are now fighting
    ExpectFalse(Target.unregisterAttacker(User));
}

/////////////////////////////////////////////////////////////////////////////
void IncreaseIntoxicationWillExecuteAttack()
{
    mapping formula = ([
        "probability": 100,
        "base damage": 20,
        "range": 0
    ]);

    ExpectTrue(Effect.testAddSpecification("increase intoxication", ({ formula })));

    // This proves that Bob is not one of Frank's attackers
    ExpectFalse(Target.unregisterAttacker(User));

    ExpectEq(0, Target.Intoxicated(), "Frank's initial intoxication");
    ExpectTrue(Effect.execute("throw turnip at frank", User));
    ExpectEq(20, Target.Intoxicated(), "Frank has taken damage");

    // Proof that Bob and Frank are now fighting
    ExpectTrue(Target.unregisterAttacker(User));
}

/////////////////////////////////////////////////////////////////////////////
void IncreaseDruggednessWillExecuteAttack()
{
    mapping formula = ([
        "probability": 100,
        "base damage": 20,
        "range": 0
    ]);

    ExpectTrue(Effect.testAddSpecification("increase druggedness", ({ formula })));

    // This proves that Bob is not one of Frank's attackers
    ExpectFalse(Target.unregisterAttacker(User));

    ExpectEq(0, Target.Drugged(), "Frank's initial druggedness");
    ExpectTrue(Effect.execute("throw turnip at frank", User));
    ExpectEq(20, Target.Drugged(), "Frank has taken damage");

    // Proof that Bob and Frank are now fighting
    ExpectTrue(Target.unregisterAttacker(User));
}

/////////////////////////////////////////////////////////////////////////////
void IncreaseSoakedWillExecuteAttack()
{
    mapping formula = ([
        "probability": 100,
        "base damage": 20,
        "range": 0
    ]);

    ExpectTrue(Effect.testAddSpecification("increase soaked", ({ formula })));

    // This proves that Bob is not one of Frank's attackers
    ExpectFalse(Target.unregisterAttacker(User));

    ExpectEq(0, Target.Soaked(), "Frank's initial soaked");
    ExpectTrue(Effect.execute("throw turnip at frank", User));
    ExpectEq(20, Target.Soaked(), "Frank has taken damage");

    // Proof that Bob and Frank are now fighting
    ExpectTrue(Target.unregisterAttacker(User));
}

/////////////////////////////////////////////////////////////////////////////
void IncreaseStuffedWillExecuteAttack()
{
    mapping formula = ([
        "probability": 100,
        "base damage": 20,
        "range": 0
    ]);

    ExpectTrue(Effect.testAddSpecification("increase stuffed", ({ formula })));

    // This proves that Bob is not one of Frank's attackers
    ExpectFalse(Target.unregisterAttacker(User));

    ExpectEq(0, Target.Stuffed(), "Frank's initial stuffed");
    ExpectTrue(Effect.execute("throw turnip at frank", User));
    ExpectEq(20, Target.Stuffed(), "Frank has taken damage");

    // Proof that Bob and Frank are now fighting
    ExpectTrue(Target.unregisterAttacker(User));
}

/////////////////////////////////////////////////////////////////////////////
void DecreaseIntoxicationWillNotExecuteAttack()
{
    mapping formula = ([
        "probability": 100,
        "base damage": 20,
        "range": 0
    ]);

    ExpectTrue(Effect.testAddSpecification("decrease intoxication", ({ formula })));

    // This proves that Bob is not one of Frank's attackers
    ExpectFalse(Target.unregisterAttacker(User));

    ExpectEq(25, Target.Intoxicated(25), "Frank's initial intoxication");
    ExpectTrue(Effect.execute("throw turnip at frank", User));
    ExpectEq(5, Target.Intoxicated(), "Frank has taken damage");

    // Proof that Bob and Frank are now fighting
    ExpectFalse(Target.unregisterAttacker(User));
}

/////////////////////////////////////////////////////////////////////////////
void DecreaseDruggednessWillNotExecuteAttack()
{
    mapping formula = ([
        "probability": 100,
        "base damage": 20,
        "range": 0
    ]);

    ExpectTrue(Effect.testAddSpecification("decrease druggedness", ({ formula })));

    // This proves that Bob is not one of Frank's attackers
    ExpectFalse(Target.unregisterAttacker(User));

    ExpectEq(25, Target.Drugged(25), "Frank's initial druggedness");
    ExpectTrue(Effect.execute("throw turnip at frank", User));
    ExpectEq(5, Target.Drugged(), "Frank has taken damage");

    // Proof that Bob and Frank are now fighting
    ExpectFalse(Target.unregisterAttacker(User));
}

/////////////////////////////////////////////////////////////////////////////
void DecreaseSoakedWillNotExecuteAttack()
{
    mapping formula = ([
        "probability": 100,
        "base damage": 20,
        "range": 0
    ]);

    ExpectTrue(Effect.testAddSpecification("decrease soaked", ({ formula })));

    // This proves that Bob is not one of Frank's attackers
    ExpectFalse(Target.unregisterAttacker(User));

    ExpectEq(25, Target.Soaked(25), "Frank's initial soaked");
    ExpectTrue(Effect.execute("throw turnip at frank", User));
    ExpectEq(5, Target.Soaked(), "Frank has taken damage");

    // Proof that Bob and Frank are now fighting
    ExpectFalse(Target.unregisterAttacker(User));
}

/////////////////////////////////////////////////////////////////////////////
void DecreaseStuffedWillNotExecuteAttack()
{
    mapping formula = ([
        "probability": 100,
        "base damage": 20,
        "range": 0
    ]);

    ExpectTrue(Effect.testAddSpecification("decrease stuffed", ({ formula })));

    // This proves that Bob is not one of Frank's attackers
    ExpectFalse(Target.unregisterAttacker(User));

    ExpectEq(25, Target.Stuffed(25), "Frank's initial stuffed");
    ExpectTrue(Effect.execute("throw turnip at frank", User));
    ExpectEq(5, Target.Stuffed(), "Frank has taken damage");

    // Proof that Bob and Frank are now fighting
    ExpectFalse(Target.unregisterAttacker(User));
}

/////////////////////////////////////////////////////////////////////////////
void NotSpecifyingTargetWillTargetCurrentForDamageResearch()
{
    Target.hitPoints(100);
    mapping formula = ([
        "probability": 100,
        "base damage": 25,
        "range": 0
    ]);

    ExpectTrue(Effect.testAddSpecification("damage hit points", ({ formula })));

    // This proves that Bob is not one of Frank's attackers
    ExpectFalse(Target.unregisterAttacker(User));

    ExpectEq(150, Target.hitPoints(), "Frank's initial HP");
    ExpectTrue(Effect.execute("throw turnip at frank", User));
    ExpectEq(129, Target.hitPoints(), "Frank has taken damage");

    // Proof that Bob and Frank are now fighting
    ExpectTrue(Target.unregisterAttacker(User));
    User.heart_beat();
    Target.hitPoints(100);
    ExpectEq(150, Target.hitPoints(), "Frank has taken damage");
    ExpectTrue(Effect.execute("throw turnip", User));
    ExpectEq(129, Target.hitPoints(), "Frank has taken damage");
}

/////////////////////////////////////////////////////////////////////////////
void NotSpecifyingTargetWillTargetOwnerForBeneficialResearch()
{
    mapping formula = ([
        "probability": 100,
        "base damage": 25,
        "range": 0
    ]);

    User.hit(110);
    ExpectTrue(Effect.testAddSpecification("increase hit points", ({ formula })));

    ExpectEq(50, User.hitPoints(), "Bob's initial HP");
    ExpectTrue(Effect.execute("throw turnip", User));
    ExpectEq(75, User.hitPoints(), "Bob has been healed");
}

/////////////////////////////////////////////////////////////////////////////
void CooldownAffectedByOtherResearch()
{
    User = clone_object("/lib/tests/support/services/mockPlayer.c");
    User.Name("Bob");

    ExpectTrue(Effect.testAddSpecification("cooldown", 100));
    ExpectTrue(Effect.testAddSpecification("cooldown modifiers", 
        (["/lib/tests/support/research/comboPartResearchItemA.c": 25 ])));

    ExpectEq(100, Effect.cooldown(User));

    User.addResearchPoints(1);
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemA.c");

    ExpectEq(75, Effect.cooldown(User));
}

/////////////////////////////////////////////////////////////////////////////
void CostAffectedByOtherResearch()
{
    User = clone_object("/lib/tests/support/services/mockPlayer.c");
    User.Name("Bob");

    ExpectTrue(Effect.testAddSpecification("hit point cost", 100));
    ExpectTrue(Effect.testAddSpecification("spell point cost", 100));
    ExpectTrue(Effect.testAddSpecification("stamina point cost", 100));
    ExpectTrue(Effect.testAddSpecification("hit point cost modifiers",
        (["/lib/tests/support/research/comboPartResearchItemA.c": 25 ])));
    ExpectTrue(Effect.testAddSpecification("spell point cost modifiers",
        (["/lib/tests/support/research/comboPartResearchItemA.c": 15 ])));
    ExpectTrue(Effect.testAddSpecification("stamina point cost modifiers",
        (["/lib/tests/support/research/comboPartResearchItemA.c": 10 ])));

    ExpectEq((["hit point cost": 100,
               "spell point cost": 100,
               "stamina point cost": 100]), Effect.getUsageCosts("", User));

    User.addResearchPoints(1);
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemA.c");

    ExpectEq((["hit point cost": 75,
               "spell point cost": 85,
               "stamina point cost": 90 ]), Effect.getUsageCosts("", User));
}

/////////////////////////////////////////////////////////////////////////////
void RepeatingEffectsExecuteCorrectNumberOfTimes()
{
    Target.hitPoints(100);
    mapping formula = ([
        "probability": 100,
        "base damage": 25,
        "range": 0
    ]);

    object subscriber = clone_object("/lib/tests/support/events/onHitSubscriber");
    Target.registerEvent(subscriber);

    ExpectTrue(Effect.testAddSpecification("damage hit points", ({ formula })));
    ExpectTrue(Effect.testAddSpecification("repeat effect", 2));

    // This proves that Bob is not one of Frank's attackers
    ExpectFalse(Target.unregisterAttacker(User));
    ExpectEq(150, Target.hitPoints(), "Frank's initial HP");

    ToggleCallOutBypass();
    ExpectTrue(Effect.execute("throw turnip at frank", User));
    ExpectEq(87, Target.hitPoints(), "Frank has taken damage");
    ExpectEq(3, subscriber.TimesOnHitEventReceived());
    ExpectEq(([ "damage": 25, "type": "magical" ]), 
        (["damage":25, "type" : "magical"]), 
        (["damage":25, "type" : "magical"]), 
        subscriber.OnHitEventData());
    ToggleCallOutBypass();
}

/////////////////////////////////////////////////////////////////////////////
void SupercedeTargetsPlacesNewFoeAtTopOfList()
{
    User.registerAttacker(Target);
    Target.registerAttacker(User);

    ExpectEq(User, Target.getTargetToAttack());

    object newAttacker =
        clone_object("/lib/tests/support/services/mockPlayer.c");
    newAttacker.Name("Norman");
    newAttacker.addCommands();
    move_object(newAttacker, Room);

    newAttacker.initiateResearch(
        "/lib/tests/support/research/supercedeResearch.c");
    command("supercede at frank", newAttacker);

    ExpectEq(newAttacker, Target.getTargetToAttack());
}

/////////////////////////////////////////////////////////////////////////////
void SiphonHitPointsWillExecuteAttack()
{
    mapping formula = ([
        "probability": 100,
        "base damage": 25,
        "range": 0
    ]);

    ExpectTrue(Effect.testAddSpecification("siphon hit points", ({ formula })));

    // This proves that Bob is not one of Frank's attackers
    ExpectFalse(Target.unregisterAttacker(User));

    ExpectEq(50, Target.hitPoints(), "Frank's initial HP");
    ExpectEq(150, User.hitPoints(), "Bob's initial HP");
    ExpectEq(150, User.spellPoints(), "Bob's initial SP");
    ExpectEq(150, User.staminaPoints(), "Bob's initial ST");

    ExpectTrue(Effect.execute("throw turnip at frank", User));
    ExpectEq(29, Target.hitPoints(), "Frank has taken damage");
    ExpectEq(156, User.hitPoints(), "Bob's increased HP");
    ExpectEq(158, User.spellPoints(), "Bob's increased SP");
    ExpectEq(158, User.staminaPoints(), "Bob's increased ST");

    // Proof that Bob and Frank are now fighting
    ExpectTrue(Target.unregisterAttacker(User));
}

/////////////////////////////////////////////////////////////////////////////
void SiphonSpellPointsWillExecuteAttack()
{
    mapping formula = ([
        "probability": 100,
        "base damage": 25,
        "range": 0
    ]);

    ExpectTrue(Effect.testAddSpecification("siphon spell points", ({ formula })));

    // This proves that Bob is not one of Frank's attackers
    ExpectFalse(Target.unregisterAttacker(User));

    ExpectEq(50, Target.spellPoints(), "Frank's initial SP");
    ExpectEq(150, User.hitPoints(), "Bob's initial HP");
    ExpectEq(150, User.spellPoints(), "Bob's initial SP");
    ExpectEq(150, User.staminaPoints(), "Bob's initial ST");

    ExpectTrue(Effect.execute("throw turnip at frank", User));
    ExpectEq(25, Target.spellPoints(), "Frank has taken SP damage");
    ExpectEq(156, User.hitPoints(), "Bob's increased HP");
    ExpectEq(158, User.spellPoints(), "Bob's increased SP");
    ExpectEq(158, User.staminaPoints(), "Bob's increased ST");

    // Proof that Bob and Frank are now fighting
    ExpectTrue(Target.unregisterAttacker(User));
}

/////////////////////////////////////////////////////////////////////////////
void SiphonStaminaPointsWillExecuteAttack()
{
    mapping formula = ([
        "probability": 100,
        "base damage": 25,
        "range": 0
    ]);

    ExpectTrue(Effect.testAddSpecification("siphon stamina points", ({ formula })));

    // This proves that Bob is not one of Frank's attackers
    ExpectFalse(Target.unregisterAttacker(User));

    ExpectEq(50, Target.staminaPoints(), "Frank's initial ST");
    ExpectEq(150, User.hitPoints(), "Bob's initial HP");
    ExpectEq(150, User.spellPoints(), "Bob's initial SP");
    ExpectEq(150, User.staminaPoints(), "Bob's initial ST");

    ExpectTrue(Effect.execute("throw turnip at frank", User));
    ExpectEq(25, Target.staminaPoints(), "Frank has taken ST damage");
    ExpectEq(156, User.hitPoints(), "Bob's increased HP");
    ExpectEq(158, User.spellPoints(), "Bob's increased SP");
    ExpectEq(158, User.staminaPoints(), "Bob's increased ST");

    // Proof that Bob and Frank are now fighting
    ExpectTrue(Target.unregisterAttacker(User));
}

/////////////////////////////////////////////////////////////////////////////
void NegativeExecuteInAreaAppliedOnCorrectTargets()
{
    Effect.testAddSpecification("command template", "throw turnip");
    Effect.testAddSpecification("damage type", "magical");
    Effect.testAddSpecification("scope", "area");

    object bystander = clone_object("/lib/tests/support/services/combatWithMockServices");
    bystander.Name("Earl");
    bystander.addAlias("earl");
    bystander.Str(20);
    bystander.Int(20);
    bystander.Dex(20);
    bystander.Con(20);
    bystander.Wis(20);
    bystander.Chr(20);
    bystander.addSkillPoints(200);
    bystander.advanceSkill("long sword", 10);
    bystander.hitPoints(100);
    move_object(bystander, Room);

    object badguy = clone_object("/lib/realizations/monster");
    badguy.Name("Fred");
    badguy.addAlias("fred");
    badguy.Str(20);
    badguy.Int(20);
    badguy.Dex(20);
    badguy.Con(20);
    badguy.Wis(20);
    badguy.Chr(20);
    badguy.addSkillPoints(200);
    badguy.advanceSkill("long sword", 10);
    badguy.hitPoints(100);
    move_object(badguy, Room);

    ExpectTrue(Effect.testAddSpecification("damage hit points", ({ ([
        "probability":100,
        "base damage" : 10,
        "range" : 0
    ]) })));

    ExpectEq(150, User.hitPoints(), "Bob's initial HP");
    ExpectEq(50, Target.hitPoints(), "Frank's initial HP");
    ExpectEq(100, bystander.hitPoints(), "Earl's initial HP");
    ExpectEq(100, badguy.hitPoints(), "Fred's initial HP");

    ExpectTrue(Effect.execute("throw turnip", User), "can execute command");

    ExpectEq(150, User.hitPoints(), "Bob's initial HP");
    ExpectEq(44, Target.hitPoints(), "Frank's initial HP");
    ExpectEq(100, bystander.hitPoints(), "Earl's initial HP");
    ExpectEq(94, badguy.hitPoints(), "Fred's initial HP");
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteInAreaAppliedOnCorrectTargets()
{
    Effect.testAddSpecification("command template", "throw turnip");
    Effect.testAddSpecification("damage type", "magical");
    Effect.testAddSpecification("scope", "area");

    object bystander = clone_object("/lib/tests/support/services/combatWithMockServices");
    bystander.Name("Earl");
    bystander.addAlias("earl");
    bystander.Str(20);
    bystander.Int(20);
    bystander.Dex(20);
    bystander.Con(20);
    bystander.Wis(20);
    bystander.Chr(20);
    bystander.addSkillPoints(200);
    bystander.advanceSkill("long sword", 10);
    bystander.hitPoints(50);
    move_object(bystander, Room);

    object badguy = clone_object("/lib/realizations/monster");
    badguy.Name("Fred");
    badguy.addAlias("fred");
    badguy.Str(20);
    badguy.Int(20);
    badguy.Dex(20);
    badguy.Con(20);
    badguy.Wis(20);
    badguy.Chr(20);
    badguy.addSkillPoints(200);
    badguy.advanceSkill("long sword", 10);
    badguy.hitPoints(50);
    move_object(badguy, Room);

    ExpectTrue(Effect.testAddSpecification("increase hit points", ({ ([
        "probability":100,
        "base damage" : 25,
        "range" : 0
    ]) })));

    User.hit(59, "lightning");
    ExpectEq(100, User.hitPoints(), "Bob's initial HP");
    ExpectEq(50, Target.hitPoints(), "Frank's initial HP");
    ExpectEq(50, bystander.hitPoints(), "Earl's initial HP");
    ExpectEq(50, badguy.hitPoints(), "Fred's initial HP");

    ExpectTrue(Effect.execute("throw turnip", User), "can execute command");

    ExpectEq(125, User.hitPoints(), "Bob's final HP");
    ExpectEq(75, Target.hitPoints(), "Frank's final HP");
    ExpectEq(75, bystander.hitPoints(), "Earl's final HP");
    ExpectEq(75, badguy.hitPoints(), "Fred's final HP");
}
