//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Rethen secures the cask with "
        "both hands. @S@'The taproom ordered this before noon.'");
    addTopic("brewery deliveries", "@S@'The brewery sends sealed casks "
        "to the public houses. We return the empties on the next run.'");
    addResponse("first conversation", "Where is the cask going?",
        "@D@He turns toward the nearby inn.");
    addResponseTopic("first conversation", "Where is the cask going?",
        "brewery deliveries");
}
