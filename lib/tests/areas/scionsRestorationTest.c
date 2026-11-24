//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;
object Room;
object Book;
object BookContainer;
object Renveth;
object RenvethConversation;
string RestorationQuest = "/areas/minlach/quests/scions-restoration.c";
string TolDhurathQuest =
    "/areas/tol-dhurath/state-machine/tol-dhurath-quest.c";

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Room = clone_object("/lib/tests/support/environment/fakeEnvironment.c");
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player->Name("scionsrestorationtest");
    Player->addCommands();
    Player->colorConfiguration("none");
    set_this_player(Player);
    move_object(Player, Room);

    Book = clone_object("/areas/items/books/scions-of-dhuras.c");
    move_object(Book, Player);

    Renveth = clone_object("/areas/minlach/characters/renveth/renveth.c");
    move_object(Renveth, Room);
    RenvethConversation = clone_object(
        "/areas/minlach/characters/renveth/startingConversation.c");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    if (objectp(Renveth))
    {
        destruct(Renveth);
    }
    if (objectp(Book))
    {
        destruct(Book);
    }
    if (objectp(BookContainer))
    {
        destruct(BookContainer);
    }
    if (objectp(RenvethConversation))
    {
        destruct(RenvethConversation);
    }
    if (objectp(Player))
    {
        destruct(Player);
    }
    if (objectp(Room))
    {
        destruct(Room);
    }
}

/////////////////////////////////////////////////////////////////////////////
void ReadingAndDeliveringTheBookBeforeTheReleaseRestoresTheOrder()
{
    ExpectFalse(Player->joinGuild("Scion of Dhuras"),
        "membership is unavailable before restoration");

    command("read scions book", Player);
    ExpectFalse(Player->questIsActive(RestorationQuest),
        "opening the book does not start the quest");
    command("1", Player);
    ExpectTrue(Player->questIsActive(RestorationQuest),
        "selecting a chapter starts the quest");

    BookContainer = clone_object("/lib/items/container.c");
    BookContainer->set("name", "leather satchel");
    move_object(BookContainer, Player);
    move_object(Book, BookContainer);
    ExpectTrue(member(deep_inventory(Player), Book) > -1,
        "the book is in the player's deep inventory");
    ExpectTrue(RenvethConversation->speakMessage("first conversation",
        Player, Renveth));
    ExpectTrue(RenvethConversation->displayResponse("1", Player, Renveth));
    ExpectSubStringMatch("Renveth opens", Player->caughtMessage());
    ExpectEq("book delivered", Player->questState(RestorationQuest));
    ExpectTrue(present(Book, Renveth));

    object quest = load_object(TolDhurathQuest);
    Player->beginQuest(TolDhurathQuest);
    quest->receiveEvent(Player, "met maiwyn");
    quest->receiveEvent(Player, "maiwyn helps");
    quest->receiveEvent(Player, "obedience trial complete");
    Renveth->notifySynchronous("tolDhurathReleaseReported", Player);

    ExpectTrue(Player->questIsCompleted(RestorationQuest));
    ExpectTrue(Player->joinGuild("Scion of Dhuras"),
        "restoration unlocks guild membership");
}

/////////////////////////////////////////////////////////////////////////////
void ReportingTheReleaseBeforeDeliveringTheBookRestoresTheOrder()
{
    command("read scions book", Player);
    command("1", Player);
    object quest = load_object(TolDhurathQuest);
    Player->beginQuest(TolDhurathQuest);
    quest->receiveEvent(Player, "met maiwyn");
    quest->receiveEvent(Player, "maiwyn helps");
    quest->receiveEvent(Player, "obedience trial complete");
    BookContainer = clone_object("/lib/items/container.c");
    BookContainer->set("name", "leather satchel");
    move_object(BookContainer, Player);
    move_object(Book, BookContainer);

    Renveth->notifySynchronous("tolDhurathReleaseReported", Player);
    ExpectEq("release reported", Player->questState(RestorationQuest));

    ExpectTrue(RenvethConversation->speakMessage("first conversation",
        Player, Renveth));
    ExpectTrue(RenvethConversation->displayResponse("1", Player, Renveth));
    ExpectSubStringMatch("Renveth opens", Player->caughtMessage());
    ExpectTrue(Player->questIsCompleted(RestorationQuest));
}
