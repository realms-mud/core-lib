//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/village.c");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "south");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "north");
    addFeature("/lib/environment/features/landforms/hill.c", "north");
    addItem("/lib/environment/items/lighting/lantern.c", "east");
    addItem("/lib/environment/items/lighting/lantern.c", "west");

    addDecorator("village north-south road");

    addExit("south", "/areas/argalen-keep/surrounding/12x6.c");
    addExit("north", "/areas/argalen-keep/surrounding/12x8.c");
}
