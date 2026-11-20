//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/rocky-shoreline.c");
    setShortDescription("A stone stair climbs toward the ruined beacon");
    addDecorator("rocky shore");
    addFeature("/lib/environment/features/stairs/stone-steps.c");
    addExit("south", "/areas/eledhel/south-coast-two/14x3.c");
    addExit("east", "/areas/eledhel/south-coast-two/15x2.c");
}
