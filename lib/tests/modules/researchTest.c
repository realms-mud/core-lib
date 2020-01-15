//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";
#include "/lib/include/inventory.h"

object Research;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Research = clone_object("/lib/tests/support/services/researchWithMockServices");
    Research->Name("Bob");
    Research->Str(20);
    Research->Int(20);
    Research->Dex(20);
    Research->Con(20);
    Research->Wis(20);
    Research->Chr(20);
    Research->hitPoints(Research->maxHitPoints());
    Research->spellPoints(Research->maxSpellPoints());
    Research->staminaPoints(Research->maxStaminaPoints());
    Research->addSkillPoints(100);
    Research->advanceSkill("long sword", 5);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Research);
}

/////////////////////////////////////////////////////////////////////////////
void InitiatePointBasedResearchFailsWhenPrerequisitesNotMet()
{
    Research->addResearchPoints(1);
    ExpectFalse(Research->initiateResearch("lib/tests/support/research/testPointsResearchItem.c"));
}

/////////////////////////////////////////////////////////////////////////////
void InitiatePointBasedResearchFailsWhenNoResearchPointsAvailable()
{
    Research->advanceSkill("long sword", 10);
    ExpectFalse(Research->initiateResearch("lib/tests/support/research/testPointsResearchItem.c"));
}

/////////////////////////////////////////////////////////////////////////////
void InitiatePointBasedResearchSucceedsWhenAllConditionsMet()
{
    Research->addResearchPoints(1);
    Research->advanceSkill("long sword", 10);
    ExpectTrue(Research->initiateResearch("lib/tests/support/research/testPointsResearchItem.c"), "initiate research");
    ExpectTrue(Research->isResearched("lib/tests/support/research/testPointsResearchItem.c"), "isResearched");
}

/////////////////////////////////////////////////////////////////////////////
void InitiatePointBasedResearchFiresOnResearchCompletedEventOnSucceess()
{
    load_object("/lib/dictionaries/environmentDictionary.c");

    ToggleCallOutBypass();
    Research->addResearchPoints(1);
    Research->advanceSkill("long sword", 10);

    Research->registerEvent(clone_object("/lib/tests/support/events/mockEventSubscriber"));
    string err = catch (Research->initiateResearch("lib/tests/support/research/testPointsResearchItem.c"));
    string expectedError = "*event handler: onResearchCompleted called";

    ExpectEq(expectedError, err, "The correct exception is thrown");
    ToggleCallOutBypass();
}

/////////////////////////////////////////////////////////////////////////////
void InitiateGrantBasedResearchSucceedsWhenAllConditionsMet()
{
    ExpectTrue(Research->initiateResearch("lib/tests/support/research/testGrantedResearchItem.c"), "initiate research");
    ExpectTrue(Research->isResearched("lib/tests/support/research/testGrantedResearchItem.c"), "isResearched");
}

/////////////////////////////////////////////////////////////////////////////
void InitiateGrantBasedResearchFiresOnResearchCompletedEventOnSucceess()
{
    load_object("/lib/dictionaries/environmentDictionary.c");

    ToggleCallOutBypass();
    Research->registerEvent(clone_object("/lib/tests/support/events/mockEventSubscriber"));
    string err = catch (Research->initiateResearch("lib/tests/support/research/testGrantedResearchItem.c"));
    string expectedError = "*event handler: onResearchCompleted called";

    ExpectEq(expectedError, err, "The correct exception is thrown");
    ToggleCallOutBypass();
}

/////////////////////////////////////////////////////////////////////////////
void InitiateTimedBasedResearchSucceedsWhenAllConditionsMet()
{
    ExpectTrue(Research->initiateResearch("lib/tests/support/research/testTimedResearchItem.c"), "initiate research");
    ExpectFalse(Research->isResearched("lib/tests/support/research/testTimedResearchItem.c"), "isResearched");
    ExpectTrue(Research->isResearching("lib/tests/support/research/testTimedResearchItem.c"), "not researched");
    Research->heart_beat();
    ExpectFalse(Research->isResearched("lib/tests/support/research/testTimedResearchItem.c"), "not researched");

    Research->heart_beat();
    Research->heart_beat();
    Research->heart_beat();
    ExpectFalse(Research->isResearched("lib/tests/support/research/testTimedResearchItem.c"), "still not researched");
    ExpectTrue(Research->isResearching("lib/tests/support/research/testTimedResearchItem.c"), "not researched");
    Research->heart_beat();
    ExpectTrue(Research->isResearched("lib/tests/support/research/testTimedResearchItem.c"), "finally researched");
    ExpectFalse(Research->isResearching("lib/tests/support/research/testTimedResearchItem.c"), "not researched");
}

