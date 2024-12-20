//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/elm-stand.c", "east");

    addExit("west", "/areas/tol-dhurath/temple-exterior/11x5.c");
    addFeature("/lib/environment/features/paths/path.c", "west");

    addRandomCreature(({"hunter","ruffian","black bear","mule deer","white-tail deer"}));
}
