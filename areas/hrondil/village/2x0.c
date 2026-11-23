//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");

    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addObject("/areas/hrondil/characters/shepherd.c");

    addDecorator("village road corner NW");

    addExit("north", "/areas/hrondil/village/2x1.c");
    addExit("west", "/areas/hrondil/village/1x0.c");
}
