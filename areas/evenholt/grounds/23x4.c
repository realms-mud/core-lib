//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/meadow.c");
    addDecorator("forest trail east-west");
    setShortDescription("The long grass east of the house");
    addFeature("/lib/environment/features/landforms/hill.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("west", "/areas/evenholt/grounds/22x4.c");
    addExit("east", "/areas/evenholt/grounds/24x4.c");
}
