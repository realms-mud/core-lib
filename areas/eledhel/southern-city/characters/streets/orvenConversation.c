//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Orven keeps the sealed note dry "
        "inside his coat. @S@'I have a few more stops to make.'");
    addTopic("messages", "@S@'I carry letters between shops and homes. "
        "The sender's mark stays visible until the right hand receives it.'");
    addResponse("first conversation", "Who is the message for?",
        "@D@He checks the address without opening the seal.");
    addResponseTopic("first conversation", "Who is the message for?",
        "messages");
}
