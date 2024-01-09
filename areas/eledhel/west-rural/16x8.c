//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/brook.c", "northwest");
    addFeature("/lib/environment/features/trees/cypress-stand.c", "northwest");

    addExit("north", "/areas/eledhel/west-rural/16x9.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("west", "/areas/eledhel/west-rural/15x8.c");
    addFeature("/lib/environment/features/paths/path.c", "west");

    addRandomCreature(({"knight of the storm","outlaw","gray squirrel","red wolf"}));
}
