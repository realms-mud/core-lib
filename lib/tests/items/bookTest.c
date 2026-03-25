//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights
//                      reserved. See the accompanying LICENSE file for
//                      details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Book;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
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
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Book);
}

/////////////////////////////////////////////////////////////////////////////
void NumChaptersReflectsAddedChapters()
{
    ExpectEq(2, Book.numChapters());
}

/////////////////////////////////////////////////////////////////////////////
void TableOfContentsShowsChapters()
{
    // tableOfContents() was removed in favor of an interactive selector.
    // Verify that chapter data is present via query("chapters").
    mixed chapters = Book.query("chapters");
    ExpectTrue(pointerp(chapters));
    ExpectEq(2, sizeof(chapters));
    ExpectEq("One", chapters[0]["title"]);
}

/////////////////////////////////////////////////////////////////////////////
void ReadChapterReturnsFormattedText()
{
    string ch = Book.readChapter(1);
    ExpectSubStringMatch("One", ch);
    ExpectSubStringMatch("First chapter text", ch);
}

/////////////////////////////////////////////////////////////////////////////
void ReadChapterOutOfRangeReturnsZero()
{
    ExpectEq(0, Book.readChapter(999));
}

/////////////////////////////////////////////////////////////////////////////
void QueryChaptersReturnsMappingArray()
{
    mixed chapters = Book.query("chapters");
    ExpectTrue(pointerp(chapters));
    ExpectEq(2, sizeof(chapters));
    ExpectEq("One", chapters[0]["title"]);
}

/////////////////////////////////////////////////////////////////////////////
void SetTitleAndQueryTitleWork()
{
    Book.set("title", "A New Title");
    ExpectEq("A New Title", Book.query("title"));
}
