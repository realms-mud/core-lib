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
    addObject("/areas/eledhel/estates/eolach/characters/archer.c");

    addDecorator("village road T-north");

    addExit("north", "/areas/eledhel/estates/eolach/grounds/1x1.c");
    addExit("east", "/areas/eledhel/estates/eolach/grounds/2x2.c");
    addExit("west", "/areas/eledhel/estates/eolach/grounds/0x2.c");
}