/////////////////////////////////////////////////////////////////////////////
void InitiateGrantBasedResearchFiresOnResearchStartedEventOnSucceess()
{
    load_object("/lib/dictionaries/environmentDictionary.c");

    ToggleCallOutBypass();
    Research->registerEvent(clone_object("/lib/tests/support/events/mockEventSubscriber"));
    string err = catch (Research->initiateResearch("lib/tests/support/research/testTimedResearchItem.c"));
    string expectedError = "*event handler: onResearchStarted called";

    ExpectEq(expectedError, err, "The correct exception is thrown");
    ToggleCallOutBypass();
}

/////////////////////////////////////////////////////////////////////////////
void InitiateGrantBasedResearchFiresOnResearchCompletedEventWhenTimeExceeded()
{
    load_object("/lib/dictionaries/environmentDictionary.c");

    ToggleCallOutBypass();
    Research->initiateResearch("lib/tests/support/research/testTimedResearchItem.c");
    Research->registerEvent(clone_object("/lib/tests/support/events/mockEventSubscriber"));

    Research->heart_beat();
    Research->heart_beat();
    Research->heart_beat();
    Research->heart_beat();
    string err = catch (Research->heart_beat());
    string expectedError = "*event handler: onResearchCompleted called";

    ExpectEq(expectedError, err, "The correct exception is thrown");
    ToggleCallOutBypass();
}

/////////////////////////////////////////////////////////////////////////////
void PassiveResearchAttributeBonusesApplied()
{
    ExpectEq(20, Research->Str(), "initial strength");
    ExpectTrue(Research->initiateResearch("lib/tests/support/research/testGrantedResearchItem.c"), "initiate research");
    ExpectEq(22, Research->Str(), "after research applied");
}

/////////////////////////////////////////////////////////////////////////////
void MultipleResearchItemsStackAttributeBonuses()
{
    ExpectEq(20, Research->Str(), "initial strength");
    ExpectTrue(Research->initiateResearch("lib/tests/support/research/testGrantedResearchItem.c"), "initiate research");
    ExpectTrue(Research->initiateResearch("lib/tests/support/research/secondGrantedResearchItem.c"), "initiate second research");
    ExpectEq(24, Research->Str(), "after research applied");
}

/////////////////////////////////////////////////////////////////////////////
void LimitedByIntoxBonusesCorrectlyApplied()
{
    ExpectEq(({}), Research->researchExtraAttacks(), "initial attacks");
    ExpectEq(5, Research->getSkill("long sword"), "initial long sword skill");
    ExpectEq(20, Research->Str(), "initial strength");
    ExpectTrue(Research->initiateResearch("lib/tests/support/research/testLimitedByIntoxResearchItem.c"), "initiate research");
    ExpectEq(({}), Research->researchExtraAttacks(), "attacks after research");
    ExpectEq(5, Research->getSkill("long sword"), "long sword skill after research");
    ExpectEq(20, Research->Str(), "strength after research");

    Research->addIntoxication(10);
    ExpectEq(({ (["attack type":"fire", "damage" : 15, "to hit" : 60]), (["attack type":"weapon"]), (["attack type":"weapon"]) }), Research->researchExtraAttacks(), "attacks after research with intox");
    ExpectEq(3, Research->getSkill("long sword"), "long sword skill after research with intox");
    ExpectEq(22, Research->Str(), "strength after research with intox");
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
    move_object(Research, room);
    move_object(target, room);

    Research->registerAttacker(target);

    ExpectEq(({}), Research->researchExtraAttacks(), "initial attacks");
    ExpectEq(5, Research->getSkill("long sword"), "initial long sword skill");
    ExpectEq(20, Research->Str(), "initial strength");

    ExpectTrue(Research->initiateResearch("lib/tests/support/research/testLimitedByOpponentResearchItem.c"), "initiate research");
    ExpectEq(({}), Research->researchExtraAttacks(), "attacks after research");
    ExpectEq(5, Research->getSkill("long sword"), "long sword skill after research");
    ExpectEq(20, Research->Str(), "strength after research");

    target->Race("dwarf");
    ExpectEq(({ (["attack type":"fire", "damage" : 15, "to hit" : 60]), (["attack type":"weapon"]), (["attack type":"weapon"]) }), Research->researchExtraAttacks(), "attacks after research with dwarf foe");
    ExpectEq(10, Research->getSkill("long sword"), "long sword skill after research with dwarf foe");
    ExpectEq(22, Research->Str(), "strength after research with dwarf foe");

    destruct(target);
    ExpectEq(({}), Research->researchExtraAttacks(), "attacks after target gone");
    ExpectEq(5, Research->getSkill("long sword"), "long sword skill after target gone");
    ExpectEq(20, Research->Str(), "strength after target gone");
}

