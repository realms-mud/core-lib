//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail north-east");
    setShortDescription("The ravine's western shelf");
    addFeature("/lib/environment/features/landforms/cliff.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("north", "/areas/evenholt/river-celebuin/15x7.c");
    addExit("east", "/areas/evenholt/river-celebuin/16x8.c");
}
