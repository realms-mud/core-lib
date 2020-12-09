//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";
#include "/lib/include/inventory.h"

object Effect;
object User;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Effect = clone_object("/lib/tests/support/research/testCombinedInstantaneousEffect");

    User = clone_object("/lib/tests/support/services/mockPlayer.c");
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

    ExpectTrue(Effect->testAddInstantaneousSpecification("damage hit points", ({ formula })));
}

/////////////////////////////////////////////////////////////////////////////
void CanAddDamageSpellPointsSpecification()
{
    mapping formula = ([
        "probability": 100,
        "base damage": 25,
        "range": 25
    ]);

    ExpectTrue(Effect->testAddInstantaneousSpecification("damage spell points", ({ formula })));
}

/////////////////////////////////////////////////////////////////////////////
void CanAddDamageStaminaPointsSpecification()
{
    mapping formula = ([
        "probability": 100,
        "base damage": 25,
        "range": 25
    ]);

    ExpectTrue(Effect->testAddInstantaneousSpecification("damage stamina points", ({ formula })));
}

/////////////////////////////////////////////////////////////////////////////
void CanAddIncreaseHitPointsSpecification()
{
    mapping formula = ([
        "probability": 100,
        "base damage": 25,
        "range": 25
    ]);

    ExpectTrue(Effect->testAddInstantaneousSpecification("increase hit points", ({ formula })));
}

/////////////////////////////////////////////////////////////////////////////
void CanAddIncreaseSpellPointsSpecification()
{
    mapping formula = ([
        "probability": 100,
        "base damage": 25,
        "range": 25
    ]);

    ExpectTrue(Effect->testAddInstantaneousSpecification("increase spell points", ({ formula })));
}

/////////////////////////////////////////////////////////////////////////////
void CanAddIncreaseStaminaPointsSpecification()
{
    mapping formula = ([
        "probability": 100,
        "base damage": 25,
        "range": 25
    ]);

    ExpectTrue(Effect->testAddInstantaneousSpecification("increase stamina points", ({ formula })));
}

/////////////////////////////////////////////////////////////////////////////
void CanAddIncreaseIntoxicationSpecification()
{
    mapping formula = ([
        "probability": 100,
        "base damage": 25,
        "range": 25
    ]);

    ExpectTrue(Effect->testAddInstantaneousSpecification("increase intoxication", ({ formula })));
}

/////////////////////////////////////////////////////////////////////////////
void CanAddIncreaseDruggednessSpecification()
{
    mapping formula = ([
        "probability": 100,
        "base damage": 25,
        "range": 25
    ]);

    ExpectTrue(Effect->testAddInstantaneousSpecification("increase druggedness", ({ formula })));
}

/////////////////////////////////////////////////////////////////////////////
void CanAddIncreaseSoakedSpecification()
{
    mapping formula = ([
        "probability": 100,
        "base damage": 25,
        "range": 25
    ]);

    ExpectTrue(Effect->testAddInstantaneousSpecification("increase soaked", ({ formula })));
}

/////////////////////////////////////////////////////////////////////////////
void CanAddIncreaseStuffedSpecification()
{
    mapping formula = ([
        "probability": 100,
        "base damage": 25,
        "range": 25
    ]);

    ExpectTrue(Effect->testAddInstantaneousSpecification("increase stuffed", ({ formula })));
}

/////////////////////////////////////////////////////////////////////////////
void CanAddDecreaseIntoxicationSpecification()
{
    mapping formula = ([
        "probability":100,
            "base damage" : 25,
            "range" : 25
    ]);

    ExpectTrue(Effect->testAddInstantaneousSpecification("decrease intoxication", ({ formula })));
}

/////////////////////////////////////////////////////////////////////////////
void CanAddDecreaseDruggednessSpecification()
{
    mapping formula = ([
        "probability":100,
            "base damage" : 25,
            "range" : 25
    ]);

    ExpectTrue(Effect->testAddInstantaneousSpecification("decrease druggedness", ({ formula })));
}

/////////////////////////////////////////////////////////////////////////////
void CanAddDecreaseSoakedSpecification()
{
    mapping formula = ([
        "probability":100,
            "base damage" : 25,
            "range" : 25
    ]);

    ExpectTrue(Effect->testAddInstantaneousSpecification("decrease soaked", ({ formula })));
}

/////////////////////////////////////////////////////////////////////////////
void CanAddDecreaseStuffedSpecification()
{
    mapping formula = ([
        "probability":100,
            "base damage" : 25,
            "range" : 25
    ]);

    ExpectTrue(Effect->testAddInstantaneousSpecification("decrease stuffed", ({ formula })));
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

    ExpectTrue(Effect->testAddInstantaneousSpecification("damage hit points", formula));
}

