//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setRegionName("Kirin West Road, Manor Approach");
    setRegionType("rural");
    setRegionLevel(3);
    asManualRegion();
    setDimensions(13, 1);
    setSettlementChance(-1);
    setEntryCoordinate(0, 0,
        "/areas/eledhel/estates/kirin/approach/second/0x0.c", "west",
        "/areas/eledhel/estates/kirin/approach/13x0.c");

    setCoordinate(1, 0,
        "/areas/eledhel/estates/kirin/approach/second/1x0.c", "road");
    setCoordinate(2, 0,
        "/areas/eledhel/estates/kirin/approach/second/2x0.c", "road");
    setCoordinate(3, 0,
        "/areas/eledhel/estates/kirin/approach/second/3x0.c", "road");
    setCoordinate(4, 0,
        "/areas/eledhel/estates/kirin/approach/second/4x0.c", "road");
    setCoordinate(5, 0,
        "/areas/eledhel/estates/kirin/approach/second/5x0.c", "road");
    setCoordinate(6, 0,
        "/areas/eledhel/estates/kirin/approach/second/6x0.c", "road");
    setCoordinate(7, 0,
        "/areas/eledhel/estates/kirin/approach/second/7x0.c", "road");
    setCoordinate(8, 0,
        "/areas/eledhel/estates/kirin/approach/second/8x0.c", "road");
    setCoordinate(9, 0,
        "/areas/eledhel/estates/kirin/approach/second/9x0.c", "road");
    setCoordinate(10, 0,
        "/areas/eledhel/estates/kirin/approach/second/10x0.c", "road");
    setCoordinate(11, 0,
        "/areas/eledhel/estates/kirin/approach/second/11x0.c", "road");
    setCoordinate(12, 0,
        "/areas/eledhel/estates/kirin/approach/second/12x0.c", "road");
}
