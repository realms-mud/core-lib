//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/wood-interior.c");
    setShortDescription("The entry to Tirwen farmhouse");
    addDecorator("keep interior floor");
    addItem("/lib/environment/items/lighting/oil-lamp.c", "east");
    addExit("north", "/areas/eledhel/tirwen/farmhouse/0x0.c");
    addExitWithDoor("west", "/areas/eledhel/tirwen/4x2.c",
        "/lib/environment/doors/plank-door.c");
}
