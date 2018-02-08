//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";
#include "/lib/include/inventory.h"

object Traits;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Traits = clone_object("/lib/tests/support/services/mockPlayer.c");
    Traits->Name("Bob");
    Traits->Str(20);
    Traits->Int(20);
    Traits->Dex(20);
    Traits->Con(20);
    Traits->Wis(20);
    Traits->Chr(20);
    Traits->hitPoints(Traits->maxHitPoints());
    Traits->spellPoints(Traits->maxSpellPoints());
    Traits->staminaPoints(Traits->maxStaminaPoints());
    Traits->addSkillPoints(100);
    Traits->advanceSkill("long sword", 5);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Traits);
}

/////////////////////////////////////////////////////////////////////////////
void AddTraitAddsTraitToUser()
{
    string trait = "lib/tests/support/traits/testTrait.c";

    ExpectFalse(Traits->isTraitOf(trait));
    ExpectTrue(Traits->addTrait(trait));
    ExpectEq(({ "Sword Boy" }), Traits->TraitNames());
}

/////////////////////////////////////////////////////////////////////////////
void CannotAddTraitTwice()
{
    string trait = "lib/tests/support/traits/testTrait.c";

    ExpectTrue(Traits->addTrait(trait));
    ExpectFalse(Traits->addTrait(trait));
    ExpectTrue(Traits->isTraitOf(trait));
}

/////////////////////////////////////////////////////////////////////////////
void TraitsResearchTreesReturnEmptyWhenNoTraitsHaveTrees()
{
    string trait = "lib/tests/support/traits/testTraitWithoutResearch.c";

    ExpectTrue(Traits->addTrait(trait));
    ExpectEq(({}), Traits->traitsResearchTrees());
}

/////////////////////////////////////////////////////////////////////////////
void TraitsResearchTreesReturnsCorrectTrees()
{
    string trait = "lib/tests/support/traits/testTraitWithResearchNoPrerequisites.c";

    ExpectTrue(Traits->addTrait(trait));
    ExpectEq(({ "lib/tests/support/research/testResearchTreeNoPrerequisites.c" }), Traits->traitsResearchTrees());
}

/////////////////////////////////////////////////////////////////////////////
void TraitsResearchTreesDoesNotReturnTreesUntilPrerequisitesMet()
{
    string trait = "lib/tests/support/traits/testTraitWithResearchThatHasPrerequisites.c";

    ExpectTrue(Traits->addTrait(trait));
    ExpectEq(({}), Traits->traitsResearchTrees());

    Traits->addSkillPoints(100);
    Traits->advanceSkill("long sword", 10);
    ExpectEq(({ "lib/tests/support/research/testResearchTree.c" }), Traits->traitsResearchTrees());
}

/////////////////////////////////////////////////////////////////////////////
void TraitsResearchTreesReturnsMultipleTrees()
{
    ExpectTrue(Traits->addTrait("lib/tests/support/traits/testTraitWithResearchThatHasPrerequisites.c"));
    ExpectTrue(Traits->addTrait("lib/tests/support/traits/testTraitWithResearchNoPrerequisites.c"));
    ExpectTrue(Traits->addTrait("lib/tests/support/traits/testTraitWithoutResearch.c"));
    ExpectTrue(Traits->addTrait("lib/tests/support/traits/testTrait.c"));

    Traits->addSkillPoints(100);
    Traits->advanceSkill("long sword", 10);
    ExpectEq(({ "lib/tests/support/research/testResearchTree.c",
                "lib/tests/support/research/testResearchTreeNoPrerequisites.c" }),
        Traits->traitsResearchTrees());
}

/////////////////////////////////////////////////////////////////////////////
void TraitsReturnsEmptyWhenNoTraitsHaveBeenAdded()
{
    ExpectEq(({}), Traits->Traits());
}

/////////////////////////////////////////////////////////////////////////////
void TraitsReturnsListOfTraits()
{
    ExpectTrue(Traits->addTrait("lib/tests/support/traits/testTraitWithoutResearch.c"));
    ExpectTrue(Traits->addTrait("lib/tests/support/traits/testTrait.c"));
    ExpectEq(({ "lib/tests/support/traits/testTrait.c", 
                "lib/tests/support/traits/testTraitWithoutResearch.c" }),
        Traits->Traits());
}

