//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");

    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "south");

    addDecorator("village road T-east");

    addExit("north",
        "/areas/eledhel/estates/anduradan/grounds/0x1.c");
    addExit("east", "/areas/eledhel/estates/anduradan/grounds/1x2.c");
    addExit("south", "/areas/northern-road/northern-manor/3x4.c");
}
