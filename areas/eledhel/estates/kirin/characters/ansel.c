//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Ansel");
    short("Ansel, Haldor's personal Aegis");
    description("Ansel keeps a close watch on the manor road and the "
        "movements around Kirin's household.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("swordsman", 6);
}
