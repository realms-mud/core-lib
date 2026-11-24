//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/plains.c");
    addFeature("/lib/environment/features/paths/gravel-road.c", "north");
    addFeature("/lib/environment/features/paths/dirt-road.c", "south");
    addFeature("/lib/environment/features/landforms/knoll.c", "west");
    addItem("/lib/environment/items/objects/signPost.c", "east");
    addDecorator("village north-south road");

    addExit("south", "/areas/northern-road/minlach-approaches/12x4.c");
    addExit("north", "/areas/northern-road/minlach-approaches/12x2.c");
}
