//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    setShortDescription("The gardens behind Pera's stand");
    addDecorator("farm path south-west bend");
    addFeature("/lib/environment/features/plants/common-kitchen-garden.c",
        "east");
    addFeature("/lib/environment/features/plants/common-root-beds.c",
        "north");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("south", "/areas/eledhel/central-rural/23x6.c");
    addExit("west", "/areas/eledhel/central-rural/22x7.c");
}
