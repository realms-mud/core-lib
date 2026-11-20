//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setRegionName("Johan's smithy");
    setRegionType("wooden building");
    setRegionLevel(1);
    setSettlementChance(-1);
    asManualRegion();
    setDimensions(3, 3);
    setEntryCoordinate(0, 1, "/areas/linwaeth/smithy/0x1.c", "west",
        "/areas/linwaeth/13x3.c");

    setCoordinate(0, 1, "/areas/linwaeth/smithy/0x1.c", "entry");
}
