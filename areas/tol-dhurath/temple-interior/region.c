//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setRegionName("Tol-Dhurath Temple, Main Level");
    setRegionType("tol-dhurath");
    setDimensions(25, 10);

    setCoordinate(0, 0,
        "/areas/tol-dhurath/temple-interior/0x0.c", "none");
    setCoordinate(0, 1,
        "/areas/tol-dhurath/temple-interior/0x1.c", "none");
    setCoordinate(0, 2,
        "/areas/tol-dhurath/temple-interior/0x2.c", "none");
    setCoordinate(0, 3,
        "/areas/tol-dhurath/temple-interior/0x3.c", "none");
    setCoordinate(0, 4,
        "/areas/tol-dhurath/temple-interior/0x4.c", "none");
    setCoordinate(1, 0,
        "/areas/tol-dhurath/temple-interior/1x0.c", "none");
    setCoordinate(1, 1,
        "/areas/tol-dhurath/temple-interior/1x1.c", "none");
    setCoordinate(1, 2,
        "/areas/tol-dhurath/temple-interior/1x2.c", "none");
    setCoordinate(1, 3,
        "/areas/tol-dhurath/temple-interior/1x3.c", "none");
    setCoordinate(1, 4,
        "/areas/tol-dhurath/temple-interior/1x4.c", "none");
    setCoordinate(2, 0,
        "/areas/tol-dhurath/temple-interior/2x0.c", "none");
    setCoordinate(2, 1,
        "/areas/tol-dhurath/temple-interior/2x1.c", "none");
    setCoordinate(2, 2,
        "/areas/tol-dhurath/temple-interior/2x2.c", "none");
    setCoordinate(2, 3,
        "/areas/tol-dhurath/temple-interior/2x3.c", "none");
    setCoordinate(2, 4,
        "/areas/tol-dhurath/temple-interior/2x4.c", "none");
    setCoordinate(3, 0,
        "/areas/tol-dhurath/temple-interior/3x0.c", "none");
    setCoordinate(3, 1,
        "/areas/tol-dhurath/temple-interior/3x1.c", "none");
    setCoordinate(3, 2,
        "/areas/tol-dhurath/temple-interior/3x2.c", "none");
    setCoordinate(3, 3,
        "/areas/tol-dhurath/temple-interior/3x3.c", "none");
    setCoordinate(3, 4,
        "/areas/tol-dhurath/temple-interior/3x4.c", "none");
    setCoordinate(3, 5,
        "/areas/tol-dhurath/temple-interior/3x5.c", "none");
    setCoordinate(3, 6,
        "/areas/tol-dhurath/temple-interior/3x6.c", "none");
    setCoordinate(3, 7,
        "/areas/tol-dhurath/temple-interior/3x7.c", "none");
    setCoordinate(3, 8,
        "/areas/tol-dhurath/temple-interior/3x8.c", "none");
    setCoordinate(3, 9,
        "/areas/tol-dhurath/temple-interior/3x9.c", "none");
    setCoordinate(4, 0,
        "/areas/tol-dhurath/temple-interior/4x0.c", "none");
    setCoordinate(4, 1,
        "/areas/tol-dhurath/temple-interior/4x1.c", "none");
    setCoordinate(4, 2,
        "/areas/tol-dhurath/temple-interior/4x2.c", "none");
    /*
    setCoordinate(4, 3,
        "/areas/tol-dhurath/temple-interior/4x3.c", "none");
    setCoordinate(4, 4,
        "/areas/tol-dhurath/temple-interior/4x4.c", "none");
    setCoordinate(4, 5,
        "/areas/tol-dhurath/temple-interior/4x5.c", "none");
    setCoordinate(4, 6,
        "/areas/tol-dhurath/temple-interior/4x6.c", "none");
    setCoordinate(4, 7,
        "/areas/tol-dhurath/temple-interior/4x7.c", "none");
    setCoordinate(4, 8,
        "/areas/tol-dhurath/temple-interior/4x8.c", "none");
    setCoordinate(4, 9,
        "/areas/tol-dhurath/temple-interior/4x9.c", "none");
    setCoordinate(5, 0,
        "/areas/tol-dhurath/temple-interior/5x0.c", "none");
    setCoordinate(5, 1,
        "/areas/tol-dhurath/temple-interior/5x1.c", "none");
        */
    setCoordinate(5, 2,
        "/areas/tol-dhurath/temple-interior/5x2.c", "none");
    /*
    setCoordinate(5, 3,
        "/areas/tol-dhurath/temple-interior/5x3.c", "none");
    setCoordinate(5, 4,
        "/areas/tol-dhurath/temple-interior/5x4.c", "none");
    setCoordinate(5, 5,
        "/areas/tol-dhurath/temple-interior/5x5.c", "none");
    setCoordinate(5, 6,
        "/areas/tol-dhurath/temple-interior/5x6.c", "none");
    setCoordinate(5, 7,
        "/areas/tol-dhurath/temple-interior/5x7.c", "none");
    setCoordinate(5, 8,
        "/areas/tol-dhurath/temple-interior/5x8.c", "none");
    setCoordinate(5, 9,
        "/areas/tol-dhurath/temple-interior/5x9.c", "none");
    setCoordinate(6, 0,
        "/areas/tol-dhurath/temple-interior/6x0.c", "none");
    setCoordinate(6, 1,
        "/areas/tol-dhurath/temple-interior/6x1.c", "none");
        */
    setCoordinate(6, 2,
        "/areas/tol-dhurath/temple-interior/6x2.c", "none");
    setCoordinate(6, 3,
        "/areas/tol-dhurath/temple-interior/6x3.c", "none");
    setCoordinate(6, 4,
        "/areas/tol-dhurath/temple-interior/6x4.c", "none");
/*    setCoordinate(6, 5,
        "/areas/tol-dhurath/temple-interior/6x5.c", "none");
    setCoordinate(6, 6,
        "/areas/tol-dhurath/temple-interior/6x6.c", "none");
    setCoordinate(6, 7,
        "/areas/tol-dhurath/temple-interior/6x7.c", "none");
    setCoordinate(6, 8,
        "/areas/tol-dhurath/temple-interior/6x8.c", "none");
    setCoordinate(6, 9,
        "/areas/tol-dhurath/temple-interior/6x9.c", "none");
        */
    setCoordinate(7, 3,
        "/areas/tol-dhurath/temple-interior/7x3.c", "none");
    setCoordinate(7, 4,
        "/areas/tol-dhurath/temple-interior/7x4.c", "none");
    setCoordinate(8, 2,
        "/areas/tol-dhurath/temple-interior/8x2.c", "none");
    setCoordinate(8, 3,
        "/areas/tol-dhurath/temple-interior/8x3.c", "none");
    setCoordinate(8, 4,
        "/areas/tol-dhurath/temple-interior/8x4.c", "none");
}
