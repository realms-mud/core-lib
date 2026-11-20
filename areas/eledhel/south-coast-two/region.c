//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setRegionName("southern headlands");
    setRegionType("hilly rural");
    setRegionLevel(6);
    setDimensions(25, 10);
    setEntryCoordinate(12, 0,
        "/areas/eledhel/south-coast-two/12x0.c", "north",
        "/areas/eledhel/south-coast-one/12x9.c");

    setCoordinate(12, 0, "/areas/eledhel/south-coast-two/12x0.c", "entry");
    setCoordinate(12, 1, "/areas/eledhel/south-coast-two/12x1.c", "path");
    setCoordinate(12, 2, "/areas/eledhel/south-coast-two/12x2.c", "path");
    setCoordinate(12, 3, "/areas/eledhel/south-coast-two/12x3.c", "path");
    setCoordinate(12, 4, "/areas/eledhel/south-coast-two/12x4.c", "path");
    setCoordinate(12, 5, "/areas/eledhel/south-coast-two/12x5.c", "path");
    setCoordinate(12, 6, "/areas/eledhel/south-coast-two/12x6.c", "path");
    setCoordinate(12, 7, "/areas/eledhel/south-coast-two/12x7.c", "path");
    setCoordinate(12, 8, "/areas/eledhel/south-coast-two/12x8.c", "path");
    setCoordinate(12, 9, "/areas/eledhel/south-coast-two/12x9.c", "exit");
    setCoordinate(13, 3, "/areas/eledhel/south-coast-two/13x3.c", "path");
    setCoordinate(14, 3, "/areas/eledhel/south-coast-two/14x3.c", "path");
    setCoordinate(15, 3, "/areas/eledhel/south-coast-two/15x3.c", "path");
    setCoordinate(14, 2, "/areas/eledhel/south-coast-two/14x2.c", "path");
    setCoordinate(15, 2, "/areas/eledhel/south-coast-two/15x2.c", "room");
    setCoordinate(16, 3, "/areas/eledhel/south-coast-two/16x3.c", "path");
    setCoordinate(17, 3, "/areas/eledhel/south-coast-two/17x3.c", "path");
    setCoordinate(18, 3, "/areas/eledhel/south-coast-two/18x3.c", "room");
    setCoordinate(13, 6, "/areas/eledhel/south-coast-two/13x6.c", "path");
    setCoordinate(14, 6, "/areas/eledhel/south-coast-two/14x6.c", "path");
    setCoordinate(14, 5, "/areas/eledhel/south-coast-two/14x5.c", "path");
    setCoordinate(15, 5, "/areas/eledhel/south-coast-two/15x5.c", "room");
}
