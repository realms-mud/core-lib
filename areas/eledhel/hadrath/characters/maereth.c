//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Maereth");
    short("Maereth, keeper of the north barley fields");
    description("Maereth watches the furrows and the distant road "
        "with the same steady attention.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("farmer", 3);
}
