//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";
#include "/lib/include/inventory.h"

object Effect;
object User;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Effect = clone_object("/lib/tests/support/research/testInstantaneousEffect");

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
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(User);
    destruct(Effect);
}

/////////////////////////////////////////////////////////////////////////////
void CanAddDamageHitPointsSpecification()
{
    mapping formula = ([
        "probability": 100,
        "base damage": 25,
        "range": 25
    ]);

    ExpectTrue(Effect.testAddInstantaneousSpecification("damage hit points", ({ formula })));
}

/////////////////////////////////////////////////////////////////////////////
void CanAddDamageSpellPointsSpecification()
{
    mapping formula = ([
        "probability": 100,
        "base damage": 25,
        "range": 25
    ]);

    ExpectTrue(Effect.testAddInstantaneousSpecification("damage spell points", ({ formula })));
}

/////////////////////////////////////////////////////////////////////////////
void CanAddDamageStaminaPointsSpecification()
{
    mapping formula = ([
        "probability": 100,
        "base damage": 25,
        "range": 25
    ]);

    ExpectTrue(Effect.testAddInstantaneousSpecification("damage stamina points", ({ formula })));
}

/////////////////////////////////////////////////////////////////////////////
void CanAddIncreaseHitPointsSpecification()
{
    mapping formula = ([
        "probability": 100,
        "base damage": 25,
        "range": 25
    ]);

    ExpectTrue(Effect.testAddInstantaneousSpecification("increase hit points", ({ formula })));
}

/////////////////////////////////////////////////////////////////////////////
void CanAddIncreaseSpellPointsSpecification()
{
    mapping formula = ([
        "probability": 100,
        "base damage": 25,
        "range": 25
    ]);

    ExpectTrue(Effect.testAddInstantaneousSpecification("increase spell points", ({ formula })));
}

/////////////////////////////////////////////////////////////////////////////
void CanAddIncreaseStaminaPointsSpecification()
{
    mapping formula = ([
        "probability": 100,
        "base damage": 25,
        "range": 25
    ]);

    ExpectTrue(Effect.testAddInstantaneousSpecification("increase stamina points", ({ formula })));
}

/////////////////////////////////////////////////////////////////////////////
void CanAddIncreaseIntoxicationSpecification()
{
    mapping formula = ([
        "probability": 100,
        "base damage": 25,
        "range": 25
    ]);

    ExpectTrue(Effect.testAddInstantaneousSpecification("increase intoxication", ({ formula })));
}

/////////////////////////////////////////////////////////////////////////////
void CanAddIncreaseDruggednessSpecification()
{
    mapping formula = ([
        "probability": 100,
        "base damage": 25,
        "range": 25
    ]);

    ExpectTrue(Effect.testAddInstantaneousSpecification("increase druggedness", ({ formula })));
}

/////////////////////////////////////////////////////////////////////////////
void CanAddIncreaseSoakedSpecification()
{
    mapping formula = ([
        "probability": 100,
        "base damage": 25,
        "range": 25
    ]);

    ExpectTrue(Effect.testAddInstantaneousSpecification("increase soaked", ({ formula })));
}

/////////////////////////////////////////////////////////////////////////////
void CanAddIncreaseStuffedSpecification()
{
    mapping formula = ([
        "probability": 100,
        "base damage": 25,
        "range": 25
    ]);

    ExpectTrue(Effect.testAddInstantaneousSpecification("increase stuffed", ({ formula })));
}

/////////////////////////////////////////////////////////////////////////////
void CanAddDecreaseIntoxicationSpecification()
{
    mapping formula = ([
        "probability":100,
            "base damage" : 25,
            "range" : 25
    ]);

    ExpectTrue(Effect.testAddInstantaneousSpecification("decrease intoxication", ({ formula })));
}

/////////////////////////////////////////////////////////////////////////////
void CanAddDecreaseDruggednessSpecification()
{
    mapping formula = ([
        "probability":100,
            "base damage" : 25,
            "range" : 25
    ]);

    ExpectTrue(Effect.testAddInstantaneousSpecification("decrease druggedness", ({ formula })));
}

/////////////////////////////////////////////////////////////////////////////
void CanAddDecreaseSoakedSpecification()
{
    mapping formula = ([
        "probability":100,
            "base damage" : 25,
            "range" : 25
    ]);

    ExpectTrue(Effect.testAddInstantaneousSpecification("decrease soaked", ({ formula })));
}

/////////////////////////////////////////////////////////////////////////////
void CanAddDecreaseStuffedSpecification()
{
    mapping formula = ([
        "probability":100,
            "base damage" : 25,
            "range" : 25
    ]);

    ExpectTrue(Effect.testAddInstantaneousSpecification("decrease stuffed", ({ formula })));
}

