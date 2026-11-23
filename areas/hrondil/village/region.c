//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setRegionName("Hrondil Village");
    setRegionType("rural");
    setRegionLevel(3);
    setSettlementChance(-1);
    asManualRegion();
    setDimensions(3, 3);

    setEntryCoordinate(0, 0, "/areas/hrondil/village/0x0.c",
        "south", "/areas/hrondil/grounds/1x2.c");
    setCoordinate(0, 1, "/areas/hrondil/village/0x1.c", "village");
    setCoordinate(0, 2, "/areas/hrondil/village/0x2.c", "village");

    setCoordinate(1, 0, "/areas/hrondil/village/1x0.c", "village");
    setCoordinate(1, 1, "/areas/hrondil/village/1x1.c", "village");
    setCoordinate(1, 2, "/areas/hrondil/village/1x2.c", "village");

    setCoordinate(2, 0, "/areas/hrondil/village/2x0.c", "village");
    setCoordinate(2, 1, "/areas/hrondil/village/2x1.c", "village");
    setCoordinate(2, 2, "/areas/hrondil/village/2x2.c", "village");
}
