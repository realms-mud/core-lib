//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");

    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addItem("/lib/environment/items/objects/wooden-fence.c", "south");

    addDecorator("village road corner NW");

    addExit("north", "/areas/eledhel/estates/belectar/grounds/2x1.c");
    addExit("west", "/areas/eledhel/estates/belectar/grounds/1x2.c");
}
