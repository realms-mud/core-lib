//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/cave.c");
    addDecorator("cave south-east passage");
    setShortDescription("The waterfall outlet");
    addFeature("/lib/environment/features/water/ravine-waterfall.c", "east");
    addExit("south", "/areas/evenholt/limestone-caves/4x1.c");
    addExit("east", "/areas/evenholt/grounds/24x2.c");
}
