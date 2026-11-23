//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Estel waits a respectful "
        "distance from the entrance. @S@'I will speak when someone "
        "is free. There is no need to interrupt a lesson.'");
    addTopic("faith", "@S@'People come here for different reasons. "
        "I ask my questions quietly and leave room for other visitors.'");
    addResponse("first conversation", "Are you waiting for a knight?",
        "@D@She nods toward the temple hall.");
    addResponseTopic("first conversation", "Are you waiting for "
        "a knight?", "faith");
}
