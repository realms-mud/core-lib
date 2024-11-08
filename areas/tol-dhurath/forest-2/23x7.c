//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/fir-stand.c", "north");
    addFeature("/lib/environment/features/water/brook.c", "northwest");

    addExit("south", "/areas/tol-dhurath/forest-2/23x6.c");
    addFeature("/lib/environment/features/paths/path.c", "south");

    addRandomCreature(({"ruffian","white-tail deer","red fox"}));
}
