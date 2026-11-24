//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/plains.c");
    addFeature("/lib/environment/features/paths/trail.c", "north");
    addFeature("/lib/environment/features/paths/dirt-road.c", "south");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addItem("/lib/environment/items/objects/stone-pile.c", "west");
    addDecorator("village road intersection");

    addExit("south", "/areas/northern-road/minlach-approaches/22x4.c");
    addExit("north", "/areas/northern-road/minlach-approaches/22x2.c");
    addExit("east", "/areas/northern-road/minlach-approaches/23x3.c");
}
