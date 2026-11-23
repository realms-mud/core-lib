//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    setShortDescription("The Tirwen lane joins the southbound King's Road");
    addDecorator("village road T-south");
    addFeature("/lib/environment/features/paths/road.c", "west");
    addFeature("/lib/environment/features/paths/road.c", "east");
    addFeature("/lib/environment/features/paths/road.c", "south");
    addExit("west", "/areas/eledhel/tirwen/2x1.c");
    addExit("east", "/areas/eledhel/tirwen/4x1.c");
    addExit("south", "/areas/eledhel/south-rural-route-05/20x2.c");
}
