//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Taren checks the cart's "
        "empty bed before taking the handles. @S@'The return load "
        "is lighter. That makes the paving easier, not the route.'");
    addTopic("goods by cart", "@S@'I move sacks and small crates "
        "between the outer stores and the tradespeople. I keep the "
        "loads low enough to see the road ahead.'");
    addResponse("first conversation", "What do you carry?",
        "@D@He taps the side of the cart.");
    addResponseTopic("first conversation", "What do you carry?",
        "goods by cart");
}
