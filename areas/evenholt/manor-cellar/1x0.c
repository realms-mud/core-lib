//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/wood-interior.c");
    addDecorator("keep interior east-west hallway");
    setShortDescription("The wine and spirits racks");
    addItem("/lib/environment/items/furniture/wine-rack.c", "north");
    addExit("west", "/areas/evenholt/manor-cellar/0x0.c");
    addExit("east", "/areas/evenholt/manor-cellar/2x0.c");
}
