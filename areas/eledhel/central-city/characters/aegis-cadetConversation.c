//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@The cadet resets her stance "
        "and begins the drill again. @S@'A clean movement is worth "
        "more than a fast one done badly.'");
    addTopic("training", "@S@'We practice the same guard until "
        "it holds under pressure. Then the instructor changes the "
        "exercise and we learn what we missed.'");

    addResponse("first conversation", "How long have you trained?",
        "@S@'Long enough to know that every correction matters. "
        "The academy does not promise a short path.'");
    addResponse("first conversation", "What are you practicing?",
        "@D@She points to the practice dummy.");
    addResponseTopic("first conversation", "What are you practicing?",
        "training");
    addResponse("training", "Can I use the practice equipment?",
        "@S@'Ask the instructor first. A weapon rack is not a "
        "public armory.'");
}
