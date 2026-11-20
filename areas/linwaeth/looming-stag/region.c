//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setRegionName("The Looming Stag");
    setRegionType("brick building");
    setRegionLevel(1);
    setSettlementChance(-1);
    asManualRegion();
    setDimensions(3, 3);
    setEntryCoordinate(2, 1,
        "/areas/linwaeth/looming-stag/2x1.c", "east",
        "/areas/linwaeth/11x3.c");

    setCoordinate(0, 1, "/areas/linwaeth/looming-stag/0x1.c", "room");
    setCoordinate(1, 1, "/areas/linwaeth/looming-stag/1x1.c", "room");
    setCoordinate(2, 1, "/areas/linwaeth/looming-stag/2x1.c", "entry");
    setCoordinate(1, 2, "/areas/linwaeth/looming-stag/1x2.c", "room");
}
