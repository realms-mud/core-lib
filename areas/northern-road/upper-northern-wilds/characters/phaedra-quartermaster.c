//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Phaedra outpost quartermaster");
    short("a Phaedra outpost quartermaster");
    description("The quartermaster checks road stores, signal oil, and "
        "the supplies sent between the northern posts.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("city guard", 6);
}
