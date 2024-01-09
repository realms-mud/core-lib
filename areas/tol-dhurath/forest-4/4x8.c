//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/poplar-stand.c", "southeast");
    addFeature("/lib/environment/features/water/canyon-creek.c", "southeast");
    addFeature("/lib/environment/features/landforms/glen.c", "southeast");

    addExit("west", "/areas/tol-dhurath/forest-4/3x8.c");
    addFeature("/lib/environment/features/paths/path.c", "west");

    addRandomCreature(({"ruffian","gray fox","coyote","timber wolf","red wolf"}));
}
