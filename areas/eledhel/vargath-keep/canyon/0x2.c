//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail east-west");
    setShortDescription("The cave stream spills into a bowl-shaped canyon");
    addFeature("/lib/environment/features/water/canyon-river.c", "south");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("west", "/areas/eledhel/vargath-keep/limestone-caves/4x2.c");
    addExit("east", "/areas/eledhel/vargath-keep/canyon/1x2.c");
}
