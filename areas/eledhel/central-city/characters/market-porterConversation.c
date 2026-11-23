//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Belen adjusts the empty "
        "sack at her side. @S@'The next load will be heavier. "
        "I am glad for a moment to rest.'");
    addTopic("loading", "@S@'I move goods from cart to counter "
        "and keep a tally for the shopkeeper. A careful hand "
        "saves a lot of counting later.'");
    addResponse("first conversation", "What do you carry?",
        "@D@She folds the sack into a compact square.");
    addResponseTopic("first conversation", "What do you carry?",
        "loading");
}
