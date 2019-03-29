//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";
#include "/lib/include/inventory.h"

object QuestItem;
object King;
object Quester;

/////////////////////////////////////////////////////////////////////////////
void SetUpQuestItem()
{
    QuestItem->testSetName("Hail to the king, baby!");
    QuestItem->testAddState("meet the king", "I've been asked to meet the king!");

    QuestItem->testAddState("met the king", 
        "I met King Tantor the Unclean of Thisplace. He seems to like me.");
    QuestItem->testAddTransition("meet the king", "met the king", "meetTheKing",
        "/lib/tests/support/quests/testKingObject.c");

    QuestItem->testAddState("serve the king",
        "The king asked me - ME - to be his personal manservant. Yay me!");
    QuestItem->testAddTransition("met the king", "serve the king", "serveTheKing");

    QuestItem->testAddState("ignore the king",
        "I told the king to piss off. I have socks to fold.");
    QuestItem->testAddTransition("met the king", "ignore the king", "ignoreTheKing");
    QuestItem->testAddEntryAction("ignore the king", "killTheKing");
    QuestItem->testAddFinalState("ignore the king", "failure");

    QuestItem->testAddState("save the king",
        "Earl the Grey tried to kill the king but I gutted him like a fish.");
    QuestItem->testAddTransition("serve the king", "save the king", "hailToTheKing");
    QuestItem->testAddFinalState("save the king", "success");

    QuestItem->testAddState("king is dead",
        "I must lay off the sauce - and the wenches. King Tantor is dead because of my night of debauchery.");
    QuestItem->testAddTransition("serve the king", "king is dead", "maybeNobodyWillNotice");
    QuestItem->testAddFinalState("king is dead", "failure");

    King = clone_object("/lib/tests/support/quests/testKingObject.c");
    QuestItem->testRegisterQuestActor(King);
    King->SetQuestItem(QuestItem);
    King->SetQuester(Quester);

    object room = clone_object("/lib/environment/environment.c");
    move_object(King, room);

    QuestItem->testSetInitialState("meet the king");
    Quester->StartQuest(QuestItem);
}

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    ignoreList += ({ "SetUpQuestItem" });
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    ToggleCallOutBypass();
    Quester = clone_object("/lib/tests/support/services/combatWithMockServices.c");
    Quester->ToggleMockQuests();

    QuestItem = clone_object("/lib/tests/support/quests/testQuestItem.c");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(King);
    destruct(QuestItem);
    destruct(Quester);
    ToggleCallOutBypass();
}

/////////////////////////////////////////////////////////////////////////////
void SetNameThrowsWhenNameNotValid()
{
    string err = catch (QuestItem->setName(3));
    ExpectEq("*ERROR - questItem: the name must be a string.", err);
}

/////////////////////////////////////////////////////////////////////////////
void SetNameSetsTheNameOfTheQuestItem()
{
    ExpectFalse(QuestItem->name());
    QuestItem->setName("Test");
    ExpectEq("Test", QuestItem->name());
}

/////////////////////////////////////////////////////////////////////////////
void SetDescriptionThrowsWhenNameNotValid()
{
    string err = catch (QuestItem->setDescription(3));
    ExpectEq("*ERROR - questItem: the description must be a string.", err);
}

/////////////////////////////////////////////////////////////////////////////
void SetDescriptionSetsTheNameOfTheQuestItem()
{
    ExpectEq("", QuestItem->description());
    QuestItem->setDescription("Test");
    ExpectEq("Test", QuestItem->description());
}
/////////////////////////////////////////////////////////////////////////////
void AddStateThrowsWhenStateNotValid()
{
    string err = catch (QuestItem->testAddState());
    ExpectEq("*ERROR - stateMachine: the state could not be added.", err);
}

/////////////////////////////////////////////////////////////////////////////
void AddStateThrowsWhenDescriptionNotValid()
{
    string err = catch (QuestItem->testAddState("blah"));
    ExpectEq("*ERROR - stateMachine: the state could not be added.", err);
}

