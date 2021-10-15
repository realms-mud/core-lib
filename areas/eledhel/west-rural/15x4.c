//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/canyon-dry-bed.c", "south");
    addFeature("/lib/environment/features/landforms/hollow.c", "south");

    addExit("west", "/areas/eledhel/west-rural/14x4.c");
    addFeature("/lib/environment/features/paths/path.c", "west");

    addRandomCreature(({"weasel","skunk","boar","raccoon"}));
}
