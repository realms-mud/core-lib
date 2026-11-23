//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setRegionName("Belathon Coastal Approach");
    setRegionType("rural");
    setRegionLevel(3);
    setSettlementChance(-1);
    asManualRegion();
    setDimensions(1, 9);

    setEntryCoordinate(0, 0,
        "/areas/eledhel/estates/belathon/approach/0x0.c",
        "south", "/areas/northern-road/belathon-eolach/23x8.c");
    setCoordinate(0, 1,
        "/areas/eledhel/estates/belathon/approach/0x1.c", "road");
    setCoordinate(0, 2,
        "/areas/eledhel/estates/belathon/approach/0x2.c", "road");
    setCoordinate(0, 3,
        "/areas/eledhel/estates/belathon/approach/0x3.c", "road");
    setCoordinate(0, 4,
        "/areas/eledhel/estates/belathon/approach/0x4.c", "road");
    setCoordinate(0, 5,
        "/areas/eledhel/estates/belathon/approach/0x5.c", "road");
    setCoordinate(0, 6,
        "/areas/eledhel/estates/belathon/approach/0x6.c", "road");
    setCoordinate(0, 7,
        "/areas/eledhel/estates/belathon/approach/0x7.c", "road");
    setCoordinate(0, 8,
        "/areas/eledhel/estates/belathon/approach/0x8.c", "road");
}
