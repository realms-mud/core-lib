//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Gryf");
    short("Gryf of House Gundil");
    description("Gryf watches the fishing boats from the keep yard.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("farmer", 1);
}
