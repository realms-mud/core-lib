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
    addItem("/lib/environment/items/objects/scarecrow.c", "south");
    addFeature("/lib/environment/features/plants/rye-field.c", "north");
    addFeature("/lib/environment/features/water/field-drain.c", "southwest");
    addItem("/lib/environment/items/objects/wooden-fence.c", "southeast");

    addDecorator("village east-west road");

    addExit("east", "/areas/eledhel/estates/eolach/approach/7x0.c");
    addExit("west", "/areas/eledhel/estates/eolach/approach/5x0.c");
}
