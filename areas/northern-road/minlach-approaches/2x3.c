//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    addFeature("/lib/environment/features/paths/trail.c", "north");
    addFeature("/lib/environment/features/paths/dirt-road.c", "south");
    addFeature("/lib/environment/features/water/field-drain.c", "west");
    addDecorator("village north-south road");

    addExit("south", "/areas/northern-road/minlach-approaches/2x4.c");
    addExit("north", "/areas/northern-road/minlach-approaches/2x2.c");
}
