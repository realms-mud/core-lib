//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/wood-interior.c");
    setShortDescription("The shared pasture barn");
    addDecorator("keep interior east entry alcove");
    addItem("/lib/environment/items/objects/sack-pile.c", "north");
    addItem("/lib/environment/items/marine/coiled-rope.c", "south");
    addItem("/lib/environment/items/lighting/window.c", "east");
    addItem("/lib/environment/items/lighting/oil-lamp.c", "west");
    addObject("/areas/eledhel/central-rural/characters/idel/idel.c");
    addExitWithDoor("east", "/areas/eledhel/central-rural/21x5.c",
        "/lib/environment/doors/plank-door.c");
}
