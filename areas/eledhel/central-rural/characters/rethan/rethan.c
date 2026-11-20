//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Rethan");
    short("Rethan, keeper of the Common Measure");
    description("Rethan is a broad-handed innkeeper with a small "
        "notch through his left thumb. He keeps a slate by the door "
        "for road conditions and writes the weight of each grain "
        "delivery where both the miller and the carrier can see it.");

    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("innkeeper", 5);

    addConversation(
        "/areas/eledhel/central-rural/characters/rethan/startingConversation.c");
}
