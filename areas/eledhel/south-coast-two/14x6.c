//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/rocky-shoreline.c");
    setShortDescription("A shelf of stone overlooks the southern surf");
    addDecorator("rocky shore");
    addFeature("/lib/environment/features/water/rocky-ocean-shore.c");
    addExit("west", "/areas/eledhel/south-coast-two/13x6.c");
    addExit("north", "/areas/eledhel/south-coast-two/14x5.c");
}
