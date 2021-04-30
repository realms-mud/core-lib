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
void Setup()
{
    ResearchItem = clone_object("/lib/tests/support/research/testPersistedActiveResearchItem");
    ResearchItem->testAddSpecification("command template", "throw turnip at ##Target##");
    ResearchItem->testAddSpecification("scope", "targeted");

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
    User->advanceSkill("long sword", 5);
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
void AddSpecificationAllowsValidBonusesToBeApplied()
{
    ExpectTrue(ResearchItem->testAddSpecification("bonus hit points", 10));
    ExpectTrue(ResearchItem->testAddSpecification("bonus long sword", 10));
    ExpectTrue(ResearchItem->testAddSpecification("bonus strength", 10));
    ExpectTrue(ResearchItem->testAddSpecification("bonus magical attack", 1));
}

/////////////////////////////////////////////////////////////////////////////
void AddSpecificationThrowsForInvalidBonuses()
{
    string err = catch (ResearchItem->testAddSpecification("bonus blarg", 10));
    string expectedError = "*ERROR - persistedActiveResearchItem: the 'bonus blarg' specification must be a valid modifier as defined in /lib/dictionaries/bonusesDictionary.c\n";

    ExpectEq(expectedError, err, "The correct exception is thrown when setting invalid value");
}

/////////////////////////////////////////////////////////////////////////////
void AddSpecificationAllowsValidPenaltiesToBeApplied()
{
    ExpectTrue(ResearchItem->testAddSpecification("penalty to attack", 5));
    ExpectTrue(ResearchItem->testAddSpecification("penalty to heal spell points rate", 10));
    ExpectTrue(ResearchItem->testAddSpecification("penalty to strength", 10));
}

/////////////////////////////////////////////////////////////////////////////
void AddSpecificationThrowsForInvalidPenalties()
{
    string err = catch (ResearchItem->testAddSpecification("penalty to blarg", 10));
    string expectedError = "*ERROR - persistedActiveResearchItem: the 'penalty to blarg' specification must be a valid modifier as defined in /lib/dictionaries/bonusesDictionary.c\n";

    ExpectEq(expectedError, err, "The correct exception is thrown when setting invalid value");
}

/////////////////////////////////////////////////////////////////////////////
void AddSpecificationAllowsValidCombatModifiersToBeApplied()
{
    ExpectTrue(ResearchItem->testAddSpecification("apply haste", 1));
    ExpectTrue(ResearchItem->testAddSpecification("apply slow", 1));
    ExpectTrue(ResearchItem->testAddSpecification("apply enfeebled", 1));
    ExpectTrue(ResearchItem->testAddSpecification("apply fortified", 1));
    ExpectTrue(ResearchItem->testAddSpecification("apply poison", 1));
    ExpectTrue(ResearchItem->testAddSpecification("apply paralysis", 1));
    ExpectTrue(ResearchItem->testAddSpecification("apply disease", 1));
    ExpectTrue(ResearchItem->testAddSpecification("apply damage reflection", 20));
}

/////////////////////////////////////////////////////////////////////////////
void AddSpecificationThrowsForInvalidCombatModifiers()
{
    string err = catch (ResearchItem->testAddSpecification("apply blarg", 10));
    string expectedError = "*ERROR - persistedActiveResearchItem: the 'apply blarg' specification must be a valid modifier as defined in /lib/dictionaries/bonusesDictionary.c\n";

    ExpectEq(expectedError, err, "The correct exception is thrown when setting invalid value");
}

/////////////////////////////////////////////////////////////////////////////
void AddSpecificationAllowsTraitToBeApplied()
{
    ExpectTrue(ResearchItem->testAddSpecification("trait", "/lib/tests/support/traits/testTraitWithDuration.c"));
}

/////////////////////////////////////////////////////////////////////////////
void AddSpecificationDoesNotAllowNonEffectTraitsToBeApplied()
{
    string err = catch (ResearchItem->testAddSpecification("trait", "/lib/tests/support/traits/testInvalidPersistedTrait.c"));
    string expectedError = "*ERROR - persistedActiveResearchItem: the trait specification must be a valid effect-based trait.\n";

    ExpectEq(expectedError, err, "The correct exception is thrown when setting invalid value");
}

/////////////////////////////////////////////////////////////////////////////
void AddSpecificationAllowsNegativeTraitToBeApplied()
{
    ExpectTrue(ResearchItem->testAddSpecification("negative trait", "/lib/tests/support/traits/testTraitWithDuration.c"));
}

/////////////////////////////////////////////////////////////////////////////
void AddSpecificationDoesNotAllowNonEffectNegativeTraitsToBeApplied()
{
    string err = catch (ResearchItem->testAddSpecification("negative trait", "/lib/tests/support/traits/testInvalidPersistedTrait.c"));
    string expectedError = "*ERROR - persistedActiveResearchItem: the trait specification must be a valid effect-based trait.\n";

    ExpectEq(expectedError, err, "The correct exception is thrown when setting invalid value");
}

/////////////////////////////////////////////////////////////////////////////
void AddSpecificationAllowsDurationToBeApplied()
{
    ExpectTrue(ResearchItem->testAddSpecification("duration", 30));
}

/////////////////////////////////////////////////////////////////////////////
void AddSpecificationDoesNotAllowNegativeDuration()
{
    string err = catch (ResearchItem->testAddSpecification("duration", -10));
    string expectedError = "*ERROR - persistedActiveResearchItem: the duration specification must be a positive integer.\n";

    ExpectEq(expectedError, err, "The correct exception is thrown when setting invalid value");
}

/////////////////////////////////////////////////////////////////////////////
void DurationMustBeAnInteger()
{
    string err = catch (ResearchItem->testAddSpecification("duration", "blah"));
    string expectedError = "*ERROR - persistedActiveResearchItem: the duration specification must be a positive integer.\n";

    ExpectEq(expectedError, err, "The correct exception is thrown when setting invalid value");
}

/////////////////////////////////////////////////////////////////////////////
void AddSpecificationAllowsValidModifierToBeSet()
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

    ExpectTrue(ResearchItem->testAddSpecification("modifiers", modifiers));
}

