//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/region.c";

public void Setup()
{
    asManualRegion();
    setRegionName("Phaedra Headquarters");
    setRegionType("stone keep");
    setRegionLevel(4);
    setDimensions(5, 5);
    setEntryCoordinate(2, 4,
        "/areas/eledhel/northern-city/phaedra-headquarters/2x4.c",
        "north", "/areas/eledhel/northern-city/5x6.c");

    setCoordinate(2, 3,
        "/areas/eledhel/northern-city/phaedra-headquarters/2x3.c", "room");
    setCoordinate(1, 3,
        "/areas/eledhel/northern-city/phaedra-headquarters/1x3.c", "room");
    setCoordinate(2, 2,
        "/areas/eledhel/northern-city/phaedra-headquarters/2x2.c", "room");
    setCoordinate(1, 2,
        "/areas/eledhel/northern-city/phaedra-headquarters/1x2.c", "room");
    setCoordinate(3, 2,
        "/areas/eledhel/northern-city/phaedra-headquarters/3x2.c", "room");
    setCoordinate(2, 4,
        "/areas/eledhel/northern-city/phaedra-headquarters/2x4.c", "entry");
}
