//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/tor.c", "south");
    addFeature("/lib/environment/features/water/brook.c", "south");
    addFeature("/lib/environment/features/trees/grape-stand.c", "south");

    addExit("north", "/areas/eledhel/west-rural/8x5.c");
    addFeature("/lib/environment/features/paths/path.c", "north");

    addRandomCreature(({"gopher","ruffian","zombie","outlaw","boar","skeleton"}));
}
