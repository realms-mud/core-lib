//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Elaron");
    short("Elaron, a northern ranger");
    description("Elaron watches the treeline and marks safe passages "
        "through the wilds.");
    Gender("male");
    Race("elf");
    SetUpPersonaOfLevel("archer", 5);
}
