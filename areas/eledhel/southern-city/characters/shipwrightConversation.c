//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Edril studies a timber "
        "joint and tests its fit. @S@'A hull must be sound before "
        "anyone trusts it beyond the harbor.'");
    addTopic("ship repairs", "@S@'We inspect the keel, ribs, and "
        "fastenings before we patch a vessel. A quick repair is "
        "no good if it hides a deeper fault.'");

    addResponse("first conversation", "What work do you take?",
        "@D@He points toward the repair floor.");
    addResponseTopic("first conversation", "What work do you take?",
        "ship repairs");
}
