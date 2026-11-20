//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Meral");
    short("Meral, keeper of the orchard rows");
    description("Meral keeps a narrow chalk tally of every basket "
        "that leaves the cultivated rows. Soil darkens the seams "
        "of her sleeves, and she checks each gate-latch before "
        "turning to speak.");

    Gender("female");
    Race("human");

    addConversation(
        "/areas/eledhel/west-rural/characters/meral/startingConversation.c");
}
