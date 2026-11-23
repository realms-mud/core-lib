//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Daina tucks a paper packet into "
        "her basket. @S@'The herbalist marked the dose clearly.'");
    addTopic("herbal remedies", "@S@'The shopkeeper explains each "
        "preparation. I ask before mixing anything from two jars.'");
    addResponse("first conversation", "What did you buy?",
        "@D@She keeps the packet closed.");
    addResponseTopic("first conversation", "What did you buy?",
        "herbal remedies");
}
