//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setRegionName("Eledhel-southern-wainwright");
    setRegionType("wooden building");
    setDimensions(5, 5);

    setCoordinate(0, 1,
        "/areas/eledhel/southern-city/wainwright/0x1.c", "room");
}