/////////////////////////////////////////////////////////////////////////////
void AddSpecificationDoesNotAllowInvalidModifierToBeSet()
{
    mapping *modifiers = ({ ([
        "type":"skill",
        "name": "long sword",
        "formula": "additive",
        "rate": 1.25
    ]),
    ([
        "type":"modifier that will fail",
        "name": "strength",
        "rate": 0.25
    ]) });

    string err = catch (ResearchItem->testAddSpecification("modifiers", modifiers));
    string expectedError = "*ERROR - persistedActiveResearchItem: the 'modifiers' specification must be a properly formatted modifier.\n";

    ExpectEq(expectedError, err, "The correct exception is thrown when setting invalid value");

}

/////////////////////////////////////////////////////////////////////////////
void AddSpecificationDoesNotAllowMalformedModifierToBeSet()
{
    string err = catch (ResearchItem->testAddSpecification("modifiers", "blah"));
    string expectedError = "*ERROR - persistedActiveResearchItem: the 'modifiers' specification must be a properly formatted modifier.\n";

    ExpectEq(expectedError, err, "The correct exception is thrown when setting invalid value");
}

/////////////////////////////////////////////////////////////////////////////
void GetTargetReturnsFalseIfCommandDoesNotParse()
{
    ExpectFalse(ResearchItem->testGetTarget(User, "flumfrug blibblefro"));
}

/////////////////////////////////////////////////////////////////////////////
void GetTargetReturnsFalseIfTargetDoesNotExist()
{
    ExpectFalse(ResearchItem->testGetTarget(User, "throw turnip at gertrude"));
}

/////////////////////////////////////////////////////////////////////////////
void GetTargetReturnsFalseIfTargetNotPresent()
{
    object room = clone_object("/lib/environment/environment");
    move_object(Target, room);

    ExpectFalse(ResearchItem->testGetTarget(User, "throw turnip at frank"));
}

