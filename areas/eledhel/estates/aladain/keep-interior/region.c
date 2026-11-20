//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setRegionName("House Aladain Keep");
    setRegionType("stone keep");
    setRegionLevel(3);
    setDimensions(5, 5);
    setEntryCoordinate(2, 0,
        "/areas/eledhel/estates/aladain/keep-interior/2x0.c", "south",
        "/areas/eledhel/estates/aladain/grounds/3x4.c");

    setCoordinate(2, 0,
        "/areas/eledhel/estates/aladain/keep-interior/2x0.c", "entry");
    setCoordinate(2, 1,
        "/areas/eledhel/estates/aladain/keep-interior/2x1.c", "room");
    setCoordinate(1, 1,
        "/areas/eledhel/estates/aladain/keep-interior/1x1.c", "room");
    setCoordinate(2, 2,
        "/areas/eledhel/estates/aladain/keep-interior/2x2.c", "room");
    setCoordinate(3, 2,
        "/areas/eledhel/estates/aladain/keep-interior/3x2.c", "room");
}
