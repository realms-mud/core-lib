//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setRegionName("Thuenach-home");
    setRegionType("wooden building");
    setDimensions(5, 5);

    setCoordinate(0, 3,
        "/lib/tutorial/eledhel/southern-city/thuenach/0x3.c", "room");
}
