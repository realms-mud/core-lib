//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setRegionName("Tirwen's orchard farms");
    setRegionType("rural");
    setRegionLevel(3);
    setDimensions(7, 5);
    setSettlementChance(-1);
    setEntryCoordinate(3, 1,
        "/areas/eledhel/tirwen/3x1.c", "south",
        "/areas/eledhel/south-rural-route-05/20x2.c");

    setCoordinate(0, 1, "/areas/eledhel/tirwen/0x1.c", "room");
    setCoordinate(1, 0, "/areas/eledhel/tirwen/1x0.c", "room");
    setCoordinate(1, 1, "/areas/eledhel/tirwen/1x1.c", "path");
    setCoordinate(2, 1, "/areas/eledhel/tirwen/2x1.c", "path");
    setCoordinate(3, 1, "/areas/eledhel/tirwen/3x1.c", "entry");
    setCoordinate(4, 1, "/areas/eledhel/tirwen/4x1.c", "path");
    setCoordinate(4, 2, "/areas/eledhel/tirwen/4x2.c", "room");
    setCoordinate(5, 1, "/areas/eledhel/tirwen/5x1.c", "path");
    setCoordinate(6, 1, "/areas/eledhel/tirwen/6x1.c", "room");
}
