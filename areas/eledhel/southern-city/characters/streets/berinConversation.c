//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Berin checks the cloth over his "
        "bread basket. @S@'I need to reach the houses before the loaves "
        "cool.'");
    addTopic("bread deliveries", "@S@'I carry the morning bread to the "
        "nearby households. The shop keeps the rest for passersby.'");
    addResponse("first conversation", "Where do you deliver the bread?",
        "@D@He points toward the quiet residential lanes.");
    addResponseTopic("first conversation", "Where do you deliver the bread?",
        "bread deliveries");
}
