//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setRegionName("Northern road from Eledhel");
    setRegionType("forest");
    setRegionLevel(8);
    setDimensions(5, 5);
    setSettlementChance(-1);

    setCoordinate(2, 0, "/areas/eledhel/north-road/2x0.c", "entry");
    setCoordinate(2, 1, "/areas/eledhel/north-road/2x1.c", "path");
    setCoordinate(2, 2, "/areas/eledhel/north-road/2x2.c", "room");
    setCoordinate(1, 2, "/areas/eledhel/north-road/1x2.c", "path");
    setCoordinate(0, 2, "/areas/eledhel/north-road/0x2.c", "path");
    setCoordinate(2, 3, "/areas/eledhel/north-road/2x3.c", "path");
    setCoordinate(2, 4, "/areas/eledhel/north-road/2x4.c", "exit");
}
