//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    setShortDescription("The common gleaning strips");
    addDecorator("farm track T-east");
    addFeature("/lib/environment/features/plants/common-grain-strips.c",
        "south");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("north", "/areas/eledhel/central-rural/21x4.c");
    addExit("east", "/areas/eledhel/central-rural/22x3.c");
    addExit("south", "/areas/eledhel/estates/aladain/grounds/0x2.c");
    addExit("west", "/areas/northern-road/north-gate/3x3.c");
}
