//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Kirin");
    short("General Kirin, lord of the manor");
    description("Kirin commands the 1st Division and keeps his household "
        "ready to support the northern road.");
    Gender("male");
    Race("maegenstryd");
    SetUpPersonaOfLevel("swordsman", 15);
}
