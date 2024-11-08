//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/mound.c", "southeast");
    addFeature("/lib/environment/features/landforms/valley.c", "northeast");

    addExit("north", "/areas/tol-dhurath/forest-3/4x5.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("south", "/areas/tol-dhurath/forest-3/4x3.c");
    addFeature("/lib/environment/features/paths/path.c", "south");

    addRandomCreature(({"ruffian","red fox","outlaw","white-tail deer"}));
}
