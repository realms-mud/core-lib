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
    addFeature("/lib/environment/features/paths/path.c", "south");

    addDecorator("village road T-east");

    addExit("north", "/areas/hrondil/village/0x1.c");
    addExit("east", "/areas/hrondil/village/1x0.c");
    addExit("south", "/areas/hrondil/grounds/1x2.c");
}
