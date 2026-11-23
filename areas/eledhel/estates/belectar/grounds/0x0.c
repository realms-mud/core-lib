//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");

    addFeature("/lib/environment/features/paths/path.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addFeature("/lib/environment/features/paths/path.c", "west");

    addDecorator("village road T-south");

    addExit("east", "/areas/eledhel/estates/belectar/grounds/1x0.c");
    addExit("south",
        "/areas/eledhel/estates/belectar/grounds/0x1.c");
    addExit("west",
        "/areas/eledhel/estates/belectar/approach/6x4.c");
}
