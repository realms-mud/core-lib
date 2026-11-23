//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addFeature("/lib/environment/features/paths/dirt-road.c", "south");
    addFeature("/lib/environment/features/plants/barley-field.c", "north");
    addFeature("/lib/environment/features/water/field-drain.c", "east");

    addDecorator("village road corner SW");

    addExit("west", "/areas/northern-road/northern-manor/23x4.c");
    addExit("south", "/areas/northern-road/northern-manor/24x5.c");
}
