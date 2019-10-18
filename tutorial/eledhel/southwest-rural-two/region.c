//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setRegionName("southwest-rural-two");
    setRegionType("rural");
    setDimensions(25, 5);
    setEntryCoordinate(24, 3,
        "/lib/tutorial/eledhel/southwest-rural-two/24x3.c", "east"
        "/lib/tutorial/eledhel/southwest-rural-one/0x2.c");

    setCoordinate(0, 2,
        "/lib/tutorial/eledhel/southwest-rural-two/0x2.c", "exit");
    setCoordinate(10, 0,
        "/lib/tutorial/eledhel/southwest-rural-two/10x0.c", "path");
    setCoordinate(10, 1,
        "/lib/tutorial/eledhel/southwest-rural-two/10x1.c", "path");
    setCoordinate(11, 0,
        "/lib/tutorial/eledhel/southwest-rural-two/11x0.c", "path");
    setCoordinate(12, 0,
        "/lib/tutorial/eledhel/southwest-rural-two/12x0.c", "path");
    setCoordinate(12, 1,
        "/lib/tutorial/eledhel/southwest-rural-two/12x1.c", "room");
    setCoordinate(13, 1,
        "/lib/tutorial/eledhel/southwest-rural-two/13x1.c", "path");
    setCoordinate(14, 1,
        "/lib/tutorial/eledhel/southwest-rural-two/14x1.c", "path");
    setCoordinate(15, 1,
        "/lib/tutorial/eledhel/southwest-rural-two/15x1.c", "path");
    setCoordinate(16, 1,
        "/lib/tutorial/eledhel/southwest-rural-two/16x1.c", "path");
    setCoordinate(17, 1,
        "/lib/tutorial/eledhel/southwest-rural-two/17x1.c", "path");
    setCoordinate(18, 1,
        "/lib/tutorial/eledhel/southwest-rural-two/18x1.c", "path");
    setCoordinate(18, 2,
        "/lib/tutorial/eledhel/southwest-rural-two/18x2.c", "room");
    setCoordinate(19, 1,
        "/lib/tutorial/eledhel/southwest-rural-two/19x1.c", "path");
    setCoordinate(1, 2,
        "/lib/tutorial/eledhel/southwest-rural-two/1x2.c", "room");
    setCoordinate(1, 3,
        "/lib/tutorial/eledhel/southwest-rural-two/1x3.c", "path");
    setCoordinate(1, 4,
        "/lib/tutorial/eledhel/southwest-rural-two/1x4.c", "path");
    setCoordinate(20, 1,
        "/lib/tutorial/eledhel/southwest-rural-two/20x1.c", "path");
    setCoordinate(21, 1,
        "/lib/tutorial/eledhel/southwest-rural-two/21x1.c", "path");
    setCoordinate(21, 2,
        "/lib/tutorial/eledhel/southwest-rural-two/21x2.c", "room");
    setCoordinate(22, 1,
        "/lib/tutorial/eledhel/southwest-rural-two/22x1.c", "path");
    setCoordinate(22, 2,
        "/lib/tutorial/eledhel/southwest-rural-two/22x2.c", "path");
    setCoordinate(22, 3,
        "/lib/tutorial/eledhel/southwest-rural-two/22x3.c", "path");
    setCoordinate(23, 1,
        "/lib/tutorial/eledhel/southwest-rural-two/23x1.c", "path");
    setCoordinate(23, 3,
        "/lib/tutorial/eledhel/southwest-rural-two/23x3.c", "path");
    setCoordinate(23, 4,
        "/lib/tutorial/eledhel/southwest-rural-two/23x4.c", "path");
    setCoordinate(24, 0,
        "/lib/tutorial/eledhel/southwest-rural-two/24x0.c", "room");
    setCoordinate(24, 1,
        "/lib/tutorial/eledhel/southwest-rural-two/24x1.c", "path");
    setCoordinate(24, 3,
        "/lib/tutorial/eledhel/southwest-rural-two/24x3.c", "path");
    setCoordinate(24, 4,
        "/lib/tutorial/eledhel/southwest-rural-two/24x4.c", "path");
    setCoordinate(2, 4,
        "/lib/tutorial/eledhel/southwest-rural-two/2x4.c", "path");
    setCoordinate(3, 4,
        "/lib/tutorial/eledhel/southwest-rural-two/3x4.c", "path");
    setCoordinate(4, 4,
        "/lib/tutorial/eledhel/southwest-rural-two/4x4.c", "path");
    setCoordinate(5, 2,
        "/lib/tutorial/eledhel/southwest-rural-two/5x2.c", "path");
    setCoordinate(5, 3,
        "/lib/tutorial/eledhel/southwest-rural-two/5x3.c", "room");
    setCoordinate(5, 4,
        "/lib/tutorial/eledhel/southwest-rural-two/5x4.c", "path");
    setCoordinate(6, 1,
        "/lib/tutorial/eledhel/southwest-rural-two/6x1.c", "path");
    setCoordinate(6, 2,
        "/lib/tutorial/eledhel/southwest-rural-two/6x2.c", "path");
    setCoordinate(7, 1,
        "/lib/tutorial/eledhel/southwest-rural-two/7x1.c", "path");
    setCoordinate(8, 0,
        "/lib/tutorial/eledhel/southwest-rural-two/8x0.c", "path");
    setCoordinate(8, 1,
        "/lib/tutorial/eledhel/southwest-rural-two/8x1.c", "path");
    setCoordinate(9, 0,
        "/lib/tutorial/eledhel/southwest-rural-two/9x0.c", "path");
    setCoordinate(9, 1,
        "/lib/tutorial/eledhel/southwest-rural-two/9x1.c", "path");
}
