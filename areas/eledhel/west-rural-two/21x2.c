//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail north-south");
    setShortDescription("The wind-worn saddle");
    addFeature("/lib/environment/features/trees/birch-stand.c", "east");
    addFeature("/lib/environment/features/trees/aspen-stand.c", "east");
    addFeature("/lib/environment/features/landforms/ridge.c", "east");

    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("north", "/areas/eledhel/west-rural-two/21x3.c");
    addExit("south", "/areas/eledhel/west-rural-two/21x1.c");

    addRandomCreature(({"wolverine", "gray squirrel"}));
}
