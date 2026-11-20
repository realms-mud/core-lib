//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    setShortDescription("A small sheep holding sits above the drove road");
    addDecorator("village cottage");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("east", "/areas/eledhel/south-coast-one/11x6.c");
    addExit("south", "/areas/eledhel/south-coast-one/10x7.c");
    addObject("/areas/eledhel/south-coast-one/characters/shepherd.c");
}
