//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/plains.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addFeature("/lib/environment/features/trees/beech-stand.c", "north");
    addItem("/lib/environment/items/objects/fox-tracks.c", "southwest");

    addDecorator("village east-west road");

    addExit("east", "/areas/northern-road/belathon-eolach/11x2.c");
    addExit("west", "/areas/northern-road/belathon-eolach/9x2.c");
}
