//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Gunther Hrondil");
    short("Lord Gunther Hrondil");
    description("Lord Gunther governs the upland holding and keeps "
        "watch for trouble on the northern road.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("swordsman", 8);
}
