//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Harumel");
    short("Harumel Belathon");
    description("A tall Belathon archer bows with elaborate courtesy "
        "and watches the household doors.");
    Gender("male");
    Race("maegenstryd");
    SetUpPersonaOfLevel("archer", 4);
}
