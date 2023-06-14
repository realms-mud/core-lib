//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";
#include "/lib/include/inventory.h"

object StateMachine;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    ToggleCallOutBypass();
    StateMachine = clone_object("/lib/tests/support/core/testStateMachine.c");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(StateMachine);
    ToggleCallOutBypass();
}

/////////////////////////////////////////////////////////////////////////////
void AddStateThrowsWhenStateNotValid()
{
    string err = catch (StateMachine.testAddState(); nolog);
    ExpectEq("*ERROR - stateMachine: the state could not be added.", err);
}

/////////////////////////////////////////////////////////////////////////////
void AddStateThrowsWhenDescriptionNotValid()
{
    string err = catch (StateMachine.testAddState("blah"); nolog);
    ExpectEq("*ERROR - stateMachine: the state could not be added.", err);
}

/////////////////////////////////////////////////////////////////////////////
void AddStateSilentlySucceedsWhenStateIsValid()
{
    // If anything were to go amiss, this would throw.
    StateMachine.testAddState("added state", "I've been asked to meet the king!");
}

/////////////////////////////////////////////////////////////////////////////
void AddStateThrowsWhenAddingTheSameStateTwice()
{
    StateMachine.testAddState("added state", "I've been asked to meet the king!");
    string err = catch (StateMachine.testAddState("added state", "I've been asked to meet the king!"); nolog);
    ExpectEq("*ERROR - stateMachine: the 'added state' state has already been added.", err);
}

/////////////////////////////////////////////////////////////////////////////
void AddStateThrowsWhenAddingAnInvalidEntryEvent()
{
    string err = catch (StateMachine.testAddState("added state", "I've been asked to meet the king!", 25); nolog);
    ExpectEq("*ERROR - stateMachine: the entry event must be a string.", err);
}

/////////////////////////////////////////////////////////////////////////////
void AddStateSilentlySucceedsWhenEntryEventIsValid()
{
    // If anything were to go amiss, this would throw.
    StateMachine.testAddState("added state", "I've been asked to meet the king!", "someEvent");
}

/////////////////////////////////////////////////////////////////////////////
void AddStateThrowsWhenAddingAnInvalidFinalStateResult()
{
    string err = catch (StateMachine.testAddState("added state", "I've been asked to meet the king!", "killTheKing", "blah"); nolog);
    ExpectEq("*ERROR - stateMachine: the final state result must be 'success' or 'failure'.", err);
}

/////////////////////////////////////////////////////////////////////////////
void AddStateSilentlySucceedsWhenFinalStateResultIsSuccess()
{
    // If anything were to go amiss, this would throw.
    StateMachine.testAddState("added state", "I've been asked to meet the king!", "killTheKing", "success");
}

/////////////////////////////////////////////////////////////////////////////
void AddStateSilentlySucceedsWhenFinalStateResultIsFailure()
{
    // If anything were to go amiss, this would throw.
    StateMachine.testAddState("added state", "I've been asked to meet the king!", "killTheKing", "failure");
}
/////////////////////////////////////////////////////////////////////////////
void InitialStateThrowsWhenStateNotPresent()
{
    StateMachine.testAddState("added state", "I've been asked to meet the king!");
    string err = catch (StateMachine.testSetInitialState("blah"); nolog);
    ExpectEq("*ERROR - stateMachine: the initial state must have been added first.", err);
}

/////////////////////////////////////////////////////////////////////////////
void AddEntryActionThrowsWhenStateNotPresent()
{
    string err = catch (StateMachine.testAddEntryAction("blah", "things"); nolog);
    ExpectEq("*ERROR - stateMachine: an entry action can only be added if both the state exists and the method to call has been implemented on this object.", err);
}

/////////////////////////////////////////////////////////////////////////////
void AddEntryActionThrowsWhenAddingAnInvalidEntryAction()
{
    StateMachine.testAddState("added state", "I've been asked to meet the king!");

    string err = catch (StateMachine.testAddEntryAction("added state", "badMethod"); nolog);
    ExpectEq("*ERROR - stateMachine: an entry action can only be added if both the state exists and the method to call has been implemented on this object.", err);
}

