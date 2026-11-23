//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Thalion checks a wheel "
        "with a practiced glance. @S@'A cart should turn without "
        "taking the whole street with it.'");
    addTopic("cart repair", "@S@'I replace broken spokes and "
        "tighten the hubs. If the frame is sound, most carts can "
        "be put back to work.'");
    addResponse("first conversation", "What do you build?",
        "@D@He looks over the cart's wooden frame.");
    addResponseTopic("first conversation", "What do you build?",
        "cart repair");
}
