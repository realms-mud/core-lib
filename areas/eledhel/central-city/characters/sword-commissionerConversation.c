//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Gethen counts the coins in his "
        "palm, then looks toward the forge. @S@'Not enough for a rushed "
        "order, and I will not ask Tirwen to spoil the work.'");
    addTopic("commission", "@S@'My route takes me through wet roads and "
        "crowded gates. I need a plain blade that can be mended, not a "
        "showpiece that frightens every porter.'");
    addResponse("first conversation", "What are you waiting for?",
        "@D@He closes his hand around the coins.");
    addResponseTopic("first conversation", "What are you waiting for?",
        "commission");
}
