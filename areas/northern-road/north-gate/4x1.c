//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "north");
    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature(
        "/lib/environment/features/plants/common-grain-strips.c",
        "south");
    addItem("/lib/environment/items/objects/hand-cart.c", "southeast");
    addItem("/lib/environment/items/objects/wooden-fence.c", "west");
    addObject("/areas/northern-road/north-gate/characters/maerwen.c");

    addDecorator("village road corner NE");

    addExit("north", "/areas/northern-road/north-gate/4x0.c");
    addExit("east", "/areas/northern-road/north-gate/5x1.c");
}
