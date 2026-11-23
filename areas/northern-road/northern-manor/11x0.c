//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-clearing.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addFeature("/lib/environment/features/trees/cherry-stand.c", "north");
    addItem("/lib/environment/items/objects/stone-pile.c", "south");

    addDecorator("village east-west road");

    addExit("east", "/areas/northern-road/northern-manor/12x0.c");
    addExit("west", "/areas/northern-road/northern-manor/10x0.c");
}
