//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Mereneth");
    short("Mereneth, keeper of the garden ditch");
    description("Mereneth checks the sluice and clears silt from the "
        "market-garden channels.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("farmer", 2);
}
