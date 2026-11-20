//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/meadow.c");
    addDecorator("forest trail north-west");
    setShortDescription("The steep eastern grade");
    addFeature("/lib/environment/features/landforms/hill.c", "east");
    addFeature("/lib/environment/features/trees/oak-stand.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("west", "/areas/evenholt/grounds/23x4.c");
    addExit("north", "/areas/evenholt/grounds/24x3.c");
}
