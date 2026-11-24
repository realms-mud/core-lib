//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setRegionName("The Finished Escape Tunnel");
    setRegionType("cave");
    asManualRegion();
    setDimensions(9, 10);

    setEntryCoordinate(8, 0,
        "/areas/eledhel/under-city/fox-route/8x0.c", "up",
        "/areas/eledhel/under-city/library-branch/18x8.c");
    setCoordinate(8, 1, "/areas/eledhel/under-city/fox-route/8x1.c", "none");
    setCoordinate(8, 2, "/areas/eledhel/under-city/fox-route/8x2.c", "none");
    setCoordinate(8, 3, "/areas/eledhel/under-city/fox-route/8x3.c", "none");
    setCoordinate(8, 4, "/areas/eledhel/under-city/fox-route/8x4.c", "none");
    setCoordinate(8, 5, "/areas/eledhel/under-city/fox-route/8x5.c", "none");
    setCoordinate(8, 6, "/areas/eledhel/under-city/fox-route/8x6.c", "none");
    setCoordinate(8, 7, "/areas/eledhel/under-city/fox-route/8x7.c", "none");
    setCoordinate(8, 8, "/areas/eledhel/under-city/fox-route/8x8.c", "none");
    setCoordinate(8, 9, "/areas/eledhel/under-city/fox-route/8x9.c", "none");
    setCoordinate(7, 9, "/areas/eledhel/under-city/fox-route/7x9.c", "none");
    setCoordinate(6, 9, "/areas/eledhel/under-city/fox-route/6x9.c", "none");
    setCoordinate(5, 9, "/areas/eledhel/under-city/fox-route/5x9.c", "none");
    setCoordinate(4, 9, "/areas/eledhel/under-city/fox-route/4x9.c", "none");
    setCoordinate(3, 9, "/areas/eledhel/under-city/fox-route/3x9.c", "none");
    setCoordinate(2, 9, "/areas/eledhel/under-city/fox-route/2x9.c", "none");
    setCoordinate(1, 9, "/areas/eledhel/under-city/fox-route/1x9.c", "none");
    setCoordinate(0, 9, "/areas/eledhel/under-city/fox-route/0x9.c", "none");
    setCoordinate(0, 8, "/areas/eledhel/under-city/fox-route/0x8.c", "none");
    setCoordinate(0, 7, "/areas/eledhel/under-city/fox-route/0x7.c", "none");
    setCoordinate(0, 6, "/areas/eledhel/under-city/fox-route/0x6.c", "none");
    setCoordinate(0, 5, "/areas/eledhel/under-city/fox-route/0x5.c", "none");
    setCoordinate(0, 4, "/areas/eledhel/under-city/fox-route/0x4.c", "none");
    setCoordinate(0, 3, "/areas/eledhel/under-city/fox-route/0x3.c", "none");
    setCoordinate(0, 2, "/areas/eledhel/under-city/fox-route/0x2.c", "none");
    setCoordinate(0, 1, "/areas/eledhel/under-city/fox-route/0x1.c", "none");
}
