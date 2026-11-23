//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Alyssa");
    short("Lady Alyssa of House Gundil");
    description("Alyssa manages the household and the stores kept for "
        "the coast watch.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("farmer", 4);
}
