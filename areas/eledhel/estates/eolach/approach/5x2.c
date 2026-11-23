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
    addFeature("/lib/environment/features/plants/rye-field.c",
        "north");
    addItem("/lib/environment/items/objects/scarecrow.c", "south");
    addItem("/lib/environment/items/objects/wooden-fence.c", "west");

    addDecorator("village east-west road");

    addExit("east", "/areas/eledhel/estates/eolach/approach/6x2.c");
    addExit("west", "/areas/eledhel/estates/eolach/approach/4x2.c");
}
