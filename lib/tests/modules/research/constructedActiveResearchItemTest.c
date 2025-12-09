//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";
#include "/lib/include/inventory.h"

object ResearchItem;
object User;
object Room;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    ResearchItem = clone_object("/lib/tests/support/research/testConstructedActiveResearchItem");

    User = clone_object("/lib/tests/support/services/mockPlayer.c");
    User.Name("Bob");
    User.Str(20);
    User.Int(20);
    User.Dex(20);
    User.Con(20);
    User.Wis(20);
    User.Chr(20);
    User.hitPoints(User.maxHitPoints());
    User.spellPoints(User.maxSpellPoints());
    User.staminaPoints(User.maxStaminaPoints());

    Room = clone_object("/lib/environment/environment");
    move_object(User, Room);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(User);
    destruct(ResearchItem);
    destruct(Room);
}

/////////////////////////////////////////////////////////////////////////////
void CanSetValidCommandName()
{
    ExpectTrue(ResearchItem.testAddSpecification("command name", "cast spell"),
        "add command name specification");
    ExpectEq("cast spell", ResearchItem.query("command name"),
        "can query the command name");
}

/////////////////////////////////////////////////////////////////////////////
void SettingInvalidCommandNameThrowsError()
{
    string err = catch (ResearchItem.testAddSpecification("command name", 123); nolog);
    string expectedError = "*ERROR - constructedActiveResearchItem: the 'command name' specification must be a string.\n";

    ExpectEq(expectedError, err, "The correct exception is thrown when setting invalid value");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetValidMaximumConstructedSize()
{
    ExpectTrue(ResearchItem.testAddSpecification("maximum constructed size", 5),
        "add maximum constructed size specification");
    ExpectEq(5, ResearchItem.query("maximum constructed size"),
        "can query the maximum constructed size");
}

/////////////////////////////////////////////////////////////////////////////
void SettingInvalidMaximumConstructedSizeThrowsError()
{
    string err = catch (ResearchItem.testAddSpecification("maximum constructed size", 0); nolog);
    string expectedError = "*ERROR - constructedActiveResearchItem: the 'maximum constructed size' specification must be a positive integer.\n";

    ExpectEq(expectedError, err, "The correct exception is thrown when setting invalid value");
}

/////////////////////////////////////////////////////////////////////////////
void SettingNonIntegerMaximumConstructedSizeThrowsError()
{
    string err = catch (ResearchItem.testAddSpecification("maximum constructed size", "big"); nolog);
    string expectedError = "*ERROR - constructedActiveResearchItem: the 'maximum constructed size' specification must be a positive integer.\n";

    ExpectEq(expectedError, err, "The correct exception is thrown when setting invalid value");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetValidConstructedRulesWithFormMustIncludeOnlyOneOf()
{
    load_object("/guilds/aeromancer/forms/bolt.c");
    load_object("/guilds/aeromancer/forms/blade.c");

    ExpectTrue(ResearchItem.testAddSpecification("constructed rules", ( [
        "form must include only one of": ({
            "/guilds/aeromancer/forms/bolt.c",
            "/guilds/aeromancer/forms/blade.c"
        })
    ])), "add constructed rules specification");

    mapping rules = ResearchItem.query("constructed rules");
    ExpectTrue(mappingp(rules), "constructed rules is a mapping");
    ExpectTrue(member(rules, "form must include only one of") > -1,
        "form must include only one of key exists");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetValidConstructedRulesWithFunctionMustIncludeOnlyOneOf()
{
    load_object("/guilds/aeromancer/functions/lightning.c");
    load_object("/guilds/aeromancer/functions/wind.c");

    ExpectTrue(ResearchItem.testAddSpecification("constructed rules", ( [
        "function must include only one of": ({
            "/guilds/aeromancer/functions/lightning.c",
            "/guilds/aeromancer/functions/wind.c"
        })
    ])), "add constructed rules specification");

    mapping rules = ResearchItem.query("constructed rules");
    ExpectTrue(mappingp(rules), "constructed rules is a mapping");
    ExpectTrue(member(rules, "function must include only one of") > -1,
        "function must include only one of key exists");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetValidConstructedRulesWithEffectMustIncludeOnlyOneOf()
{
    load_object("/guilds/aeromancer/effects/damage-hp.c");
    load_object("/guilds/aeromancer/effects/damage-sp.c");

    ExpectTrue(ResearchItem.testAddSpecification("constructed rules", ( [
        "effect must include only one of": ({
            "/guilds/aeromancer/effects/damage-hp.c",
            "/guilds/aeromancer/effects/damage-sp.c"
        })
    ])), "add constructed rules specification");

    mapping rules = ResearchItem.query("constructed rules");
    ExpectTrue(mappingp(rules), "constructed rules is a mapping");
    ExpectTrue(member(rules, "effect must include only one of") > -1,
        "effect must include only one of key exists");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetValidConstructedRulesWithEffectCanIncludeAnyOf()
{
    load_object("/guilds/aeromancer/effects/damage-hp.c");
    load_object("/guilds/aeromancer/effects/damage-sp.c");
    load_object("/guilds/aeromancer/effects/damage-stamina.c");

    ExpectTrue(ResearchItem.testAddSpecification("constructed rules", ( [
        "effect can include any of": ({
            "/guilds/aeromancer/effects/damage-hp.c",
            "/guilds/aeromancer/effects/damage-sp.c",
            "/guilds/aeromancer/effects/damage-stamina.c"
        })
    ])), "add constructed rules specification");

    mapping rules = ResearchItem.query("constructed rules");
    ExpectTrue(mappingp(rules), "constructed rules is a mapping");
    ExpectTrue(member(rules, "effect can include any of") > -1,
        "effect can include any of key exists");
}

/////////////////////////////////////////////////////////////////////////////
void SettingInvalidConstructedRulesThrowsError()
{
    string err = catch (ResearchItem.testAddSpecification("constructed rules", "not a mapping"); nolog);
    string expectedError = "*ERROR - constructedActiveResearchItem: the 'constructed rules' specification must be a valid rule set.\n";

    ExpectEq(expectedError, err, "The correct exception is thrown when setting invalid value");
}

/////////////////////////////////////////////////////////////////////////////
void SettingConstructedRulesWithInvalidRuleTypeThrowsError()
{
    string err = catch (ResearchItem.testAddSpecification("constructed rules", ( [
        "invalid rule type": ({ "/some/path.c" })
    ])); nolog);
    string expectedError = "*ERROR - constructedActiveResearchItem: the 'constructed rules' specification must be a valid rule set.\n";

    ExpectEq(expectedError, err, "The correct exception is thrown when setting invalid rule type");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetValidMaxConstructedSizeModifier()
{
    ExpectTrue(ResearchItem.testAddSpecification("max constructed size modifier", ({
        ( [
            "type": "skill",
            "name": "spellcraft",
            "formula": "additive",
            "rate": 0.10
        ])
    })), "add max constructed size modifier specification");

    mixed modifier = ResearchItem.query("max constructed size modifier");
    ExpectTrue(pointerp(modifier), "max constructed size modifier is an array");
}

/////////////////////////////////////////////////////////////////////////////
void SettingInvalidMaxConstructedSizeModifierThrowsError()
{
    string err = catch (ResearchItem.testAddSpecification("max constructed size modifier", "invalid"); nolog);
    string expectedError = "*ERROR - constructedActiveResearchItem: the 'max constructed size modifier' specification must be a properly formatted modifier.\n";

    ExpectEq(expectedError, err, "The correct exception is thrown when setting invalid value");
}

/////////////////////////////////////////////////////////////////////////////
void GetUsageCostsReturnsBaseCostsWhenNoComponents()
{
    // Base cost is 10 SP from Setup(), no components
    mapping baseCosts = ResearchItem.testGetUsageCosts("test spell target", User);

    ExpectTrue(mappingp(baseCosts), "getUsageCosts returns a mapping");
    ExpectEq(0, baseCosts["hit point cost"], "hit point cost is 0");
    ExpectEq(10, baseCosts["spell point cost"], "spell point cost is base 10");
    ExpectEq(0, baseCosts["stamina point cost"], "stamina point cost is 0");
}

/////////////////////////////////////////////////////////////////////////////
void GetUsageCostsAggregatesSingleComponentCosts()
{
    // Load the component to ensure it's registered with the research service
    load_object("/lib/tests/support/research/testConstructedComponentA.c");

    // Set up constructed research on user with Component A as the type
    ExpectTrue(User.setConstructedResearch("test combo", ([
        "constraint": "/lib/tests/support/research/testConstructedActiveResearchItem.c",
        "type": "/lib/tests/support/research/testConstructedComponentA.c",
        "elements": ({})
    ])), "setConstructedResearch succeeds");

    mapping costs = ResearchItem.testGetUsageCosts("test spell test combo", User);

    // Base: HP=0, SP=10, ST=0
    // Component A (type): HP=5, SP=10, ST=8
    // Total: HP=5, SP=20, ST=8
    ExpectEq(5, costs["hit point cost"], "hit point cost is 5");
    ExpectEq(20, costs["spell point cost"], "spell point cost is 10+10=20");
    ExpectEq(8, costs["stamina point cost"], "stamina point cost is 8");
}

/////////////////////////////////////////////////////////////////////////////
void GetUsageCostsAggregatesMultipleComponentCosts()
{
    // Component A as type, Component B in elements
    User.setConstructedResearch("test combo", ([
        "constraint": "/lib/tests/support/research/testConstructedActiveResearchItem.c",
        "type": "/lib/tests/support/research/testConstructedComponentA.c",
        "elements": ({
            ([ "research": "/lib/tests/support/research/testConstructedComponentB.c" ])
        })
    ]));

    mapping costs = ResearchItem.testGetUsageCosts("test spell test combo", User);

    // Base: HP=0, SP=10, ST=0
    // Component A (type): HP=5, SP=10, ST=8
    // Component B: HP=7, SP=15, ST=12
    // Total: HP=12, SP=35, ST=20
    ExpectEq(12, costs["hit point cost"], "hit point cost is 5+7=12");
    ExpectEq(35, costs["spell point cost"], "spell point cost is 10+10+15=35");
    ExpectEq(20, costs["stamina point cost"], "stamina point cost is 8+12=20");
}

/////////////////////////////////////////////////////////////////////////////
void GetUsageCostsAggregatesThreeComponentCosts()
{
    // Component A as type, Component B and C in elements
    User.setConstructedResearch("test combo", ( [
        "constraint": "/lib/tests/support/research/testConstructedActiveResearchItem.c",
        "type": "/lib/tests/support/research/testConstructedComponentA.c",
        "elements": ({
            ([ "research": "/lib/tests/support/research/testConstructedComponentB.c" ]),
            ([ "research": "/lib/tests/support/research/testConstructedComponentC.c" ])
        })
    ]));

    mapping costs = ResearchItem.testGetUsageCosts("test spell test combo", User);

    // Base: HP=0, SP=10, ST=0
    // Component A (type): HP=5, SP=10, ST=8
    // Component B: HP=7, SP=15, ST=12
    // Component C: HP=3, SP=20, ST=5
    // Total: HP=15, SP=55, ST=25
    ExpectEq(15, costs["hit point cost"], "hit point cost is 5+7+3=15");
    ExpectEq(55, costs["spell point cost"], "spell point cost is 10+10+15+20=55");
    ExpectEq(25, costs["stamina point cost"], "stamina point cost is 8+12+5=25");
}

/////////////////////////////////////////////////////////////////////////////
void CooldownReturnsBaseCooldownWhenNoComponents()
{
    // Base cooldown is 10 from Setup()
    int cooldown = ResearchItem.testCooldown(User);

    ExpectEq(10, cooldown, "cooldown returns base value of 10");
}

/////////////////////////////////////////////////////////////////////////////
void CooldownAggregatesSingleComponentCooldown()
{
    load_object("/lib/tests/support/research/testConstructedComponentA.c");

    ExpectTrue(User.setConstructedResearch("test combo", ([
        "constraint": "/lib/tests/support/research/testConstructedActiveResearchItem.c",
        "type": "/lib/tests/support/research/testConstructedComponentA.c",
        "elements": ({})
    ])), "setConstructedResearch succeeds");

    int cooldown = ResearchItem.testCooldown(User, "test spell test combo");

    // Base: 10, Component A: 3
    // Total: 13
    ExpectEq(13, cooldown, "cooldown is 10+3=13");
}

/////////////////////////////////////////////////////////////////////////////
void CooldownAggregatesMultipleComponentCooldowns()
{
    User.setConstructedResearch("test combo", ([
        "constraint": "/lib/tests/support/research/testConstructedActiveResearchItem.c",
        "type": "/lib/tests/support/research/testConstructedComponentA.c",
        "elements": ({
            ([ "research": "/lib/tests/support/research/testConstructedComponentB.c" ])
        })
    ]));

    int cooldown = ResearchItem.testCooldown(User, "test spell test combo");

    // Base: 10, Component A: 3, Component B: 5
    // Total: 18
    ExpectEq(18, cooldown, "cooldown is 10+3+5=18");
}

/////////////////////////////////////////////////////////////////////////////
void CooldownAggregatesThreeComponentCooldowns()
{
    User.setConstructedResearch("test combo", ([
        "constraint": "/lib/tests/support/research/testConstructedActiveResearchItem.c",
        "type": "/lib/tests/support/research/testConstructedComponentA.c",
        "elements": ({
            ([ "research": "/lib/tests/support/research/testConstructedComponentB.c" ]),
            ([ "research": "/lib/tests/support/research/testConstructedComponentC.c" ])
        })
    ]));

    int cooldown = ResearchItem.testCooldown(User, "test spell test combo");

    // Base: 10, Component A: 3, Component B: 5, Component C: 2
    // Total: 20
    ExpectEq(20, cooldown, "cooldown is 10+3+5+2=20");
}

/////////////////////////////////////////////////////////////////////////////
void CooldownReturnsMinimumOfTwoWhenCalculatedValueIsLower()
{
    // Set base cooldown to 1 (minimum allowed value, 0 throws error)
    ResearchItem.testAddSpecification("cooldown", 1);

    int cooldown = ResearchItem.testCooldown(User);

    // Minimum cooldown is 2
    ExpectEq(2, cooldown, "cooldown minimum is 2");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetSpellPointCost()
{
    ExpectTrue(ResearchItem.testAddSpecification("spell point cost", 50),
        "add spell point cost specification");
    ExpectEq(50, ResearchItem.query("spell point cost"),
        "can query the spell point cost");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetStaminaPointCost()
{
    ExpectTrue(ResearchItem.testAddSpecification("stamina point cost", 25),
        "add stamina point cost specification");
    ExpectEq(25, ResearchItem.query("stamina point cost"),
        "can query the stamina point cost");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetHitPointCost()
{
    ExpectTrue(ResearchItem.testAddSpecification("hit point cost", 15),
        "add hit point cost specification");
    ExpectEq(15, ResearchItem.query("hit point cost"),
        "can query the hit point cost");
}

////////////////////////////////////////////////////////////////////////////
void RepeatEffectCountReturnsBaseWhenNoComponents()
{
    int repeat = ResearchItem.testGetRepeatEffectCount("test spell target", User);

    ExpectEq(0, repeat, "repeat effect count returns base value of 0");
}

/////////////////////////////////////////////////////////////////////////////
void RepeatEffectCountAggregatesSingleComponentRepeatEffect()
{
    load_object("/lib/tests/support/research/testConstructedComponentA.c");

    ExpectTrue(User.setConstructedResearch("test combo", ([
        "constraint": "/lib/tests/support/research/testConstructedActiveResearchItem.c",
        "type": "/lib/tests/support/research/testConstructedComponentA.c",
        "elements": ({})
    ])), "setConstructedResearch succeeds");

    int repeat = ResearchItem.testGetRepeatEffectCount("test spell test combo", User);

    // Base: 0, Component A: 2
    // Total: 2
    ExpectEq(2, repeat, "repeat effect count is 0+2=2");
}

/////////////////////////////////////////////////////////////////////////////
void RepeatEffectCountAggregatesMultipleComponentRepeatEffects()
{
    User.setConstructedResearch("test combo", ([
        "constraint": "/lib/tests/support/research/testConstructedActiveResearchItem.c",
        "type": "/lib/tests/support/research/testConstructedComponentA.c",
        "elements": ({
            ([ "research": "/lib/tests/support/research/testConstructedComponentB.c" ])
        })
    ]));

    int repeat = ResearchItem.testGetRepeatEffectCount("test spell test combo", User);

    // Base: 0, Component A: 2, Component B: 1
    // Total: 3
    ExpectEq(3, repeat, "repeat effect count is 0+2+1=3");
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteDeductsAggregatedSpellPointCost()
{
    // Load components
    load_object("/lib/tests/support/research/testConstructedComponentA.c");

    // User must have researched the constructed research item
    User.addResearchPoints(1);
    User.initiateResearch("/lib/tests/support/research/testConstructedActiveResearchItem.c");

    // Set up constructed research on user
    ExpectTrue(User.setConstructedResearch("test combo", ( [
        "constraint": "/lib/tests/support/research/testConstructedActiveResearchItem.c",
        "type": "/lib/tests/support/research/testConstructedComponentA.c",
        "elements": ({})
    ])), "setConstructedResearch succeeds");

    int initialSP = User.spellPoints();

    // Execute the spell
    ExpectTrue(User.researchCommand("test spell test combo"), 
        "spell execution succeeds");

    // Base: SP=10, Component A: SP=10 = 20 total
    ExpectEq(initialSP - 20, User.spellPoints(), 
        "spell points deducted correctly");
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteFailsWhenNotEnoughSpellPoints()
{
    load_object("/lib/tests/support/research/testConstructedComponentA.c");

    User.addResearchPoints(1);
    User.initiateResearch("/lib/tests/support/research/testConstructedActiveResearchItem.c");

    User.setConstructedResearch("test combo", ( [
        "constraint": "/lib/tests/support/research/testConstructedActiveResearchItem.c",
        "type": "/lib/tests/support/research/testConstructedComponentA.c",
        "elements": ({})
    ]));

    // Set spell points too low (base 10 + component A 10 = 20 needed)
    User.spellPoints(-User.spellPoints() + 15);

    ExpectFalse(User.researchCommand("test spell test combo"), 
        "spell execution fails due to insufficient spell points");
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteAppliesCooldown()
{
    load_object("/lib/tests/support/research/testConstructedComponentA.c");

    User.addResearchPoints(1);
    User.initiateResearch("/lib/tests/support/research/testConstructedActiveResearchItem.c");

    User.setConstructedResearch("test combo", ( [
        "constraint": "/lib/tests/support/research/testConstructedActiveResearchItem.c",
        "type": "/lib/tests/support/research/testConstructedComponentA.c",
        "elements": ({})
    ]));

    ExpectFalse(User.blockedByCooldown(
        "/lib/tests/support/research/testConstructedActiveResearchItem.c"),
        "not on cooldown before execution");

    User.researchCommand("test spell test combo");

    ExpectTrue(User.blockedByCooldown(
        "/lib/tests/support/research/testConstructedActiveResearchItem.c"),
        "on cooldown after execution");
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteWithElementsDeductsFullAggregatedCost()
{
    load_object("/lib/tests/support/research/testConstructedComponentA.c");
    load_object("/lib/tests/support/research/testConstructedComponentB.c");

    User.addResearchPoints(1);
    User.initiateResearch("/lib/tests/support/research/testConstructedActiveResearchItem.c");

    // Set up constructed research with type and one element
    ExpectTrue(User.setConstructedResearch("test combo", ([
        "constraint": "/lib/tests/support/research/testConstructedActiveResearchItem.c",
        "type": "/lib/tests/support/research/testConstructedComponentA.c",
        "elements": ({
            ([ "research": "/lib/tests/support/research/testConstructedComponentB.c" ])
        })
    ])), "setConstructedResearch succeeds");

    int initialSP = User.spellPoints();

    ExpectTrue(User.researchCommand("test spell test combo"), 
        "spell execution succeeds");

    // Base: SP=10, Component A: SP=10, Component B: SP=15 = 35 total
    ExpectEq(initialSP - 35, User.spellPoints(), 
        "spell points deducted correctly for all components");
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteWithElementsAppliesAggregatedCooldown()
{
    load_object("/lib/tests/support/research/testConstructedComponentA.c");
    load_object("/lib/tests/support/research/testConstructedComponentB.c");

    User.addResearchPoints(1);
    User.initiateResearch("/lib/tests/support/research/testConstructedActiveResearchItem.c");

    User.setConstructedResearch("test combo", ( [
        "constraint": "/lib/tests/support/research/testConstructedActiveResearchItem.c",
        "type": "/lib/tests/support/research/testConstructedComponentA.c",
        "elements": ({
            ([ "research": "/lib/tests/support/research/testConstructedComponentB.c" ])
        })
    ]));

    User.researchCommand("test spell test combo");

    // Cooldown should be applied (base 10 + A:3 + B:5 = 18)
    ExpectTrue(User.blockedByCooldown(
        "/lib/tests/support/research/testConstructedActiveResearchItem.c"),
        "cooldown applied after execution with elements");
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteDisplaysCombinationMessage()
{
    load_object("/lib/tests/support/research/testConstructedComponentA.c");
    load_object("/lib/tests/support/research/testConstructedComponentB.c");

    User.addResearchPoints(1);
    User.initiateResearch("/lib/tests/support/research/testConstructedActiveResearchItem.c");
    User.colorConfiguration("none");

    object Target = clone_object("/lib/realizations/monster.c");
    Target.Name("Orc");
    object shadow = clone_object("/lib/tests/support/services/catchShadow.c");
    shadow.beginShadow(Target);
    move_object(Target, Room);

    object Bystander = clone_object("/lib/tests/support/services/mockPlayer.c");
    Bystander.Name("Frank");
    Bystander.colorConfiguration("none");
    move_object(Bystander, Room);

    User.setConstructedResearch("test combo", ([
        "constraint": "/lib/tests/support/research/testConstructedActiveResearchItem.c",
        "type": "/lib/tests/support/research/testConstructedComponentA.c",
        "elements": ({
            ([ "research": "/lib/tests/support/research/testConstructedComponentB.c" ])
        })
    ]));

    User.researchCommand("test spell test combo");

    // Initiator (Bob) sees "You blast..."
    string initiatorMessage = User.caughtMessage();
    ExpectEq("You blast a bolt of lightning at Orc.\n", initiatorMessage, 
        "initiator sees message from their perspective");

    // Target (Orc) sees "Bob blasts..."
    string targetMessage = Target.caughtMessage();
    ExpectEq("Bob blasts a bolt of lightning at you.\n", targetMessage,
        "target sees message with initiator's name");

    // Bystander (Frank) sees "Bob blasts..."
    string bystanderMessage = Bystander.caughtMessage();
    ExpectEq("Bob blasts a bolt of lightning at Orc.\n", bystanderMessage,
        "bystander sees message with initiator's name");

    destruct(Target);
    destruct(Bystander);
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteFailsWhenNotEnoughSpellPointsForFullCost()
{
    load_object("/lib/tests/support/research/testConstructedComponentA.c");
    load_object("/lib/tests/support/research/testConstructedComponentB.c");

    User.addResearchPoints(1);
    User.initiateResearch("/lib/tests/support/research/testConstructedActiveResearchItem.c");

    User.setConstructedResearch("test combo", ( [
        "constraint": "/lib/tests/support/research/testConstructedActiveResearchItem.c",
        "type": "/lib/tests/support/research/testConstructedComponentA.c",
        "elements": ({
            ([ "research": "/lib/tests/support/research/testConstructedComponentB.c" ])
        })
    ]));

    // Need 35 SP total (base 10 + A:10 + B:15), set to 30
    User.spellPoints(-User.spellPoints() + 30);

    ExpectFalse(User.researchCommand("test spell test combo"), 
        "spell execution fails due to insufficient spell points for full cost");
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteBlockedWhenOnCooldown()
{
    load_object("/lib/tests/support/research/testConstructedComponentA.c");

    User.addResearchPoints(1);
    User.initiateResearch("/lib/tests/support/research/testConstructedActiveResearchItem.c");

    User.setConstructedResearch("test combo", ( [
        "constraint": "/lib/tests/support/research/testConstructedActiveResearchItem.c",
        "type": "/lib/tests/support/research/testConstructedComponentA.c",
        "elements": ({})
    ]));

    // First execution should succeed
    ExpectTrue(User.researchCommand("test spell test combo"), 
        "first spell execution succeeds");

    // Restore spell points for second attempt
    User.spellPoints(User.maxSpellPoints());

    // Second execution should fail due to cooldown
    ExpectFalse(User.researchCommand("test spell test combo"), 
        "second spell execution fails due to cooldown");
}
