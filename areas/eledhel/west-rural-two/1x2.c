//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/ravine-dry-creek.c", "southwest");
    addFeature("/lib/environment/features/trees/oak-stand.c", "southwest");
    addFeature("/lib/environment/features/trees/aspen-stand.c", "southwest");

    addExit("east", "/areas/eledhel/west-rural-two/2x2.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("west", "/areas/eledhel/west-rural-two/0x2.c");
    addFeature("/lib/environment/features/paths/path.c", "west");

    addRandomCreature(({"ruffian","zombie","fisher","skeleton","white-tail deer"}));
}
