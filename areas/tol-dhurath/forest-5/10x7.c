//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/elm-stand.c", "west");
    addFeature("/lib/environment/features/landforms/hillock.c", "west");

    addExit("north", "/areas/tol-dhurath/forest-5/10x8.c");
    addFeature("/lib/environment/features/paths/path.c", "north");

    addRandomCreature(({"zombie","black bear","mule deer","red fox","brown bear","boar"}));
}
