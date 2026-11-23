//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Iveron checks the fish under a "
        "damp cloth. @S@'The catch must reach the stalls fresh.'");
    addTopic("fish catch", "@S@'We sort the fish by size, then send "
        "the best of the catch straight to the market.'");
    addResponse("first conversation", "Where does the catch go?",
        "@D@He gestures toward the inland stalls.");
    addResponseTopic("first conversation", "Where does the catch go?",
        "fish catch");
}
