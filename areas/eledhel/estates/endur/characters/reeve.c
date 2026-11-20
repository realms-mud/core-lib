//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Endrath");
    short("Endrath, reeve of House Endur");
    description("Endrath keeps the cattle tallies and settles questions "
        "between the estate's herders.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("farmer", 3);
}
