//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Orwen checks his list a second "
        "time. @S@'If I forget the salt again, the whole kitchen will "
        "know before I do.'");
    addTopic("market list", "@S@'I buy for a household, not a hall. "
        "Meleth will split a sack when we do not need the whole of it.'");
    addResponse("first conversation", "What are you buying?",
        "@D@He holds up the list.");
    addResponseTopic("first conversation", "What are you buying?",
        "market list");
}
