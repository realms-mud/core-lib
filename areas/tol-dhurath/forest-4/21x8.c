//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/hollow.c", "west");

    addExit("north", "/areas/tol-dhurath/forest-4/21x9.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("east", "/areas/tol-dhurath/forest-4/22x8.c");
    addFeature("/lib/environment/features/paths/path.c", "east");

    addRandomCreature(({"muskrat","red squirrel","timber wolf","raccoon"}));
}
