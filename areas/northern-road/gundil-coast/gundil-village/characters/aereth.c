//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Aereth");
    short("Aereth, Gundil fisher");
    description("Aereth cleans the day's catch beside the landing and "
        "knows the safe gaps between the reefs.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("fisher", 3);
}
