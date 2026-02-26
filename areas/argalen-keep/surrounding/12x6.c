//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/village.c");
    addBuilding("/lib/environment/buildings/religious/church.c", "west",
        "/areas/argalen-keep/surrounding/church/0x0.c");
    addBuilding("/lib/environment/buildings/homes/large-stone-house.c", "east");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "south");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "north");
    addItem("/lib/environment/items/lighting/lantern.c", "west");

    addDecorator("village north-south road");

    addExit("south", "/areas/argalen-keep/surrounding/12x5.c");
    addExit("north", "/areas/argalen-keep/surrounding/12x7.c");
}
