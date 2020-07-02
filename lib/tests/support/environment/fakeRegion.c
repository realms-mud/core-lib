//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setRegionName("Fake Region");
    setRegionType("tol-dhurath");
    asManualRegion();
    setDimensions(1, 1);

    setCoordinate(0, 0,
        "/areas/tol-dhurath/temple-interior/7x3.c", "none");
}
