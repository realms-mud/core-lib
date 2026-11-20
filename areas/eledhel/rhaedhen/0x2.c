//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    setShortDescription("The King's Road enters Rhaedhen");
    addDecorator("village east-west road");
    addFeature("/lib/environment/features/paths/road.c", "south");
    addFeature("/lib/environment/features/paths/road.c", "east");
    addExit("south", "/areas/eledhel/southwest-rural-three/12x3.c");
    addExit("east", "/areas/eledhel/rhaedhen/1x2.c");
}
