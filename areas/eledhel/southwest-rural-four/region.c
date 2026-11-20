//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setRegionName("southern drove road and crossings");
    setRegionType("hilly rural");
    setRegionLevel(3);
    setDimensions(25, 10);
    setEntryCoordinate(12, 0,
        "/areas/eledhel/southwest-rural-four/12x0.c", "north",
        "/areas/eledhel/south-rural-route-07/24x2.c");

    setCoordinate(12, 0,
        "/areas/eledhel/southwest-rural-four/12x0.c", "entry");
    setCoordinate(12, 1,
        "/areas/eledhel/southwest-rural-four/12x1.c", "path");
    setCoordinate(12, 2,
        "/areas/eledhel/southwest-rural-four/12x2.c", "path");
    setCoordinate(12, 3,
        "/areas/eledhel/southwest-rural-four/12x3.c", "path");
    setCoordinate(12, 4,
        "/areas/eledhel/southwest-rural-four/12x4.c", "path");
    setCoordinate(12, 5,
        "/areas/eledhel/southwest-rural-four/12x5.c", "path");
    setCoordinate(12, 6,
        "/areas/eledhel/southwest-rural-four/12x6.c", "path");
    setCoordinate(12, 7,
        "/areas/eledhel/southwest-rural-four/12x7.c", "path");
    setCoordinate(12, 8,
        "/areas/eledhel/southwest-rural-four/12x8.c", "path");
    setCoordinate(12, 9,
        "/areas/eledhel/southwest-rural-four/12x9.c", "path");
    setCoordinate(13, 9,
        "/areas/eledhel/southwest-rural-four/13x9.c", "path");
    setCoordinate(14, 9,
        "/areas/eledhel/southwest-rural-four/14x9.c", "path");
    setCoordinate(15, 9,
        "/areas/eledhel/southwest-rural-four/15x9.c", "path");
    setCoordinate(16, 9,
        "/areas/eledhel/southwest-rural-four/16x9.c", "path");
    setCoordinate(17, 9,
        "/areas/eledhel/southwest-rural-four/17x9.c", "path");
    setCoordinate(18, 9,
        "/areas/eledhel/southwest-rural-four/18x9.c", "path");
    setCoordinate(19, 9,
        "/areas/eledhel/southwest-rural-four/19x9.c", "path");
    setCoordinate(20, 9,
        "/areas/eledhel/southwest-rural-four/20x9.c", "path");
    setCoordinate(21, 9,
        "/areas/eledhel/southwest-rural-four/21x9.c", "path");
    setCoordinate(22, 9,
        "/areas/eledhel/southwest-rural-four/22x9.c", "path");
    setCoordinate(23, 9,
        "/areas/eledhel/southwest-rural-four/23x9.c", "path");
    setCoordinate(24, 9,
        "/areas/eledhel/southwest-rural-four/24x9.c", "exit");
    setCoordinate(11, 3,
        "/areas/eledhel/southwest-rural-four/11x3.c", "path");
    setCoordinate(10, 3,
        "/areas/eledhel/southwest-rural-four/10x3.c", "room");
    setCoordinate(10, 2,
        "/areas/eledhel/southwest-rural-four/10x2.c", "room");
    setCoordinate(10, 4,
        "/areas/eledhel/southwest-rural-four/10x4.c", "room");
    setCoordinate(13, 6,
        "/areas/eledhel/southwest-rural-four/13x6.c", "path");
    setCoordinate(14, 6,
        "/areas/eledhel/southwest-rural-four/14x6.c", "room");
    setCoordinate(14, 5,
        "/areas/eledhel/southwest-rural-four/14x5.c", "room");
}
