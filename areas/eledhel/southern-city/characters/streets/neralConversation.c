//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Neral wraps the bowl in a square "
        "of cloth. @S@'That should keep it safe on the walk home.'");
    addTopic("pottery purchases", "@S@'I look for an even rim and no "
        "hairline cracks. The potter replaces a piece that fails inspection.'");
    addResponse("first conversation", "How do you choose a good bowl?",
        "@D@He turns it carefully in his hands.");
    addResponseTopic("first conversation", "How do you choose a good bowl?",
        "pottery purchases");
}
