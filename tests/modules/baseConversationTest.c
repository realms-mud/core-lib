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
void Init()
{
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
    Conversation = load_object("/lib/tests/support/conversations/fakeConversation.c");
    object room = load_object("/lib/tests/support/environment/fakeEnvironment.c");

    Actor = clone_object("/lib/tests/support/services/mockPlayer.c");
    Actor->Name("Gorthaur");
    Actor->restore();
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
void CannotAddSameTopicTwice()
{
    Conversation->testAddTopic("test", "This is a test message");
    ExpectEq("*ERROR - baseConversation.c, addTopic: Topic 'test' already exists.\n",
        catch (Conversation->testAddTopic("test", "This is a test message")));
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
void CannotAddSameRepeatableTopicTwice()
{
    Conversation->testAddRepeatableTopic("test", "This is a test message");
    ExpectEq("*ERROR - baseConversation.c, addTopic: Topic 'test' already exists.\n",
        catch (Conversation->testAddRepeatableTopic("test", "This is a test message")));
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
void CannotAddTopicPrerequisiteIfTopicDoesNotExist()
{
    ExpectEq("*ERROR - baseConversation.c, addTopicPrerequisite: Could not add the prerequisite to 'test'. Make sure that the topic exists.\n",
        catch (Conversation->testAddTopicPrerequisite("test", (["race":(["type":"race", "value" : ({ "elf", "high elf", "half elf" })])]))));
}

/////////////////////////////////////////////////////////////////////////////
void CannotAddInvalidPrerequisiteToTopic()
{
    Conversation->testAddTopic("test", "This is a test message");
    ExpectEq("*ERROR - baseConversation.c, addTopicPrerequisite: The passed prerequisite to 'test' is invalid.\n",
        catch (Conversation->testAddTopicPrerequisite("test", (["blarg":(["type":"blah", "value" : ({ "elf", "high elf", "half elf" })])]))));
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
void CannotAddTopicEventIfTopicDoesNotExist()
{
    ExpectEq("*ERROR - baseConversation.c, addTopicEvent: Topic 'test' does not exist.\n",
        catch (Conversation->testAddTopicEvent("test", "conversationEventHappened")));
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
void CannotAddTopicTriggerIfTopicDoesNotExist()
{
    ExpectEq("*ERROR - baseConversation.c, addTopicTrigger: Topic 'test' does not exist.\n",
        catch (Conversation->testAddTopicTrigger("test", "conversationEventHappened")));
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
void CannotAddResponseIfTopicDoesNotExist()
{
    ExpectEq("*ERROR - baseConversation.c, addResponse: Topic 'test' does not exist.\n",
        catch (Conversation->testAddResponse("test", "Test response", "This is a test response")));
}

/////////////////////////////////////////////////////////////////////////////
void CannotAddResponseIfItAlreadyExists()
{
    Conversation->testAddTopic("test", "This is a test message");
    Conversation->testAddResponse("test", "Test response", "This is a test response");
    ExpectEq("*ERROR - baseConversation.c, addResponse: The response 'Test response' already exists.\n",
        catch (Conversation->testAddResponse("test", "Test response", "This is a test response")));
}

/////////////////////////////////////////////////////////////////////////////
void CannotRespondToMessageBeforeItHasBeenSpoken()
{
    Conversation->testAddTopic("test", "This is a test message");
    Conversation->testAddResponse("test", "Another", "This is another test response");

    Conversation->displayResponse("1", Actor, Owner);
    ExpectEq("", Actor->caughtMessages());
}

/////////////////////////////////////////////////////////////////////////////
void CanRespondToMessage()
{
    Conversation->testAddTopic("test", "This is a test message");
    Conversation->testAddResponse("test", "Another", "This is another test response");

    ExpectTrue(Conversation->speakMessage("test", Actor, Owner));
    Conversation->displayResponse("1", Actor, Owner);
    ExpectEq("This is another test response\n[0m", Actor->caughtMessage());
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
void CannotAddResponsePrerequisiteIfTopicOrResponseDoNotExist()
{
    ExpectEq("*ERROR - baseConversation.c, addResponsePrerequisite: Could not add the prerequiste. Check to make sure that the topic and response exist.\n",
        catch (Conversation->testAddResponsePrerequisite("test", "Another", (["race":(["type":"race", "value" : ({ "elf", "high elf", "half elf" })])]))));

    Conversation->testAddTopic("test", "This is a test message");
    ExpectEq("*ERROR - baseConversation.c, addResponsePrerequisite: Could not add the prerequiste. Check to make sure that the topic and response exist.\n",
        catch (Conversation->testAddResponsePrerequisite("test", "Another", (["race":(["type":"race", "value" : ({ "elf", "high elf", "half elf" })])]))));
}

/////////////////////////////////////////////////////////////////////////////
void CannotAddInvalidPrerequisiteToResponse()
{
    Conversation->testAddTopic("test", "This is a test message");
    Conversation->testAddResponse("test", "Another", "This is another test response");
    ExpectEq("*ERROR - baseConversation.c, addResponsePrerequisite: The passed prerequisite to 'Another' is invalid.\n",
        catch (Conversation->testAddResponsePrerequisite("test", "Another", (["blarg":(["type":"blah", "value" : ({ "elf", "high elf", "half elf" })])]))));
}

/////////////////////////////////////////////////////////////////////////////
void AddResponseEventAddsAndTriggersEvent()
{
    object subscriber = clone_object("/lib/tests/support/events/conversationSubscriber.c");
    Owner->registerEventHandler("conversationEventHappened");
    Owner->registerEvent(subscriber);

    Conversation->testAddTopic("test", "This is a test message");
    Conversation->testAddResponse("test", "Another", "This is another test response");
    Conversation->testAddResponseEvent("test", "Another", "conversationEventHappened");

    ExpectEq(0, subscriber->TimesConversationEventHappenedReceived());
    ExpectTrue(Conversation->speakMessage("test", Actor, Owner));
    Conversation->displayResponse("1", Actor, Owner);
    ExpectEq(1, subscriber->TimesConversationEventHappenedReceived());
}

/////////////////////////////////////////////////////////////////////////////
void CannotAddResponseEventIfResponseDoesNotExist()
{
    Conversation->testAddTopic("test", "This is a test message");
    ExpectEq("*ERROR - baseConversation.c, addResponseEvent: Could not add the event. Check to make sure that the topic and response exist.\n",
        catch (Conversation->testAddResponseEvent("test", "Another", "conversationEventHappened")));
}

/////////////////////////////////////////////////////////////////////////////
void CannotAddResponseEffectIfResponseDoesNotExist()
{
    Conversation->testAddTopic("test", "This is a test message");
    ExpectEq("*ERROR - baseConversation.c, addResponseEffect: Could not add the event. Check to make sure that the topic and response exist and that the effect is valid.\n",
        catch (Conversation->testAddResponseEffect("test", "Another", (["opinion": 5 ]))));
}

/////////////////////////////////////////////////////////////////////////////
void CannotAddResponseEffectIfItIsInvalid()
{
    Conversation->testAddTopic("test", "This is a test message");
    Conversation->testAddResponse("test", "Another", "This is another test response");
    ExpectEq("*ERROR - baseConversation.c, addResponseEffect: Could not add the event. Check to make sure that the topic and response exist and that the effect is valid.\n",
        catch (Conversation->testAddResponseEffect("test", "Another", (["blah":5]))));
}

/////////////////////////////////////////////////////////////////////////////
void AddResponseEffectAllowsAndAppliesOpinion()
{
    destruct(Actor);
    Actor = clone_object("/lib/realizations/player.c");
    Actor->restore("gorthaur");
    Conversation->testAddTopic("test", "This is a test message");
    Conversation->testAddResponse("test", "Another", "This is another test response");
    Conversation->testAddResponseEffect("test", "Another", (["opinion":5]));

    Actor->addTrait("/lib/tests/support/traits/testNoOpposingRootTrait.c");
    ExpectEq(10, Owner->opinionOf(Actor));
    ExpectTrue(Conversation->speakMessage("test", Actor, Owner));
    Conversation->displayResponse("1", Actor, Owner);
    ExpectEq(15, Owner->opinionOf(Actor));
}

/////////////////////////////////////////////////////////////////////////////
void AddResponseEffectAllowsAndAppliesAttack()
{
    Conversation->testAddTopic("test", "This is a test message");
    Conversation->testAddResponse("test", "Another", "This is another test response");
    Conversation->testAddResponseEffect("test", "Another", (["attack":1]));

    ExpectEq("Nothing at all, aren't you lucky?", Owner->getHostileList());
    ExpectTrue(Conversation->speakMessage("test", Actor, Owner));
    Conversation->displayResponse("1", Actor, Owner);
    ExpectEq("Gorthaur", Owner->getHostileList());
}

/////////////////////////////////////////////////////////////////////////////
void AddResponseEffectAllowsAndAppliesMove()
{
    Conversation->testAddTopic("test", "This is a test message");
    Conversation->testAddResponse("test", "Another", "This is another test response");
    Conversation->testAddResponseEffect("test", "Another", (["move":"/lib/tests/support/environment/toLocation.c"]));

    object room = load_object("/lib/tests/support/environment/fakeEnvironment.c");
    ExpectTrue(present(Owner, room));
    ExpectTrue(Conversation->speakMessage("test", Actor, Owner));
    Conversation->displayResponse("1", Actor, Owner);
    ExpectFalse(present(Owner, room));
    ExpectTrue(present(Owner, load_object("/lib/tests/support/environment/toLocation.c")));
}

/////////////////////////////////////////////////////////////////////////////
void AddResponseEffectAllowsAndAppliesGiveWithoutItemPresent()
{
    Conversation->testAddTopic("test", "This is a test message");
    Conversation->testAddResponse("test", "Another", "This is another test response");
    Conversation->testAddResponseEffect("test", "Another", (["give":"/lib/tests/support/items/testSword.c"]));

    ExpectFalse(present_clone("/lib/tests/support/items/testSword.c", Actor));
    ExpectTrue(Conversation->speakMessage("test", Actor, Owner));
    Conversation->displayResponse("1", Actor, Owner);
    ExpectTrue(present_clone("/lib/tests/support/items/testSword.c", Actor));
}

/////////////////////////////////////////////////////////////////////////////
void AddResponseEffectAllowsAndAppliesGiveWithItemPresent()
{
    Conversation->testAddTopic("test", "This is a test message");
    Conversation->testAddResponse("test", "Another", "This is another test response");
    Conversation->testAddResponseEffect("test", "Another", (["give":"/lib/tests/support/items/testSword.c"]));

    object weapon = clone_object("/lib/tests/support/items/testSword.c");
    move_object(weapon, Owner);
    ExpectTrue(weapon->equip("Sword of Weasels"), "The sword could be equipped");
    ExpectTrue(Owner->isEquipped(weapon), "The sword has been equipped");

    ExpectTrue(present_clone(weapon, Owner), "Owner has the sword");
    ExpectTrue(Conversation->speakMessage("test", Actor, Owner));
    Conversation->displayResponse("1", Actor, Owner);
    ExpectFalse(Owner->isEquipped(weapon), "The sword is no longer equipped");
    ExpectFalse(present_clone(weapon, Owner), "The sword is not in Owner's inventory");
    ExpectTrue(present_clone(weapon, Actor), "Actor has the sword");
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
    ExpectSubStringMatch("I am Gorthaur and I am here to pass the trial", Actor->caughtMessage());

    Conversation->displayResponse("3", Actor, Owner);
    ExpectSubStringMatch("Who I am is not your concern, wraith", Actor->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void MessagesAreCorrectlyParsed()
{
    Conversation->testAddTopic("test", "@D@##TargetName## ##Infinitive::glare## at ##InitiatorName## and ##Infinitive::snarl##, @S@`##ActorName##! That was really rude, you jerk!' @A@Annoyed@E@");
    ExpectTrue(Conversation->speakMessage("test", Actor, Owner));
    ExpectEq("[0;36mGertrude glares at you and snarls, [0;33m`Gorthaur! That was really\nrude, you jerk!' [0;34;1m[Annoyed][0m\n[0m", Actor->caughtMessage());
}
