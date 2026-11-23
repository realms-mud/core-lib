//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Raeth checks the wax seal "
        "without breaking it. @S@'It is for the hall. I will hand "
        "it to the officer on duty.'");
    addTopic("Aegis messages", "@S@'I carry routine dispatches "
        "between the city offices and the guard. The seal tells "
        "the receiver where it belongs.'");
    addResponse("first conversation", "What are you carrying?",
        "@D@He keeps one hand over the sealed case.");
    addResponseTopic("first conversation", "What are you carrying?",
        "Aegis messages");
}
