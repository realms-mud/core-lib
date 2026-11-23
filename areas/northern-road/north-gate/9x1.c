//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "north");
    addFeature("/lib/environment/features/paths/dirt-road.c", "south");
    addFeature("/lib/environment/features/plants/barley-field.c", "east");
    addItem("/lib/environment/items/objects/scarecrow.c", "west");

    addDecorator("village north-south road");

    addExit("north", "/areas/northern-road/north-gate/9x0.c");
    addExit("south", "/areas/northern-road/north-gate/9x2.c");
}
