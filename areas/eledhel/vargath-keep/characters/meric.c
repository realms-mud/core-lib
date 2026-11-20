//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Meric");
    short("Meric, a Knight of the Storm");
    description("Meric watches the room with a trained soldier's "
        "attention, his black armour marking him as a Knight of the Storm.");

    Gender("male");
    Race("human");
}
