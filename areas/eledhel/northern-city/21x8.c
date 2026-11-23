//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    setShortDescription("Morleth's Stone, an herbalist's shop and home");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "west");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "east");
    addBuildingWithDoor(
        "/lib/environment/buildings/shops/herbalist.c", "south",
        "/areas/eledhel/northern-city/morleths-stone/0x0.c",
        "/lib/environment/doors/plank-door.c");
    addDecorator("east-west road");
    addExit("west", "/areas/eledhel/northern-city/20x8.c");
    addExit("east", "/areas/eledhel/northern-city/22x8.c");
}
