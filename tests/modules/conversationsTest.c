//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";
#include "/lib/include/inventory.h"

object Actor;
object Owner;
object Conversation;

/////////////////////////////////////////////////////////////////////////////
varargs void PrepActor(int useMock)
{
    if (useMock)
    {
        Actor = clone_object("/lib/tests/support/services/mockPlayer.c");
        Actor->Name("Gorthaur");
    }
    else
    {
        Actor = clone_object("/lib/realizations/player.c");
        Actor->restore("gorthaur");
    }
    move_object(Actor, "/lib/tests/support/environment/fakeEnvironment.c");
}

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    ignoreList += ({ "PrepActor" });
    setRestoreCaller(this_object());
    object database = clone_object("/lib/tests/modules/secure/fakeDatabase.c");
    database->PrepDatabase();

    object dataAccess = clone_object("/lib/modules/secure/dataAccess.c");
    dataAccess->savePlayerData(database->Gorthaur());

    destruct(dataAccess);
    destruct(database);
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    ToggleCallOutBypass();
    object room = load_object("/lib/tests/support/environment/fakeEnvironment.c");

    Owner = clone_object("/lib/tests/support/services/mockNPC.c");
    Owner->Name("Gertrude");
    Owner->Gender(2);
    move_object(Owner, room);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Owner);
    destruct(Actor);
    ToggleCallOutBypass();
}

/////////////////////////////////////////////////////////////////////////////
void AlterOpinionOfUpdatesOpinionOfTarget()
{
    PrepActor();
    Actor->addTrait("/lib/tests/support/traits/testNoOpposingRootTrait.c");
    ExpectEq(10, Owner->opinionOf(Actor));
    ExpectEq(5, Owner->alterOpinionOf(Actor, 5));
    ExpectEq(15, Owner->opinionOf(Actor));
}

/////////////////////////////////////////////////////////////////////////////
void AddConversationFailsIfFileDoesNotExist()
{
    ExpectEq("*ERROR - conversations.c, addConversation: '/a/bad/file.c' does not exist",
        catch (Owner->testAddConversation("/a/bad/file.c")));
}

/////////////////////////////////////////////////////////////////////////////
void AddConversationFailsIfFileDoesNotInheritBaseConversation()
{
    ExpectEq("*ERROR - conversations.c, addConversation: '/lib/realizations/player.c' must inherit /lib/modules/conversations/baseConversation.c",
        catch (Owner->testAddConversation("/lib/realizations/player.c")));
}

/////////////////////////////////////////////////////////////////////////////
void AddConversationFailsIfFileHasNoTopics()
{
    ExpectEq("*ERROR - conversations.c, addConversation: There are no conversations in '/lib/modules/conversations/baseConversation.c'",
        catch (Owner->testAddConversation("/lib/modules/conversations/baseConversation.c")));
}

/////////////////////////////////////////////////////////////////////////////
void InitialWithCharacterInitiatesFirstConversation()
{
    PrepActor(1);

    Owner->testAddConversation("/lib/tests/support/conversations/testConversation.c");
    command("talk", Actor);
    ExpectEq(2, sizeof(Actor->caughtMessages()));
    ExpectSubStringMatch("We start talking for the first time.", Actor->caughtMessages()[0]);
    ExpectSubStringMatch("OK...", Actor->caughtMessages()[1]);
}

/////////////////////////////////////////////////////////////////////////////
void TalkTwiceRepeatsCurrentTopic()
{
    PrepActor(1);

    Owner->testAddConversation("/lib/tests/support/conversations/testConversation.c");
    command("talk", Actor);
    ExpectEq(2, sizeof(Actor->caughtMessages()));
    ExpectSubStringMatch("We start talking for the first time.", Actor->caughtMessages()[0]);
    ExpectSubStringMatch("OK...", Actor->caughtMessages()[1]);

    Actor->resetCatchList();
    command("talk", Actor);
    ExpectEq(2, sizeof(Actor->caughtMessages()));
    ExpectSubStringMatch("We start talking for the first time.", Actor->caughtMessages()[0]);
    ExpectSubStringMatch("OK...", Actor->caughtMessages()[1]);
}

/////////////////////////////////////////////////////////////////////////////
void RepeatRepeatsCurrentTopic()
{
    PrepActor(1);

    Owner->testAddConversation("/lib/tests/support/conversations/testConversation.c");
    command("talk", Actor);
    ExpectEq(2, sizeof(Actor->caughtMessages()));
    ExpectSubStringMatch("We start talking for the first time.", Actor->caughtMessages()[0]);
    ExpectSubStringMatch("OK...", Actor->caughtMessages()[1]);

    Actor->resetCatchList();
    command("repeat", Actor);
    ExpectEq(2, sizeof(Actor->caughtMessages()));
    ExpectSubStringMatch("We start talking for the first time.", Actor->caughtMessages()[0]);
    ExpectSubStringMatch("OK...", Actor->caughtMessages()[1]);
}

