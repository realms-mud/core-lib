//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/rocky-mountain.c");
    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addFeature("/lib/environment/features/landforms/tor.c", "north");
    addFeature("/lib/environment/features/water/spring.c", "south");
    addItem(
        "/lib/environment/items/objects/spring-votive-stones.c", "south");
    addDecorator("village east-west road");
    addExit("east", "/areas/northern-road/upper-northern-wilds/12x0.c");
    addExit("west", "/areas/northern-road/upper-northern-wilds/10x0.c");
    addExit("north",
        "/areas/northern-road/upper-northern-wilds/inland/return-slope.c");
}
