//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    setShortDescription("The common orchard");
    addDecorator("farm orchard intersection");
    addFeature("/lib/environment/features/trees/apple-stand.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "south");

    addExit("south", "/areas/eledhel/central-rural/22x5.c");
    addExit("east", "/areas/eledhel/central-rural/23x6.c");
    addExit("west", "/areas/eledhel/central-rural/21x6.c");
    addExit("north", "/areas/eledhel/central-rural/22x7.c");
}
