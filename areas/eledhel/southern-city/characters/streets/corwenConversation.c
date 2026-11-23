//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Corwen turns his travel pack "
        "around. @S@'I am looking for the road to the harbor.'");
    addTopic("harbor road", "@S@'The route runs past the workshops. "
        "Keep to the broad lane and it will bring you down to the quays.'");
    addResponse("first conversation", "Can you find the harbor road?",
        "@D@He studies the street signs.");
    addResponseTopic("first conversation", "Can you find the harbor road?",
        "harbor road");
}
