//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Nethor");
    short("Nethor, steward of House Belectar");
    description("Nethor records the barley harvest and the brewery's "
        "deliveries.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("farmer", 3);
}
