//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Kethran keeps his eyes on "
        "the road below. @S@'The gate watch changes at midnight. "
        "Until then, I keep this walk clear.'");
    addTopic("wall walk", "@S@'The passage runs inside the wall. "
        "From here the sentries can watch the road without "
        "crowding the gatehouse.'");

    addResponse("first conversation", "Why patrol the wall?",
        "@D@He gestures toward the stair.");
    addResponseTopic("first conversation", "Why patrol the wall?",
        "wall walk");
}
