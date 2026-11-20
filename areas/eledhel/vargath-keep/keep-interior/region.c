//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setRegionName("Vargath's Keep");
    setRegionType("stone keep");
    setRegionLevel(8);
    setDimensions(5, 5);
    setSettlementChance(-1);
    setEntryCoordinate(0, 2,
        "/areas/eledhel/vargath-keep/keep-interior/0x2.c", "west",
        "/areas/eledhel/vargath-keep/canyon/4x2.c");

    setCoordinate(0, 2,
        "/areas/eledhel/vargath-keep/keep-interior/0x2.c", "entry");
    setCoordinate(1, 2,
        "/areas/eledhel/vargath-keep/keep-interior/1x2.c", "path");
    setCoordinate(2, 2,
        "/areas/eledhel/vargath-keep/keep-interior/2x2.c", "room");
    setCoordinate(3, 2,
        "/areas/eledhel/vargath-keep/keep-interior/3x2.c", "room");
    setCoordinate(4, 2,
        "/areas/eledhel/vargath-keep/keep-interior/4x2.c", "room");
    setCoordinate(1, 1,
        "/areas/eledhel/vargath-keep/keep-interior/1x1.c", "room");
    setCoordinate(2, 1,
        "/areas/eledhel/vargath-keep/keep-interior/2x1.c", "room");
    setCoordinate(3, 1,
        "/areas/eledhel/vargath-keep/keep-interior/3x1.c", "room");
    setCoordinate(4, 1,
        "/areas/eledhel/vargath-keep/keep-interior/4x1.c", "room");
    setCoordinate(1, 3,
        "/areas/eledhel/vargath-keep/keep-interior/1x3.c", "room");
    setCoordinate(2, 3,
        "/areas/eledhel/vargath-keep/keep-interior/2x3.c", "room");
    setCoordinate(3, 3,
        "/areas/eledhel/vargath-keep/keep-interior/3x3.c", "room");
    setCoordinate(4, 3,
        "/areas/eledhel/vargath-keep/keep-interior/4x3.c", "room");
}
