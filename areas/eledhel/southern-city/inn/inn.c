//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setRegionName("Eledhel-southern-inn");
    setRegionType("wooden building");
    setDimensions(5, 5);

    setCoordinate(0, 1,
        "/areas/eledhel/southern-city/inn/0x1.c", "room");
}
