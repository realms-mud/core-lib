//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/chokecherry-stand.c", "west");
    addFeature("/lib/environment/features/landforms/knoll.c", "northeast");
    addFeature("/lib/environment/features/water/canyon-dry-bed.c", "northwest");

    addExit("south", "/areas/tol-dhurath/forest-1/22x6.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("north", "/areas/tol-dhurath/forest-1/22x8.c");
    addFeature("/lib/environment/features/paths/path.c", "north");

    addRandomCreature(({"beaver","hunter","kit fox"}));
}
