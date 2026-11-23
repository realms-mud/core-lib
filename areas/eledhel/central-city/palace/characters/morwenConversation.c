//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Morwen looks up from the "
        "window seat. @S@'If you have come to discuss court manners, "
        "I warn you that I am a difficult student.'");
    addTopic("diplomacy", "@S@'A treaty is not a victory if no "
        "one can live with its terms. Listening is slower than "
        "giving orders, but it is often more useful.'");
    addTopic("court", "@S@'The court prefers ceremony. I prefer "
        "a clear answer and a chair that does not require a dozen "
        "rules for sitting in it.'");
    addResponse("first conversation", "What matters in diplomacy?",
        "@D@Her teasing expression gives way to careful attention.");
    addResponseTopic("first conversation", "What matters in "
        "diplomacy?", "diplomacy");
    addResponse("diplomacy", "Do you enjoy court life?",
        "@D@She glances toward the formal rooms.");
    addResponseTopic("diplomacy", "Do you enjoy court life?", "court");
}
