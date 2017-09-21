//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";
#include "/lib/include/inventory.h"

object ResearchItem;
object User;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    ResearchItem = clone_object("/lib/tests/support/research/testActiveResearchItem");
    ResearchItem->addSpecification("command template", "the command");

    User = clone_object("/lib/tests/support/services/combatWithMockServices");
    User->Name("Bob");
    User->Str(20);
    User->Int(20);
    User->Dex(20);
    User->Con(20);
    User->Wis(20);
    User->Chr(20);
    User->hitPoints(User->maxHitPoints());
    User->spellPoints(User->maxSpellPoints());
    User->staminaPoints(User->maxStaminaPoints());
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(User);
    destruct(ResearchItem);
}

/////////////////////////////////////////////////////////////////////////////
void TypeIsActive()
{
    ExpectEq("active", ResearchItem->query("type"), "query the research type");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetValidHitPointCost()
{
    ExpectTrue(ResearchItem->addSpecification("hit point cost", 20), "add hit point cost specification");
    ExpectEq(20, ResearchItem->query("hit point cost"), "can query the hit point cost");
}

/////////////////////////////////////////////////////////////////////////////
void SettingInvalidHitPointCostThrowsError()
{
    string err = catch (ResearchItem->addSpecification("hit point cost", "blah"));
    string expectedError = "*ERROR - activeResearchItem: the 'hit point cost' specification must be an integer greater than 0.\n";

    ExpectEq(expectedError, err, "The correct exception is thrown when setting invalid value");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetValidSpellPointCost()
{
    ExpectTrue(ResearchItem->addSpecification("spell point cost", 20), "add spell point cost specification");
    ExpectEq(20, ResearchItem->query("spell point cost"), "can query the spell point cost");
}

/////////////////////////////////////////////////////////////////////////////
void SettingInvalidSpellPointCostThrowsError()
{
    string err = catch (ResearchItem->addSpecification("spell point cost", "blah"));
    string expectedError = "*ERROR - activeResearchItem: the 'spell point cost' specification must be an integer greater than 0.\n";
    ExpectEq(expectedError, err, "The correct exception is thrown when setting invalid value");
}
/////////////////////////////////////////////////////////////////////////////
void CanSetValidStaminaPointCost()
{
    ExpectTrue(ResearchItem->addSpecification("stamina point cost", 20), "add stamina point cost specification");
    ExpectEq(20, ResearchItem->query("stamina point cost"), "can query the stamina point cost");
}

/////////////////////////////////////////////////////////////////////////////
void SettingInvalidStaminaPointCostThrowsError()
{
    string err = catch (ResearchItem->addSpecification("stamina point cost", "blah"));
    string expectedError = "*ERROR - activeResearchItem: the 'stamina point cost' specification must be an integer greater than 0.\n";
    ExpectEq(expectedError, err, "The correct exception is thrown when setting invalid value");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetValidCooldown()
{
    ExpectTrue(ResearchItem->addSpecification("cooldown", 5), "add cooldown specification");
    ExpectEq(5, ResearchItem->query("cooldown"), "can query the cooldown");
}

/////////////////////////////////////////////////////////////////////////////
void SettingInvalidCooldownThrowsError()
{
    string err = catch (ResearchItem->addSpecification("cooldown", "blah"));
    string expectedError = "*ERROR - activeResearchItem: the 'cooldown' specification must be an integer greater than 0.\n";
    ExpectEq(expectedError, err, "The correct exception is thrown when setting invalid value");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetValidEventHandler()
{
    ExpectTrue(ResearchItem->addSpecification("event handler", "blah"), "add event handler specification");
    ExpectEq("blah", ResearchItem->query("event handler"), "can query the event handler");
}

/////////////////////////////////////////////////////////////////////////////
void SettingInvalidEventHandlerThrowsError()
{
    string err = catch (ResearchItem->addSpecification("event handler", 6));
    string expectedError = "*ERROR - activeResearchItem: the 'event handler' specification must be a string.\n";
    ExpectEq(expectedError, err, "The correct exception is thrown when setting invalid value");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetValidUseAbilityMessage()
{
    ExpectTrue(ResearchItem->addSpecification("use ability message", "blah"), "add use ability message specification");
    ExpectEq("blah", ResearchItem->query("use ability message"), "can query the use ability message");
}

/////////////////////////////////////////////////////////////////////////////
void SettingInvalidUseAbilityMessageThrowsError()
{
    string err = catch (ResearchItem->addSpecification("use ability message", 1));
    string expectedError = "*ERROR - activeResearchItem: the 'use ability message' specification must be a string.\n";
    ExpectEq(expectedError, err, "The correct exception is thrown when setting invalid value");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetValidUseAbilityFailMessage()
{
    ExpectTrue(ResearchItem->addSpecification("use ability fail message", "blah"), "add use ability fail message specification");
    ExpectEq("blah", ResearchItem->query("use ability fail message"), "can query the use ability fail message");
}

/////////////////////////////////////////////////////////////////////////////
void SettingInvalidUseAbilityFailMessageThrowsError()
{
    string err = catch (ResearchItem->addSpecification("use ability fail message", 1));
    string expectedError = "*ERROR - activeResearchItem: the 'use ability fail message' specification must be a string.\n";
    ExpectEq(expectedError, err, "The correct exception is thrown when setting invalid value");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetValidUseAbilityCooldownMessage()
{
    ExpectTrue(ResearchItem->addSpecification("use ability cooldown message", "blah"), "add use ability cooldown message specification");
    ExpectEq("blah", ResearchItem->query("use ability cooldown message"), "can query the use ability cooldown message");
}

/////////////////////////////////////////////////////////////////////////////
void SettingInvalidUseAbilityCooldownMessageThrowsError()
{
    string err = catch (ResearchItem->addSpecification("use ability cooldown message", 1));
    string expectedError = "*ERROR - activeResearchItem: the 'use ability cooldown message' specification must be a string.\n";
    ExpectEq(expectedError, err, "The correct exception is thrown when setting invalid value");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetValidCommandTemplate()
{
    ExpectFalse(ResearchItem->canExecuteCommand("blah"), "cannot execute the command template before set");
    ExpectTrue(ResearchItem->addSpecification("command template", "blah"), "add command template specification");
    ExpectTrue(ResearchItem->canExecuteCommand("blah"), "can execute the command template");
}

/////////////////////////////////////////////////////////////////////////////
void SettingInvalidCommandTemplateThrowsError()
{
    string err = catch (ResearchItem->addSpecification("command template", 2));
    string expectedError = "*ERROR - activeResearchItem: the 'command template' specification must be a string.\n";
    ExpectEq(expectedError, err, "The correct exception is thrown when setting invalid value");
}

/////////////////////////////////////////////////////////////////////////////
void CallingExecuteWhenNotResearchedReturnsFalse()
{
    ExpectFalse(ResearchItem->execute("the command", User));
}

/////////////////////////////////////////////////////////////////////////////
void CallingExecuteWhenAwaitingCooldownReturnsFalse()
{
    ResearchItem->addSpecification("scope", "self");
    User->ToggleMockResearch();
    ExpectTrue(ResearchItem->execute("the command", User), "Cooldown is initially false");
    User->ToggleCooldown();
    ExpectFalse(ResearchItem->execute("the command", User), "Cooldown is set to true and execute fails");
}

/////////////////////////////////////////////////////////////////////////////
void CallingExecuteWhenHitPointsAreLowerThanHPCostReturnsFalse()
{
    ResearchItem->addSpecification("scope", "self");
    ResearchItem->addSpecification("hit point cost", 20);

    User->ToggleMockResearch();
    ExpectTrue(ResearchItem->execute("the command", User), "initially have enough points");
    ResearchItem->decreaseHitPointsOnUser(User);
    ExpectFalse(ResearchItem->execute("the command", User), "hit points are dropped below threshhold");
}

/////////////////////////////////////////////////////////////////////////////
void CallingExecuteWhenSpellPointsAreLowerThanHPCostReturnsFalse()
{
    ResearchItem->addSpecification("scope", "self");
    ResearchItem->addSpecification("spell point cost", 20);

    User->ToggleMockResearch();
    ExpectTrue(ResearchItem->execute("the command", User), "initially have enough points");
    User->spellPoints(-1 * (User->spellPoints() - 10));
    ExpectFalse(ResearchItem->execute("the command", User), "points are dropped below threshhold");
}

/////////////////////////////////////////////////////////////////////////////
void CallingExecuteWhenStaminaPointsAreLowerThanHPCostReturnsFalse()
{
    ResearchItem->addSpecification("scope", "self");
    ResearchItem->addSpecification("stamina point cost", 20);

    User->ToggleMockResearch();
    ExpectTrue(ResearchItem->execute("the command", User), "initially have enough points");
    User->staminaPoints(-1 * (User->staminaPoints() - 10));
    ExpectFalse(ResearchItem->execute("the command", User), "points are dropped below threshhold");
}

/////////////////////////////////////////////////////////////////////////////
void CallingExecuteOnSelfScopeCallsExecuteOnSelf()
{
    ResearchItem->addSpecification("scope", "self");
    ResearchItem->ToggleReportExecution();

    User->ToggleMockResearch();

    string err = catch (ResearchItem->execute("the command", User));
    string expectedError = "*research: executeOnSelf called";
    ExpectEq(expectedError, err);
}

/////////////////////////////////////////////////////////////////////////////
void CallingExecuteOnTargetedScopeCallsExecuteOnTarget()
{
    ResearchItem->addSpecification("scope", "targeted");
    ResearchItem->ToggleReportExecution();

    User->ToggleMockResearch();

    string err = catch (ResearchItem->execute("the command", User));
    string expectedError = "*research: executeOnTarget called";
    ExpectEq(expectedError, err);
}

/////////////////////////////////////////////////////////////////////////////
void CallingExecuteOnAreaScopeCallsExecuteInArea()
{
    ResearchItem->addSpecification("scope", "area");
    ResearchItem->ToggleReportExecution();

    User->ToggleMockResearch();

    string err = catch (ResearchItem->execute("the command", User));
    string expectedError = "*research: executeInArea called";
    ExpectEq(expectedError, err);
}

/////////////////////////////////////////////////////////////////////////////
void CallingExecuteOnEnvironmentScopeCallsExecuteOnEnvironment()
{
    ResearchItem->addSpecification("scope", "environmental");
    ResearchItem->ToggleReportExecution();

    User->ToggleMockResearch();

    string err = catch (ResearchItem->execute("the command", User));
    string expectedError = "*research: executeOnEnvironment called";
    ExpectEq(expectedError, err);
}

/////////////////////////////////////////////////////////////////////////////
void CallingExecuteOnRegionScopeCallsExecuteOnRegion()
{
    ResearchItem->addSpecification("scope", "region");
    ResearchItem->ToggleReportExecution();

    User->ToggleMockResearch();

    string err = catch (ResearchItem->execute("the command", User));
    string expectedError = "*research: executeOnRegion called";
    ExpectEq(expectedError, err);
}

/////////////////////////////////////////////////////////////////////////////
void CallingExecuteOnGlobalScopeCallsExecuteGlobally()
{
    ResearchItem->addSpecification("scope", "global");
    ResearchItem->ToggleReportExecution();

    User->ToggleMockResearch();

    string err = catch (ResearchItem->execute("the command", User));
    string expectedError = "*research: executeGlobally called";
    ExpectEq(expectedError, err);
}

/////////////////////////////////////////////////////////////////////////////
void CallingExecuteDecreasesHitPointsAppropriately()
{
    ResearchItem->addSpecification("scope", "self");
    ResearchItem->addSpecification("hit point cost", 20);

    User->ToggleMockResearch();
    ExpectEq(150, User->hitPoints(), "initial hit point total");
    ExpectTrue(ResearchItem->execute("the command", User), "initially have enough points");
    ExpectEq(130, User->hitPoints(), "hit point total after execution");
}

/////////////////////////////////////////////////////////////////////////////
void CallingExecuteDecreasesSpellPointsAppropriately()
{
    ResearchItem->addSpecification("scope", "self");

    // Because of bonusReduceSpellPoints, the toggling of mock research, and my desire to
    // be lazy, 2 of these 22 will be reduced from the end cost
    ResearchItem->addSpecification("spell point cost", 22);

    User->ToggleMockResearch();
    ExpectEq(150, User->spellPoints(), "initial spell point total");
    ExpectTrue(ResearchItem->execute("the command", User), "initially have enough points");
    ExpectEq(130, User->spellPoints(), "spell point total after execution");
}

/////////////////////////////////////////////////////////////////////////////
void CallingExecuteDecreasesStaminaPointsAppropriately()
{
    ResearchItem->addSpecification("scope", "self");

    // Because of bonusReduceStaminaPoints, the toggling of mock research, and my desire to
    // be lazy, 2 of these 22 will be reduced from the end cost
    ResearchItem->addSpecification("stamina point cost", 22);

    User->ToggleMockResearch();
    ExpectEq(150, User->staminaPoints(), "initial stamina point total");
    ExpectTrue(ResearchItem->execute("the command", User), "initially have enough points");
    ExpectEq(130, User->staminaPoints(), "stamina point total after execution");
}

