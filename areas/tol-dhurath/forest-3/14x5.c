//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/hollow.c", "southeast");
    addFeature("/lib/environment/features/water/rocky-lake-shore.c", "west");
    addFeature("/lib/environment/features/landforms/valley.c", "north");

    addExit("west", "/areas/tol-dhurath/forest-3/13x5.c");
    addFeature("/lib/environment/features/paths/path.c", "west");

    addRandomCreature(({"boar","ruffian"}));
}
