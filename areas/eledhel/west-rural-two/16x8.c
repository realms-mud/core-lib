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
    setShortDescription("The hollow's three-way path");
    addFeature("/lib/environment/features/landforms/hollow.c", "southeast");

    addExit("south", "/areas/eledhel/west-rural-two/16x7.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("east", "/areas/eledhel/west-rural-two/17x8.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("north", "/areas/eledhel/west-rural-two/16x9.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}
