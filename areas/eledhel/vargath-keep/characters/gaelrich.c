//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Gaelrich");
    short("Gaelrich, Vargath's lieutenant");
    description("Gaelrich stands close to Vargath, keeping watch over "
        "the audience chamber and its guarded exits.");

    Gender("male");
    Race("human");
}
