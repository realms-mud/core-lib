//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Wethen wipes chalk from "
        "the edge of his slate. @S@'The figures are easier to check "
        "before the carts begin arriving.'");
    addTopic("ledgers", "@S@'I copy the counts after a load is "
        "received. If the numbers disagree, someone checks the goods "
        "before the book is closed.'");
    addResponse("first conversation", "What do you record?",
        "@D@He turns the slate so its marks face away.");
    addResponseTopic("first conversation", "What do you record?",
        "ledgers");
}
