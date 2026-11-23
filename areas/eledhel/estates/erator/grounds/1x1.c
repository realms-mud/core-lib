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
    addFeature("/lib/environment/features/plants/common-grain-strips.c",
        "north");

    addDecorator("village road corner NE");

    addExit("north", "/areas/eledhel/estates/erator/grounds/1x0.c");
    addExit("east", "/areas/eledhel/estates/erator/grounds/2x1.c");
}
