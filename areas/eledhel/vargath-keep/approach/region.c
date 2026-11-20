//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setRegionName("Vargath's northwest approach");
    setRegionType("forest");
    setRegionLevel(8);
    setDimensions(5, 5);
    setSettlementChance(-1);
    setEntryCoordinate(0, 2,
        "/areas/eledhel/vargath-keep/approach/0x2.c", "west",
        "/areas/eledhel/north-road/0x2.c");

    setCoordinate(0, 2,
        "/areas/eledhel/vargath-keep/approach/0x2.c", "entry");
    setCoordinate(1, 2,
        "/areas/eledhel/vargath-keep/approach/1x2.c", "path");
    setCoordinate(2, 2,
        "/areas/eledhel/vargath-keep/approach/2x2.c", "path");
    setCoordinate(3, 2,
        "/areas/eledhel/vargath-keep/approach/3x2.c", "room");
    setCoordinate(4, 2,
        "/areas/eledhel/vargath-keep/approach/4x2.c", "exit");
    setCoordinate(2, 1,
        "/areas/eledhel/vargath-keep/approach/2x1.c", "room");
    setCoordinate(3, 1,
        "/areas/eledhel/vargath-keep/approach/3x1.c", "room");
}
