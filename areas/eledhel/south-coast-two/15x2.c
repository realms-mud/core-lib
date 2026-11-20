//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/rocky-shoreline.c");
    setShortDescription("The beacon's stone foundation is open to the sky");
    addDecorator("rocky shore");
    addFeature("/lib/environment/features/landforms/promontory.c");
    addExit("west", "/areas/eledhel/south-coast-two/14x2.c");
    addExit("south", "/areas/eledhel/south-coast-two/15x3.c");
}
