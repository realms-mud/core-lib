//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/glen.c", "south");
    addFeature("/lib/environment/features/water/creek.c", "south");

    addExit("west", "/areas/eledhel/west-rural/11x5.c");
    addFeature("/lib/environment/features/paths/path.c", "west");

    addRandomCreature(({"outlaw","warg","gray squirrel","white-tail deer","skeleton"}));
}
