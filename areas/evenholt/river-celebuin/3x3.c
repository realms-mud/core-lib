//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail south-east");
    setShortDescription("The leaf-covered path above the river");
    addFeature("/lib/environment/features/trees/oak-stand.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("south", "/areas/evenholt/river-celebuin/3x4.c");
    addExit("east", "/areas/evenholt/river-celebuin/4x3.c");
}
