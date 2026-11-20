//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/ruin.c");
    addDecorator("ruined interior south T-intersection");
    addFeature("/lib/environment/features/caves/timber-supports.c",
        "north");
    addItem("/lib/environment/items/objects/sack-pile.c", "southwest");

    addExit("west", "/areas/eledhel/central-rural/cellar/1x1.c");
    addExit("east", "/areas/eledhel/central-rural/cellar/3x1.c");
    addExit("south", "/areas/eledhel/central-rural/cellar/2x2.c");
}
