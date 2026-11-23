//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    setShortDescription("The naval headquarters overlooks the northern docks");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "west");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "east");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "south");
    addBuildingWithDoor(
        "/areas/eledhel/northern-city/naval-headquarters-building.c", "north",
        "/areas/eledhel/northern-city/naval-headquarters/0x0.c",
        "/lib/environment/doors/plank-door.c");
    addDecorator("road intersection");
    addExit("west", "/areas/eledhel/northern-city/22x8.c");
    addExit("east", "/areas/eledhel/northern-city/24x8.c");
    addExit("south", "/areas/eledhel/northern-city/23x7.c");
}
