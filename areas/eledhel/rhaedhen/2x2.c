//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    setShortDescription("The small green at Rhaedhen's crossroads");
    addDecorator("village square");
    addFeature("/lib/environment/features/paths/road.c", "west");
    addFeature("/lib/environment/features/paths/road.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("west", "/areas/eledhel/rhaedhen/1x2.c");
    addExit("north", "/areas/eledhel/rhaedhen/2x1.c");
    addExit("east", "/areas/eledhel/rhaedhen/3x2.c");
    addExit("south", "/areas/eledhel/rhaedhen/2x3.c");
}
