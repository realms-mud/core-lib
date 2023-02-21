//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/gulley-creek.c", "west");
    addFeature("/lib/environment/features/water/brook.c", "west");

    addExit("west", "/areas/tol-dhurath/forest-4/3x9.c");
    addFeature("/lib/environment/features/paths/path.c", "west");

    addRandomCreature(({"weasel","badger","red wolf","chipmunk"}));
}
