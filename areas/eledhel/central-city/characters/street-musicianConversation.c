//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Ivran taps a quiet rhythm "
        "on the drum's rim. @S@'I leave enough space for the carts "
        "and enough music for the walkers.'");
    addTopic("street music", "@S@'A short tune suits a crossing. "
        "If I keep it simple, people can carry it with them.'");
    addResponse("first conversation", "Do you play for the street?",
        "@D@He nods toward the passing crowd.");
    addResponseTopic("first conversation", "Do you play for the "
        "street?", "street music");
}
