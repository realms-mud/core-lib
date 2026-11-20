//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail north-east");
    setShortDescription("The pond hollow");

    addFeature("/lib/environment/features/water/pond.c", "west");
    addFeature("/lib/environment/features/trees/aspen-stand.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "north");

    addExit("east", "/areas/eledhel/west-rural-two/8x2.c");
    addExit("north", "/areas/eledhel/west-rural-two/7x3.c");

    addNonCombatCreature(({"beaver", "otter", "muskrat"}));
}
