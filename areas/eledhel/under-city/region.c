//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setRegionName("The Old-City Underways");
    setRegionType("cave");
    asManualRegion();
    setDimensions(25, 10);

    setEntryCoordinate(14, 5,
        "/areas/eledhel/under-city/central-city/14x5.c", "up",
        "/areas/eledhel/central-city/palace/hidden-passage.c");

    setCoordinate(12, 0, "/areas/eledhel/under-city/central-city/12x0.c", "none");
    setCoordinate(12, 1, "/areas/eledhel/under-city/central-city/12x1.c", "none");
    setCoordinate(12, 2, "/areas/eledhel/under-city/central-city/12x2.c", "none");
    setCoordinate(12, 3, "/areas/eledhel/under-city/central-city/12x3.c", "none");
    setCoordinate(12, 4, "/areas/eledhel/under-city/central-city/12x4.c", "none");
    setCoordinate(12, 5, "/areas/eledhel/under-city/central-city/12x5.c", "none");
    setCoordinate(12, 6, "/areas/eledhel/under-city/central-city/12x6.c", "none");
    setCoordinate(12, 7, "/areas/eledhel/under-city/central-city/12x7.c", "none");
    setCoordinate(12, 8, "/areas/eledhel/under-city/central-city/12x8.c", "none");
    setCoordinate(12, 9, "/areas/eledhel/under-city/central-city/12x9.c", "none");

    setCoordinate(8, 5, "/areas/eledhel/under-city/central-city/8x5.c", "none");
    setCoordinate(9, 5, "/areas/eledhel/under-city/central-city/9x5.c", "none");
    setCoordinate(10, 5, "/areas/eledhel/under-city/central-city/10x5.c", "none");
    setCoordinate(11, 5, "/areas/eledhel/under-city/central-city/11x5.c", "none");
    setCoordinate(13, 5, "/areas/eledhel/under-city/central-city/13x5.c", "none");
    setCoordinate(15, 5, "/areas/eledhel/under-city/central-city/15x5.c", "none");
    setCoordinate(16, 5, "/areas/eledhel/under-city/central-city/16x5.c", "none");
    setCoordinate(17, 5, "/areas/eledhel/under-city/central-city/17x5.c", "none");
    setCoordinate(18, 5, "/areas/eledhel/under-city/central-city/18x5.c", "none");
    setCoordinate(11, 4, "/areas/eledhel/under-city/aegis-branch/11x4.c", "none");
    setCoordinate(11, 6, "/areas/eledhel/under-city/central-city/11x6.c", "none");
    setCoordinate(13, 6, "/areas/eledhel/under-city/werric-branch/13x6.c", "none");
    setCoordinate(14, 6, "/areas/eledhel/under-city/central-city/14x6.c", "none");
    setCoordinate(15, 6, "/areas/eledhel/under-city/central-city/15x6.c", "none");
    setCoordinate(16, 6, "/areas/eledhel/under-city/central-city/16x6.c", "none");
    setCoordinate(17, 6, "/areas/eledhel/under-city/central-city/17x6.c", "none");
    setCoordinate(18, 6, "/areas/eledhel/under-city/central-city/18x6.c", "none");
    setCoordinate(8, 4, "/areas/eledhel/under-city/central-city/8x4.c", "none");
    setCoordinate(9, 4, "/areas/eledhel/under-city/central-city/9x4.c", "none");
    setCoordinate(10, 4, "/areas/eledhel/under-city/central-city/10x4.c", "none");
    setCoordinate(13, 4, "/areas/eledhel/under-city/central-city/13x4.c", "none");
    setCoordinate(14, 4, "/areas/eledhel/under-city/central-city/14x4.c", "none");
    setCoordinate(15, 4, "/areas/eledhel/under-city/central-city/15x4.c", "none");
}
