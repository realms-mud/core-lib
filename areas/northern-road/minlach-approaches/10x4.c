//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/plants/barley-field.c", "south");
    addFeature("/lib/environment/features/landforms/knoll.c", "north");
    addItem("/lib/environment/items/objects/milestone.c", "west");
    addDecorator("village east-west road");

    addExit("west", "/areas/northern-road/minlach-approaches/9x4.c");
    addExit("east", "/areas/northern-road/minlach-approaches/11x4.c");
}
