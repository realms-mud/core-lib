//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/environment/modules/regions/core.c";

/////////////////////////////////////////////////////////////////////////////
protected nomask int *getRandomEntryCoordinates(string enterFrom)
{
    int startOnXAxis;
    int useMax;
    switch (enterFrom)
    {
        case "north":
        {
            startOnXAxis = 0;
            useMax = 1;
            break;
        }
        case "south":
        {
            startOnXAxis = 0;
            useMax = 0;
            break;
        }
        case "east":
        {
            startOnXAxis = 1;
            useMax = 1;
            break;
        }
        case "west":
        {
            startOnXAxis = 1;
            useMax = 0;
            break;
        }
        default:
        {
            // Pick a random start from an edge position
            startOnXAxis = random(2);
            useMax = random(2);
            break;
        }
    }

    return ({
        startOnXAxis ? (useMax ? (MaxX - 1) : 0) : random(MaxX),
        startOnXAxis ? random(MaxY) : (useMax ? (MaxY - 1) : 0)
    });
}

/////////////////////////////////////////////////////////////////////////////
protected nomask varargs mapping createExit(int count)
{
    mapping ret = ([]);
    if (sizeof(entry) && (count < 20))
    {
        int x = -1;
        int y = -1;
        string exitTo = 0;
        int *exitCoordinates = ({});

        if (entry[0] == 0)
        {
            x = MaxX - 1;
            y = random(MaxY);
            exitCoordinates = ({ 0, y });
            exitTo = "east";
        }
        else if (entry[0] == (MaxX - 1))
        {
            x = 0;
            y = random(MaxY);
            exitCoordinates = ({ (MaxX - 1), y });
            exitTo = "west";
        }
        else if (entry[1] == 0)
        {
            y = MaxY - 1;
            x = random(MaxX);
            exitCoordinates = ({ x, 0 });
            exitTo = "north";
        }
        else if (entry[1] == (MaxY - 1))
        {
            y = 0;
            x = random(MaxX);
            exitCoordinates = ({ x, (MaxY - 1) });
            exitTo = "south";
        }

        if (!grid[x][y]["is placed"])
        {
            grid[x][y]["room type"] = "exit";
            grid[x][y]["exit to"] = exitTo;
            grid[x][y]["exit coordinates"] = exitCoordinates;

            string name = sprintf("%dx%d", x, y);
            grid[x][y]["identifier"] = sprintf("%s,%s-%s", EntryPoint || "none",
                EnterFrom || "no exit", name);
            grid[x][y]["name"] = name;

            ret = grid[x][y];
        }
        else
        {
            ret = createExit(++count);
        }
    }
    return ret;
}