/////////////////////////////////////////////////////////////////////////////
void AddEntryActionSilentlySucceedsWhenEverythingValidates()
{
    // If anything were to go amiss, this would throw.
    StateMachine.testAddState("added state", "I've been asked to meet the king!");
    StateMachine.testAddEntryAction("added state", "killTheKing");
}

/////////////////////////////////////////////////////////////////////////////
void AddExitActionThrowsWhenStateNotPresent()
{
    string err = catch (StateMachine.testAddExitAction("blah", "things"); nolog);
    ExpectEq("*ERROR - stateMachine: an exit action can only be added if both the state exists and the method to call has been implemented on this object.", err);
}

/////////////////////////////////////////////////////////////////////////////
void AddExitActionThrowsWhenAddingAnInvalidEntryAction()
{
    StateMachine.testAddState("added state", "I've been asked to meet the king!");

    string err = catch (StateMachine.testAddExitAction("added state", "badMethod"); nolog);
    ExpectEq("*ERROR - stateMachine: an exit action can only be added if both the state exists and the method to call has been implemented on this object.", err);
}

/////////////////////////////////////////////////////////////////////////////
void GetStateDescriptionReturnsDescriptionWhenStateExists()
{
    StateMachine.testAddState("added state", "I've been asked to meet the king!");
    ExpectEq("I've been asked to meet the king!", StateMachine.getStateDescription("meet the king"));
}

/////////////////////////////////////////////////////////////////////////////
void GetStateDescriptionReturnsNullWhenStateDoesNotExist()
{
    StateMachine.testAddState("added state", "I've been asked to meet the king!");
    ExpectFalse(StateMachine.getStateDescription("blah"));
}

/////////////////////////////////////////////////////////////////////////////
void AddExitActionSilentlySucceedsWhenEverythingValidates()
{
    // If anything were to go amiss, this would throw.
    StateMachine.testAddState("added state", "I've been asked to meet the king!");
    StateMachine.testAddExitAction("added state", "killTheKing");
}

/////////////////////////////////////////////////////////////////////////////
void SetInitialStateSetsTheInitialState()
{
    // If anything were to go amiss, this would throw.
    StateMachine.testAddState("added state", "I've been asked to meet the king!");
    StateMachine.testSetInitialState("added state");
    ExpectEq("added state", StateMachine.initialState());
}

/////////////////////////////////////////////////////////////////////////////
void AddTransitionThrowsWhenStatesDoNotExist()
{
    string err = catch (StateMachine.testAddTransition("a", "b", "someEvent"); nolog);
    ExpectEq("*ERROR - stateMachine: the transition could not be added.", err);
}

/////////////////////////////////////////////////////////////////////////////
void AddTransitionThrowsWhenFirstStateDoesNotExist()
{
    StateMachine.testAddState("b", "do b stuff");
    string err = catch (StateMachine.testAddTransition("a", "b", "someEvent"); nolog);
    ExpectEq("*ERROR - stateMachine: the transition could not be added.", err);
}

/////////////////////////////////////////////////////////////////////////////
void AddTransitionThrowsWhenSecondStateDoesNotExist()
{
    StateMachine.testAddState("a", "do a stuff");
    string err = catch (StateMachine.testAddTransition("a", "b", "someEvent"); nolog);
    ExpectEq("*ERROR - stateMachine: the transition could not be added.", err);
}

/////////////////////////////////////////////////////////////////////////////
void AddTransitionSilentlySucceedsWhenStatesValidate()
{
    StateMachine.testAddState("a", "do a stuff");
    StateMachine.testAddState("b", "do b stuff");
    StateMachine.testAddTransition("a", "b", "someEvent");
}

