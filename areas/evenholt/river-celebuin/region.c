//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setRegionName("River Celebuin and the gorge");
    setRegionType("forest");
    setRegionLevel(4);
    setDimensions(25, 10);
    setSettlementChance(-1);
    setEntryCoordinate(0, 4,
        "/areas/evenholt/river-celebuin/0x4.c", "west",
        "/areas/evenholt/grounds/24x2.c");

    setCoordinate(0, 4, "/areas/evenholt/river-celebuin/0x4.c", "entry");
    setCoordinate(1, 4, "/areas/evenholt/river-celebuin/1x4.c", "path");
    setCoordinate(2, 4, "/areas/evenholt/river-celebuin/2x4.c", "path");
    setCoordinate(3, 4, "/areas/evenholt/river-celebuin/3x4.c", "path");
    setCoordinate(4, 4, "/areas/evenholt/river-celebuin/4x4.c", "path");
    setCoordinate(5, 4, "/areas/evenholt/river-celebuin/5x4.c", "path");
    setCoordinate(6, 4, "/areas/evenholt/river-celebuin/6x4.c", "path");
    setCoordinate(7, 4, "/areas/evenholt/river-celebuin/7x4.c", "path");
    setCoordinate(8, 4, "/areas/evenholt/river-celebuin/8x4.c", "path");
    setCoordinate(9, 4, "/areas/evenholt/river-celebuin/9x4.c", "path");
    setCoordinate(10, 4, "/areas/evenholt/river-celebuin/10x4.c", "room");
    setCoordinate(11, 4, "/areas/evenholt/river-celebuin/11x4.c", "room");
    setCoordinate(12, 4, "/areas/evenholt/river-celebuin/12x4.c", "path");
    setCoordinate(3, 3, "/areas/evenholt/river-celebuin/3x3.c", "path");
    setCoordinate(4, 3, "/areas/evenholt/river-celebuin/4x3.c", "path");
    setCoordinate(5, 3, "/areas/evenholt/river-celebuin/5x3.c", "path");
    setCoordinate(12, 5, "/areas/evenholt/river-celebuin/12x5.c", "path");
    setCoordinate(13, 5, "/areas/evenholt/river-celebuin/13x5.c", "path");
    setCoordinate(14, 5, "/areas/evenholt/river-celebuin/14x5.c", "path");
    setCoordinate(15, 5, "/areas/evenholt/river-celebuin/15x5.c", "path");
    setCoordinate(16, 5, "/areas/evenholt/river-celebuin/16x5.c", "path");
    setCoordinate(17, 5, "/areas/evenholt/river-celebuin/17x5.c", "path");
    setCoordinate(15, 6, "/areas/evenholt/river-celebuin/15x6.c", "path");
    setCoordinate(16, 6, "/areas/evenholt/river-celebuin/16x6.c", "room");
    setCoordinate(17, 6, "/areas/evenholt/river-celebuin/17x6.c", "path");
    setCoordinate(15, 7, "/areas/evenholt/river-celebuin/15x7.c", "path");
    setCoordinate(16, 7, "/areas/evenholt/river-celebuin/16x7.c", "path");
    setCoordinate(17, 7, "/areas/evenholt/river-celebuin/17x7.c", "path");
    setCoordinate(15, 8, "/areas/evenholt/river-celebuin/15x8.c", "path");
    setCoordinate(16, 8, "/areas/evenholt/river-celebuin/16x8.c", "path");
    setCoordinate(17, 8, "/areas/evenholt/river-celebuin/17x8.c", "path");
}
