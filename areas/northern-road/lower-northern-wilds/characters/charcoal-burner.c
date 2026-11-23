//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Nimwen");
    short("Nimwen, a charcoal burner");
    description("Nimwen tends a charcoal hearth in a forest clearing "
        "and warns travelers of wolf sign.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("swordsman", 4);
}
