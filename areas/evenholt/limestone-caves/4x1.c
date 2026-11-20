//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/cave.c");
    addDecorator("cave north-west passage");
    setShortDescription("The dead-end pool");
    addFeature("/lib/environment/features/water/ravine-pond.c", "east");
    addExit("west", "/areas/evenholt/limestone-caves/3x1.c");
    addExit("north", "/areas/evenholt/limestone-caves/4x0.c");
}