/////////////////////////////////////////////////////////////////////////////
void GetTargetReturnsValidTarget()
{
    ExpectEq(Target, ResearchItem->testGetTarget(User, "throw turnip at frank"));
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteOnSelfAppliesEffectOnSelf()
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

    ExpectTrue(ResearchItem->testAddSpecification("bonus long sword", 10));
    ExpectTrue(ResearchItem->testAddSpecification("bonus magical attack", 10));
    ExpectTrue(ResearchItem->testAddSpecification("bonus weapon attack", 2));
    ExpectTrue(ResearchItem->testAddSpecification("duration", 10));

    ExpectEq(5, User->getSkill("long sword"), "initial long sword skill");
    ExpectEq("({ ([ attack type: wielded primary, ]), })", User->getAttacks(), "only one attack initially");
    ExpectTrue(ResearchItem->testExecuteOnSelf("command", User, program_name(ResearchItem)), "can execute command");

    object modifier = User->registeredInventoryObject(program_name(ResearchItem) + "#" + User->RealName());
    ExpectEq("/lib/tests/support/research/testPersistedActiveResearchItem.c#Bob", 
        modifier->query("fully qualified name"), "Modifier with FQN is registered");

    ExpectEq(15, User->getSkill("long sword"), "long sword skill after research used");

    mapping *expectedAttacks = ({ (["attack type": "magical", "damage": 10, "to hit": 60]), (["attack type":"wielded primary"]), (["attack type":"wielded primary"]), (["attack type":"wielded primary"]) });
    ExpectEq(expectedAttacks, User->getAttacks(), "Three weapon attacks and a magical attack are returned");
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteOnSelfAppliesCombatEffectOnSelf()
{
    ExpectTrue(ResearchItem->testAddSpecification("apply haste", 1));
    ExpectTrue(ResearchItem->testAddSpecification("duration", 10));

    ExpectTrue(ResearchItem->testExecuteOnSelf("command", User, program_name(ResearchItem)), "can execute command");

    object modifier = User->registeredInventoryObject(program_name(ResearchItem) + "#" + User->RealName());
    ExpectEq("/lib/tests/support/research/testPersistedActiveResearchItem.c#Bob",
        modifier->query("fully qualified name"), "Modifier with FQN is registered");

    ExpectTrue(User->inventoryGetModifier("combatModifiers", "haste"));
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteOnSelfCanBeDoneMultipleTimes()
{
    ExpectTrue(ResearchItem->testAddSpecification("bonus long sword", 10));
    ExpectTrue(ResearchItem->testAddSpecification("duration", 10));

    ExpectTrue(ResearchItem->testExecuteOnSelf("command", User, program_name(ResearchItem)), "can execute command");
    ExpectEq(15, User->getSkill("long sword"), "long sword skill after research used first time");

    ExpectTrue(ResearchItem->testAddSpecification("bonus long sword", 12));
    ExpectTrue(ResearchItem->testExecuteOnSelf("command", User, program_name(ResearchItem)), "can execute command second time");
    ExpectEq(17, User->getSkill("long sword"), "long sword skill after research used second time");
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteOnTargetAppliesEffectOnTarget()
{
    ExpectTrue(ResearchItem->testAddSpecification("bonus long sword", 5));
    ExpectTrue(ResearchItem->testAddSpecification("duration", 10));

    ExpectEq(10, Target->getSkill("long sword"), "initial long sword skill");
    ExpectTrue(ResearchItem->testExecuteOnTarget("throw turnip at frank", User, program_name(ResearchItem)), "can execute command");

    object modifier = Target->registeredInventoryObject(program_name(ResearchItem) + "#" + User->RealName());
    ExpectEq("/lib/tests/support/research/testPersistedActiveResearchItem.c#Bob",
        modifier->query("fully qualified name"), "Modifier with FQN is registered");

    ExpectEq(15, Target->getSkill("long sword"), "long sword skill after research used");
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteOnTargetAppliesNegativeEffect()
{
    ExpectTrue(ResearchItem->testAddSpecification("penalty to long sword", 5));
    ExpectTrue(ResearchItem->testAddSpecification("duration", 10));

    ExpectEq(10, Target->getSkill("long sword"), "initial long sword skill");
    ExpectTrue(ResearchItem->testExecuteOnTarget("throw turnip at frank", User, program_name(ResearchItem)), "can execute command");

    ExpectTrue(Target->registeredInventoryObject(program_name(ResearchItem) + "#" + User->RealName()));
    ExpectEq(5, Target->getSkill("long sword"), "long sword skill after research used");
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteOnTargetFailsIfEffectNegativeAndTargetNotOnKillList()
{
    destruct(Target);
    object Target = clone_object("/lib/tests/support/services/combatWithMockServices");
    Target->Name("Frank");
    Target->addAlias("frank");
    move_object(Target, Room);

    ExpectTrue(ResearchItem->testAddSpecification("penalty to long sword", 5));
    ExpectTrue(ResearchItem->testAddSpecification("duration", 10));

    ExpectFalse(ResearchItem->testExecuteOnTarget("throw turnip at frank", User, program_name(ResearchItem)), "can execute command");

    ExpectFalse(Target->registeredInventoryObject(program_name(ResearchItem) + "#" + User->RealName()));
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteOnTargetFailsIfEffectNegativeAndTargetButNotUserOnKillList()
{
    User->toggleKillList();

    destruct(Target);
    object Target = clone_object("/lib/tests/support/services/combatWithMockServices");
    Target->Name("Frank");
    Target->addAlias("frank");
    Target->toggleKillList();
    move_object(Target, Room);

    ExpectTrue(ResearchItem->testAddSpecification("penalty to long sword", 5));
    ExpectTrue(ResearchItem->testAddSpecification("duration", 10));

    ExpectFalse(ResearchItem->testExecuteOnTarget("throw turnip at frank", User, program_name(ResearchItem)), "can execute command");

    ExpectFalse(Target->registeredInventoryObject(program_name(ResearchItem) + "#" + User->RealName()));
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteOnTargetAppliedIfBothPlayersOnKillList()
{
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

    ExpectTrue(ResearchItem->testAddSpecification("penalty to long sword", 5));
    ExpectTrue(ResearchItem->testAddSpecification("duration", 10));

    ExpectEq(10, Target->getSkill("long sword"), "initial long sword skill");
    ExpectTrue(ResearchItem->testExecuteOnTarget("throw turnip at frank", User, program_name(ResearchItem)), "can execute command");

    ExpectTrue(Target->registeredInventoryObject(program_name(ResearchItem) + "#" + User->RealName()));
    ExpectEq(5, Target->getSkill("long sword"), "long sword skill after research used");
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteOnTargetAppliesBeneficialCombatEffectOnTarget()
{
    destruct(Target);
    object Target = clone_object("/lib/tests/support/services/combatWithMockServices");
    Target->Name("Frank");
    Target->addAlias("frank");
    move_object(Target, Room);

    ExpectTrue(ResearchItem->testAddSpecification("apply haste", 1));
    ExpectTrue(ResearchItem->testAddSpecification("duration", 10));

    ExpectTrue(ResearchItem->testExecuteOnTarget("throw turnip at frank", User, program_name(ResearchItem)), "can execute command");

    object modifier = Target->registeredInventoryObject(program_name(ResearchItem) + "#" + User->RealName());
    ExpectEq("/lib/tests/support/research/testPersistedActiveResearchItem.c#Bob",
        modifier->query("fully qualified name"), "Modifier with FQN is registered");

    ExpectTrue(Target->inventoryGetModifier("combatModifiers", "haste"));
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteOnTargetFailsIfCombatEffectNegativeAndTargetNotOnKillList()
{
    destruct(Target);
    object Target = clone_object("/lib/tests/support/services/combatWithMockServices");
    Target->Name("Frank");
    Target->addAlias("frank");
    move_object(Target, Room);

    ExpectTrue(ResearchItem->testAddSpecification("apply slow", 1));
    ExpectTrue(ResearchItem->testAddSpecification("duration", 10));

    ExpectFalse(ResearchItem->testExecuteOnTarget("throw turnip at frank", User, program_name(ResearchItem)), "can execute command");
    ExpectFalse(Target->inventoryGetModifier("combatModifiers", "slow"));
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteOnTargetSucceedsIfCombatEffectNegativeAndUserAndTargetOnKillList()
{
    destruct(Target);
    object Target = clone_object("/lib/tests/support/services/combatWithMockServices");
    Target->Name("Frank");
    Target->addAlias("frank");
    move_object(Target, Room);
    Target->toggleKillList();

    ExpectTrue(User->onKillList(), "user");
    ExpectTrue(Target->onKillList(), "targ");
    ExpectTrue(ResearchItem->testAddSpecification("apply slow", 1));
    ExpectTrue(ResearchItem->testAddSpecification("duration", 10));

    ExpectTrue(ResearchItem->testExecuteOnTarget("throw turnip at frank", User, program_name(ResearchItem)), "can execute command");

    object modifier = Target->registeredInventoryObject(program_name(ResearchItem) + "#" + User->RealName());
    ExpectEq("/lib/tests/support/research/testPersistedActiveResearchItem.c#Bob",
        modifier->query("fully qualified name"), "Modifier with FQN is registered");

    ExpectTrue(Target->inventoryGetModifier("combatModifiers", "slow"));
}

/////////////////////////////////////////////////////////////////////////////
void NegativeExecuteInAreaAppliedOnCorrectTargets()
{
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

    ExpectTrue(ResearchItem->testAddSpecification("penalty to long sword", 5));
    ExpectTrue(ResearchItem->testAddSpecification("duration", 10));

    ExpectEq(5, User->getSkill("long sword"), "initial user long sword skill");
    ExpectEq(10, Target->getSkill("long sword"), "initial target long sword skill");
    ExpectEq(10, bystander->getSkill("long sword"), "initial bystander long sword skill");
    ExpectEq(10, badguy->getSkill("long sword"), "initial badguy long sword skill");
    ExpectTrue(ResearchItem->testExecuteInArea("command", User, program_name(ResearchItem)), "can execute command");

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

    ExpectTrue(ResearchItem->testAddSpecification("bonus long sword", 5));
    ExpectTrue(ResearchItem->testAddSpecification("duration", 10));

    ExpectEq(5, User->getSkill("long sword"), "initial user long sword skill");
    ExpectEq(10, Target->getSkill("long sword"), "initial target long sword skill");
    ExpectEq(10, bystander->getSkill("long sword"), "initial bystander long sword skill");
    ExpectEq(10, badguy->getSkill("long sword"), "initial badguy long sword skill");
    ExpectTrue(ResearchItem->testExecuteInArea("command", User, program_name(ResearchItem)), "can execute command");

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
    ResearchItem->testAddSpecification("trait", "/lib/tests/support/traits/testTraitWithDuration.c");

    ExpectTrue(ResearchItem->testExecuteOnSelf("command", User, program_name(ResearchItem)), "can execute command");
    ExpectTrue(User->isTraitOf("/lib/tests/support/traits/testTraitWithDuration.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteOnTargetAppliesTraitOnTarget()
{
    ResearchItem->testAddSpecification("trait", "/lib/tests/support/traits/testTraitWithDuration.c");

    ExpectTrue(ResearchItem->testExecuteOnTarget("throw turnip at frank", User, program_name(ResearchItem)), "can execute command");
    ExpectTrue(Target->isTraitOf("/lib/tests/support/traits/testTraitWithDuration.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteOnTargetAppliesNegativeTrait()
{
    ResearchItem->testAddSpecification("negative trait", "/lib/tests/support/traits/testTraitWithDuration.c");
    ExpectTrue(ResearchItem->testExecuteOnTarget("throw turnip at frank", User, program_name(ResearchItem)), "can execute command");
    ExpectTrue(Target->isTraitOf("/lib/tests/support/traits/testTraitWithDuration.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteOnTargetFailsIfTraitNegativeAndTargetNotOnKillList()
{
    destruct(Target);
    object Target = clone_object("/lib/tests/support/services/mockPlayer.c");
    Target->Name("Frank");
    Target->addAlias("frank");
    move_object(Target, Room);

    ResearchItem->testAddSpecification("negative trait", "/lib/tests/support/traits/testTraitWithDuration.c");
    ExpectFalse(ResearchItem->testExecuteOnTarget("throw turnip at frank", User, program_name(ResearchItem)), "can execute command");
    ExpectFalse(Target->isTraitOf("/lib/tests/support/traits/testTraitWithDuration.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteOnTargetFailsIfTraitNegativeAndTargetButNotUserOnKillList()
{
    User->toggleKillList();

    destruct(Target);
    object Target = clone_object("/lib/tests/support/services/mockPlayer.c");
    Target->Name("Frank");
    Target->addAlias("frank");
    Target->toggleKillList();
    move_object(Target, Room);

    ResearchItem->testAddSpecification("negative trait", "/lib/tests/support/traits/testTraitWithDuration.c");
    ExpectFalse(ResearchItem->testExecuteOnTarget("throw turnip at frank", User, program_name(ResearchItem)), "can execute command");
    ExpectFalse(Target->isTraitOf("/lib/tests/support/traits/testTraitWithDuration.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteOnTargetAppliesTraitIfBothPlayersOnKillList()
{
    destruct(Target);
    object Target = clone_object("/lib/tests/support/services/mockPlayer.c");
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

    ResearchItem->testAddSpecification("negative trait", "/lib/tests/support/traits/testTraitWithDuration.c");
    ExpectTrue(ResearchItem->testExecuteOnTarget("throw turnip at frank", User, program_name(ResearchItem)), "can execute command");
    ExpectTrue(Target->isTraitOf("/lib/tests/support/traits/testTraitWithDuration.c"));
}

/////////////////////////////////////////////////////////////////////////////
void NegativeExecuteInAreaAppliesTraitOnCorrectTargets()
{
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

    ResearchItem->testAddSpecification("negative trait", "/lib/tests/support/traits/testTraitWithDuration.c");
    ExpectTrue(ResearchItem->testExecuteInArea("command", User, program_name(ResearchItem)), "can execute command");

    ExpectFalse(User->isTraitOf("/lib/tests/support/traits/testTraitWithDuration.c"), "user safe");
    ExpectTrue(Target->isTraitOf("/lib/tests/support/traits/testTraitWithDuration.c"), "target applied");
    ExpectTrue(badguy->isTraitOf("/lib/tests/support/traits/testTraitWithDuration.c"), "badguy applied");
    ExpectFalse(bystander->isTraitOf("/lib/tests/support/traits/testTraitWithDuration.c"), "bystander safe");
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteInAreaAppliesTraitOnCorrectTargets()
{
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

    ResearchItem->testAddSpecification("trait", "/lib/tests/support/traits/testTraitWithDuration.c");
    ExpectTrue(ResearchItem->testExecuteInArea("command", User, program_name(ResearchItem)), "can execute command");

    ExpectTrue(User->isTraitOf("/lib/tests/support/traits/testTraitWithDuration.c"));
    ExpectFalse(Target->isTraitOf("/lib/tests/support/traits/testTraitWithDuration.c"));
    ExpectFalse(badguy->isTraitOf("/lib/tests/support/traits/testTraitWithDuration.c"));
    ExpectTrue(bystander->isTraitOf("/lib/tests/support/traits/testTraitWithDuration.c"));
}

/////////////////////////////////////////////////////////////////////////////
void DisplayDetailsShowCorrectInformation()
{
    object research = load_object("/guilds/scion/paths/sword/electricity/tempest.c");
    ExpectEq("Research Name   : Tempest\n"
        "This research provides the user with the knowledge of the tempest technique.\n"
        "By means of this, the Scion is able to use their weapon as a conduit for\n"
        "emitting a powerful storm that harries a foe.\n"
        "\n"
        "Learning this costs 1 research point.\n"
        "Research Type   : Active\n"
        "Scope           : Targeted\n"
        "Duration        : 1 minute 30 seconds\n"
        "Cost to use     : 175 spell points\n"
        "Usage cooldown  : 4 minutes 0 seconds\n"
        "Command syntax  : tempest [at <Target>]\n"
        "                  (-50) Penalty to resist electricity\n"
        "                  (-25) Penalty to resist physical\n"
        "                  Enfeebled is applied to target\n"
        "                  Slow is applied to target\n"
        "                  Modified -> +25% if Static Charge is researched\n"
        "                  Modified -> +25% if Ionization is researched\n"
        "                  Modified -> +50% if Plasma Eruption is researched\n"
        "                  Modified -> 0.05 * your long sword skill (additive)\n"
        "                  Modified -> 0.10 * your elemental air skill (additive)\n"
        "                  Modified -> 1.05 * your level (logarithmic)\n"
        "                  Modified -> 1.25 * your spellcraft skill (logarithmic)\n"
        "                  Modified -> 1.25 * your magical essence skill (logarithmic)\n"
        "                  Modified -> 0.10 * your physics skill (additive)\n"
        "                  Modified -> 0.05 * your mathematics skill (additive)\n"
        "                  Modified -> 0.05 * your chemistry skill (additive)\n"
        "                  Modified -> 0.05 * your intelligence attribute (additive)\n"
        "                  Modified -> 0.03 * your dexterity attribute (additive)\n"
        "                  Modified -> 0.03 * your wisdom attribute (additive)\n"
        "This is only applied when you're using: hand and a half sword, long sword, or\n"
        "two-handed sword.\n"
        "Prerequisites:\n"
        "       Research: The Way Of The Sword\n"
        "       Research: Shocking Barrier\n"
        "          Level: Level of 33 in Scion of Dhuras\n", 
            research->researchDetails());
    destruct(research);
}

/////////////////////////////////////////////////////////////////////////////
void SupercedeTargetsPlacesNewFoeAtTopOfList()
{
    User->registerAttacker(Target);
    Target->registerAttacker(User);

    ExpectEq(User, Target->getTargetToAttack());

    object newAttacker =
        clone_object("/lib/tests/support/services/mockPlayer.c");
    newAttacker->Name("Norman");
    newAttacker->addCommands();
    move_object(newAttacker, Room);

    newAttacker->initiateResearch(
        "/lib/tests/support/research/persistedSupercedeItem.c");
    command("persisted supercede frank", newAttacker);

    ExpectEq(newAttacker, Target->getTargetToAttack());
}
