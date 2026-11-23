//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Balechor");
    short("Lord Balechor of Eolach");
    description("The lord of Eolach receives reports with measured "
        "courtesy and expects them to be precise.");
    Gender("male");
    Race("maegenstryd");
    SetUpPersonaOfLevel("swordsman", 8);
}
