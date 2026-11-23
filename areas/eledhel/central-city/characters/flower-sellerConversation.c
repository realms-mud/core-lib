//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Alwen protects a small basket "
        "from the passing carts. @S@'These last through the walk if "
        "I keep them out of the wheels.'");
    addTopic("flower baskets", "@S@'I buy from growers outside the "
        "walls and carry only what I can sell fresh. A handful is "
        "enough to brighten a room.'");
    addResponse("first conversation", "Where do the flowers come from?",
        "@D@She lifts the basket for you to see.");
    addResponseTopic("first conversation", "Where do the flowers come "
        "from?", "flower baskets");
}
