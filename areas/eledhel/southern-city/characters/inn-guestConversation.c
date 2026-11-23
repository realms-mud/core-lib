//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Perrin sets down his spoon "
        "and shifts his travel pack beneath the bench.");
    addTopic("the road", "@S@'I am heading south at first light. "
        "The road is easier when you start rested and carry only "
        "what you need.'");

    addResponse("first conversation", "Where are you bound?",
        "@S@'A farm south of the city. I came in to buy supplies "
        "and will leave after breakfast.'");
    addResponseTopic("first conversation", "Where are you bound?",
        "the road");
}