/////////////////////////////////////////////////////////////////////////////
void CanAddComplexSpecification()
{
    mapping *formula = ({ ([
        "probability": 33,
        "base damage": 25,
        "range": 25
    ]),
    ([
        "probability": 33,
        "base damage": 15,
        "range": 15
    ]),
    ([
        "probability": 34,
        "custom method": "customFormula"
    ]) });

    ExpectTrue(Effect.testAddInstantaneousSpecification("damage hit points", formula));
}

/////////////////////////////////////////////////////////////////////////////
void CannotAddFormulasThatAreLessThan100PercentProbability()
{
    mapping formula = ([
        "probability": 50,
        "base damage": 25,
        "range": 25
    ]);

    string err = catch (Effect.testAddInstantaneousSpecification("damage hit points", ({ formula })); nolog);
    string expectedError = "*ERROR - instantaneousEffect: the 'damage hit points' specification must be a properly formatted formula.\n";
    ExpectEq(expectedError, err);
}

/////////////////////////////////////////////////////////////////////////////
void CannotAddFormulasWithCustomMethodsThatDoNotExist()
{
    mapping formula = ([
        "probability":100,
        "custom method": "thisMethodDoesNotExist"
    ]);

    string err = catch (Effect.testAddInstantaneousSpecification("damage hit points", ({ formula })); nolog);
    string expectedError = "*ERROR - instantaneousEffect: the 'damage hit points' specification must be a properly formatted formula.\n";
    ExpectEq(expectedError, err);
}

/////////////////////////////////////////////////////////////////////////////
void CanAddModifierSpecification()
{
    mapping *modifiers = ({ ([
        "type":"skill",
        "name": "long sword",
        "formula": "additive",
        "rate": 1.25
    ]),
    ([
        "type":"attribute",
        "name": "strength",
        "formula": "subtractive",
        "rate": 0.25
    ]) });

    ExpectTrue(Effect.testAddInstantaneousSpecification("modifiers", modifiers));
}

/////////////////////////////////////////////////////////////////////////////
void CannotAddInvalidModifierSpecification()
{
    mapping modifier = ([
        "name": "long sword",
        "formula": "additive",
        "rate": 1.25
    ]);

    string err = catch (Effect.testAddInstantaneousSpecification("modifiers", ({ modifier })); nolog);
    string expectedError = "*ERROR - instantaneousEffect: the 'modifiers' specification must be a properly formatted modifier.\n";
    ExpectEq(expectedError, err);
}

/////////////////////////////////////////////////////////////////////////////
void CannotAddIncorrectModifierSpecification()
{
    string err = catch (Effect.testAddInstantaneousSpecification("modifiers", "blah"); nolog);
    string expectedError = "*ERROR - instantaneousEffect: the 'modifiers' specification must be a properly formatted modifier.\n";
    ExpectEq(expectedError, err);
}

/////////////////////////////////////////////////////////////////////////////
void CanAddDamageTypeSpecification()
{
    ExpectTrue(Effect.testAddInstantaneousSpecification("damage type", "fire"));
}

/////////////////////////////////////////////////////////////////////////////
void CannotAddInvalidDamageTypeSpecification()
{
    string err = catch (Effect.testAddInstantaneousSpecification("damage type", "turnip"); nolog);
    string expectedError = "*ERROR - instantaneousEffect: the 'damage type' specification must be a valid attack type as defined in attacksDictionary.\n";
    ExpectEq(expectedError, err);
}

/////////////////////////////////////////////////////////////////////////////
void CanApplyFormula()
{
    mapping *formula = ({ ([
        "probability": 100,
        "base damage": 50,
        "range": 0
    ]) });

    ExpectTrue(Effect.testAddInstantaneousSpecification("damage hit points", formula));
    ExpectEq(50, Effect.testApplyFormula(User, "damage hit points"));
}

/////////////////////////////////////////////////////////////////////////////
void CanApplyMultipleFormulas()
{
    mapping *formula = ({ ([
        "probability": 33,
        "base damage": 25,
        "range": 0
    ]),
    ([
        "probability": 33,
        "base damage": 25,
        "range": 0
    ]),
    ([
        "probability": 34,
        "custom method": "customFormula"
    ]) });

    ExpectTrue(Effect.testAddInstantaneousSpecification("damage spell points", formula));
    ExpectEq(25, Effect.testApplyFormula(User, "damage spell points"));
}

/////////////////////////////////////////////////////////////////////////////
void GetTargetReturnsFalseIfCommandDoesNotParse()
{
    ExpectFalse(Effect.testGetTarget(User, "flumfrug blibblefro"));
}

