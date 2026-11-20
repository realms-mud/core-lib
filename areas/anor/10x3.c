//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    setShortDescription("A fish and salt stall faces the market square");
    addDecorator("village market");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("north", "/areas/anor/10x2.c");
    addExit("east", "/areas/anor/11x3.c");
    addObject("/areas/anor/characters/salt-merchant.c");
}
