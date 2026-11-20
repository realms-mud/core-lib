//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    setShortDescription("The stone front of Endur Manor");
    addDecorator("village cottage");
    addItem("/lib/environment/items/lighting/lantern.c", "north");
    addExit("west", "/areas/eledhel/estates/endur/grounds/2x2.c");
    addExit("north",
        "/areas/eledhel/estates/endur/manor-interior/2x0.c");
}
