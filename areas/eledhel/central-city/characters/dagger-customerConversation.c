//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Dareth checks the empty "
        "sheath at his belt. @S@'It is only a tool, but I want it "
        "ready before I take the late watch.'");
    addTopic("watch duty", "@S@'Most nights are quiet. That is no "
        "reason to carry a dull knife or to draw it when a word would "
        "serve better.'");
    addResponse("first conversation", "Why is the knife at the smith?",
        "@D@He taps the empty sheath.");
    addResponseTopic("first conversation", "Why is the knife at the "
        "smith?", "watch duty");
}
