//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Norwen reviews a list "
        "written in a small hand. @S@'I have enough coin for the "
        "things we need, if I do not get distracted.'");
    addTopic("provisions", "@S@'The household needs flour, oil, "
        "and a little salt. I can buy the rest another day.'");
    addResponse("first conversation", "What is on your list?",
        "@D@She folds the paper before the ink can smudge.");
    addResponseTopic("first conversation", "What is on your list?",
        "provisions");
}
