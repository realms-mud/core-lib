//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "north");
    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addFeature("/lib/environment/features/trees/apple-stand.c", "northeast");
    addFeature("/lib/environment/features/trees/pear-stand.c", "southwest");
    addItem("/lib/environment/items/objects/signPost.c", "northwest");
    addItem("/lib/environment/items/objects/wooden-fence.c", "southeast");

    addDecorator("village road T-north");

    addExit("north", "/areas/eledhel/estates/anduradan/grounds/0x2.c");
    addExit("east", "/areas/northern-road/northern-manor/4x4.c");
    addExit("west", "/areas/northern-road/northern-manor/2x4.c");
}
