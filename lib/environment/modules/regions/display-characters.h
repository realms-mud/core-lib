//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef displayCharacters_h
#define displayCharacters_h

private mapping displayCharacter = ([
    "north":([
        "ascii": "|",
        "unicode": "\u2502"
    ]),
    "south":([
        "ascii": "|",
        "unicode": "\u2502"
    ]),
    "east":([
        "ascii": "-",
        "unicode": "\u2500"
    ]),
    "west":([
        "ascii": "-",
        "unicode": "\u2500"
    ]),
    "northwest":([
        "ascii": "\\",
        "unicode": "\u2572"
    ]),
    "southeast":([
        "ascii": "\\",
        "unicode": "\u2572"
    ]),
    "northeast":([
        "ascii": "/",
        "unicode": "\u2571"
    ]),
    "southwest":([
        "ascii": "/",
        "unicode": "\u2571"
    ]),
    "path": ([
        "ascii": "o",
        "unicode": "\u25c7"
    ]),
    "room": ([
        "ascii": "#",
        "unicode": "\u25a3"
    ]),
    "training ground": ([
        "ascii": "O",
        "unicode": "\u2720"
    ]),
    "shop": ([
        "ascii": "$",
        "unicode": "$"
    ]),
    "entry": ([
        "ascii": "#",
        "unicode": "\u25a3"
    ]),
    "exit": ([
        "ascii": "X",
        "unicode": "\u2327"
    ]),
    "player": ([
        "ascii": "P",
        "unicode": "\u2659"
    ]),
    "divider": ([
        "ascii": "'",
        "unicode": "\u2551"
    ]),
    "none": ([
        "ascii": " ",
        "unicode": " "
    ]),
]);

#endif
