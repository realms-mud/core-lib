//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    setShortDescription("The guarded quay below the naval headquarters");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "north");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "east");
    addDecorator("path");
    addObject("/areas/eledhel/northern-city/characters/dock-sentinel.c");
    addExit("north", "/areas/eledhel/northern-city/23x8.c");
    addExit("east", "/areas/eledhel/northern-city/24x7.c");
}
