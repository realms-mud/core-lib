//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/areas/minlach/investigation-room.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("village road T-east");
    setShortDescription("The common woodland boundary");
    addItem("/lib/environment/items/objects/boundary-stone.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addClue("boundary stone", "woodland-boundary", "inspectBoundaryStone",
        "The carved line places the berry hedge on the common "
        "and standing timber beyond it in a managed plot.");
    addExit("east", "/areas/minlach/surrounding/1x4.c");
    addExit("south", "/areas/minlach/surrounding/0x3.c");
    addExit("north", "/areas/minlach/surrounding/0x5.c");
}
