//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setRegionName("Celedrath Estate");
    setRegionType("rural");
    setRegionLevel(2);
    setDimensions(5, 5);
    setSettlementChance(-1);
    setEntryCoordinate(0, 2,
        "/areas/eledhel/estates/celedrath/grounds/0x2.c", "east",
        "/areas/eledhel/southwest-rural-three/20x3.c");

    setCoordinate(0, 2,
        "/areas/eledhel/estates/celedrath/grounds/0x2.c", "entry");
    setCoordinate(1, 2,
        "/areas/eledhel/estates/celedrath/grounds/1x2.c", "path");
    setCoordinate(2, 2,
        "/areas/eledhel/estates/celedrath/grounds/2x2.c", "entry");
    setCoordinate(1, 1,
        "/areas/eledhel/estates/celedrath/grounds/1x1.c", "room");
    setCoordinate(3, 2,
        "/areas/eledhel/estates/celedrath/grounds/3x2.c", "room");
}
