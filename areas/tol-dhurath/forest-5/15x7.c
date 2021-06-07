//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/valley.c", "northeast");
    addFeature("/lib/environment/features/landforms/knoll.c", "northeast");

    addExit("south", "/areas/tol-dhurath/forest-5/15x6.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("west", "/areas/tol-dhurath/forest-5/14x7.c");
    addFeature("/lib/environment/features/paths/path.c", "west");

    addRandomCreature(({"gopher","fisher","mink","timber wolf","kit fox","chipmunk"}));
}