/////////////////////////////////////////////////////////////////////////////
void CannotAddFormulasThatAreLessThan100PercentProbability()
{
    mapping formula = ([
        "probability": 50,
        "base damage": 25,
        "range": 25
    ]);

    string err = catch (Effect->testAddInstantaneousSpecification("damage hit points", ({ formula })));
    string expectedError = "*ERROR - combinedInstantaneousEffect: the 'damage hit points' specification must be a properly formatted formula.\n";
    ExpectEq(expectedError, err);
}

/////////////////////////////////////////////////////////////////////////////
void CannotAddFormulasWithCustomMethodsThatDoNotExist()
{
    mapping formula = ([
        "probability":100,
        "custom method": "thisMethodDoesNotExist"
    ]);

    string err = catch (Effect->testAddInstantaneousSpecification("damage hit points", ({ formula })));
    string expectedError = "*ERROR - combinedInstantaneousEffect: the 'damage hit points' specification must be a properly formatted formula.\n";
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

    ExpectTrue(Effect->testAddInstantaneousSpecification("modifiers", modifiers));
}

/////////////////////////////////////////////////////////////////////////////
void CannotAddInvalidModifierSpecification()
{
    mapping modifier = ([
        "name": "long sword",
        "formula": "additive",
        "rate": 1.25
    ]);

    string err = catch (Effect->testAddInstantaneousSpecification("modifiers", ({ modifier })));
    string expectedError = "*ERROR - combinedInstantaneousEffect: the 'modifiers' specification must be a properly formatted modifier.\n";
    ExpectEq(expectedError, err);
}

/////////////////////////////////////////////////////////////////////////////
void CannotAddIncorrectModifierSpecification()
{
    string err = catch (Effect->testAddInstantaneousSpecification("modifiers", "blah"));
    string expectedError = "*ERROR - combinedInstantaneousEffect: the 'modifiers' specification must be a properly formatted modifier.\n";
    ExpectEq(expectedError, err);
}

/////////////////////////////////////////////////////////////////////////////
void CanAddDamageTypeSpecification()
{
    ExpectTrue(Effect->testAddInstantaneousSpecification("damage type", "fire"));
}

/////////////////////////////////////////////////////////////////////////////
void CannotAddInvalidDamageTypeSpecification()
{
    string err = catch (Effect->testAddInstantaneousSpecification("damage type", "turnip"));
    string expectedError = "*ERROR - combinedInstantaneousEffect: the 'damage type' specification must be a valid attack type as defined in attacksDictionary.\n";
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

    ExpectTrue(Effect->testAddInstantaneousSpecification("damage hit points", formula));
    ExpectEq(50, Effect->testApplyFormula(User, 0, "damage hit points"));
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

    ExpectTrue(Effect->testAddInstantaneousSpecification("damage spell points", formula));
    ExpectEq(25, Effect->testApplyFormula(User, 0, "damage spell points"));
}

/////////////////////////////////////////////////////////////////////////////
void CanAddMaximumCombinationChainSpecification()
{
    ExpectTrue(
        Effect->testAddInstantaneousSpecification("maximum combination chain", 2));
}

/////////////////////////////////////////////////////////////////////////////
void CannotAddInvalidMaximumCombinationChainSpecification()
{
    string err = catch (
        Effect->testAddInstantaneousSpecification("maximum combination chain", -1));
    string expectedError = "*ERROR - combinedInstantaneousEffect: the "
        "'maximum combination chain' specification must be a "
        "positive integer.\n";
    ExpectEq(expectedError, err);
}

/////////////////////////////////////////////////////////////////////////////
void CanAddMaxCombinationChainModifierSpecification()
{
    mapping *modifiers = ({ ([
        "type":"skill",
        "name" : "long sword",
        "formula" : "additive",
        "rate" : 1.25
    ]),
    ([
        "type":"attribute",
        "name" : "strength",
        "formula" : "subtractive",
        "rate" : 0.25
    ]) });

    ExpectTrue(Effect->testAddInstantaneousSpecification("max combination chain modifier", modifiers));
}

/////////////////////////////////////////////////////////////////////////////
void CannotAddInvalidMaxCombinationChainModifierSpecification()
{
    mapping modifier = ([
        "name": "long sword",
        "formula": "additive",
        "rate": 1.25
    ]);

    string err = catch (Effect->testAddInstantaneousSpecification("modifiers", ({ modifier })));
    string expectedError = "*ERROR - combinedInstantaneousEffect: the 'modifiers' specification must be a properly formatted modifier.\n";
    ExpectEq(expectedError, err);
}

