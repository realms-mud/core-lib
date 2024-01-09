//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setRegionName("Eledhel-southern-swordsmith");
    setRegionType("limestone building");
    setDimensions(5, 5);

    setCoordinate(0, 0,
        "/areas/eledhel/southern-city/swordsmith/0x0.c", "shop");
    setCoordinate(0, 1,
        "/areas/eledhel/southern-city/swordsmith/0x1.c", "room");
    setCoordinate(0, 2,
        "/areas/eledhel/southern-city/swordsmith/0x2.c", "shop");

    setCoordinate(1, 0,
        "/areas/eledhel/southern-city/swordsmith/1x0.c", "room");
    setCoordinate(1, 1,
        "/areas/eledhel/southern-city/swordsmith/1x1.c", "room");
    setCoordinate(1, 2,
        "/areas/eledhel/southern-city/swordsmith/1x2.c", "room");

    setCoordinate(2, 0,
        "/areas/eledhel/southern-city/swordsmith/2x0.c", "room");
    setCoordinate(2, 1,
        "/areas/eledhel/southern-city/swordsmith/2x1.c", "room");
    setCoordinate(2, 2,
        "/areas/eledhel/southern-city/swordsmith/2x2.c", "room");
}
