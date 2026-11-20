//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setRegionName("southern drove country");
    setRegionType("hilly rural");
    setRegionLevel(5);
    setDimensions(25, 10);
    setEntryCoordinate(12, 0,
        "/areas/eledhel/south-coast-one/12x0.c", "north",
        "/areas/linwaeth/12x9.c");

    setCoordinate(12, 0, "/areas/eledhel/south-coast-one/12x0.c", "entry");
    setCoordinate(12, 1, "/areas/eledhel/south-coast-one/12x1.c", "path");
    setCoordinate(12, 2, "/areas/eledhel/south-coast-one/12x2.c", "path");
    setCoordinate(12, 3, "/areas/eledhel/south-coast-one/12x3.c", "path");
    setCoordinate(12, 4, "/areas/eledhel/south-coast-one/12x4.c", "path");
    setCoordinate(12, 5, "/areas/eledhel/south-coast-one/12x5.c", "path");
    setCoordinate(12, 6, "/areas/eledhel/south-coast-one/12x6.c", "path");
    setCoordinate(12, 7, "/areas/eledhel/south-coast-one/12x7.c", "path");
    setCoordinate(12, 8, "/areas/eledhel/south-coast-one/12x8.c", "path");
    setCoordinate(12, 9, "/areas/eledhel/south-coast-one/12x9.c", "exit");
    setCoordinate(13, 2, "/areas/eledhel/south-coast-one/13x2.c", "path");
    setCoordinate(14, 2, "/areas/eledhel/south-coast-one/14x2.c", "room");
    setCoordinate(15, 2, "/areas/eledhel/south-coast-one/15x2.c", "room");
    setCoordinate(14, 1, "/areas/eledhel/south-coast-one/14x1.c", "room");
    setCoordinate(14, 3, "/areas/eledhel/south-coast-one/14x3.c", "room");
    setCoordinate(11, 6, "/areas/eledhel/south-coast-one/11x6.c", "path");
    setCoordinate(10, 6, "/areas/eledhel/south-coast-one/10x6.c", "room");
    setCoordinate(10, 7, "/areas/eledhel/south-coast-one/10x7.c", "room");
    setCoordinate(11, 4, "/areas/eledhel/south-coast-one/11x4.c", "path");
    setCoordinate(10, 4, "/areas/eledhel/south-coast-one/10x4.c", "path");
    setCoordinate(10, 5, "/areas/eledhel/south-coast-one/10x5.c", "room");
}
