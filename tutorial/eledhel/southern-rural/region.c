//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
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
        "/lib/tutorial/eledhel/southern-rural/3x9.c", "north"
        "/lib/tutorial/eledhel/southern-city/12x0.c");

    setCoordinate(0, 0,
        "/lib/tutorial/eledhel/southern-rural/0x0.c", "path");
    setCoordinate(0, 1,
        "/lib/tutorial/eledhel/southern-rural/0x1.c", "path");
    setCoordinate(0, 2,
        "/lib/tutorial/eledhel/southern-rural/0x2.c", "path");
    setCoordinate(0, 3,
        "/lib/tutorial/eledhel/southern-rural/0x3.c", "room");
    setCoordinate(0, 4,
        "/lib/tutorial/eledhel/southern-rural/0x4.c", "path");
    setCoordinate(0, 5,
        "/lib/tutorial/eledhel/southern-rural/0x5.c", "path");
    setCoordinate(0, 6,
        "/lib/tutorial/eledhel/southern-rural/0x6.c", "path");
    setCoordinate(0, 7,
        "/lib/tutorial/eledhel/southern-rural/0x7.c", "room");
    setCoordinate(1, 0,
        "/lib/tutorial/eledhel/southern-rural/1x0.c", "path");
    setCoordinate(1, 2,
        "/lib/tutorial/eledhel/southern-rural/1x2.c", "room");
    setCoordinate(1, 3,
        "/lib/tutorial/eledhel/southern-rural/1x3.c", "path");
    setCoordinate(1, 5,
        "/lib/tutorial/eledhel/southern-rural/1x5.c", "path");
    setCoordinate(1, 6,
        "/lib/tutorial/eledhel/southern-rural/1x6.c", "path");
    setCoordinate(1, 7,
        "/lib/tutorial/eledhel/southern-rural/1x7.c", "path");
    setCoordinate(2, 0,
        "/lib/tutorial/eledhel/southern-rural/2x0.c", "exit");
    setCoordinate(2, 5,
        "/lib/tutorial/eledhel/southern-rural/2x5.c", "path");
    setCoordinate(2, 6,
        "/lib/tutorial/eledhel/southern-rural/2x6.c", "path");
    setCoordinate(2, 7,
        "/lib/tutorial/eledhel/southern-rural/2x7.c", "path");
    setCoordinate(3, 6,
        "/lib/tutorial/eledhel/southern-rural/3x6.c", "path");
    setCoordinate(3, 7,
        "/lib/tutorial/eledhel/southern-rural/3x7.c", "path");
    setCoordinate(3, 8,
        "/lib/tutorial/eledhel/southern-rural/3x8.c", "path");
    setCoordinate(3, 9,
        "/lib/tutorial/eledhel/southern-rural/3x9.c", "entry");
    setCoordinate(4, 6,
        "/lib/tutorial/eledhel/southern-rural/4x6.c", "room");
    setCoordinate(4, 7,
        "/lib/tutorial/eledhel/southern-rural/4x7.c", "path");
    setCoordinate(4, 9,
        "/lib/tutorial/eledhel/southern-rural/4x9.c", "room");

    // MapIcons
}

