//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/combe.c", "north");
    addFeature("/lib/environment/features/landforms/mound.c", "north");

    addExit("south", "/areas/eledhel/west-rural-two/15x1.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("north", "/areas/eledhel/west-rural-two/15x3.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}
