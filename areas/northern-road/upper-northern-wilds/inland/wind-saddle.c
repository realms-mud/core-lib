//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/rocky-mountain.c");
    addFeature("/lib/environment/features/paths/gravel-road.c", "east");
    addFeature("/lib/environment/features/paths/gravel-road.c", "west");
    addFeature("/lib/environment/features/landforms/tor.c", "north");
    addFeature("/lib/environment/features/trees/pine-stand.c", "south");
    addItem("/lib/environment/items/objects/fox-tracks.c", "northwest");
    addExit("east",
        "/areas/northern-road/upper-northern-wilds/inland/low-track.c");
    addExit("west",
        "/areas/northern-road/upper-northern-wilds/inland/fir-shelf.c");
    addRandomCreature(({ "red fox", "white-tail deer" }));
}
