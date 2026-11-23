//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Norien brushes flour from her "
        "apron. @S@'This loaf is for a household up the lane.'");
    addTopic("baking", "@S@'The ovens are busiest before the market "
        "opens. I save the firm loaves for travelers.'");
    addResponse("first conversation", "Who gets the loaf?",
        "@D@She checks the wrapping.");
    addResponseTopic("first conversation", "Who gets the loaf?", "baking");
}
