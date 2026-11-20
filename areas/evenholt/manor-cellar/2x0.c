//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/wood-interior.c");
    addDecorator("keep interior floor");
    setShortDescription("The requisitioned medical stores");
    addItem("/lib/environment/items/furniture/cupboard.c", "west");
    addExit("west", "/areas/evenholt/manor-cellar/1x0.c");
}