/////////////////////////////////////////////////////////////////////////////
void PassiveResearchSkillBonusesApplied()
{
    ExpectEq(5, Research->getSkill("long sword"), "initial long sword skill");
    ExpectTrue(Research->initiateResearch("lib/tests/support/research/testGrantedResearchItem.c"), "initiate research");
    ExpectEq(10, Research->getSkill("long sword"), "after research long sword skill");
}

/////////////////////////////////////////////////////////////////////////////
void PassiveResearchAttacksApplied()
{
    object weapon = clone_object("/lib/items/weapon");
    weapon->set("name", "blah");
    weapon->set("defense class", 2);
    weapon->set("weapon class", 10);
    weapon->set("material", "galvorn");
    weapon->set("weapon type", "long sword");
    weapon->set("equipment locations", OnehandedWeapon);
    move_object(weapon, Research);
    weapon->equip("blah");

    ExpectEq(({}), Research->researchExtraAttacks(), "initial attacks");
    ExpectTrue(Research->initiateResearch("lib/tests/support/research/testGrantedResearchItem.c"), "initiate research");
    ExpectEq(({ (["attack type": "fire", "damage": 15, "to hit": 60]), (["attack type": "weapon"]), (["attack type": "weapon"]) }), Research->researchExtraAttacks(), "after research attacks");

    Research->addResearchPoints(1);
    Research->advanceSkill("long sword", 10);
    ExpectTrue(Research->initiateResearch("lib/tests/support/research/testPointsResearchItem.c"), "initiate research");
    ExpectTrue(Research->isResearched("lib/tests/support/research/testPointsResearchItem.c"), "isResearched");
    ExpectEq(({ (["attack type":"fire", "damage" : 15, "to hit" : 60]), (["attack type":"fire", "damage" : 15, "to hit" : 60]), (["attack type":"weapon"]), (["attack type":"weapon"]), (["attack type":"weapon"]) }), Research->researchExtraAttacks(), "after research attacks");
    ExpectEq(({ (["attack type":"fire", "damage" : 15, "to hit" : 60]), (["attack type":"fire", "damage" : 15, "to hit" : 60]), (["attack type":"wielded primary"]), (["attack type":"wielded primary"]), (["attack type":"wielded primary"]), (["attack type":"wielded primary"]) }), Research->getAttacks());
}

/////////////////////////////////////////////////////////////////////////////
void ResearchCommandExecutesCommandBasedResearch()
{
    // This is a laziness thing - I don't want to create a granted research 
    ExpectTrue(Research->initiateResearch("lib/tests/support/research/testTimedResearchItem.c"), "initiate research");
    Research->heart_beat();
    Research->heart_beat();
    Research->heart_beat();
    Research->heart_beat();
    Research->heart_beat();
    ExpectTrue(Research->isResearched("lib/tests/support/research/testTimedResearchItem.c"), "finally researched");

    object target = clone_object("/lib/realizations/player");
    target->Name("Frank");
    target->addAlias("frank");
    target->Str(20);
    target->Int(20);
    target->Dex(20);
    target->Con(20);
    target->Wis(20);
    target->Chr(20);
    target->addSkillPoints(100);
    target->advanceSkill("long sword", 5);

    object room = clone_object("/lib/environment/environment");
    move_object(Research, room);
    move_object(target, room);

    ExpectEq(5, target->getSkill("long sword"));
    ExpectTrue(Research->researchCommand("throw turnip at frank"));
    ExpectTrue(target->registeredInventoryObject("lib/tests/support/research/testTimedResearchItem.c" + "#" + program_name(Research)));
    ExpectEq(10, target->getSkill("long sword"));
    ExpectTrue(Research->sustainedResearchIsActive("lib/tests/support/research/testTimedResearchItem.c"), "research is active");
}

