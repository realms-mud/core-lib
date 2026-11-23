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
    addFeature("/lib/environment/features/paths/path.c", "west");

    addDecorator("village road T-north");

    addExit("north",
        "/areas/eledhel/estates/gundil/grounds/1x1.c");
    addExit("east", "/areas/eledhel/estates/gundil/grounds/2x2.c");
    addExit("west",
        "/areas/eledhel/estates/gundil/grounds/0x2.c");
}
