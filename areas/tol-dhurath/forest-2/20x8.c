//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/combe.c", "northeast");
    addFeature("/lib/environment/features/landforms/butte.c", "northeast");

    addExit("south", "/areas/tol-dhurath/forest-2/20x7.c");
    addFeature("/lib/environment/features/paths/path.c", "south");

    addRandomCreature(({"ruffian","hunter","coyote","outlaw","timber wolf","white-tail deer"}));
}
