//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setRegionName("Linwaeth and the southern road");
    setRegionType("city");
    setRegionLevel(4);
    setDimensions(25, 10);
    setSettlementChance(-1);
    setEntryCoordinate(12, 0, "/areas/linwaeth/12x0.c", "north",
        "/areas/eledhel/south-rural-route-17/21x2.c");

    setCoordinate(12, 0, "/areas/linwaeth/12x0.c", "entry");
    setCoordinate(12, 1, "/areas/linwaeth/12x1.c", "path");
    setCoordinate(12, 2, "/areas/linwaeth/12x2.c", "path");
    setCoordinate(11, 2, "/areas/linwaeth/11x2.c", "path");
    setCoordinate(13, 2, "/areas/linwaeth/13x2.c", "path");
    setCoordinate(12, 3, "/areas/linwaeth/12x3.c", "room");
    setCoordinate(11, 3, "/areas/linwaeth/11x3.c", "room");
    setCoordinate(13, 3, "/areas/linwaeth/13x3.c", "room");
    setCoordinate(11, 4, "/areas/linwaeth/11x4.c", "room");
    setCoordinate(12, 4, "/areas/linwaeth/12x4.c", "room");
    setCoordinate(13, 4, "/areas/linwaeth/13x4.c", "room");
    setCoordinate(11, 5, "/areas/linwaeth/11x5.c", "room");
    setCoordinate(12, 5, "/areas/linwaeth/12x5.c", "path");
    setCoordinate(13, 5, "/areas/linwaeth/13x5.c", "room");
    setCoordinate(12, 6, "/areas/linwaeth/12x6.c", "path");
    setCoordinate(11, 6, "/areas/linwaeth/11x6.c", "room");
    setCoordinate(13, 6, "/areas/linwaeth/13x6.c", "room");
    setCoordinate(12, 7, "/areas/linwaeth/12x7.c", "path");
    setCoordinate(11, 7, "/areas/linwaeth/11x7.c", "path");
    setCoordinate(13, 7, "/areas/linwaeth/13x7.c", "path");
    setCoordinate(10, 8, "/areas/linwaeth/10x8.c", "room");
    setCoordinate(14, 8, "/areas/linwaeth/14x8.c", "room");
    setCoordinate(14, 7, "/areas/linwaeth/14x7.c", "path");
    setCoordinate(12, 8, "/areas/linwaeth/12x8.c", "path");
    setCoordinate(11, 8, "/areas/linwaeth/11x8.c", "room");
    setCoordinate(12, 9, "/areas/linwaeth/12x9.c", "exit");
}
