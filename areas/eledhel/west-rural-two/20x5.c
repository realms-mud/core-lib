//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/hillock.c", "west");
    addFeature("/lib/environment/features/water/canyon-creek.c", "west");
    addFeature("/lib/environment/features/landforms/sinkhole.c", "west");

    addExit("north", "/areas/eledhel/west-rural-two/20x6.c");
    addFeature("/lib/environment/features/paths/path.c", "north");

    addRandomCreature(({"zombie","skunk","outlaw","opossum"}));
}
