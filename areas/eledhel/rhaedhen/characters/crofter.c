//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Calendir");
    short("Calendir, a crofter of Rhaedhen");
    description("Calendir tends a narrow strip of vegetables and keeps "
        "a few goats for milk.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("farmer", 2);
}