/////////////////////////////////////////////////////////////////////////////
void AddStateSilentlySucceedsWhenStateIsValid()
{
    // If anything were to go amiss, this would throw.
    QuestItem->testAddState("meet the king", "I've been asked to meet the king!");
}

/////////////////////////////////////////////////////////////////////////////
void AddStateThrowsWhenAddingTheSameStateTwice()
{
    QuestItem->testAddState("meet the king", "I've been asked to meet the king!");
    string err = catch (QuestItem->testAddState("meet the king", "I've been asked to meet the king!"));
    ExpectEq("*ERROR - stateMachine: the 'meet the king' state has already been added.", err);
}

/////////////////////////////////////////////////////////////////////////////
void AddStateThrowsWhenAddingAnInvalidEntryEvent()
{
    string err = catch (QuestItem->testAddState("meet the king", "I've been asked to meet the king!", 25));
    ExpectEq("*ERROR - stateMachine: the entry event must be a string.", err);
}

/////////////////////////////////////////////////////////////////////////////
void AddStateSilentlySucceedsWhenEntryEventIsValid()
{
    // If anything were to go amiss, this would throw.
    QuestItem->testAddState("meet the king", "I've been asked to meet the king!", "someEvent");
}

/////////////////////////////////////////////////////////////////////////////
void AddStateThrowsWhenAddingAnInvalidFinalStateResult()
{
    string err = catch (QuestItem->testAddState("meet the king", "I've been asked to meet the king!", "killTheKing", "blah"));
    ExpectEq("*ERROR - stateMachine: the final state result must be 'success' or 'failure'.", err);
}

/////////////////////////////////////////////////////////////////////////////
void AddStateSilentlySucceedsWhenFinalStateResultIsSuccess()
{
    // If anything were to go amiss, this would throw.
    QuestItem->testAddState("meet the king", "I've been asked to meet the king!", "killTheKing", "success");
}

/////////////////////////////////////////////////////////////////////////////
void AddStateSilentlySucceedsWhenFinalStateResultIsFailure()
{
    // If anything were to go amiss, this would throw.
    QuestItem->testAddState("meet the king", "I've been asked to meet the king!", "killTheKing", "failure");
}

/////////////////////////////////////////////////////////////////////////////
void InitialStateThrowsWhenStateNotPresent()
{
    QuestItem->testAddState("meet the king", "I've been asked to meet the king!");
    string err = catch (QuestItem->testSetInitialState("blah"));
    ExpectEq("*ERROR - stateMachine: the initial state must have been added first.", err);
}

/////////////////////////////////////////////////////////////////////////////
void AddEntryActionThrowsWhenStateNotPresent()
{
    string err = catch (QuestItem->testAddEntryAction("blah", "things"));
    ExpectEq("*ERROR - stateMachine: an entry action can only be added if both the state exists and the method to call has been implemented on this object.", err);
}

/////////////////////////////////////////////////////////////////////////////
void AddEntryActionThrowsWhenAddingAnInvalidEntryAction()
{
    QuestItem->testAddState("meet the king", "I've been asked to meet the king!");

    string err = catch (QuestItem->testAddEntryAction("meet the king", "badMethod"));
    ExpectEq("*ERROR - stateMachine: an entry action can only be added if both the state exists and the method to call has been implemented on this object.", err);
}

/////////////////////////////////////////////////////////////////////////////
void AddEntryActionSilentlySucceedsWhenEverythingValidates()
{
    // If anything were to go amiss, this would throw.
    QuestItem->testAddState("meet the king", "I've been asked to meet the king!");
    QuestItem->testAddEntryAction("meet the king", "killTheKing");
}

/////////////////////////////////////////////////////////////////////////////
void AddExitActionThrowsWhenStateNotPresent()
{
    string err = catch (QuestItem->testAddExitAction("blah", "things"));
    ExpectEq("*ERROR - stateMachine: an exit action can only be added if both the state exists and the method to call has been implemented on this object.", err);
}

