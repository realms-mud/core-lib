//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Eryth turns an empty cask to "
        "check its hoops. @S@'This one is sound enough to return.'");
    addTopic("barrel repair", "@S@'A loose hoop means a lost load. "
        "I check the casks before they go back aboard.'");
    addResponse("first conversation", "What is wrong with the cask?",
        "@D@He taps one of the iron hoops.");
    addResponseTopic("first conversation", "What is wrong with the cask?",
        "barrel repair");
}
