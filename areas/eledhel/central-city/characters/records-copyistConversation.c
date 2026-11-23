//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Nethor presses a hand "
        "against the pages to keep them from shifting. @S@'The copies "
        "are for the public shelves, not the archive.'");
    addTopic("records", "@S@'A clean copy lets another clerk check "
        "the original without wearing the ink away.'");
    addResponse("first conversation", "What are you carrying?",
        "@D@He keeps the packet carefully closed.");
    addResponseTopic("first conversation", "What are you carrying?",
        "records");
}
