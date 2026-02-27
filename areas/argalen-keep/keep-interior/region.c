//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setRegionName("Argalen Keep Interior");
    setRegionType("stone keep");
    setDimensions(10, 8);

    // === Ground Floor ===
    // Gatehouse entry (y=0)
    setCoordinate(5, 0,
        "/areas/argalen-keep/keep-interior/5x0.c", "none");

    // Courtyard (y=1)
    setCoordinate(4, 1,
        "/areas/argalen-keep/keep-interior/4x1.c", "none");
    setCoordinate(5, 1,
        "/areas/argalen-keep/keep-interior/5x1.c", "none");
    setCoordinate(6, 1,
        "/areas/argalen-keep/keep-interior/6x1.c", "none");

    // Main hallway (y=2)
    setCoordinate(3, 2,
        "/areas/argalen-keep/keep-interior/3x2.c", "none");
    setCoordinate(4, 2,
        "/areas/argalen-keep/keep-interior/4x2.c", "none");
    setCoordinate(5, 2,
        "/areas/argalen-keep/keep-interior/5x2.c", "none");
    setCoordinate(6, 2,
        "/areas/argalen-keep/keep-interior/6x2.c", "none");
    setCoordinate(7, 2,
        "/areas/argalen-keep/keep-interior/7x2.c", "none");

    // Great hall and side rooms (y=3)
    setCoordinate(3, 3,
        "/areas/argalen-keep/keep-interior/3x3.c", "none");
    setCoordinate(4, 3,
        "/areas/argalen-keep/keep-interior/4x3.c", "none");
    setCoordinate(5, 3,
        "/areas/argalen-keep/keep-interior/5x3.c", "none");
    setCoordinate(6, 3,
        "/areas/argalen-keep/keep-interior/6x3.c", "none");
    setCoordinate(7, 3,
        "/areas/argalen-keep/keep-interior/7x3.c", "none");

    // Great hall north and back hallway (y=4)
    setCoordinate(3, 4,
        "/areas/argalen-keep/keep-interior/3x4.c", "none");
    setCoordinate(4, 4,
        "/areas/argalen-keep/keep-interior/4x4.c", "none");
    setCoordinate(5, 4,
        "/areas/argalen-keep/keep-interior/5x4.c", "none");
    setCoordinate(6, 4,
        "/areas/argalen-keep/keep-interior/6x4.c", "none");
    setCoordinate(7, 4,
        "/areas/argalen-keep/keep-interior/7x4.c", "none");

    // Upper hallway (y=5)
    setCoordinate(3, 5,
        "/areas/argalen-keep/keep-interior/3x5.c", "none");
    setCoordinate(4, 5,
        "/areas/argalen-keep/keep-interior/4x5.c", "none");
    setCoordinate(5, 5,
        "/areas/argalen-keep/keep-interior/5x5.c", "none");
    setCoordinate(6, 5,
        "/areas/argalen-keep/keep-interior/6x5.c", "none");
    setCoordinate(7, 5,
        "/areas/argalen-keep/keep-interior/7x5.c", "none");

    // Lord's chambers and study (y=6)
    setCoordinate(3, 6,
        "/areas/argalen-keep/keep-interior/3x6.c", "none");
    setCoordinate(5, 6,
        "/areas/argalen-keep/keep-interior/5x6.c", "none");
    setCoordinate(7, 6,
        "/areas/argalen-keep/keep-interior/7x6.c", "none");
}