/////////////////////////////////////////////////////////////////////////////
void AddExitActionThrowsWhenAddingAnInvalidEntryAction()
{
    QuestItem->testAddState("meet the king", "I've been asked to meet the king!");

    string err = catch (QuestItem->testAddExitAction("meet the king", "badMethod"));
    ExpectEq("*ERROR - stateMachine: an exit action can only be added if both the state exists and the method to call has been implemented on this object.", err);
}

/////////////////////////////////////////////////////////////////////////////
void GetStateDescriptionReturnsDescriptionWhenStateExists()
{
    QuestItem->testAddState("meet the king", "I've been asked to meet the king!");
    ExpectEq("I've been asked to meet the king!", QuestItem->getStateDescription("meet the king"));
}

/////////////////////////////////////////////////////////////////////////////
void GetStateDescriptionReturnsNullWhenStateDoesNotExist()
{
    QuestItem->testAddState("meet the king", "I've been asked to meet the king!");
    ExpectFalse(QuestItem->getStateDescription("blah"));
}

/////////////////////////////////////////////////////////////////////////////
void AddExitActionSilentlySucceedsWhenEverythingValidates()
{
    // If anything were to go amiss, this would throw.
    QuestItem->testAddState("meet the king", "I've been asked to meet the king!");
    QuestItem->testAddExitAction("meet the king", "killTheKing");
}

/////////////////////////////////////////////////////////////////////////////
void SetInitialStateSetsTheInitialState()
{
    // If anything were to go amiss, this would throw.
    QuestItem->testAddState("meet the king", "I've been asked to meet the king!");
    QuestItem->testSetInitialState("meet the king");
    ExpectEq("meet the king", QuestItem->initialState());
}

/////////////////////////////////////////////////////////////////////////////
void AddTransitionThrowsWhenStatesDoNotExist()
{
    string err = catch (QuestItem->testAddTransition("a", "b", "someEvent"));
    ExpectEq("*ERROR - stateMachine: the transition could not be added.", err);
}

/////////////////////////////////////////////////////////////////////////////
void AddTransitionThrowsWhenFirstStateDoesNotExist()
{
    QuestItem->testAddState("b", "do b stuff");
    string err = catch (QuestItem->testAddTransition("a", "b", "someEvent"));
    ExpectEq("*ERROR - stateMachine: the transition could not be added.", err);
}

/////////////////////////////////////////////////////////////////////////////
void AddTransitionThrowsWhenSecondStateDoesNotExist()
{
    QuestItem->testAddState("a", "do a stuff");
    string err = catch (QuestItem->testAddTransition("a", "b", "someEvent"));
    ExpectEq("*ERROR - stateMachine: the transition could not be added.", err);
}

/////////////////////////////////////////////////////////////////////////////
void AddTransitionSilentlySucceedsWhenStatesValidate()
{
    QuestItem->testAddState("a", "do a stuff");
    QuestItem->testAddState("b", "do b stuff");
    QuestItem->testAddTransition("a", "b", "someEvent");
}

/////////////////////////////////////////////////////////////////////////////
void AddTransitionThrowsWhenEventHasAlreadyBeenAdded()
{
    QuestItem->testAddState("a", "do a stuff");
    QuestItem->testAddState("b", "do b stuff");
    QuestItem->testAddTransition("a", "b", "someEvent");

    QuestItem->testAddState("c", "do c stuff");
    string err = catch (QuestItem->testAddTransition("a", "c", "someEvent"));
    ExpectEq("*ERROR - stateMachine: a transition for that event already exists.", err);
}

/////////////////////////////////////////////////////////////////////////////
void AddTransitionThrowsWhenAnInvalidInitiatorIsPassed()
{
    QuestItem->testAddState("a", "do a stuff");
    QuestItem->testAddState("b", "do b stuff");

    string err = catch (QuestItem->testAddTransition("a", "b", "someEvent", "invalidInitiator"));
    ExpectEq("*ERROR - stateMachine: the transition initiator must be a valid program name.", err);
}

