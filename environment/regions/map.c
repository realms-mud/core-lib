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
        "unicode": "\xe2\x8c\xa5"
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

            int userHere = objectp(present(user, grid[x][y]["environment"]));
            string exitColor = userHere ? "user location" : "exit";

            row[0] += sprintf(" %s ", hasExit(location, "north") ?
               configuration->decorate(displayCharacter["north"][charset],
                   exitColor, "map", colorConfiguration): " ");

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

        map += sprintf("%s\n%s\n%s\n", row[0], row[1], row[2]);
    }
    return map;
}
