//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Mavren tests a cloak's "
        "lining with his thumb. @S@'A cart is no place to discover "
        "your coat leaks.'");
    addTopic("travel gear", "@S@'The north road is cold after "
        "sunset. I would rather spend coin here than lose a day "
        "to a sick driver.'");

    addResponse("first conversation", "Where are you headed?",
        "@D@He glances toward the northern avenue.");
    addResponseTopic("first conversation", "Where are you headed?",
        "travel gear");
}
