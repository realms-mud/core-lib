//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setRegionName("Minlach");
    setRegionType("city");
    setRegionLevel(5);
    setDimensions(5, 5);
    setSettlementChance(-1);

    setCoordinate(0, 1, "/areas/minlach/0x1.c", "room");
    setCoordinate(0, 2, "/areas/minlach/0x2.c", "room");
    setCoordinate(1, 0, "/areas/minlach/1x0.c", "entry");
    setCoordinate(1, 1, "/areas/minlach/1x1.c", "path");
    setCoordinate(1, 2, "/areas/minlach/1x2.c", "room");
    setCoordinate(2, 1, "/areas/minlach/2x1.c", "room");
    setCoordinate(2, 2, "/areas/minlach/2x2.c", "room");
    setCoordinate(0, 3, "/areas/minlach/0x3.c", "room");
    setCoordinate(0, 4, "/areas/minlach/0x4.c", "room");
    setCoordinate(1, 3, "/areas/minlach/1x3.c", "room");
    setCoordinate(1, 4, "/areas/minlach/1x4.c", "room");
    setCoordinate(2, 3, "/areas/minlach/2x3.c", "room");
    setCoordinate(2, 4, "/areas/minlach/2x4.c", "room");
    setCoordinate(3, 2, "/areas/minlach/3x2.c", "room");
    setCoordinate(3, 3, "/areas/minlach/3x3.c", "room");
    setCoordinate(3, 4, "/areas/minlach/3x4.c", "room");
}
