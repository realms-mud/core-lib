//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Rinan turns the wheel by its "
        "rim. @S@'The hub sits straight on the axle.'");
    addTopic("wheelwright", "@S@'A loose hub is dangerous on a loaded "
        "cart. I asked the shop to check it before I left.'");
    addResponse("first conversation", "What did the wainwright repair?",
        "@D@He taps the center of the wheel.");
    addResponseTopic("first conversation", "What did the wainwright repair?",
        "wheelwright");
}
