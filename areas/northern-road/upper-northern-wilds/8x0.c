//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-mountain.c");
    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addFeature("/lib/environment/features/landforms/precipice.c", "north");
    addFeature("/lib/environment/features/trees/pine-stand.c", "south");
    addItem("/lib/environment/items/military/signal-fire.c", "northwest");
    addDecorator("village east-west road");
    addExit("east", "/areas/northern-road/upper-northern-wilds/9x0.c");
    addExit("west", "/areas/northern-road/upper-northern-wilds/7x0.c");
}