/////////////////////////////////////////////////////////////////////////////
void AddTransitionThrowsWhenEventHasAlreadyBeenAdded()
{
    StateMachine.testAddState("a", "do a stuff");
    StateMachine.testAddState("b", "do b stuff");
    StateMachine.testAddTransition("a", "b", "someEvent");

    StateMachine.testAddState("c", "do c stuff");
    string err = catch (StateMachine.testAddTransition("a", "c", "someEvent"); nolog);
    ExpectEq("*ERROR - stateMachine: a transition for that event already exists.", err);
}

/////////////////////////////////////////////////////////////////////////////
void AddTransitionThrowsWhenAnInvalidInitiatorIsPassed()
{
    StateMachine.testAddState("a", "do a stuff");
    StateMachine.testAddState("b", "do b stuff");

    string err = catch (StateMachine.testAddTransition("a", "b", "someEvent", "/lib/invalidInitiator"); nolog);
    ExpectEq("*ERROR - stateMachine: the transition initiator must be a valid program name.", err);
}

/////////////////////////////////////////////////////////////////////////////
void AddTransitionSilentlySucceedsWhenEverythingValidates()
{
    StateMachine.testAddState("a", "do a stuff");
    StateMachine.testAddState("b", "do b stuff");
    StateMachine.testAddTransition("a", "b", "someEvent", "/lib/realizations/living.c");
}

/////////////////////////////////////////////////////////////////////////////
void CanTransitionStates()
{
    StateMachine.testStartStateMachine();
    ExpectEq("meet the king", StateMachine.getCurrentState());

    StateMachine.receiveEvent(this_object(), "meetTheKing", this_object());
    ExpectEq("met the king", StateMachine.getCurrentState());
}

/////////////////////////////////////////////////////////////////////////////
void DoesNotTransitionIfNotInProperStateForEvent()
{
    StateMachine.testStartStateMachine();
    ExpectEq("meet the king", StateMachine.getCurrentState());

    StateMachine.receiveEvent(this_object(), "hailToTheKing", this_object());
    ExpectEq("meet the king", StateMachine.getCurrentState());
}

/////////////////////////////////////////////////////////////////////////////
void OnEnterEventsFireWhenTransitionOccurs()
{
    StateMachine.testAddEntryAction("met the king", "doEnterStuff");
    StateMachine.testStartStateMachine();
    ExpectEq("meet the king", StateMachine.getCurrentState());
    ExpectTrue(sizeof(StateMachine.actionList()) == 0);

    StateMachine.receiveEvent(this_object(), "meetTheKing", this_object());
    ExpectEq("met the king", StateMachine.getCurrentState());
    ExpectTrue(sizeof(StateMachine.actionList()) == 1);
    ExpectTrue(member(StateMachine.actionList(), "Enter stuff has been done.") == 0);
}

/////////////////////////////////////////////////////////////////////////////
void OnExitEventsFireWhenTransitionOccurs()
{
    StateMachine.testAddExitAction("meet the king", "doExitStuff");
    StateMachine.testStartStateMachine();
    ExpectEq("meet the king", StateMachine.getCurrentState());
    ExpectTrue(sizeof(StateMachine.actionList()) == 0);

    StateMachine.receiveEvent(this_object(), "meetTheKing", this_object());
    ExpectEq("met the king", StateMachine.getCurrentState());
    ExpectTrue(sizeof(StateMachine.actionList()) == 1);
    ExpectTrue(member(StateMachine.actionList(), "Exit stuff has been done.") == 0);
}

/////////////////////////////////////////////////////////////////////////////
void OnEnterAndExitEventsFireInCorrectOrder()
{
    StateMachine.testAddExitAction("meet the king", "doExitStuff");
    StateMachine.testAddEntryAction("met the king", "doEnterStuff");
    StateMachine.testStartStateMachine();

    ExpectEq("meet the king", StateMachine.getCurrentState());
    ExpectTrue(sizeof(StateMachine.actionList()) == 0);

    StateMachine.receiveEvent(this_object(), "meetTheKing", this_object());
    ExpectEq("met the king", StateMachine.getCurrentState());
    ExpectTrue(sizeof(StateMachine.actionList()) == 2);
    ExpectTrue(member(StateMachine.actionList(), "Exit stuff has been done.") == 0);
    ExpectTrue(member(StateMachine.actionList(), "Enter stuff has been done.") == 1);
}

