//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/wood-interior.c");
    addDecorator("keep interior floor");
    setShortDescription("The cellar steps and dry-goods store");
    addItem("/lib/environment/items/furniture/chest.c", "east");
    addExit("up", "/areas/evenholt/manor/3x1.c");
    addExit("east", "/areas/evenholt/manor-cellar/1x0.c");
}
