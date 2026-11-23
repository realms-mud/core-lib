//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Calendir");
    short("Calendir, a ridge scout");
    description("Calendir patrols the stony northern ridges and keeps "
        "watch for raiders.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("archer", 6);
}
