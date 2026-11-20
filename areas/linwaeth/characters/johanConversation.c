//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Johan wipes a tool clean before "
        "he answers. @S@'If it is broken, let me see it. If it is only "
        "dirty, you can spare us both the trouble.'");
    addTopic("the old road", "@S@'The road south has carried carts "
        "longer than I have worked iron. The stones remember every "
        "overloaded wheel, and so do the people who mend them.'");
    addResponse("first conversation", "Can you repair my equipment?",
        "@S@'Bring it here and I will tell you what can be done.'");
    addResponse("first conversation", "What do you know about the road?",
        "@S@'Ask the innkeeper for the latest reports. I can tell "
        "you what the tracks and broken fittings say, not who made them.'");
    addResponseTopic("first conversation", "What do you know about the road?",
        "the old road");
}
