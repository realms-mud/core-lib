//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/brook.c", "southeast");
    addFeature("/lib/environment/features/trees/ironwood-stand.c", "southeast");

    addExit("east", "/areas/eledhel/west-rural/15x5.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("west", "/areas/eledhel/west-rural/13x5.c");
    addFeature("/lib/environment/features/paths/path.c", "west");

    addRandomCreature(({"warg","otter","keeper of the night","mink","opossum"}));
}
