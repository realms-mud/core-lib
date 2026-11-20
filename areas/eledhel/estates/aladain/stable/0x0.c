//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/wood-interior.c");
    setShortDescription("The household stable");
    addItem("/lib/environment/items/objects/sack-pile.c", "north");
    addItem("/lib/environment/items/lighting/oil-lamp.c", "east");
    addObject("/areas/eledhel/estates/aladain/characters/stablehand.c");
    addExitWithDoor("east", "/areas/eledhel/estates/aladain/grounds/1x1.c",
        "/lib/environment/doors/plank-door.c");
}
