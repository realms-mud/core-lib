//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/ruin.c");
    addDecorator("ruined interior south-west corner hallway");
    addFeature("/lib/environment/features/caves/timber-supports.c",
        "north");
    addItem("/lib/environment/items/objects/packing-crate.c", "east");

    addExit("west", "/areas/eledhel/central-rural/cellar/2x1.c");
    addExit("south", "/areas/eledhel/central-rural/cellar/3x2.c");
}
