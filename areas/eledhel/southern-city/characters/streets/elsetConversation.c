//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Elset unfolds a delivery list and "
        "marks a stop with charcoal. @S@'One more parcel on this side.'");
    addTopic("courier routes", "@S@'I keep to the side lanes when carts "
        "are moving. The main crossings are slower at market hours.'");
    addResponse("first conversation", "How do you choose your route?",
        "@D@She traces a line between the houses.");
    addResponseTopic("first conversation", "How do you choose your route?",
        "courier routes");
}
