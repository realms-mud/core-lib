//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object ResearchItem;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    ResearchItem = clone_object("/lib/tests/support/research/testConstructedResearchComponent");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(ResearchItem);
}

/////////////////////////////////////////////////////////////////////////////
void TypeIsConstructed()
{
    ExpectEq("constructed", ResearchItem.query("type"), "query the research type");
}

/////////////////////////////////////////////////////////////////////////////
void EffectIsStrategic()
{
    ExpectEq("strategic", ResearchItem.query("effect"), "query the research effect");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetValidAdditionalHitPointCost()
{
    ExpectTrue(ResearchItem.testAddSpecification("additional hit point cost", 20),
        "add additional hit point cost specification");
    ExpectEq(20, ResearchItem.query("additional hit point cost"),
        "can query the additional hit point cost");
}

/////////////////////////////////////////////////////////////////////////////
void SettingInvalidAdditionalHitPointCostThrowsError()
{
    string err = catch (ResearchItem.testAddSpecification("additional hit point cost", "blah"); nolog);
    string expectedError = "*ERROR - constructedResearchComponent: the 'additional hit point cost' specification must be an integer greater than 0.\n";

    ExpectEq(expectedError, err, "The correct exception is thrown when setting invalid value");
}

/////////////////////////////////////////////////////////////////////////////
void SettingZeroAdditionalHitPointCostThrowsError()
{
    string err = catch (ResearchItem.testAddSpecification("additional hit point cost", 0); nolog);
    string expectedError = "*ERROR - constructedResearchComponent: the 'additional hit point cost' specification must be an integer greater than 0.\n";

    ExpectEq(expectedError, err, "The correct exception is thrown when setting zero value");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetValidAdditionalSpellPointCost()
{
    ExpectTrue(ResearchItem.testAddSpecification("additional spell point cost", 25),
        "add additional spell point cost specification");
    ExpectEq(25, ResearchItem.query("additional spell point cost"),
        "can query the additional spell point cost");
}

/////////////////////////////////////////////////////////////////////////////
void SettingInvalidAdditionalSpellPointCostThrowsError()
{
    string err = catch (ResearchItem.testAddSpecification("additional spell point cost", "blah"); nolog);
    string expectedError = "*ERROR - constructedResearchComponent: the 'additional spell point cost' specification must be an integer greater than 0.\n";

    ExpectEq(expectedError, err, "The correct exception is thrown when setting invalid value");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetValidAdditionalStaminaPointCost()
{
    ExpectTrue(ResearchItem.testAddSpecification("additional stamina point cost", 15),
        "add additional stamina point cost specification");
    ExpectEq(15, ResearchItem.query("additional stamina point cost"),
        "can query the additional stamina point cost");
}

/////////////////////////////////////////////////////////////////////////////
void SettingInvalidAdditionalStaminaPointCostThrowsError()
{
    string err = catch (ResearchItem.testAddSpecification("additional stamina point cost", -5); nolog);
    string expectedError = "*ERROR - constructedResearchComponent: the 'additional stamina point cost' specification must be an integer greater than 0.\n";

    ExpectEq(expectedError, err, "The correct exception is thrown when setting invalid value");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetValidAdditionalCooldown()
{
    ExpectTrue(ResearchItem.testAddSpecification("additional cooldown", 10),
        "add additional cooldown specification");
    ExpectEq(10, ResearchItem.query("additional cooldown"),
        "can query the additional cooldown");
}

/////////////////////////////////////////////////////////////////////////////
void SettingInvalidAdditionalCooldownThrowsError()
{
    string err = catch (ResearchItem.testAddSpecification("additional cooldown", "fast"); nolog);
    string expectedError = "*ERROR - constructedResearchComponent: the 'additional cooldown' specification must be an integer greater than 0.\n";

    ExpectEq(expectedError, err, "The correct exception is thrown when setting invalid value");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetValidAdditionalRepeatEffect()
{
    ExpectTrue(ResearchItem.testAddSpecification("additional repeat effect", 3),
        "add additional repeat effect specification");
    ExpectEq(3, ResearchItem.query("additional repeat effect"),
        "can query the additional repeat effect");
}

/////////////////////////////////////////////////////////////////////////////
void SettingInvalidAdditionalRepeatEffectThrowsError()
{
    string err = catch (ResearchItem.testAddSpecification("additional repeat effect", 0); nolog);
    string expectedError = "*ERROR - constructedResearchComponent: the 'additional repeat effect' specification must be an integer greater than 0.\n";

    ExpectEq(expectedError, err, "The correct exception is thrown when setting invalid value");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetValidDamageType()
{
    ExpectTrue(ResearchItem.testAddSpecification("damage type", "fire"),
        "add damage type specification");
    ExpectEq("fire", ResearchItem.query("damage type"),
        "can query the damage type");
}

/////////////////////////////////////////////////////////////////////////////
void SettingInvalidDamageTypeThrowsError()
{
    string err = catch (ResearchItem.testAddSpecification("damage type", "invalid"); nolog);
    string expectedError = "*ERROR - constructedResearchComponent: the 'damage type' specification must be a valid attack type as defined in attacksService.\n";

    ExpectEq(expectedError, err, "The correct exception is thrown when setting invalid value");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetValidUseCombinationMessage()
{
    ExpectTrue(ResearchItem.testAddSpecification("use combination message",
        "##Infinitive::fire## a bolt at ##TargetName##"),
        "add use combination message specification");
    ExpectEq("##Infinitive::fire## a bolt at ##TargetName##",
        ResearchItem.query("use combination message"),
        "can query the use combination message");
}

/////////////////////////////////////////////////////////////////////////////
void SettingInvalidUseCombinationMessageThrowsError()
{
    string err = catch (ResearchItem.testAddSpecification("use combination message", 123); nolog);
    string expectedError = "*ERROR - constructedResearchComponent: the 'use combination message' specification must be a string.\n";

    ExpectEq(expectedError, err, "The correct exception is thrown when setting invalid value");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetValidRelatedResearch()
{
    ExpectTrue(ResearchItem.testAddSpecification("related research",
        ({ "/lib/tests/support/research/testGrantedResearchItem.c" })),
        "add related research specification");
    ExpectEq(({ "/lib/tests/support/research/testGrantedResearchItem.c" }),
        ResearchItem.query("related research"),
        "can query the related research");
}

/////////////////////////////////////////////////////////////////////////////
void SettingInvalidRelatedResearchThrowsError()
{
    string err = catch (ResearchItem.testAddSpecification("related research", "not an array"); nolog);
    string expectedError = "*ERROR - knowledgeResearchItem: the 'related research' specification must be a list of related research.\n";

    ExpectEq(expectedError, err, "The correct exception is thrown when setting invalid value");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetValidAffectedResearch()
{
    ExpectTrue(ResearchItem.testAddSpecification("affected research", ([
        "Constructed Spell Multiplier": 25
    ])), "add affected research specification");

    ExpectTrue(ResearchItem.testAddSpecification("affected research type", "percentage"),
        "add affected research type specification");

    ExpectEq(([ "Constructed Spell Multiplier": 25 ]),
        ResearchItem.query("affected research"),
        "can query the affected research");
}

/////////////////////////////////////////////////////////////////////////////
void GetUsageCostsReturnsAdditionalCosts()
{
    ResearchItem.testAddSpecification("additional hit point cost", 10);
    ResearchItem.testAddSpecification("additional spell point cost", 20);
    ResearchItem.testAddSpecification("additional stamina point cost", 15);

    mapping costs = ResearchItem.getUsageCosts("", 0);

    ExpectEq(10, costs["hit point cost"], "hit point cost is correct");
    ExpectEq(20, costs["spell point cost"], "spell point cost is correct");
    ExpectEq(15, costs["stamina point cost"], "stamina point cost is correct");
}

/////////////////////////////////////////////////////////////////////////////
void GetUsageCostsReturnsZeroWhenNoCostsSet()
{
    mapping costs = ResearchItem.getUsageCosts("", 0);

    ExpectEq(0, costs["hit point cost"], "hit point cost is zero");
    ExpectEq(0, costs["spell point cost"], "spell point cost is zero");
    ExpectEq(0, costs["stamina point cost"], "stamina point cost is zero");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetValidAffectedResearchType()
{
    ExpectTrue(ResearchItem.testAddSpecification("affected research type", "percentage"),
        "add affected research type specification");
    ExpectEq("percentage", ResearchItem.query("affected research type"),
        "can query the affected research type");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetAffectedResearchTypeToBonus()
{
    ExpectTrue(ResearchItem.testAddSpecification("affected research type", "bonus"),
        "add affected research type as bonus");
    ExpectEq("bonus", ResearchItem.query("affected research type"),
        "can query the affected research type as bonus");
}

/////////////////////////////////////////////////////////////////////////////
void DisplayRelatedResearchEffectsShowsDamageType()
{
    object User = clone_object("/lib/realizations/player.c");
    User.colorConfiguration("none");

    ResearchItem.testAddSpecification("damage type", "fire");

    string details = ResearchItem.researchDetails();
    ExpectSubStringMatch("Constructed items cause fire damage", details,
        "damage type is displayed");

    destruct(User);
}

/////////////////////////////////////////////////////////////////////////////
void DisplayRelatedResearchEffectsShowsAdditionalCosts()
{
    object User = clone_object("/lib/realizations/player.c");
    User.colorConfiguration("none");

    ResearchItem.testAddSpecification("additional hit point cost", 10);
    ResearchItem.testAddSpecification("additional spell point cost", 20);
    ResearchItem.testAddSpecification("additional stamina point cost", 15);
    ResearchItem.testAddSpecification("additional cooldown", 5);

    string details = ResearchItem.researchDetails();
    ExpectSubStringMatch("Hit point cost of constructed items increased by 10", details,
        "additional hit point cost is displayed");
    ExpectSubStringMatch("Spell point cost of constructed items increased by 20", details,
        "additional spell point cost is displayed");
    ExpectSubStringMatch("Stamina cost of constructed items increased by 15", details,
        "additional stamina point cost is displayed");
    ExpectSubStringMatch("Cooldown of constructed items increased by 5", details,
        "additional cooldown is displayed");

    destruct(User);
}

/////////////////////////////////////////////////////////////////////////////
void DisplayRelatedResearchEffectsShowsAdditionalRepeatEffect()
{
    object User = clone_object("/lib/realizations/player.c");
    User.colorConfiguration("none");

    ResearchItem.testAddSpecification("additional repeat effect", 2);

    string details = ResearchItem.researchDetails();
    ExpectSubStringMatch("Effect repeats 2 additional times", details,
        "additional repeat effect is displayed");

    destruct(User);
}

/////////////////////////////////////////////////////////////////////////////
void DisplayRelatedResearchEffectsShowsSingularRepeatEffect()
{
    object User = clone_object("/lib/realizations/player.c");
    User.colorConfiguration("none");

    ResearchItem.testAddSpecification("additional repeat effect", 1);

    string details = ResearchItem.researchDetails();
    ExpectSubStringMatch("Effect repeats 1 additional time\\.", details,
        "additional repeat effect singular is displayed correctly");

    destruct(User);
}
