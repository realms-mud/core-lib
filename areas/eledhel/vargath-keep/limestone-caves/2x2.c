//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/cave.c");
    addDecorator("cave north-east passage");
    setShortDescription("A deep pool opens beneath the limestone roof");
    addFeature("/lib/environment/features/water/lake.c", "east");
    addExit("north", "/areas/eledhel/vargath-keep/limestone-caves/2x1.c");
    addExit("east", "/areas/eledhel/vargath-keep/limestone-caves/3x2.c");
}
