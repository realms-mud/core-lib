//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/teak-stand.c", "south");
    addFeature("/lib/environment/features/landforms/hollow.c", "south");
    addFeature("/lib/environment/features/landforms/bluff.c", "south");

    addExit("east", "/areas/tol-dhurath/forest-4/18x1.c");
    addFeature("/lib/environment/features/paths/path.c", "east");

    addRandomCreature(({"ruffian","fisher","porcupine","raccoon","gray squirrel","timber wolf"}));
}
