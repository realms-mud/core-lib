//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Maren");
    short("Maren, keeper of the Aladain stable");
    description("Maren checks the girths and hooves before a horse "
        "is led from its stall. A row of fresh marks on the tack "
        "board records the next journeys.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("farmer", 3);
}
