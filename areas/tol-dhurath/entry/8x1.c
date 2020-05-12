//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/sycamore-stand.c", "southeast");
    addFeature("/lib/environment/features/landforms/crag.c", "southeast");

    addExit("south", "/areas/tol-dhurath/entry/8x0.c");
    addFeature("/lib/environment/features/paths/path.c", "south");

    addRandomCreature(({"ruffian","zombie","warg","keeper of the night","skeleton","timber wolf"}));
}
