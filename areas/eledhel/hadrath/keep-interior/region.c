//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/region.c";

public void Setup()
{
    setRegionName("House Hadrath Keep");
    setRegionType("stone keep");
    setRegionLevel(4);
    setDimensions(5, 5);
    setEntryCoordinate(2, 0,
        "/areas/eledhel/hadrath/keep-interior/2x0.c", "south",
        "/areas/eledhel/hadrath/grounds/2x1.c");
    setCoordinate(2, 1,
        "/areas/eledhel/hadrath/keep-interior/2x1.c", "path");
    setCoordinate(1, 1,
        "/areas/eledhel/hadrath/keep-interior/1x1.c", "room");
    setCoordinate(3, 1,
        "/areas/eledhel/hadrath/keep-interior/3x1.c", "room");
    setCoordinate(2, 2,
        "/areas/eledhel/hadrath/keep-interior/2x2.c", "room");
    setCoordinate(1, 2,
        "/areas/eledhel/hadrath/keep-interior/1x2.c", "room");
    setCoordinate(3, 2,
        "/areas/eledhel/hadrath/keep-interior/3x2.c", "room");
    setCoordinate(2, 3,
        "/areas/eledhel/hadrath/keep-interior/2x3.c", "room");
}
