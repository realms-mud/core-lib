//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    setShortDescription("The western lane through Llenwych fields");
    addDecorator("farm path north-east bend");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("east", "/areas/eledhel/estates/llenwych/grounds/0x2.c");
    addExit("west", "/areas/eledhel/estates/llenwych/grounds/2x2.c");
    addExit("north", "/areas/eledhel/estates/llenwych/grounds/1x1.c");
}
