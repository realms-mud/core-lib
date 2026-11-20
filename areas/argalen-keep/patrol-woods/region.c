//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setRegionName("Argalen Patrol Woods");
    setRegionType("forest");
    setRegionLevel(3);
    setDimensions(25, 10);
    setEntryCoordinate(24, 4,
        "/areas/argalen-keep/patrol-woods/24x4.c", "east",
        "/areas/argalen-keep/surrounding/8x4.c");

    setCoordinate(0, 4,
        "/areas/argalen-keep/patrol-woods/0x4.c", "exit");
    setCoordinate(1, 4,
        "/areas/argalen-keep/patrol-woods/1x4.c", "path");
    setCoordinate(2, 4,
        "/areas/argalen-keep/patrol-woods/2x4.c", "path");
    setCoordinate(3, 4,
        "/areas/argalen-keep/patrol-woods/3x4.c", "path");
    setCoordinate(4, 4,
        "/areas/argalen-keep/patrol-woods/4x4.c", "path");
    setCoordinate(5, 4,
        "/areas/argalen-keep/patrol-woods/5x4.c", "path");
    setCoordinate(6, 4,
        "/areas/argalen-keep/patrol-woods/6x4.c", "path");
    setCoordinate(7, 4,
        "/areas/argalen-keep/patrol-woods/7x4.c", "path");
    setCoordinate(8, 4,
        "/areas/argalen-keep/patrol-woods/8x4.c", "path");
    setCoordinate(9, 4,
        "/areas/argalen-keep/patrol-woods/9x4.c", "path");
    setCoordinate(10, 4,
        "/areas/argalen-keep/patrol-woods/10x4.c", "path");
    setCoordinate(11, 4,
        "/areas/argalen-keep/patrol-woods/11x4.c", "path");
    setCoordinate(12, 4,
        "/areas/argalen-keep/patrol-woods/12x4.c", "path");
    setCoordinate(13, 4,
        "/areas/argalen-keep/patrol-woods/13x4.c", "path");
    setCoordinate(14, 4,
        "/areas/argalen-keep/patrol-woods/14x4.c", "path");
    setCoordinate(15, 4,
        "/areas/argalen-keep/patrol-woods/15x4.c", "path");
    setCoordinate(16, 4,
        "/areas/argalen-keep/patrol-woods/16x4.c", "path");
    setCoordinate(17, 4,
        "/areas/argalen-keep/patrol-woods/17x4.c", "path");
    setCoordinate(18, 4,
        "/areas/argalen-keep/patrol-woods/18x4.c", "path");
    setCoordinate(19, 4,
        "/areas/argalen-keep/patrol-woods/19x4.c", "path");
    setCoordinate(20, 4,
        "/areas/argalen-keep/patrol-woods/20x4.c", "path");
    setCoordinate(21, 4,
        "/areas/argalen-keep/patrol-woods/21x4.c", "path");
    setCoordinate(22, 4,
        "/areas/argalen-keep/patrol-woods/22x4.c", "path");
    setCoordinate(23, 4,
        "/areas/argalen-keep/patrol-woods/23x4.c", "path");
    setCoordinate(12, 3,
        "/areas/argalen-keep/patrol-woods/12x3.c", "room");
    setCoordinate(18, 3,
        "/areas/argalen-keep/patrol-woods/18x3.c", "room");
}
