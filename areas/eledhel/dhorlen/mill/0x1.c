//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/craft-workroom.c");
    setShortDescription("The mill's stone entry and loading room");
    addDecorator("keep interior floor");
    addItem("/lib/environment/items/crafts/flour-sack.c", "east");
    addExit("north", "/areas/eledhel/dhorlen/mill/0x0.c");
    addExitWithDoor("south", "/areas/eledhel/dhorlen/2x2.c",
        "/lib/environment/doors/plank-door.c");
}
