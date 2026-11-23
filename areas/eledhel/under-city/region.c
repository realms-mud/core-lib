//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setRegionName("The Secret Ways of Eledhel");
    setRegionType("cave");
    asManualRegion();
    setDimensions(25, 9);

    setEntryCoordinate(0, 0,
        "/areas/eledhel/under-city/trunk/0x0.c", "up",
        "/areas/eledhel/central-city/palace/hidden-passage.c");

    for (int index = 1; index <= 100; index++)
    {
        int x = index % 25;
        int y = index / 25;
        if (y % 2)
        {
            x = 24 - x;
        }
        setCoordinate(x, y, sprintf(
            "/areas/eledhel/under-city/trunk/%dx0.c", index), "none");
    }

    setCoordinate(0, 5,
        "/areas/eledhel/under-city/phaedra-landing/0x0.c", "none");
    setCoordinate(1, 5,
        "/areas/eledhel/under-city/phaedra-mechanism/0x0.c", "none");
    setCoordinate(2, 5, "/areas/eledhel/under-city/phaedra-branch/0x0.c",
        "none");
    setCoordinate(3, 5, "/areas/eledhel/under-city/library-branch/0x0.c",
        "none");
    setCoordinate(4, 5, "/areas/eledhel/under-city/museum-branch/0x0.c",
        "none");
    setCoordinate(5, 5, "/areas/eledhel/under-city/aegis-branch/0x0.c",
        "none");
    setCoordinate(6, 5, "/areas/eledhel/under-city/werric-branch/0x0.c",
        "none");
    setCoordinate(7, 5, "/areas/eledhel/under-city/naval-branch/0x0.c",
        "none");
    setCoordinate(8, 5,
        "/areas/eledhel/under-city/justice-mechanism/0x0.c", "none");
    setCoordinate(9, 5, "/areas/eledhel/under-city/justice-branch/0x0.c",
        "none");

    for (int station = 0; station < 10; station++)
    {
        setCoordinate(station + 10, 5, sprintf(
            "/areas/eledhel/under-city/stations/%dx0.c", station), "none");
    }

    for (int caveRoom = 0; caveRoom < 42; caveRoom++)
    {
        int x = (caveRoom < 25) ? caveRoom : 49 - caveRoom;
        int y = (caveRoom < 25) ? 7 : 8;
        setCoordinate(x, y, sprintf(
            "/areas/eledhel/under-city/fox-route/%dx0.c", caveRoom),
            "none");
    }
}
