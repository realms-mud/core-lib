//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-clearing.c");
    setShortDescription("The spring hollow");
    addDecorator("farm track T-south");
    addFeature("/lib/environment/features/water/spring.c", "north");
    addFeature("/lib/environment/features/trees/willow-stand.c", "west");
    addFeature("/lib/environment/features/plants/raspberry-canes.c", "east");
    addExit("west", "/areas/eledhel/central-rural/21x7.c");
    addExit("east", "/areas/eledhel/central-rural/23x7.c");
    addExit("south", "/areas/eledhel/central-rural/22x6.c");
}
