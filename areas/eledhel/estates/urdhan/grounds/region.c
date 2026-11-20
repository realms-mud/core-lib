//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setRegionName("House Urdhan Manor");
    setRegionType("rural");
    setRegionLevel(2);
    setDimensions(5, 5);
    setSettlementChance(-1);
    setEntryCoordinate(0, 2,
        "/areas/eledhel/estates/urdhan/grounds/0x2.c", "south",
        "/areas/eledhel/southern-rural/2x6.c");

    setCoordinate(0, 2,
        "/areas/eledhel/estates/urdhan/grounds/0x2.c", "entry");
    setCoordinate(1, 2,
        "/areas/eledhel/estates/urdhan/grounds/1x2.c", "path");
    setCoordinate(2, 2,
        "/areas/eledhel/estates/urdhan/grounds/2x2.c", "room");
    setCoordinate(2, 1,
        "/areas/eledhel/estates/urdhan/grounds/2x1.c", "room");
    setCoordinate(3, 2,
        "/areas/eledhel/estates/urdhan/grounds/3x2.c", "room");
}