/////////////////////////////////////////////////////////////////////////////
void OnEnterDoesNotFireEventWhenNoneSet()
{
    object King = clone_object("/lib/tests/support/quests/testKingObject.c");
    object subscriber = clone_object("/lib/tests/support/quests/someEventHandler.c");
    King.registerEvent(subscriber);

    StateMachine.testRegisterStateActor(King);
    StateMachine.testStartStateMachine();

    ExpectEq("meet the king", StateMachine.getCurrentState());
    ExpectFalse(subscriber.checkNotification());

    StateMachine.receiveEvent(this_object(), "meetTheKing", this_object());
    ExpectEq("met the king", StateMachine.getCurrentState());
    ExpectFalse(subscriber.checkNotification());
}

/////////////////////////////////////////////////////////////////////////////
void OnEnterFiresEventWhenItHasBeenSet()
{
    StateMachine.testAddState("added state", "I've been asked to meet the king!");

    StateMachine.testAddState("next state",
        "I met King Tantor the Unclean of Thisplace. He seems to like me.", "someEvent");
    StateMachine.testAddTransition("added state", "next state", "meetTheKing");

    object King = clone_object("/lib/tests/support/quests/testKingObject.c");
    object subscriber = clone_object("/lib/tests/support/quests/someEventHandler.c");
    King.registerEvent(subscriber);
    ExpectEq(0, subscriber.checkNotification());
    StateMachine.testRegisterStateActor(King);
    King.SetQuestItem(StateMachine);
    King.SetQuester(StateMachine);

    object room = clone_object("/lib/environment/environment.c");
    move_object(King, room);

    StateMachine.testSetInitialState("added state");
    StateMachine.testStartStateMachine();

    ExpectEq("added state", StateMachine.getCurrentState());
    ExpectFalse(subscriber.checkNotification());

    King.DoMeetTheKingStuff();
    ExpectEq("next state", StateMachine.getCurrentState());
    ExpectEq("someEvent", subscriber.checkNotification());
}

/////////////////////////////////////////////////////////////////////////////
void OnEnterFiresIfSetForInitialState()
{
    StateMachine.testAddState("added state", "I've been asked to meet the king!");
    StateMachine.testAddEntryAction("added state", "doEnterStuff");

    object King = clone_object("/lib/tests/support/quests/testKingObject.c");
    StateMachine.testRegisterStateActor(King);

    object room = clone_object("/lib/environment/environment.c");
    move_object(King, room);

    StateMachine.testSetInitialState("added state");
    ExpectFalse(member(StateMachine.actionList(), "Enter stuff has been done.") == 0);
    StateMachine.testStartStateMachine();

    ExpectEq("added state", StateMachine.getCurrentState());
    ExpectTrue(member(StateMachine.actionList(), "Enter stuff has been done.") == 0);
}

/////////////////////////////////////////////////////////////////////////////
void EntryEventFiresIfSetForInitialState()
{
    StateMachine.testAddState("added state", "I've been asked to meet the king!", "someEvent");

    object King = clone_object("/lib/tests/support/quests/testKingObject.c");
    object subscriber = clone_object("/lib/tests/support/quests/someEventHandler.c");
    King.registerEvent(subscriber);
    ExpectEq(0, subscriber.checkNotification());
    StateMachine.testRegisterStateActor(King);
    King.SetQuestItem(StateMachine);
    King.SetQuester(StateMachine);

    object room = clone_object("/lib/environment/environment.c");
    move_object(King, room);

    StateMachine.testSetInitialState("added state");
    ExpectFalse(subscriber.checkNotification());
    StateMachine.testStartStateMachine();

    ExpectEq("added state", StateMachine.getCurrentState());
    ExpectEq("someEvent", subscriber.checkNotification());
}