/////////////////////////////////////////////////////////////////////////////
void TraitNamesReturnsEmptyWhenNoTraitsHaveBeenAdded()
{
    ExpectEq(({}), Traits->TraitNames());
}

/////////////////////////////////////////////////////////////////////////////
void TraitNamesReturnsListOfTraits()
{
    ExpectTrue(Traits->addTrait("lib/tests/support/traits/testTraitWithoutResearch.c"));
    ExpectTrue(Traits->addTrait("lib/tests/support/traits/testTrait.c"));
    ExpectTrue(Traits->addTrait("lib/tests/support/traits/testTraitWithResearchThatHasPrerequisites.c"));
    ExpectTrue(Traits->addTrait("lib/tests/support/traits/testTraitWithResearchNoPrerequisites.c"));
    ExpectEq(({ "Armsmaster", "Jerk", "Sword Boy", "Duelist" }), Traits->TraitNames());
}

/////////////////////////////////////////////////////////////////////////////
void AddTraitFiresOnTraitAddedEvent()
{
    Traits->registerEvent(clone_object("/lib/tests/support/events/traitEventSubscriber.c"));
    string err = catch (Traits->addTrait("lib/tests/support/traits/testTrait.c"));
    string expectedError = "*event handler: onTraitAdded called, data: lib/tests/support/traits/testTrait.c, caller: lib/tests/support/services/mockPlayer.c";

    ExpectEq(expectedError, err, "The correct exception is thrown when setting invalid names");
}

/////////////////////////////////////////////////////////////////////////////
void RemoveTraitReturnsFalseIfTraitNotPresent()
{
    ExpectFalse(Traits->removeTrait("lib/tests/support/traits/testTrait.c"));
}

/////////////////////////////////////////////////////////////////////////////
void RemoveTraitRemovesSpecifiedTrait()
{
    string trait = "lib/tests/support/traits/testTrait.c";

    ExpectTrue(Traits->addTrait(trait));
    ExpectTrue(Traits->isTraitOf(trait));
    ExpectTrue(Traits->removeTrait(trait));
    ExpectFalse(Traits->isTraitOf(trait));
}

/////////////////////////////////////////////////////////////////////////////
void RemoveTraitFiresOnTraitRemovedEvent()
{
    ExpectTrue(Traits->addTrait("lib/tests/support/traits/testTrait.c"));

    Traits->registerEvent(clone_object("/lib/tests/support/events/traitEventSubscriber.c"));
    string err = catch (Traits->removeTrait("lib/tests/support/traits/testTrait.c"));
    string expectedError = "*event handler: onTraitRemoved called, data: lib/tests/support/traits/testTrait.c, caller: lib/tests/support/services/mockPlayer.c";

    ExpectEq(expectedError, err, "The correct exception is thrown when setting invalid names");
}

/////////////////////////////////////////////////////////////////////////////
void TraitSkillBonusesApplied()
{
    ExpectEq(5, Traits->getSkill("long sword"), "initial long sword skill");
    ExpectTrue(Traits->addTrait("lib/tests/support/traits/testTrait.c"), "add trait");
    ExpectEq(6, Traits->getSkill("long sword"), "after trait long sword skill");
}

/////////////////////////////////////////////////////////////////////////////
void TraitAttributeBonusesApplied()
{
    ExpectEq(20, Traits->Str(), "initial strength");
    ExpectTrue(Traits->addTrait("lib/tests/support/traits/testTrait.c"), "add trait");
    ExpectEq(22, Traits->Str(), "after trait strength");
}

/////////////////////////////////////////////////////////////////////////////
void MultipleTraitsStackAttributeBonuses()
{
    ExpectEq(20, Traits->Str(), "initial strength");
    ExpectTrue(Traits->addTrait("lib/tests/support/traits/testTrait.c"), "add trait");
    ExpectTrue(Traits->addTrait("lib/modules/traits/genetic/strong.c"), "add trait");
    ExpectEq(24, Traits->Str(), "after trait strength");
}

