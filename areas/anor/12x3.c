//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    setShortDescription("Stone paving leads toward the harbor");
    addDecorator("village road T-west");
    addFeature("/lib/environment/features/paths/cobblestone-road.c",
        "north");
    addFeature("/lib/environment/features/paths/cobblestone-road.c",
        "south");
    addExit("north", "/areas/anor/12x2.c");
    addExit("south", "/areas/anor/12x4.c");
    addExit("west", "/areas/anor/11x3.c");
}
