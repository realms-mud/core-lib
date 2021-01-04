//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";
#include "/lib/include/inventory.h"

object Actor;
object Owner;
object Room;
object Conversation;

/////////////////////////////////////////////////////////////////////////////
varargs object PrepActor(int useMock, string characterName)
{
    object actor;

    if (!characterName)
    {
        characterName = "gorthaur";
    }

    if (useMock)
    {
        actor = clone_object("/lib/tests/support/services/mockPlayer.c");
        actor->Name(characterName);
    }
    else
    {
        actor = clone_object("/lib/realizations/player.c");
        actor->restore(characterName);
    }
    move_object(actor, Room);

    return actor;
}

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    load_object("/lib/dictionaries/environmentDictionary.c");

    ignoreList += ({ "PrepActor" });
    setRestoreCaller(this_object());
    object database = clone_object("/lib/tests/modules/secure/fakeDatabase.c");
    database->PrepDatabase();

    object dataAccess = clone_object("/lib/modules/secure/dataAccess.c");
    dataAccess->savePlayerData(database->Gorthaur());

    mapping secondActor = database->Gorthaur();
    secondActor["name"] = "maeglin";
    dataAccess->savePlayerData(secondActor);

    destruct(dataAccess);
    destruct(database);
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    ToggleCallOutBypass();
    Room = clone_object("/lib/tests/support/environment/fakeEnvironment.c");

    Owner = clone_object("/lib/tests/support/services/mockNPC.c");
    Owner->Name("Gertrude");
    Owner->Gender("female");

    move_object(Owner, Room);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Owner);
    destruct(Actor);
    destruct(Room);
    ToggleCallOutBypass();
}

/////////////////////////////////////////////////////////////////////////////
void AlterOpinionOfUpdatesOpinionOfTarget()
{
    Actor = PrepActor();
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
    Actor = PrepActor(1);

    Owner->testAddConversation("/lib/tests/support/conversations/testConversation.c");
    Actor->characterState(Owner, "first conversation");
    ExpectTrue(command("talk gertrude", Actor));
    ExpectEq(2, sizeof(Actor->caughtMessages()));
    ExpectSubStringMatch("We start talking for the first time.", Actor->caughtMessages()[0]);
    ExpectSubStringMatch("OK...", Actor->caughtMessages()[1]);
}

/////////////////////////////////////////////////////////////////////////////
void TalkTwiceRepeatsCurrentTopic()
{
    Actor = PrepActor(1);

    Owner->testAddConversation("/lib/tests/support/conversations/testConversation.c");
    command("talk to gertrude", Actor);
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
    Actor = PrepActor(1);

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
    Actor = PrepActor(1);

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
    Actor = PrepActor(1);

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
    Actor = PrepActor(1);

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
    Actor = PrepActor(1);

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
    Actor = PrepActor(1);

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
    Actor = PrepActor(1);

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
    Actor = PrepActor(1);

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
    Actor = PrepActor(1);

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
    Actor = PrepActor(1);

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
    Actor = PrepActor(1);

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
    Actor = PrepActor(1);

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
    Actor = PrepActor(1);

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
    Actor = PrepActor(1);

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
void ConversationInterjectionsAreCorrect()
{
    Actor = PrepActor(1);
    object interloper = clone_object("/lib/tests/support/conversations/testNPC.c");
    move_object(interloper, Room);

    Owner->testAddConversation("/lib/tests/support/conversations/testInterjection.c");

    efun::set_this_player(Actor);
    Owner->onTriggerConversation(Actor, "talk to me");
    ExpectSubStringMatch("This is a conversation.*You bore me, dunderhead.*Response", 
        implode(Actor->caughtMessages(), "\n"));

    destruct(interloper);
}

/////////////////////////////////////////////////////////////////////////////
void DisablesResponseWhenStatePrerequisiteNotMet()
{
    Actor = PrepActor(1);

    Owner->testAddConversation("/lib/tests/support/conversations/testConversationShowDisabled.c");

    object stateMachine = load_object("/lib/tests/support/core/testStateMachine.c");
    stateMachine->testStartStateMachine();
    stateMachine->registerEvent(Actor);
    ExpectEq("meet the king", stateMachine->getCurrentState());
    stateMachine->receiveEvent(Owner, "meetTheKing", Actor);
    ExpectEq("met the king", stateMachine->getCurrentState());

    command("talk", Actor);
    ExpectEq("\x1b[0;31;1m[4]: \x1b[0m\x1b[0;33;1mState Prerequisite\n\x1b[0m", 
        Actor->caughtMessages()[4]);

    Actor->resetCatchList();
    command("4", Actor);
    ExpectSubStringMatch("block by state", Actor->caughtMessage());

    Actor->resetCatchList();
    stateMachine->receiveEvent(Owner, "serveTheKing", Actor);
    command("talk", Actor);
    ExpectEq("\x1b[0;31m[4]: \x1b[0m\x1b[0;31mState Prerequisite\n\x1b[0m",
        Actor->caughtMessages()[4]);

    Actor->resetCatchList();
    command("4", Actor);
    ExpectSubStringMatch("What?", Actor->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void UniqueCharacterInstancesHaveDistinctConversations()
{
    Actor = PrepActor(1);

    object actor2 = PrepActor(1, "maeglin");
    move_object(actor2, "/lib/tests/support/environment/startingRoom.c");

    object brendan = clone_object("/tutorial/characters/brendan/brendan.c");
    move_object(brendan, Room);

    object brendan2 = clone_object("/tutorial/characters/brendan/brendan.c");
    move_object(brendan2, "/lib/tests/support/environment/startingRoom.c");

    command("talk brendan", Actor);
    command("talk brendan", actor2);
    ExpectEq("0", Actor->stateFor(brendan), "initial brendan conversation");
    ExpectEq("0", actor2->stateFor(brendan2), "initial brendan2 conversation");
    command("1", Actor);
    ExpectEq("villain", Actor->stateFor(brendan), "brendan villain advanced");
    ExpectEq("0", actor2->stateFor(brendan2), "brendan2 villain not advanced");
    command("1", actor2);
    ExpectEq("villain", Actor->stateFor(brendan), "brendan villain not advanced");
    ExpectEq("villain", actor2->stateFor(brendan2), "brendan2 villain advanced");
    command("1", actor2);
    ExpectEq("villain", Actor->stateFor(brendan), "brendan still is in villain state");
    ExpectEq("you are a simpleton", actor2->stateFor(brendan2), "brendan2 is advanced to simpleton");
    command("1", Actor);
    ExpectEq("you are a simpleton", Actor->stateFor(brendan), "brendan is advanced to simpleton");
    ExpectEq("you are a simpleton", actor2->stateFor(brendan2), "brendan2 is not advanced past simpleton");

    destruct(actor2);
    destruct(brendan);
    destruct(brendan2);
}

/////////////////////////////////////////////////////////////////////////////
void ResponsesAreCorrectlyHighlighted()
{
    Actor = PrepActor(1);

    Owner->testAddConversation("/lib/tests/support/conversations/testDefaultConversation.c");

    command("talk", Actor);

    ExpectSubStringMatch("0;33;1mFirst", implode(Actor->caughtMessages(), ""));

    command("1", Actor);
    command("1", Actor);
    Actor->resetCatchList();

    command("talk", Actor);
    ExpectSubStringMatch("0;36mFirst", implode(Actor->caughtMessages(), ""));
}
