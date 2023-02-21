//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setRegionName("church-of-ilyrth");
    setRegionType("wooden building");
    setDimensions(5, 5);

    setCoordinate(0, 3,
        "/areas/eledhel/southern-city/church-of-ilyrth/0x3.c", "room");
}
