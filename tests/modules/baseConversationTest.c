//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";
#include "/lib/include/inventory.h"

object Actor;
object Owner;
object Conversation;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Conversation = clone_object("/lib/tests/support/conversations/fakeConversation.c");
    object room = load_object("/lib/tests/support/environment/fakeEnvironment.c");

    Actor = clone_object("/lib/tests/support/services/mockPlayer.c");
    Actor->Name("Bob");
    Actor->Gender(1);
    Actor->Race("human");
    move_object(Actor, room);

    Owner = clone_object("/lib/realizations/npc.c");
    Owner->Name("Gertrude");
    Owner->Gender(2);
    move_object(Owner, room);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Owner);
    destruct(Actor);
    destruct(Conversation);
}

/////////////////////////////////////////////////////////////////////////////
void AddTopicAddsDiscussionTopic()
{
    Conversation->testAddTopic("test", "This is a test message");
    ExpectTrue(Conversation->speakMessage("test", Actor, Owner));
    ExpectFalse(Conversation->isRepeatable("test"));
    ExpectSubStringMatch("This is a test message", Actor->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void AddRepeatableTopicAddsDiscussionTopic()
{
    Conversation->testAddRepeatableTopic("test", "This is a test message");
    ExpectTrue(Conversation->speakMessage("test", Actor, Owner));
    ExpectTrue(Conversation->isRepeatable("test"));
    ExpectSubStringMatch("This is a test message", Actor->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void AddTopicPrerequisiteAddsAndHonorsPrerequisite()
{
    Conversation->testAddTopic("test", "This is a test message");
    Conversation->testAddTopicPrerequisite("test", (["race": (["type":"race", "value" : ({ "elf", "high elf", "half elf" })])]));

    ExpectFalse(Conversation->speakMessage("test", Actor, Owner));

    Actor->Race("elf");
    ExpectTrue(Conversation->speakMessage("test", Actor, Owner));
    ExpectSubStringMatch("This is a test message", Actor->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanAddMultipleTopicPrerequisites()
{
    Conversation->testAddTopic("test", "This is a test message");
    Conversation->testAddTopicPrerequisite("test", (["race": (["type":"race", "value": ({ "elf", "high elf", "half elf" })])]));

    ExpectFalse(Conversation->speakMessage("test", Actor, Owner));

    Actor->Race("elf");
    ExpectTrue(Conversation->speakMessage("test", Actor, Owner));
    Conversation->testAddTopicPrerequisite("test", (["long sword": (["type":"skill", "value" : 10])]));
    ExpectFalse(Conversation->speakMessage("test", Actor, Owner));
    
    ExpectEq(([ "test":(["race":(["type":"race", "value" : ({ "elf", "high elf", "half elf" })]), "long sword":(["type":"skill", "value" : 10])])]),
        Conversation->getPrerequisites());

    Actor->Str(20);
    Actor->addSkillPoints(100);
    Actor->advanceSkill("long sword", 10);
    ExpectTrue(Conversation->speakMessage("test", Actor, Owner));
}

/////////////////////////////////////////////////////////////////////////////
void AddTopicEventAddsAndTriggersEvent()
{
    object subscriber = clone_object("/lib/tests/support/events/conversationSubscriber.c");
    Owner->registerEventHandler("conversationEventHappened");
    Owner->registerEvent(subscriber);

    Conversation->testAddTopic("test", "This is a test message");
    Conversation->testAddTopicEvent("test", "conversationEventHappened");

    ExpectEq(0, subscriber->TimesConversationEventHappenedReceived());
    ExpectTrue(Conversation->speakMessage("test", Actor, Owner));
    ExpectEq(1, subscriber->TimesConversationEventHappenedReceived());
}

/////////////////////////////////////////////////////////////////////////////
void AddTopicTriggerAddsTrigger()
{
    Conversation->testAddTopic("test", "This is a test message");
    Conversation->triggerConversation("conversationEventHappened", Actor, Owner);
    ExpectEq(0, Actor->caughtMessage());

    Conversation->testAddTopicTrigger("test", "conversationEventHappened");

    Conversation->triggerConversation("conversationEventHappened", Actor, Owner);
    ExpectEq("This is a test message\n[0m", Actor->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void AddResponseShowsAvailableResponsesWhenMessageSpoken()
{
    Conversation->testAddTopic("test", "This is a test message");
    Conversation->testAddResponse("test", "Test response", "This is a test response");
    ExpectTrue(Conversation->speakMessage("test", Actor, Owner));
    ExpectEq(2, sizeof(Actor->caughtMessages()));
    ExpectEq("This is a test message\n[0m", Actor->caughtMessages()[0]);
    ExpectEq("[0;31m[1][0m: [0;33mTest response\n[0m", Actor->caughtMessages()[1]);
}

/////////////////////////////////////////////////////////////////////////////
void AddMultipleResponsesShowsAvailableResponsesInSortedOrder()
{
    Conversation->testAddTopic("test", "This is a test message");
    Conversation->testAddResponse("test", "Test response", "This is a test response");
    Conversation->testAddResponse("test", "Another", "This is another test response");
    ExpectTrue(Conversation->speakMessage("test", Actor, Owner));
    ExpectEq(3, sizeof(Actor->caughtMessages()));
    ExpectEq("This is a test message\n[0m", Actor->caughtMessages()[0]);
    ExpectEq("[0;31m[1][0m: [0;33mAnother\n[0m", Actor->caughtMessages()[1]);
    ExpectEq("[0;31m[2][0m: [0;33mTest response\n[0m", Actor->caughtMessages()[2]);
}

/////////////////////////////////////////////////////////////////////////////
void AddResponsePrerequisiteAddsPrerequisiteToDisplayOfMessage()
{
    Conversation->testAddTopic("test", "This is a test message");
    Conversation->testAddResponse("test", "Test response", "This is a test response");
    Conversation->testAddResponse("test", "Another", "This is another test response");
    Conversation->testAddResponsePrerequisite("test", "Another", (["race":(["type":"race", "value" : ({ "elf", "high elf", "half elf" })])]));

    ExpectTrue(Conversation->speakMessage("test", Actor, Owner));
    ExpectEq(2, sizeof(Actor->caughtMessages()));
    ExpectEq("This is a test message\n[0m", Actor->caughtMessages()[0]);
    ExpectEq("[0;31m[1][0m: [0;33mTest response\n[0m", Actor->caughtMessages()[1]);
}

/////////////////////////////////////////////////////////////////////////////
void ResponsesAllDisplayedWhenPrerequisitesMet()
{
    Conversation->testAddTopic("test", "This is a test message");
    Conversation->testAddResponse("test", "Test response", "This is a test response");
    Conversation->testAddResponse("test", "Another", "This is another test response");
    Conversation->testAddResponsePrerequisite("test", "Another", (["race":(["type":"race", "value" : ({ "elf", "high elf", "half elf" })])]));

    ExpectTrue(Conversation->speakMessage("test", Actor, Owner));
    ExpectEq(2, sizeof(Actor->caughtMessages()));
    ExpectEq("This is a test message\n[0m", Actor->caughtMessages()[0]);
    ExpectEq("[0;31m[1][0m: [0;33mTest response\n[0m", Actor->caughtMessages()[1]);

    Actor->resetCatchList();
    Actor->Race("elf");
    ExpectTrue(Conversation->speakMessage("test", Actor, Owner));
    ExpectEq(3, sizeof(Actor->caughtMessages()));
    ExpectEq("This is a test message\n[0m", Actor->caughtMessages()[0]);
    ExpectEq("[0;31m[1][0m: [0;33mAnother\n[0m", Actor->caughtMessages()[1]);
    ExpectEq("[0;31m[2][0m: [0;33mTest response\n[0m", Actor->caughtMessages()[2]);
}

/////////////////////////////////////////////////////////////////////////////
void SpeakMessageDisplaysCorrectMessageWithAvailableResponses()
{
    destruct(Conversation);
    Conversation = clone_object("/lib/tests/support/conversations/testConversation.c");

    Conversation->speakMessage("start quest", Actor, Owner);
    ExpectSubStringMatch("Greetings, seekers. Welcome", Actor->caughtMessages()[0]);
    ExpectSubStringMatch("I am someone...", Actor->caughtMessages()[1]);
    ExpectSubStringMatch("My name is...", Actor->caughtMessages()[2]);
    ExpectSubStringMatch("None of your business", Actor->caughtMessages()[3]);
}

/////////////////////////////////////////////////////////////////////////////
void DisplayResponseReturnsNothingIfMessageNotSpokenFirst()
{
    destruct(Conversation);
    Conversation = clone_object("/lib/tests/support/conversations/testConversation.c");

    Conversation->displayResponse("1", Actor, Owner);
    ExpectFalse(Actor->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DisplayResponseReturnsCorrectMessage()
{
    destruct(Conversation);
    Conversation = clone_object("/lib/tests/support/conversations/testConversation.c");

    Conversation->speakMessage("start quest", Actor, Owner);
    Conversation->displayResponse("1", Actor, Owner);
    ExpectSubStringMatch("I am one who wishes to complete this", Actor->caughtMessage());

    Conversation->displayResponse("2", Actor, Owner);
    ExpectSubStringMatch("I am Bob and I am here to pass the trial", Actor->caughtMessage());

    Conversation->displayResponse("3", Actor, Owner);
    ExpectSubStringMatch("Who I am is not your concern, wraith", Actor->caughtMessage());
}