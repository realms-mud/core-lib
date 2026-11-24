//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setRegionName("Minlach Approaches");
    setRegionType("rural");
    setRegionLevel(3);
    setSettlementChance(-1);
    setDimensions(25, 10);

    setEntryCoordinate(0, 4,
        "/areas/northern-road/minlach-approaches/0x4.c", "west",
        "/areas/northern-road/upper-northern-wilds/24x0.c");

    setCoordinate(1, 4,
        "/areas/northern-road/minlach-approaches/1x4.c", "road");
    setCoordinate(2, 4,
        "/areas/northern-road/minlach-approaches/2x4.c", "road");
    setCoordinate(3, 4,
        "/areas/northern-road/minlach-approaches/3x4.c", "road");
    setCoordinate(4, 4,
        "/areas/northern-road/minlach-approaches/4x4.c", "road");
    setCoordinate(5, 4,
        "/areas/northern-road/minlach-approaches/5x4.c", "road");
    setCoordinate(6, 4,
        "/areas/northern-road/minlach-approaches/6x4.c", "road");
    setCoordinate(7, 4,
        "/areas/northern-road/minlach-approaches/7x4.c", "road");
    setCoordinate(8, 4,
        "/areas/northern-road/minlach-approaches/8x4.c", "road");
    setCoordinate(9, 4,
        "/areas/northern-road/minlach-approaches/9x4.c", "road");
    setCoordinate(10, 4,
        "/areas/northern-road/minlach-approaches/10x4.c", "road");
    setCoordinate(11, 4,
        "/areas/northern-road/minlach-approaches/11x4.c", "road");
    setCoordinate(12, 4,
        "/areas/northern-road/minlach-approaches/12x4.c", "road");
    setCoordinate(13, 4,
        "/areas/northern-road/minlach-approaches/13x4.c", "road");
    setCoordinate(14, 4,
        "/areas/northern-road/minlach-approaches/14x4.c", "road");
    setCoordinate(15, 4,
        "/areas/northern-road/minlach-approaches/15x4.c", "road");
    setCoordinate(16, 4,
        "/areas/northern-road/minlach-approaches/16x4.c", "road");
    setCoordinate(17, 4,
        "/areas/northern-road/minlach-approaches/17x4.c", "road");
    setCoordinate(18, 4,
        "/areas/northern-road/minlach-approaches/18x4.c", "road");
    setCoordinate(19, 4,
        "/areas/northern-road/minlach-approaches/19x4.c", "road");
    setCoordinate(20, 4,
        "/areas/northern-road/minlach-approaches/20x4.c", "road");
    setCoordinate(21, 4,
        "/areas/northern-road/minlach-approaches/21x4.c", "road");
    setCoordinate(22, 4,
        "/areas/northern-road/minlach-approaches/22x4.c", "road");
    setCoordinate(23, 4,
        "/areas/northern-road/minlach-approaches/23x4.c", "road");
    setCoordinate(24, 4,
        "/areas/northern-road/minlach-approaches/24x4.c", "road");

    setCoordinate(2, 3,
        "/areas/northern-road/minlach-approaches/2x3.c", "room");
    setCoordinate(2, 2,
        "/areas/northern-road/minlach-approaches/2x2.c", "room");
    setCoordinate(5, 5,
        "/areas/northern-road/minlach-approaches/5x5.c", "path");
    setCoordinate(6, 5,
        "/areas/northern-road/minlach-approaches/6x5.c", "room");
    setCoordinate(7, 5,
        "/areas/northern-road/minlach-approaches/7x5.c", "room");
    setCoordinate(6, 6,
        "/areas/northern-road/minlach-approaches/6x6.c", "path");
    setCoordinate(7, 6,
        "/areas/northern-road/minlach-approaches/7x6.c", "room");

    setCoordinate(12, 3,
        "/areas/northern-road/minlach-approaches/12x3.c", "path");
    setCoordinate(12, 2,
        "/areas/northern-road/minlach-approaches/12x2.c", "room");
    setCoordinate(12, 1,
        "/areas/northern-road/minlach-approaches/12x1.c", "room");
    setCoordinate(13, 2,
        "/areas/northern-road/minlach-approaches/13x2.c", "room");

    setCoordinate(18, 5,
        "/areas/northern-road/minlach-approaches/18x5.c", "room");
    setCoordinate(19, 5,
        "/areas/northern-road/minlach-approaches/19x5.c", "room");
    setCoordinate(19, 6,
        "/areas/northern-road/minlach-approaches/19x6.c", "room");

    setCoordinate(22, 3,
        "/areas/northern-road/minlach-approaches/22x3.c", "path");
    setCoordinate(22, 2,
        "/areas/northern-road/minlach-approaches/22x2.c", "room");
    setCoordinate(23, 3,
        "/areas/northern-road/minlach-approaches/23x3.c", "path");
    setCoordinate(23, 2,
        "/areas/northern-road/minlach-approaches/23x2.c", "room");

    setCoordinate(23, 5,
        "/areas/northern-road/minlach-approaches/23x5.c", "room");
    setCoordinate(23, 6,
        "/areas/northern-road/minlach-approaches/23x6.c", "room");
}
