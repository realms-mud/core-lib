//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setRegionName("The Common Measure");
    setRegionType("wooden building");
    setDimensions(5, 5);
    setEntryCoordinate(2, 2,
        "/areas/eledhel/central-rural/common-measure/0x1.c", "west",
        "/areas/eledhel/central-rural/24x6.c");

    setCoordinate(2, 1,
        "/areas/eledhel/central-rural/common-measure/0x0.c", "room");
    setCoordinate(3, 2,
        "/areas/eledhel/central-rural/common-measure/1x1.c", "room");
    setCoordinate(3, 1,
        "/areas/eledhel/central-rural/common-measure/1x0.c", "room");
}
