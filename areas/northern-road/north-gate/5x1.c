//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addItem("/lib/environment/items/objects/signPost.c", "north");
    addItem("/lib/environment/items/objects/hand-cart.c", "southeast");
    addFeature("/lib/environment/features/plants/common-kitchen-garden.c",
        "south");

    addDecorator("village square");

    addExit("west", "/areas/northern-road/north-gate/4x1.c");
}
