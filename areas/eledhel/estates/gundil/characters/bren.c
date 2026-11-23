//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Bren");
    short("Bren of House Gundil");
    description("Bren is learning the names of the sea lanes and cliffs.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("farmer", 1);
}
