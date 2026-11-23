//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Thalen");
    short("Thalen, captain of Hadrath Watch");
    description("Thalen studies the patrol board before sending "
        "another pair of riders down the southern lanes.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("city guard", 4);
}
