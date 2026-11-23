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
    addItem("/lib/environment/items/objects/boundary-stone.c", "southwest");
    addFeature("/lib/environment/features/plants/rye-field.c", "north");
    addFeature("/lib/environment/features/water/field-drain.c", "southeast");

    addDecorator("village east-west road");

    addExit("east", "/areas/eledhel/estates/eolach/approach/3x2.c");
    addExit("west", "/areas/eledhel/estates/eolach/approach/1x2.c");
}
