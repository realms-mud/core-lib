//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@The guard keeps her post "
        "without blocking the passage. @S@'Visitors should check "
        "with Sendral before entering the household rooms.'");
    addTopic("visitors", "@S@'The public reception rooms are ahead. "
        "The private wings are for household business and are "
        "kept under watch.'");
    addTopic("the guard", "@S@'My duty is to keep the passage clear "
        "and make sure guests know where they may go.'");

    addResponse("first conversation", "Where can visitors go?",
        "@D@You glance toward the palace doors.");
    addResponseTopic("first conversation", "Where can visitors go?",
        "visitors");
    addResponse("first conversation", "Can you let me into the private wing?",
        "@S@'No. Speak to the castellan if you have business "
        "that belongs there.'");
    addResponseTopic("first conversation",
        "Can you let me into the private wing?", "the guard");
    addResponse("visitors", "Where is the castellan?",
        "@S@'Sendral is in the household passage near the gate.'");
}
