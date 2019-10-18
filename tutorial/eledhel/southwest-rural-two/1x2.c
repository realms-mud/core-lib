//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");

    addExit("north", "/lib/tutorial/eledhel/southwest-rural-two/1x3.c");
    addFeature("/lib/environment/features/paths/road.c", "north");
    addExit("west", "/lib/tutorial/eledhel/southwest-rural-two/0x2.c");
    addFeature("/lib/environment/features/paths/road.c", "west");
}

