//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/willow-stand.c", "south");

    addExit("west", "/areas/eledhel/west-rural/22x6.c");
    addFeature("/lib/environment/features/paths/path.c", "west");

    addRandomCreature(({"white-tail deer","hunter","ruffian"}));
}
