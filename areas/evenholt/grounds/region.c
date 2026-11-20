//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setRegionName("Evenholt and the western grounds");
    setRegionType("forest");
    setRegionLevel(3);
    setDimensions(25, 10);
    setSettlementChance(-1);
    setEntryCoordinate(0, 4,
        "/areas/evenholt/grounds/0x4.c", "west",
        "/areas/eledhel/west-rural-two/24x4.c");

    setCoordinate(0, 4, "/areas/evenholt/grounds/0x4.c", "entry");
    setCoordinate(1, 4, "/areas/evenholt/grounds/1x4.c", "path");
    setCoordinate(2, 4, "/areas/evenholt/grounds/2x4.c", "path");
    setCoordinate(3, 4, "/areas/evenholt/grounds/3x4.c", "path");
    setCoordinate(4, 4, "/areas/evenholt/grounds/4x4.c", "path");
    setCoordinate(5, 4, "/areas/evenholt/grounds/5x4.c", "path");
    setCoordinate(6, 4, "/areas/evenholt/grounds/6x4.c", "path");
    setCoordinate(7, 4, "/areas/evenholt/grounds/7x4.c", "path");
    setCoordinate(8, 4, "/areas/evenholt/grounds/8x4.c", "path");
    setCoordinate(9, 4, "/areas/evenholt/grounds/9x4.c", "path");
    setCoordinate(10, 4, "/areas/evenholt/grounds/10x4.c", "path");
    setCoordinate(11, 4, "/areas/evenholt/grounds/11x4.c", "path");
    setCoordinate(12, 4, "/areas/evenholt/grounds/12x4.c", "path");
    setCoordinate(13, 4, "/areas/evenholt/grounds/13x4.c", "path");
    setCoordinate(14, 4, "/areas/evenholt/grounds/14x4.c", "path");
    setCoordinate(15, 4, "/areas/evenholt/grounds/15x4.c", "path");
    setCoordinate(16, 4, "/areas/evenholt/grounds/16x4.c", "path");
    setCoordinate(17, 4, "/areas/evenholt/grounds/17x4.c", "path");
    setCoordinate(18, 4, "/areas/evenholt/grounds/18x4.c", "path");
    setCoordinate(19, 4, "/areas/evenholt/grounds/19x4.c", "path");
    setCoordinate(20, 4, "/areas/evenholt/grounds/20x4.c", "room");
    setCoordinate(21, 4, "/areas/evenholt/grounds/21x4.c", "room");
    setCoordinate(22, 4, "/areas/evenholt/grounds/22x4.c", "room");
    setCoordinate(23, 4, "/areas/evenholt/grounds/23x4.c", "room");
    setCoordinate(24, 4, "/areas/evenholt/grounds/24x4.c", "room");
    setCoordinate(6, 3, "/areas/evenholt/grounds/6x3.c", "path");
    setCoordinate(7, 3, "/areas/evenholt/grounds/7x3.c", "room");
    setCoordinate(16, 5, "/areas/evenholt/grounds/16x5.c", "path");
    setCoordinate(17, 5, "/areas/evenholt/grounds/17x5.c", "path");
    setCoordinate(18, 5, "/areas/evenholt/grounds/18x5.c", "path");
    setCoordinate(19, 5, "/areas/evenholt/grounds/19x5.c", "path");
    setCoordinate(20, 5, "/areas/evenholt/grounds/20x5.c", "path");
    setCoordinate(19, 3, "/areas/evenholt/grounds/19x3.c", "room");
    setCoordinate(20, 3, "/areas/evenholt/grounds/20x3.c", "room");
    setCoordinate(21, 3, "/areas/evenholt/grounds/21x3.c", "room");
    setCoordinate(22, 3, "/areas/evenholt/grounds/22x3.c", "room");
    setCoordinate(19, 0, "/areas/evenholt/grounds/19x0.c", "room");
    setCoordinate(20, 0, "/areas/evenholt/grounds/20x0.c", "room");
    setCoordinate(21, 0, "/areas/evenholt/grounds/21x0.c", "room");
    setCoordinate(19, 1, "/areas/evenholt/grounds/19x1.c", "path");
    setCoordinate(20, 1, "/areas/evenholt/grounds/20x1.c", "path");
    setCoordinate(21, 1, "/areas/evenholt/grounds/21x1.c", "path");
    setCoordinate(19, 2, "/areas/evenholt/grounds/19x2.c", "path");
    setCoordinate(20, 2, "/areas/evenholt/grounds/20x2.c", "path");
    setCoordinate(21, 2, "/areas/evenholt/grounds/21x2.c", "path");
    setCoordinate(22, 0, "/areas/evenholt/grounds/22x0.c", "path");
    setCoordinate(23, 0, "/areas/evenholt/grounds/23x0.c", "path");
    setCoordinate(24, 0, "/areas/evenholt/grounds/24x0.c", "path");
    setCoordinate(24, 1, "/areas/evenholt/grounds/24x1.c", "path");
    setCoordinate(24, 2, "/areas/evenholt/grounds/24x2.c", "room");
    setCoordinate(24, 3, "/areas/evenholt/grounds/24x3.c", "path");
}
