//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/tor.c", "northeast");
    addFeature("/lib/environment/features/landforms/hollow.c", "northeast");
    addFeature("/lib/environment/features/landforms/sinkhole.c", "northeast");

    addExit("west", "/areas/tol-dhurath/forest-5/3x5.c");
    addFeature("/lib/environment/features/paths/path.c", "west");

    addRandomCreature(({"skunk","porcupine","coyote","outlaw","white-tail deer","opossum"}));
}