/////////////////////////////////////////////////////////////////////////////
void CanAddCombinationRulesSpecification()
{
    mapping rules = ([
        "must include only one of": ({ 
            "lib/tests/support/research/comboPartResearchItemA.c",
            "lib/tests/support/research/comboPartResearchItemB.c", }),
        "must include any of": ({ 
            "lib/tests/support/research/comboPartResearchItemC.c",
            "lib/tests/support/research/comboPartResearchItemD.c", }),
        "can include only one of": ({ 
            "lib/tests/support/research/comboPartResearchItemE.c",
            "lib/tests/support/research/comboPartResearchItemF.c", }),
        "can include any of": ({ 
            "lib/tests/support/research/comboPartResearchItemG.c",
            "lib/tests/support/research/comboPartResearchItemH.c", }),
    ]);

    ExpectTrue(Effect->testAddInstantaneousSpecification("combination rules", rules));
}

/////////////////////////////////////////////////////////////////////////////
void CannotAddSameCombinationItemsToMultipleScopesSpecification()
{
    mapping rules = ([
        "must include only one of": ({ 
            "lib/tests/support/research/comboPartResearchItemA.c",
            "lib/tests/support/research/comboPartResearchItemB.c", }),
        "must include any of": ({ 
            "lib/tests/support/research/comboPartResearchItemA.c",
            "lib/tests/support/research/comboPartResearchItemD.c", }),
        "can include only one of": ({ 
            "lib/tests/support/research/comboPartResearchItemE.c",
            "lib/tests/support/research/comboPartResearchItemF.c", }),
        "can include any of": ({ 
            "lib/tests/support/research/comboPartResearchItemG.c",
            "lib/tests/support/research/comboPartResearchItemH.c", }),
    ]);

    string err = catch (Effect->testAddInstantaneousSpecification("combination rules", rules));
    string expectedError = "ERROR - combinedInstantaneousEffect: items "
        ".lib/tests/support/research/comboPartResearchItemA.c. can only be "
        "placed once in only one of 'must include only";
    ExpectSubStringMatch(expectedError, err);
}

/////////////////////////////////////////////////////////////////////////////
void CannotAddInvalidCombinationItemsSpecification()
{
    mapping rules = ([
        "must include only one of": ({ 
            "lib/tests/support/research/comboPartResearchItemA.c",
            "lib/tests/support/research/comboPartResearchItemB.c", }),
        "breaking junk": "stuff"
    ]);

    string err = catch (Effect->testAddInstantaneousSpecification("combination rules", rules));
    string expectedError = "*ERROR - combinedInstantaneousEffect: the "
        "'combination rules' specification must be a valid rule set.\n";
    ExpectEq(expectedError, err);
}

/////////////////////////////////////////////////////////////////////////////
void GetCombinationListReturnsValidList()
{
    User->addResearchPoints(50);
    User->initiateResearch("lib/tests/support/research/comboPartResearchItemA.c");
    User->initiateResearch("lib/tests/support/research/comboPartResearchItemB.c");
    User->initiateResearch("lib/tests/support/research/comboPartResearchItemC.c");
    User->initiateResearch("lib/tests/support/research/comboPartResearchItemD.c");
    User->initiateResearch("lib/tests/support/research/comboPartResearchItemE.c");
    User->initiateResearch("lib/tests/support/research/comboPartResearchItemF.c");
    User->initiateResearch("lib/tests/support/research/comboPartResearchItemG.c");
    User->initiateResearch("lib/tests/support/research/comboPartResearchItemH.c");

    mapping rules = ([
        "must include only one of": ({ 
            "lib/tests/support/research/comboPartResearchItemA.c",
            "lib/tests/support/research/comboPartResearchItemB.c", }),
        "must include any of": ({ 
            "lib/tests/support/research/comboPartResearchItemC.c",
            "lib/tests/support/research/comboPartResearchItemD.c", }),
        "can include only one of": ({ 
            "lib/tests/support/research/comboPartResearchItemE.c",
            "lib/tests/support/research/comboPartResearchItemF.c", }),
        "can include any of": ({ 
            "lib/tests/support/research/comboPartResearchItemG.c",
            "lib/tests/support/research/comboPartResearchItemH.c", }),
    ]);

    Effect->testAddInstantaneousSpecification("maximum combination chain", 3);
    Effect->testAddInstantaneousSpecification("combination rules", rules);

    ExpectEq(({"lib/tests/support/research/comboPartResearchItemA.c",
        "lib/tests/support/research/comboPartResearchItemD.c",
        "lib/tests/support/research/comboPartResearchItemF.c" }), 
        Effect->testGetCombinationList("combination blarg frumbus clerb",
        User));
}
