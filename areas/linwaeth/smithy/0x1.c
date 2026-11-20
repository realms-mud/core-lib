//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/craft-workroom.c");
    setShortDescription("Johan's smithy");
    addDecorator("keep interior floor");
    addItem("/lib/environment/items/lighting/forge-fire.c", "east");
    addObject("/areas/linwaeth/characters/johan.c");
    addShop("/lib/environment/shopInventories/swordsmith.c");
    addExitWithDoor("west", "/areas/linwaeth/13x3.c",
        "/lib/environment/doors/plank-door.c");
}
