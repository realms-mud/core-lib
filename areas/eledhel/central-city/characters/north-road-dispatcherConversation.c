//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Yeren folds his list and "
        "looks toward the northern road. @S@'I record what comes "
        "through. The carts choose their own pace.'");
    addTopic("north road", "@S@'Travelers come down from the "
        "north with small loads and letters. The public road stays "
        "open to anyone who can make the journey.'");
    addResponse("first conversation", "What do you record?",
        "@D@He taps the folded list.");
    addResponseTopic("first conversation", "What do you record?",
        "north road");
}
