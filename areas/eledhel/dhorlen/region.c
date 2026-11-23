//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//*****************************************************************************
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setRegionName("Dhorlen ford and mill");
    setRegionType("rural");
    setRegionLevel(3);
    setDimensions(7, 5);
    setSettlementChance(-1);
    setEntryCoordinate(3, 1,
        "/areas/eledhel/dhorlen/3x1.c", "north",
        "/areas/eledhel/south-rural-route-07/22x2.c");

    setCoordinate(0, 2, "/areas/eledhel/dhorlen/0x2.c", "room");
    setCoordinate(1, 2, "/areas/eledhel/dhorlen/1x2.c", "path");
    setCoordinate(2, 2, "/areas/eledhel/dhorlen/2x2.c", "room");
    setCoordinate(3, 1, "/areas/eledhel/dhorlen/3x1.c", "entry");
    setCoordinate(3, 2, "/areas/eledhel/dhorlen/3x2.c", "room");
    setCoordinate(3, 3, "/areas/eledhel/dhorlen/3x3.c", "path");
    setCoordinate(3, 4, "/areas/eledhel/dhorlen/3x4.c", "path");
    setCoordinate(4, 2, "/areas/eledhel/dhorlen/4x2.c", "path");
    setCoordinate(4, 4, "/areas/eledhel/dhorlen/4x4.c", "room");
    setCoordinate(5, 2, "/areas/eledhel/dhorlen/5x2.c", "room");
}
