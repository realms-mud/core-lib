//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail T-east");
    setShortDescription("The twin-brook ford");
    addFeature("/lib/environment/features/water/brook.c", "southeast");
    addFeature("/lib/environment/features/water/creek.c", "southeast");

    addExit("south", "/areas/eledhel/west-rural-two/24x3.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("north", "/areas/eledhel/west-rural-two/24x5.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("east", "/areas/evenholt/grounds/0x4.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}
