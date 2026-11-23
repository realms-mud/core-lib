//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Tavren checks the folded "
        "statement in his hands. @S@'I have been waiting since "
        "morning, but at least someone will hear me.'");
    addTopic("the petition", "@S@'A trader says my cart damaged "
        "his crates. I brought two witnesses and the wheel that "
        "broke. I only want the facts considered.'");

    addResponse("first conversation", "What brings you here?",
        "@S@'A dispute over a cart and some damaged cargo. "
        "I have written down what happened.'");
    addResponseTopic("first conversation", "What brings you here?",
        "the petition");
}
