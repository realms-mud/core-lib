//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Fethil watches the cart crossing "
        "until the lane clears. @S@'The way is open now.'");
    addTopic("shop patrol", "@S@'We check the busiest doors and make "
        "sure the carts do not block access to the shops.'");
    addResponse("first conversation", "What is your patrol checking?",
        "@D@She points along the row of trade doors.");
    addResponseTopic("first conversation", "What is your patrol checking?",
        "shop patrol");
}
