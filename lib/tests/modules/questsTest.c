//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";
#include "/lib/include/inventory.h"

object Quests;
object QuestItem;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    getService("environment");

    Quests = clone_object("/lib/realizations/player");
    Quests.Name("Bob");

    QuestItem = clone_object("/lib/tests/support/quests/fakeQuestItem.c");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Quests);
}

/////////////////////////////////////////////////////////////////////////////
void QuestIsInProgressReturnsFalseWhenQuestIsInvalid()
{
    ExpectFalse(Quests.questIsInProgress("bad/quest.c"));
}

/////////////////////////////////////////////////////////////////////////////
void QuestIsInProgressReturnsFalseWhenQuestIsNotStarted()
{
    ExpectFalse(Quests.questIsInProgress("/lib/tests/support/quests/fakeQuestItem.c"));
}

/////////////////////////////////////////////////////////////////////////////
void QuestIsInProgressReturnsTrueWhenQuestHasBeenStarted()
{
    ExpectTrue(Quests.beginQuest("/lib/tests/support/quests/fakeQuestItem.c"));
    ExpectTrue(Quests.questIsInProgress("/lib/tests/support/quests/fakeQuestItem.c"));
}

/////////////////////////////////////////////////////////////////////////////
void QuestIsInProgressReturnsFalseWhenQuestHasBeenCompleted()
{
    ExpectTrue(Quests.beginQuest("/lib/tests/support/quests/fakeQuestItem.c"));

    // Progress the quest to completion
    ExpectTrue(QuestItem.receiveEvent(Quests, "meetTheKing"));
    ExpectTrue(QuestItem.receiveEvent(Quests, "ignoreTheKing"));

    ExpectFalse(Quests.questIsInProgress("/lib/tests/support/quests/fakeQuestItem.c"));
}

/////////////////////////////////////////////////////////////////////////////
void QuestIsActiveReturnsFalseWhenQuestIsInvalid()
{
    ExpectFalse(Quests.questIsActive("bad/quest.c"));
}

/////////////////////////////////////////////////////////////////////////////
void QuestIsActiveReturnsFalseWhenQuestIsNotStarted()
{
    ExpectFalse(Quests.questIsActive("/lib/tests/support/quests/fakeQuestItem.c"));
}

/////////////////////////////////////////////////////////////////////////////
void QuestIsActiveReturnsTrueWhenQuestHasBeenActivated()
{
    ExpectTrue(Quests.beginQuest("/lib/tests/support/quests/fakeQuestItem.c"));
    ExpectTrue(Quests.questIsActive("/lib/tests/support/quests/fakeQuestItem.c"));
}

/////////////////////////////////////////////////////////////////////////////
void QuestIsActiveReturnsFalseWhenQuestHasBeenDeactivated()
{
    ExpectTrue(Quests.beginQuest("/lib/tests/support/quests/fakeQuestItem.c"));
    ExpectTrue(Quests.deactivateQuest("/lib/tests/support/quests/fakeQuestItem.c"));
    ExpectFalse(Quests.questIsActive("/lib/tests/support/quests/fakeQuestItem.c"));
}

/////////////////////////////////////////////////////////////////////////////
void QuestIsActiveReturnsTrueWhenQuestHasBeenReactivated()
{
    ExpectTrue(Quests.beginQuest("/lib/tests/support/quests/fakeQuestItem.c"));
    ExpectTrue(Quests.deactivateQuest("/lib/tests/support/quests/fakeQuestItem.c"));
    ExpectFalse(Quests.questIsActive("/lib/tests/support/quests/fakeQuestItem.c"));
    ExpectTrue(Quests.activateQuest("/lib/tests/support/quests/fakeQuestItem.c"));
    ExpectTrue(Quests.questIsActive("/lib/tests/support/quests/fakeQuestItem.c"));
}

/////////////////////////////////////////////////////////////////////////////
void QuestIsActiveReturnsFalseWhenQuestHasBeenCompleted()
{
    ExpectTrue(Quests.beginQuest("/lib/tests/support/quests/fakeQuestItem.c"));

    // Progress the quest to completion
    ExpectTrue(QuestItem.receiveEvent(Quests, "meetTheKing"));
    ExpectTrue(QuestItem.receiveEvent(Quests, "ignoreTheKing"));

    ExpectFalse(Quests.questIsActive("/lib/tests/support/quests/fakeQuestItem.c"));
}

/////////////////////////////////////////////////////////////////////////////
void QuestIsCompletedReturnsFalseWhenQuestIsInvalid()
{
    ExpectFalse(Quests.questIsCompleted("bad/quest.c"));
}

