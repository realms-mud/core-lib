//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Peryn checks the marks on a "
        "cloth sample. @S@'The order is cut from this bolt.'");
    addTopic("cloth orders", "@S@'The weaver keeps the pattern and "
        "length on the slate. That prevents a short measure at delivery.'");
    addResponse("first conversation", "How are the orders measured?",
        "@D@She points to the written tally.");
    addResponseTopic("first conversation", "How are the orders measured?",
        "cloth orders");
}
