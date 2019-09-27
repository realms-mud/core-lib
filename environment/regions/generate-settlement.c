//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/environment/regions/core.c";

private int GenerateSettlementsChance = -1;
private mapping *settlementPath = ({});

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
        settlementPath = ({ });

        int startX = random(MaxX - settlement["x dimension"]);
        int startY = random(MaxY - settlement["y dimension"]);

        for (int relativeX = 0; relativeX < settlement["x dimension"]; relativeX++)
        {
            for (int relativeY = 0; relativeY < settlement["y dimension"]; relativeY++)
            {
                int x = startX + relativeX;
                int y = startY + relativeY;

                mapping settlementRoom = settlement["layout"][relativeX][relativeY];

                grid[x][y]["room type"] = settlementRoom["type"];
                grid[x][y]["terrain"] = settlement["terrain"];

                string name = sprintf("%dx%d", x, y);
                grid[x][y]["identifier"] = sprintf("%s,%s-%s", EntryPoint || "none",
                    EnterFrom || "no exit", name);
                grid[x][y]["name"] = name;

                if (member(settlementRoom, "buildings"))
                {
                    grid[x][y]["buildings"] = settlementRoom["buildings"];
                }
                if(member(settlementRoom, "exits"))
                {
                    mapping exits = settlementRoom["exits"];

                    foreach(string exit in m_indices(exits))
                    {
                        grid[x][y]["exits"][exit] = sprintf("%dx%d", 
                            startX + exits[exit][0],
                            startY + exits[exit][1]);
                    }
                }

                if (grid[x][y]["room type"] == "building")
                {
                    grid[x][y]["icon"] = Dictionary->getBuildingLayout("1x1");
                    decorators += ({ grid[x][y] });
                }
                else if(grid[x][y]["room type"] == "path")
                {          
                    settlementPath += ({ grid[x][y] });
                }
            }
        }

        rooms += settlementPath;
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask object getSettlementEntrance()
{
    object ret = 0;

    if (sizeof(settlementPath) && member(settlementPath[0], "environment"))
    {
        ret = settlementPath[0]["environment"];
    }
    return ret;
}
