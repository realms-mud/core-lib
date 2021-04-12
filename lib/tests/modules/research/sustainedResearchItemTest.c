//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";
#include "/lib/include/inventory.h"

object ResearchItem;
object User;
object Target;
object Room;

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    load_object("/lib/tests/support/research/testSustainedTraitResearch.c");
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    ResearchItem = clone_object("/lib/tests/support/research/testSustainedResearchItem");
    ResearchItem->addTestSpecification("command template", "the command");
    ResearchItem->addTestSpecification("command template", "throw turnip at ##Target##");

    User = clone_object("/lib/tests/support/services/combatWithMockServices.c");
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
    User->addSkillPoints(100);
    User->advanceSkill("long sword", 3);
    User->toggleKillList();

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
    Target->addSkillPoints(200);
    Target->advanceSkill("long sword", 10);

    Room = clone_object("/lib/environment/environment");
    move_object(User, Room);
    move_object(Target, Room);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Target);
    destruct(User);
    destruct(ResearchItem);
    destruct(Room);
}

/////////////////////////////////////////////////////////////////////////////
void TypeIsSustained()
{
    ExpectEq("sustained", ResearchItem->query("type"), "query the research type");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetValidHitPointCost()
{
    ExpectTrue(ResearchItem->addTestSpecification("hit point cost", 20), "add hit point cost specification");
    ExpectEq(20, ResearchItem->query("hit point cost"), "can query the hit point cost");
}

/////////////////////////////////////////////////////////////////////////////
void SettingInvalidHitPointCostThrowsError()
{
    string err = catch (ResearchItem->addTestSpecification("hit point cost", "blah"));
    string expectedError = "*ERROR - sustainedResearchItem: the 'hit point cost' specification must be an integer greater than 0.\n";

    ExpectEq(expectedError, err, "The correct exception is thrown when setting invalid value");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetValidSpellPointCost()
{
    ExpectTrue(ResearchItem->addTestSpecification("spell point cost", 20), "add spell point cost specification");
    ExpectEq(20, ResearchItem->query("spell point cost"), "can query the spell point cost");
}

/////////////////////////////////////////////////////////////////////////////
void SettingInvalidSpellPointCostThrowsError()
{
    string err = catch (ResearchItem->addTestSpecification("spell point cost", "blah"));
    string expectedError = "*ERROR - sustainedResearchItem: the 'spell point cost' specification must be an integer greater than 0.\n";
    ExpectEq(expectedError, err, "The correct exception is thrown when setting invalid value");
}
/////////////////////////////////////////////////////////////////////////////
void CanSetValidStaminaPointCost()
{
    ExpectTrue(ResearchItem->addTestSpecification("stamina point cost", 20), "add stamina point cost specification");
    ExpectEq(20, ResearchItem->query("stamina point cost"), "can query the stamina point cost");
}

/////////////////////////////////////////////////////////////////////////////
void SettingInvalidStaminaPointCostThrowsError()
{
    string err = catch (ResearchItem->addTestSpecification("stamina point cost", "blah"));
    string expectedError = "*ERROR - sustainedResearchItem: the 'stamina point cost' specification must be an integer greater than 0.\n";
    ExpectEq(expectedError, err, "The correct exception is thrown when setting invalid value");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetValidCooldown()
{
    ExpectTrue(ResearchItem->addTestSpecification("cooldown", 5), "add cooldown specification");
    ExpectEq(5, ResearchItem->cooldown(User), "can query the cooldown");
}

/////////////////////////////////////////////////////////////////////////////
void CanModifyCooldown()
{
    destruct(User);
    User = clone_object("/lib/tests/support/services/mockPlayer.c");
    User->Name("Bob");
    User->addResearchPoints(3);

    ExpectTrue(ResearchItem->addTestSpecification("cooldown", 30), "add cooldown specification");
    ExpectTrue(ResearchItem->addTestSpecification("cooldown modifiers", ([
        "/lib/tests/support/research/comboPartResearchItemA.c": 6,
        "/lib/tests/support/research/comboPartResearchItemB.c": 4,
        "/lib/tests/support/research/comboPartResearchItemC.c": 20 ])), 
        "add cooldown modifiers specification");

    ExpectEq(30, ResearchItem->cooldown(User));

    User->initiateResearch("/lib/tests/support/research/comboPartResearchItemA.c");
    ExpectEq(24, ResearchItem->cooldown(User));

    User->initiateResearch("/lib/tests/support/research/comboPartResearchItemB.c");
    ExpectEq(20, ResearchItem->cooldown(User));

    // Cooldown cannot go below 2
    User->initiateResearch("/lib/tests/support/research/comboPartResearchItemC.c");
    ExpectEq(2, ResearchItem->cooldown(User));
}

/////////////////////////////////////////////////////////////////////////////
void SettingInvalidCooldownThrowsError()
{
    string err = catch (ResearchItem->addTestSpecification("cooldown", "blah"));
    string expectedError = "*ERROR - sustainedResearchItem: the 'cooldown' specification must be an integer greater than 0.\n";
    ExpectEq(expectedError, err, "The correct exception is thrown when setting invalid value");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetValidEventHandler()
{
    ExpectTrue(ResearchItem->addTestSpecification("event handler", "blah"), "add event handler specification");
    ExpectEq("blah", ResearchItem->query("event handler"), "can query the event handler");
}

/////////////////////////////////////////////////////////////////////////////
void SettingInvalidEventHandlerThrowsError()
{
    string err = catch (ResearchItem->addTestSpecification("event handler", 6));
    string expectedError = "*ERROR - sustainedResearchItem: the 'event handler' specification must be a string.\n";
    ExpectEq(expectedError, err, "The correct exception is thrown when setting invalid value");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetValidUseAbilityActivateMessage()
{
    ExpectTrue(ResearchItem->addTestSpecification("use ability activate message", "blah"), "add use ability activate message specification");
    ExpectEq("blah", ResearchItem->query("use ability activate message"), "can query the use ability activate message");
}

/////////////////////////////////////////////////////////////////////////////
void SettingInvalidUseAbilityActivateMessageThrowsError()
{
    string err = catch (ResearchItem->addTestSpecification("use ability activate message", 1));
    string expectedError = "*ERROR - sustainedResearchItem: the 'use ability activate message' specification must be a string.\n";
    ExpectEq(expectedError, err, "The correct exception is thrown when setting invalid value");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetValidUseAbilityDeactivateMessage()
{
    ExpectTrue(ResearchItem->addTestSpecification("use ability deactivate message", "blah"), "add use ability deactivate message specification");
    ExpectEq("blah", ResearchItem->query("use ability deactivate message"), "can query the use ability deactivate message");
}

/////////////////////////////////////////////////////////////////////////////
void SettingInvalidUseAbilityDeactivateMessageThrowsError()
{
    string err = catch (ResearchItem->addTestSpecification("use ability deactivate message", 1));
    string expectedError = "*ERROR - sustainedResearchItem: the 'use ability deactivate message' specification must be a string.\n";
    ExpectEq(expectedError, err, "The correct exception is thrown when setting invalid value");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetValidUseAbilityFailMessage()
{
    ExpectTrue(ResearchItem->addTestSpecification("use ability fail message", "blah"), "add use ability fail message specification");
    ExpectEq("blah", ResearchItem->query("use ability fail message"), "can query the use ability fail message");
}

/////////////////////////////////////////////////////////////////////////////
void SettingInvalidUseAbilityFailMessageThrowsError()
{
    string err = catch (ResearchItem->addTestSpecification("use ability fail message", 1));
    string expectedError = "*ERROR - sustainedResearchItem: the 'use ability fail message' specification must be a string.\n";
    ExpectEq(expectedError, err, "The correct exception is thrown when setting invalid value");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetValidUseAbilityCooldownMessage()
{
    ExpectTrue(ResearchItem->addTestSpecification("use ability cooldown message", "blah"), "add use ability cooldown message specification");
    ExpectEq("blah", ResearchItem->query("use ability cooldown message"), "can query the use ability cooldown message");
}

/////////////////////////////////////////////////////////////////////////////
void SettingInvalidUseAbilityCooldownMessageThrowsError()
{
    string err = catch (ResearchItem->addTestSpecification("use ability cooldown message", 1));
    string expectedError = "*ERROR - sustainedResearchItem: the 'use ability cooldown message' specification must be a string.\n";
    ExpectEq(expectedError, err, "The correct exception is thrown when setting invalid value");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetValidCommandTemplate()
{
    ExpectFalse(ResearchItem->canExecuteCommand("blah"), "cannot execute before template set");
    ExpectTrue(ResearchItem->addTestSpecification("command template", "blah"), "add command template specification");
    ExpectTrue(ResearchItem->canExecuteCommand("blah"), "can execute the command template");
}

/////////////////////////////////////////////////////////////////////////////
void SettingInvalidCommandTemplateThrowsError()
{
    string err = catch (ResearchItem->addTestSpecification("command template", 2));
    string expectedError = "*ERROR - sustainedResearchItem: the 'command template' specification must be a string.\n";
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
    ResearchItem->addTestSpecification("scope", "self");
    User->ToggleMockResearch();
    ExpectTrue(ResearchItem->execute("the command", User), "Cooldown is initially false");
    User->ToggleCooldown();
    ExpectFalse(ResearchItem->execute("the command", User), "Cooldown is set to true and execute fails");
}

/////////////////////////////////////////////////////////////////////////////
void CallingExecuteWithSustainedHPCostWillDecreaseHP()
{
    ResearchItem->addTestSpecification("scope", "self");
    ResearchItem->addTestSpecification("hit point cost", 20);

    User->ToggleMockResearch();
    ExpectEq(164, User->maxHitPoints());
    ExpectTrue(ResearchItem->execute("the command", User), "initially have enough points");
    ExpectEq(144, User->maxHitPoints());
}

/////////////////////////////////////////////////////////////////////////////
void DeactivatingWithHitPointCostReturnsHPToOriginalValue()
{
    ResearchItem->addTestSpecification("scope", "self");
    ResearchItem->addTestSpecification("hit point cost", 20);

    User->ToggleMockResearch();
    ExpectEq(164, User->maxHitPoints());
    ExpectTrue(ResearchItem->execute("the command", User), "initially have enough points");
    ExpectEq(144, User->maxHitPoints());
    ExpectTrue(ResearchItem->execute("the command", User), "second execution");
    ExpectEq(164, User->maxHitPoints(), "value returned to 164");
}

/////////////////////////////////////////////////////////////////////////////
void CallingExecuteWithSustainedSPCostWillDecreaseSP()
{
    ResearchItem->addTestSpecification("scope", "self");
    ResearchItem->addTestSpecification("spell point cost", 20);

    User->ToggleMockResearch();
    ExpectEq(164, User->maxSpellPoints());
    ExpectTrue(ResearchItem->execute("the command", User), "initially have enough points");
    ExpectEq(144, User->maxSpellPoints());
}

/////////////////////////////////////////////////////////////////////////////
void DeactivatingWithSepllPointCostReturnsSPToOriginalValue()
{
    ResearchItem->addTestSpecification("scope", "self");
    ResearchItem->addTestSpecification("spell point cost", 20);

    User->ToggleMockResearch();
    ExpectEq(164, User->maxSpellPoints());
    ExpectTrue(ResearchItem->execute("the command", User), "initially have enough points");
    ExpectEq(144, User->maxSpellPoints());
    ExpectTrue(ResearchItem->execute("the command", User), "second execution");
    ExpectEq(164, User->maxSpellPoints());
}

/////////////////////////////////////////////////////////////////////////////
void CallingExecuteWithSustainedStaminaCostWillDecreaseStamina()
{
    ResearchItem->addTestSpecification("scope", "self");
    ResearchItem->addTestSpecification("stamina point cost", 20);

    User->ToggleMockResearch();
    ExpectEq(164, User->maxStaminaPoints());
    ExpectTrue(ResearchItem->execute("the command", User), "initially have enough points");
    ExpectEq(144, User->maxStaminaPoints());
}

/////////////////////////////////////////////////////////////////////////////
void DeactivatingWithStaminaPointCostReturnsStaminaToOriginalValue()
{
    ResearchItem->addTestSpecification("scope", "self");
    ResearchItem->addTestSpecification("stamina point cost", 150);

    User->ToggleMockResearch();
    ExpectEq(164, User->maxStaminaPoints());
    ExpectTrue(ResearchItem->execute("the command", User), "initially have enough points");
    ExpectEq(14, User->maxStaminaPoints());
    ExpectTrue(ResearchItem->execute("the command", User), "second execution");
    ExpectEq(164, User->maxStaminaPoints());
}

/////////////////////////////////////////////////////////////////////////////
void CallingExecuteWithSelfScopeAppliesEffectsToUser()
{
    object weapon = clone_object("/lib/items/weapon");
    weapon->set("name", "blah");
    weapon->set("defense class", 2);
    weapon->set("weapon class", 10);
    weapon->set("material", "galvorn");
    weapon->set("weapon type", "long sword");
    weapon->set("equipment locations", OnehandedWeapon);
    move_object(weapon, User);
    weapon->equip("blah");

    ResearchItem->addTestSpecification("scope", "self");
    ResearchItem->addTestSpecification("hit point cost", 20);
    ResearchItem->addTestSpecification("bonus strength", 5);
    ResearchItem->addTestSpecification("bonus long sword", 5);
    ResearchItem->addTestSpecification("bonus magical attack", 10);
    ResearchItem->addTestSpecification("bonus weapon attack", 2);

    User->ToggleMockResearch();

    ExpectEq(5, User->getSkill("long sword"), "initial long sword skill");
    ExpectEq(22, User->Str(), "initial strength");
    ExpectEq("({ ([ attack type: wielded primary, ]), ([ attack type: wielded primary, ]), })", User->getAttacks(), "only one attack initially");
    ExpectTrue(ResearchItem->execute("the command", User), "initially have enough points");

    object modifier = User->registeredInventoryObject(program_name(ResearchItem) + "#" + User->RealName());
    ExpectEq("/lib/tests/support/research/testSustainedResearchItem.c#Bob",
        modifier->query("fully qualified name"), "Modifier with FQN is registered");

    ExpectEq(10, User->getSkill("long sword"), "long sword skill after ability used");
    ExpectEq(27, User->Str(), "strength after ability used");

    mapping *expectedAttacks = ({ 
        (["attack type":"magical", "damage" : 10, "to hit" : 60]), 
        (["attack type":"wielded primary"]), 
        (["attack type":"wielded primary"]), 
        (["attack type":"wielded primary"]), 
        (["attack type":"wielded primary"]) });
    ExpectEq(expectedAttacks, User->getAttacks(), "Three weapon attacks and a magical attack are returned");
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteOnSelfAppliesCombatEffectOnSelf()
{
    User->ToggleMockResearch();
    ResearchItem->addTestSpecification("scope", "self");
    ResearchItem->addTestSpecification("hit point cost", 20);

    ExpectTrue(ResearchItem->addTestSpecification("apply haste", 1));

    ExpectTrue(ResearchItem->execute("the command", User), "can execute command");

    object modifier = User->registeredInventoryObject(program_name(ResearchItem) + "#" + User->RealName());
    ExpectEq("/lib/tests/support/research/testSustainedResearchItem.c#Bob",
        modifier->query("fully qualified name"), "Modifier with FQN is registered");

    ExpectTrue(User->inventoryGetModifier("combatModifiers", "haste"));
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteOnTargetAppliesEffectOnTarget()
{
    User->ToggleMockResearch();
    ResearchItem->addTestSpecification("scope", "targeted");
    ExpectTrue(ResearchItem->addTestSpecification("bonus long sword", 5));

    ExpectEq(10, Target->getSkill("long sword"), "initial long sword skill");
    ExpectTrue(ResearchItem->execute("throw turnip at frank", User), "can execute command");

    object modifier = Target->registeredInventoryObject(program_name(ResearchItem) + "#" + User->RealName());
    ExpectEq("/lib/tests/support/research/testSustainedResearchItem.c#Bob",
        modifier->query("fully qualified name"), "Modifier with FQN is registered");

    ExpectEq(15, Target->getSkill("long sword"), "long sword skill after research used");
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteOnTargetAppliesCombatEffectOnTarget()
{
    User->ToggleMockResearch();
    ResearchItem->addTestSpecification("scope", "targeted");
    ExpectTrue(ResearchItem->addTestSpecification("apply haste", 1));

    ExpectTrue(ResearchItem->execute("throw turnip at frank", User), "can execute command");

    object modifier = Target->registeredInventoryObject(program_name(ResearchItem) + "#" + User->RealName());
    ExpectEq("/lib/tests/support/research/testSustainedResearchItem.c#Bob",
        modifier->query("fully qualified name"), "Modifier with FQN is registered");

    ExpectTrue(Target->inventoryGetModifier("combatModifiers", "haste"));
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteOnTargetDoesNotApplyCombatEffectOnTargetIfKillListNotTrueForBoth()
{
    destruct(Target);
    object Target = clone_object("/lib/tests/support/services/combatWithMockServices");
    Target->Name("Frank");
    Target->addAlias("frank");
    move_object(Target, Room);

    User->ToggleMockResearch();
    ResearchItem->addTestSpecification("scope", "targeted");
    ExpectTrue(ResearchItem->addTestSpecification("apply slow", 1));

    ExpectFalse(ResearchItem->execute("throw turnip at frank", User), "can execute command");
    ExpectFalse(Target->inventoryGetModifier("combatModifiers", "slow"));
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteOnTargetAppliesCombatEffectOnTargetIfKillListTrueForBoth()
{
    destruct(Target);
    object Target = clone_object("/lib/tests/support/services/combatWithMockServices");
    Target->Name("Frank");
    Target->addAlias("frank");
    Target->toggleKillList();
    move_object(Target, Room);

    User->ToggleMockResearch();
    ResearchItem->addTestSpecification("scope", "targeted");
    ExpectTrue(ResearchItem->addTestSpecification("apply slow", 1));

    ExpectTrue(ResearchItem->execute("throw turnip at frank", User), "can execute command");
    ExpectTrue(Target->inventoryGetModifier("combatModifiers", "slow"));
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteOnTargetAppliesNegativeEffect()
{
    User->ToggleMockResearch();
    ResearchItem->addTestSpecification("scope", "targeted");
    ExpectTrue(ResearchItem->addTestSpecification("penalty to long sword", 5));

    ExpectEq(10, Target->getSkill("long sword"), "initial long sword skill");
    ExpectTrue(ResearchItem->execute("throw turnip at frank", User), "can execute command");

    ExpectTrue(Target->registeredInventoryObject(program_name(ResearchItem) + "#" + User->RealName()));
    ExpectEq(5, Target->getSkill("long sword"), "long sword skill after research used");
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteOnTargetFailsIfEffectNegativeAndTargetNotOnKillList()
{
    User->ToggleMockResearch();
    ResearchItem->addTestSpecification("scope", "targeted");
    destruct(Target);
    object Target = clone_object("/lib/tests/support/services/combatWithMockServices");
    Target->Name("Frank");
    Target->addAlias("frank");
    move_object(Target, Room);

    ExpectTrue(ResearchItem->addTestSpecification("penalty to long sword", 5));

    ExpectFalse(ResearchItem->execute("throw turnip at frank", User), "can execute command");

    ExpectFalse(Target->registeredInventoryObject(program_name(ResearchItem) + "#" + User->RealName()));
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteOnTargetFailsIfEffectNegativeAndTargetButNotUserOnKillList()
{
    User->ToggleMockResearch();
    ResearchItem->addTestSpecification("scope", "targeted");
    User->toggleKillList();

    destruct(Target);
    object Target = clone_object("/lib/tests/support/services/combatWithMockServices");
    Target->Name("Frank");
    Target->addAlias("frank");
    Target->toggleKillList();
    move_object(Target, Room);

    ExpectTrue(ResearchItem->addTestSpecification("penalty to long sword", 5));

    ExpectFalse(ResearchItem->execute("throw turnip at frank", User), "can execute command");

    ExpectFalse(Target->registeredInventoryObject(program_name(ResearchItem) + "#" + User->RealName()));
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteOnTargetAppliedIfBothPlayersOnKillList()
{
    User->ToggleMockResearch();
    ResearchItem->addTestSpecification("scope", "targeted");
    destruct(Target);
    object Target = clone_object("/lib/tests/support/services/combatWithMockServices");
    Target->Name("Frank");
    Target->addAlias("frank");
    Target->toggleKillList();
    Target->Str(20);
    Target->Int(20);
    Target->Dex(20);
    Target->Con(20);
    Target->Wis(20);
    Target->Chr(20);
    Target->addSkillPoints(200);
    Target->advanceSkill("long sword", 10);
    move_object(Target, Room);

    ExpectTrue(ResearchItem->addTestSpecification("penalty to long sword", 5));

    ExpectEq(10, Target->getSkill("long sword"), "initial long sword skill");
    ExpectTrue(ResearchItem->execute("throw turnip at frank", User), "can execute command");

    ExpectTrue(Target->registeredInventoryObject(program_name(ResearchItem) + "#" + User->RealName()));
    ExpectEq(5, Target->getSkill("long sword"), "long sword skill after research used");
}

/////////////////////////////////////////////////////////////////////////////
void NegativeExecuteInAreaAppliedOnCorrectTargets()
{
    User->ToggleMockResearch();
    ResearchItem->addTestSpecification("scope", "area");
    object bystander = clone_object("/lib/tests/support/services/combatWithMockServices");
    bystander->Name("Earl");
    bystander->addAlias("earl");
    bystander->Str(20);
    bystander->addSkillPoints(200);
    bystander->advanceSkill("long sword", 10);
    move_object(bystander, Room);

    object badguy = clone_object("/lib/realizations/monster");
    badguy->Name("Fred");
    badguy->addAlias("fred");
    badguy->Str(20);
    badguy->addSkillPoints(200);
    badguy->advanceSkill("long sword", 10);
    move_object(badguy, Room);

    ExpectTrue(ResearchItem->addTestSpecification("penalty to long sword", 5));

    ExpectEq(5, User->getSkill("long sword"), "initial user long sword skill");
    ExpectEq(10, Target->getSkill("long sword"), "initial target long sword skill");
    ExpectEq(10, bystander->getSkill("long sword"), "initial bystander long sword skill");
    ExpectEq(10, badguy->getSkill("long sword"), "initial badguy long sword skill");
    ExpectTrue(ResearchItem->execute("the command", User), "can execute command");

    ExpectFalse(User->registeredInventoryObject(program_name(ResearchItem) + "#" + User->RealName()));
    ExpectTrue(Target->registeredInventoryObject(program_name(ResearchItem) + "#" + User->RealName()));
    ExpectTrue(badguy->registeredInventoryObject(program_name(ResearchItem) + "#" + User->RealName()));
    ExpectFalse(bystander->registeredInventoryObject(program_name(ResearchItem) + "#" + User->RealName()));
    ExpectEq(5, User->getSkill("long sword"), "user long sword skill after research used");
    ExpectEq(5, Target->getSkill("long sword"), "target long sword skill after research used");
    ExpectEq(10, bystander->getSkill("long sword"), "bystander long sword skill after research used");
    ExpectEq(5, badguy->getSkill("long sword"), "badguy long sword skill after research used");
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteInAreaAppliedOnCorrectTargets()
{
    User->ToggleMockResearch();
    ResearchItem->addTestSpecification("scope", "area");
    object bystander = clone_object("/lib/tests/support/services/combatWithMockServices");
    bystander->Name("Earl");
    bystander->addAlias("earl");
    bystander->Str(20);
    bystander->addSkillPoints(200);
    bystander->advanceSkill("long sword", 10);
    move_object(bystander, Room);

    object badguy = clone_object("/lib/realizations/monster");
    badguy->Name("Fred");
    badguy->addAlias("fred");
    badguy->Str(20);
    badguy->addSkillPoints(200);
    badguy->advanceSkill("long sword", 10);
    move_object(badguy, Room);

    ExpectTrue(ResearchItem->addTestSpecification("bonus long sword", 5));

    ExpectEq(5, User->getSkill("long sword"), "initial user long sword skill");
    ExpectEq(10, Target->getSkill("long sword"), "initial target long sword skill");
    ExpectEq(10, bystander->getSkill("long sword"), "initial bystander long sword skill");
    ExpectEq(10, badguy->getSkill("long sword"), "initial badguy long sword skill");
    ExpectTrue(ResearchItem->execute("the command", User), "can execute command");

    ExpectTrue(User->registeredInventoryObject(program_name(ResearchItem) + "#" + User->RealName()));
    ExpectFalse(Target->registeredInventoryObject(program_name(ResearchItem) + "#" + User->RealName()));
    ExpectFalse(badguy->registeredInventoryObject(program_name(ResearchItem) + "#" + User->RealName()));
    ExpectTrue(bystander->registeredInventoryObject(program_name(ResearchItem) + "#" + User->RealName()));
    ExpectEq(10, User->getSkill("long sword"), "user long sword skill after research used");
    ExpectEq(10, Target->getSkill("long sword"), "target long sword skill after research used");
    ExpectEq(15, bystander->getSkill("long sword"), "bystander long sword skill after research used");
    ExpectEq(10, badguy->getSkill("long sword"), "badguy long sword skill after research used");
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteOnSelfAppliesTraitOnSelf()
{
    ResearchItem->addTestSpecification("scope", "self");
    ResearchItem->addTestSpecification("hit point cost", 20);
    ResearchItem->addTestSpecification("trait", "/lib/tests/support/traits/testTraitForSustainedResearch.c");

    User->ToggleMockResearch();
    ExpectTrue(ResearchItem->execute("the command", User), "can execute command");
    ExpectTrue(User->isTraitOf("/lib/tests/support/traits/testTraitForSustainedResearch.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteOnTargetAppliesTraitOnTarget()
{
    User->ToggleMockResearch();
    ResearchItem->addTestSpecification("scope", "targeted");
    ResearchItem->addTestSpecification("hit point cost", 20);
    ResearchItem->addTestSpecification("trait", "/lib/tests/support/traits/testTraitForSustainedResearch.c");

    ExpectTrue(ResearchItem->execute("throw turnip at frank", User), "can execute command");
    ExpectTrue(Target->isTraitOf("/lib/tests/support/traits/testTraitForSustainedResearch.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteOnTargetAppliesNegativeTrait()
{
    User->ToggleMockResearch();
    ResearchItem->addTestSpecification("scope", "targeted");
    ResearchItem->addTestSpecification("hit point cost", 20);
    ResearchItem->addTestSpecification("negative trait", "/lib/tests/support/traits/testTraitForSustainedResearch.c");

    ExpectTrue(ResearchItem->execute("throw turnip at frank", User), "can execute command");
    ExpectTrue(Target->isTraitOf("/lib/tests/support/traits/testTraitForSustainedResearch.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteOnTargetFailsIfTraitNegativeAndTargetNotOnKillList()
{
    User->ToggleMockResearch();
    destruct(Target);
    object Target = clone_object("/lib/tests/support/services/combatWithMockServices");
    Target->Name("Frank");
    Target->addAlias("frank");
    move_object(Target, Room);

    ResearchItem->addTestSpecification("scope", "targeted");
    ResearchItem->addTestSpecification("hit point cost", 20);
    ResearchItem->addTestSpecification("negative trait", "/lib/tests/support/traits/testTraitForSustainedResearch.c");

    ExpectFalse(ResearchItem->execute("throw turnip at frank", User), "can execute command");
    ExpectFalse(Target->isTraitOf("/lib/tests/support/traits/testTraitForSustainedResearch.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteOnTargetFailsIfTraitNegativeAndTargetButNotUserOnKillList()
{
    User->ToggleMockResearch();
    User->toggleKillList();

    destruct(Target);
    object Target = clone_object("/lib/tests/support/services/combatWithMockServices");
    Target->Name("Frank");
    Target->addAlias("frank");
    Target->toggleKillList();
    move_object(Target, Room);

    ResearchItem->addTestSpecification("scope", "targeted");
    ResearchItem->addTestSpecification("hit point cost", 20);
    ResearchItem->addTestSpecification("negative trait", "/lib/tests/support/traits/testTraitForSustainedResearch.c");

    ExpectFalse(ResearchItem->execute("throw turnip at frank", User), "can execute command");
    ExpectFalse(Target->isTraitOf("/lib/tests/support/traits/testTraitForSustainedResearch.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteOnTargetAppliesTraitIfBothPlayersOnKillList()
{
    User->ToggleMockResearch();

    destruct(Target);
    object Target = clone_object("/lib/tests/support/services/combatWithMockServices");
    Target->Name("Frank");
    Target->addAlias("frank");
    Target->toggleKillList();
    Target->Str(20);
    Target->Int(20);
    Target->Dex(20);
    Target->Con(20);
    Target->Wis(20);
    Target->Chr(20);
    Target->addSkillPoints(200);
    Target->advanceSkill("long sword", 10);
    move_object(Target, Room);

    ResearchItem->addTestSpecification("scope", "targeted");
    ResearchItem->addTestSpecification("hit point cost", 20);
    ResearchItem->addTestSpecification("negative trait", "/lib/tests/support/traits/testTraitForSustainedResearch.c");

    ExpectTrue(ResearchItem->execute("throw turnip at frank", User), "can execute command");
    ExpectTrue(Target->isTraitOf("/lib/tests/support/traits/testTraitForSustainedResearch.c"));
}

/////////////////////////////////////////////////////////////////////////////
void NegativeExecuteInAreaAppliesTraitOnCorrectTargets()
{
    User->ToggleMockResearch();

    object bystander = clone_object("/lib/tests/support/services/combatWithMockServices");
    bystander->Name("Earl");
    bystander->addAlias("earl");
    bystander->Str(20);
    bystander->addSkillPoints(200);
    bystander->advanceSkill("long sword", 10);
    move_object(bystander, Room);

    object badguy = clone_object("/lib/realizations/monster");
    badguy->Name("Fred");
    badguy->addAlias("fred");
    badguy->Str(20);
    badguy->addSkillPoints(200);
    badguy->advanceSkill("long sword", 10);
    move_object(badguy, Room);

    ResearchItem->addTestSpecification("scope", "area");
    ResearchItem->addTestSpecification("hit point cost", 20);
    ResearchItem->addTestSpecification("negative trait", "/lib/tests/support/traits/testTraitForSustainedResearch.c");

    ExpectTrue(ResearchItem->execute("throw turnip at frank", User), "can execute command");
    ExpectTrue(Target->isTraitOf("/lib/tests/support/traits/testTraitForSustainedResearch.c"));
    ExpectFalse(User->isTraitOf("/lib/tests/support/traits/testTraitForSustainedResearch.c"));
    ExpectTrue(badguy->isTraitOf("/lib/tests/support/traits/testTraitForSustainedResearch.c"));
    ExpectFalse(bystander->isTraitOf("/lib/tests/support/traits/testTraitForSustainedResearch.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteInAreaAppliesTraitOnCorrectTargets()
{
    User->ToggleMockResearch();
    object bystander = clone_object("/lib/tests/support/services/combatWithMockServices");
    bystander->Name("Earl");
    bystander->addAlias("earl");
    bystander->Str(20);
    bystander->addSkillPoints(200);
    bystander->advanceSkill("long sword", 10);
    move_object(bystander, Room);

    object badguy = clone_object("/lib/realizations/monster");
    badguy->Name("Fred");
    badguy->addAlias("fred");
    badguy->Str(20);
    badguy->addSkillPoints(200);
    badguy->advanceSkill("long sword", 10);
    move_object(badguy, Room);

    ResearchItem->addTestSpecification("scope", "area");
    ResearchItem->addTestSpecification("hit point cost", 20);
    ResearchItem->addTestSpecification("trait", "/lib/tests/support/traits/testTraitForSustainedResearch.c");

    ExpectTrue(ResearchItem->execute("throw turnip at frank", User), "can execute command");
    ExpectFalse(Target->isTraitOf("/lib/tests/support/traits/testTraitForSustainedResearch.c"), "target");
    ExpectTrue(User->isTraitOf("/lib/tests/support/traits/testTraitForSustainedResearch.c"), "user");
    ExpectFalse(badguy->isTraitOf("/lib/tests/support/traits/testTraitForSustainedResearch.c"), "badguy");
    ExpectTrue(bystander->isTraitOf("/lib/tests/support/traits/testTraitForSustainedResearch.c"), "bystander");
}
