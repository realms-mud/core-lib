//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/cave.c");
    addDecorator("cave north-east passage");
    setShortDescription("The stream narrows and quickens in the dark");
    addFeature("/lib/environment/features/water/ravine-creek.c", "east");
    addExit("north", "/areas/eledhel/vargath-keep/limestone-caves/1x0.c");
    addExit("east", "/areas/eledhel/vargath-keep/limestone-caves/2x1.c");
}
