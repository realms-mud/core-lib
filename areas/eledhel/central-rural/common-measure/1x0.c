//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/wood-interior.c");
    addItem("/lib/environment/items/objects/sack-pile.c", "west");
    addItem("/lib/environment/items/furniture/cupboard.c", "east");
    addItem("/lib/environment/items/lighting/window.c", "north");

    addExit("south", "/areas/eledhel/central-rural/common-measure/1x1.c");
}
