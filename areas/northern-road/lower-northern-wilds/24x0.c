//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/plains.c");
    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addFeature("/lib/environment/features/paths/dirt-road.c", "south");
    addFeature("/lib/environment/features/landforms/knoll.c", "north");

    addDecorator("village road corner SW");

    addExit("west", "/areas/northern-road/lower-northern-wilds/23x0.c");
    addExit("south", "/areas/northern-road/lower-northern-wilds/24x1.c");
}
