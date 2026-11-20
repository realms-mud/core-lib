//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    setShortDescription("The bean rows beside the stream");
    addDecorator("farm track T-north");
    addFeature("/lib/environment/features/plants/common-pulse-rows.c",
        "south");
    addFeature("/lib/environment/features/water/brook.c", "east");
    addExit("north", "/areas/eledhel/central-rural/22x4.c");
    addExit("east", "/areas/eledhel/central-rural/23x3.c");
    addExit("west", "/areas/eledhel/central-rural/21x3.c");
}
