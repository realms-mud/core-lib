//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/promontory.c", "south");
    addFeature("/lib/environment/features/water/ravine-creek.c", "southeast");
    addFeature("/lib/environment/features/landforms/hill.c", "west");

    addExit("west", "/areas/tol-dhurath/entry/1x7.c");
    addFeature("/lib/environment/features/paths/path.c", "west");

    addRandomCreature(({"ruffian","red fox","white-tail deer"}));
}
