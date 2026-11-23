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

    addDecorator("village road corner NW");

    addExit("north", "/areas/eledhel/estates/erator/grounds/2x1.c");
    addExit("west", "/areas/eledhel/estates/erator/grounds/1x2.c");
}
