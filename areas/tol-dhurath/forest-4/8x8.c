//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/brook.c", "northwest");
    addFeature("/lib/environment/features/landforms/hollow.c", "northwest");
    addFeature("/lib/environment/features/trees/fir-stand.c", "northwest");

    addExit("south", "/areas/tol-dhurath/forest-4/8x7.c");
    addFeature("/lib/environment/features/paths/path.c", "south");

    addRandomCreature(({"hunter","coyote","warg","mink"}));
}
