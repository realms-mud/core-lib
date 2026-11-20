//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setRegionName("Evenholt limestone caves");
    setRegionType("cave");
    setRegionLevel(4);
    setDimensions(5, 5);
    setEntryCoordinate(0, 0,
        "/areas/evenholt/limestone-caves/0x0.c", "up",
        "/areas/evenholt/grounds/20x0.c");

    setCoordinate(0, 0, "/areas/evenholt/limestone-caves/0x0.c", "entry");
    setCoordinate(1, 0, "/areas/evenholt/limestone-caves/1x0.c", "path");
    setCoordinate(1, 1, "/areas/evenholt/limestone-caves/1x1.c", "room");
    setCoordinate(2, 1, "/areas/evenholt/limestone-caves/2x1.c", "room");
    setCoordinate(2, 2, "/areas/evenholt/limestone-caves/2x2.c", "path");
    setCoordinate(3, 2, "/areas/evenholt/limestone-caves/3x2.c", "path");
    setCoordinate(3, 1, "/areas/evenholt/limestone-caves/3x1.c", "path");
    setCoordinate(4, 1, "/areas/evenholt/limestone-caves/4x1.c", "room");
    setCoordinate(4, 0, "/areas/evenholt/limestone-caves/4x0.c", "exit");
}
