//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Mavren");
    short("Mavren, a carter buying a winter cloak");
    description("Mavren checks the seams of a thick cloak before "
        "taking another wagon north.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("grocer", 3);
    addConversation(
        "/areas/eledhel/central-city/characters/furrier-customerConversation.c");
}
