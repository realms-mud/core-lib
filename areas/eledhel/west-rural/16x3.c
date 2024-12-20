//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/red-oak-stand.c", "west");
    addFeature("/lib/environment/features/landforms/hill.c", "west");
    addFeature("/lib/environment/features/landforms/ridge.c", "west");

    addExit("east", "/areas/eledhel/west-rural/17x3.c");
    addFeature("/lib/environment/features/paths/path.c", "east");

    addRandomCreature(({"gopher","skeleton","gray wolf"}));
}
