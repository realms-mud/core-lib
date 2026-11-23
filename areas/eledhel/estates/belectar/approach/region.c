//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setRegionName("Gundil to Belectar Road");
    setRegionType("rural");
    setRegionLevel(3);
    setDimensions(9, 5);
    setSettlementChance(-1);

    setEntryCoordinate(0, 0,
        "/areas/eledhel/estates/belectar/approach/0x0.c", "west",
        "/areas/eledhel/estates/gundil/grounds/0x1.c");
    setCoordinate(0, 2,
        "/areas/eledhel/estates/belectar/approach/0x2.c", "road");
    setCoordinate(0, 3,
        "/areas/eledhel/estates/belectar/approach/0x3.c", "road");
    setCoordinate(0, 4,
        "/areas/eledhel/estates/belectar/approach/0x4.c", "road");

    setCoordinate(1, 0,
        "/areas/eledhel/estates/belectar/approach/1x0.c", "road");
    setCoordinate(1, 2,
        "/areas/eledhel/estates/belectar/approach/1x2.c", "road");
    setCoordinate(1, 4,
        "/areas/eledhel/estates/belectar/approach/1x4.c", "road");

    setCoordinate(2, 0,
        "/areas/eledhel/estates/belectar/approach/2x0.c", "road");
    setCoordinate(2, 2,
        "/areas/eledhel/estates/belectar/approach/2x2.c", "road");
    setCoordinate(2, 4,
        "/areas/eledhel/estates/belectar/approach/2x4.c", "road");

    setCoordinate(3, 0,
        "/areas/eledhel/estates/belectar/approach/3x0.c", "road");
    setCoordinate(3, 2,
        "/areas/eledhel/estates/belectar/approach/3x2.c", "road");
    setCoordinate(3, 4,
        "/areas/eledhel/estates/belectar/approach/3x4.c", "road");

    setCoordinate(4, 0,
        "/areas/eledhel/estates/belectar/approach/4x0.c", "road");
    setCoordinate(4, 2,
        "/areas/eledhel/estates/belectar/approach/4x2.c", "road");
    setCoordinate(4, 4,
        "/areas/eledhel/estates/belectar/approach/4x4.c", "road");

    setCoordinate(5, 0,
        "/areas/eledhel/estates/belectar/approach/5x0.c", "road");
    setCoordinate(5, 2,
        "/areas/eledhel/estates/belectar/approach/5x2.c", "road");
    setCoordinate(5, 4,
        "/areas/eledhel/estates/belectar/approach/5x4.c", "road");

    setCoordinate(6, 0,
        "/areas/eledhel/estates/belectar/approach/6x0.c", "road");
    setCoordinate(6, 2,
        "/areas/eledhel/estates/belectar/approach/6x2.c", "road");
    setCoordinate(6, 4,
        "/areas/eledhel/estates/belectar/approach/6x4.c", "road");

    setCoordinate(7, 0,
        "/areas/eledhel/estates/belectar/approach/7x0.c", "road");
    setCoordinate(7, 2,
        "/areas/eledhel/estates/belectar/approach/7x2.c", "road");

    setCoordinate(8, 0,
        "/areas/eledhel/estates/belectar/approach/8x0.c", "road");
    setCoordinate(8, 1,
        "/areas/eledhel/estates/belectar/approach/8x1.c", "road");
    setCoordinate(8, 2,
        "/areas/eledhel/estates/belectar/approach/8x2.c", "road");
}
