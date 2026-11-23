//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Daereth");
    short("Daereth, keeper of the alder ditch");
    description("Daereth checks the sluice stones and clears the drainage "
        "cut after heavy rain.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("farmer", 3);
}