/////////////////////////////////////////////////////////////////////////////
void AddTransitionSilentlySucceedsWhenEverythingValidates()
{
    QuestItem->testAddState("a", "do a stuff");
    QuestItem->testAddState("b", "do b stuff");
    QuestItem->testAddTransition("a", "b", "someEvent", "/lib/realizations/living.c");
}

/////////////////////////////////////////////////////////////////////////////
void QuestStoryReturnsCorrectNarrativeForQuestStatesCompleted()
{
    SetUpQuestItem();
    ExpectEq("\x1b[0;36mI've been asked to meet the king! I met King Tantor "
        "the Unclean of Thisplace. He seems to like me. The king asked me - "
        "ME - to be his personal manservant. Yay me! I told the king to piss "
        "off. I have socks to fold.\x1b[0m\x1b[0;31;1m [Failure]\x1b[0m",
        QuestItem->questStory(({"meet the king", "met the king", "serve the king", "ignore the king"}),
            clone_object("/lib/realizations/player.c")));
}

/////////////////////////////////////////////////////////////////////////////
void CanTransitionQuestStates()
{
    SetUpQuestItem();

    ExpectEq("meet the king", Quester->questState(program_name(QuestItem)));

    King->DoMeetTheKingStuff();
    ExpectEq("met the king", Quester->questState(program_name(QuestItem)));
}

/////////////////////////////////////////////////////////////////////////////
void DoesNotTransitionIfNotInProperStateForEvent()
{
    SetUpQuestItem();

    ExpectEq("meet the king", Quester->questState(program_name(QuestItem)));

    King->ConfuseTheForcesOfEvil();
    ExpectEq("meet the king", Quester->questState(program_name(QuestItem)));
}

/////////////////////////////////////////////////////////////////////////////
void OnEnterEventsFireWhenTransitionOccurs()
{
    SetUpQuestItem();
    QuestItem->testAddEntryAction("met the king", "doEnterStuff");
    ExpectEq("meet the king", Quester->questState(program_name(QuestItem)));
    ExpectTrue(sizeof(QuestItem->actionList()) == 0);

    King->DoMeetTheKingStuff();
    ExpectEq("met the king", Quester->questState(program_name(QuestItem)));
    ExpectTrue(sizeof(QuestItem->actionList()) == 1);
    ExpectTrue(member(QuestItem->actionList(), "Enter stuff has been done.") == 0);
}

/////////////////////////////////////////////////////////////////////////////
void OnExitEventsFireWhenTransitionOccurs()
{
    SetUpQuestItem();
    QuestItem->testAddExitAction("meet the king", "doExitStuff");
    ExpectEq("meet the king", Quester->questState(program_name(QuestItem)));
    ExpectTrue(sizeof(QuestItem->actionList()) == 0);

    King->DoMeetTheKingStuff();
    ExpectEq("met the king", Quester->questState(program_name(QuestItem)));
    ExpectTrue(sizeof(QuestItem->actionList()) == 1);
    ExpectTrue(member(QuestItem->actionList(), "Exit stuff has been done.") == 0);
}

/////////////////////////////////////////////////////////////////////////////
void OnEnterAndExitEventsFireInCorrectOrder()
{
    SetUpQuestItem();
    QuestItem->testAddExitAction("meet the king", "doExitStuff");
    QuestItem->testAddEntryAction("met the king", "doEnterStuff");

    ExpectEq("meet the king", Quester->questState(program_name(QuestItem)));
    ExpectTrue(sizeof(QuestItem->actionList()) == 0);

    King->DoMeetTheKingStuff();
    ExpectEq("met the king", Quester->questState(program_name(QuestItem)));
    ExpectTrue(sizeof(QuestItem->actionList()) == 2);
    ExpectTrue(member(QuestItem->actionList(), "Exit stuff has been done.") == 0);
    ExpectTrue(member(QuestItem->actionList(), "Enter stuff has been done.") == 1);
}

