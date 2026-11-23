//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");

    addFeature("/lib/environment/features/paths/path.c", "south");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addObject("/areas/eledhel/estates/kirin/characters/ansel.c");

    addDecorator("village road corner SW");

    addExit("south", "/areas/eledhel/estates/kirin/grounds/2x1.c");
    addExit("west", "/areas/eledhel/estates/kirin/grounds/1x0.c");
}
