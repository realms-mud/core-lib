//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Dana");
    short("Dana, member of Kirin's household");
    description("Dana helps manage the workers' cottages and stores "
        "along the west road.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("farmer", 2);
}
