//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/craft-workroom.c");
    addItem("/lib/environment/items/lighting/oil-lamp.c", "west");
    addItem("/areas/eledhel/west-rural/items/cask-hoops.c", "east");
    addObject("/areas/eledhel/west-rural/characters/derrik/derrik.c");

    addExitWithDoor("west", "/areas/eledhel/west-rural/23x2.c",
        "/lib/environment/doors/plank-door.c");
}
