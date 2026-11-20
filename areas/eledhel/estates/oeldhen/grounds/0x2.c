//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    setShortDescription("The Oeldhen estate lane");
    addDecorator("farm path north-east bend");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addFeature("/lib/environment/features/paths/road.c", "west");
    addExit("west", "/areas/eledhel/southern-rural/4x6.c");
    addExit("east", "/areas/eledhel/estates/oeldhen/grounds/1x2.c");
}
