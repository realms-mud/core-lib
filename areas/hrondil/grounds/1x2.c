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
    addFeature("/lib/environment/features/paths/path.c", "west");

    addDecorator("village road T-north");

    addExit("north", "/areas/hrondil/village/0x0.c");
    addExit("east", "/areas/hrondil/grounds/2x2.c");
    addExit("west", "/areas/hrondil/grounds/0x2.c");
}
