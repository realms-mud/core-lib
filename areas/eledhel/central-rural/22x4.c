//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    setShortDescription("The public root beds");
    addDecorator("farm track T-south");
    addFeature("/lib/environment/features/plants/common-root-beds.c",
        "north");
    addFeature("/lib/environment/features/water/brook.c", "east");
    addItem("/lib/environment/items/objects/boundary-stone.c", "west");
    addExit("east", "/areas/eledhel/central-rural/23x4.c");
    addExit("west", "/areas/eledhel/central-rural/21x4.c");
    addExit("south", "/areas/eledhel/central-rural/22x3.c");
}