/////////////////////////////////////////////////////////////////////////////
void SetBonusAttackAddsExtraAttack()
{
    mapping *expectedAttacks = ({ (["attack type":"fire", "damage" : 15, "to hit" : 35]), (["attack type":"weapon"]), (["attack type":"weapon"]) });

    ExpectTrue(Traits->addTrait("lib/tests/support/traits/testTrait.c"), "add test trait");
    ExpectTrue(Traits->addTrait("lib/tests/support/traits/testTraitWithResearchNoPrerequisites.c"), "add trait");
    ExpectEq(expectedAttacks, Traits->traitsExtraAttacks(), "traitsExtraAttacks returns the correct result");
}

/////////////////////////////////////////////////////////////////////////////
void LimitedByEquipmentCorrectlyApplied()
{
    object room = clone_object("/lib/environment/environment");
    move_object(Traits, room);

    ExpectEq(5, Traits->getSkill("long sword"), "initial long sword skill");
    ExpectEq(20, Traits->Str(), "initial strength");
    ExpectEq(({}), Traits->traitsExtraAttacks(), "traitsExtraAttacks returns the correct result");

    ExpectTrue(Traits->addTrait("lib/tests/support/traits/testLimitedByEquipmentTrait.c"), "initiate research");
    ExpectEq(5, Traits->getSkill("long sword"), "trait no weapon long sword skill");
    ExpectEq(20, Traits->Str(), "trait no weapon strength");
    ExpectEq(({}), Traits->traitsExtraAttacks(), "traitsExtraAttacks returns the correct result");

    object weapon = clone_object("/lib/items/weapon");
    weapon->set("name", "blah");
    weapon->set("weapon type", "long sword");
    weapon->set("equipment locations", OnehandedWeapon);
    move_object(weapon, Traits);
    ExpectTrue(weapon->equip("blah"), "weapon equip called");

    ExpectEq(6, Traits->getSkill("long sword"), "trait with weapon long sword skill");
    ExpectEq(22, Traits->Str(), "trait with weapon strength");
    ExpectEq(({ (["attack type":"weapon"]) }), Traits->traitsExtraAttacks(), "traitsExtraAttacks returns the correct result");
}

/////////////////////////////////////////////////////////////////////////////
void LimitedByOpponentBonusesCorrectlyApplied()
{
    object target = clone_object("/lib/realizations/player");
    target->Name("Frank");
    target->addAlias("frank");
    target->Race("elf");
    target->Str(20);
    target->Int(20);
    target->Dex(20);
    target->Con(20);
    target->Wis(20);
    target->Chr(20);
    object room = clone_object("/lib/environment/environment");
    move_object(Traits, room);
    move_object(target, room);

    Traits->registerAttacker(target);

    ExpectEq(5, Traits->getSkill("long sword"), "initial long sword skill");
    ExpectEq(20, Traits->Str(), "initial strength");
    ExpectEq(({}), Traits->traitsExtraAttacks(), "traitsExtraAttacks returns the correct result");

    ExpectTrue(Traits->addTrait("lib/tests/support/traits/testLimitedByOpponentTrait.c"), "initiate research");
    ExpectEq(5, Traits->getSkill("long sword"), "after trait long sword skill");
    ExpectEq(20, Traits->Str(), "after trait strength");
    ExpectEq(({}), Traits->traitsExtraAttacks(), "traitsExtraAttacks returns the correct result");

    target->Race("dwarf");
    ExpectEq(6, Traits->getSkill("long sword"), "facing dwarf sword skill");
    ExpectEq(22, Traits->Str(), "facing dwarf strength");
    ExpectEq(({ (["attack type":"weapon"]) }), Traits->traitsExtraAttacks(), "traitsExtraAttacks returns the correct result");

    destruct(target);
    ExpectEq(5, Traits->getSkill("long sword"), "dwarf gone long sword skill");
    ExpectEq(20, Traits->Str(), "dwarf gone strength");
    ExpectEq(({}), Traits->traitsExtraAttacks(), "traitsExtraAttacks returns the correct result");
}

