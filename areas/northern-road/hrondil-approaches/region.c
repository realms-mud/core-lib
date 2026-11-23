//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setRegionName("Hrondil Road");
    setRegionType("rural");
    setRegionLevel(5);
    setSettlementChance(-1);
    setDimensions(25, 9);

    setEntryCoordinate(0, 0,
        "/areas/northern-road/hrondil-approaches/0x0.c", "south",
        "/areas/northern-road/belathon-eolach/24x8.c");
    setCoordinate(0, 2, "/areas/northern-road/hrondil-approaches/0x2.c", "road");
    setCoordinate(0, 3, "/areas/northern-road/hrondil-approaches/0x3.c", "road");
    setCoordinate(0, 4, "/areas/northern-road/hrondil-approaches/0x4.c", "road");
    setCoordinate(0, 6, "/areas/northern-road/hrondil-approaches/0x6.c", "road");
    setCoordinate(0, 7, "/areas/northern-road/hrondil-approaches/0x7.c", "road");
    setCoordinate(0, 8, "/areas/northern-road/hrondil-approaches/0x8.c", "road");

    setCoordinate(1, 0, "/areas/northern-road/hrondil-approaches/1x0.c", "road");
    setCoordinate(1, 2, "/areas/northern-road/hrondil-approaches/1x2.c", "road");
    setCoordinate(1, 4, "/areas/northern-road/hrondil-approaches/1x4.c", "road");
    setCoordinate(1, 6, "/areas/northern-road/hrondil-approaches/1x6.c", "road");
    setCoordinate(1, 8, "/areas/northern-road/hrondil-approaches/1x8.c", "road");

    setCoordinate(2, 0, "/areas/northern-road/hrondil-approaches/2x0.c", "road");
    setCoordinate(2, 2, "/areas/northern-road/hrondil-approaches/2x2.c", "road");
    setCoordinate(2, 4, "/areas/northern-road/hrondil-approaches/2x4.c", "road");
    setCoordinate(2, 6, "/areas/northern-road/hrondil-approaches/2x6.c", "road");
    setCoordinate(2, 8, "/areas/northern-road/hrondil-approaches/2x8.c", "road");

    setCoordinate(3, 0, "/areas/northern-road/hrondil-approaches/3x0.c", "road");
    setCoordinate(3, 2, "/areas/northern-road/hrondil-approaches/3x2.c", "road");
    setCoordinate(3, 4, "/areas/northern-road/hrondil-approaches/3x4.c", "road");
    setCoordinate(3, 6, "/areas/northern-road/hrondil-approaches/3x6.c", "road");
    setCoordinate(3, 8, "/areas/northern-road/hrondil-approaches/3x8.c", "road");

    setCoordinate(4, 0, "/areas/northern-road/hrondil-approaches/4x0.c", "road");
    setCoordinate(4, 2, "/areas/northern-road/hrondil-approaches/4x2.c", "road");
    setCoordinate(4, 4, "/areas/northern-road/hrondil-approaches/4x4.c", "road");
    setCoordinate(4, 6, "/areas/northern-road/hrondil-approaches/4x6.c", "road");
    setCoordinate(4, 8, "/areas/northern-road/hrondil-approaches/4x8.c", "road");

    setCoordinate(5, 0, "/areas/northern-road/hrondil-approaches/5x0.c", "road");
    setCoordinate(5, 2, "/areas/northern-road/hrondil-approaches/5x2.c", "road");
    setCoordinate(5, 4, "/areas/northern-road/hrondil-approaches/5x4.c", "road");
    setCoordinate(5, 6, "/areas/northern-road/hrondil-approaches/5x6.c", "road");
    setCoordinate(5, 8, "/areas/northern-road/hrondil-approaches/5x8.c", "road");

    setCoordinate(6, 0, "/areas/northern-road/hrondil-approaches/6x0.c", "road");
    setCoordinate(6, 2, "/areas/northern-road/hrondil-approaches/6x2.c", "road");
    setCoordinate(6, 4, "/areas/northern-road/hrondil-approaches/6x4.c", "road");
    setCoordinate(6, 6, "/areas/northern-road/hrondil-approaches/6x6.c", "road");
    setCoordinate(6, 8, "/areas/northern-road/hrondil-approaches/6x8.c", "road");

    setCoordinate(7, 0, "/areas/northern-road/hrondil-approaches/7x0.c", "road");
    setCoordinate(7, 2, "/areas/northern-road/hrondil-approaches/7x2.c", "road");
    setCoordinate(7, 4, "/areas/northern-road/hrondil-approaches/7x4.c", "road");
    setCoordinate(7, 6, "/areas/northern-road/hrondil-approaches/7x6.c", "road");
    setCoordinate(7, 8, "/areas/northern-road/hrondil-approaches/7x8.c", "road");

    setCoordinate(8, 0, "/areas/northern-road/hrondil-approaches/8x0.c", "road");
    setCoordinate(8, 2, "/areas/northern-road/hrondil-approaches/8x2.c", "road");
    setCoordinate(8, 4, "/areas/northern-road/hrondil-approaches/8x4.c", "road");
    setCoordinate(8, 6, "/areas/northern-road/hrondil-approaches/8x6.c", "road");
    setCoordinate(8, 8, "/areas/northern-road/hrondil-approaches/8x8.c", "road");

    setCoordinate(9, 0, "/areas/northern-road/hrondil-approaches/9x0.c", "road");
    setCoordinate(9, 2, "/areas/northern-road/hrondil-approaches/9x2.c", "road");
    setCoordinate(9, 4, "/areas/northern-road/hrondil-approaches/9x4.c", "road");
    setCoordinate(9, 6, "/areas/northern-road/hrondil-approaches/9x6.c", "road");
    setCoordinate(9, 8, "/areas/northern-road/hrondil-approaches/9x8.c", "road");

    setCoordinate(10, 0, "/areas/northern-road/hrondil-approaches/10x0.c", "road");
    setCoordinate(10, 2, "/areas/northern-road/hrondil-approaches/10x2.c", "road");
    setCoordinate(10, 4, "/areas/northern-road/hrondil-approaches/10x4.c", "road");
    setCoordinate(10, 6, "/areas/northern-road/hrondil-approaches/10x6.c", "road");
    setCoordinate(10, 8, "/areas/northern-road/hrondil-approaches/10x8.c", "road");

    setCoordinate(11, 0, "/areas/northern-road/hrondil-approaches/11x0.c", "road");
    setCoordinate(11, 2, "/areas/northern-road/hrondil-approaches/11x2.c", "road");
    setCoordinate(11, 4, "/areas/northern-road/hrondil-approaches/11x4.c", "road");
    setCoordinate(11, 6, "/areas/northern-road/hrondil-approaches/11x6.c", "road");
    setCoordinate(11, 8, "/areas/northern-road/hrondil-approaches/11x8.c", "road");

    setCoordinate(12, 0, "/areas/northern-road/hrondil-approaches/12x0.c", "road");
    setCoordinate(12, 2, "/areas/northern-road/hrondil-approaches/12x2.c", "road");
    setCoordinate(12, 4, "/areas/northern-road/hrondil-approaches/12x4.c", "road");
    setCoordinate(12, 6, "/areas/northern-road/hrondil-approaches/12x6.c", "road");
    setCoordinate(12, 8, "/areas/northern-road/hrondil-approaches/12x8.c", "road");

    setCoordinate(13, 0, "/areas/northern-road/hrondil-approaches/13x0.c", "road");
    setCoordinate(13, 2, "/areas/northern-road/hrondil-approaches/13x2.c", "road");
    setCoordinate(13, 4, "/areas/northern-road/hrondil-approaches/13x4.c", "road");
    setCoordinate(13, 6, "/areas/northern-road/hrondil-approaches/13x6.c", "road");
    setCoordinate(13, 8, "/areas/northern-road/hrondil-approaches/13x8.c", "road");

    setCoordinate(14, 0, "/areas/northern-road/hrondil-approaches/14x0.c", "road");
    setCoordinate(14, 2, "/areas/northern-road/hrondil-approaches/14x2.c", "road");
    setCoordinate(14, 4, "/areas/northern-road/hrondil-approaches/14x4.c", "road");
    setCoordinate(14, 6, "/areas/northern-road/hrondil-approaches/14x6.c", "road");
    setCoordinate(14, 8, "/areas/northern-road/hrondil-approaches/14x8.c", "road");

    setCoordinate(15, 0, "/areas/northern-road/hrondil-approaches/15x0.c", "road");
    setCoordinate(15, 2, "/areas/northern-road/hrondil-approaches/15x2.c", "road");
    setCoordinate(15, 4, "/areas/northern-road/hrondil-approaches/15x4.c", "road");
    setCoordinate(15, 6, "/areas/northern-road/hrondil-approaches/15x6.c", "road");
    setCoordinate(15, 8, "/areas/northern-road/hrondil-approaches/15x8.c", "road");

    setCoordinate(16, 0, "/areas/northern-road/hrondil-approaches/16x0.c", "road");
    setCoordinate(16, 2, "/areas/northern-road/hrondil-approaches/16x2.c", "road");
    setCoordinate(16, 4, "/areas/northern-road/hrondil-approaches/16x4.c", "road");
    setCoordinate(16, 6, "/areas/northern-road/hrondil-approaches/16x6.c", "road");
    setCoordinate(16, 8, "/areas/northern-road/hrondil-approaches/16x8.c", "road");

    setCoordinate(17, 0, "/areas/northern-road/hrondil-approaches/17x0.c", "road");
    setCoordinate(17, 2, "/areas/northern-road/hrondil-approaches/17x2.c", "road");
    setCoordinate(17, 4, "/areas/northern-road/hrondil-approaches/17x4.c", "road");
    setCoordinate(17, 6, "/areas/northern-road/hrondil-approaches/17x6.c", "road");
    setCoordinate(17, 8, "/areas/northern-road/hrondil-approaches/17x8.c", "road");

    setCoordinate(18, 0, "/areas/northern-road/hrondil-approaches/18x0.c", "road");
    setCoordinate(18, 2, "/areas/northern-road/hrondil-approaches/18x2.c", "road");
    setCoordinate(18, 4, "/areas/northern-road/hrondil-approaches/18x4.c", "road");
    setCoordinate(18, 6, "/areas/northern-road/hrondil-approaches/18x6.c", "road");
    setCoordinate(18, 8, "/areas/northern-road/hrondil-approaches/18x8.c", "road");

    setCoordinate(19, 0, "/areas/northern-road/hrondil-approaches/19x0.c", "road");
    setCoordinate(19, 2, "/areas/northern-road/hrondil-approaches/19x2.c", "road");
    setCoordinate(19, 4, "/areas/northern-road/hrondil-approaches/19x4.c", "road");
    setCoordinate(19, 6, "/areas/northern-road/hrondil-approaches/19x6.c", "road");
    setCoordinate(19, 8, "/areas/northern-road/hrondil-approaches/19x8.c", "road");

    setCoordinate(20, 0, "/areas/northern-road/hrondil-approaches/20x0.c", "road");
    setCoordinate(20, 2, "/areas/northern-road/hrondil-approaches/20x2.c", "road");
    setCoordinate(20, 4, "/areas/northern-road/hrondil-approaches/20x4.c", "road");
    setCoordinate(20, 6, "/areas/northern-road/hrondil-approaches/20x6.c", "road");
    setCoordinate(20, 8, "/areas/northern-road/hrondil-approaches/20x8.c", "road");

    setCoordinate(21, 0, "/areas/northern-road/hrondil-approaches/21x0.c", "road");
    setCoordinate(21, 2, "/areas/northern-road/hrondil-approaches/21x2.c", "road");
    setCoordinate(21, 4, "/areas/northern-road/hrondil-approaches/21x4.c", "road");
    setCoordinate(21, 6, "/areas/northern-road/hrondil-approaches/21x6.c", "road");
    setCoordinate(21, 8, "/areas/northern-road/hrondil-approaches/21x8.c", "road");

    setCoordinate(22, 0, "/areas/northern-road/hrondil-approaches/22x0.c", "road");
    setCoordinate(22, 2, "/areas/northern-road/hrondil-approaches/22x2.c", "road");
    setCoordinate(22, 4, "/areas/northern-road/hrondil-approaches/22x4.c", "road");
    setCoordinate(22, 6, "/areas/northern-road/hrondil-approaches/22x6.c", "road");
    setCoordinate(22, 8, "/areas/northern-road/hrondil-approaches/22x8.c", "road");

    setCoordinate(23, 0, "/areas/northern-road/hrondil-approaches/23x0.c", "road");
    setCoordinate(23, 2, "/areas/northern-road/hrondil-approaches/23x2.c", "road");
    setCoordinate(23, 4, "/areas/northern-road/hrondil-approaches/23x4.c", "road");
    setCoordinate(23, 6, "/areas/northern-road/hrondil-approaches/23x6.c", "road");
    setCoordinate(23, 8, "/areas/northern-road/hrondil-approaches/23x8.c", "road");

    setCoordinate(24, 0, "/areas/northern-road/hrondil-approaches/24x0.c", "road");
    setCoordinate(24, 1, "/areas/northern-road/hrondil-approaches/24x1.c", "road");
    setCoordinate(24, 2, "/areas/northern-road/hrondil-approaches/24x2.c", "road");
    setCoordinate(24, 4, "/areas/northern-road/hrondil-approaches/24x4.c", "road");
    setCoordinate(24, 5, "/areas/northern-road/hrondil-approaches/24x5.c", "road");
    setCoordinate(24, 6, "/areas/northern-road/hrondil-approaches/24x6.c", "road");
    setCoordinate(24, 8, "/areas/northern-road/hrondil-approaches/24x8.c", "road");
}