/////////////////////////////////////////////////////////////////////////////
void LimitedByEquipmentCorrectlyApplied()
{
    object room = clone_object("/lib/environment/environment");
    move_object(Research, room);

    ExpectTrue(Research->initiateResearch("lib/tests/support/research/testLimitedActiveResearchItem.c"), "initiate research");
    ExpectFalse(Research->researchCommand("throw turnip at Bob"), "cannot use research command");

    object weapon = clone_object("/lib/items/weapon");
    weapon->set("name", "blah");
    weapon->set("weapon type", "long sword");
    weapon->set("equipment locations", OnehandedWeapon);
    move_object(weapon, Research);
    ExpectTrue(weapon->equip("blah"), "weapon equip called");

    ExpectTrue(Research->researchCommand("throw turnip at Bob"), "can now use research command");
}

/////////////////////////////////////////////////////////////////////////////
void TraitCorrectlyApplied()
{
    object room = clone_object("/lib/environment/environment");
    move_object(Research, room);

    ExpectTrue(Research->initiateResearch("lib/tests/support/research/testPersistedActiveTraitResearch.c"), "initiate research");
    ExpectTrue(Research->researchCommand("throw turnip"), "can use research command");
    ExpectTrue(Research->isTraitOf("lib/tests/support/traits/testTraitWithDuration.c"), "trait applied");
}

/////////////////////////////////////////////////////////////////////////////
void TargetedResearchWithoutAtRunsOnResearcher()
{
    // This is a laziness thing - I don't want to create a granted research 
    ExpectTrue(Research->initiateResearch("lib/tests/support/research/testTimedResearchItem.c"), "initiate research");
    Research->heart_beat();
    Research->heart_beat();
    Research->heart_beat();
    Research->heart_beat();
    Research->heart_beat();
    ExpectTrue(Research->isResearched("lib/tests/support/research/testTimedResearchItem.c"), "finally researched");

    object room = clone_object("/lib/environment/environment");
    move_object(Research, room);

    ExpectEq(5, Research->getSkill("long sword"));
    ExpectTrue(Research->researchCommand("throw turnip"));
    ExpectTrue(Research->registeredInventoryObject("lib/tests/support/research/testTimedResearchItem.c" + "#" + program_name(Research)));
    ExpectEq(10, Research->getSkill("long sword"));
    ExpectTrue(Research->sustainedResearchIsActive("lib/tests/support/research/testTimedResearchItem.c"), "research is active");
}

/////////////////////////////////////////////////////////////////////////////
void CustomEventFiredWhenResearchUsed()
{
    load_object("/lib/dictionaries/environmentDictionary.c");

    ToggleCallOutBypass();
    // This is a laziness thing - I don't want to create a granted research 
    ExpectTrue(Research->initiateResearch("lib/tests/support/research/testTimedResearchItem.c"), "initiate research");
    Research->heart_beat();
    Research->heart_beat();
    Research->heart_beat();
    Research->heart_beat();
    Research->heart_beat();
    ExpectTrue(Research->isResearched("lib/tests/support/research/testTimedResearchItem.c"), "finally researched");

    object room = clone_object("/lib/environment/environment");
    move_object(Research, room);

    object subscriber = clone_object("/lib/tests/support/events/customEventSubscriber");
    Research->registerEvent(subscriber);
    ExpectEq(0, subscriber->TimesUsedResearchEventReceived(), "event not fired yet");
    Research->researchCommand("throw turnip");
    ExpectEq(1, subscriber->TimesUsedResearchEventReceived(), "custom event fired");
    ToggleCallOutBypass();
}

/////////////////////////////////////////////////////////////////////////////
void CannotAddNegativeResearchPoints()
{
    ExpectFalse(Research->addResearchPoints(-2));
}

/////////////////////////////////////////////////////////////////////////////
void AddingResearchPointsFiresOnResearchPointsAdded()
{
    load_object("/lib/dictionaries/environmentDictionary.c");

    ToggleCallOutBypass();
    Research->registerEvent(clone_object("/lib/tests/support/events/mockEventSubscriber"));

    string err = catch (Research->addResearchPoints(1));
    string expectedError = "*event handler: onResearchPointsAdded called";

    ExpectEq(expectedError, err, "The correct exception is thrown when setting invalid value");
    ToggleCallOutBypass();
}

