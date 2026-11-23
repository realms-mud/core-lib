//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/region.c";

public void Setup()
{
    setRegionName("Belathon Keep");
    setRegionType("keep");
    setRegionLevel(3);
    setSettlementChance(-1);
    asManualRegion();
    setDimensions(3, 1);

    setEntryCoordinate(0, 0,
        "/areas/eledhel/estates/belathon/keep-interior/0x0.c", "west",
        "/areas/eledhel/estates/belathon/grounds/2x1.c");
    setCoordinate(1, 0,
        "/areas/eledhel/estates/belathon/keep-interior/1x0.c", "room");
    setCoordinate(2, 0,
        "/areas/eledhel/estates/belathon/keep-interior/2x0.c", "room");
}
