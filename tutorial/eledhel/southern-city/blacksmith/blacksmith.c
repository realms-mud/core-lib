//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setRegionName("Eledhel-southern-blacksmith");
    setRegionType("limestone building");
    setDimensions(5, 5);

    setCoordinate(0, 0,
        "/lib/tutorial/eledhel/southern-city/blacksmith/0x0.c", "shop");
    setCoordinate(0, 1,
        "/lib/tutorial/eledhel/southern-city/blacksmith/0x1.c", "room");
    setCoordinate(0, 2,
        "/lib/tutorial/eledhel/southern-city/blacksmith/0x0.c", "shop");

    setCoordinate(1, 0,
        "/lib/tutorial/eledhel/southern-city/blacksmith/0x0.c", "room");
    setCoordinate(1, 1,
        "/lib/tutorial/eledhel/southern-city/blacksmith/0x0.c", "room");
    setCoordinate(1, 2,
        "/lib/tutorial/eledhel/southern-city/blacksmith/0x0.c", "room");

    setCoordinate(2, 0,
        "/lib/tutorial/eledhel/southern-city/blacksmith/0x0.c", "room");
    setCoordinate(2, 1,
        "/lib/tutorial/eledhel/southern-city/blacksmith/0x0.c", "room");
    setCoordinate(2, 2,
        "/lib/tutorial/eledhel/southern-city/blacksmith/0x0.c", "room");
}
