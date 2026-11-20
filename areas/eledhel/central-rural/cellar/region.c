//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setRegionName("The Old Root Cellar");
    setRegionType("ruins");
    setRegionLevel(2);
    setDimensions(5, 5);
    setEntryCoordinate(2, 2,
        "/areas/eledhel/central-rural/cellar/2x2.c", "west",
        "/areas/eledhel/central-rural/23x8.c");

    setCoordinate(1, 1,
        "/areas/eledhel/central-rural/cellar/1x1.c", "room");
    setCoordinate(2, 1,
        "/areas/eledhel/central-rural/cellar/2x1.c", "room");
    setCoordinate(3, 1,
        "/areas/eledhel/central-rural/cellar/3x1.c", "room");
    setCoordinate(3, 2,
        "/areas/eledhel/central-rural/cellar/3x2.c", "room");
}
