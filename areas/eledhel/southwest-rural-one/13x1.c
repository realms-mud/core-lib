//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    setShortDescription("A sheep track leaves the south road");

    addExit("north", "/areas/eledhel/southwest-rural-one/13x2.c");
    addFeature("/lib/environment/features/paths/road.c", "north");
    addExit("west", "/areas/eledhel/estates/llenwych/grounds/0x2.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}
