//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
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
    User.colorConfiguration("none");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(User);
    destruct(Effect);
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
    string expectedError = "*ERROR - combinedInstantaneousEffect: the 'modifiers' specification must be a properly formatted modifier.\n";
    ExpectEq(expectedError, err);
}

/////////////////////////////////////////////////////////////////////////////
void CannotAddIncorrectModifierSpecification()
{
    string err = catch (Effect.testAddInstantaneousSpecification("modifiers", "blah"); nolog);
    string expectedError = "*ERROR - combinedInstantaneousEffect: the 'modifiers' specification must be a properly formatted modifier.\n";
    ExpectEq(expectedError, err);
}

/////////////////////////////////////////////////////////////////////////////
void CanAddMaximumCombinationChainSpecification()
{
    ExpectTrue(
        Effect.testAddInstantaneousSpecification("maximum combination chain", 2));
}

/////////////////////////////////////////////////////////////////////////////
void CannotAddInvalidMaximumCombinationChainSpecification()
{
    string err = catch (
        Effect.testAddInstantaneousSpecification("maximum combination chain", -1); nolog);
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

    ExpectTrue(Effect.testAddInstantaneousSpecification("max combination chain modifier", modifiers));
}

/////////////////////////////////////////////////////////////////////////////
void CannotAddInvalidMaxCombinationChainModifierSpecification()
{
    mapping modifier = ([
        "name": "long sword",
        "formula": "additive",
        "rate": 1.25
    ]);

    string err = catch (Effect.testAddInstantaneousSpecification("modifiers", ({ modifier })); nolog);
    string expectedError = "*ERROR - combinedInstantaneousEffect: the 'modifiers' specification must be a properly formatted modifier.\n";
    ExpectEq(expectedError, err);
}

/////////////////////////////////////////////////////////////////////////////
void CanAddCombinationRulesSpecification()
{
    mapping rules = ([
        "must include only one of": ({ 
            "/lib/tests/support/research/comboPartResearchItemA.c",
            "/lib/tests/support/research/comboPartResearchItemB.c", }),
        "must include any of": ({ 
            "/lib/tests/support/research/comboPartResearchItemC.c",
            "/lib/tests/support/research/comboPartResearchItemD.c", }),
        "can include only one of": ({ 
            "/lib/tests/support/research/comboPartResearchItemE.c",
            "/lib/tests/support/research/comboPartResearchItemF.c", }),
        "can include any of": ({ 
            "/lib/tests/support/research/comboPartResearchItemG.c",
            "/lib/tests/support/research/comboPartResearchItemH.c", }),
    ]);

    ExpectTrue(Effect.testAddInstantaneousSpecification("combination rules", rules));
}

/////////////////////////////////////////////////////////////////////////////
void CannotAddSameCombinationItemsToMultipleScopesSpecification()
{
    mapping rules = ([
        "must include only one of": ({ 
            "/lib/tests/support/research/comboPartResearchItemA.c",
            "/lib/tests/support/research/comboPartResearchItemB.c", }),
        "must include any of": ({ 
            "/lib/tests/support/research/comboPartResearchItemA.c",
            "/lib/tests/support/research/comboPartResearchItemD.c", }),
        "can include only one of": ({ 
            "/lib/tests/support/research/comboPartResearchItemE.c",
            "/lib/tests/support/research/comboPartResearchItemF.c", }),
        "can include any of": ({ 
            "/lib/tests/support/research/comboPartResearchItemG.c",
            "/lib/tests/support/research/comboPartResearchItemH.c", }),
    ]);

    string err = catch (Effect.testAddInstantaneousSpecification("combination rules", rules); nolog);
    string expectedError = "ERROR - combinedInstantaneousEffect: items "
        "./lib/tests/support/research/comboPartResearchItemA.c. can only be "
        "placed once in only one of 'must include only";
    ExpectSubStringMatch(expectedError, err);
}

/////////////////////////////////////////////////////////////////////////////
void CannotAddInvalidCombinationItemsSpecification()
{
    mapping rules = ([
        "must include only one of": ({ 
            "/lib/tests/support/research/comboPartResearchItemA.c",
            "/lib/tests/support/research/comboPartResearchItemB.c", }),
        "breaking junk": "stuff"
    ]);

    string err = catch (Effect.testAddInstantaneousSpecification("combination rules", rules); nolog);
    string expectedError = "*ERROR - combinedInstantaneousEffect: the "
        "'combination rules' specification must be a valid rule set.\n";
    ExpectEq(expectedError, err);
}

