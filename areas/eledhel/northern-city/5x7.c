//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    setShortDescription("Arena Park, between the prison and Phaedra Hall");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "south");
    addDecorator("path");
    addBuildingWithDoor("/lib/environment/buildings/civic/prison.c", "west",
        "/areas/eledhel/northern-city/prison/0x2.c",
        "/lib/environment/doors/plank-door.c");
    addBuildingWithDoor(
        "/lib/environment/buildings/civic/gladiator-ring.c", "east",
        "/areas/eledhel/northern-city/arena/4x2.c",
        "/lib/environment/doors/plank-door.c");
    addExit("south", "/areas/eledhel/northern-city/5x6.c");
}
