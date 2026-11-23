//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Aredec offers a measured "
        "nod. @S@'If you have a concern, state it clearly. Rank "
        "does not make a poor argument sound.'");
    addTopic("Aegis Guard", "@S@'The Aegis must know how to "
        "protect people and when not to use force. Both lessons "
        "take practice.'");
    addTopic("discipline", "@S@'A soldier should be able to "
        "question an order that violates the code. Loyalty without "
        "judgment is not honor.'");
    addResponse("first conversation", "What does the Aegis teach?",
        "@D@He rests one hand on the back of a chair.");
    addResponseTopic("first conversation", "What does the Aegis "
        "teach?", "Aegis Guard");
    addResponse("Aegis Guard", "Can a soldier challenge a superior?",
        "@D@Aredec answers without hesitation.");
    addResponseTopic("Aegis Guard", "Can a soldier challenge a "
        "superior?", "discipline");
}
