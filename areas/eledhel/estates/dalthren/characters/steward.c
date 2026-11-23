//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Daeron");
    short("Daeron, steward of House Dalthren");
    description("Daeron keeps the orchard accounts and oversees the "
        "household's horses.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("farmer", 2);
}
