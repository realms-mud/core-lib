//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-clearing.c");
    addFeature("/lib/environment/features/paths/gravel-road.c", "east");
    addFeature("/lib/environment/features/trees/oak-stand.c", "north");
    addItem("/lib/environment/items/objects/milestone.c", "southwest");
    addDecorator("village east-west road");

    addExit("west",
        "/areas/northern-road/upper-northern-wilds/24x0.c");
    addExit("east", "/areas/northern-road/minlach-approaches/1x4.c");
}