/////////////////////////////////////////////////////////////////////////////
void CannotUseResearchWhileAwaitingCooldown()
{
    // This is a laziness thing - I don't want to create a granted research 
    ExpectTrue(Research->initiateResearch("lib/tests/support/research/testTimedResearchItem.c"), "initiate research");
    Research->heart_beat();
    Research->heart_beat();
    Research->heart_beat();
    Research->heart_beat();
    Research->heart_beat();
    ExpectTrue(Research->isResearched("lib/tests/support/research/testTimedResearchItem.c"), "finally researched");

    object room = clone_object("/lib/environment/environment");
    move_object(Research, room);

    ExpectFalse(Research->blockedByCooldown("lib/tests/support/research/testTimedResearchItem.c"), "not blocked by cool down");
    ExpectTrue(Research->researchCommand("throw turnip"), "command used");
    ExpectFalse(Research->blockedByCooldown("lib/tests/support/research/testTimedResearchItem.c"), "not blocked by cool down");

    // Deactivate the skill
    ExpectTrue(Research->researchCommand("throw turnip"), "command used second time");
    ExpectTrue(Research->blockedByCooldown("lib/tests/support/research/testTimedResearchItem.c"), "blocked by cool down");
    Research->heart_beat();
    ExpectTrue(Research->blockedByCooldown("lib/tests/support/research/testTimedResearchItem.c"), "blocked by cool down");
    Research->heart_beat();
    ExpectFalse(Research->blockedByCooldown("lib/tests/support/research/testTimedResearchItem.c"), "can use again");
}

/////////////////////////////////////////////////////////////////////////////
void InitiateTreeResearchFailsWhenAllConditionsNotMet()
{
    ExpectFalse(Research->addResearchTree("lib/tests/support/research/testResearchTree.c"));
    ExpectFalse(Research->isResearched("lib/tests/support/research/testPointsResearchItem.c"), "isResearched");
}

/////////////////////////////////////////////////////////////////////////////
void InitiateTreeResearchSucceedsWhenAllConditionsMet()
{
    Research->advanceSkill("long sword", 10);
    ExpectTrue(Research->addResearchTree("lib/tests/support/research/testResearchTree.c"));
    ExpectTrue(Research->isResearched("lib/tests/support/research/testTreeRoot.c"), "isResearched");
}

/////////////////////////////////////////////////////////////////////////////
void AvailableResearchTreesIsEmptyByDefault()
{
    ExpectEq(({}), Research->availableResearchTrees());
}

/////////////////////////////////////////////////////////////////////////////
void AvailableResearchTreesReturnsAllTreesWithResearchedItems()
{
    Research->advanceSkill("long sword", 10);
    ExpectEq(({}), Research->availableResearchTrees());
    ExpectTrue(Research->addResearchTree("lib/tests/support/research/testResearchTree.c"));
    ExpectEq(({ "lib/tests/support/research/testResearchTree.c" }), Research->availableResearchTrees(), "tree added");
    ExpectTrue(Research->addResearchTree("lib/tests/support/research/testSecondResearchTree.c"));
    ExpectEq(({ "lib/tests/support/research/testResearchTree.c", "lib/tests/support/research/testSecondResearchTree.c" }), 
        Research->availableResearchTrees());
}

/////////////////////////////////////////////////////////////////////////////
void AvailableResearchTreesReturnsTreesAvailableFromGuilds()
{
    ExpectEq(({}), Research->availableResearchTrees());

    Research->ToggleMockGuilds();

    ExpectEq(({ "lib/tests/support/guilds/testGuildResearchTree.c" }),
        Research->availableResearchTrees());
}

/////////////////////////////////////////////////////////////////////////////
void AvailableResearchTreesReturnsTreesAvailableFromRaces()
{
    ExpectEq(({}), Research->availableResearchTrees());

    Research->Race("high elf");

    ExpectEq(({ "lib/instances/research/races/highElfResearchTree.c" }),
        Research->availableResearchTrees());
}

/////////////////////////////////////////////////////////////////////////////
void AvailableResearchTreesReturnsTreesAvailableFromTraits()
{
    ExpectEq(({}), Research->availableResearchTrees());

    Research->ToggleMockTrait();

    ExpectEq(({ "does/not/exist/traitResearchTree.c", "some/other/locale/traitResearchTree.c" }),
        Research->availableResearchTrees());
}

/////////////////////////////////////////////////////////////////////////////
void AvailableResearchTreesReturnsTreesAvailableFromBackground()
{
    ExpectEq(({}), Research->availableResearchTrees());

    Research->ToggleMockBackground();

    ExpectEq(({ "does/not/exist/backgroundResearchTree.c", "some/other/locale/backgroundResearchTree.c" }),
        Research->availableResearchTrees());
}

