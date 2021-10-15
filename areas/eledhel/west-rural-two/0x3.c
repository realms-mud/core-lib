//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/yew-stand.c", "east");
    addFeature("/lib/environment/features/landforms/tor.c", "east");
    addFeature("/lib/environment/features/landforms/ridge.c", "east");

    addExit("east", "/areas/eledhel/west-rural-two/1x3.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("south", "/areas/eledhel/west-rural-two/0x2.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}
