//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addFeature("/lib/environment/features/water/stream.c", "south");
    addItem("/lib/environment/items/objects/water-trough.c", "east");
    addItem("/lib/environment/items/objects/sack-pile.c", "north");
    addDecorator("village road corner SW");

    addExit("west", "/areas/northern-road/minlach-approaches/18x5.c");
    addExit("south", "/areas/northern-road/minlach-approaches/19x6.c");
}
