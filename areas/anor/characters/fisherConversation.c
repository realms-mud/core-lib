//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@S@'The harbor feeds the town. "
        "We trade the catch for grain, timber, and tools.'");
    addResponse("first conversation", "Can I hire a boat?",
        "@S@'Ask again when the tide turns. No one here puts a boat "
        "through the outer rocks in a hard wind.'");
}
