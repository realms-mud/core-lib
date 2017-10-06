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
    Conversation = clone_object("/lib/tests/support/conversations/testConversation.c");
    object room = load_object("/lib/tests/support/environment/fakeEnvironment.c");

    Actor = clone_object("/lib/tests/support/services/mockPlayer.c");
    Actor->Name("Bob");
    Actor->Gender(1);
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
void SpeakMessageDisplaysCorrectMessageWithAvailableResponses()
{
    Conversation->speakMessage("start quest", Actor, Owner);
    ExpectSubStringMatch("Greetings, seekers. Welcome", Actor->caughtMessages()[0]);
    ExpectSubStringMatch("I am someone...", Actor->caughtMessages()[1]);
    ExpectSubStringMatch("My name is...", Actor->caughtMessages()[2]);
    ExpectSubStringMatch("None of your business", Actor->caughtMessages()[3]);
}

/////////////////////////////////////////////////////////////////////////////
void DisplayResponseReturnsNothingIfMessageNotSpokenFirst()
{
    Conversation->displayResponse("1", Actor, Owner);
    ExpectFalse(Actor->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DisplayResponseReturnsCorrectMessage()
{
    Conversation->speakMessage("start quest", Actor, Owner);
    Conversation->displayResponse("1", Actor, Owner);
    ExpectSubStringMatch("I am one who wishes to complete this", Actor->caughtMessage());

    Conversation->displayResponse("2", Actor, Owner);
    ExpectSubStringMatch("I am Bob and I am here to pass the trial", Actor->caughtMessage());

    Conversation->displayResponse("3", Actor, Owner);
    ExpectSubStringMatch("Who I am is not your concern, wraith", Actor->caughtMessage());
}