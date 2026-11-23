//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Gruffyd");
    short("Lord Gruffyd of House Gundil");
    description("Gruffyd keeps the household watch over the sea road "
        "and the dolomite cliffs.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("swordsman", 8);
}
