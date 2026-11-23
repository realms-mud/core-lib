//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Quelan pulls his cart clear of "
        "a shop door. @S@'The next load can get through.'");
    addTopic("market carts", "@S@'We keep the widest lane open for "
        "deliveries. Smaller loads use the side approach.'");
    addResponse("first conversation", "Where do the carts unload?",
        "@D@He points toward a marked space.");
    addResponseTopic("first conversation", "Where do the carts unload?",
        "market carts");
}
