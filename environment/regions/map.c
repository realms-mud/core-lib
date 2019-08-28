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
    "exit": ([
        "ascii": "X",
        "unicode": "\xe2\x8c\xa7"
    ]),
    "none": ([
        "ascii": " ",
        "unicode": " "
    ]),
]);

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
