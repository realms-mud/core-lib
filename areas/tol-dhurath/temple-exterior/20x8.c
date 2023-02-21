//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/green-apple-stand.c", "south");
    addFeature("/lib/environment/features/water/ravine-brook.c", "north");
    addFeature("/lib/environment/features/water/gorge-creek.c", "west");

    addExit("west", "/areas/tol-dhurath/temple-exterior/19x8.c");
    addFeature("/lib/environment/features/paths/path.c", "west");

    addRandomCreature(({"gray fox","ruffian","red fox","outlaw","timber wolf"}));
}
