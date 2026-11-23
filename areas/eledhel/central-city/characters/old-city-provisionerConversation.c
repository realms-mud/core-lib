//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Meleth checks a row of jars "
        "against her delivery slate. @S@'If it is for a journey, tell "
        "me how far. If it is for home, tell me how many.'");
    addTopic("provisions", "@S@'I keep food and common supplies here. "
        "The storehouses handle bulk orders; this counter is for people "
        "who need a little today.'");
    addTopic("deliveries", "@S@'The carts arrive early, before the "
        "street gets crowded. If a crate is short, I mark it before "
        "the driver leaves.'");
    addResponse("first conversation", "What can I buy here?",
        "@D@She gestures to the shelves and barrels.");
    addResponseTopic("first conversation", "What can I buy here?",
        "provisions");
    addResponse("provisions", "When do your goods arrive?",
        "@D@Meleth taps the slate beside the counter.");
    addResponseTopic("provisions", "When do your goods arrive?",
        "deliveries");
}
