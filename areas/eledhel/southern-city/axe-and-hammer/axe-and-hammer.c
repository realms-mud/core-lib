//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setRegionName("Eledhel-southern-axe-and-hammer");
    setRegionType("limestone building");
    setDimensions(5, 5);

    setCoordinate(0, 1,
        "/areas/eledhel/southern-city/axe-and-hammer/0x1.c", "room");
}
