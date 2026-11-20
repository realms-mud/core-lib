//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    setShortDescription("The market-cart crossing");
    addDecorator("farm track intersection");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "north");

    addExit("east", "/areas/eledhel/central-rural/24x5.c");
    addExit("west", "/areas/eledhel/central-rural/22x5.c");
    addExit("north", "/areas/eledhel/central-rural/23x6.c");
    addExit("south", "/areas/eledhel/central-rural/23x4.c");
}
