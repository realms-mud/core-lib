//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Cyril");
    short("Cyril, the mute steward");
    description("Cyril moves between the stables and house with "
        "quiet purpose. He anticipates what is needed, keeps the "
        "supplies in order, and answers with a look or a gesture.");

    Gender("male");
    Race("human");
}
