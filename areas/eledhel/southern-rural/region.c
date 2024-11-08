//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setRegionName("southern-rural");
    setRegionType("rural");
    setDimensions(5, 10);
    setEntryCoordinate(3, 9,
        "/areas/eledhel/southern-rural/3x9.c", "north",
        "/areas/eledhel/southern-city/12x0.c");

    setCoordinate(0, 0,
        "/areas/eledhel/southern-rural/0x0.c", "path");
    setCoordinate(0, 1,
        "/areas/eledhel/southern-rural/0x1.c", "path");
    setCoordinate(0, 2,
        "/areas/eledhel/southern-rural/0x2.c", "path");
    setCoordinate(0, 3,
        "/areas/eledhel/southern-rural/0x3.c", "room");
    setCoordinate(0, 4,
        "/areas/eledhel/southern-rural/0x4.c", "path");
    setCoordinate(0, 5,
        "/areas/eledhel/southern-rural/0x5.c", "path");
    setCoordinate(0, 6,
        "/areas/eledhel/southern-rural/0x6.c", "path");
    setCoordinate(0, 7,
        "/areas/eledhel/southern-rural/0x7.c", "room");
    setCoordinate(1, 0,
        "/areas/eledhel/southern-rural/1x0.c", "path");
    setCoordinate(1, 2,
        "/areas/eledhel/southern-rural/1x2.c", "room");
    setCoordinate(1, 3,
        "/areas/eledhel/southern-rural/1x3.c", "path");
    setCoordinate(1, 5,
        "/areas/eledhel/southern-rural/1x5.c", "path");
    setCoordinate(1, 6,
        "/areas/eledhel/southern-rural/1x6.c", "path");
    setCoordinate(1, 7,
        "/areas/eledhel/southern-rural/1x7.c", "path");
    setCoordinate(2, 0,
        "/areas/eledhel/southern-rural/2x0.c", "exit");
    setCoordinate(2, 5,
        "/areas/eledhel/southern-rural/2x5.c", "path");
    setCoordinate(2, 6,
        "/areas/eledhel/southern-rural/2x6.c", "path");
    setCoordinate(2, 7,
        "/areas/eledhel/southern-rural/2x7.c", "path");
    setCoordinate(3, 6,
        "/areas/eledhel/southern-rural/3x6.c", "path");
    setCoordinate(3, 7,
        "/areas/eledhel/southern-rural/3x7.c", "path");
    setCoordinate(3, 8,
        "/areas/eledhel/southern-rural/3x8.c", "path");
    setCoordinate(3, 9,
        "/areas/eledhel/southern-rural/3x9.c", "entry");
    setCoordinate(4, 6,
        "/areas/eledhel/southern-rural/4x6.c", "room");
    setCoordinate(4, 7,
        "/areas/eledhel/southern-rural/4x7.c", "path");
    setCoordinate(4, 9,
        "/areas/eledhel/southern-rural/4x9.c", "room");

    // MapIcons
}

