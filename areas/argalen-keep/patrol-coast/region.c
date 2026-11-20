//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setRegionName("Argalen Patrol Coast");
    setRegionType("rocky shoreline");
    setRegionLevel(2);
    setDimensions(25, 10);
    setEntryCoordinate(12, 0,
        "/areas/argalen-keep/patrol-coast/12x0.c", "north",
        "/areas/argalen-keep/surrounding/12x0.c");

    setCoordinate(12, 1,
        "/areas/argalen-keep/patrol-coast/12x1.c", "path");
    setCoordinate(12, 2,
        "/areas/argalen-keep/patrol-coast/12x2.c", "path");
    setCoordinate(12, 3,
        "/areas/argalen-keep/patrol-coast/12x3.c", "path");
    setCoordinate(12, 4,
        "/areas/argalen-keep/patrol-coast/12x4.c", "path");
    setCoordinate(13, 4,
        "/areas/argalen-keep/patrol-coast/13x4.c", "path");
    setCoordinate(14, 4,
        "/areas/argalen-keep/patrol-coast/14x4.c", "path");
    setCoordinate(15, 4,
        "/areas/argalen-keep/patrol-coast/15x4.c", "path");
    setCoordinate(16, 4,
        "/areas/argalen-keep/patrol-coast/16x4.c", "path");
    setCoordinate(17, 4,
        "/areas/argalen-keep/patrol-coast/17x4.c", "path");
    setCoordinate(18, 4,
        "/areas/argalen-keep/patrol-coast/18x4.c", "path");
    setCoordinate(19, 4,
        "/areas/argalen-keep/patrol-coast/19x4.c", "path");
    setCoordinate(20, 4,
        "/areas/argalen-keep/patrol-coast/20x4.c", "path");
    setCoordinate(21, 4,
        "/areas/argalen-keep/patrol-coast/21x4.c", "path");
    setCoordinate(22, 4,
        "/areas/argalen-keep/patrol-coast/22x4.c", "path");
    setCoordinate(23, 4,
        "/areas/argalen-keep/patrol-coast/23x4.c", "path");
    setCoordinate(24, 4,
        "/areas/argalen-keep/patrol-coast/24x4.c", "path");
    setCoordinate(11, 2,
        "/areas/argalen-keep/patrol-coast/11x2.c", "farm");
    setCoordinate(10, 2,
        "/areas/argalen-keep/patrol-coast/10x2.c", "farm");
    setCoordinate(11, 4,
        "/areas/argalen-keep/patrol-coast/11x4.c", "path");
    setCoordinate(10, 4,
        "/areas/argalen-keep/patrol-coast/10x4.c", "path");
    setCoordinate(9, 4,
        "/areas/argalen-keep/patrol-coast/9x4.c", "room");
    setCoordinate(8, 4,
        "/areas/argalen-keep/patrol-coast/8x4.c", "room");
    setCoordinate(10, 5,
        "/areas/argalen-keep/patrol-coast/10x5.c", "room");
    setCoordinate(17, 5,
        "/areas/argalen-keep/patrol-coast/17x5.c", "path");
    setCoordinate(17, 6,
        "/areas/argalen-keep/patrol-coast/17x6.c", "room");
    setCoordinate(21, 5,
        "/areas/argalen-keep/patrol-coast/21x5.c", "path");
    setCoordinate(21, 6,
        "/areas/argalen-keep/patrol-coast/21x6.c", "room");
}
