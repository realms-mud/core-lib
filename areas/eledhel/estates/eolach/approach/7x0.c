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
    addFeature("/lib/environment/features/plants/oat-field.c",
        "north");
    addFeature("/lib/environment/features/trees/ash-stand.c", "south");
    addItem("/lib/environment/items/objects/boundary-stone.c", "southeast");

    addDecorator("village east-west road");

    addExit("east", "/areas/eledhel/estates/eolach/approach/8x0.c");
    addExit("west", "/areas/eledhel/estates/eolach/approach/6x0.c");
}
