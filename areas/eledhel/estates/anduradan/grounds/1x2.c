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
    addFeature("/lib/environment/features/paths/path.c", "west");
    addObject("/areas/eledhel/estates/anduradan/characters/steward.c");

    addDecorator("village road T-north");

    addExit("north",
        "/areas/eledhel/estates/anduradan/grounds/1x1.c");
    addExit("east", "/areas/eledhel/estates/anduradan/grounds/2x2.c");
    addExit("west",
        "/areas/eledhel/estates/anduradan/grounds/0x2.c");
}
