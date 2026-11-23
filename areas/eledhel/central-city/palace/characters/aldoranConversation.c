//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Aldoran watches a groom "
        "lead a horse across the stable yard. @S@'A sound mount "
        "is worth little if no one has prepared it properly.'");
    addTopic("stable wing", "@S@'The horses need clean water, "
        "steady handling, and enough rest. We check the tack before "
        "anyone rides out.'");
    addTopic("horses", "@S@'A horse will tell you when something "
        "is wrong. You must pay attention before the signal becomes "
        "impossible to miss.'");
    addResponse("first conversation", "What is your responsibility?",
        "@D@He gestures toward the stalls.");
    addResponseTopic("first conversation", "What is your "
        "responsibility?", "stable wing");
    addResponse("stable wing", "How do you judge a horse?",
        "@D@Aldoran studies the animal's gait.");
    addResponseTopic("stable wing", "How do you judge a horse?",
        "horses");
}