/////////////////////////////////////////////////////////////////////////////
void GetTargetReturnsFalseIfTargetDoesNotExist()
{
    Effect.addCommandTemplate("throw turnip at ##Target##");
    ExpectFalse(Effect.testGetTarget(User, "throw turnip at gertrude"));
}

/////////////////////////////////////////////////////////////////////////////
void GetTargetReturnsFalseIfTargetNotPresent()
{
    object room = clone_object("/lib/environment/environment");
    object victim = clone_object("/lib/tests/support/services/combatWithMockServices");
    victim.Name("Frank");
    victim.addAlias("frank");

    Effect.addCommandTemplate("throw turnip at ##Target##");
    ExpectFalse(Effect.testGetTarget(User, "throw turnip at frank"));
}

/////////////////////////////////////////////////////////////////////////////
void GetTargetReturnsValidTarget()
{
    object room = clone_object("/lib/environment/environment");
    object owner = clone_object("/lib/tests/support/services/combatWithMockServices");
    move_object(User, room);
    move_object(owner, room);

    Effect.addCommandTemplate("throw turnip at ##Target##");

    ExpectEq(User, Effect.testGetTarget(owner, "throw turnip at bob"));
}

/////////////////////////////////////////////////////////////////////////////
void GetTargetWithNoneSpecifiedReturnsUser()
{
    object room = clone_object("/lib/environment/environment");
    object owner = clone_object("/lib/tests/support/services/combatWithMockServices");
    move_object(User, room);
    move_object(owner, room);

    Effect.addCommandTemplate("throw turnip [at ##Target##]");

    ExpectEq(User, Effect.testGetTarget(owner, "throw turnip"));
}

/////////////////////////////////////////////////////////////////////////////
void GetTargetForDamageItemWithNoneSpecifiedReturnsNullIfNotInCombat()
{
    object room = clone_object("/lib/environment/environment");
    object owner = clone_object("/lib/tests/support/services/combatWithMockServices");
    move_object(User, room);
    move_object(owner, room);

    Effect.addCommandTemplate("throw turnip [at ##Target##]");
    Effect.testAddInstantaneousSpecification("damage type", "fire");
    ExpectEq(0, Effect.testGetTarget(owner, "throw turnip"));
}

/////////////////////////////////////////////////////////////////////////////
void GetTargetForDamageItemWithNoneSpecifiedReturnsAttackerInCombat()
{
    object room = clone_object("/lib/environment/environment");

    object victim = clone_object("/lib/tests/support/services/combatWithMockServices");
    victim.Name("Frank");
    victim.addAlias("frank");
    victim.Con(20);
    victim.hitPoints(victim.maxHitPoints());

    object owner = clone_object("/lib/tests/support/services/combatWithMockServices");
    owner.Con(20);
    owner.hitPoints(owner.maxHitPoints());
    move_object(victim, room);
    move_object(owner, room);

    owner.attack(victim);
    Effect.addCommandTemplate("throw turnip [at ##Target##]");
    Effect.testAddInstantaneousSpecification("damage type", "fire");
    ExpectEq(victim, Effect.testGetTarget(owner, "throw turnip"));
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteOnSelfDoesNotCallApplyEffect()
{
    Effect.ToggleApplyEffect();
    ExpectFalse(Effect.testExecuteOnSelf("command", User, program_name(Effect)));
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteOnSelfCallsApplyBeneficialEffect()
{
    Effect.ToggleBeneficialEffect();
    ExpectTrue(Effect.testExecuteOnSelf("command", User, program_name(Effect)));
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteOnTargetMustHaveAValidTarget()
{
    object room = clone_object("/lib/environment/environment");
    object owner = clone_object("/lib/tests/support/services/combatWithMockServices");
    move_object(owner, room);

    Effect.ToggleApplyEffect();
    Effect.addCommandTemplate("throw turnip at ##Target##");

    ExpectFalse(Effect.testExecuteOnTarget("blarg flargleblarg", owner, program_name(Effect)), "invalid command sent");
    ExpectFalse(Effect.testExecuteOnTarget("throw turnip at bob", owner, program_name(Effect)), "bob is not present");

    move_object(User, room);
    ExpectTrue(Effect.testExecuteOnTarget("throw turnip at bob", owner, program_name(Effect)), "bob is present");
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteInAreaCallsApplyEffect()
{
    object room = clone_object("/lib/environment/environment");
    object creature = clone_object("/lib/tests/support/services/combatWithMockServices");
    move_object(creature, room);

    creature = clone_object("/lib/tests/support/services/combatWithMockServices");
    move_object(creature, room);

    move_object(User, room);

    ExpectEq(1, Effect.testExecuteInArea("command", User, program_name(Effect)));
    Effect.ToggleApplyEffect();
    ExpectEq(3, Effect.testExecuteInArea("command", User, program_name(Effect)));
}
