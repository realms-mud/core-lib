//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addItem("/lib/environment/items/objects/sack-pile.c", "north");
    addItem("/lib/environment/items/objects/wooden-fence.c", "west");
    addDecorator("village road T-south");

    addExit("west", "/areas/northern-road/minlach-approaches/4x4.c");
    addExit("east", "/areas/northern-road/minlach-approaches/6x4.c");
    addExit("south", "/areas/northern-road/minlach-approaches/5x5.c");
}
