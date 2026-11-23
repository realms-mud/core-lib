//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Maerwen");
    short("Maerwen, market gardener");
    description("Maerwen tends the city-facing plots and notes which carts "
        "take the north road.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("farmer", 2);
}
