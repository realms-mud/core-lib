//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef displayCharacters_h
#define displayCharacters_h

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
    "training ground": ([
        "ascii": "O",
        "unicode": "\xe2\x9c\xa0"
    ]),
    "shop": ([
        "ascii": "$",
        "unicode": "$"
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

#endif