/////////////////////////////////////////////////////////////////////////////
void OnEnterDoesNotFireEventWhenNoneSet()
{
    SetUpQuestItem();

    ExpectEq("meet the king", Quester->questState(program_name(QuestItem)));
    ExpectFalse(King->checkNotification());

    King->DoMeetTheKingStuff();
    ExpectEq("met the king", Quester->questState(program_name(QuestItem)));
    ExpectFalse(King->checkNotification());
}

/////////////////////////////////////////////////////////////////////////////
void OnEnterFiresEventWhenItHasBeenSet()
{
    QuestItem->testAddState("meet the king", "I've been asked to meet the king!");

    QuestItem->testAddState("met the king",
        "I met King Tantor the Unclean of Thisplace. He seems to like me.", "someEvent");
    QuestItem->testAddTransition("meet the king", "met the king", "meetTheKing");

    King = clone_object("/lib/tests/support/quests/testKingObject.c");
    object subscriber = clone_object("/lib/tests/support/quests/someEventHandler.c");
    King->registerEvent(subscriber);
    QuestItem->testRegisterQuestActor(King);
    King->SetQuestItem(QuestItem);
    King->SetQuester(Quester);

    object room = clone_object("/lib/environment/environment.c");
    move_object(King, room);

    QuestItem->testSetInitialState("meet the king");
    Quester->StartQuest(QuestItem);
    ExpectTrue(QuestItem->beginQuest(Quester));

    ExpectEq("meet the king", Quester->questState(program_name(QuestItem)));
    ExpectFalse(subscriber->checkNotification());

    King->DoMeetTheKingStuff();
    ExpectEq("met the king", Quester->questState(program_name(QuestItem)));
    ExpectEq("someEvent", subscriber->checkNotification());
}

/////////////////////////////////////////////////////////////////////////////
void OnEnterFiresIfSetForInitialState()
{
    QuestItem->testAddState("meet the king", "I've been asked to meet the king!");
    QuestItem->testAddEntryAction("meet the king", "doEnterStuff");

    King = clone_object("/lib/tests/support/quests/testKingObject.c");
    QuestItem->testRegisterQuestActor(King);
    King->SetQuestItem(QuestItem);
    King->SetQuester(Quester);

    object room = clone_object("/lib/environment/environment.c");
    move_object(King, room);

    QuestItem->testSetInitialState("meet the king");
    ExpectFalse(member(QuestItem->actionList(), "Enter stuff has been done.") == 0);
    Quester->StartQuest(QuestItem);

    ExpectTrue(QuestItem->beginQuest(Quester));
    ExpectEq("meet the king", Quester->questState(program_name(QuestItem)));
    ExpectTrue(member(QuestItem->actionList(), "Enter stuff has been done.") == 0);
}

/////////////////////////////////////////////////////////////////////////////
void EntryEventFiresIfSetForInitialState()
{
    QuestItem->testAddState("meet the king", "I've been asked to meet the king!", "someEvent");

    King = clone_object("/lib/tests/support/quests/testKingObject.c");
    object subscriber = clone_object("/lib/tests/support/quests/someEventHandler.c");
    King->registerEvent(subscriber);
    QuestItem->testRegisterQuestActor(King);
    King->SetQuestItem(QuestItem);
    King->SetQuester(Quester);

    object room = clone_object("/lib/environment/environment.c");
    move_object(King, room);

    QuestItem->testSetInitialState("meet the king");
    ExpectFalse(subscriber->checkNotification());
    Quester->StartQuest(QuestItem);

    ExpectTrue(QuestItem->beginQuest(Quester));
    ExpectEq("meet the king", Quester->questState(program_name(QuestItem)));
    ExpectEq("someEvent", subscriber->checkNotification());
}

/////////////////////////////////////////////////////////////////////////////
void CanBeginQuestReturnsTrueIfNoPrerequisitesSet()
{
    SetUpQuestItem();

    ExpectTrue(QuestItem->canBeginQuest(Quester));
}

