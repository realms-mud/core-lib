//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    setShortDescription("The harbor watch keeps a post above the market");
    addDecorator("village cottage");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("south", "/areas/anor/10x2.c");
}
