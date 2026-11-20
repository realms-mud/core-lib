//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    setShortDescription("The old caravan shed");
    addDecorator("village square");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("east", "/areas/linwaeth/12x8.c");
}
