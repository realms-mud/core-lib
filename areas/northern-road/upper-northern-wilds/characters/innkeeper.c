//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Mira");
    short("Mira, keeper of the Windward Inn");
    description("Mira keeps a warm room for travelers and listens for "
        "news from the Minlach road and the northern coast.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("innkeeper", 5);
}
