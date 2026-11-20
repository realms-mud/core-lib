//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Vargath");
    addAlias("Vargoth");
    short("Vargath, arms dealer and mine-lord");
    description("Vargath watches his audience with a brutal, "
        "posturing confidence. Iron orders, guarded mines and threats "
        "against his workers have made his fortune.");

    Gender("male");
    Race("human");
}
