//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/region.c";

public void Setup()
{
    setRegionName("House Hadrath Keep Grounds");
    setRegionType("rural");
    setRegionLevel(4);
    setDimensions(5, 5);
    setSettlementChance(-1);
    setEntryCoordinate(0, 2,
        "/areas/eledhel/hadrath/grounds/0x2.c", "west",
        "/areas/eledhel/hadrath/watchlands/19x5.c");
    setCoordinate(1, 2, "/areas/eledhel/hadrath/grounds/1x2.c", "path");
    setCoordinate(2, 2, "/areas/eledhel/hadrath/grounds/2x2.c", "room");
    setCoordinate(3, 2, "/areas/eledhel/hadrath/grounds/3x2.c", "room");
    setCoordinate(1, 1, "/areas/eledhel/hadrath/grounds/1x1.c", "room");
    setCoordinate(2, 1, "/areas/eledhel/hadrath/grounds/2x1.c", "entry");
    setCoordinate(2, 3, "/areas/eledhel/hadrath/grounds/2x3.c", "room");
    setCoordinate(3, 1, "/areas/eledhel/hadrath/grounds/3x1.c", "room");
}
