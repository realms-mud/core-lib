//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail intersection");
    setShortDescription("The rune-carved altar in the gorge");
    addFeature("/lib/environment/features/water/creek.c", "south");
    addItem("/lib/environment/items/furniture/small-table.c", "none");
    addItem("/areas/evenholt/river-celebuin/items/tankard-of-obstinance.c",
        "none");
    addExit("north", "/areas/evenholt/river-celebuin/16x5.c");
    addExit("west", "/areas/evenholt/river-celebuin/15x6.c");
    addExit("east", "/areas/evenholt/river-celebuin/17x6.c");
    addExit("south", "/areas/evenholt/river-celebuin/16x7.c");
}
