//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-clearing.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addItem("/lib/environment/items/objects/wooden-fence.c", "north");

    addDecorator("village east-west road");

    addExit("east", "/areas/eledhel/estates/kirin/grounds/0x2.c");
    addExit("west",
        "/areas/eledhel/estates/kirin/approach/second/11x0.c");
}
