//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/pier.c");
    setShortDescription("The harbor road turns east along the quay");
    addDecorator("village road T-east");
    addFeature("/lib/environment/features/paths/cobblestone-road.c",
        "north");
    addFeature("/lib/environment/features/paths/cobblestone-road.c",
        "south");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("north", "/areas/anor/12x5.c");
    addExit("south", "/areas/anor/12x7.c");
    addExit("east", "/areas/anor/13x6.c");
}
