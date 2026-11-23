//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Veler wraps a small tool head "
        "in leather. @S@'The edge is ready for the forge.'");
    addTopic("forge orders", "@S@'The smith marks each order before "
        "heating the metal. That keeps the finished tools together.'");
    addResponse("first conversation", "What is the tool for?",
        "@D@He checks the wrapping.");
    addResponseTopic("first conversation", "What is the tool for?",
        "forge orders");
}
