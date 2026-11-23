//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Dareth arranges wrapped "
        "food and water flasks beneath the counter. "
        "@S@'The quay shop is open. Take what will travel well.'");
    addTopic("provisions", "@S@'Crews buy dried food and clean "
        "water for the crossing. I keep simple supplies for "
        "people staying ashore too.'");

    addResponse("first conversation", "What do the crews need?",
        "@D@He gestures toward the shelves.");
    addResponseTopic("first conversation", "What do the crews need?",
        "provisions");
}
