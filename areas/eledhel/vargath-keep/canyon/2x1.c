//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/cave.c");
    addDecorator("forest trail T-south");
    setShortDescription("Iron ore and charcoal are stacked in a cut chamber");
    addFeature("/lib/environment/features/ore-veins/iron.c", "north");
    addExit("west", "/areas/eledhel/vargath-keep/canyon/1x1.c");
    addExit("east", "/areas/eledhel/vargath-keep/canyon/3x1.c");
    addExit("south", "/areas/eledhel/vargath-keep/canyon/2x2.c");
}
