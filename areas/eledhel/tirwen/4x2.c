//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    setShortDescription("The timber porch of Tirwen's farmhouse");
    addDecorator("village cottage");
    addItem("/lib/environment/items/objects/woodpile.c", "west");
    addExit("north", "/areas/eledhel/tirwen/4x1.c");
    addExitWithDoor("east",
        "/areas/eledhel/tirwen/farmhouse/0x1.c",
        "/lib/environment/doors/plank-door.c");
}