/////////////////////////////////////////////////////////////////////////////
void QuestIsCompletedReturnsFalseWhenQuestIsNotStarted()
{
    ExpectFalse(Quests.questIsCompleted("/lib/tests/support/quests/fakeQuestItem.c"));
}

/////////////////////////////////////////////////////////////////////////////
void QuestIsCompletedReturnsFalseWhenQuestHasBeenStartedButNotCompleted()
{
    ExpectTrue(Quests.beginQuest("/lib/tests/support/quests/fakeQuestItem.c"));
    ExpectFalse(Quests.questIsCompleted("/lib/tests/support/quests/fakeQuestItem.c"));
}

/////////////////////////////////////////////////////////////////////////////
void QuestIsCompletedReturnsTrueWhenQuestHasBeenCompleted()
{
    ExpectTrue(Quests.beginQuest("/lib/tests/support/quests/fakeQuestItem.c"));

    // Progress the quest to completion
    ExpectTrue(QuestItem.receiveEvent(Quests, "meetTheKing"));
    ExpectTrue(QuestItem.receiveEvent(Quests, "ignoreTheKing"));

    ExpectTrue(Quests.questIsCompleted("/lib/tests/support/quests/fakeQuestItem.c"));
}

/////////////////////////////////////////////////////////////////////////////
void QuestStateReturnsFalseWhenQuestIsInvalid()
{
    ExpectFalse(Quests.questState("bad/quest.c"));
}

/////////////////////////////////////////////////////////////////////////////
void QuestStateReturnsFalseWhenQuestIsNotStarted()
{
    ExpectFalse(Quests.questState("/lib/tests/support/quests/fakeQuestItem.c"));
}

