//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setRegionName("Northern Trail from Tol-Dhurath to Hrondil");
    setRegionType("forest");
    setRegionLevel(5);
    setDimensions(25, 10);

    setCoordinate(0, 4,
        "/areas/tol-dhurath/northern-trail/0x4.c", "road");
    setCoordinate(1, 4,
        "/areas/tol-dhurath/northern-trail/1x4.c", "road");
    setCoordinate(2, 4,
        "/areas/tol-dhurath/northern-trail/2x4.c", "road");
    setCoordinate(3, 4,
        "/areas/tol-dhurath/northern-trail/3x4.c", "road");
    setCoordinate(3, 5,
        "/areas/tol-dhurath/northern-trail/3x5.c", "room");
    setCoordinate(4, 4,
        "/areas/tol-dhurath/northern-trail/4x4.c", "road");
    setCoordinate(5, 4,
        "/areas/tol-dhurath/northern-trail/5x4.c", "road");
    setCoordinate(6, 4,
        "/areas/tol-dhurath/northern-trail/6x4.c", "road");
    setCoordinate(6, 5,
        "/areas/tol-dhurath/northern-trail/6x5.c", "room");
    setCoordinate(7, 4,
        "/areas/tol-dhurath/northern-trail/7x4.c", "road");
    setCoordinate(8, 4,
        "/areas/tol-dhurath/northern-trail/8x4.c", "road");
    setCoordinate(9, 4,
        "/areas/tol-dhurath/northern-trail/9x4.c", "road");
    setCoordinate(10, 4,
        "/areas/tol-dhurath/northern-trail/10x4.c", "road");
    setCoordinate(11, 4,
        "/areas/tol-dhurath/northern-trail/11x4.c", "road");
    setCoordinate(12, 4,
        "/areas/tol-dhurath/northern-trail/12x4.c", "road");
    setCoordinate(13, 4,
        "/areas/tol-dhurath/northern-trail/13x4.c", "road");
    setCoordinate(14, 4,
        "/areas/tol-dhurath/northern-trail/14x4.c", "road");
    setCoordinate(14, 5,
        "/areas/tol-dhurath/northern-trail/14x5.c", "room");
    setCoordinate(15, 4,
        "/areas/tol-dhurath/northern-trail/15x4.c", "road");
    setCoordinate(16, 4,
        "/areas/tol-dhurath/northern-trail/16x4.c", "road");
    setCoordinate(17, 4,
        "/areas/tol-dhurath/northern-trail/17x4.c", "road");
    setCoordinate(18, 4,
        "/areas/tol-dhurath/northern-trail/18x4.c", "road");
    setCoordinate(19, 4,
        "/areas/tol-dhurath/northern-trail/19x4.c", "road");
    setEntryCoordinate(20, 0,
        "/areas/tol-dhurath/northern-trail/20x0.c", "south",
        "/areas/tol-dhurath/forest-1/15x9.c");
    setCoordinate(20, 1,
        "/areas/tol-dhurath/northern-trail/20x1.c", "road");
    setCoordinate(20, 2,
        "/areas/tol-dhurath/northern-trail/20x2.c", "road");
    setCoordinate(20, 3,
        "/areas/tol-dhurath/northern-trail/20x3.c", "road");
    setCoordinate(20, 4,
        "/areas/tol-dhurath/northern-trail/20x4.c", "road");
}
