//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/plains.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addItem("/lib/environment/items/objects/boundary-stone.c", "north");
    addFeature("/lib/environment/features/plants/barley-field.c", "south");
    addFeature("/lib/environment/features/trees/oak-stand.c", "east");
    addItem("/lib/environment/items/objects/wooden-fence.c", "southeast");

    addDecorator("village east-west road");

    addExit("east", "/areas/eledhel/estates/eolach/grounds/0x0.c");
    addExit("west", "/areas/eledhel/estates/eolach/approach/7x2.c");
}
