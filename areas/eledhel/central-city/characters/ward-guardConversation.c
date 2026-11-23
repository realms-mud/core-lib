//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Calen watches a cart turn "
        "into a side street. @S@'A clear lane keeps the people "
        "walking and the goods moving.'");
    addTopic("guard duty", "@S@'I am here to prevent trouble "
        "where the streets narrow. If a disagreement starts, "
        "I try to settle it before it spreads.'");
    addResponse("first conversation", "What do you watch for?",
        "@D@He scans the adjoining street.");
    addResponseTopic("first conversation", "What do you watch for?",
        "guard duty");
}
