//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    setShortDescription("The mill lane");
    addDecorator("farm track T-west");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addFeature("/lib/environment/features/water/brook.c", "west");
    addExit("north", "/areas/eledhel/central-rural/23x5.c");
    addExit("south", "/areas/eledhel/central-rural/23x3.c");
    addExit("west", "/areas/eledhel/central-rural/22x4.c");
}
