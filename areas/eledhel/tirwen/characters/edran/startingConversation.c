//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Edran rests one hand on the "
        "fold gate. @S@'Come through slowly, and shut that latch "
        "when you leave.'");
    addTopic("the flock", "@S@'The sheep graze the lower field by "
        "day and return to this fold at dusk. They belong to the "
        "farm households; none are strays.'");
    addTopic("the road", "@S@'The King's Road is west of the farm "
        "lane. The drovers use it for the ford, but I keep the "
        "flock off the cart track.'");
    addResponse("first conversation", "May I cross the pasture?",
        "@S@'Use the lane and leave the fold gate as you found it.'");
    addResponseTopic("first conversation", "May I cross the pasture?",
        "the flock");
    addResponse("first conversation", "Where is the King's Road?",
        "@S@'Follow the farm lane west. The main road is at its end.'");
    addResponseTopic("first conversation", "Where is the King's Road?",
        "the road");
}
