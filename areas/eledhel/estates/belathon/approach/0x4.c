//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");

    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "south");

    addDecorator("village north-south road");

    addExit("north",
        "/areas/eledhel/estates/belathon/approach/0x5.c");
    addExit("south",
        "/areas/eledhel/estates/belathon/approach/0x3.c");
}
