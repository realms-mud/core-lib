//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-clearing.c");
    addDecorator("forest trail T-north");
    setShortDescription("The stable yard");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addObject("/areas/evenholt/characters/cyril.c");
    addObject("/areas/evenholt/characters/hrothgil.c");
    addExit("west", "/areas/evenholt/grounds/20x4.c");
    addExit("east", "/areas/evenholt/grounds/22x4.c");
    addExit("north", "/areas/evenholt/grounds/21x3.c");
}
