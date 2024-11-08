//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/mound.c", "northwest");
    addFeature("/lib/environment/features/trees/ash-stand.c", "northwest");

    addExit("west", "/areas/tol-dhurath/forest-4/16x5.c");
    addFeature("/lib/environment/features/paths/path.c", "west");

    addRandomCreature(({"hunter","outlaw","red fox","red wolf"}));
}
