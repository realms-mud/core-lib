//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Aelinwen");
    short("Aelinwen Dalthren");
    description("Aelinwen watches the orchards and horse pasture of her "
        "family's northern manor.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("swordsman", 6);
}
