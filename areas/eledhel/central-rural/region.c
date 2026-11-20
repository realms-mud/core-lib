//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setRegionName("West Gate and Farmlands");
    setRegionType("rural");
    setRegionLevel(3);
    setDimensions(25, 10);
    setSettlementChance(-1);

    setCoordinate(22, 5,
        "/areas/eledhel/central-rural/22x5.c", "path");
    setCoordinate(22, 6,
        "/areas/eledhel/central-rural/22x6.c", "room");
    setCoordinate(23, 5,
        "/areas/eledhel/central-rural/23x5.c", "path");
    setCoordinate(23, 6,
        "/areas/eledhel/central-rural/23x6.c", "room");
    setCoordinate(24, 6,
        "/areas/eledhel/central-rural/24x6.c", "room");
    setCoordinate(24, 7,
        "/areas/eledhel/central-rural/24x7.c", "room");
    setCoordinate(24, 5,
        "/areas/eledhel/central-rural/24x5.c", "entry");
    setCoordinate(23, 4, "/areas/eledhel/central-rural/23x4.c", "path");
    setCoordinate(23, 3, "/areas/eledhel/central-rural/23x3.c", "room");
    setCoordinate(23, 2, "/areas/eledhel/central-rural/23x2.c", "room");
    setCoordinate(22, 4, "/areas/eledhel/central-rural/22x4.c", "room");
    setCoordinate(22, 3, "/areas/eledhel/central-rural/22x3.c", "room");
    setCoordinate(21, 4, "/areas/eledhel/central-rural/21x4.c", "room");
    setCoordinate(20, 4, "/areas/eledhel/central-rural/20x4.c", "room");
    setCoordinate(21, 3, "/areas/eledhel/central-rural/21x3.c", "room");
    setCoordinate(21, 5, "/areas/eledhel/central-rural/21x5.c", "path");
    setCoordinate(20, 5, "/areas/eledhel/central-rural/20x5.c", "room");
    setCoordinate(21, 6, "/areas/eledhel/central-rural/21x6.c", "path");
    setCoordinate(21, 7, "/areas/eledhel/central-rural/21x7.c", "path");
    setCoordinate(22, 7, "/areas/eledhel/central-rural/22x7.c", "room");
    setCoordinate(23, 7, "/areas/eledhel/central-rural/23x7.c", "room");
    setCoordinate(21, 8, "/areas/eledhel/central-rural/21x8.c", "path");
    setCoordinate(22, 8, "/areas/eledhel/central-rural/22x8.c", "room");
    setCoordinate(23, 8, "/areas/eledhel/central-rural/23x8.c", "room");
    setCoordinate(21, 9, "/areas/eledhel/central-rural/21x9.c", "room");
}
