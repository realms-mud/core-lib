//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/environment/regions/core.c";

private object configuration = load_object("/lib/dictionaries/configurationDictionary.c");

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
    "path": ([
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
    "exit": ([
        "ascii": "X",
        "unicode": "\xe2\x8c\xa7"
    ]),
    "player": ([
        "ascii": "P",
        "unicode": "\xe2\x99\x99"
    ]),
    "divider": ([
        "ascii": "'",
        "unicode": "\xe2\x95\x91"
    ]),
    "none": ([
        "ascii": " ",
        "unicode": " "
    ]),
]);

/////////////////////////////////////////////////////////////////////////////
private nomask int hasExit(mapping location, string direction)
{
    return member(location["exits"], direction) ||
        ((member(({ "entry", "exit" }), location["room type"]) > -1) &&
        (location["exit to"] == direction));
}

/////////////////////////////////////////////////////////////////////////////
private nomask varargs string displayMapSection(object user, int startX, 
    int startY, int endX, int endY, int addDivider)
{
    string colorConfiguration = user->colorConfiguration();
    string charset = user->charsetConfiguration();

    string map = "";

    if (user)
    {
        for (int y = startY; y >= endY; y--)
        {
            string *row = ({ "", "", "", "" });

            for (int x = startX; x <= endX; x++)
            {
                mapping location = grid[x][y];

                int userHere = objectp(present(user, location["environment"]));
                string exitColor = userHere ? "user location" : "exit";

                row[0] += sprintf(" %s ", hasExit(location, "north") ?
                    configuration->decorate(displayCharacter["north"][charset],
                        exitColor, "map", colorConfiguration) : " ");

                row[1] += sprintf("%s%s%s",
                    (hasExit(location, "west") ?
                        configuration->decorate(displayCharacter["west"][charset],
                            exitColor, "map", colorConfiguration) : " "),
                    configuration->decorate(
                    (userHere ? displayCharacter["player"][charset] :
                        displayCharacter[location["room type"]][charset]),
                        (userHere ? "user location" : location["room type"]),
                        "map", colorConfiguration),
                        (hasExit(location, "east") ?
                            configuration->decorate(displayCharacter["east"][charset],
                                exitColor, "map", colorConfiguration) : " "));

                row[2] += sprintf(" %s ", hasExit(location, "south") ?
                    configuration->decorate(displayCharacter["south"][charset],
                        exitColor, "map", colorConfiguration) : " ");
            }

            string divider = !addDivider ? "" :
                configuration->decorate(displayCharacter["divider"][charset],
                    "divider", "map", colorConfiguration);

            map += sprintf("%s%s\n%s%s\n%s%s\n", row[0], divider, row[1], 
                divider, row[2], divider);
        }
    }
    return map;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *getMiniMap(object environment, object user)
{
    string map = 0;

    if (environment)
    {
        string coordinates = environment->getCoordinates();
        if (coordinates)
        {
            int xCoordinate = to_int(regreplace(coordinates, "([0-9]+)x.*", "\\1", 1));
            int endX = (xCoordinate == (MaxX - 1)) ? (MaxX - 1) : xCoordinate +
                ((xCoordinate == 0) ? 2 : 1);
            int startX = xCoordinate ? xCoordinate - ((endX == (MaxX - 1)) ? 2 : 1) : 0;

            int yCoordinate = to_int(regreplace(coordinates, ".*x([0-9]+)", "\\1", 1));
            int startY = (yCoordinate == (MaxY - 1)) ? (MaxY - 1) : yCoordinate +
                ((yCoordinate == 0) ? 2 : 1);
            int endY = yCoordinate ? yCoordinate - ((yCoordinate == (MaxY - 1)) ? 2 : 1) : 0;

            map = displayMapSection(user, startX, startY, endX, endY, 1);
        }
    }
    return map ? explode(map, "\n") : 0;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string displayMap(object user)
{
    return "\n" + displayMapSection(user, 0, MaxY - 1, MaxX - 1, 0);
}
