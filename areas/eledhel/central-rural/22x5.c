//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    setShortDescription("The west-road farm junction");
    addDecorator("farm track T-north");
    addItem("/lib/environment/items/objects/boundary-stone.c", "south");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "north");

    addExit("east", "/areas/eledhel/central-rural/23x5.c");
    addExit("west", "/areas/eledhel/west-rural/0x0.c");
    addExit("north", "/areas/eledhel/central-rural/22x6.c");
}
