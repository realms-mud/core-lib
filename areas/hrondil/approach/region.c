//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setRegionName("Hrondil Limestone Approach");
    setRegionType("rural");
    setRegionLevel(4);
    setSettlementChance(-1);
    setDimensions(5, 9);

    setEntryCoordinate(0, 0,
        "/areas/hrondil/approach/0x0.c", "south",
        "/areas/northern-road/hrondil-approaches/12x4.c");
    setCoordinate(0, 1, "/areas/hrondil/approach/0x1.c", "approach");
    setCoordinate(0, 2, "/areas/hrondil/approach/0x2.c", "approach");
    setCoordinate(0, 3, "/areas/hrondil/approach/0x3.c", "approach");
    setCoordinate(0, 4, "/areas/hrondil/approach/0x4.c", "approach");
    setCoordinate(0, 5, "/areas/hrondil/approach/0x5.c", "approach");
    setCoordinate(0, 6, "/areas/hrondil/approach/0x6.c", "approach");
    setCoordinate(0, 7, "/areas/hrondil/approach/0x7.c", "approach");
    setCoordinate(0, 8, "/areas/hrondil/approach/0x8.c", "approach");
}
