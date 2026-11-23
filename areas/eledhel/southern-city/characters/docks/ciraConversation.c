//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Cira reads a short supply list "
        "to the crew. @S@'Check the water flasks before departure.'");
    addTopic("crew supplies", "@S@'The crew checks food, water, and "
        "lines before taking a boat out. Small things are easy to forget.'");
    addResponse("first conversation", "What is the crew missing?",
        "@D@She folds the list and calls the next item.");
    addResponseTopic("first conversation", "What is the crew missing?",
        "crew supplies");
}