/////////////////////////////////////////////////////////////////////////////
void CannotAddCommandTemplateBeforeCombinationRulesAreSet()
{
    string err = catch (
        Effect.testAddInstantaneousSpecification("command template", 
            "do stuff ##Combinations## [at ##Target##]"); nolog);

    string expectedError = "*ERROR - combinedInstantaneousEffect: the "
        "'combination rules' specification must be set before a command "
        "template is created.\n";
    ExpectEq(expectedError, err);
}

/////////////////////////////////////////////////////////////////////////////
void CannotAddCommandTemplateWithoutCombinationsKeyword()
{
    string err = catch (
        Effect.testAddInstantaneousSpecification("command template", 
            "do stuff [at ##Target##]"); nolog);

    string expectedError = "*ERROR - combinedInstantaneousEffect: the "
        "'command template' specification must include the ##Combinations## "
        "macro.\n";
    ExpectEq(expectedError, err);
}

/////////////////////////////////////////////////////////////////////////////
void CanAddCommandTemplate()
{
    mapping rules = ([
        "must include only one of": ({ 
            "/lib/tests/support/research/comboPartResearchItemA.c",
            "/lib/tests/support/research/comboPartResearchItemB.c", }),
        "can include any of": ({ 
            "/lib/tests/support/research/comboPartResearchItemG.c",
            "/lib/tests/support/research/comboPartResearchItemH.c", }),
    ]);

    Effect.testAddInstantaneousSpecification("combination rules", rules);
    Effect.testAddInstantaneousSpecification("command template",
        "do stuff ##Combinations## [at ##Target##]");

    ExpectEq("do stuff", Effect.query("command name"));
    ExpectEq("at (.+)", Effect.query("command target"));
    ExpectEq("((blarg *|hruf *|muclid *|rarg *)+)", 
        Effect.query("command combinations"));
}

/////////////////////////////////////////////////////////////////////////////
void GetCombinationListReturnsValidList()
{
    User.addResearchPoints(50);
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemA.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemB.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemC.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemD.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemE.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemF.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemG.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemH.c");

    mapping rules = ([
        "must include only one of": ({ 
            "/lib/tests/support/research/comboPartResearchItemA.c",
            "/lib/tests/support/research/comboPartResearchItemB.c", }),
        "must include any of": ({ 
            "/lib/tests/support/research/comboPartResearchItemC.c",
            "/lib/tests/support/research/comboPartResearchItemD.c", }),
        "can include only one of": ({ 
            "/lib/tests/support/research/comboPartResearchItemE.c",
            "/lib/tests/support/research/comboPartResearchItemF.c", }),
        "can include any of": ({ 
            "/lib/tests/support/research/comboPartResearchItemG.c",
            "/lib/tests/support/research/comboPartResearchItemH.c", }),
    ]);

    Effect.testAddInstantaneousSpecification("maximum combination chain", 3);
    Effect.testAddInstantaneousSpecification("combination rules", rules);
    Effect.testAddInstantaneousSpecification("command template", "combination ##Combinations## [at ##Target##]");

    ExpectEq(({"/lib/tests/support/research/comboPartResearchItemA.c",
        "/lib/tests/support/research/comboPartResearchItemD.c",
        "/lib/tests/support/research/comboPartResearchItemF.c" }), 
        Effect.testGetCombinationList("combination blarg frumbus clerb at frank",
        User));
}

/////////////////////////////////////////////////////////////////////////////
void GetCombinationListCanGetMultipleOfTheSameItem()
{
    User.addResearchPoints(50);
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemA.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemB.c");

    mapping rules = ([
        "must include only one of": ({ 
            "/lib/tests/support/research/comboPartResearchItemA.c",
            "/lib/tests/support/research/comboPartResearchItemB.c", }),
    ]);

    Effect.testAddInstantaneousSpecification("maximum combination chain", 3);
    Effect.testAddInstantaneousSpecification("combination rules", rules);
    Effect.testAddInstantaneousSpecification("command template", "combination ##Combinations## [at ##Target##]");

    ExpectEq(({ "/lib/tests/support/research/comboPartResearchItemA.c",
        "/lib/tests/support/research/comboPartResearchItemA.c" }),
        Effect.testGetCombinationList("combination blarg blarg",
        User));
}

