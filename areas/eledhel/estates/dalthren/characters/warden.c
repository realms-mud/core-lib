//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Eldrin");
    short("Eldrin, road warden of Dalthren");
    description("Eldrin rides the boundary and warns travelers away from "
        "the disputed pasture.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("swordsman", 3);
}
