//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/ravine-brook.c", "west");
    addFeature("/lib/environment/features/landforms/cliff.c", "west");
    addFeature("/lib/environment/features/landforms/glen.c", "west");

    addExit("north", "/areas/tol-dhurath/forest-4/8x7.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("west", "/areas/tol-dhurath/forest-4/7x6.c");
    addFeature("/lib/environment/features/paths/path.c", "west");

    addRandomCreature(({"gopher","outlaw","warg","coyote","timber wolf","boar","mountain lion"}));
}
