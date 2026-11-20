//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/region.c";

public void Setup()
{
    asManualRegion();
    setRegionName("Eledhel Arena");
    setRegionType("stone keep");
    setRegionLevel(3);
    setDimensions(5, 5);
    setEntryCoordinate(4, 2,
        "/areas/eledhel/northern-city/arena/4x2.c",
        "west", "/areas/eledhel/northern-city/5x7.c");

    setCoordinate(4, 2,
        "/areas/eledhel/northern-city/arena/4x2.c", "entry");
    setCoordinate(4, 3,
        "/areas/eledhel/northern-city/arena/4x3.c", "room");
    setCoordinate(3, 3,
        "/areas/eledhel/northern-city/arena/3x3.c", "room");
    setCoordinate(3, 2,
        "/areas/eledhel/northern-city/arena/3x2.c", "room");
}
