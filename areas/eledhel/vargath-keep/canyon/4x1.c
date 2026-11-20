//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/cave.c");
    addDecorator("forest trail south-west");
    setShortDescription("A narrow smelter vents through a crack in the cliff");
    addFeature("/lib/environment/features/ore-veins/iron.c", "north");
    addItem("/lib/environment/items/furniture/workbench.c", "none");
    addExit("west", "/areas/eledhel/vargath-keep/canyon/3x1.c");
    addExit("south", "/areas/eledhel/vargath-keep/canyon/4x2.c");
}
