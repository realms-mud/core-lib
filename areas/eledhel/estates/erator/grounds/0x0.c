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

    addExit("north", "/areas/northern-road/north-gate/9x9.c");
    addExit("east", "/areas/eledhel/estates/erator/grounds/1x0.c");
    addExit("south", "/areas/eledhel/estates/erator/grounds/0x1.c");
}
