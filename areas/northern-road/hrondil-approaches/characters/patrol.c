//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Cerdan");
    short("Cerdan, a northern road patrolman");
    description("Cerdan rides the upland road and watches the ridges "
        "for raiders.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("swordsman", 4);
}
