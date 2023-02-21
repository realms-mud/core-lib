//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/environment/modules/regions/core.c";

/////////////////////////////////////////////////////////////////////////////
private mapping getNextDirection(int x, int y, string previousDirection)
{
    string *possibleDirections = 
        availableDirections - ({ oppositeDirection[previousDirection] });

    if (x == 0)
    {
        possibleDirections -= ({ "west" });
    }
    else  if (x == (MaxX - 1))
    {
        possibleDirections -= ({ "east" });
    }

    if (y == 0)
    {
        possibleDirections -= ({ "south" });
    }
    else  if (y == (MaxY - 1))
    {
        possibleDirections -= ({ "north" });
    }

    if (previousDirection && 
        (member(possibleDirections, oppositeDirection[previousDirection]) > -1))
    {
        for (int i; i < 50; i++)
        {
            // It's more likely you'll go in a straight line than not
            possibleDirections += ({ previousDirection });
        }
    }

    int numDirections = sizeof(possibleDirections);
    string direction =  numDirections ? 
        possibleDirections[random(numDirections)] : "none";

    switch (direction)
    {
        case "east":
        {
            x++;
            break;
        }
        case "west":
        {
            x--;
            break;
        }
        case "north":
        {
            y++;
            break;
        }
        case "south":
        {
            y--;
            break;
        }
    }

    return (["x":x, "y" : y, "direction" : direction]);
}

/////////////////////////////////////////////////////////////////////////////
private nomask varargs string *traverseAPath(mapping startRoom, 
    string previousDirection, string *path)
{
    if (!path)
    {
        path = ({});
    }

    if(!startRoom["is placed"] || (startRoom["room type"] == "entry"))
    {
        path += ({ sprintf("%dx%d%s", startRoom["x"], startRoom["y"],
            (previousDirection ? "," + previousDirection : "")) });

        mapping nextRoom =
            getNextDirection(startRoom["x"], startRoom["y"], previousDirection);

        string nextCoordinates = sprintf("%dx%d", nextRoom["x"], nextRoom["y"]);
        mapping room = grid[nextRoom["x"]][nextRoom["y"]];

        if (room["room type"] == "building")
        {
            path = 0;
        }
        else if (nextRoom["direction"] != "none")
        {
            if ((room["is placed"] != 1))
            {
                if(!sizeof(filter(path, 
                    (: sizeof(regexp(({ $1 }), 
                        sprintf("%dx%d(,|$)", nextRoom["x"], nextRoom["y"]))) :))))
                {
                    path = traverseAPath(room, nextRoom["direction"], path);
                }
                else
                {
                    path = 0;
                }
            }
            else if(!sizeof(filter(path, 
                    (: sizeof(regexp(({ $1 }), 
                        sprintf("%dx%d(,|$)", nextRoom["x"], nextRoom["y"]))) :))))
            {
                path += ({ sprintf("%dx%d,%s",  nextRoom["x"], nextRoom["y"],
                    nextRoom["direction"]) });
            }
            else
            {
                path = 0;
            }
        }
    }
    
    return path;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void constructPath(mapping room)
{
    string *path = 0;
    for (int i = 0; (!path && (i < 20)); i++)
    {
        path = traverseAPath(room);
    }

    int fromX = -1;
    int fromY = -1;

    for (int i = 0; i < sizeof(path); i++)
    {
        int toX = to_int(regreplace(path[i], "([0-9]+)x[0-9]+,*.*", "\\1", 1));
        int toY = to_int(regreplace(path[i], "[0-9]+x([0-9]+),*.*", "\\1", 1));
        string direction = regreplace(path[i], ".*,(.+)", "\\1", 1);

        if ((fromX > -1) && (fromY > -1))
        {
            grid[fromX][fromY]["exits"][direction] = sprintf("%dx%d", toX, toY);
            grid[toX][toY]["exits"][oppositeDirection[direction]] =
                sprintf("%dx%d", fromX, fromY);
            grid[toX][toY]["is placed"] = 1;
            if (grid[toX][toY]["room type"] == "none")
            {
                grid[toX][toY]["room type"] = "path";

                string name = sprintf("%dx%d", toX, toY);
                grid[toX][toY]["identifier"] = sprintf("%s,%s-%s", EntryPoint || "none",
                    EnterFrom || "no exit", name);
                grid[toX][toY]["name"] = name;

                rooms += ({ grid[toX][toY] });
            }
        }
        else
        {
            grid[toX][toY]["is placed"] = 1;
        }

        fromX = toX;
        fromY = toY;
    }
}
