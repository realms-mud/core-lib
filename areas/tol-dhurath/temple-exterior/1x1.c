//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/hillock.c", "north");
    addFeature("/lib/environment/features/trees/willow-stand.c", "southeast");
    addFeature("/lib/environment/features/trees/apple-stand.c", "south");

    addExit("north", "/areas/tol-dhurath/temple-exterior/1x2.c");
    addFeature("/lib/environment/features/paths/path.c", "north");

    addRandomCreature(({"outlaw","boar","white-tail deer"}));
}
