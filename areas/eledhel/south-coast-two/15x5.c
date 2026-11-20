//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/rocky-shoreline.c");
    setShortDescription("A splintered hull lies above the reach of the tide");
    addDecorator("rocky shore");
    addFeature("/lib/environment/features/water/rocky-ocean-shore.c");
    addExit("west", "/areas/eledhel/south-coast-two/14x5.c");
    addRandomCreature(({ "outlaw", "coyote", "raccoon" }));
}
