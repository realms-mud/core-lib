//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    setShortDescription("Rhaedhen's lane of cottages and gardens");
    addDecorator("village east-west road");
    addFeature("/lib/environment/features/paths/road.c", "west");
    addFeature("/lib/environment/features/paths/road.c", "east");
    addExit("west", "/areas/eledhel/rhaedhen/0x2.c");
    addExit("east", "/areas/eledhel/rhaedhen/2x2.c");
}
