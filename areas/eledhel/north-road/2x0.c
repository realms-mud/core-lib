//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addDecorator("forest trail north-south");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "south");
    setShortDescription("The northern road leaves the city behind");

    addExit("south", "/areas/eledhel/northern-city/12x9.c");
    addExit("north", "/areas/eledhel/north-road/2x1.c");
}
