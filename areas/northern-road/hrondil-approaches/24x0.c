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
    addFeature("/lib/environment/features/landforms/hillock.c", "north");
    addItem("/lib/environment/items/objects/stone-pile.c", "east");

    addDecorator("village road corner SW");

    addExit("west", "/areas/northern-road/hrondil-approaches/23x0.c");
    addExit("south", "/areas/northern-road/hrondil-approaches/24x1.c");
}