/////////////////////////////////////////////////////////////////////////////
void LimitedByNearDeathBonusesCorrectlyApplied()
{
    destruct(Traits);
    Traits = clone_object("/lib/realizations/player.c");
    Traits->Name("Bob");
    Traits->Str(20);
    Traits->Int(20);
    Traits->Dex(20);
    Traits->Con(20);
    Traits->Wis(20);
    Traits->Chr(20);
    Traits->addSkillPoints(100);
    Traits->advanceSkill("long sword", 5);

    ExpectEq(5, Traits->getSkill("long sword"), "initial long sword skill");
    ExpectEq(20, Traits->Str(), "initial strength");
    ExpectEq(({}), Traits->traitsExtraAttacks(), "traitsExtraAttacks returns the correct result");

    ExpectTrue(Traits->addTrait("lib/tests/support/traits/testLimitedByNearDeathTrait.c"), "initiate research");
    ExpectEq(6, Traits->getSkill("long sword"), "near death sword skill");
    ExpectEq(22, Traits->Str(), "near death strength");
    ExpectEq(({ (["attack type":"weapon"]) }), Traits->traitsExtraAttacks(), "traitsExtraAttacks returns the correct result");

    Traits->hitPoints(Traits->maxHitPoints());
    ExpectEq(5, Traits->getSkill("long sword"), "dwarf gone long sword skill");
    ExpectEq(20, Traits->Str(), "dwarf gone strength");
    ExpectEq(({}), Traits->traitsExtraAttacks(), "traitsExtraAttacks returns the correct result");
}

/////////////////////////////////////////////////////////////////////////////
void DefaultOpinionModifierIsZero()
{
    object target = clone_object("/lib/realizations/player");
    ExpectEq(0, Traits->opinionModifier(target));
}

/////////////////////////////////////////////////////////////////////////////
void OpinionModifierIsModifiedPositivelyBySameRoot()
{
    object target = clone_object("/lib/realizations/player");
    ExpectTrue(target->addTrait("lib/tests/support/traits/testTrait.c"));
    ExpectTrue(Traits->addTrait("lib/tests/support/traits/testTraitWithResearchNoPrerequisites.c"));
    ExpectEq(5, Traits->opinionModifier(target));
}

/////////////////////////////////////////////////////////////////////////////
void OpinionModifierIsNotModifiedNegativelyByOppositeRoot()
{
    object target = clone_object("/lib/realizations/player");
    ExpectTrue(target->addTrait("lib/tests/support/traits/testTrait.c"));
    ExpectTrue(Traits->addTrait("lib/tests/support/traits/testLimitedByOpponentTrait.c"));
    ExpectEq(-5, Traits->opinionModifier(target));
}

/////////////////////////////////////////////////////////////////////////////
void OpinionModifierIsModifiedByUnrelatedRoot()
{
    object target = clone_object("/lib/realizations/player");
    ExpectTrue(target->addTrait("lib/tests/support/traits/testNoOpposingRootTrait.c"));
    ExpectTrue(Traits->addTrait("lib/tests/support/traits/testTraitWithoutResearch.c"));
    ExpectEq(10, Traits->opinionModifier(target));
}

/////////////////////////////////////////////////////////////////////////////
void OpinionModifierHandlesMultipleTraitsWithoutApplyingSameModifierMoreThanOnce()
{
    object target = clone_object("/lib/realizations/player");
    ExpectTrue(target->addTrait("lib/tests/support/traits/testTrait.c"));
    ExpectTrue(target->addTrait("lib/tests/support/traits/testTraitWithResearchNoPrerequisites.c"));
    ExpectTrue(Traits->addTrait("lib/tests/support/traits/testTrait.c"));
    ExpectTrue(Traits->addTrait("lib/tests/support/traits/testTraitWithResearchNoPrerequisites.c"));
    ExpectTrue(Traits->addTrait("lib/tests/support/traits/testLimitedByOpponentTrait.c"));
    ExpectEq(5, Traits->opinionModifier(target));
}

