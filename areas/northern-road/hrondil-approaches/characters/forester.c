//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Iarwen");
    short("Iarwen, a northern forester");
    description("Iarwen marks safe paths through the alder wood and "
        "keeps watch for wolves.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("archer", 3);
}
