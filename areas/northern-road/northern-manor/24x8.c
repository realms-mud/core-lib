//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/plains.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "north");
    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addFeature("/lib/environment/features/landforms/hillock.c", "south");
    addItem("/lib/environment/items/objects/milestone.c", "southeast");

    addDecorator("village road corner NW");

    addExit("north", "/areas/northern-road/belathon-eolach/0x0.c");
    addExit("west", "/areas/northern-road/northern-manor/23x8.c");
}
