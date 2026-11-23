//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Gwaeron");
    short("Gwaeron, road warden of Anduradan");
    description("Gwaeron patrols the boundary ditches and reports "
        "trouble on the manor road.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("swordsman", 2);
}
