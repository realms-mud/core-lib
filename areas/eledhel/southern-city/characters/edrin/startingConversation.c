//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@S@'Welcome. The shelves are arranged "
        "by subject, though I can usually find a title faster than the "
        "catalog can.'");
    addTopic("the library", "@S@'The public library keeps the records "
        "and histories. My shop is for books you can take home, and "
        "for the occasional text a scholar cannot wait to borrow.'");
    addTopic("maps", "@D@Edrin draws a careful line on the counter "
        "with one finger. @S@'A map can tell you where a road was "
        "when it was drawn. It cannot tell you whether the bridge "
        "still stands or who is waiting beyond the next hill.'");
    addTopic("choosing a book", "@S@'Tell me what you want to learn "
        "and how much time you have. A short practical guide can be "
        "more useful than a grand volume you never finish.'");
    addTopic("local histories", "@S@'The city records are useful, "
        "but they were written by people with their own interests. "
        "Compare accounts before deciding what a disputed event means.'");
    addTopic("reading a map", "@S@'Look for the date, the scale, and "
        "the landmarks the maker used. A map is a tool for asking "
        "better questions, not a substitute for paying attention.'");

    addResponse("first conversation", "What do you recommend?",
        "@S@'A good history makes a long winter shorter. A map makes "
        "a long road safer.'");
    addResponseTopic("first conversation", "What do you recommend?",
        "the library");
    addResponse("first conversation", "Do you have maps?",
        "@S@'I keep maps of the settled roads. Check the date before "
        "you trust one, and ask the watch about any recent changes.'");
    addResponseTopic("first conversation", "Do you have maps?", "maps");
    addResponse("first conversation", "Can you help me find a subject?",
        "@S@'Certainly. Tell me what you hope to learn and I will "
        "point you toward the right shelf.'");
    addResponseTopic("first conversation",
        "Can you help me find a subject?", "choosing a book");
    addResponse("the library", "Can I read there without buying?",
        "@S@'The public library is the place for that. My shop sells "
        "books, but I can tell you where to begin.'");
    addResponseTopic("the library", "Can I read there without buying?",
        "choosing a book");
    addResponse("maps", "Can a map be trusted?",
        "@S@'As a record of what its maker saw, yes. As a promise "
        "that the road is unchanged, no.'");
    addResponseTopic("maps", "Can a map be trusted?", "reading a map");
    addResponse("first conversation", "Do you have books on Eledhel?",
        "@S@'I keep several histories and travel accounts. Their "
        "authors disagree about parts of the past.'");
    addResponseTopic("first conversation",
        "Do you have books on Eledhel?", "local histories");
    addResponse("local histories", "Which account should I believe?",
        "@S@'Read more than one, and notice who wrote each. I can "
        "help you find accounts that differ.'");
    addResponseTopic("local histories", "Which account should I believe?",
        "choosing a book");
    addResponse("reading a map", "What if the landmarks have changed?",
        "@S@'Ask someone who travels that road now. I can sell you "
        "a map, but I cannot promise it knows today's conditions.'");
    addResponseTopic("reading a map",
        "What if the landmarks have changed?", "the library");
}
