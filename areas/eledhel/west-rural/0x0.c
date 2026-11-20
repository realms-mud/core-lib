//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail T-north");
    addFeature("/lib/environment/features/trees/cottonwood-stand.c", "southeast");
    addFeature("/lib/environment/features/landforms/glen.c", "southeast");
    addFeature("/lib/environment/features/water/brook.c", "southeast");

    addExit("north", "/areas/eledhel/west-rural/0x1.c");
    addExit("east", "/areas/eledhel/central-rural/22x5.c");
    addExit("west", "/areas/eledhel/west-rural-two/0x0.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "west");

    addNonCombatCreature(({"red fox","white-tail deer","chipmunk"}));
}
