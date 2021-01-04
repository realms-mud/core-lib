//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");

    addExit("south", "/areas/eledhel/southwest-rural-two/22x1.c");
    addFeature("/lib/environment/features/paths/road.c", "south");
    addExit("north", "/areas/eledhel/southwest-rural-two/22x3.c");
    addFeature("/lib/environment/features/paths/road.c", "north");
    addExit("west", "/areas/eledhel/southwest-rural-two/21x2.c");
    addFeature("/lib/environment/features/paths/road.c", "west");
}