/////////////////////////////////////////////////////////////////////////////
void AvailableResearchTreesReturnsTreesAvailableFromAllRelevantServices()
{
    string *expectedTrees = ({
        "does/not/exist/backgroundResearchTree.c",
        "some/other/locale/backgroundResearchTree.c",
        "does/not/exist/traitResearchTree.c", 
        "some/other/locale/traitResearchTree.c",
        "lib/tests/support/guilds/testGuildResearchTree.c",
        "lib/instances/research/races/highElfResearchTree.c",
        "lib/tests/support/research/testResearchTree.c"
    });
    ExpectEq(({}), Research->availableResearchTrees());

    Research->advanceSkill("long sword", 10);
    ExpectTrue(Research->addResearchTree("lib/tests/support/research/testResearchTree.c"));

    Research->Race("high elf");
    Research->ToggleMockGuilds();
    Research->ToggleMockTrait();
    Research->ToggleMockBackground();
    ExpectEq(expectedTrees, Research->availableResearchTrees());
}

/////////////////////////////////////////////////////////////////////////////
void CompletedResearchReturnsFinishedResearch()
{
    Research->addResearchPoints(1);
    Research->advanceSkill("long sword", 10);
    ExpectEq(({}), Research->completedResearch());

    ExpectTrue(Research->initiateResearch("lib/tests/support/research/testPointsResearchItem.c"), "initiate research");
    ExpectEq(({ "lib/tests/support/research/testPointsResearchItem.c" }), Research->completedResearch());

    ExpectTrue(Research->initiateResearch("lib/tests/support/research/testGrantedResearchItem.c"), "initiate research");
    ExpectEq(({ "lib/tests/support/research/testPointsResearchItem.c", "lib/tests/support/research/testGrantedResearchItem.c" }),
        Research->completedResearch());
}

/////////////////////////////////////////////////////////////////////////////
void CompletedResearchDoesNotReturnResearchInProgress()
{
    Research->addResearchPoints(1);
    Research->advanceSkill("long sword", 10);
    ExpectEq(({}), Research->completedResearch());

    ExpectTrue(Research->initiateResearch("lib/tests/support/research/testPointsResearchItem.c"), "initiate research");
    ExpectEq(({ "lib/tests/support/research/testPointsResearchItem.c" }), Research->completedResearch());

    ExpectTrue(Research->initiateResearch("lib/tests/support/research/testTimedResearchItem.c"), "initiate research");
    ExpectEq(({ "lib/tests/support/research/testPointsResearchItem.c" }), Research->completedResearch());
}

/////////////////////////////////////////////////////////////////////////////
void ResearchInProgressDoesNotReturnCompletedResearch()
{
    Research->addResearchPoints(1);
    Research->advanceSkill("long sword", 10);
    ExpectEq(({}), Research->researchInProgress());

    ExpectTrue(Research->initiateResearch("lib/tests/support/research/testTimedResearchItem.c"), "initiate research");
    ExpectEq(({ "lib/tests/support/research/testTimedResearchItem.c" }), Research->researchInProgress());

    ExpectTrue(Research->initiateResearch("lib/tests/support/research/testPointsResearchItem.c"), "initiate research");
    ExpectEq(({ "lib/tests/support/research/testTimedResearchItem.c" }), Research->researchInProgress());
}

/////////////////////////////////////////////////////////////////////////////
void ResearchInProgressTransitionsToCompletedWhenCompleted()
{
    Research->addResearchPoints(1);
    Research->advanceSkill("long sword", 10);
    ExpectEq(({}), Research->completedResearch());

    ExpectTrue(Research->initiateResearch("lib/tests/support/research/testTimedResearchItem.c"), "initiate research");
    ExpectEq(({ "lib/tests/support/research/testTimedResearchItem.c" }), Research->researchInProgress(), "research begun");
    ExpectEq(({}), Research->completedResearch(), "no research completed");

    Research->heart_beat();
    Research->heart_beat();
    Research->heart_beat();
    Research->heart_beat();
    Research->heart_beat();

    ExpectEq(({ }), Research->researchInProgress(), "research ended");
    ExpectEq(({ "lib/tests/support/research/testTimedResearchItem.c" }), Research->completedResearch(), "research completed");
}

