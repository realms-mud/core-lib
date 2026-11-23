//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Haldreth");
    short("Haldreth, Belathon's carter");
    description("The house carter checks his wagon and the goods brought "
        "through the outer ward.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("swordsman", 2);
}
