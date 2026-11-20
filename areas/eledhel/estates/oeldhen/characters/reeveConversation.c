//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@S@'The Oeldhen fields supply "
        "vegetables and grain to the capital. The road is watched, "
        "but carts still need daylight to make the gate.'");
    addResponse("first conversation", "Who tends the garden?",
        "@S@'The household grows kitchen herbs and keeps the seed "
        "beds here. Ask before taking anything from the plots.'");
}
