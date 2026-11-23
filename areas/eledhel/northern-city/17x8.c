//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    setShortDescription("The entrance to Eledhel's small museum");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "east");
    addBuildingWithDoor(
        "/lib/environment/buildings/civic/museum-small.c", "north",
        "/areas/eledhel/northern-city/museum/0x0.c",
        "/lib/environment/doors/plank-door.c");
    addDecorator("path");
    addExit("east", "/areas/eledhel/northern-city/18x8.c");
}
