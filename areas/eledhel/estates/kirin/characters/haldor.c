//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Haldor");
    short("Haldor, captain of Kirin's household patrol");
    description("Haldor keeps the manor patrol ready and checks the "
        "tracks along the west road.");
    Gender("male");
    Race("maegenstryd");
    SetUpPersonaOfLevel("swordsman", 8);
}
