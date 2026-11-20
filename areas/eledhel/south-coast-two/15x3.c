//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/rocky-shoreline.c");
    setShortDescription("The path passes the broken beacon's lower stones");
    addDecorator("coast trail T-north");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("west", "/areas/eledhel/south-coast-two/14x3.c");
    addExit("east", "/areas/eledhel/south-coast-two/16x3.c");
    addExit("north", "/areas/eledhel/south-coast-two/15x2.c");
}
