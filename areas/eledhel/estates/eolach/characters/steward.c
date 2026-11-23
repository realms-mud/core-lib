//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Eolach steward");
    short("the steward of Eolach Keep");
    description("The steward keeps the farm accounts and arranges "
        "supplies for the fortress.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("swordsman", 2);
}
