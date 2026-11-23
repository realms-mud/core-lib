//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Calven checks the bunghole "
        "on a cider cask. @S@'The batch is settling. I have "
        "produce and roots on the counter while it rests.'");
    addTopic("cider", "@S@'The best cider starts with sound fruit "
        "and a clean cask. I sell the household stores as well; "
        "not everyone has time to visit the market.'");
    addTopic("fruit", "@S@'Much of the fruit comes from farms "
        "south of the city. I pay fairly for ripe apples and "
        "send the damaged ones to the press.'");

    addResponse("first conversation", "What are you brewing?",
        "@D@He pats the side of the cask.");
    addResponseTopic("first conversation", "What are you brewing?",
        "cider");
    addResponse("first conversation", "Where do you get the fruit?",
        "@D@Calven points south along the avenue.");
    addResponseTopic("first conversation",
        "Where do you get the fruit?", "fruit");
}
