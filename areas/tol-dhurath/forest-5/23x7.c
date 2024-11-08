//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/brook.c", "west");
    addFeature("/lib/environment/features/landforms/knoll.c", "west");

    addExit("east", "/areas/tol-dhurath/forest-5/24x7.c");
    addFeature("/lib/environment/features/paths/path.c", "east");

    addRandomCreature(({"ruffian","skunk","white-tail deer","raccoon","kit fox"}));
}
