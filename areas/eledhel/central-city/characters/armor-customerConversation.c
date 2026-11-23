//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Nereth turns a metal fitting "
        "between his fingers. @S@'It caught on a shield strap during "
        "inspection. I will not put it back until Barad checks it.'");
    addTopic("guard repairs", "@S@'A piece of kit can be old and still "
        "be sound. What matters is whether someone takes the time to "
        "check it before duty.'");
    addResponse("first conversation", "Why bring it to Barad?",
        "@D@He holds up the bent fastening.");
    addResponseTopic("first conversation", "Why bring it to Barad?",
        "guard repairs");
}
