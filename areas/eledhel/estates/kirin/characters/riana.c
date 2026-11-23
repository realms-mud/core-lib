//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Riana");
    short("Lady Riana Kirin");
    description("Riana oversees the manor household and sees that the "
        "workers' families are supplied.");
    Gender("female");
    Race("maegenstryd");
    SetUpPersonaOfLevel("swordsman", 1);
}
