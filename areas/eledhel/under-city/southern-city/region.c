//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setRegionName("The Southern Underways of Eledhel");
    setRegionType("cave");
    asManualRegion();
    setDimensions(25, 10);
    setEntryCoordinate(12, 9,
        "/areas/eledhel/under-city/southern-city/12x9.c", "north",
        "/areas/eledhel/under-city/central-city/12x0.c");

    setCoordinate(12, 0, "/areas/eledhel/under-city/southern-city/12x0.c", "none");
    setCoordinate(12, 1, "/areas/eledhel/under-city/southern-city/12x1.c", "none");
    setCoordinate(12, 2, "/areas/eledhel/under-city/southern-city/12x2.c", "none");
    setCoordinate(12, 3, "/areas/eledhel/under-city/southern-city/12x3.c", "none");
    setCoordinate(12, 4, "/areas/eledhel/under-city/southern-city/12x4.c", "none");
    setCoordinate(12, 5, "/areas/eledhel/under-city/southern-city/12x5.c", "none");
    setCoordinate(12, 6, "/areas/eledhel/under-city/southern-city/12x6.c", "none");
    setCoordinate(12, 7, "/areas/eledhel/under-city/southern-city/12x7.c", "none");
    setCoordinate(12, 8, "/areas/eledhel/under-city/southern-city/12x8.c", "none");

    setCoordinate(13, 7, "/areas/eledhel/under-city/southern-city/13x7.c", "none");
    setCoordinate(14, 7, "/areas/eledhel/under-city/southern-city/14x7.c", "none");
    setCoordinate(15, 7, "/areas/eledhel/under-city/southern-city/15x7.c", "none");
    setCoordinate(16, 7, "/areas/eledhel/under-city/southern-city/16x7.c", "none");
    setCoordinate(17, 7, "/areas/eledhel/under-city/southern-city/17x7.c", "none");
    setCoordinate(18, 7, "/areas/eledhel/under-city/southern-city/18x7.c", "none");
    setCoordinate(19, 7, "/areas/eledhel/under-city/southern-city/19x7.c", "none");
    setCoordinate(20, 7, "/areas/eledhel/under-city/justice-mechanism/20x7.c", "none");

    setCoordinate(16, 6, "/areas/eledhel/under-city/southern-city/16x6.c", "none");
    setCoordinate(17, 6, "/areas/eledhel/under-city/southern-city/17x6.c", "none");
    setCoordinate(18, 6, "/areas/eledhel/under-city/southern-city/18x6.c", "none");
    setCoordinate(19, 6, "/areas/eledhel/under-city/southern-city/19x6.c", "none");
    setCoordinate(20, 6, "/areas/eledhel/under-city/southern-city/20x6.c", "none");

    setCoordinate(6, 3, "/areas/eledhel/under-city/southern-city/6x3.c", "none");
    setCoordinate(7, 3, "/areas/eledhel/under-city/southern-city/7x3.c", "none");
    setCoordinate(8, 3, "/areas/eledhel/under-city/southern-city/8x3.c", "none");
    setCoordinate(9, 3, "/areas/eledhel/under-city/southern-city/9x3.c", "none");
    setCoordinate(10, 3, "/areas/eledhel/under-city/southern-city/10x3.c", "none");
    setCoordinate(11, 3, "/areas/eledhel/under-city/southern-city/11x3.c", "none");

    setCoordinate(6, 2, "/areas/eledhel/under-city/southern-city/6x2.c", "none");
    setCoordinate(6, 1, "/areas/eledhel/under-city/southern-city/6x1.c", "none");
    setCoordinate(7, 1, "/areas/eledhel/under-city/southern-city/7x1.c", "none");
    setCoordinate(8, 1, "/areas/eledhel/under-city/southern-city/8x1.c", "none");
}
