//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Sira wipes her hands on "
        "her apron. @S@'I have one more load to take down to the "
        "warehouse before I can call it a day.'");
    addTopic("market work", "@S@'The porters share the heavy work "
        "here. The market keeps the streets lively, but the "
        "warehouse clerks make sure nothing goes missing.'");

    addResponse("first conversation", "What do you do?",
        "@D@She nods toward the handcart outside.");
    addResponseTopic("first conversation", "What do you do?",
        "market work");
}
