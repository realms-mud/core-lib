//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setRegionName("The Northern Underways of Eledhel");
    setRegionType("cave");
    asManualRegion();
    setDimensions(25, 10);
    setEntryCoordinate(12, 0,
        "/areas/eledhel/under-city/northern-city/12x0.c", "south",
        "/areas/eledhel/under-city/central-city/12x9.c");

    setCoordinate(12, 1, "/areas/eledhel/under-city/northern-city/12x1.c", "none");
    setCoordinate(12, 2, "/areas/eledhel/under-city/northern-city/12x2.c", "none");
    setCoordinate(12, 3, "/areas/eledhel/under-city/northern-city/12x3.c", "none");
    setCoordinate(12, 4, "/areas/eledhel/under-city/northern-city/12x4.c", "none");
    setCoordinate(12, 5, "/areas/eledhel/under-city/northern-city/12x5.c", "none");
    setCoordinate(12, 6, "/areas/eledhel/under-city/northern-city/12x6.c", "none");
    setCoordinate(12, 7, "/areas/eledhel/under-city/northern-city/12x7.c", "none");
    setCoordinate(12, 8, "/areas/eledhel/under-city/northern-city/12x8.c", "none");
    setCoordinate(12, 9, "/areas/eledhel/under-city/northern-city/12x9.c", "none");

    setCoordinate(13, 8, "/areas/eledhel/under-city/northern-city/13x8.c", "none");
    setCoordinate(14, 8, "/areas/eledhel/under-city/northern-city/14x8.c", "none");
    setCoordinate(15, 8, "/areas/eledhel/under-city/northern-city/15x8.c", "none");
    setCoordinate(16, 8, "/areas/eledhel/under-city/northern-city/16x8.c", "none");
    setCoordinate(17, 8, "/areas/eledhel/under-city/museum-branch/17x8.c", "none");
    setCoordinate(18, 8, "/areas/eledhel/under-city/library-branch/18x8.c", "none");
    setCoordinate(19, 8, "/areas/eledhel/under-city/northern-city/19x8.c", "none");
    setCoordinate(20, 8, "/areas/eledhel/under-city/northern-city/20x8.c", "none");
    setCoordinate(21, 8, "/areas/eledhel/under-city/northern-city/21x8.c", "none");
    setCoordinate(22, 8, "/areas/eledhel/under-city/northern-city/22x8.c", "none");
    setCoordinate(23, 8, "/areas/eledhel/under-city/naval-branch/23x8.c", "none");

    setCoordinate(5, 6, "/areas/eledhel/under-city/northern-city/5x6.c", "none");
    setCoordinate(6, 6, "/areas/eledhel/under-city/northern-city/6x6.c", "none");
    setCoordinate(7, 6, "/areas/eledhel/under-city/northern-city/7x6.c", "none");
    setCoordinate(8, 6, "/areas/eledhel/under-city/northern-city/8x6.c", "none");
    setCoordinate(9, 6, "/areas/eledhel/under-city/northern-city/9x6.c", "none");
    setCoordinate(10, 6, "/areas/eledhel/under-city/northern-city/10x6.c", "none");
    setCoordinate(11, 6, "/areas/eledhel/under-city/northern-city/11x6.c", "none");

    setCoordinate(18, 7, "/areas/eledhel/under-city/northern-city/18x7.c", "none");
    setCoordinate(19, 7, "/areas/eledhel/under-city/northern-city/19x7.c", "none");
    setCoordinate(20, 7, "/areas/eledhel/under-city/northern-city/20x7.c", "none");
    setCoordinate(21, 7, "/areas/eledhel/under-city/northern-city/21x7.c", "none");
    setCoordinate(22, 7, "/areas/eledhel/under-city/northern-city/22x7.c", "none");
    setCoordinate(23, 7, "/areas/eledhel/under-city/northern-city/23x7.c", "none");
}
