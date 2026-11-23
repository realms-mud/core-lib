//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Haldren");
    short("Haldren, cliff watch of Gundil");
    description("Haldren watches the cliff steps and warns visitors when "
        "the sea is rough.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("swordsman", 3);
}
