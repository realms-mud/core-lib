//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Edreth looks over a small "
        "branch before setting it aside. @S@'A little trimming now "
        "keeps the path open.'");
    addTopic("city garden", "@S@'There is not much soil between "
        "the stones. I keep the small planted places healthy and "
        "clear the walks of fallen growth.'");
    addResponse("first conversation", "What are you tending?",
        "@D@He gestures toward the street's planted borders.");
    addResponseTopic("first conversation", "What are you tending?",
        "city garden");
}
