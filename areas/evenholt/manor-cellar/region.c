//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setRegionName("Evenholt Manor cellar");
    setRegionType("stone keep");
    setDimensions(5, 5);
    setEntryCoordinate(0, 0,
        "/areas/evenholt/manor-cellar/0x0.c", "up",
        "/areas/evenholt/manor/3x1.c");

    setCoordinate(0, 0, "/areas/evenholt/manor-cellar/0x0.c", "entry");
    setCoordinate(1, 0, "/areas/evenholt/manor-cellar/1x0.c", "room");
    setCoordinate(2, 0, "/areas/evenholt/manor-cellar/2x0.c", "room");
}
