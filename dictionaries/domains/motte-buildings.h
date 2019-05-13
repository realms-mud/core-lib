//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef motteBuildings_h
#define motteBuildings_h

private mapping MotteBuildings = ([
    "unbuilt northwest building":([
        "type": "northwest building",
        "dimensions": "2x1",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;1m",
                "24-bit": "\x1b[0;38;2;128;0;0m"
            ]),
        ]),
        "components":([
            "NW1": ([
                "ascii": ".?.",
                "unicode": "\xe2\x94\x8a\xe2\x81\x87\xe2\x94\x8a",
            ]),
            "NW2": ([
                "ascii": "...",
                "unicode": "\xe2\x94\x94\xe2\x94\x88\xe2\x94\x98",
            ]),
        ]),
    ]),

    "unbuilt northeast building":([
        "type": "northeast building",
        "dimensions": "2x1",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;1m",
                "24-bit": "\x1b[0;38;2;128;0;0m"
            ]),
        ]),
        "components":([
            "NE1": ([
                "ascii": ".?.",
                "unicode": "\xe2\x94\x8a\xe2\x81\x87\xe2\x94\x8a",
            ]),
            "NE2": ([
                "ascii": "...",
                "unicode": "\xe2\x94\x94\xe2\x94\x88\xe2\x94\x98",
            ]),
        ]),
    ]),

    "unbuilt first western building":([
        "type": "western building",
        "dimensions": "2x1",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;9m",
                "24-bit": "\x1b[0;38;2;200;0;0m"
            ]),
        ]),
        "components":([
            "WB1": ([
                "ascii": ".. ",
                "unicode": "\xe2\x94\x88\xe2\x94\x90 ",
            ]),
            "WB2": ([
                "ascii": "?. ",
                "unicode": "\xe2\x81\x87\xe2\x94\x8a ",
            ]),
            "WB3": ([
                "ascii": ".. ",
                "unicode": "\xe2\x94\x88\xe2\x94\x98 ",
            ]),
        ]),
    ]),

    "unbuilt second western building":([
        "type": "western building",
        "dimensions": "2x1",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;9m",
                "24-bit": "\x1b[0;38;2;200;0;0m"
            ]),
        ]),
        "components":([
            "WB4": ([
                "ascii": ".. ",
                "unicode": "\xe2\x94\x88\xe2\x94\x90 ",
            ]),
            "WB5": ([
                "ascii": "?. ",
                "unicode": "\xe2\x81\x87\xe2\x94\x8a ",
            ]),
            "WB6": ([
                "ascii": ".. ",
                "unicode": "\xe2\x94\x88\xe2\x94\x98 ",
            ]),
        ]),
    ]),

    "unbuilt first eastern building":([
        "type": "eastern building",
        "dimensions": "2x1",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;9m",
                "24-bit": "\x1b[0;38;2;200;0;0m"
            ]),
        ]),
        "components":([
            "EB1": ([
                "ascii": " ..",
                "unicode": " \xe2\x94\x8c\xe2\x94\x88",
            ]),
            "EB2": ([
                "ascii": " .?",
                "unicode": " \xe2\x94\x8a\xe2\x81\x87",
            ]),
            "EB3": ([
                "ascii": ".. ",
                "unicode": " \xe2\x94\x94\xe2\x94\x88",
            ]),
        ]),
    ]),

    "unbuilt second eastern building":([
        "type": "eastern building",
        "dimensions": "2x1",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;9m",
                "24-bit": "\x1b[0;38;2;200;0;0m"
            ]),
        ]),
        "components":([
            "EB4": ([
                "ascii": " ..",
                "unicode": " \xe2\x94\x8c\xe2\x94\x88",
            ]),
            "EB5": ([
                "ascii": " .?",
                "unicode": " \xe2\x94\x8a\xe2\x81\x87",
            ]),
            "EB6": ([
                "ascii": ".. ",
                "unicode": " \xe2\x94\x94\xe2\x94\x88",
            ]),
        ]),
    ]),

    "unbuilt southwest building":([
        "type": "southwest building",
        "dimensions": "2x1",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;1m",
                "24-bit": "\x1b[0;38;2;128;0;0m"
            ]),
        ]),
        "components":([
            "SW1": ([
                "ascii": "...",
                "unicode": "\xe2\x94\x8c\xe2\x94\x88\xe2\x94\x90",
            ]),
            "SW2": ([
                "ascii": ".?.",
                "unicode": "\xe2\x94\x8a\xe2\x81\x87\xe2\x94\x8a",
            ]),
        ]),
    ]),

    "unbuilt southeast building":([
        "type": "southeast building",
        "dimensions": "2x1",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;1m",
                "24-bit": "\x1b[0;38;2;128;0;0m"
            ]),
        ]),
        "components":([
            "SE1": ([
                "ascii": "...",
                "unicode": "\xe2\x94\x8c\xe2\x94\x88\xe2\x94\x90",
            ]),
            "SE2": ([
                "ascii": ".?.",
                "unicode": "\xe2\x94\x8a\xe2\x81\x87\xe2\x94\x8a",
            ]),
        ]),
    ]),
]);

#endif
