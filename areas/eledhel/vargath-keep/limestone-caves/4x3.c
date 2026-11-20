//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/cave.c");
    addDecorator("cave north-west passage");
    setShortDescription("Sunlight shines up through a dead-end pool");
    addFeature("/lib/environment/features/water/lake.c", "south");
    addExit("west", "/areas/eledhel/vargath-keep/limestone-caves/3x3.c");
    addExit("north", "/areas/eledhel/vargath-keep/limestone-caves/4x2.c");
}
