//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/region.c";

public void Setup()
{
    asManualRegion();
    setRegionName("Eledhel Prison");
    setRegionType("stone keep");
    setRegionLevel(3);
    setDimensions(5, 5);
    setEntryCoordinate(0, 2,
        "/areas/eledhel/northern-city/prison/0x2.c",
        "east", "/areas/eledhel/northern-city/5x7.c");

    setCoordinate(0, 2,
        "/areas/eledhel/northern-city/prison/0x2.c", "entry");
    setCoordinate(1, 2,
        "/areas/eledhel/northern-city/prison/1x2.c", "room");
    setCoordinate(2, 2,
        "/areas/eledhel/northern-city/prison/2x2.c", "room");
    setCoordinate(3, 2,
        "/areas/eledhel/northern-city/prison/cell/0x0.c", "room");
    setCoordinate(2, 3,
        "/areas/eledhel/northern-city/prison/2x3.c", "room");
    setCoordinate(3, 3,
        "/areas/eledhel/northern-city/prison/3x3.c", "room");
}
