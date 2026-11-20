//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Maereth");
    short("Maereth, steward of House Urdhan");
    description("Maereth keeps the grain accounts and oversees repairs "
        "to the estate mill.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("farmer", 3);
}
