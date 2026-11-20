//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setRegionName("Evenholt Manor");
    setRegionType("stone keep");
    setDimensions(5, 5);
    setEntryCoordinate(0, 1, "/areas/evenholt/manor/0x1.c", "south",
        "/areas/evenholt/grounds/20x4.c");

    setCoordinate(0, 0, "/areas/evenholt/manor/0x0.c", "room");
    setCoordinate(1, 0, "/areas/evenholt/manor/1x0.c", "room");
    setCoordinate(2, 0, "/areas/evenholt/manor/2x0.c", "room");
    setCoordinate(3, 0, "/areas/evenholt/manor/3x0.c", "room");
    setCoordinate(0, 1, "/areas/evenholt/manor/0x1.c", "entry");
    setCoordinate(1, 1, "/areas/evenholt/manor/1x1.c", "room");
    setCoordinate(2, 1, "/areas/evenholt/manor/2x1.c", "room");
    setCoordinate(3, 1, "/areas/evenholt/manor/3x1.c", "room");
    setCoordinate(0, 2, "/areas/evenholt/manor/0x2.c", "room");
    setCoordinate(1, 2, "/areas/evenholt/manor/1x2.c", "path");
    setCoordinate(2, 2, "/areas/evenholt/manor/2x2.c", "room");
    setCoordinate(3, 2, "/areas/evenholt/manor/3x2.c", "room");
}
