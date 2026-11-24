//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/keep.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addItem("/lib/environment/items/objects/water-trough.c", "north");
    addItem("/lib/environment/items/military/supply-crate.c", "south");
    addDecorator("village keep wall");

    addExit("west", "/areas/northern-road/minlach-approaches/12x2.c");
}
