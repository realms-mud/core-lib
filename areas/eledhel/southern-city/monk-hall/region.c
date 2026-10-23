//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setRegionName("Eledhel Monastic Training Hall");
    setRegionType("city");
    setDimensions(5, 5);
    setCoordinate(0, 0,
        "/areas/eledhel/southern-city/monk-hall/0x0.c", "none");
}
