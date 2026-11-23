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

    addDecorator("village road corner SW");

    addExit("south", "/areas/eledhel/estates/belectar/grounds/2x1.c");
    addExit("west", "/areas/eledhel/estates/belectar/grounds/1x0.c");
}
