//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail east-west");
    setShortDescription("The birch run");
    addFeature("/lib/environment/features/trees/birch-stand.c", "southeast");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "west");

    addFeature("/lib/environment/features/water/brook.c", "south");
    addExit("east", "/areas/eledhel/west-rural-two/23x1.c");
    addExit("west", "/areas/eledhel/west-rural-two/21x1.c");

    addRandomCreature(({"muskrat", "beaver", "red squirrel"}));
}
