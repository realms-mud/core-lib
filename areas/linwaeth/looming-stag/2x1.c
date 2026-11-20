//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/inn.c");
    setShortDescription("The Looming Stag's entry and kitchen");
    addDecorator("keep interior floor");
    addItem("/lib/environment/items/furniture/counter.c", "north");
    addExitWithDoor("east", "/areas/linwaeth/11x3.c",
        "/lib/environment/doors/plank-door.c");
    addExit("west", "/areas/linwaeth/looming-stag/1x1.c");
}
