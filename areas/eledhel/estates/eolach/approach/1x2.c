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
    addFeature("/lib/environment/features/plants/common-pulse-rows.c",
        "south");
    addFeature("/lib/environment/features/plants/oat-field.c", "north");
    addFeature("/lib/environment/features/water/field-drain.c", "northwest");
    addItem("/lib/environment/items/objects/wooden-fence.c", "east");

    addDecorator("village east-west road");

    addExit("east", "/areas/eledhel/estates/eolach/approach/2x2.c");
    addExit("west", "/areas/eledhel/estates/eolach/approach/0x2.c");
}
