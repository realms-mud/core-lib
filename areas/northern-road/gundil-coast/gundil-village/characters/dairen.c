//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Dairen");
    short("Dairen, keeper of the cliff steps");
    description("Dairen checks the sea steps before allowing anyone down "
        "to the water.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("swordsman", 3);
}
