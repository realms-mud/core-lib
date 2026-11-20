//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setRegionName("Vargath's limestone approach");
    setRegionType("cave");
    setRegionLevel(8);
    setDimensions(5, 5);
    setSettlementChance(-1);
    setEntryCoordinate(0, 0,
        "/areas/eledhel/vargath-keep/limestone-caves/0x0.c", "up",
        "/areas/eledhel/vargath-keep/approach/4x2.c");

    setCoordinate(0, 0,
        "/areas/eledhel/vargath-keep/limestone-caves/0x0.c", "entry");
    setCoordinate(1, 0,
        "/areas/eledhel/vargath-keep/limestone-caves/1x0.c", "path");
    setCoordinate(1, 1,
        "/areas/eledhel/vargath-keep/limestone-caves/1x1.c", "path");
    setCoordinate(2, 1,
        "/areas/eledhel/vargath-keep/limestone-caves/2x1.c", "path");
    setCoordinate(2, 2,
        "/areas/eledhel/vargath-keep/limestone-caves/2x2.c", "room");
    setCoordinate(3, 2,
        "/areas/eledhel/vargath-keep/limestone-caves/3x2.c", "path");
    setCoordinate(3, 3,
        "/areas/eledhel/vargath-keep/limestone-caves/3x3.c", "path");
    setCoordinate(4, 3,
        "/areas/eledhel/vargath-keep/limestone-caves/4x3.c", "room");
    setCoordinate(4, 2,
        "/areas/eledhel/vargath-keep/limestone-caves/4x2.c", "exit");
}
