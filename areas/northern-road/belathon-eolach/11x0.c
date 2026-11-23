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
    addFeature("/lib/environment/features/plants/common-grain-strips.c",
        "north");
    addItem("/lib/environment/items/objects/hay-bale.c", "south");

    addDecorator("village east-west road");

    addExit("east", "/areas/northern-road/belathon-eolach/12x0.c");
    addExit("west", "/areas/northern-road/belathon-eolach/10x0.c");
}
