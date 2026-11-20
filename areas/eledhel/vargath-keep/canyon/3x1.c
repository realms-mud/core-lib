//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/cave.c");
    addDecorator("forest trail T-south");
    setShortDescription("A low foundry is blackened by iron smoke");
    addFeature("/lib/environment/features/ore-veins/iron.c", "north");
    addItem("/lib/environment/items/crafts/anvil.c", "none");
    addExit("west", "/areas/eledhel/vargath-keep/canyon/2x1.c");
    addExit("east", "/areas/eledhel/vargath-keep/canyon/4x1.c");
    addExit("south", "/areas/eledhel/vargath-keep/canyon/3x2.c");
}
