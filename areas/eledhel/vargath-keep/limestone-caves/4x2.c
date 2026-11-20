//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/cave.c");
    addDecorator("cave south-east passage");
    setShortDescription("The waterfall exit drops into a bowl-shaped canyon");
    addFeature("/lib/environment/features/water/ravine-waterfall.c", "east");
    addExit("south", "/areas/eledhel/vargath-keep/limestone-caves/4x3.c");
    addExit("east", "/areas/eledhel/vargath-keep/canyon/0x2.c");
}
