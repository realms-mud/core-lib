//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/region.c";

public void Setup()
{
    setRegionName("Hadrath Watch Country");
    setRegionType("rural");
    setRegionLevel(4);
    setDimensions(20, 10);
    setSettlementChance(-1);

    for (int x = 0; x < 20; x++)
    {
        for (int y = 0; y < 10; y++)
        {
            string path = "/areas/eledhel/hadrath/watchlands/" +
                to_string(x) + "x" + to_string(y) + ".c";
            if (x == 0 && y == 0)
            {
                setEntryCoordinate(x, y, path, "north",
                    "/areas/eledhel/south-rural-route-08/18x2.c");
            }
            else
            {
                setCoordinate(x, y, path, "room");
            }
        }
    }
}
