//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Verran checks a handcart's "
        "bindings. @S@'The next parcel is ready to go.'");
    addTopic("cart loading", "@S@'Heavy crates ride low, and fragile "
        "goods stay above them. It keeps the road trip from costing a shop.'");
    addResponse("first conversation", "How do you load the cart?",
        "@D@He taps the lower crate.");
    addResponseTopic("first conversation", "How do you load the cart?",
        "cart loading");
}
