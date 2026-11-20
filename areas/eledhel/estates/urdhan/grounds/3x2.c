//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    setShortDescription("The timber front of Urdhan Manor");
    addDecorator("village cottage");
    addItem("/lib/environment/items/lighting/lantern.c", "north");
    addExit("west", "/areas/eledhel/estates/urdhan/grounds/2x2.c");
    addExit("north",
        "/areas/eledhel/estates/urdhan/manor-interior/2x0.c");
}
