//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/environment/regions/core.c";

/////////////////////////////////////////////////////////////////////////////
protected nomask void generateSettlement()
{
    mapping settlement = Dictionary->constructSettlement(RegionType);
    if (mappingp(settlement))
    {
        int startX = random(MaxX - settlement["x dimension"]);
        int startY = random(MaxY - settlement["y dimension"]);

        for (int relativeX = 0; relativeX < settlement["x dimension"]; relativeX++)
        {
            for (int relativeY = 0; relativeY < settlement["y dimension"]; relativeY++)
            {
                int x = startX + relativeX;
                int y = startY + relativeY;

                grid[x][y]["room type"] = 
                    settlement["layout"][relativeX][relativeY]["type"];

                grid[x][y]["name"] = sprintf("%dx%d", x, y);

                mapping exits = settlement["layout"][relativeX][relativeY]["exits"];
                foreach(string exit in m_indices(exits))
                {
                    grid[x][y]["exits"][exit] = sprintf("%dx%d", exits[exit][0],
                        exits[exit][1]);
                }

                if (grid[x][y]["room type"] != "building")
                {
                    rooms += ({ grid[x][y] });
                }
            }
        }
    }
}
