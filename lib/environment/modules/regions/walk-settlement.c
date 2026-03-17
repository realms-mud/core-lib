//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/environment/modules/regions/core.c";

private int GenerateSettlementsChance = -1;
private int SettlementDecided = 0;
private int HasSettlement = 0;
private mapping SettlementTemplate = 0;
private int SettlementStartX = -1;
private int SettlementStartY = -1;
private mapping *settlementPath = ({});

/////////////////////////////////////////////////////////////////////////////
public void setSettlementChance(int chance)
{
    if ((chance >= 0) && (chance <= 100))
    {
        GenerateSettlementsChance = chance;
    }
    else if (chance != GenerateSettlementsChance)
    {
        raise_error(sprintf("walkableRegion: settlement chance (%d) must be "
            "between 0 and 100.\n", chance));
    }
}

/////////////////////////////////////////////////////////////////////////////
public int settlementChance()
{
    return GenerateSettlementsChance;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int hasSettlement()
{
    return HasSettlement;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int *settlementOrigin()
{
    if (HasSettlement)
    {
        return ({ SettlementStartX, SettlementStartY });
    }
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isSettlementCell(int x, int y)
{
    if (!HasSettlement || !SettlementTemplate)
    {
        return 0;
    }

    int relX = x - SettlementStartX;
    int relY = y - SettlementStartY;

    return (relX >= 0 && relX < SettlementTemplate["x dimension"] &&
        relY >= 0 && relY < SettlementTemplate["y dimension"] &&
        member(SettlementTemplate["layout"], relX) &&
        member(SettlementTemplate["layout"][relX], relY) &&
        SettlementTemplate["layout"][relX][relY]["type"] != "none");
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getSettlementCellData(int x, int y)
{
    if (!isSettlementCell(x, y))
    {
        return 0;
    }

    int relX = x - SettlementStartX;
    int relY = y - SettlementStartY;

    return SettlementTemplate["layout"][relX][relY];
}

/////////////////////////////////////////////////////////////////////////////
private nomask void placeSettlementCell(int x, int y, mapping cellData)
{
    if (grid[x][y]["is placed"])
    {
        return;
    }

    grid[x][y]["room type"] = cellData["type"];
    grid[x][y]["terrain"] = SettlementTemplate["terrain"];
    grid[x][y]["is placed"] = 1;
    grid[x][y]["is settlement"] = 1;

    string name = sprintf("%dx%d", x, y);
    grid[x][y]["identifier"] = sprintf("%s-%s", RegionName || "walk", name);
    grid[x][y]["name"] = name;

    if (member(cellData, "buildings"))
    {
        grid[x][y]["buildings"] = cellData["buildings"];
    }

    mapping exits = ([]);

    if (y + 1 < MaxY)
    {
        exits["north"] = sprintf("%dx%d", x, y + 1);
    }
    if (y - 1 >= 0)
    {
        exits["south"] = sprintf("%dx%d", x, y - 1);
    }
    if (x + 1 < MaxX)
    {
        exits["east"] = sprintf("%dx%d", x + 1, y);
    }
    if (x - 1 >= 0)
    {
        exits["west"] = sprintf("%dx%d", x - 1, y);
    }

    grid[x][y]["exits"] = exits;

    if (cellData["type"] == "building")
    {
        grid[x][y]["icon"] = RegionService->getBuildingLayout("1x1");
        decorators += ({ grid[x][y] });
    }
    else if (cellData["type"] == "path")
    {
        settlementPath += ({ grid[x][y] });
    }

    rooms += ({ grid[x][y] });
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void decideSettlement()
{
    if (SettlementDecided)
    {
        return;
    }
    SettlementDecided = 1;

    if (RegionService->canConstructSettlement(this_object()))
    {
        mapping settlement = RegionService->constructSettlement(RegionType);

        if (mappingp(settlement))
        {
            HasSettlement = 1;
            SettlementTemplate = settlement;

            int sizeX = settlement["x dimension"];
            int sizeY = settlement["y dimension"];

            SettlementStartX = MaxX / 2 - sizeX / 2;
            SettlementStartY = MaxY / 2 - sizeY / 2;

            if (sizeof(entry) == 2)
            {
                int entryDistX = SettlementStartX - entry[0];
                int entryDistY = SettlementStartY - entry[1];
                if (entryDistX < 0)
                {
                    entryDistX = -entryDistX;
                }
                if (entryDistY < 0)
                {
                    entryDistY = -entryDistY;
                }

                if (entryDistX < sizeX && entryDistY < sizeY)
                {
                    SettlementStartY = entry[1] + 3;
                }
            }

            if (SettlementStartX < 0)
            {
                SettlementStartX = 0;
            }
            if (SettlementStartY < 0)
            {
                SettlementStartY = 0;
            }
            if (SettlementStartX + sizeX > MaxX)
            {
                SettlementStartX = MaxX - sizeX;
            }
            if (SettlementStartY + sizeY > MaxY)
            {
                SettlementStartY = MaxY - sizeY;
            }

            for (int relX = 0; relX < sizeX; relX++)
            {
                for (int relY = 0; relY < sizeY; relY++)
                {
                    int absX = SettlementStartX + relX;
                    int absY = SettlementStartY + relY;

                    if (member(settlement["layout"], relX) &&
                        member(settlement["layout"][relX], relY))
                    {
                        mapping cellData =
                            settlement["layout"][relX][relY];

                        if (cellData["type"] != "none")
                        {
                            placeSettlementCell(absX, absY, cellData);
                        }
                    }
                }
            }
        }
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