/////////////////////////////////////////////////////////////////////////////
void QuestStateReturnsCorrectQuestState()
{
    ExpectTrue(Quests.beginQuest("/lib/tests/support/quests/fakeQuestItem.c"));
    ExpectEq("meet the king", Quests.questState("/lib/tests/support/quests/fakeQuestItem.c"));

    ExpectTrue(QuestItem.receiveEvent(Quests, "meetTheKing"));
    ExpectEq("met the king", Quests.questState("/lib/tests/support/quests/fakeQuestItem.c"));

    ExpectTrue(QuestItem.receiveEvent(Quests, "serveTheKing"));
    ExpectEq("serve the king", Quests.questState("/lib/tests/support/quests/fakeQuestItem.c"));

    ExpectTrue(QuestItem.receiveEvent(Quests, "maybeNobodyWillNotice"));
    ExpectEq("king is dead", Quests.questState("/lib/tests/support/quests/fakeQuestItem.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ActiveQuestsReturnsCorrectListOfQuests()
{
    ExpectEq(({}), Quests.activeQuests());

    ExpectTrue(Quests.beginQuest("/lib/tests/support/quests/fakeQuestItem.c"));
    ExpectEq(({ "/lib/tests/support/quests/fakeQuestItem.c" }), Quests.activeQuests());

    ExpectTrue(Quests.beginQuest("/lib/tests/support/quests/mockQuest.c"));
    ExpectEq(({ "/lib/tests/support/quests/fakeQuestItem.c", "/lib/tests/support/quests/mockQuest.c" }), 
        Quests.activeQuests());

    ExpectTrue(Quests.deactivateQuest("/lib/tests/support/quests/fakeQuestItem.c"));
    ExpectEq(({ "/lib/tests/support/quests/mockQuest.c" }), Quests.activeQuests());

    ExpectTrue(Quests.activateQuest("/lib/tests/support/quests/fakeQuestItem.c"));
    ExpectEq(({ "/lib/tests/support/quests/fakeQuestItem.c", "/lib/tests/support/quests/mockQuest.c" }),
        Quests.activeQuests());
}

/////////////////////////////////////////////////////////////////////////////
void CompletedQuestsReturnsCorrectListOfQuests()
{
    ExpectEq(({}), Quests.activeQuests());

    ExpectTrue(Quests.beginQuest("/lib/tests/support/quests/fakeQuestItem.c"));
    ExpectEq(({ }), Quests.completedQuests());

    ExpectTrue(Quests.beginQuest("/lib/tests/support/quests/anotherQuest.c"));
    ExpectEq(({ "/lib/tests/support/quests/anotherQuest.c" }), Quests.completedQuests());

    ExpectTrue(Quests.deactivateQuest("/lib/tests/support/quests/fakeQuestItem.c"));
    ExpectEq(({ "/lib/tests/support/quests/anotherQuest.c" }), Quests.completedQuests());

    ExpectTrue(QuestItem.receiveEvent(Quests, "meetTheKing"));
    ExpectTrue(QuestItem.receiveEvent(Quests, "ignoreTheKing"));
    ExpectEq(({ "/lib/tests/support/quests/fakeQuestItem.c", "/lib/tests/support/quests/anotherQuest.c" }),
        Quests.completedQuests());
}

/////////////////////////////////////////////////////////////////////////////
void QuestsInProgressReturnsCorrectListOfQuests()
{
    ExpectEq(({}), Quests.activeQuests());

    ExpectTrue(Quests.beginQuest("/lib/tests/support/quests/fakeQuestItem.c"));
    ExpectEq(({ "/lib/tests/support/quests/fakeQuestItem.c" }), Quests.questsInProgress());

    ExpectTrue(Quests.beginQuest("/lib/tests/support/quests/mockQuest.c"));
    ExpectEq(({ "/lib/tests/support/quests/fakeQuestItem.c", "/lib/tests/support/quests/mockQuest.c" }),
        Quests.questsInProgress());

    ExpectTrue(Quests.deactivateQuest("/lib/tests/support/quests/fakeQuestItem.c"));
    ExpectEq(({ "/lib/tests/support/quests/fakeQuestItem.c", "/lib/tests/support/quests/mockQuest.c" }),
        Quests.questsInProgress());

    ExpectTrue(QuestItem.receiveEvent(Quests, "meetTheKing"));
    ExpectTrue(QuestItem.receiveEvent(Quests, "ignoreTheKing"));
    ExpectEq(({ "/lib/tests/support/quests/mockQuest.c" }), Quests.questsInProgress());
}

/////////////////////////////////////////////////////////////////////////////
void ActivateQuestReturnsFalseWhenQuestIsInvalid()
{
    ExpectFalse(Quests.activateQuest("bad/quest.c"));
    ExpectFalse(Quests.questIsActive("/lib/tests/support/quests/fakeQuestItem.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ActivateQuestReturnsFalseWhenQuestIsNotStarted()
{
    ExpectFalse(Quests.activateQuest("/lib/tests/support/quests/fakeQuestItem.c"));
    ExpectFalse(Quests.questIsActive("/lib/tests/support/quests/fakeQuestItem.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ActivateQuestReturnsTrueWhenQuestHasBeenStarted()
{
    ExpectTrue(Quests.beginQuest("/lib/tests/support/quests/fakeQuestItem.c"));
    ExpectTrue(Quests.questIsActive("/lib/tests/support/quests/fakeQuestItem.c"), "begun quest is active");
    ExpectTrue(Quests.deactivateQuest("/lib/tests/support/quests/fakeQuestItem.c"), "quest deactivated");
    ExpectFalse(Quests.questIsActive("/lib/tests/support/quests/fakeQuestItem.c", "deactivated quest returns not active"));
    ExpectTrue(Quests.activateQuest("/lib/tests/support/quests/fakeQuestItem.c", "activate the quest"));
    ExpectTrue(Quests.questIsActive("/lib/tests/support/quests/fakeQuestItem.c"), "re-activated quest is active");
}

/////////////////////////////////////////////////////////////////////////////
void ActivateQuestReturnsFalseWhenQuestHasBeenCompleted()
{
    ExpectTrue(Quests.beginQuest("/lib/tests/support/quests/fakeQuestItem.c"));
    ExpectTrue(QuestItem.receiveEvent(Quests, "meetTheKing"));
    ExpectTrue(QuestItem.receiveEvent(Quests, "ignoreTheKing"));

    ExpectFalse(Quests.activateQuest("/lib/tests/support/quests/fakeQuestItem.c"));
    ExpectFalse(Quests.questIsActive("/lib/tests/support/quests/fakeQuestItem.c"));
}

/////////////////////////////////////////////////////////////////////////////
void DeactivateQuestReturnsFalseWhenQuestIsInvalid()
{
    ExpectFalse(Quests.activateQuest("bad/quest.c"));
    ExpectFalse(Quests.deactivateQuest("/lib/tests/support/quests/fakeQuestItem.c"));
}

/////////////////////////////////////////////////////////////////////////////
void DeactivateQuestReturnsFalseWhenQuestIsNotStarted()
{
    ExpectFalse(Quests.activateQuest("/lib/tests/support/quests/fakeQuestItem.c"));
    ExpectFalse(Quests.deactivateQuest("/lib/tests/support/quests/fakeQuestItem.c"));
}

/////////////////////////////////////////////////////////////////////////////
void DeactivateQuestReturnsTrueWhenQuestHasBeenStarted()
{
    ExpectTrue(Quests.beginQuest("/lib/tests/support/quests/fakeQuestItem.c"));
    ExpectTrue(Quests.questIsActive("/lib/tests/support/quests/fakeQuestItem.c"), "begun quest is active");
    ExpectTrue(Quests.deactivateQuest("/lib/tests/support/quests/fakeQuestItem.c"), "quest deactivated");
    ExpectFalse(Quests.questIsActive("/lib/tests/support/quests/fakeQuestItem.c", "deactivated quest returns not active"));
}

/////////////////////////////////////////////////////////////////////////////
void DeactivateQuestReturnsFalseWhenQuestHasBeenCompleted()
{
    ExpectTrue(Quests.beginQuest("/lib/tests/support/quests/fakeQuestItem.c"));
    ExpectTrue(QuestItem.receiveEvent(Quests, "meetTheKing"));
    ExpectTrue(QuestItem.receiveEvent(Quests, "ignoreTheKing"));

    ExpectFalse(Quests.deactivateQuest("/lib/tests/support/quests/fakeQuestItem.c"));
    ExpectFalse(Quests.questIsActive("/lib/tests/support/quests/fakeQuestItem.c"));
}

/////////////////////////////////////////////////////////////////////////////
void BeginQuestFiresOnQuestStartedEvent()
{
    ToggleCallOutBypass();
    object events = clone_object("/lib/tests/support/events/questEventsSubscriber.c");
    Quests.registerEvent(events);
    ExpectTrue(Quests.beginQuest("/lib/tests/support/quests/fakeQuestItem.c"));
    ExpectEq(([ "onQuestStarted":"/lib/tests/support/quests/fakeQuestItem.c"]),
        events.quests());
    ToggleCallOutBypass();
}

/////////////////////////////////////////////////////////////////////////////
void BeginQuestFiresProperEventsWhenInitialStateIsCompletionState()
{
    ToggleCallOutBypass();
    object events = clone_object("/lib/tests/support/events/questEventsSubscriber.c");
    Quests.registerEvent(events);
    ExpectTrue(Quests.beginQuest("/lib/tests/support/quests/anotherQuest.c"));
    ExpectEq((["onQuestStarted":"/lib/tests/support/quests/anotherQuest.c",
        "onQuestCompleted": "/lib/tests/support/quests/anotherQuest.c",
        "onQuestSucceeded": "/lib/tests/support/quests/anotherQuest.c"]),
        events.quests());
    ToggleCallOutBypass();
}

/////////////////////////////////////////////////////////////////////////////
void AdvanceQuestStateFiresEachTimeStateAdvances()
{
    ToggleCallOutBypass();
    object events = clone_object("/lib/tests/support/events/questEventsSubscriber.c");
    Quests.registerEvent(events);

    ExpectTrue(Quests.beginQuest("/lib/tests/support/quests/fakeQuestItem.c"));
    ExpectFalse(member(events.quests(), "onQuestAdvancedState"));
    ExpectTrue(QuestItem.receiveEvent(Quests, "meetTheKing"));
    ExpectTrue(member(events.quests(), "onQuestAdvancedState"));

    events.clearEvents();
    ExpectFalse(member(events.quests(), "onQuestAdvancedState"));
    ExpectTrue(QuestItem.receiveEvent(Quests, "ignoreTheKing"));
    ExpectTrue(member(events.quests(), "onQuestAdvancedState"));
    ToggleCallOutBypass();
}

/////////////////////////////////////////////////////////////////////////////
void AdvanceQuestToFailStateFiresOnQuestCompletedAndOnQuestFailed()
{
    ToggleCallOutBypass();
    object events = clone_object("/lib/tests/support/events/questEventsSubscriber.c");
    Quests.registerEvent(events);

    ExpectTrue(Quests.beginQuest("/lib/tests/support/quests/fakeQuestItem.c"));
    ExpectFalse(member(events.quests(), "onQuestCompleted"));
    ExpectFalse(member(events.quests(), "onQuestFailed"));
    ExpectTrue(QuestItem.receiveEvent(Quests, "meetTheKing"));
    ExpectTrue(QuestItem.receiveEvent(Quests, "ignoreTheKing"));
    ExpectTrue(member(events.quests(), "onQuestCompleted"));
    ExpectTrue(member(events.quests(), "onQuestFailed"));
    ToggleCallOutBypass();
}

/////////////////////////////////////////////////////////////////////////////
void AdvanceQuestToFailStateDoesNotFireOnQuestSucceeded()
{
    object events = clone_object("/lib/tests/support/events/questEventsSubscriber.c");
    Quests.registerEvent(events);

    ExpectTrue(Quests.beginQuest("/lib/tests/support/quests/fakeQuestItem.c"));
    ExpectFalse(member(events.quests(), "onQuestSucceeded"));
    ExpectTrue(QuestItem.receiveEvent(Quests, "meetTheKing"));
    ExpectTrue(QuestItem.receiveEvent(Quests, "ignoreTheKing"));
    ExpectFalse(member(events.quests(), "onQuestSucceeded"));
}

/////////////////////////////////////////////////////////////////////////////
void AdvanceQuestToSuccessStateFiresOnQuestCompletedAndOnQuestSucceeded()
{
    ToggleCallOutBypass();
    object events = clone_object("/lib/tests/support/events/questEventsSubscriber.c");
    Quests.registerEvent(events);

    ExpectTrue(Quests.beginQuest("/lib/tests/support/quests/fakeQuestItem.c"));
    ExpectFalse(member(events.quests(), "onQuestCompleted"));
    ExpectFalse(member(events.quests(), "onQuestSucceeded"));
    ExpectTrue(QuestItem.receiveEvent(Quests, "meetTheKing"));
    ExpectTrue(QuestItem.receiveEvent(Quests, "serveTheKing"));
    ExpectTrue(QuestItem.receiveEvent(Quests, "hailToTheKing"));
    ExpectTrue(member(events.quests(), "onQuestCompleted"));
    ExpectTrue(member(events.quests(), "onQuestSucceeded"));
    ToggleCallOutBypass();
}

/////////////////////////////////////////////////////////////////////////////
void AdvanceQuestToSuccessStateDoesNotFireOnQuestFailed()
{
    object events = clone_object("/lib/tests/support/events/questEventsSubscriber.c");
    Quests.registerEvent(events);

    ExpectTrue(Quests.beginQuest("/lib/tests/support/quests/fakeQuestItem.c"));
    ExpectFalse(member(events.quests(), "onQuestFailed"));
    ExpectTrue(QuestItem.receiveEvent(Quests, "meetTheKing"));
    ExpectTrue(QuestItem.receiveEvent(Quests, "serveTheKing"));
    ExpectTrue(QuestItem.receiveEvent(Quests, "hailToTheKing"));
    ExpectFalse(member(events.quests(), "onQuestFailed"));
}

/////////////////////////////////////////////////////////////////////////////
void ActivateQuestFiresOnQuestActivatedWhenItSucceeds()
{
    ToggleCallOutBypass();
    object events = clone_object("/lib/tests/support/events/questEventsSubscriber.c");
    Quests.registerEvent(events);

    ExpectTrue(Quests.beginQuest("/lib/tests/support/quests/fakeQuestItem.c"));
    ExpectFalse(member(events.quests(), "onQuestActivated"));
    ExpectTrue(Quests.activateQuest("/lib/tests/support/quests/fakeQuestItem.c"));
    ExpectTrue(member(events.quests(), "onQuestActivated"));
    ToggleCallOutBypass();
}

/////////////////////////////////////////////////////////////////////////////
void ActivateQuestDoesNotFireOnQuestActivatedWhenItFails()
{
    object events = clone_object("/lib/tests/support/events/questEventsSubscriber.c");
    Quests.registerEvent(events);

    ExpectFalse(member(events.quests(), "onQuestActivated"));
    ExpectFalse(Quests.activateQuest("/lib/tests/support/quests/fakeQuestItem.c"));
    ExpectFalse(member(events.quests(), "onQuestActivated"));
}

/////////////////////////////////////////////////////////////////////////////
void DeactivateQuestFiresOnQuestActivatedWhenItSucceeds()
{
    ToggleCallOutBypass();
    object events = clone_object("/lib/tests/support/events/questEventsSubscriber.c");
    Quests.registerEvent(events);

    ExpectTrue(Quests.beginQuest("/lib/tests/support/quests/fakeQuestItem.c"));
    ExpectFalse(member(events.quests(), "onQuestDeactivated"));
    ExpectTrue(Quests.deactivateQuest("/lib/tests/support/quests/fakeQuestItem.c"));
    ExpectTrue(member(events.quests(), "onQuestDeactivated"));
    ToggleCallOutBypass();
}

/////////////////////////////////////////////////////////////////////////////
void DeactivateQuestDoesNotFireOnQuestActivatedWhenItFails()
{
    object events = clone_object("/lib/tests/support/events/questEventsSubscriber.c");
    Quests.registerEvent(events);

    ExpectFalse(member(events.quests(), "onQuestDeactivated"));
    ExpectFalse(Quests.deactivateQuest("/lib/tests/support/quests/fakeQuestItem.c"));
    ExpectFalse(member(events.quests(), "onQuestDeactivated"));
}