/////////////////////////////////////////////////////////////////////////////
void AddResearchChoiceBroadcastsCorrectEventWithData()
{
    load_object("/lib/dictionaries/environmentDictionary.c");

    ToggleCallOutBypass();
    mapping researchChoice = ([
        "type": "research choice",
        "name": "Test name",
        "description": "Test description",
        "apply": "at level 5",
        "research objects": ({ "lib/tests/support/research/testLimitedActiveResearchItem.c",
            "lib/tests/support/research/testGrantedResearchItem.c" })
    ]);

    object subscriber = clone_object("/lib/tests/support/events/onResearchChoiceAvailableSubscriber.c");
    Research->registerEvent(subscriber);
    ExpectTrue(Research->addResearchChoice(researchChoice));

    mapping expectedChoices = ([
        "1": ([ 
            "choice": "Test name",
            "type": "research object",
            "name": "Active research",
            "description": "This is limited active research", 
            "key": "lib/tests/support/research/testLimitedActiveResearchItem.c"
        ]),
        "2": ([ 
            "choice": "Test name", 
            "type": "research object",
            "name": "Granted research",
            "description": "This is granted research",
            "key": "lib/tests/support/research/testGrantedResearchItem.c"
        ])
    ]);

    ExpectEq(expectedChoices, subscriber->choices());
    ToggleCallOutBypass();
}

/////////////////////////////////////////////////////////////////////////////
void AddResearchChoiceHandlesResearchPath()
{
    load_object("/lib/dictionaries/environmentDictionary.c");

    ToggleCallOutBypass();
    mapping researchChoice = ([
        "type":"research path",
        "name" : "Test name",
        "description" : "Test description",
        "apply" : "at level 5",
        "research objects" : ({ "lib/tests/support/guilds/testGuildResearchTree.c",
            "lib/tests/support/research/testSecondResearchTree.c" })
    ]);

    object subscriber = clone_object("/lib/tests/support/events/onResearchChoiceAvailableSubscriber.c");
    Research->registerEvent(subscriber);
    ExpectTrue(Research->addResearchChoice(researchChoice));

    mapping expectedChoices = ([
        "1":([
            "choice":"Test name",
            "type" : "research tree",
            "name" : "tree of guild researchiness",
            "description" : "this is the land-loving mother pigeon of all research trees",
            "obsoletes": ({ "lib/tests/support/research/testSecondResearchTree.c" }),
            "key" : "lib/tests/support/guilds/testGuildResearchTree.c"
        ]),
        "2": ([
            "choice":"Test name",
            "type" : "research tree",
            "name" : "tree of guild researchiness",
            "description" : "this is the land-loving mother pigeon of all research trees",
            "obsoletes": ({ "lib/tests/support/guilds/testGuildResearchTree.c" }),
            "key" : "lib/tests/support/research/testSecondResearchTree.c"
        ])
    ]);

    ExpectEq(expectedChoices, subscriber->choices());
    ToggleCallOutBypass();
}

