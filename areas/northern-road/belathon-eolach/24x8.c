//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "north");
    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addFeature("/lib/environment/features/plants/rye-field.c", "south");
    addItem("/lib/environment/items/objects/milestone.c", "southeast");
    addItem("/lib/environment/items/objects/signPost.c", "southwest");

    addDecorator("village road corner NW");

    addExit("north", "/areas/northern-road/hrondil-approaches/0x0.c");
    addExit("west", "/areas/northern-road/belathon-eolach/23x8.c");
}
