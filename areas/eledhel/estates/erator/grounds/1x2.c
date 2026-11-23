//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");

    addFeature("/lib/environment/features/paths/path.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "west");

    addDecorator("village east-west road");

    addExit("east", "/areas/eledhel/estates/erator/grounds/2x2.c");
    addExit("west", "/areas/eledhel/estates/erator/grounds/0x2.c");
}
