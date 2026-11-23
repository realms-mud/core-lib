//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setRegionName("Northern Manor Road");
    setRegionType("rural");
    setRegionLevel(3);
    setDimensions(25, 10);
    setSettlementChance(-1);

    setEntryCoordinate(0, 0,
        "/areas/northern-road/northern-manor/0x0.c", "south",
        "/areas/northern-road/gundil-coast/9x8.c");
    setCoordinate(0, 2, "/areas/northern-road/northern-manor/0x2.c", "road");
    setCoordinate(0, 3, "/areas/northern-road/northern-manor/0x3.c", "road");
    setCoordinate(0, 4, "/areas/northern-road/northern-manor/0x4.c", "road");
    setCoordinate(0, 6, "/areas/northern-road/northern-manor/0x6.c", "road");
    setCoordinate(0, 7, "/areas/northern-road/northern-manor/0x7.c", "road");
    setCoordinate(0, 8, "/areas/northern-road/northern-manor/0x8.c", "road");

    setCoordinate(1, 0, "/areas/northern-road/northern-manor/1x0.c", "road");
    setCoordinate(1, 2, "/areas/northern-road/northern-manor/1x2.c", "road");
    setCoordinate(1, 4, "/areas/northern-road/northern-manor/1x4.c", "road");
    setCoordinate(1, 6, "/areas/northern-road/northern-manor/1x6.c", "road");
    setCoordinate(1, 8, "/areas/northern-road/northern-manor/1x8.c", "road");

    setCoordinate(2, 0, "/areas/northern-road/northern-manor/2x0.c", "road");
    setCoordinate(2, 2, "/areas/northern-road/northern-manor/2x2.c", "road");
    setCoordinate(2, 4, "/areas/northern-road/northern-manor/2x4.c", "road");
    setCoordinate(2, 6, "/areas/northern-road/northern-manor/2x6.c", "road");
    setCoordinate(2, 8, "/areas/northern-road/northern-manor/2x8.c", "road");

    setCoordinate(3, 0, "/areas/northern-road/northern-manor/3x0.c", "road");
    setCoordinate(3, 2, "/areas/northern-road/northern-manor/3x2.c", "road");
    setCoordinate(3, 4, "/areas/northern-road/northern-manor/3x4.c", "road");
    setCoordinate(3, 6, "/areas/northern-road/northern-manor/3x6.c", "road");
    setCoordinate(3, 8, "/areas/northern-road/northern-manor/3x8.c", "road");

    setCoordinate(4, 0, "/areas/northern-road/northern-manor/4x0.c", "road");
    setCoordinate(4, 2, "/areas/northern-road/northern-manor/4x2.c", "road");
    setCoordinate(4, 4, "/areas/northern-road/northern-manor/4x4.c", "road");
    setCoordinate(4, 6, "/areas/northern-road/northern-manor/4x6.c", "road");
    setCoordinate(4, 8, "/areas/northern-road/northern-manor/4x8.c", "road");

    setCoordinate(5, 0, "/areas/northern-road/northern-manor/5x0.c", "road");
    setCoordinate(5, 2, "/areas/northern-road/northern-manor/5x2.c", "road");
    setCoordinate(5, 4, "/areas/northern-road/northern-manor/5x4.c", "road");
    setCoordinate(5, 6, "/areas/northern-road/northern-manor/5x6.c", "road");
    setCoordinate(5, 8, "/areas/northern-road/northern-manor/5x8.c", "road");

    setCoordinate(6, 0, "/areas/northern-road/northern-manor/6x0.c", "road");
    setCoordinate(6, 2, "/areas/northern-road/northern-manor/6x2.c", "road");
    setCoordinate(6, 4, "/areas/northern-road/northern-manor/6x4.c", "road");
    setCoordinate(6, 6, "/areas/northern-road/northern-manor/6x6.c", "road");
    setCoordinate(6, 8, "/areas/northern-road/northern-manor/6x8.c", "road");

    setCoordinate(7, 0, "/areas/northern-road/northern-manor/7x0.c", "road");
    setCoordinate(7, 2, "/areas/northern-road/northern-manor/7x2.c", "road");
    setCoordinate(7, 4, "/areas/northern-road/northern-manor/7x4.c", "road");
    setCoordinate(7, 6, "/areas/northern-road/northern-manor/7x6.c", "road");
    setCoordinate(7, 8, "/areas/northern-road/northern-manor/7x8.c", "road");

    setCoordinate(8, 0, "/areas/northern-road/northern-manor/8x0.c", "road");
    setCoordinate(8, 2, "/areas/northern-road/northern-manor/8x2.c", "road");
    setCoordinate(8, 4, "/areas/northern-road/northern-manor/8x4.c", "road");
    setCoordinate(8, 6, "/areas/northern-road/northern-manor/8x6.c", "road");
    setCoordinate(8, 8, "/areas/northern-road/northern-manor/8x8.c", "road");

    setCoordinate(9, 0, "/areas/northern-road/northern-manor/9x0.c", "road");
    setCoordinate(9, 2, "/areas/northern-road/northern-manor/9x2.c", "road");
    setCoordinate(9, 4, "/areas/northern-road/northern-manor/9x4.c", "road");
    setCoordinate(9, 6, "/areas/northern-road/northern-manor/9x6.c", "road");
    setCoordinate(9, 8, "/areas/northern-road/northern-manor/9x8.c", "road");

    setCoordinate(10, 0, "/areas/northern-road/northern-manor/10x0.c", "road");
    setCoordinate(10, 2, "/areas/northern-road/northern-manor/10x2.c", "road");
    setCoordinate(10, 4, "/areas/northern-road/northern-manor/10x4.c", "road");
    setCoordinate(10, 6, "/areas/northern-road/northern-manor/10x6.c", "road");
    setCoordinate(10, 8, "/areas/northern-road/northern-manor/10x8.c", "road");

    setCoordinate(11, 0, "/areas/northern-road/northern-manor/11x0.c", "road");
    setCoordinate(11, 2, "/areas/northern-road/northern-manor/11x2.c", "road");
    setCoordinate(11, 4, "/areas/northern-road/northern-manor/11x4.c", "road");
    setCoordinate(11, 6, "/areas/northern-road/northern-manor/11x6.c", "road");
    setCoordinate(11, 8, "/areas/northern-road/northern-manor/11x8.c", "road");

    setCoordinate(12, 0, "/areas/northern-road/northern-manor/12x0.c", "road");
    setCoordinate(12, 2, "/areas/northern-road/northern-manor/12x2.c", "road");
    setCoordinate(12, 4, "/areas/northern-road/northern-manor/12x4.c", "road");
    setCoordinate(12, 6, "/areas/northern-road/northern-manor/12x6.c", "road");
    setCoordinate(12, 8, "/areas/northern-road/northern-manor/12x8.c", "road");

    setCoordinate(13, 0, "/areas/northern-road/northern-manor/13x0.c", "road");
    setCoordinate(13, 2, "/areas/northern-road/northern-manor/13x2.c", "road");
    setCoordinate(13, 4, "/areas/northern-road/northern-manor/13x4.c", "road");
    setCoordinate(13, 6, "/areas/northern-road/northern-manor/13x6.c", "road");
    setCoordinate(13, 8, "/areas/northern-road/northern-manor/13x8.c", "road");

    setCoordinate(14, 0, "/areas/northern-road/northern-manor/14x0.c", "road");
    setCoordinate(14, 2, "/areas/northern-road/northern-manor/14x2.c", "road");
    setCoordinate(14, 4, "/areas/northern-road/northern-manor/14x4.c", "road");
    setCoordinate(14, 6, "/areas/northern-road/northern-manor/14x6.c", "road");
    setCoordinate(14, 8, "/areas/northern-road/northern-manor/14x8.c", "road");

    setCoordinate(15, 0, "/areas/northern-road/northern-manor/15x0.c", "road");
    setCoordinate(15, 2, "/areas/northern-road/northern-manor/15x2.c", "road");
    setCoordinate(15, 4, "/areas/northern-road/northern-manor/15x4.c", "road");
    setCoordinate(15, 6, "/areas/northern-road/northern-manor/15x6.c", "road");
    setCoordinate(15, 8, "/areas/northern-road/northern-manor/15x8.c", "road");

    setCoordinate(16, 0, "/areas/northern-road/northern-manor/16x0.c", "road");
    setCoordinate(16, 2, "/areas/northern-road/northern-manor/16x2.c", "road");
    setCoordinate(16, 4, "/areas/northern-road/northern-manor/16x4.c", "road");
    setCoordinate(16, 6, "/areas/northern-road/northern-manor/16x6.c", "road");
    setCoordinate(16, 8, "/areas/northern-road/northern-manor/16x8.c", "road");

    setCoordinate(17, 0, "/areas/northern-road/northern-manor/17x0.c", "road");
    setCoordinate(17, 2, "/areas/northern-road/northern-manor/17x2.c", "road");
    setCoordinate(17, 4, "/areas/northern-road/northern-manor/17x4.c", "road");
    setCoordinate(17, 6, "/areas/northern-road/northern-manor/17x6.c", "road");
    setCoordinate(17, 8, "/areas/northern-road/northern-manor/17x8.c", "road");

    setCoordinate(18, 0, "/areas/northern-road/northern-manor/18x0.c", "road");
    setCoordinate(18, 2, "/areas/northern-road/northern-manor/18x2.c", "road");
    setCoordinate(18, 4, "/areas/northern-road/northern-manor/18x4.c", "road");
    setCoordinate(18, 6, "/areas/northern-road/northern-manor/18x6.c", "road");
    setCoordinate(18, 8, "/areas/northern-road/northern-manor/18x8.c", "road");

    setCoordinate(19, 0, "/areas/northern-road/northern-manor/19x0.c", "road");
    setCoordinate(19, 2, "/areas/northern-road/northern-manor/19x2.c", "road");
    setCoordinate(19, 4, "/areas/northern-road/northern-manor/19x4.c", "road");
    setCoordinate(19, 6, "/areas/northern-road/northern-manor/19x6.c", "road");
    setCoordinate(19, 8, "/areas/northern-road/northern-manor/19x8.c", "road");

    setCoordinate(20, 0, "/areas/northern-road/northern-manor/20x0.c", "road");
    setCoordinate(20, 2, "/areas/northern-road/northern-manor/20x2.c", "road");
    setCoordinate(20, 4, "/areas/northern-road/northern-manor/20x4.c", "road");
    setCoordinate(20, 6, "/areas/northern-road/northern-manor/20x6.c", "road");
    setCoordinate(20, 8, "/areas/northern-road/northern-manor/20x8.c", "road");

    setCoordinate(21, 0, "/areas/northern-road/northern-manor/21x0.c", "road");
    setCoordinate(21, 2, "/areas/northern-road/northern-manor/21x2.c", "road");
    setCoordinate(21, 4, "/areas/northern-road/northern-manor/21x4.c", "road");
    setCoordinate(21, 6, "/areas/northern-road/northern-manor/21x6.c", "road");
    setCoordinate(21, 8, "/areas/northern-road/northern-manor/21x8.c", "road");

    setCoordinate(22, 0, "/areas/northern-road/northern-manor/22x0.c", "road");
    setCoordinate(22, 2, "/areas/northern-road/northern-manor/22x2.c", "road");
    setCoordinate(22, 4, "/areas/northern-road/northern-manor/22x4.c", "road");
    setCoordinate(22, 6, "/areas/northern-road/northern-manor/22x6.c", "road");
    setCoordinate(22, 8, "/areas/northern-road/northern-manor/22x8.c", "road");

    setCoordinate(23, 0, "/areas/northern-road/northern-manor/23x0.c", "road");
    setCoordinate(23, 2, "/areas/northern-road/northern-manor/23x2.c", "road");
    setCoordinate(23, 4, "/areas/northern-road/northern-manor/23x4.c", "road");
    setCoordinate(23, 6, "/areas/northern-road/northern-manor/23x6.c", "road");
    setCoordinate(23, 8, "/areas/northern-road/northern-manor/23x8.c", "road");

    setCoordinate(24, 0, "/areas/northern-road/northern-manor/24x0.c", "road");
    setCoordinate(24, 1, "/areas/northern-road/northern-manor/24x1.c", "road");
    setCoordinate(24, 2, "/areas/northern-road/northern-manor/24x2.c", "road");
    setCoordinate(24, 4, "/areas/northern-road/northern-manor/24x4.c", "road");
    setCoordinate(24, 5, "/areas/northern-road/northern-manor/24x5.c", "road");
    setCoordinate(24, 6, "/areas/northern-road/northern-manor/24x6.c", "road");
    setCoordinate(24, 8, "/areas/northern-road/northern-manor/24x8.c", "road");
}