/////////////////////////////////////////////////////////////////////////////
void SelectResearchChoiceDoesNotAddResearchWhithoutChoiceSetUp()
{
    ExpectFalse(Research->selectResearchChoice("lib/tests/support/research/testLimitedActiveResearchItem.c", "Test name", "1"));
    ExpectFalse(Research->isResearched("lib/tests/support/research/testLimitedActiveResearchItem.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectResearchChoiceFiresCorrectEvent()
{
    load_object("/lib/dictionaries/environmentDictionary.c");

    ToggleCallOutBypass();
    mapping researchChoice = ([
        "type":"research choice",
        "name" : "Test name",
        "description" : "Test description",
        "apply" : "at level 5",
        "research objects" : ({ "lib/tests/support/research/testLimitedActiveResearchItem.c",
            "lib/tests/support/research/testGrantedResearchItem.c" })
    ]);

    ExpectTrue(Research->addResearchChoice(researchChoice));

    Research->registerEvent(clone_object("/lib/tests/support/events/onResearchChoiceAvailableSubscriber.c"));
    string err = catch (Research->selectResearchChoice("lib/tests/support/research/testLimitedActiveResearchItem.c", "Test name", "1"));
    string expectedError = "*event handler: onResearchChoiceChosen called";

    ExpectEq(expectedError, err, "The correct exception is thrown");
    ToggleCallOutBypass();
}

/////////////////////////////////////////////////////////////////////////////
void SelectResearchPathSelectsCorrectResearchTree()
{
    mapping researchChoice = ([
        "type":"research path",
        "name" : "Test name",
        "description" : "Test description",
        "apply" : "at level 5",
        "research objects" : ({ "lib/tests/support/guilds/testGuildResearchTree.c",
            "lib/tests/support/research/testSecondResearchTree.c" })
    ]);
    Research->advanceSkill("long sword", 10);

    ExpectTrue(Research->addResearchChoice(researchChoice));
    ExpectFalse(Research->isResearched("lib/tests/support/guilds/testGuildTreeRoot.c"));
    ExpectFalse(member(Research->availableResearchTrees(), "lib/tests/support/research/testSecondResearchTree.c") > -1);
    ExpectTrue(Research->selectResearchPath("lib/tests/support/research/testSecondResearchTree.c", "Test name", "1"));
    ExpectTrue(Research->isResearched("lib/tests/support/guilds/testGuildTreeRoot.c"));
    ExpectTrue(member(Research->availableResearchTrees(), "lib/tests/support/research/testSecondResearchTree.c") > -1);
}

/////////////////////////////////////////////////////////////////////////////
void SelectResearchPathFiresCorrectEvent()
{
    load_object("/lib/dictionaries/environmentDictionary.c");

    ToggleCallOutBypass();
    mapping researchChoice = ([
        "type":"research path",
        "name" : "Test name",
        "description" : "Test description",
        "apply" : "at level 5",
        "research objects" : ({ "lib/tests/support/guilds/testGuildResearchTree.c",
            "lib/tests/support/research/testSecondResearchTree.c" })
    ]);
    Research->advanceSkill("long sword", 10);

    ExpectTrue(Research->addResearchChoice(researchChoice));

    Research->registerEvent(clone_object("/lib/tests/support/events/onResearchChoiceAvailableSubscriber.c"));
    string err = catch (Research->selectResearchPath("lib/tests/support/research/testSecondResearchTree.c", "Test name", "1"));
    string expectedError = "*event handler: onResearchPathChosen called";

    ExpectEq(expectedError, err, "The correct exception is thrown");
    ToggleCallOutBypass();
}

/////////////////////////////////////////////////////////////////////////////
void SelectResearchPathDoesNotAddResearchWhithoutChoiceSetUp()
{
    ExpectFalse(Research->selectResearchChoice("lib/tests/support/research/testSecondResearchTree.c", "Test name", "1"));
    ExpectFalse(Research->isResearched("lib/tests/support/guilds/testGuildTreeRoot.c"));
}

/////////////////////////////////////////////////////////////////////////////
void PassiveResearchCombatBonusesApplied()
{
    ExpectEq(150, Research->maxSpellPoints(), "initial spell points");
    ExpectTrue(Research->initiateResearch("lib/tests/support/research/testGrantedResearchItem.c"), "initiate research");
    ExpectEq(155, Research->maxSpellPoints(), "after research spell points");
}

/////////////////////////////////////////////////////////////////////////////
void ResearchSustainedCommandReducesByCost()
{
    ExpectTrue(Research->initiateResearch("lib/tests/support/research/testSustainedTraitResearch.c"), "initiate research");
    ExpectTrue(Research->isResearched("lib/tests/support/research/testSustainedTraitResearch.c"), "finally researched");

    object target = clone_object("/lib/realizations/player");
    target->Name("Frank");
    target->addAlias("frank");
    target->Str(20);
    target->Int(20);
    target->Dex(20);
    target->Con(20);
    target->Wis(20);
    target->Chr(20);

    object room = clone_object("/lib/environment/environment");
    move_object(Research, room);
    move_object(target, room);

    ExpectEq(150, Research->maxSpellPoints(), "initial max spell points");
    ExpectTrue(Research->researchCommand("throw turnip at frank"));
    ExpectEq(140, Research->maxSpellPoints(), "max spell points decreased");
    ExpectTrue(Research->sustainedResearchIsActive("lib/tests/support/research/testSustainedTraitResearch.c"), "research is active");
    ExpectTrue(target->isTraitOf("lib/tests/support/traits/testTraitForSustainedResearch.c"), "trait is active");
}

/////////////////////////////////////////////////////////////////////////////
void CorrectEnchantmentsReturned()
{
    ExpectTrue(Research->initiateResearch("lib/tests/support/research/testEnchantmentResearchItem.c"), "initiate research");
    ExpectEq((["electricity":5, "fire": 2, "magical": 1 ]), 
        Research->researchEnchantments());

    ExpectTrue(Research->initiateResearch("lib/tests/support/research/anotherEnchantmentResearch.c"), "initiate research");
    ExpectEq((["electricity":5, "fire" : 5, "magical" : 1]),
        Research->researchEnchantments());
}
