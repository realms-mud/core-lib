//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Calwen");
    short("Calwen, keeper of the sea inn");
    description("Calwen remembers every crew that has put in at Gundil "
        "after a storm.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("farmer", 2);
}
