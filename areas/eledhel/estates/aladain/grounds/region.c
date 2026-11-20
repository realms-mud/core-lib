//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setRegionName("House Aladain and the village");
    setRegionType("rural");
    setRegionLevel(3);
    setDimensions(5, 5);
    setSettlementChance(-1);
    setEntryCoordinate(0, 2,
        "/areas/eledhel/estates/aladain/grounds/0x2.c", "north",
        "/areas/eledhel/central-rural/21x3.c");

    setCoordinate(0, 2,
        "/areas/eledhel/estates/aladain/grounds/0x2.c", "entry");
    setCoordinate(1, 2,
        "/areas/eledhel/estates/aladain/grounds/1x2.c", "path");
    setCoordinate(2, 2,
        "/areas/eledhel/estates/aladain/grounds/2x2.c", "room");
    setCoordinate(3, 2,
        "/areas/eledhel/estates/aladain/grounds/3x2.c", "room");
    setCoordinate(1, 3,
        "/areas/eledhel/estates/aladain/grounds/1x3.c", "room");
    setCoordinate(2, 3,
        "/areas/eledhel/estates/aladain/grounds/2x3.c", "room");
    setCoordinate(3, 3,
        "/areas/eledhel/estates/aladain/grounds/3x3.c", "path");
    setCoordinate(1, 4,
        "/areas/eledhel/estates/aladain/grounds/1x4.c", "room");
    setCoordinate(2, 4,
        "/areas/eledhel/estates/aladain/grounds/2x4.c", "path");
    setCoordinate(3, 4,
        "/areas/eledhel/estates/aladain/grounds/3x4.c", "entry");
    setCoordinate(4, 4,
        "/areas/eledhel/estates/aladain/grounds/4x4.c", "room");
    setCoordinate(1, 1,
        "/areas/eledhel/estates/aladain/grounds/1x1.c", "room");
    setCoordinate(2, 1,
        "/areas/eledhel/estates/aladain/grounds/2x1.c", "path");
    setCoordinate(3, 1,
        "/areas/eledhel/estates/aladain/grounds/3x1.c", "room");
}
