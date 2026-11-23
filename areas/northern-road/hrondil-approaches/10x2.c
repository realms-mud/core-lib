//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addFeature("/lib/environment/features/water/field-drain.c", "south");
    addItem("/lib/environment/items/objects/hand-cart.c", "southeast");
    addFeature("/lib/environment/features/plants/common-grain-strips.c",
        "south");

    addDecorator("village east-west road");

    addExit("east", "/areas/northern-road/hrondil-approaches/11x2.c");
    addExit("west", "/areas/northern-road/hrondil-approaches/9x2.c");
}
