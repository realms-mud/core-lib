//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";
#include "/lib/include/inventory.h"

object QuestItem;

/////////////////////////////////////////////////////////////////////////////
void SetUpQuestItem()
{
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
        "I must lay off the sauce - and the wenches. King Tantor is dead because of my night of debauchery.",
        "/lib/tests/support/quests/testKingObject.c");
    QuestItem->testAddTransition("serve the king", "king is dead", "maybeNobodyWillNotice");
    QuestItem->testAddFinalState("king is dead", "failure");

    object king = clone_object("/lib/tests/support/quests/testKingObject.c");
    QuestItem->testRegisterQuestActor(king);

    object assassin = clone_object("/lib/tests/support/quests/testAssassinObject.c");
    QuestItem->testRegisterQuestActor(assassin);

    object room = clone_object("/lib/environment/room.c");
    move_object(king, room);
    move_object(assassin, room);

    QuestItem->testInitialState("meet the king");
}

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    ignoreList += ({ "SetUpQuestItem" });
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    QuestItem = clone_object("/lib/tests/support/quests/testQuestItem.c");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(QuestItem);
}

/////////////////////////////////////////////////////////////////////////////
void AddStateThrowsWhenStateNotValid()
{
    string err = catch (QuestItem->testAddState());
    ExpectEq("*ERROR - questItem: the quest state could not be added.", err);
}

/////////////////////////////////////////////////////////////////////////////
void AddStateThrowsWhenDescriptionNotValid()
{
    string err = catch (QuestItem->testAddState("blah"));
    ExpectEq("*ERROR - questItem: the quest state could not be added.", err);
}

/////////////////////////////////////////////////////////////////////////////
void AddStateSilentlySucceedsWhenStateIsValid()
{
    // If anything were to go amiss, this would throw.
    QuestItem->testAddState("meet the king", "I've been asked to meet the king!");
}

/////////////////////////////////////////////////////////////////////////////
void InitialStateThrowsWhenStateNotPresent()
{
    QuestItem->testAddState("meet the king", "I've been asked to meet the king!");
    string err = catch (QuestItem->testInitialState("blah"));
    ExpectEq("*ERROR - questItem: the initial state must have been added first.", err);
}

/////////////////////////////////////////////////////////////////////////////
void AddEntryActionThrowsWhenStateNotPresent()
{
    string err = catch (QuestItem->testAddEntryAction("blah", "things"));
    ExpectEq("*ERROR - questItem: an entry action can only be added if the both the state exists and the method to call has been implemented on this object.", err);
}

/////////////////////////////////////////////////////////////////////////////
void AddExitActionThrowsWhenStateNotPresent()
{
    string err = catch (QuestItem->testAddExitAction("blah", "things"));
    ExpectEq("*ERROR - questItem: an exit action can only be added if the both the state exists and the method to call has been implemented on this object.", err);
}

/////////////////////////////////////////////////////////////////////////////
void SetInitialStateSetsTheInitialState()
{
    // If anything were to go amiss, this would throw.
    QuestItem->testAddState("meet the king", "I've been asked to meet the king!");
    QuestItem->testInitialState("meet the king");
    ExpectEq("meet the king", QuestItem->testInitialState());
}

/////////////////////////////////////////////////////////////////////////////
void GimmeStory()
{
    SetUpQuestItem();
    ExpectEq("x", QuestItem->questStory(({"meet the king", "met the king", "serve the king", "ignore the king"})));
}