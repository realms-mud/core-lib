//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/promontory.c", "north");
    addFeature("/lib/environment/features/trees/sugar-maple-stand.c", "west");
    addFeature("/lib/environment/features/landforms/ridge.c", "southwest");

    addExit("north", "/areas/tol-dhurath/temple-exterior/13x9.c");
    addFeature("/lib/environment/features/paths/path.c", "north");

    addRandomCreature(({"ruffian","outlaw","coyote","boar","timber wolf"}));
}
