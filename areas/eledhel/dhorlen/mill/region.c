//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//*****************************************************************************
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setRegionName("Dhorlen water mill");
    setRegionType("rural");
    setRegionLevel(3);
    setDimensions(5, 5);
    setEntryCoordinate(0, 1,
        "/areas/eledhel/dhorlen/mill/0x1.c", "south",
        "/areas/eledhel/dhorlen/2x2.c");

    setCoordinate(0, 0,
        "/areas/eledhel/dhorlen/mill/0x0.c", "room");
    setCoordinate(0, 1,
        "/areas/eledhel/dhorlen/mill/0x1.c", "entry");
}
