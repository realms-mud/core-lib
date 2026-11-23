//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setRegionName("Erator Farm and Keep Grounds");
    setRegionType("rural");
    setRegionLevel(2);
    asManualRegion();
    setDimensions(3, 3);
    setSettlementChance(-1);

    setEntryCoordinate(0, 0,
        "/areas/eledhel/estates/erator/grounds/0x0.c", "north",
        "/areas/northern-road/north-gate/9x9.c");
    setCoordinate(0, 1,
        "/areas/eledhel/estates/erator/grounds/0x1.c", "room");
    setCoordinate(0, 2,
        "/areas/eledhel/estates/erator/grounds/0x2.c", "room");

    setCoordinate(1, 0,
        "/areas/eledhel/estates/erator/grounds/1x0.c", "room");
    setCoordinate(1, 1,
        "/areas/eledhel/estates/erator/grounds/1x1.c", "room");
    setCoordinate(1, 2,
        "/areas/eledhel/estates/erator/grounds/1x2.c", "room");

    setCoordinate(2, 0,
        "/areas/eledhel/estates/erator/grounds/2x0.c", "room");
    setCoordinate(2, 1,
        "/areas/eledhel/estates/erator/grounds/2x1.c", "room");
    setCoordinate(2, 2,
        "/areas/eledhel/estates/erator/grounds/2x2.c", "room");
}
