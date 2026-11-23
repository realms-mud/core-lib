//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Hethin compares her list with the "
        "parcels in her basket. @S@'I have one stop left.'");
    addTopic("market list", "@S@'I buy dry goods first, then anything "
        "that should not sit in the sun. It saves a second trip home.'");
    addResponse("first conversation", "What is still on your list?",
        "@D@She folds the paper to keep it from the wind.");
    addResponseTopic("first conversation", "What is still on your list?",
        "market list");
}
