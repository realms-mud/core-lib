//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setRegionName("Minlach Headland and Cove");
    setRegionType("forest");
    setRegionLevel(3);
    setDimensions(5, 5);
    setSettlementChance(-1);
    setCoordinate(0, 0, "/areas/minlach/shore/0x0.c", "entry");
    setCoordinate(0, 1, "/areas/minlach/shore/0x1.c", "path");
    setCoordinate(0, 2, "/areas/minlach/shore/0x2.c", "room");
    setCoordinate(0, 3, "/areas/minlach/shore/0x3.c", "room");
    setCoordinate(1, 3, "/areas/minlach/shore/1x3.c", "room");
    setCoordinate(2, 3, "/areas/minlach/shore/2x3.c", "room");
    setCoordinate(2, 2, "/areas/minlach/shore/2x2.c", "room");
    setCoordinate(2, 1, "/areas/minlach/shore/2x1.c", "path");
    setCoordinate(2, 0, "/areas/minlach/shore/2x0.c", "entry");
}
