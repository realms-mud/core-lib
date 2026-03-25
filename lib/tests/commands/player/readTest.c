//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights
//                      reserved. See the accompanying LICENSE file for
//                      details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;
object Room;
object Book;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Room = clone_object("/lib/tests/support/environment/fakeEnvironment.c");
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player.Name("bob");
    Player.addCommands();
    Player.colorConfiguration("none");
    move_object(Player, Room);

    Book = clone_object("/lib/items/book.c");
    Book.set("name", "test chronicle");
    Book.set("short", "A test chronicle");
    Book.set("title", "The Test Chronicle");
    Book.addChapter("One",
        "First chapter text. This is a short paragraph used to test "
        "formatting and chapter retrieval.");
    Book.addChapter("Two",
        "Second chapter text. Another paragraph that will be wrapped "
        "and returned by readChapter().");
    move_object(Book, Room);
    Player.resetCatchList();
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Player);
    destruct(Room);
}

/////////////////////////////////////////////////////////////////////////////
void ReadWithNoTargetAsksForTarget()
{
    ExpectTrue(command("read", Player));
    ExpectEq("Read what?\n", Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ReadNonexistentReportsMissing()
{
    ExpectTrue(command("read nothing", Player));
    ExpectEq("There is no 'nothing' here.\n", Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ReadBookShowsTableOfContents()
{
    ExpectTrue(command("read test chronicle", Player));

    string all = implode(Player.caughtMessages(), "\n");
    ExpectSubStringMatch("The Test Chronicle", all);
    ExpectSubStringMatch("1\.+ One", all);
    ExpectSubStringMatch("2\.+ Two", all);
}

/////////////////////////////////////////////////////////////////////////////
void ReadSelectingChapterDisplaysChapter()
{
    ExpectTrue(command("read test chronicle", Player), "read test chronicle");
    ExpectTrue(command("1", Player), "1 pressed");

    string all = implode(Player.caughtMessages(), "\n");
    ExpectSubStringMatch("One", all);

    ExpectSubStringMatch("First chapter text. This is a short paragraph "
        "used to test formatting and\\\nchapter retrieval.", all);

    ExpectSubStringMatch("Return", all);
}

/////////////////////////////////////////////////////////////////////////////
void ReadSelectingMultipleChaptersWithoutExiting()
{
    ExpectTrue(command("read test chronicle", Player));
    ExpectTrue(command("1", Player));

    ExpectTrue(command("1", Player));
    ExpectTrue(command("2", Player));

    string all = implode(Player.caughtMessages(), "\n");
    ExpectSubStringMatch("Two", all);
    ExpectSubStringMatch("Second chapter text", all);
}
