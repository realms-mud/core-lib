//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/pine-stand.c", "west");

    addExit("west", "/areas/eledhel/west-rural/9x8.c");
    addFeature("/lib/environment/features/paths/path.c", "west");

    addRandomCreature(({"opossum","weasel","otter"}));
}
