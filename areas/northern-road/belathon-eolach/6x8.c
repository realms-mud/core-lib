//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addFeature("/lib/environment/features/plants/rye-field.c", "north");
    addItem("/lib/environment/items/objects/hay-bale.c", "southwest");

    addDecorator("village east-west road");

    addExit("east", "/areas/northern-road/belathon-eolach/7x8.c");
    addExit("west", "/areas/northern-road/belathon-eolach/5x8.c");
}