/////////////////////////////////////////////////////////////////////////////
void GetCombinationListReturnsFailureWhenItemsNotResearched()
{
    mapping rules = ([
        "must include only one of": ({ 
            "/lib/tests/support/research/comboPartResearchItemA.c",
            "/lib/tests/support/research/comboPartResearchItemB.c", }),
        "must include any of": ({ 
            "/lib/tests/support/research/comboPartResearchItemC.c",
            "/lib/tests/support/research/comboPartResearchItemD.c", }),
        "can include only one of": ({ 
            "/lib/tests/support/research/comboPartResearchItemE.c",
            "/lib/tests/support/research/comboPartResearchItemF.c", }),
        "can include any of": ({ 
            "/lib/tests/support/research/comboPartResearchItemG.c",
            "/lib/tests/support/research/comboPartResearchItemH.c", }),
    ]);

    Effect.testAddInstantaneousSpecification("maximum combination chain", 3);
    Effect.testAddInstantaneousSpecification("combination rules", rules);
    Effect.testAddInstantaneousSpecification("command template", "combination ##Combinations## [at ##Target##]");

    ExpectEq(0, 
        Effect.testGetCombinationList("combination blarg frumbus clerb",
        User));
    ExpectEq("That is an invalid combination. You do not have the following "
        "researched:\nblarg, clerb, and frumbus.\n", User.caughtMessage());

    User.addResearchPoints(50);
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemA.c");

    ExpectEq(0, 
        Effect.testGetCombinationList("combination blarg frumbus clerb",
        User));
    ExpectEq("That is an invalid combination. You do not have the following "
        "researched:\nclerb and frumbus.\n", User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void GetCombinationListFailsWhenMustIncludeOnlyOneOfRuleIsViolated()
{
    User.addResearchPoints(50);
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemA.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemB.c");

    mapping rules = ([
        "must include only one of": ({ 
            "/lib/tests/support/research/comboPartResearchItemA.c",
            "/lib/tests/support/research/comboPartResearchItemB.c", }),
        "can include any of": ({ 
            "/lib/tests/support/research/comboPartResearchItemG.c",
            "/lib/tests/support/research/comboPartResearchItemH.c", }),
    ]);

    Effect.testAddInstantaneousSpecification("maximum combination chain", 3);
    Effect.testAddInstantaneousSpecification("combination rules", rules);
    Effect.testAddInstantaneousSpecification("command template", "combination ##Combinations## [at ##Target##]");

    ExpectEq(0,
        Effect.testGetCombinationList("combination hruf muclid",
            User));
    ExpectEq("That is an invalid combination. You must use exactly one of: "
        "blarg or rarg.\n", User.caughtMessage());

    ExpectEq(0, 
        Effect.testGetCombinationList("combination blarg rarg",
        User));
    ExpectEq("That is an invalid combination. You must use exactly one of: "
        "blarg or rarg.\n", User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void GetCombinationListFailsWhenCanIncludeOnlyOneOfRuleIsViolated()
{
    User.addResearchPoints(50);
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemA.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemB.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemE.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemF.c");

    mapping rules = ([
        "must include only one of": ({ 
            "/lib/tests/support/research/comboPartResearchItemA.c",
            "/lib/tests/support/research/comboPartResearchItemB.c", }),
        "can include only one of": ({ 
            "/lib/tests/support/research/comboPartResearchItemE.c",
            "/lib/tests/support/research/comboPartResearchItemF.c", }),
    ]);

    Effect.testAddInstantaneousSpecification("maximum combination chain", 3);
    Effect.testAddInstantaneousSpecification("combination rules", rules);
    Effect.testAddInstantaneousSpecification("command template", "combination ##Combinations## [at ##Target##]");

    ExpectEq(({ "/lib/tests/support/research/comboPartResearchItemA.c",
        "/lib/tests/support/research/comboPartResearchItemE.c" }),
        Effect.testGetCombinationList("combination blarg surlac",
        User));

    ExpectEq(0, 
        Effect.testGetCombinationList("combination blarg surlac clerb",
        User));
    ExpectEq("That is an invalid combination. You can only use one of: "
        "clerb or surlac.\n", User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void GetCombinationListFailsWhenMustIncludeAnyOfRuleIsViolated()
{
    User.addResearchPoints(50);
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemA.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemB.c");

    mapping rules = ([
        "must include any of": ({ 
            "/lib/tests/support/research/comboPartResearchItemA.c",
            "/lib/tests/support/research/comboPartResearchItemB.c", }),
    ]);

    Effect.testAddInstantaneousSpecification("maximum combination chain", 3);
    Effect.testAddInstantaneousSpecification("combination rules", rules);
    Effect.testAddInstantaneousSpecification("command template", "combination ##Combinations## [at ##Target##]");

    ExpectEq(0, 
        Effect.testGetCombinationList("combination frumbus clerb",
        User));
    ExpectEq("That is an invalid combination. You must use at least one of: "
        "blarg or rarg.\n", User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanOnlyExecuteCombinationsOfValidSizes()
{
    User.addResearchPoints(50);
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemA.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemB.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemC.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemD.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemE.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemF.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemG.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemH.c");

    mapping rules = ([
        "must include only one of": ({ 
            "/lib/tests/support/research/comboPartResearchItemA.c",
            "/lib/tests/support/research/comboPartResearchItemB.c", }),
        "must include any of": ({ 
            "/lib/tests/support/research/comboPartResearchItemC.c",
            "/lib/tests/support/research/comboPartResearchItemD.c", }),
        "can include only one of": ({ 
            "/lib/tests/support/research/comboPartResearchItemE.c",
            "/lib/tests/support/research/comboPartResearchItemF.c", }),
        "can include any of": ({ 
            "/lib/tests/support/research/comboPartResearchItemG.c",
            "/lib/tests/support/research/comboPartResearchItemH.c", }),
    ]);

    Effect.testAddInstantaneousSpecification("maximum combination chain", 3);
    Effect.testAddInstantaneousSpecification("combination rules", rules);
    Effect.testAddInstantaneousSpecification("command template", "combination ##Combinations## [at ##Target##]");

    ExpectEq(0, sizeof(Effect.testGetCombinationList("combination frumbus", User)));
    ExpectEq("That is an invalid combination. You can "
            "only chain 2 to 3 actions together.\n", User.caughtMessage());

    ExpectEq(2, sizeof(Effect.testGetCombinationList("combination blarg frumbus at frank", User)));
    ExpectEq(3, sizeof(Effect.testGetCombinationList("combination blarg frumbus clerb", User)));

    ExpectEq(0, sizeof(Effect.testGetCombinationList("combination blarg frumbus hruf clerb", User)));
    ExpectEq("That is an invalid combination. You can "
        "only chain 2 to 3 actions together.\n", User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ApplyAllFormulasAppliesAllResearchFormulasAndCombinationModifiers()
{
    User.addResearchPoints(50);
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemA.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemB.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemC.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemD.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemE.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemF.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemG.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemH.c");

    mapping rules = ([
        "must include only one of": ({ 
            "/lib/tests/support/research/comboPartResearchItemA.c",
            "/lib/tests/support/research/comboPartResearchItemB.c", }),
        "must include any of": ({ 
            "/lib/tests/support/research/comboPartResearchItemC.c",
            "/lib/tests/support/research/comboPartResearchItemD.c", }),
        "can include only one of": ({ 
            "/lib/tests/support/research/comboPartResearchItemE.c",
            "/lib/tests/support/research/comboPartResearchItemF.c", }),
        "can include any of": ({ 
            "/lib/tests/support/research/comboPartResearchItemG.c", }),
    ]);

    Effect.testAddInstantaneousSpecification("maximum combination chain", 3);
    Effect.testAddInstantaneousSpecification("combination rules", rules);
    Effect.testAddInstantaneousSpecification("command template", "combination ##Combinations## [at ##Target##]");

    Effect.testAddInstantaneousSpecification("modifiers", ({ ([
        "type": "research",
        "research item": "/lib/tests/support/research/comboPartResearchItemH.c",
        "name": "Combo stuff",
        "formula": "multiplicative",
        "base value": 1,
        "rate": 1.5
     ]) }));
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemH.c");

    ExpectEq(93, Effect.testApplyAllFormulas(({
        load_object("/lib/tests/support/research/comboPartResearchItemA.c"),
        load_object("/lib/tests/support/research/comboPartResearchItemD.c"),
        load_object("/lib/tests/support/research/comboPartResearchItemE.c") }),
        User, "damage hit points"));
}
