//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/apple-stand.c", "northwest");

    addExit("north", "/areas/tol-dhurath/entry/2x3.c");
    addFeature("/lib/environment/features/paths/path.c", "north");

    addRandomCreature(({"hunter","ruffian","gray fox","outlaw","white-tail deer"}));
}
