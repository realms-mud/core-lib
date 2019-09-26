//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/environment/regions/core.c";

private int GenerateSettlementsChance = -1;

/////////////////////////////////////////////////////////////////////////////
public void setSettlementChance(int chance)
{
    if ((chance >= 0) && (chance <= 100))
    {
        GenerateSettlementsChance = chance;
    }
    else
    {
        raise_error("Region: settlement chance must be between 0 and 100.\n");
    }
}

/////////////////////////////////////////////////////////////////////////////
public int settlementChance()
{
    return GenerateSettlementsChance;
}

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

                string name = sprintf("%dx%d", x, y);
                grid[x][y]["identifier"] = sprintf("%s,%s-%s", EntryPoint || "none",
                    EnterFrom || "no exit", name);
                grid[x][y]["name"] = name;

                if(member(settlement["layout"][relativeX][relativeY], "exits"))
                {
                    mapping exits = settlement["layout"][relativeX][relativeY]["exits"];

                    foreach(string exit in m_indices(exits))
                    {
                        grid[x][y]["exits"][exit] = sprintf("%dx%d", exits[exit][0],
                            exits[exit][1]);
                    }
                }

                if (member(settlement["layout"][relativeX][relativeY], "features"))
                {

                }

                if (grid[x][y]["room type"] == "building")
                {
                    grid[x][y]["icon"] = Dictionary->getBuildingLayout("1x1");
                    decorators += ({ grid[x][y] });
                }
                else if(grid[x][y]["room type"] == "path")
                {
                    rooms += ({ grid[x][y] });
                }
            }
        }
    }
}
