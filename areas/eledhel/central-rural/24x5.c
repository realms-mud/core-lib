//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    setShortDescription("The west-gate approach");
    addDecorator("farm track T-north");
    addItem("/lib/environment/items/objects/notice-board.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "north");

    addExit("east", "/areas/eledhel/central-city/0x5.c");
    addExit("west", "/areas/eledhel/central-rural/23x5.c");
    addExit("north", "/areas/eledhel/central-rural/24x6.c");
}