/////////////////////////////////////////////////////////////////////////////
void CanBeginQuestReturnsFalseIfPrerequisitesNotMet()
{
    SetUpQuestItem();
    QuestItem->testAddPrerequisite("long sword", (["type":"skill", "value" : 10]));

    ExpectFalse(QuestItem->canBeginQuest(Quester));
}

/////////////////////////////////////////////////////////////////////////////
void CanBeginQuestReturnsTrueIfPrerequisitesMet()
{
    SetUpQuestItem();
    QuestItem->testAddPrerequisite("long sword", (["type":"skill", "value" : 10]));
    Quester->Str(20);
    Quester->addSkillPoints(100);
    Quester->advanceSkill("long sword", 10);
    ExpectTrue(QuestItem->canBeginQuest(Quester));
}

/////////////////////////////////////////////////////////////////////////////
void BeginQuestReturnsFalseIfPrerequisitesNotMet()
{
    SetUpQuestItem();
    QuestItem->testAddPrerequisite("long sword", (["type":"skill", "value" : 10]));

    ExpectFalse(QuestItem->beginQuest(Quester));
}

/////////////////////////////////////////////////////////////////////////////
void BeginQuestReturnsTrueIfPrerequisitesMet()
{
    SetUpQuestItem();
    QuestItem->testAddPrerequisite("long sword", (["type":"skill", "value" : 10]));
    Quester->Str(20);
    Quester->addSkillPoints(100);
    Quester->advanceSkill("long sword", 10);
    ExpectTrue(QuestItem->beginQuest(Quester));
}

/////////////////////////////////////////////////////////////////////////////
void QuestInCompletionStateReturnsTrueWhenQuestCompletesAsFailure()
{
    SetUpQuestItem();

    ExpectFalse(QuestItem->questInCompletionState(Quester->questState(program_name(QuestItem))));

    King->DoMeetTheKingStuff();
    ExpectFalse(QuestItem->questInCompletionState(Quester->questState(program_name(QuestItem))));

    King->TimeToFoldSocks();
    ExpectEq("ignore the king", Quester->questState(program_name(QuestItem)));
    ExpectTrue(QuestItem->questInCompletionState(Quester->questState(program_name(QuestItem))));
}

/////////////////////////////////////////////////////////////////////////////
void QuestSucceededReturnsFalseWhenQuestCompletesAsFailure()
{
    SetUpQuestItem();

    ExpectFalse(QuestItem->questSucceeded(Quester));

    King->DoMeetTheKingStuff();
    King->TimeToFoldSocks();
    ExpectTrue(QuestItem->questInCompletionState(Quester->questState(program_name(QuestItem))));
    ExpectFalse(QuestItem->questSucceeded(Quester));
}

/////////////////////////////////////////////////////////////////////////////
void QuestInCompletionStateReturnsTrueWhenQuestCompletesAsSuccess()
{
    SetUpQuestItem();

    ExpectFalse(QuestItem->questInCompletionState(Quester->questState(program_name(QuestItem))));

    King->DoMeetTheKingStuff();
    ExpectFalse(QuestItem->questInCompletionState(Quester->questState(program_name(QuestItem))));

    King->SureIWillServe();
    ExpectFalse(QuestItem->questInCompletionState(Quester->questState(program_name(QuestItem))));

    King->ConfuseTheForcesOfEvil();
    ExpectTrue(QuestItem->questInCompletionState(Quester->questState(program_name(QuestItem))));
}

/////////////////////////////////////////////////////////////////////////////
void QuestSucceededReturnsTrueWhenQuestCompletesAsSuccess()
{
    SetUpQuestItem();

    ExpectFalse(QuestItem->questSucceeded(Quester));

    King->DoMeetTheKingStuff();
    ExpectFalse(QuestItem->questSucceeded(Quester)); 

    King->SureIWillServe();
    ExpectFalse(QuestItem->questSucceeded(Quester));

    King->ConfuseTheForcesOfEvil();
    ExpectTrue(QuestItem->questSucceeded(Quester));
}
