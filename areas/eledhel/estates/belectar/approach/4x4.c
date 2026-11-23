//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addItem("/lib/environment/items/objects/wooden-fence.c", "north");

    addDecorator("village east-west road");

    addExit("east", "/areas/eledhel/estates/belectar/approach/5x4.c");
    addExit("west", "/areas/eledhel/estates/belectar/approach/3x4.c");
}
