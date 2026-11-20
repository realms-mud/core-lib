//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-clearing.c");
    addDecorator("forest trail south-west");
    setShortDescription("The garden stream and tool table");
    addFeature("/lib/environment/features/water/creek.c", "north");
    addFeature("/lib/environment/features/trees/elm-stand.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addObject("/areas/evenholt/characters/mirael.c");
    addExit("west", "/areas/evenholt/grounds/21x3.c");
    addExit("south", "/areas/evenholt/grounds/22x4.c");
}
