//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail T-east");
    addFeature("/lib/environment/features/water/gulley-creek.c", "north");

    addExit("south", "/areas/tol-dhurath/forest-1/17x1.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("north", "/areas/tol-dhurath/forest-1/17x3.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("east", "/areas/tol-dhurath/forest-1/18x2.c");
    addFeature("/lib/environment/features/paths/path.c", "east");

    addItem("/lib/environment/items/objects/outlaw-warning-sign.c", "east");
    addNonCombatCreature(({"hunter","white-tail deer"}));
}
