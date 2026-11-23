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
    addFeature("/lib/environment/features/paths/path.c", "west");
    addItem("/lib/environment/items/objects/hitching-post.c", "north");

    addDecorator("village road intersection");

    addExit("north", "/areas/eledhel/estates/kirin/grounds/1x0.c");
    addExit("east", "/areas/eledhel/estates/kirin/grounds/2x1.c");
    addExit("south", "/areas/eledhel/estates/kirin/grounds/1x2.c");
    addExit("west", "/areas/eledhel/estates/kirin/grounds/0x1.c");
}
