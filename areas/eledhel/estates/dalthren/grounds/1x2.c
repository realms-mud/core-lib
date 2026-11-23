//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");

    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addObject("/areas/eledhel/estates/dalthren/characters/steward.c");

    addDecorator("village road corner NE");

    addExit("north",
        "/areas/eledhel/estates/dalthren/grounds/1x1.c");
    addExit("east", "/areas/eledhel/estates/dalthren/grounds/2x2.c");
}
