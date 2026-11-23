//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Weryn draws the bowstring taut "
        "between both hands. @S@'The twist is even.'");
    addTopic("bowstrings", "@S@'A string should be checked for worn "
        "strands before it goes on a bow. I test each one under tension.'");
    addResponse("first conversation", "How do you test a bowstring?",
        "@D@She eases the string back into its coil.");
    addResponseTopic("first conversation", "How do you test a bowstring?",
        "bowstrings");
}
