//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Brann reins his cart toward the "
        "edge of the paving. @S@'Pedestrians can pass here.'");
    addTopic("cart routes", "@S@'I use the wide road for loads and "
        "leave the narrow lanes to people on foot.'");
    addResponse("first conversation", "Where do you take the cart?",
        "@D@He checks the harness.");
    addResponseTopic("first conversation", "Where do you take the cart?",
        "cart routes");
}
