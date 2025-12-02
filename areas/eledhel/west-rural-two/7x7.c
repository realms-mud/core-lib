//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/spruce-stand.c", "northeast");
    addFeature("/lib/environment/features/water/brook.c", "northeast");
    addFeature("/lib/environment/features/trees/hemlock-stand.c", "northeast");

    addExit("south", "/areas/eledhel/west-rural-two/7x6.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("east", "/areas/eledhel/west-rural-two/8x7.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("west", "/areas/eledhel/west-rural-two/6x7.c");
    addFeature("/lib/environment/features/paths/path.c", "west");

    addRandomCreature(({"hunter","outlaw","badger","white-tail deer"}));
}
