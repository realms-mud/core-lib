//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    setShortDescription("The Celedrath coastal estate lane");
    addDecorator("farm path north-east bend");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addFeature("/lib/environment/features/paths/road.c", "east");
    addExit("east", "/areas/eledhel/southwest-rural-three/20x3.c");
    addExit("west", "/areas/eledhel/estates/celedrath/grounds/1x2.c");
}
