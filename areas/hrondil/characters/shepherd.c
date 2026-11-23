//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Mellor");
    short("Mellor, an upland shepherd");
    description("Mellor tends the sheep folds and knows the paths "
        "through the limestone hills.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("swordsman", 2);
}
