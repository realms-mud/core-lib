//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Merron");
    short("Merron, a hill-country crofter");
    description("Merron tends a small upland holding and trades "
        "news with passing carters.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("swordsman", 2);
}
