//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/knoll.c", "west");
    addFeature("/lib/environment/features/trees/sycamore-stand.c", "west");
    addFeature("/lib/environment/features/landforms/ridge.c", "west");

    addExit("west", "/areas/tol-dhurath/forest-2/17x3.c");
    addFeature("/lib/environment/features/paths/path.c", "west");

    addRandomCreature(({"zombie","coyote","knight of the storm","outlaw","red wolf"}));
}
