//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Marel looks up from the "
        "common-room tables. @S@'Welcome to the Golden Flask. "
        "Travelers can find a warm meal and a place to rest here.'");
    addTopic("the inn", "@S@'The kitchen is through the east door. "
        "The guest passage is to the south. Ask before taking "
        "anything from the household stores.'");
    addTopic("the city", "@S@'The palace stands east of the plaza. "
        "The Aegis and Werric houses are reached by the streets "
        "to the west and north.'");

    addResponse("first conversation", "Can I get food here?",
        "@D@Marel nods toward the counter.");
    addResponse("first conversation", "Where are the guest rooms?",
        "@S@'Take the passage to the south. I can tell you what "
        "is available before you settle in.'");
    addResponseTopic("first conversation",
        "Where are the guest rooms?", "the inn");
    addResponse("first conversation", "What is nearby?",
        "@D@She points through the door toward the plaza.");
    addResponseTopic("first conversation", "What is nearby?", "the city");
}
