//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setRegionName("Eledhel Palace");
    setRegionType("palace");
    setRegionLevel(1);
    setSettlementChance(-1);
    asManualRegion();
    setDimensions(6, 5);
    setEntryCoordinate(0, 2,
        "/areas/eledhel/central-city/palace/0x2.c", "west",
        "/areas/eledhel/central-city/14x5.c");

    setCoordinate(0, 1,
        "/areas/eledhel/central-city/palace/0x1.c", "none");
    setCoordinate(0, 2,
        "/areas/eledhel/central-city/palace/0x2.c", "none");
    setCoordinate(0, 3,
        "/areas/eledhel/central-city/palace/0x3.c", "none");
    setCoordinate(0, 0,
        "/areas/eledhel/central-city/palace/0x0.c", "none");
    setCoordinate(0, 4,
        "/areas/eledhel/central-city/palace/0x4.c", "none");
    setCoordinate(1, 0,
        "/areas/eledhel/central-city/palace/1x0.c", "none");
    setCoordinate(1, 1,
        "/areas/eledhel/central-city/palace/1x1.c", "none");
    setCoordinate(1, 2,
        "/areas/eledhel/central-city/palace/1x2.c", "none");
    setCoordinate(1, 3,
        "/areas/eledhel/central-city/palace/1x3.c", "none");
    setCoordinate(1, 4,
        "/areas/eledhel/central-city/palace/1x4.c", "none");
    setCoordinate(2, 0,
        "/areas/eledhel/central-city/palace/2x0.c", "none");
    setCoordinate(2, 1,
        "/areas/eledhel/central-city/palace/2x1.c", "none");
    setCoordinate(2, 2,
        "/areas/eledhel/central-city/palace/2x2.c", "none");
    setCoordinate(2, 3,
        "/areas/eledhel/central-city/palace/2x3.c", "none");
    setCoordinate(2, 4,
        "/areas/eledhel/central-city/palace/2x4.c", "none");
    setCoordinate(3, 0,
        "/areas/eledhel/central-city/palace/3x0.c", "none");
    setCoordinate(3, 1,
        "/areas/eledhel/central-city/palace/3x1.c", "none");
    setCoordinate(3, 2,
        "/areas/eledhel/central-city/palace/3x2.c", "none");
    setCoordinate(3, 3,
        "/areas/eledhel/central-city/palace/3x3.c", "none");
    setCoordinate(3, 4,
        "/areas/eledhel/central-city/palace/3x4.c", "none");
    setCoordinate(4, 0,
        "/areas/eledhel/central-city/palace/4x0.c", "none");
    setCoordinate(4, 1,
        "/areas/eledhel/central-city/palace/4x1.c", "none");
    setCoordinate(4, 2,
        "/areas/eledhel/central-city/palace/4x2.c", "none");
    setCoordinate(4, 3,
        "/areas/eledhel/central-city/palace/4x3.c", "none");
    setCoordinate(4, 4,
        "/areas/eledhel/central-city/palace/4x4.c", "none");
    setCoordinate(5, 0,
        "/areas/eledhel/central-city/palace/5x0.c", "none");
    setCoordinate(5, 1,
        "/areas/eledhel/central-city/palace/5x1.c", "none");
    setCoordinate(5, 2,
        "/areas/eledhel/central-city/palace/5x2.c", "none");
    setCoordinate(5, 3,
        "/areas/eledhel/central-city/palace/5x3.c", "none");
}
