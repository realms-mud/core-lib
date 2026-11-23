//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-clearing.c");

    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "east");

    addDecorator("village road corner NE");

    addExit("north", "/areas/eledhel/estates/gundil/grounds/0x1.c");
    addExit("east", "/areas/eledhel/estates/gundil/grounds/1x2.c");
}
