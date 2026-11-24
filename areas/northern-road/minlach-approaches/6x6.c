//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-clearing.c");
    addFeature("/lib/environment/features/water/stream.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addFeature("/lib/environment/features/trees/willow-stand.c", "south");
    addItem("/lib/environment/items/objects/stone-pile.c", "west");
    addDecorator("village road corner NE");

    addExit("north", "/areas/northern-road/minlach-approaches/6x5.c");
    addExit("east", "/areas/northern-road/minlach-approaches/7x6.c");
}
