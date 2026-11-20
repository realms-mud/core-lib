//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setRegionName("Anor, east-coast harbor town");
    setRegionType("city");
    setRegionLevel(7);
    setDimensions(25, 10);
    setSettlementChance(-1);
    setEntryCoordinate(12, 0, "/areas/anor/12x0.c", "north",
        "/areas/eledhel/south-coast-two/12x9.c");

    setCoordinate(12, 0, "/areas/anor/12x0.c", "entry");
    setCoordinate(12, 1, "/areas/anor/12x1.c", "path");
    setCoordinate(12, 2, "/areas/anor/12x2.c", "path");
    setCoordinate(12, 3, "/areas/anor/12x3.c", "path");
    setCoordinate(12, 4, "/areas/anor/12x4.c", "path");
    setCoordinate(12, 5, "/areas/anor/12x5.c", "path");
    setCoordinate(12, 6, "/areas/anor/12x6.c", "path");
    setCoordinate(12, 7, "/areas/anor/12x7.c", "path");
    setCoordinate(12, 8, "/areas/anor/12x8.c", "path");
    setCoordinate(12, 9, "/areas/anor/12x9.c", "room");
    setCoordinate(11, 2, "/areas/anor/11x2.c", "path");
    setCoordinate(10, 2, "/areas/anor/10x2.c", "room");
    setCoordinate(10, 1, "/areas/anor/10x1.c", "room");
    setCoordinate(10, 3, "/areas/anor/10x3.c", "room");
    setCoordinate(11, 3, "/areas/anor/11x3.c", "path");
    setCoordinate(13, 6, "/areas/anor/13x6.c", "path");
    setCoordinate(14, 6, "/areas/anor/14x6.c", "room");
    setCoordinate(15, 6, "/areas/anor/15x6.c", "room");
    setCoordinate(15, 5, "/areas/anor/15x5.c", "room");
}
