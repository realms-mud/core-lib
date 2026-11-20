//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/cave.c");
    addDecorator("cave north-east passage");
    setShortDescription("The beginning of the south passage");
    addFeature("/lib/environment/features/water/ravine-creek.c", "west");
    addExit("north", "/areas/evenholt/limestone-caves/2x1.c");
    addExit("east", "/areas/evenholt/limestone-caves/3x2.c");
}
