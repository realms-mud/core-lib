//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    setShortDescription("The central street descends toward the quay");
    addDecorator("village north-south road");
    addFeature("/lib/environment/features/paths/cobblestone-road.c",
        "north");
    addFeature("/lib/environment/features/paths/cobblestone-road.c",
        "south");
    addExit("north", "/areas/anor/12x3.c");
    addExit("south", "/areas/anor/12x5.c");
}
