//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/region.c";

public void Setup()
{
    setRegionName("Eledhel North Gate, Market Gardens, and Erator Road");
    setRegionType("rural");
    setRegionLevel(2);
    setDimensions(25, 10);
    setSettlementChance(-1);

    setEntryCoordinate(0, 0,
        "/areas/northern-road/north-gate/0x0.c", "west",
        "/areas/eledhel/north-road/2x0.c");
    setCoordinate(1, 0, "/areas/northern-road/north-gate/1x0.c", "path");
    setCoordinate(2, 0, "/areas/northern-road/north-gate/2x0.c", "path");
    setCoordinate(3, 0, "/areas/northern-road/north-gate/3x0.c", "path");
    setCoordinate(4, 0, "/areas/northern-road/north-gate/4x0.c", "path");
    setCoordinate(5, 0, "/areas/northern-road/north-gate/5x0.c", "path");
    setCoordinate(6, 0, "/areas/northern-road/north-gate/6x0.c", "path");
    setCoordinate(7, 0, "/areas/northern-road/north-gate/7x0.c", "path");
    setCoordinate(8, 0, "/areas/northern-road/north-gate/8x0.c", "path");
    setCoordinate(9, 0, "/areas/northern-road/north-gate/9x0.c", "path");

    setCoordinate(4, 1, "/areas/northern-road/north-gate/4x1.c", "room");
    setCoordinate(5, 1, "/areas/northern-road/north-gate/5x1.c", "room");
    setCoordinate(9, 1, "/areas/northern-road/north-gate/9x1.c", "path");

    setCoordinate(0, 2, "/areas/northern-road/north-gate/0x2.c", "path");
    setCoordinate(1, 2, "/areas/northern-road/north-gate/1x2.c", "path");
    setCoordinate(2, 2, "/areas/northern-road/north-gate/2x2.c", "path");
    setCoordinate(3, 2, "/areas/northern-road/north-gate/3x2.c", "path");
    setCoordinate(4, 2, "/areas/northern-road/north-gate/4x2.c", "path");
    setCoordinate(5, 2, "/areas/northern-road/north-gate/5x2.c", "path");
    setCoordinate(6, 2, "/areas/northern-road/north-gate/6x2.c", "path");
    setCoordinate(7, 2, "/areas/northern-road/north-gate/7x2.c", "path");
    setCoordinate(8, 2, "/areas/northern-road/north-gate/8x2.c", "path");
    setCoordinate(9, 2, "/areas/northern-road/north-gate/9x2.c", "path");

    setCoordinate(0, 3, "/areas/northern-road/north-gate/0x3.c", "path");
    setCoordinate(1, 3, "/areas/northern-road/north-gate/1x3.c", "room");
    setCoordinate(2, 3, "/areas/northern-road/north-gate/2x3.c", "room");
    setCoordinate(3, 3, "/areas/northern-road/north-gate/3x3.c", "room");

    setCoordinate(0, 4, "/areas/northern-road/north-gate/0x4.c", "path");
    setCoordinate(1, 4, "/areas/northern-road/north-gate/1x4.c", "path");
    setCoordinate(2, 4, "/areas/northern-road/north-gate/2x4.c", "path");
    setCoordinate(3, 4, "/areas/northern-road/north-gate/3x4.c", "path");
    setCoordinate(4, 4, "/areas/northern-road/north-gate/4x4.c", "path");
    setCoordinate(5, 4, "/areas/northern-road/north-gate/5x4.c", "path");
    setCoordinate(6, 4, "/areas/northern-road/north-gate/6x4.c", "path");
    setCoordinate(7, 4, "/areas/northern-road/north-gate/7x4.c", "path");
    setCoordinate(8, 4, "/areas/northern-road/north-gate/8x4.c", "path");
    setCoordinate(9, 4, "/areas/northern-road/north-gate/9x4.c", "path");

    setCoordinate(3, 5, "/areas/northern-road/north-gate/3x5.c", "room");
    setCoordinate(4, 5, "/areas/northern-road/north-gate/4x5.c", "room");
    setCoordinate(6, 5, "/areas/northern-road/north-gate/6x5.c", "room");
    setCoordinate(7, 5, "/areas/northern-road/north-gate/7x5.c", "room");
    setCoordinate(8, 5, "/areas/northern-road/north-gate/8x5.c", "room");
    setCoordinate(9, 5, "/areas/northern-road/north-gate/9x5.c", "path");

    setCoordinate(0, 6, "/areas/northern-road/north-gate/0x6.c", "path");
    setCoordinate(1, 6, "/areas/northern-road/north-gate/1x6.c", "path");
    setCoordinate(2, 6, "/areas/northern-road/north-gate/2x6.c", "path");
    setCoordinate(3, 6, "/areas/northern-road/north-gate/3x6.c", "path");
    setCoordinate(4, 6, "/areas/northern-road/north-gate/4x6.c", "path");
    setCoordinate(5, 6, "/areas/northern-road/north-gate/5x6.c", "path");
    setCoordinate(6, 6, "/areas/northern-road/north-gate/6x6.c", "path");
    setCoordinate(7, 6, "/areas/northern-road/north-gate/7x6.c", "path");
    setCoordinate(8, 6, "/areas/northern-road/north-gate/8x6.c", "path");
    setCoordinate(9, 6, "/areas/northern-road/north-gate/9x6.c", "path");

    setCoordinate(0, 7, "/areas/northern-road/north-gate/0x7.c", "path");

    setCoordinate(0, 8, "/areas/northern-road/north-gate/0x8.c", "path");
    setCoordinate(1, 8, "/areas/northern-road/north-gate/1x8.c", "path");
    setCoordinate(2, 8, "/areas/northern-road/north-gate/2x8.c", "path");
    setCoordinate(3, 8, "/areas/northern-road/north-gate/3x8.c", "path");
    setCoordinate(4, 8, "/areas/northern-road/north-gate/4x8.c", "path");
    setCoordinate(5, 8, "/areas/northern-road/north-gate/5x8.c", "path");
    setCoordinate(6, 8, "/areas/northern-road/north-gate/6x8.c", "path");
    setCoordinate(7, 8, "/areas/northern-road/north-gate/7x8.c", "path");
    setCoordinate(8, 8, "/areas/northern-road/north-gate/8x8.c", "path");
    setCoordinate(9, 8, "/areas/northern-road/north-gate/9x8.c", "path");

    setCoordinate(9, 9, "/areas/northern-road/north-gate/9x9.c", "room");

    setCoordinate(10, 0,
        "/areas/northern-road/north-gate/market-gardens/0x0.c", "room");
    setCoordinate(10, 1,
        "/areas/northern-road/north-gate/market-gardens/0x1.c", "room");
    setCoordinate(10, 2,
        "/areas/northern-road/north-gate/market-gardens/0x2.c", "room");
    setCoordinate(10, 3,
        "/areas/northern-road/north-gate/market-gardens/0x3.c", "room");
    setCoordinate(10, 4,
        "/areas/northern-road/north-gate/market-gardens/0x4.c", "room");

    setCoordinate(11, 0,
        "/areas/northern-road/north-gate/market-gardens/1x0.c", "room");
    setCoordinate(11, 1,
        "/areas/northern-road/north-gate/market-gardens/1x1.c", "room");
    setCoordinate(11, 2,
        "/areas/northern-road/north-gate/market-gardens/1x2.c", "room");
    setCoordinate(11, 3,
        "/areas/northern-road/north-gate/market-gardens/1x3.c", "room");
    setCoordinate(11, 4,
        "/areas/northern-road/north-gate/market-gardens/1x4.c", "room");

    setCoordinate(12, 0,
        "/areas/northern-road/north-gate/market-gardens/2x0.c", "room");
    setCoordinate(12, 1,
        "/areas/northern-road/north-gate/market-gardens/2x1.c", "room");
    setCoordinate(12, 2,
        "/areas/northern-road/north-gate/market-gardens/2x2.c", "room");
    setCoordinate(12, 3,
        "/areas/northern-road/north-gate/market-gardens/2x3.c", "room");
    setCoordinate(12, 4,
        "/areas/northern-road/north-gate/market-gardens/2x4.c", "room");

    setCoordinate(13, 0,
        "/areas/northern-road/north-gate/market-gardens/3x0.c", "room");
    setCoordinate(13, 1,
        "/areas/northern-road/north-gate/market-gardens/3x1.c", "room");
    setCoordinate(13, 2,
        "/areas/northern-road/north-gate/market-gardens/3x2.c", "room");
    setCoordinate(13, 3,
        "/areas/northern-road/north-gate/market-gardens/3x3.c", "room");
    setCoordinate(13, 4,
        "/areas/northern-road/north-gate/market-gardens/3x4.c", "room");

    setCoordinate(14, 0,
        "/areas/northern-road/north-gate/market-gardens/4x0.c", "room");
    setCoordinate(14, 1,
        "/areas/northern-road/north-gate/market-gardens/4x1.c", "room");
    setCoordinate(14, 2,
        "/areas/northern-road/north-gate/market-gardens/4x2.c", "room");
    setCoordinate(14, 3,
        "/areas/northern-road/north-gate/market-gardens/4x3.c", "room");
    setCoordinate(14, 4,
        "/areas/northern-road/north-gate/market-gardens/4x4.c", "room");

    setCoordinate(10, 5, "/areas/northern-road/north-gate/10x5.c", "path");
    setCoordinate(11, 5, "/areas/northern-road/north-gate/11x5.c", "path");
    setCoordinate(12, 5, "/areas/northern-road/north-gate/12x5.c", "path");
}
