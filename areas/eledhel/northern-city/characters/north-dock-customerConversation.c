//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Nerion weighs a small parcel "
        "in his hands. @S@'I am getting provisions before my watch "
        "assembles. Better to be ready before the call.'");
    addTopic("shipboard life", "@S@'A quiet watch still takes work. "
        "You check the lines, listen for a change in the hull, "
        "and trust the next sailor to do the same.'");

    addResponse("first conversation", "What are you buying?",
        "@S@'Food for the ship. Taviel keeps the pier stall, "
        "and the quartermaster handles the naval stores.'");
    addResponse("first conversation", "Do you like sailing?",
        "@D@Nerion looks out toward the berths.");
    addResponseTopic("first conversation", "Do you like sailing?",
        "shipboard life");
    addResponse("shipboard life", "Does the watch get dangerous?",
        "@S@'Sometimes. Most of the time it is patience, good knots, "
        "and paying attention before trouble starts.'");
}
