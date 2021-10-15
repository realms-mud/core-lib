//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/ridge.c", "northeast");
    addFeature("/lib/environment/features/trees/golden-apple-stand.c", "northeast");

    addExit("east", "/areas/eledhel/west-rural-two/17x4.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("south", "/areas/eledhel/west-rural-two/16x3.c");
    addFeature("/lib/environment/features/paths/path.c", "south");

    addRandomCreature(({"outlaw","red fox","raccoon","white-tail deer"}));
}
