//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setRegionName("Belathon Outer Ward");
    setRegionType("rural");
    setRegionLevel(3);
    setSettlementChance(-1);
    asManualRegion();
    setDimensions(3, 3);

    setEntryCoordinate(0, 0,
        "/areas/eledhel/estates/belathon/grounds/0x0.c",
        "west", "/areas/eledhel/estates/belathon/approach/0x8.c");
    setCoordinate(0, 1,
        "/areas/eledhel/estates/belathon/grounds/0x1.c", "grounds");
    setCoordinate(0, 2,
        "/areas/eledhel/estates/belathon/grounds/0x2.c", "grounds");

    setCoordinate(1, 0,
        "/areas/eledhel/estates/belathon/grounds/1x0.c", "grounds");
    setCoordinate(1, 1,
        "/areas/eledhel/estates/belathon/grounds/1x1.c", "grounds");
    setCoordinate(1, 2,
        "/areas/eledhel/estates/belathon/grounds/1x2.c", "grounds");

    setCoordinate(2, 0,
        "/areas/eledhel/estates/belathon/grounds/2x0.c", "grounds");
    setCoordinate(2, 1,
        "/areas/eledhel/estates/belathon/grounds/2x1.c", "grounds");
    setCoordinate(2, 2,
        "/areas/eledhel/estates/belathon/grounds/2x2.c", "grounds");
}
