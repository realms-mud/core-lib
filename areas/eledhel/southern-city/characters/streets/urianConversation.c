//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Urian shifts a small display "
        "away from the cart lane. @S@'There is room to pass now.'");
    addTopic("street trade", "@S@'I sell small household goods to "
        "people headed between the market and the harbor.'");
    addResponse("first conversation", "What do you sell?",
        "@D@He indicates the neatly arranged goods.");
    addResponseTopic("first conversation", "What do you sell?",
        "street trade");
}
