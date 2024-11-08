//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/ravine-brook.c", "south");
    addFeature("/lib/environment/features/water/gorge-creek.c", "north");

    addExit("east", "/areas/tol-dhurath/forest-3/10x0.c");
    addFeature("/lib/environment/features/paths/path.c", "east");

    addRandomCreature(({"ruffian","red fox","outlaw"}));
}
