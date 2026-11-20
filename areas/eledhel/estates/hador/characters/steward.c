//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Haldren");
    short("Haldren, steward of House Hador");
    description("Haldren keeps the drove accounts and arranges fodder "
        "and remounts for travelers.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("farmer", 3);
}
