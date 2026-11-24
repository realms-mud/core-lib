//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-clearing.c");
    addFeature("/lib/environment/features/paths/gravel-road.c", "east");
    addFeature("/lib/environment/features/paths/gravel-road.c", "west");
    addFeature("/lib/environment/features/trees/fir-stand.c", "north");
    addFeature("/lib/environment/features/landforms/bluff.c", "south");
    addExit("east",
        "/areas/northern-road/upper-northern-wilds/inland/wind-saddle.c");
    addExit("west",
        "/areas/northern-road/upper-northern-wilds/inland/ridge-path.c");
    addExit("south",
        "/areas/northern-road/upper-northern-wilds/inland/wrecked-coach.c");
}
