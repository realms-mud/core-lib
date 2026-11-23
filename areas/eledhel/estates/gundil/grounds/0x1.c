//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-clearing.c");

    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "south");

    addDecorator("village road T-east");

    addExit("north", "/areas/eledhel/estates/gundil/grounds/0x0.c");
    addExit("east", "/areas/eledhel/estates/belectar/approach/0x0.c");
    addExit("south",
        "/areas/eledhel/estates/gundil/grounds/0x2.c");
}
