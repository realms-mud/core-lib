//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setRegionName("Minlach Commons and Old Workings");
    setRegionType("forest");
    setRegionLevel(3);
    setDimensions(5, 7);
    setSettlementChance(-1);
    setCoordinate(4, 1, "/areas/minlach/surrounding/4x1.c", "entry");
    setCoordinate(3, 1, "/areas/minlach/surrounding/3x1.c", "room");
    setCoordinate(2, 1, "/areas/minlach/surrounding/2x1.c", "room");
    setCoordinate(2, 0, "/areas/minlach/surrounding/2x0.c", "room");
    setCoordinate(2, 2, "/areas/minlach/surrounding/2x2.c", "room");
    setCoordinate(3, 2, "/areas/minlach/surrounding/3x2.c", "room");
    setCoordinate(3, 3, "/areas/minlach/surrounding/3x3.c", "path");
    setCoordinate(2, 3, "/areas/minlach/surrounding/2x3.c", "room");
    setCoordinate(4, 3, "/areas/minlach/surrounding/4x3.c", "room");
    setCoordinate(3, 4, "/areas/minlach/surrounding/3x4.c", "path");
    setCoordinate(2, 4, "/areas/minlach/surrounding/2x4.c", "path");
    setCoordinate(1, 4, "/areas/minlach/surrounding/1x4.c", "room");
    setCoordinate(0, 4, "/areas/minlach/surrounding/0x4.c", "room");
    setCoordinate(0, 3, "/areas/minlach/surrounding/0x3.c", "room");
    setCoordinate(0, 5, "/areas/minlach/surrounding/0x5.c", "room");
    setCoordinate(1, 5, "/areas/minlach/surrounding/1x5.c", "path");
    setCoordinate(2, 5, "/areas/minlach/surrounding/2x5.c", "room");
    setCoordinate(1, 6, "/areas/minlach/surrounding/1x6.c", "room");
    setCoordinate(0, 6, "/areas/minlach/surrounding/0x6.c", "room");
    setCoordinate(3, 5, "/areas/minlach/surrounding/3x5.c", "room");
    setCoordinate(4, 5, "/areas/minlach/surrounding/4x5.c", "room");
    setCoordinate(4, 6, "/areas/minlach/surrounding/4x6.c", "room");
    setCoordinate(3, 6, "/areas/minlach/surrounding/3x6.c", "room");
}
