//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setRegionName("Oeldhen Manor Interior");
    setRegionType("stone keep");
    setRegionLevel(2);
    setDimensions(5, 5);
    setEntryCoordinate(2, 0,
        "/areas/eledhel/estates/oeldhen/manor-interior/2x0.c", "south",
        "/areas/eledhel/estates/oeldhen/grounds/2x2.c");

    setCoordinate(2, 0,
        "/areas/eledhel/estates/oeldhen/manor-interior/2x0.c", "entry");
    setCoordinate(2, 1,
        "/areas/eledhel/estates/oeldhen/manor-interior/2x1.c", "path");
    setCoordinate(1, 1,
        "/areas/eledhel/estates/oeldhen/manor-interior/1x1.c", "room");
    setCoordinate(3, 1,
        "/areas/eledhel/estates/oeldhen/manor-interior/3x1.c", "room");
    setCoordinate(2, 2,
        "/areas/eledhel/estates/oeldhen/manor-interior/2x2.c", "room");
}
