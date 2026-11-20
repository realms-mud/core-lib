//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/rocky-shoreline.c");
    setShortDescription("Tide pools mark the foot of the headland");
    addDecorator("rocky shore");
    addFeature("/lib/environment/features/water/tidal-pool.c");
    addExit("west", "/areas/eledhel/south-coast-two/16x3.c");
    addExit("east", "/areas/eledhel/south-coast-two/18x3.c");
}
