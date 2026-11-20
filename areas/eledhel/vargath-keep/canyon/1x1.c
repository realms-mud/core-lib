//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/cave.c");
    addDecorator("forest trail south-east");
    setShortDescription("A storage cavern opens above the canyon floor");
    addFeature("/lib/environment/features/ore-veins/iron.c", "north");
    addExit("south", "/areas/eledhel/vargath-keep/canyon/1x2.c");
    addExit("east", "/areas/eledhel/vargath-keep/canyon/2x1.c");
}
