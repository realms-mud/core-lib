//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/rocky-shoreline.c");
    setShortDescription("A narrow shelf leads to a wreck above the tide");
    addDecorator("rocky shore");
    addFeature("/lib/environment/features/landforms/cliff.c");
    addExit("south", "/areas/eledhel/south-coast-two/14x6.c");
    addExit("east", "/areas/eledhel/south-coast-two/15x5.c");
}
