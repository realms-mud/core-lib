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
    addFeature("/lib/environment/features/water/field-drain.c", "west");

    addDecorator("village north-south road");

    addExit("north", "/areas/northern-road/northern-manor/0x2.c");
    addExit("south", "/areas/northern-road/northern-manor/0x4.c");
}
