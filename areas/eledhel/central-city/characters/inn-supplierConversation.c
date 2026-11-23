//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Keldan keeps the delivery "
        "under a clean cloth. @S@'The innkeeper asked for it intact. "
        "I will wait until the door is free.'");
    addTopic("deliveries", "@S@'I bring small orders to the houses "
        "on this lane. If there is a problem, I would rather hear "
        "about it before the next load.'");
    addResponse("first conversation", "What are you delivering?",
        "@D@He checks the knot on the cloth.");
    addResponseTopic("first conversation", "What are you delivering?",
        "deliveries");
}
