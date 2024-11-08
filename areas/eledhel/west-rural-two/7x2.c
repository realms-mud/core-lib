//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/pond.c", "west");
    addFeature("/lib/environment/features/trees/aspen-stand.c", "west");

    addExit("east", "/areas/eledhel/west-rural-two/8x2.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("north", "/areas/eledhel/west-rural-two/7x3.c");
    addFeature("/lib/environment/features/paths/path.c", "north");

    addRandomCreature(({"black bear","weasel","ruffian","outlaw"}));
}
