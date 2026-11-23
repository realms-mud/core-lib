//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Dalon watches the line of crates "
        "beside the water. @S@'Keep a clear path to the berth.'");
    addTopic("quay watch", "@S@'We keep an eye on cargo and leave "
        "room for the crews to move between ship and shore.'");
    addResponse("first conversation", "What is the watch protecting?",
        "@D@He glances toward the open berth.");
    addResponseTopic("first conversation", "What is the watch protecting?",
        "quay watch");
}
