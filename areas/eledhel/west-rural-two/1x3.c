//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail north-west");
    setShortDescription("The sinkhole ridge");
    addFeature("/lib/environment/features/trees/ash-stand.c", "west");
    addFeature("/lib/environment/features/landforms/sinkhole.c", "west");
    addFeature("/lib/environment/features/landforms/distant-peak.c", "west");

    addExit("north", "/areas/eledhel/west-rural-two/1x4.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("west", "/areas/eledhel/west-rural-two/0x3.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}
