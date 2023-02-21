//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/hill.c", "northwest");
    addFeature("/lib/environment/features/water/lake-shore-bluff.c", "northwest");
    addFeature("/lib/environment/features/landforms/hollow.c", "northwest");

    addExit("west", "/areas/eledhel/west-rural/17x5.c");
    addFeature("/lib/environment/features/paths/path.c", "west");

    addRandomCreature(({"warg","mule deer","outlaw"}));
}
