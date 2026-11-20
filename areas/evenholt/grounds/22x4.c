//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/meadow.c");
    addDecorator("forest trail T-north");
    setShortDescription("The eastern edge of the yard");
    addFeature("/lib/environment/features/trees/elm-stand.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("west", "/areas/evenholt/grounds/21x4.c");
    addExit("east", "/areas/evenholt/grounds/23x4.c");
    addExit("north", "/areas/evenholt/grounds/22x3.c");
}