/////////////////////////////////////////////////////////////////////////////
// NOTE: Order is critical for these next tests as the state of the
//       conversation is getting saved in the test database! Do not
//       reorder any of these or insert a test in between any cases
//       or you may well break something.
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
void CannotRespondToConversationWithInvalidResponse()
{
    PrepActor(1);

    Owner->testAddConversation("/lib/tests/support/conversations/testConversation.c");
    command("talk", Actor);
    ExpectEq(2, sizeof(Actor->caughtMessages()));
    ExpectSubStringMatch("We start talking for the first time.", Actor->caughtMessages()[0]);
    ExpectSubStringMatch("OK...", Actor->caughtMessages()[1]);
    command("2", Actor);
    ExpectSubStringMatch("What?", Actor->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanRespondToConversationWithValidResponse()
{
    PrepActor(1);

    Owner->testAddConversation("/lib/tests/support/conversations/testConversation.c");
    command("talk", Actor);
    ExpectEq(2, sizeof(Actor->caughtMessages()));
    ExpectSubStringMatch("We start talking for the first time.", Actor->caughtMessages()[0]);
    ExpectSubStringMatch("OK...", Actor->caughtMessages()[1]);
    command("1", Actor);
    ExpectSubStringMatch("Then let's talk", Actor->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void AfterFirstConversationIsCompleteNextTalkTriggersDefaultConversation()
{
    PrepActor(1);

    Owner->testAddConversation("/lib/tests/support/conversations/testConversation.c");
    command("talk", Actor);
    ExpectEq(3, sizeof(Actor->caughtMessages()));
    ExpectSubStringMatch("This is the default conversation", Actor->caughtMessages()[0]);
    ExpectSubStringMatch("Goodbye", Actor->caughtMessages()[1]);
    ExpectSubStringMatch("Quest...", Actor->caughtMessages()[2]);
}

/////////////////////////////////////////////////////////////////////////////
void SelectingTerminalTopicDoesHaveResponses()
{
    PrepActor(1);

    Owner->testAddConversation("/lib/tests/support/conversations/testConversation.c");
    command("talk", Actor);
    command("1", Actor);
    ExpectEq(5, sizeof(Actor->caughtMessages()));
    ExpectSubStringMatch("This is the default conversation", Actor->caughtMessages()[0]);
    ExpectSubStringMatch("Goodbye", Actor->caughtMessages()[1]);
    ExpectSubStringMatch("Quest...", Actor->caughtMessages()[2]);
    ExpectSubStringMatch("See you later!", Actor->caughtMessages()[3]);
    ExpectSubStringMatch("Not if I see you first.", Actor->caughtMessages()[4]);
}

/////////////////////////////////////////////////////////////////////////////
void TalkingAgainReturnsToDefaultConversation()
{
    PrepActor(1);

    Owner->testAddConversation("/lib/tests/support/conversations/testConversation.c");
    command("talk", Actor);
    command("1", Actor);

    Actor->resetCatchList();
    command("talk", Actor);
    ExpectEq(3, sizeof(Actor->caughtMessages()));
    ExpectSubStringMatch("This is the default conversation", Actor->caughtMessages()[0]);
    ExpectSubStringMatch("Goodbye", Actor->caughtMessages()[1]);
    ExpectSubStringMatch("Quest...", Actor->caughtMessages()[2]);
}

/////////////////////////////////////////////////////////////////////////////
void ShowsAdditionalResponseWhenStatePrerequisiteMet()
{
    PrepActor(1);

    Owner->testAddConversation("/lib/tests/support/conversations/testConversation.c");

    object stateMachine = load_object("/lib/tests/support/core/testStateMachine.c");
    stateMachine->testStartStateMachine();
    stateMachine->registerEvent(Actor);
    ExpectEq("meet the king", stateMachine->getCurrentState());
    stateMachine->receiveEvent(Owner, "meetTheKing", Actor);
    ExpectEq("met the king", stateMachine->getCurrentState());

    Actor->resetCatchList();
    command("talk", Actor);
    ExpectEq(4, sizeof(Actor->caughtMessages()));
    ExpectSubStringMatch("This is the default conversation", Actor->caughtMessages()[0]);
    ExpectSubStringMatch("Goodbye", Actor->caughtMessages()[1]);
    ExpectSubStringMatch("Quest...", Actor->caughtMessages()[2]);
    ExpectSubStringMatch("State Prerequisite", Actor->caughtMessages()[3]);
}

/////////////////////////////////////////////////////////////////////////////
void RemovesResponseWhenStatePrerequisiteNoLongerMet()
{
    PrepActor(1);

    Owner->testAddConversation("/lib/tests/support/conversations/testConversation.c");

    object stateMachine = load_object("/lib/tests/support/core/testStateMachine.c");
    stateMachine->testStartStateMachine();
    stateMachine->registerEvent(Actor);
    ExpectEq("meet the king", stateMachine->getCurrentState());
    stateMachine->receiveEvent(Owner, "meetTheKing", Actor);
    ExpectEq("met the king", stateMachine->getCurrentState());

    command("talk", Actor);
    ExpectEq(4, sizeof(Actor->caughtMessages()));
    command("1", Actor);

    stateMachine->receiveEvent(Owner, "serveTheKing", Actor);
    Actor->resetCatchList();
    command("talk", Actor);
    ExpectEq(3, sizeof(Actor->caughtMessages()));
}

/////////////////////////////////////////////////////////////////////////////
void ShowsAdditionalResponseWhenOpinionPrerequisiteMet()
{
    PrepActor(1);

    Owner->testAddConversation("/lib/tests/support/conversations/testConversation.c");
    Owner->alterOpinionOf(Actor, 50);

    Actor->resetCatchList();
    command("talk", Actor);
    ExpectEq(4, sizeof(Actor->caughtMessages()));
    ExpectSubStringMatch("This is the default conversation", Actor->caughtMessages()[0]);
    ExpectSubStringMatch("Goodbye", Actor->caughtMessages()[1]);
    ExpectSubStringMatch("Opinion Prerequisite", Actor->caughtMessages()[2]);
    ExpectSubStringMatch("Quest...", Actor->caughtMessages()[3]);
}

/////////////////////////////////////////////////////////////////////////////
void CanChainTopicsIntoMultiPartConversation()
{
    PrepActor(1);

    Owner->testAddConversation("/lib/tests/support/conversations/testConversation.c");
    Owner->alterOpinionOf(Actor, -25);

    command("talk", Actor);
    ExpectEq(3, sizeof(Actor->caughtMessages()));
    ExpectSubStringMatch("This is the default conversation", Actor->caughtMessages()[0]);
    ExpectSubStringMatch("Goodbye", Actor->caughtMessages()[1]);
    ExpectSubStringMatch("Quest...", Actor->caughtMessages()[2]);

    Actor->resetCatchList();
    command("2", Actor);
    ExpectEq(5, sizeof(Actor->caughtMessages()));
    ExpectSubStringMatch("I wanna do a quest!", Actor->caughtMessages()[0]);
    ExpectSubStringMatch("Greetings, seekers. Welcome to your trial", Actor->caughtMessages()[1]);
    ExpectSubStringMatch("I am someone", Actor->caughtMessages()[2]);
    ExpectSubStringMatch("My name is", Actor->caughtMessages()[3]);
    ExpectSubStringMatch("None of your business", Actor->caughtMessages()[4]);

    Actor->resetCatchList();
    command("2", Actor);
    ExpectEq(1, sizeof(Actor->caughtMessages()));
    ExpectSubStringMatch("I am Gorthaur and I am here to pass the trial", Actor->caughtMessages()[0]);
}

/////////////////////////////////////////////////////////////////////////////
void ExternalStateChangeWillReplaceDefaultConversationOnlyOnce()
{
    PrepActor(1);

    Owner->testAddConversation("/lib/tests/support/conversations/testConversation.c");
    object stateMachine = load_object("/lib/tests/support/core/testStateMachine.c");
    stateMachine->registerEvent(Owner);
    stateMachine->testStartStateMachine();

    Actor->resetCatchList();
    command("talk", Actor);
    ExpectEq(3, sizeof(Actor->caughtMessages()));
    ExpectSubStringMatch("This is the default conversation", Actor->caughtMessages()[0]);
    ExpectSubStringMatch("Goodbye", Actor->caughtMessages()[1]);
    ExpectSubStringMatch("Quest...", Actor->caughtMessages()[2]);
    command("1", Actor);

    Actor->resetCatchList();
    object commandObj = clone_object("/lib/tests/support/conversations/commandObj.c");
    move_object(commandObj, Actor);

    command("issueCommand", Actor);
    command("talk", Actor);
    ExpectSubStringMatch("You are serving the king", Actor->caughtMessage());

    Actor->resetCatchList();
    command("talk", Actor);
    ExpectEq(3, sizeof(Actor->caughtMessages()));
    ExpectSubStringMatch("This is the default conversation", Actor->caughtMessages()[0]);
}

/////////////////////////////////////////////////////////////////////////////
void CanHaveMultipleConversationObjectsAdded()
{
    PrepActor(1);

    Owner->testAddConversation("/lib/tests/support/conversations/testConversation.c");
    Owner->testAddConversation("/lib/tests/support/conversations/secondConversation.c");
    object stateMachine = load_object("/lib/tests/support/core/testStateMachine.c");
    stateMachine->registerEvent(Owner);
    stateMachine->testStartStateMachine();

    Actor->resetCatchList();
    command("talk", Actor);
    ExpectEq(3, sizeof(Actor->caughtMessages()));
    ExpectSubStringMatch("This is the default conversation", Actor->caughtMessages()[0]);
    ExpectSubStringMatch("Goodbye", Actor->caughtMessages()[1]);
    ExpectSubStringMatch("Quest...", Actor->caughtMessages()[2]);
    command("1", Actor);

    Actor->resetCatchList();
    object commandObj = clone_object("/lib/tests/support/conversations/commandObj.c");
    move_object(commandObj, Actor);

    command("triggerSecond", Actor);
    command("talk", Actor);
    ExpectSubStringMatch("Piss off you gorbellied twit-goblin!", Actor->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void RepeatableTopicsAreRepeatedWhenTalkTriggered()
{
    PrepActor(1);

    Owner->testAddConversation("/lib/tests/support/conversations/testConversation.c");
    Owner->testAddConversation("/lib/tests/support/conversations/secondConversation.c");
    object stateMachine = load_object("/lib/tests/support/core/testStateMachine.c");
    stateMachine->registerEvent(Owner);
    stateMachine->testStartStateMachine();

    object commandObj = clone_object("/lib/tests/support/conversations/commandObj.c");
    move_object(commandObj, Actor);

    // Reset the conversation back to default state
    command("issueCommand", Actor);
    command("talk", Actor);

    Actor->resetCatchList();
    command("talk", Actor);
    ExpectEq(3, sizeof(Actor->caughtMessages()));
    ExpectSubStringMatch("This is the default conversation", Actor->caughtMessages()[0]);

    command("1", Actor);

    Actor->resetCatchList();
    command("triggerSecond", Actor);
    command("talk", Actor);
    ExpectSubStringMatch("Piss off you gorbellied twit-goblin!", Actor->caughtMessage());

    Actor->resetCatchList();
    command("talk", Actor);
    ExpectSubStringMatch("Piss off you gorbellied twit-goblin!", Actor->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ConversationFromOtherObjectReturnsToDefaultOnFirstConversationObj()
{
    PrepActor(1);

    Owner->testAddConversation("/lib/tests/support/conversations/testConversation.c");
    Owner->testAddConversation("/lib/tests/support/conversations/secondConversation.c");
    object stateMachine = load_object("/lib/tests/support/core/testStateMachine.c");
    stateMachine->registerEvent(Owner);
    stateMachine->testStartStateMachine();

    object commandObj = clone_object("/lib/tests/support/conversations/commandObj.c");
    move_object(commandObj, Actor);

    // Reset the conversation back to default state
    command("issueCommand", Actor);
    command("talk", Actor);

    Actor->resetCatchList();
    command("talk", Actor);
    ExpectEq(3, sizeof(Actor->caughtMessages()));
    ExpectSubStringMatch("This is the default conversation", Actor->caughtMessages()[0]);

    command("1", Actor);

    Actor->resetCatchList();
    command("triggerThird", Actor);
    command("talk", Actor);
    ExpectSubStringMatch("You are serving the king", Actor->caughtMessage());

    Actor->resetCatchList();
    command("talk", Actor);
    ExpectEq(3, sizeof(Actor->caughtMessages()));
    ExpectSubStringMatch("This is the default conversation", Actor->caughtMessages()[0]);
}

/////////////////////////////////////////////////////////////////////////////
/*void ResponseTopicDisplayedAfterResponse()
{
    PrepActor(1);

    Owner->addConversation("/lib/tutorial/characters/berenar/startingConversation.c");
    command("talk", Actor);
    command("1", Actor);
    ExpectEq("This is another test response\n[0m", Actor->caughtMessages());
}
*/
