//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/region.c";

public void Setup()
{
    setRegionName("Hrondil and the Limestone Uplands");
    setRegionType("rural");
    setRegionLevel(5);
    setSettlementChance(-1);
    setDimensions(25, 9);

    for (int y = 0; y < 9; y++)
    {
        for (int x = 0; x < 25; x++)
        {
            int road = !(y % 2) ||
                (((y == 1) || (y == 5)) && (x == 24)) ||
                (((y == 3) || (y == 7)) && (x == 0));

            if (road)
            {
                string path = "/areas/northern-road/hrondil-approaches/" +
                    to_string(x) + "x" + to_string(y) + ".c";

                if ((x == 0) && (y == 0))
                {
                    setEntryCoordinate(x, y, path, "south",
                        "/areas/northern-road/belathon-eolach/24x8.c");
                }
                else
                {
                    setCoordinate(x, y, path, "road");
                }
            }
        }
    }
}
