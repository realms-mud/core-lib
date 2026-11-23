//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Saran looks toward the workroom. "
        "@S@'The cart is ready. The harness is the only thing holding "
        "me here.'");
    addTopic("cart delivery", "@S@'I carry flour and lamp oil between "
        "the storehouses and the smaller shops. A sound harness keeps "
        "the whole load from shifting.'");
    addResponse("first conversation", "Where are you headed?",
        "@D@He taps the empty hand that should hold the reins.");
    addResponseTopic("first conversation", "Where are you headed?",
        "cart delivery");
}
