//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Eolach archer");
    short("an archer of Eolach Keep");
    description("A northern archer keeps watch over the gate and "
        "surrounding farms.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("archer", 4);
}
