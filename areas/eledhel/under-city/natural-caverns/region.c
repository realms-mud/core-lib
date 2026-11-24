//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setRegionName("The Natural Caverns beyond Eledhel");
    setRegionType("cave");
    asManualRegion();
    setDimensions(8, 6);

    setEntryCoordinate(0, 0,
        "/areas/eledhel/under-city/natural-caverns/0x0.c", "up",
        "/areas/eledhel/under-city/fox-route/0x1.c");
    setCoordinate(1, 0, "/areas/eledhel/under-city/natural-caverns/1x0.c", "none");
    setCoordinate(2, 0, "/areas/eledhel/under-city/natural-caverns/2x0.c", "none");
    setCoordinate(3, 0, "/areas/eledhel/under-city/natural-caverns/3x0.c", "none");
    setCoordinate(4, 0, "/areas/eledhel/under-city/natural-caverns/4x0.c", "none");
    setCoordinate(5, 0, "/areas/eledhel/under-city/natural-caverns/5x0.c", "none");
    setCoordinate(6, 0, "/areas/eledhel/under-city/natural-caverns/6x0.c", "none");
    setCoordinate(7, 0, "/areas/eledhel/under-city/natural-caverns/7x0.c", "none");
    setCoordinate(7, 1, "/areas/eledhel/under-city/natural-caverns/7x1.c", "none");
    setCoordinate(7, 2, "/areas/eledhel/under-city/natural-caverns/7x2.c", "none");
    setCoordinate(7, 3, "/areas/eledhel/under-city/natural-caverns/7x3.c", "none");
    setCoordinate(7, 4, "/areas/eledhel/under-city/natural-caverns/7x4.c", "none");
    setCoordinate(7, 5, "/areas/eledhel/under-city/natural-caverns/7x5.c", "none");
    setCoordinate(6, 5, "/areas/eledhel/under-city/natural-caverns/6x5.c", "none");
    setCoordinate(5, 5, "/areas/eledhel/under-city/natural-caverns/5x5.c", "none");
    setCoordinate(4, 5, "/areas/eledhel/under-city/natural-caverns/4x5.c", "none");
}