/////////////////////////////////////////////////////////////////////////////
void HasTraitOfRootReturnsCorrectlyForQueriedRoot()
{
    ExpectFalse(Traits->hasTraitOfRoot("disfigured"));
    ExpectTrue(Traits->addTrait("lib/tests/support/traits/testGeneticTrait.c"));
    ExpectTrue(Traits->hasTraitOfRoot("disfigured"));
    ExpectTrue(Traits->addTrait("lib/tests/support/traits/testHealthTrait.c"));
    ExpectTrue(Traits->addTrait("lib/tests/support/traits/testPersonalityTrait.c"));
    ExpectTrue(Traits->hasTraitOfRoot("disfigured"));
    ExpectTrue(Traits->removeTrait("lib/tests/support/traits/testGeneticTrait.c"));
    ExpectTrue(Traits->hasTraitOfRoot("disfigured"));
}

/////////////////////////////////////////////////////////////////////////////
void TraitsWithDurationAreRemovedWhenTheyExpire()
{
    string trait = "lib/tests/support/traits/testTraitWithDuration.c";

    ExpectFalse(Traits->isTraitOf(trait), "trait initially not part of user");
    ExpectTrue(Traits->addTrait(trait), "trait added");
    ExpectTrue(Traits->isTraitOf(trait), "trait added");

    Traits->agePlayer(10);
    Traits->heart_beat();
    ExpectFalse(Traits->isTraitOf(trait), "trait has expired");
}

/////////////////////////////////////////////////////////////////////////////
void TraitsWithExpireMessagesReportMessageToUserOnExpiry()
{
    string trait = "lib/tests/support/traits/testTraitWithDuration.c";

    ExpectTrue(Traits->addTrait(trait), "trait added");
    ExpectFalse(Traits->caughtMessage());

    Traits->agePlayer(10);
    Traits->heart_beat();
    ExpectEq("This is an expire message.", Traits->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void TraitsWithSustainedEffectAreRemovedWhenResearchNotSustained()
{
    string trait = "lib/tests/support/traits/testTraitForSustainedResearch.c";
    ExpectTrue(Traits->initiateResearch("lib/tests/support/research/testSustainedTraitResearch.c"), "initiate research");

    ExpectTrue(Traits->addTrait(trait), "trait added");
    ExpectTrue(Traits->isTraitOf(trait), "trait added");

    Traits->heart_beat();
    ExpectFalse(Traits->isTraitOf(trait), "trait was removed");
}

/////////////////////////////////////////////////////////////////////////////
void TraitsWithSustainedEffectsAreNotRemovedWhenAssociatedResearchActive()
{
    string trait = "lib/tests/support/traits/testTraitForSustainedResearch.c";
    object room = clone_object("/lib/environment/environment");
    move_object(Traits, room);

    ExpectTrue(Traits->initiateResearch("lib/tests/support/research/testSustainedTraitResearch.c"), "initiate research");
    ExpectTrue(Traits->researchCommand("throw turnip"), "command used");

    ExpectTrue(Traits->isTraitOf(trait), "trait is set on user");

    Traits->heart_beat();
    ExpectTrue(Traits->isTraitOf(trait), "trait has not been removed");
}

/////////////////////////////////////////////////////////////////////////////
void TraitsWithSustainedEffectsAreRemovedAfterResearchInactivated()
{
    string trait = "lib/tests/support/traits/testTraitForSustainedResearch.c";
    object room = clone_object("/lib/environment/environment");
    move_object(Traits, room);

    ExpectTrue(Traits->initiateResearch("lib/tests/support/research/testSustainedTraitResearch.c"), "initiate research");
    ExpectTrue(Traits->researchCommand("throw turnip"), "command used");

    ExpectTrue(Traits->isTraitOf(trait), "trait added");

    Traits->heart_beat();
    ExpectTrue(Traits->isTraitOf(trait), "trait has not been removed");

    ExpectTrue(Traits->researchCommand("throw turnip"), "command used again");
    Traits->heart_beat();
    ExpectFalse(Traits->isTraitOf(trait), "trait has been removed");
}
