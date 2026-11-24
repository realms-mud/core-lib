//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-mountain.c");
    addFeature("/lib/environment/features/paths/gravel-road.c", "east");
    addFeature("/lib/environment/features/landforms/ridge.c", "north");
    addFeature("/lib/environment/features/trees/spruce-stand.c", "west");
    addRandomCreature(({ "gray wolf", "white-tail deer" }));
    addExit("west",
        "/areas/northern-road/upper-northern-wilds/hollow-mill/wheel-room.c");
    addExit("east",
        "/areas/northern-road/upper-northern-wilds/inland/fir-shelf.c");
}
