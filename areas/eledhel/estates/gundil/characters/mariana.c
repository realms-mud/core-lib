//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Mariana");
    short("Mariana of House Gundil");
    description("Mariana keeps a small book of the village's boats and "
        "their crews.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("farmer", 1);
}
