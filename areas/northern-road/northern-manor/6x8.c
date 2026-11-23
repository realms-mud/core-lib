//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/plains.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "north");
    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addFeature("/lib/environment/features/trees/apple-stand.c", "northeast");
    addFeature("/lib/environment/features/plants/blackberry-bramble.c",
        "southwest");
    addItem("/lib/environment/items/objects/signPost.c", "southeast");

    addDecorator("village road T-north");

    addExit("north", "/areas/eledhel/estates/dalthren/grounds/0x2.c");
    addExit("east", "/areas/northern-road/northern-manor/7x8.c");
    addExit("west", "/areas/northern-road/northern-manor/5x8.c");
}
