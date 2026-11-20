//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    addDecorator("farm path south dead end");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addItem("/lib/environment/items/objects/water-trough.c", "north");
    addItem("/lib/environment/items/objects/hand-cart.c", "west");
    addObject("/areas/eledhel/central-rural/characters/othyl/othyl.c");

    addExit("south", "/areas/eledhel/central-rural/24x6.c");
}
