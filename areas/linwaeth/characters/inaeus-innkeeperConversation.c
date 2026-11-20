//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@S@'Welcome to the Looming Stag. "
        "My family has kept this house open for generations. Come in "
        "out of the road and tell me what brings you to Linwaeth.'");
    addTopic("the south road", "@S@'The King's Road continues south "
        "through open country. The old caravan ground lies beyond "
        "the fields; keep to the marked road and report trouble here.'");
    addResponse("first conversation", "Who keeps the forge?",
        "@S@'Johan the Elder works the smithy east of the square. "
        "He knows the town's tools and the old road better than most.'");
    addResponse("first conversation", "What lies south of town?",
        "@S@'Fields first, then the old caravan ground. Some people "
        "live apart from the town there. Do not mistake hardship "
        "for guilt.'");
    addResponseTopic("first conversation", "What lies south of town?",
        "the south road");
}
