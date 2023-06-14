//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
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
    database.PrepDatabase();

    object dataAccess = clone_object("/lib/modules/secure/dataAccess.c");
    dataAccess.savePlayerData(database.Gorthaur());

    destruct(dataAccess);
    destruct(database);
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Conversation = load_object("/lib/tests/support/conversations/fakeConversation.c");
    object room = load_object("/lib/tests/support/environment/fakeEnvironment.c");

    Actor = clone_object("/lib/tests/support/services/mockPlayer.c");
    Actor.Name("Gorthaur");
    Actor.restore();
    Actor.hitPoints(Actor.maxHitPoints());
    move_object(Actor, room);

    Owner = clone_object("/lib/tests/support/services/mockNPC.c");
    Owner.Name("Gertrude");
    Owner.Gender("female");
    Owner.Con(20);
    Owner.hitPoints(Owner.maxHitPoints());
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
    Conversation.testAddTopic("test", "This is a test message");
    ExpectTrue(Conversation.speakMessage("test", Actor, Owner));
    ExpectFalse(Conversation.isRepeatable("test"));
    ExpectSubStringMatch("This is a test message", Actor.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CannotAddSameTopicTwice()
{
    Conversation.testAddTopic("test", "This is a test message");
    ExpectEq("*ERROR - baseConversation.c, addTopic: Topic 'test' already exists.\n",
        catch (Conversation.testAddTopic("test", "This is a test message"); nolog));
}

/////////////////////////////////////////////////////////////////////////////
void AddRepeatableTopicAddsDiscussionTopic()
{
    Conversation.testAddRepeatableTopic("test", "This is a test message");
    ExpectTrue(Conversation.speakMessage("test", Actor, Owner));
    ExpectTrue(Conversation.isRepeatable("test"));
    ExpectSubStringMatch("This is a test message", Actor.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CannotAddSameRepeatableTopicTwice()
{
    Conversation.testAddRepeatableTopic("test", "This is a test message");
    ExpectEq("*ERROR - baseConversation.c, addTopic: Topic 'test' already exists.\n",
        catch (Conversation.testAddRepeatableTopic("test", "This is a test message"); nolog));
}

/////////////////////////////////////////////////////////////////////////////
void AddTopicPrerequisiteAddsAndHonorsPrerequisite()
{
    Conversation.testAddTopic("test", "This is a test message");
    Conversation.testAddTopicPrerequisite("test", (["race": (["type":"race", "value" : ({ "elf", "high elf", "half elf" })])]));

    ExpectFalse(Conversation.speakMessage("test", Actor, Owner));

    Actor.Race("elf");
    ExpectTrue(Conversation.speakMessage("test", Actor, Owner));
    ExpectSubStringMatch("This is a test message", Actor.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void AddTopicPrerequisiteHandlesSpokenTopicPrerequisite()
{
    Owner.testAddConversation("/lib/tests/support/conversations/spokenTopicTestConversation.c");
    Conversation = load_object("/lib/tests/support/conversations/spokenTopicTestConversation.c");
    ExpectFalse(Conversation.speakMessage("test 2", Actor, Owner), "test 2 conversation should fail");

    ExpectTrue(Conversation.speakMessage("test", Actor, Owner), "test conversation should pass");
    ExpectTrue(Conversation.speakMessage("test 2", Actor, Owner), "test 2 should pass");
    ExpectSubStringMatch("This is another test message", Actor.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CannotAddTopicPrerequisiteIfTopicDoesNotExist()
{
    ExpectEq("*ERROR - baseConversation.c, addTopicPrerequisite: Could not add the prerequisite to 'test'. Make sure that the topic exists.\n",
        catch (Conversation.testAddTopicPrerequisite("test", 
            (["race":(["type":"race", "value" : ({ "elf", "high elf", "half elf" })])])); nolog));
}

/////////////////////////////////////////////////////////////////////////////
void CannotAddInvalidPrerequisiteToTopic()
{
    Conversation.testAddTopic("test", "This is a test message");
    ExpectEq("*ERROR - baseConversation.c, addTopicPrerequisite: The passed prerequisite to 'test' is invalid.\n",
        catch (Conversation.testAddTopicPrerequisite("test", 
            (["blarg":(["type":"blah", "value" : ({ "elf", "high elf", "half elf" })])])); nolog));
}

/////////////////////////////////////////////////////////////////////////////
void CanAddMultipleTopicPrerequisites()
{
    Conversation.testAddTopic("test", "This is a test message");
    Conversation.testAddTopicPrerequisite("test", (["race": (["type":"race", "value": ({ "elf", "high elf", "half elf" })])]));

    ExpectFalse(Conversation.speakMessage("test", Actor, Owner));

    Actor.Race("elf");
    ExpectTrue(Conversation.speakMessage("test", Actor, Owner));
    Conversation.testAddTopicPrerequisite("test", (["long sword": (["type":"skill", "value" : 10])]));
    ExpectFalse(Conversation.speakMessage("test", Actor, Owner));
    
    ExpectEq(([ "test":(["race":(["type":"race", "value" : ({ "elf", "high elf", "half elf" })]), "long sword":(["type":"skill", "value" : 10])])]),
        Conversation.getPrerequisites());

    Actor.Str(20);
    Actor.addSkillPoints(100);
    Actor.advanceSkill("long sword", 10);
    ExpectTrue(Conversation.speakMessage("test", Actor, Owner));
}

/////////////////////////////////////////////////////////////////////////////
void AddTopicEventAddsAndTriggersEvent()
{
    object subscriber = clone_object("/lib/tests/support/events/conversationSubscriber.c");
    Owner.registerEventHandler("conversationEventHappened");
    Owner.registerEvent(subscriber);

    Conversation.testAddTopic("test", "This is a test message");
    Conversation.testAddTopicEvent("test", "conversationEventHappened");

    ExpectEq(0, subscriber.TimesConversationEventHappenedReceived());
    ExpectTrue(Conversation.speakMessage("test", Actor, Owner));
    ExpectEq(1, subscriber.TimesConversationEventHappenedReceived());
}

/////////////////////////////////////////////////////////////////////////////
void CannotAddTopicEventIfTopicDoesNotExist()
{
    ExpectEq("*ERROR - baseConversation.c, addTopicEvent: Topic 'test' does not exist.\n",
        catch (Conversation.testAddTopicEvent("test", "conversationEventHappened"); nolog));
}

/////////////////////////////////////////////////////////////////////////////
void AddTopicTriggerAddsTrigger()
{
    Conversation.testAddTopic("test", "This is a test message");
    Conversation.triggerConversation("conversationEventHappened", Actor, Owner);
    ExpectEq(0, Actor.caughtMessage());

    Conversation.testAddTopicTrigger("test", "conversationEventHappened");

    Conversation.triggerConversation("conversationEventHappened", Actor, Owner);
    ExpectEq("\nThis is a test message\n", Actor.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CannotAddTopicTriggerIfTopicDoesNotExist()
{
    ExpectEq("*ERROR - baseConversation.c, addTopicTrigger: Topic 'test' does not exist.\n",
        catch (Conversation.testAddTopicTrigger("test", "conversationEventHappened"); nolog));
}

/////////////////////////////////////////////////////////////////////////////
void AddResponseShowsAvailableResponsesWhenMessageSpoken()
{
    Conversation.testAddTopic("test", "This is a test message");
    Conversation.testAddResponse("test", "Test response", "This is a test response");
    ExpectTrue(Conversation.speakMessage("test", Actor, Owner));
    ExpectEq(2, sizeof(Actor.caughtMessages()));
    ExpectEq("\nThis is a test message\n", Actor.caughtMessages()[0]);
    ExpectEq("\x1b[0;31;1m[1]: \x1b[0m\x1b[0;33;1mTest response\n\x1b[0m", Actor.caughtMessages()[1]);
}

/////////////////////////////////////////////////////////////////////////////
void AddMultipleResponsesShowsAvailableResponsesInSortedOrder()
{
    Conversation.testAddTopic("test", "This is a test message");
    Conversation.testAddResponse("test", "Test response", "This is a test response");
    Conversation.testAddResponse("test", "Another", "This is another test response");
    ExpectTrue(Conversation.speakMessage("test", Actor, Owner));
    ExpectEq(3, sizeof(Actor.caughtMessages()));
    ExpectEq("\nThis is a test message\n", Actor.caughtMessages()[0]);
    ExpectEq("\x1b[0;31;1m[1]: \x1b[0m\x1b[0;33;1mAnother\n\x1b[0m", Actor.caughtMessages()[1]);
    ExpectEq("\x1b[0;31;1m[2]: \x1b[0m\x1b[0;33;1mTest response\n\x1b[0m", Actor.caughtMessages()[2]);
}

/////////////////////////////////////////////////////////////////////////////
void CannotAddResponseIfTopicDoesNotExist()
{
    ExpectEq("*ERROR - baseConversation.c, addResponse: Topic 'test' does not exist.\n",
        catch (Conversation.testAddResponse("test", "Test response", "This is a test response"); nolog));
}

/////////////////////////////////////////////////////////////////////////////
void AddTopicInterjectionAddsInterjection()
{
    efun::set_this_player(Actor);

    Conversation.testAddTopic("test", "This is a test message");
    Conversation.testAddTopicInterjection("test",
        "/lib/tests/support/conversations/testNPC.c",
        "interjected comment");
    Conversation.testAddResponse("test", "Test response", "This is a test response");

    object interloper = clone_object("/lib/tests/support/conversations/testNPC.c");
    move_object(interloper, environment(Owner));

    ExpectTrue(Conversation.speakMessage("test", Actor, Owner));
    ExpectEq(3, sizeof(Actor.caughtMessages()));
    ExpectSubStringMatch("This is a test message", Actor.caughtMessages()[0]);
    ExpectSubStringMatch("You bore me, dunderhead", Actor.caughtMessages()[1]);
    ExpectSubStringMatch("Test response", Actor.caughtMessages()[2]);
    destruct(interloper);
}

/////////////////////////////////////////////////////////////////////////////
void AddTopicInterjectionDoesNotInterjectiWhenInterloperNotPresent()
{
    efun::set_this_player(Actor);

    Conversation.testAddTopic("test", "This is a test message");
    Conversation.testAddTopicInterjection("test",
        "/lib/tests/support/conversations/testNPC.c",
        "interjected comment");
    Conversation.testAddResponse("test", "Test response", "This is a test response");

    ExpectTrue(Conversation.speakMessage("test", Actor, Owner));
    ExpectEq(2, sizeof(Actor.caughtMessages()));
    ExpectSubStringMatch("This is a test message", Actor.caughtMessages()[0]);
    ExpectSubStringMatch("Test response", Actor.caughtMessages()[1]);
}

/////////////////////////////////////////////////////////////////////////////
void CannotAddInterjectionIfTopicDoesNotExist()
{
    ExpectEq("*ERROR - baseConversation.c, addTopicInterjection: Topic 'test' does not exist.\n",
        catch (Conversation.testAddTopicInterjection("test", 
            "/lib/tests/support/conversations/testNPC.c", 
            "missing response"); nolog));
}

/////////////////////////////////////////////////////////////////////////////
void CannotAddInterjectionIfActorDoesNotExist()
{
    Conversation.testAddTopic("test", "This is a test message");

    ExpectEq("*ERROR - baseConversation.c, addTopicInterjection: Actor '/lib/tests/support/conversations/badActor.c' does not exist.\n",
        catch (Conversation.testAddTopicInterjection("test",
            "/lib/tests/support/conversations/badActor.c",
            "missing response"); nolog));
}

/////////////////////////////////////////////////////////////////////////////
void CannotAddInterjectionIfActorDoesButTopicDoesNotExist()
{
    Conversation.testAddTopic("test", "This is a test message");

    ExpectEq("*ERROR - baseConversation.c, addTopicInterjection: Topic 'missing response' does not exist on actor.\n",
        catch (Conversation.testAddTopicInterjection("test",
            "/lib/tests/support/conversations/testNPC.c",
            "missing response"); nolog));
}

/////////////////////////////////////////////////////////////////////////////
void CannotAddResponseIfItAlreadyExists()
{
    Conversation.testAddTopic("test", "This is a test message");
    Conversation.testAddResponse("test", "Test response", "This is a test response");
    ExpectEq("*ERROR - baseConversation.c, addResponse: The response 'Test response' already exists.\n",
        catch (Conversation.testAddResponse("test", "Test response", "This is a test response"); nolog));
}

/////////////////////////////////////////////////////////////////////////////
void CannotRespondToMessageBeforeItHasBeenSpoken()
{
    Conversation.testAddTopic("test", "This is a test message");
    Conversation.testAddResponse("test", "Another", "This is another test response");

    Conversation.displayResponse("1", Actor, Owner);
    ExpectEq("", Actor.caughtMessages());
}

/////////////////////////////////////////////////////////////////////////////
void CanRespondToMessage()
{
    Conversation.testAddTopic("test", "This is a test message");
    Conversation.testAddResponse("test", "Another", "This is another test response");

    ExpectTrue(Conversation.speakMessage("test", Actor, Owner));
    Conversation.displayResponse("1", Actor, Owner);
    ExpectEq("\nThis is another test response\n\n", Actor.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void AddResponsePrerequisiteAddsPrerequisiteToDisplayOfMessage()
{
    Conversation.testAddTopic("test", "This is a test message");
    Conversation.testAddResponse("test", "Test response", "This is a test response");
    Conversation.testAddResponse("test", "Another", "This is another test response");
    Conversation.testAddResponsePrerequisite("test", "Another", (["race":(["type":"race", "value" : ({ "elf", "high elf", "half elf" })])]));

    ExpectTrue(Conversation.speakMessage("test", Actor, Owner));
    ExpectEq(2, sizeof(Actor.caughtMessages()));
    ExpectEq("\nThis is a test message\n", Actor.caughtMessages()[0]);
    ExpectEq("\x1b[0;31;1m[1]: \x1b[0m\x1b[0;33;1mTest response\n\x1b[0m", Actor.caughtMessages()[1]);
}

/////////////////////////////////////////////////////////////////////////////
void ResponsesAllDisplayedWhenPrerequisitesMet()
{
    Conversation.testAddTopic("test", "This is a test message");
    Conversation.testAddResponse("test", "Test response", "This is a test response");
    Conversation.testAddResponse("test", "Another", "This is another test response");
    Conversation.testAddResponsePrerequisite("test", "Another", (["race":(["type":"race", "value" : ({ "elf", "high elf", "half elf" })])]));

    ExpectTrue(Conversation.speakMessage("test", Actor, Owner));
    ExpectEq(2, sizeof(Actor.caughtMessages()));
    ExpectEq("\nThis is a test message\n", Actor.caughtMessages()[0]);
    ExpectEq("\x1b[0;31;1m[1]: \x1b[0m\x1b[0;33;1mTest response\n\x1b[0m", Actor.caughtMessages()[1]);

    Actor.resetCatchList();
    Actor.Race("elf");
    ExpectTrue(Conversation.speakMessage("test", Actor, Owner));
    ExpectEq(3, sizeof(Actor.caughtMessages()));
    ExpectEq("\nThis is a test message\n", Actor.caughtMessages()[0]);
    ExpectEq("\x1b[0;31;1m[1]: \x1b[0m\x1b[0;33;1mAnother\n\x1b[0m", Actor.caughtMessages()[1]);
    ExpectEq("\x1b[0;31;1m[2]: \x1b[0m\x1b[0;33;1mTest response\n\x1b[0m", Actor.caughtMessages()[2]);
}

/////////////////////////////////////////////////////////////////////////////
void CannotAddResponsePrerequisiteIfTopicOrResponseDoNotExist()
{
    ExpectEq("*ERROR - baseConversation.c, addResponsePrerequisite: Could not add the prerequiste. Check to make sure that the topic and response exist.\n",
        catch (Conversation.testAddResponsePrerequisite("test", "Another", 
            (["race":(["type":"race", "value" : ({ "elf", "high elf", "half elf" })])])); nolog));

    Conversation.testAddTopic("test", "This is a test message");
    ExpectEq("*ERROR - baseConversation.c, addResponsePrerequisite: Could not add the prerequiste. Check to make sure that the topic and response exist.\n",
        catch (Conversation.testAddResponsePrerequisite("test", "Another", 
            (["race":(["type":"race", "value" : ({ "elf", "high elf", "half elf" })])])); nolog));
}

/////////////////////////////////////////////////////////////////////////////
void CannotAddInvalidPrerequisiteToResponse()
{
    Conversation.testAddTopic("test", "This is a test message");
    Conversation.testAddResponse("test", "Another", "This is another test response");
    ExpectEq("*ERROR - baseConversation.c, addResponsePrerequisite: The passed prerequisite to 'Another' is invalid.\n",
        catch (Conversation.testAddResponsePrerequisite("test", "Another", 
            (["blarg":(["type":"blah", "value" : ({ "elf", "high elf", "half elf" })])])); nolog));
}

/////////////////////////////////////////////////////////////////////////////
void AddResponseEventAddsAndTriggersEvent()
{
    object subscriber = clone_object("/lib/tests/support/events/conversationSubscriber.c");
    Owner.registerEventHandler("conversationEventHappened");
    Owner.registerEvent(subscriber);

    Conversation.testAddTopic("test", "This is a test message");
    Conversation.testAddResponse("test", "Another", "This is another test response");
    Conversation.testAddResponseEvent("test", "Another", "conversationEventHappened");

    ExpectEq(0, subscriber.TimesConversationEventHappenedReceived());
    ExpectTrue(Conversation.speakMessage("test", Actor, Owner));
    Conversation.displayResponse("1", Actor, Owner);
    ExpectEq(1, subscriber.TimesConversationEventHappenedReceived());
}

/////////////////////////////////////////////////////////////////////////////
void CannotAddResponseEventIfResponseDoesNotExist()
{
    Conversation.testAddTopic("test", "This is a test message");
    ExpectEq("*ERROR - baseConversation.c, addResponseEvent: Could not add the event. Check to make sure that the topic and response exist.\n",
        catch (Conversation.testAddResponseEvent("test", "Another", "conversationEventHappened"); nolog));
}

/////////////////////////////////////////////////////////////////////////////
void CannotAddResponseEffectIfResponseDoesNotExist()
{
    Conversation.testAddTopic("test", "This is a test message");
    ExpectEq("*ERROR - baseConversation.c, addResponseEffect: Could not add the event. Check to make sure that the topic and response exist and that the effect is valid.\n",
        catch (Conversation.testAddResponseEffect("test", "Another", (["opinion": 5 ])); nolog));
}

/////////////////////////////////////////////////////////////////////////////
void CannotAddResponseEffectIfItIsInvalid()
{
    Conversation.testAddTopic("test", "This is a test message");
    Conversation.testAddResponse("test", "Another", "This is another test response");
    ExpectEq("*ERROR - baseConversation.c, addResponseEffect: Could not add the event. Check to make sure that the topic and response exist and that the effect is valid.\n",
        catch (Conversation.testAddResponseEffect("test", "Another", (["blah":5])); nolog));
}

/////////////////////////////////////////////////////////////////////////////
void AddResponseEffectAllowsAndAppliesOpinion()
{
    destruct(Actor);
    Actor = clone_object("/lib/realizations/player.c");
    Actor.restore("gorthaur");
    Conversation.testAddTopic("test", "This is a test message");
    Conversation.testAddResponse("test", "Another", "This is another test response");
    Conversation.testAddResponseEffect("test", "Another", (["opinion":5]));

    Actor.addTrait("/lib/tests/support/traits/testNoOpposingRootTrait.c");
    ExpectEq(10, Owner.opinionOf(Actor));
    ExpectTrue(Conversation.speakMessage("test", Actor, Owner));
    Conversation.displayResponse("1", Actor, Owner);
    ExpectEq(15, Owner.opinionOf(Actor));
}

/////////////////////////////////////////////////////////////////////////////
void AddResponseEffectAllowsAndAppliesAttack()
{
    Conversation.testAddTopic("test", "This is a test message");
    Conversation.testAddResponse("test", "Another", "This is another test response");
    Conversation.testAddResponseEffect("test", "Another", (["attack":1]));

    ExpectEq("Nothing at all, aren't you lucky?", Owner.getHostileList());
    ExpectTrue(Conversation.speakMessage("test", Actor, Owner));
    Conversation.displayResponse("1", Actor, Owner);
    ExpectEq("Gorthaur", Owner.getHostileList());
}

/////////////////////////////////////////////////////////////////////////////
void AddResponseEffectAllowsAndAppliesMove()
{
    Conversation.testAddTopic("test", "This is a test message");
    Conversation.testAddResponse("test", "Another", "This is another test response");
    Conversation.testAddResponseEffect("test", "Another", (["move":"/lib/tests/support/environment/toLocation.c"]));

    object room = load_object("/lib/tests/support/environment/fakeEnvironment.c");
    ExpectTrue(present(Owner, room));
    ExpectTrue(Conversation.speakMessage("test", Actor, Owner));
    Conversation.displayResponse("1", Actor, Owner);
    ExpectFalse(present(Owner, room));
    ExpectTrue(present(Owner, load_object("/lib/tests/support/environment/toLocation.c")));
}

/////////////////////////////////////////////////////////////////////////////
void AddResponseEffectAllowsAndAppliesGiveWithoutItemPresent()
{
    Conversation.testAddTopic("test", "This is a test message");
    Conversation.testAddResponse("test", "Another", "This is another test response");
    Conversation.testAddResponseEffect("test", "Another", (["give":"/lib/tests/support/items/testSword.c"]));

    ExpectFalse(present_clone("/lib/tests/support/items/testSword.c", Actor));
    ExpectTrue(Conversation.speakMessage("test", Actor, Owner));
    Conversation.displayResponse("1", Actor, Owner);
    ExpectTrue(present_clone("/lib/tests/support/items/testSword.c", Actor));
}

/////////////////////////////////////////////////////////////////////////////
void AddResponseEffectAllowsAndAppliesGiveWithItemPresent()
{
    Conversation.testAddTopic("test", "This is a test message");
    Conversation.testAddResponse("test", "Another", "This is another test response");
    Conversation.testAddResponseEffect("test", "Another", (["give":"/lib/tests/support/items/testSword.c"]));

    object weapon = clone_object("/lib/tests/support/items/testSword.c");
    move_object(weapon, Owner);
    ExpectTrue(weapon.equip("Sword of Weasels"), "The sword could be equipped");
    ExpectTrue(Owner.isEquipped(weapon), "The sword has been equipped");

    ExpectTrue(present_clone(weapon, Owner), "Owner has the sword");
    ExpectTrue(Conversation.speakMessage("test", Actor, Owner));
    Conversation.displayResponse("1", Actor, Owner);
    ExpectFalse(Owner.isEquipped(weapon), "The sword is no longer equipped");
    ExpectFalse(present_clone(weapon, Owner), "The sword is not in Owner's inventory");
    ExpectTrue(present_clone(weapon, Actor), "Actor has the sword");
}

/////////////////////////////////////////////////////////////////////////////
void SpeakMessageDisplaysCorrectMessageWithAvailableResponses()
{
    destruct(Conversation);
    Conversation = clone_object("/lib/tests/support/conversations/testConversation.c");

    Conversation.speakMessage("start quest", Actor, Owner);
    ExpectSubStringMatch("Greetings, seekers. Welcome", Actor.caughtMessages()[0]);
    ExpectSubStringMatch("I am someone...", Actor.caughtMessages()[1]);
    ExpectSubStringMatch("My name is...", Actor.caughtMessages()[2]);
    ExpectSubStringMatch("None of your business", Actor.caughtMessages()[3]);
}

/////////////////////////////////////////////////////////////////////////////
void DisplayResponseReturnsNothingIfMessageNotSpokenFirst()
{
    destruct(Conversation);
    Conversation = clone_object("/lib/tests/support/conversations/testConversation.c");

    Conversation.displayResponse("1", Actor, Owner);
    ExpectFalse(Actor.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DisplayResponseReturnsCorrectMessage()
{
    destruct(Conversation);
    Conversation = clone_object("/lib/tests/support/conversations/testConversation.c");

    Conversation.speakMessage("start quest", Actor, Owner);
    Conversation.displayResponse("1", Actor, Owner);
    ExpectSubStringMatch("I am one who wishes to complete this", Actor.caughtMessage());

    Conversation.speakMessage("start quest", Actor, Owner);
    Conversation.displayResponse("2", Actor, Owner);
    ExpectSubStringMatch("I am Gorthaur and I am here to pass the trial", Actor.caughtMessage());

    Conversation.speakMessage("start quest", Actor, Owner);
    Conversation.displayResponse("3", Actor, Owner);
    ExpectSubStringMatch("Who I am is not your concern, wraith", Actor.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void MessagesAreCorrectlyParsed()
{
    Conversation.testAddTopic("test", "@D@##TargetName## ##Infinitive::glare## "
        "at ##InitiatorName## and ##Infinitive::snarl##, @S@`##ActorName##! "
        "That was really rude, you jerk!' @D@You ##ResponseInfinitive::laugh##. "
        "@A@Annoyed@E@");

    ExpectTrue(Conversation.speakMessage("test", Actor, Owner));
    ExpectEq("\n\x1b[0;36mGertrude glares at you and snarls, \x1b[0m\x1b[0;33m"
        "`Gorthaur! That was really rude, you\njerk!' \x1b[0m\x1b[0;36mYou "
        "laugh. \x1b[0m\x1b[0;34;1m[Annoyed]\x1b[0m\n", 
        Actor.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void MessagesAreCorrectlyDisplayedWithNoneColorConfiguration()
{
    Actor.colorConfiguration("none");
    Conversation.testAddTopic("test", "@D@##TargetName## ##Infinitive::glare## "
        "at ##InitiatorName## and ##Infinitive::snarl##, @S@`##ActorName##! "
        "That was really rude, you jerk!' @D@You ##ResponseInfinitive::laugh##. "
        "@A@Annoyed@E@");

    ExpectTrue(Conversation.speakMessage("test", Actor, Owner));
    ExpectEq("\nGertrude glares at you and snarls, `Gorthaur! That was really "
        "rude, you\njerk!' You laugh. [Annoyed]\n", Actor.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void MessagesAreCorrectlyDisplayedWithThreeBitColorConfiguration()
{
    Actor.colorConfiguration("3-bit");
    Conversation.testAddTopic("test", "@D@##TargetName## ##Infinitive::glare## "
        "at ##InitiatorName## and ##Infinitive::snarl##, @S@`##ActorName##! "
        "That was really rude, you jerk!' @D@You ##ResponseInfinitive::laugh##. "
        "@A@Annoyed@E@");

    ExpectTrue(Conversation.speakMessage("test", Actor, Owner));
    ExpectEq("\n\x1b[0;36mGertrude glares at you and snarls, \x1b[0m\x1b[0;33m"
        "`Gorthaur! That was really rude, you\njerk!' \x1b[0m\x1b[0;36mYou "
        "laugh. \x1b[0m\x1b[0;34;1m[Annoyed]\x1b[0m\n",
        Actor.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void MessagesAreCorrectlyDisplayedWithEightBitColorConfiguration()
{
    Actor.colorConfiguration("8-bit");
    Conversation.testAddTopic("test", "@D@##TargetName## ##Infinitive::glare## "
        "at ##InitiatorName## and ##Infinitive::snarl##, @S@`##ActorName##! "
        "That was really rude, you jerk!' @D@You ##ResponseInfinitive::laugh##. "
        "@A@Annoyed@E@");

    ExpectTrue(Conversation.speakMessage("test", Actor, Owner));
    ExpectEq("\n\x1b[0;38;5;80mGertrude glares at you and snarls, \x1b[0m\x1b[0;38;5;190m"
        "`Gorthaur! That was really rude, you\njerk!' \x1b[0m\x1b[0;38;5;80mYou "
        "laugh. \x1b[0m\x1b[0;38;5;20;1m[Annoyed]\x1b[0m\n",
        Actor.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void MessagesAreCorrectlyDisplayedWithTwentyFourBitColorConfiguration()
{
    Actor.colorConfiguration("24-bit");
    Conversation.testAddTopic("test", "@D@##TargetName## ##Infinitive::glare## "
        "at ##InitiatorName## and ##Infinitive::snarl##, @S@`##ActorName##! "
        "That was really rude, you jerk!' @D@You ##ResponseInfinitive::laugh##. "
        "@A@Annoyed@E@");

    ExpectTrue(Conversation.speakMessage("test", Actor, Owner));
    ExpectEq("\n\x1b[0;38;2;180;180;190mGertrude glares at you and snarls, "
        "\x1b[0m\x1b[0;38;2;200;200;0m`Gorthaur! That was really rude, "
        "you\njerk!' \x1b[0m\x1b[0;38;2;180;180;190mYou "
        "laugh. \x1b[0m\x1b[0;38;2;60;20;190;1m[Annoyed]\x1b[0m\n",
        Actor.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanAddConditionalTopicAddendum()
{
    Conversation.testAddTopic("test", "@D@##TargetName## ##Infinitive::glare## "
        "at ##InitiatorName## and ##Infinitive::snarl##, @S@`##ActorName##! "
        "That was really rude, you jerk!' @D@You ##ResponseInfinitive::laugh##. "
        "@A@Annoyed@E@");

    Conversation.testAddConditionalTopicAddendum("test", "fredIsAJerkToo",
        (["presence":(["type":"presence", "value" : ({ "fred" })])]),
        " @S@`And you, Fred. Bite me!'");

    Conversation.testAddConditionalTopicAddendum("test", "lameGortyCheck",
        (["presence":(["type":"presence", "value" : ({ "gorthaur" })])]),
        " @D@##TargetName## ##Infinitive::knee## ##ActorName## in the groin.");

    move_object(Actor, this_object());
    move_object(Owner, this_object());

    ExpectTrue(Conversation.speakMessage("test", Actor, Owner));
    ExpectEq("\n\x1b[0;36mGertrude glares at you and snarls, \x1b[0m\x1b[0;33m"
        "`Gorthaur! That was really rude, you\njerk!' \x1b[0m\x1b[0;36mYou "
        "laugh. \x1b[0m\x1b[0;34;1m[Annoyed]\x1b[0m \x1b[0;36mGertrude knees "
        "Gorthaur in the groin.\n\x1b[0m",
        Actor.caughtMessage());
    
    object fred = clone_object("/lib/realizations/npc.c");
    fred.Name("fred");
    move_object(fred, this_object());

    ExpectTrue(Conversation.speakMessage("test", Actor, Owner));
    ExpectEq("\n\x1b[0;36mGertrude glares at you and snarls, \x1b[0m\x1b[0;33m"
        "`Gorthaur! That was really rude, you\njerk!' \x1b[0m\x1b[0;36mYou "
        "laugh. \x1b[0m\x1b[0;34;1m[Annoyed]\x1b[0m \x1b[0;36mGertrude knees "
        "Gorthaur in the groin.\n\x1b[0m\x1b[0;33m`And you, Fred. "
        "Bite me!'\n\x1b[0m",
        Actor.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ResponsesAreClearedAfterChosen()
{
    destruct(Conversation);
    Conversation = clone_object("/lib/tests/support/conversations/testConversation.c");

    Conversation.speakMessage("start quest", Actor, Owner);
    Conversation.displayResponse("1", Actor, Owner);
    ExpectSubStringMatch("I am one who wishes to complete this", Actor.caughtMessage());
    Actor.resetCatchList();

    Conversation.displayResponse("1", Actor, Owner);
    ExpectFalse(Actor.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DisabledResponsesAreCorrectlyDisplayed()
{
    Conversation.testAddTopic("test", "This is a test message");
    Conversation.testAddResponse("test", "Test response", "This is a test response");
    Conversation.testAddResponse("test", "Another", "This is another test response");
    Conversation.testAddResponsePrerequisite("test", "Another", 
        (["race":(["type":"race", "value": ({ "elf", "high elf", "half elf" })])]), 1);

    ExpectTrue(Conversation.speakMessage("test", Actor, Owner));
    ExpectEq(3, sizeof(Actor.caughtMessages()));
    ExpectEq("\nThis is a test message\n", Actor.caughtMessages()[0]);
    ExpectEq("\x1b[0;31m[1]: \x1b[0m\x1b[0;31mAnother\n\x1b[0m", Actor.caughtMessages()[1]);
    ExpectEq("\x1b[0;31;1m[2]: \x1b[0m\x1b[0;33;1mTest response\n\x1b[0m", Actor.caughtMessages()[2]);

    Actor.resetCatchList();
    Actor.Race("elf");
    ExpectTrue(Conversation.speakMessage("test", Actor, Owner));
    ExpectEq(3, sizeof(Actor.caughtMessages()));
    ExpectEq("\nThis is a test message\n", Actor.caughtMessages()[0]);
    ExpectEq("\x1b[0;31;1m[1]: \x1b[0m\x1b[0;33;1mAnother\n\x1b[0m", Actor.caughtMessages()[1]);
    ExpectEq("\x1b[0;31;1m[2]: \x1b[0m\x1b[0;33;1mTest response\n\x1b[0m", Actor.caughtMessages()[2]);
}

/////////////////////////////////////////////////////////////////////////////
void AddResponseEffectAllowsAndAppliesExperience()
{
    Conversation.testAddTopic("test", "This is a test message");
    Conversation.testAddResponse("test", "Another", "This is another test response");
    Conversation.testAddResponseEffect("test", "Another", (["experience": 1000]));

    object room = load_object("/lib/tests/support/environment/fakeEnvironment.c");
    ExpectEq(0, Actor.effectiveExperience());
    ExpectTrue(Conversation.speakMessage("test", Actor, Owner));
    Conversation.displayResponse("1", Actor, Owner);
    ExpectEq(1000, Actor.effectiveExperience());
    ExpectSubStringMatch("You have gained 1000 experience", Actor.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void AddResponseEffectAllowsAndAppliesExperienceToSpecificGuild()
{
    load_object("/lib/tests/support/guilds/testGuild.c");
    load_object("/lib/tests/support/guilds/mageGuild.c");
    Actor.joinGuild("test");
    Actor.joinGuild("fake mage");

    Conversation.testAddTopic("test", "This is a test message");
    Conversation.testAddResponse("test", "Another", "This is another test response");
    Conversation.testAddResponseEffect("test", "Another", (["experience": ([
            "amount": 500,
            "guild": "fake mage"])]));

    object room = load_object("/lib/tests/support/environment/fakeEnvironment.c");
    ExpectEq(0, Actor.effectiveExperience());
    ExpectEq(0, Actor.guildExperience("test"));
    ExpectEq(0, Actor.guildExperience("fake mage"));
    ExpectTrue(Conversation.speakMessage("test", Actor, Owner));
    Conversation.displayResponse("1", Actor, Owner);
    ExpectEq(500, Actor.effectiveExperience());
    ExpectEq(0, Actor.guildExperience("test"));
    ExpectEq(500, Actor.guildExperience("fake mage"));
    ExpectSubStringMatch("You have gained 500 experience.*fake mage only", 
        Actor.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanHandleCallOthers()
{
    object shadow =
        clone_object("/lib/tests/support/services/conversationShadow.c");
    shadow.beginShadow(Owner);

    Conversation.testAddTopic("test", "@D@##TargetName## ##Infinitive::glare## "
        "at ##InitiatorName## and ##Infinitive::snarl##, @S@`"
        "##CallOther::firstOne##, aka ##CallOther::secondOne##! That was "
        "really rude!' @D@You ##ResponseInfinitive::laugh##. "
        "@A@Annoyed@E@");

    move_object(Actor, this_object());
    move_object(Owner, this_object());

    ExpectTrue(Conversation.speakMessage("test", Actor, Owner));
    ExpectEq("\n\x1b[0;36mGertrude glares at you and snarls, \x1b[0m\x1b[0;33m"
        "`Gorthaur, aka Ser Arseling! That was\nreally rude!' \x1b[0m\x1b[0;36mYou "
        "laugh. \x1b[0m\x1b[0;34;1m[Annoyed]\x1b[0m\n",
        Actor.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void AddResponseEffectAllowsAndAppliesJoin()
{
    Conversation.testAddTopic("test", "This is a test message");
    Conversation.testAddResponse("test", "Another", "This is another test response");
    Conversation.testAddResponseEffect("test", "Another", (["join":1]));

    object room = load_object("/lib/tests/support/environment/fakeEnvironment.c");
    ExpectEq(0, Actor.partyName());
    ExpectEq(0, Owner.partyName());
    ExpectTrue(Conversation.speakMessage("test", Actor, Owner));
    Conversation.displayResponse("1", Actor, Owner);
    ExpectEq("Gorthaur's Party", Actor.partyName());
    ExpectEq("Gorthaur's Party", Owner.partyName());
    ExpectTrue(object_name(Actor.getParty()) == object_name(Owner.getParty()));
    ExpectEq(2, sizeof(Owner.getParty().members(1)));
    ExpectEq(2, sizeof(Actor.getParty().members(1)));
    ExpectSubStringMatch("Gertrude has joined your party", Actor.caughtMessage());
}
