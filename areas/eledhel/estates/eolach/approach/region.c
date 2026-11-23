//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setRegionName("Eolach Farm and Ridge Approach");
    setRegionType("rural");
    setRegionLevel(4);
    setSettlementChance(-1);
    asManualRegion();
    setDimensions(9, 3);

    setEntryCoordinate(0, 0,
        "/areas/eledhel/estates/eolach/approach/0x0.c",
        "south", "/areas/northern-road/belathon-eolach/5x0.c");
    setCoordinate(0, 1,
        "/areas/eledhel/estates/eolach/approach/0x1.c", "road");
    setCoordinate(0, 2,
        "/areas/eledhel/estates/eolach/approach/0x2.c", "road");

    setCoordinate(1, 0,
        "/areas/eledhel/estates/eolach/approach/1x0.c", "road");
    setCoordinate(1, 1,
        "/areas/eledhel/estates/eolach/approach/1x1.c", "road");
    setCoordinate(1, 2,
        "/areas/eledhel/estates/eolach/approach/1x2.c", "road");

    setCoordinate(2, 0,
        "/areas/eledhel/estates/eolach/approach/2x0.c", "road");
    setCoordinate(2, 1,
        "/areas/eledhel/estates/eolach/approach/2x1.c", "road");
    setCoordinate(2, 2,
        "/areas/eledhel/estates/eolach/approach/2x2.c", "road");

    setCoordinate(3, 0,
        "/areas/eledhel/estates/eolach/approach/3x0.c", "road");
    setCoordinate(3, 1,
        "/areas/eledhel/estates/eolach/approach/3x1.c", "road");
    setCoordinate(3, 2,
        "/areas/eledhel/estates/eolach/approach/3x2.c", "road");

    setCoordinate(4, 0,
        "/areas/eledhel/estates/eolach/approach/4x0.c", "road");
    setCoordinate(4, 1,
        "/areas/eledhel/estates/eolach/approach/4x1.c", "road");
    setCoordinate(4, 2,
        "/areas/eledhel/estates/eolach/approach/4x2.c", "road");

    setCoordinate(5, 0,
        "/areas/eledhel/estates/eolach/approach/5x0.c", "road");
    setCoordinate(5, 1,
        "/areas/eledhel/estates/eolach/approach/5x1.c", "road");
    setCoordinate(5, 2,
        "/areas/eledhel/estates/eolach/approach/5x2.c", "road");

    setCoordinate(6, 0,
        "/areas/eledhel/estates/eolach/approach/6x0.c", "road");
    setCoordinate(6, 1,
        "/areas/eledhel/estates/eolach/approach/6x1.c", "road");
    setCoordinate(6, 2,
        "/areas/eledhel/estates/eolach/approach/6x2.c", "road");

    setCoordinate(7, 0,
        "/areas/eledhel/estates/eolach/approach/7x0.c", "road");
    setCoordinate(7, 1,
        "/areas/eledhel/estates/eolach/approach/7x1.c", "road");
    setCoordinate(7, 2,
        "/areas/eledhel/estates/eolach/approach/7x2.c", "road");

    setCoordinate(8, 0,
        "/areas/eledhel/estates/eolach/approach/8x0.c", "road");
    setCoordinate(8, 1,
        "/areas/eledhel/estates/eolach/approach/8x1.c", "road");
    setCoordinate(8, 2,
        "/areas/eledhel/estates/eolach/approach/8x2.c", "road");
}
