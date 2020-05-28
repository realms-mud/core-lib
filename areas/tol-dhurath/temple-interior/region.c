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

    setCoordinate(6, 2,
        "/areas/tol-dhurath/temple-interior/6x2.c", "none");
    setCoordinate(6, 3,
        "/areas/tol-dhurath/temple-interior/6x3.c", "none");
    setCoordinate(6, 4,
        "/areas/tol-dhurath/temple-interior/6x4.c", "none");
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
