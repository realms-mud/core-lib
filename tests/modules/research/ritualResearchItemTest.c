//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
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
    Room = clone_object("/lib/environment/room");

    ResearchItem = clone_object("/lib/tests/support/research/testRitualResearchItem");
    ResearchItem->init();

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
void TypeIsRitual()
{
    ExpectEq("ritual", ResearchItem->query("type"), "query the research type");
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
    string expectedError = "*ERROR - ritualResearchItem: the 'cooldown' specification must be an integer greater than 0.\n";
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
    string expectedError = "*ERROR - ritualResearchItem: the 'event handler' specification must be a string.\n";
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
    string expectedError = "*ERROR - ritualResearchItem: the 'use ability message' specification must be a string.\n";
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
    string expectedError = "*ERROR - ritualResearchItem: the 'use ability fail message' specification must be a string.\n";
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
    string expectedError = "*ERROR - ritualResearchItem: the 'use ability cooldown message' specification must be a string.\n";
    ExpectEq(expectedError, err, "The correct exception is thrown when setting invalid value");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetValidCommandTemplate()
{
    ExpectTrue(ResearchItem->addSpecification("command template", "blah"), "add command template specification");
    ExpectEq("blah", ResearchItem->query("command template"), "can query the command template");
}

/////////////////////////////////////////////////////////////////////////////
void SettingInvalidCommandTemplateThrowsError()
{
    string err = catch (ResearchItem->addSpecification("command template", 2));
    string expectedError = "*ERROR - ritualResearchItem: the 'command template' specification must be a string.\n";
    ExpectEq(expectedError, err, "The correct exception is thrown when setting invalid value");
}

/////////////////////////////////////////////////////////////////////////////
void CallingExecuteWhenNotResearchedReturnsFalse()
{
    ResearchItem->addSpecification("scope", "self");
    ResearchItem->TogglePerformRitual();
    ExpectFalse(ResearchItem->execute("the command", User));
}

/////////////////////////////////////////////////////////////////////////////
void CallingExecuteFailsUntilRitualPerformed()
{
    ResearchItem->addSpecification("scope", "self");
    User->ToggleMockResearch();
    ExpectFalse(ResearchItem->execute("the command", User));
    ResearchItem->TogglePerformRitual();
    ExpectTrue(ResearchItem->execute("the command", User));
}

/////////////////////////////////////////////////////////////////////////////
void CallingExecuteWhenAwaitingCooldownReturnsFalse()
{
    ResearchItem->addSpecification("scope", "self");
    ResearchItem->TogglePerformRitual();
    User->ToggleMockResearch();
    ExpectTrue(ResearchItem->execute("the command", User), "Cooldown is initially false");
    User->ToggleCooldown();
    ExpectFalse(ResearchItem->execute("the command", User), "Cooldown is set to true and execute fails");
}

/////////////////////////////////////////////////////////////////////////////
void CallingExecuteOnSelfScopeCallsExecuteOnSelf()
{
    ResearchItem->addSpecification("scope", "self");
    ResearchItem->ToggleReportExecution();
    ResearchItem->TogglePerformRitual();

    User->ToggleMockResearch();

    string err = catch (ResearchItem->execute("the command", User));
    string expectedError = "*research: executeOnSelf called";
    ExpectEq(expectedError, err);
}

/////////////////////////////////////////////////////////////////////////////
void CallingExecuteOnTargettedScopeCallsExecuteOnTarget()
{
    ResearchItem->addSpecification("scope", "targetted");
    ResearchItem->ToggleReportExecution();
    ResearchItem->TogglePerformRitual();

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
    ResearchItem->TogglePerformRitual();

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
    ResearchItem->TogglePerformRitual();

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
    ResearchItem->TogglePerformRitual();

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
    ResearchItem->TogglePerformRitual();

    User->ToggleMockResearch();

    string err = catch (ResearchItem->execute("the command", User));
    string expectedError = "*research: executeGlobally called";
    ExpectEq(expectedError, err);
}

