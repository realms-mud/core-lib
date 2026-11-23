//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setRegionName("Gundil Sea Village");
    setRegionType("rural");
    setRegionLevel(3);
    setDimensions(5, 5);
    setSettlementChance(-1);

    setCoordinate(0, 0,
        "/areas/northern-road/gundil-coast/gundil-village/0x0.c", "village");
    setCoordinate(0, 1,
        "/areas/northern-road/gundil-coast/gundil-village/0x1.c", "village");
    setEntryCoordinate(0, 2,
        "/areas/northern-road/gundil-coast/gundil-village/0x2.c", "west",
        "/areas/northern-road/gundil-coast/9x8.c");
    setCoordinate(0, 3,
        "/areas/northern-road/gundil-coast/gundil-village/0x3.c", "village");
    setCoordinate(0, 4,
        "/areas/northern-road/gundil-coast/gundil-village/0x4.c", "village");

    setCoordinate(1, 0,
        "/areas/northern-road/gundil-coast/gundil-village/1x0.c", "village");
    setCoordinate(1, 1,
        "/areas/northern-road/gundil-coast/gundil-village/1x1.c", "village");
    setCoordinate(1, 2,
        "/areas/northern-road/gundil-coast/gundil-village/1x2.c", "village");
    setCoordinate(1, 3,
        "/areas/northern-road/gundil-coast/gundil-village/1x3.c", "village");
    setCoordinate(1, 4,
        "/areas/northern-road/gundil-coast/gundil-village/1x4.c", "village");

    setCoordinate(2, 0,
        "/areas/northern-road/gundil-coast/gundil-village/2x0.c", "village");
    setCoordinate(2, 1,
        "/areas/northern-road/gundil-coast/gundil-village/2x1.c", "village");
    setCoordinate(2, 2,
        "/areas/northern-road/gundil-coast/gundil-village/2x2.c", "village");
    setCoordinate(2, 3,
        "/areas/northern-road/gundil-coast/gundil-village/2x3.c", "village");
    setCoordinate(2, 4,
        "/areas/northern-road/gundil-coast/gundil-village/2x4.c", "village");

    setCoordinate(3, 0,
        "/areas/northern-road/gundil-coast/gundil-village/3x0.c", "village");
    setCoordinate(3, 1,
        "/areas/northern-road/gundil-coast/gundil-village/3x1.c", "village");
    setCoordinate(3, 2,
        "/areas/northern-road/gundil-coast/gundil-village/3x2.c", "village");
    setCoordinate(3, 3,
        "/areas/northern-road/gundil-coast/gundil-village/3x3.c", "village");
    setCoordinate(3, 4,
        "/areas/northern-road/gundil-coast/gundil-village/3x4.c", "village");

    setCoordinate(4, 0,
        "/areas/northern-road/gundil-coast/gundil-village/4x0.c", "village");
    setCoordinate(4, 1,
        "/areas/northern-road/gundil-coast/gundil-village/4x1.c", "village");
    setCoordinate(4, 2,
        "/areas/northern-road/gundil-coast/gundil-village/4x2.c", "village");
    setCoordinate(4, 3,
        "/areas/northern-road/gundil-coast/gundil-village/4x3.c", "village");
    setCoordinate(4, 4,
        "/areas/northern-road/gundil-coast/gundil-village/4x4.c", "village");
}
