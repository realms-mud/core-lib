//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/paths/dirt-road.c", "west");

    addDecorator("village east-west road");

    addExit("east", "/areas/eledhel/estates/kirin/approach/9x0.c");
    addExit("west", "/areas/eledhel/estates/kirin/approach/7x0.c");
}
