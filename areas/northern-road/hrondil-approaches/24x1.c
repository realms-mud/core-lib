//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/plains.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "north");
    addFeature("/lib/environment/features/paths/dirt-road.c", "south");
    addFeature("/lib/environment/features/trees/alder-stand.c", "east");
    addItem("/lib/environment/items/objects/boundary-stone.c", "west");

    addDecorator("village north-south road");

    addExit("north", "/areas/northern-road/hrondil-approaches/24x0.c");
    addExit("south", "/areas/northern-road/hrondil-approaches/24x2.c");
}
