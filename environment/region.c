//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private object configuration = load_object("/lib/dictionaries/configurationDictionary.c");

protected int MaxX = 25;
protected int MaxY = 10;
private string *availableDirections = ({ "north", "south", "east", "west" });
private mapping oppositeDirection = ([
    "north": "south",
    "south": "north",
    "west": "east",
    "east": "west"
]);

private mapping displayCharacter = ([
    "north":([
        "ascii": "|",
        "unicode": "\xe2\x94\x82"
    ]),
    "south":([
        "ascii": "|",
        "unicode": "\xe2\x94\x82"
    ]),
    "east":([
        "ascii": "-",
        "unicode": "\xe2\x94\x80"
    ]),
    "west":([
        "ascii": "-",
        "unicode": "\xe2\x94\x80"
    ]),
    "corridor": ([
        "ascii": "o",
        "unicode": "\xe2\x97\x87"
    ]),
    "room": ([
        "ascii": "#",
        "unicode": "\xe2\x96\xa3"
    ]),
    "entry": ([
        "ascii": "#",
        "unicode": "\xe2\x96\xa3"
    ]),
    "none": ([
        "ascii": " ",
        "unicode": " "
    ]),
]);

private mapping grid = ([
]);

private mapping *rooms = ({ });

/////////////////////////////////////////////////////////////////////////////
public nomask string getRelativeOverheadMap(int x, int y)
{
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
private nomask void createEmptyGrid(int x, int y)
{
    for (int i = 0; i < x; i++)
    {
        grid[i] = ([]);
        for (int j = 0; j < y; j++)
        {
            grid[i][j] = ([
                "x": i,
                "y": j,
                "room type": "none",
                "is placed": 0,
                "environmental elements": ([]),
                "exits": ([]),
                "objects": ([]),
                "living": ([])
            ]);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void addRandomEnvironmentalElements()
{

}

/////////////////////////////////////////////////////////////////////////////
private nomask void addRandomObjects()
{

}

/////////////////////////////////////////////////////////////////////////////
private nomask void addRandomCreature()
{

}

/////////////////////////////////////////////////////////////////////////////
private nomask varargs void createRoom(int isEntry)
{
    int x;
    int y;
    if (isEntry)
    {
        // Pick a random start from an edge position
        int startOnXAxis = random(2);
        int useMax = random(2);
        x = startOnXAxis ? (useMax ? (MaxX - 1) : 0) : random(MaxX);
        y = startOnXAxis ? random(MaxY) : (useMax ? (MaxY - 1) : 0);
    }
    else
    {
        x = random(MaxX);
        y = random(MaxY);
    }

    if (!grid[x][y]["is placed"])
    {
        grid[x][y]["is placed"] = isEntry;
        grid[x][y]["room type"] = isEntry ? "entry" : "room";

        addRandomEnvironmentalElements();
        addRandomObjects();
        addRandomCreature();

        rooms += ({ grid[x][y] });
    }
    else
    {
        createRoom(isEntry);
    }
}

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
        if ((nextRoom["direction"] != "none"))
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
public nomask string displayMap(object user)
{
    string colorConfiguration = user->colorConfiguration();
    string charset = user->charsetConfiguration();

    string map = "\n";

    for(int y = (MaxY - 1); y >= 0; y--)
    {
        string *row = ({ "", "", "", "" });

        for(int x = 0; x < MaxX; x++)
        {
            mapping location = grid[x][y];
            row[0] += sprintf(" %s ", member(location["exits"], "north") ?
               configuration->decorate(displayCharacter["north"][charset],
                   "exit", "map", colorConfiguration): " ");

            row[1] += sprintf("%s%s%s",
                (member(location["exits"], "west") ?
                    configuration->decorate(displayCharacter["west"][charset],
                    "exit", "map", colorConfiguration) : " "),
                configuration->decorate(displayCharacter[location["room type"]][charset],
                    location["room type"], "map", colorConfiguration),
                (member(location["exits"], "east") ?
                    configuration->decorate(displayCharacter["east"][charset],
                    "exit", "map", colorConfiguration) : " "));

            row[2] += sprintf(" %s ", member(location["exits"], "south") ?
                configuration->decorate(displayCharacter["south"][charset],
                    "exit", "map", colorConfiguration) : " ");
        }

        map += sprintf("%s\n%s\n%s\n", row[0], row[1], row[2]);
    }
    return map;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void createArea()
{
    createEmptyGrid(MaxX, MaxY);

    // Create entry point
    createRoom(1);

    int numberOfRooms = 25 + random(25);
    for (int i = 0; i < numberOfRooms; i++)
    {
        createRoom();
    }

    while (sizeof(filter(rooms, (: $1["is placed"] == 0 :))))
    {
        foreach(mapping room in rooms)
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
                        grid[toX][toY]["room type"] = "corridor";
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
    }
}
