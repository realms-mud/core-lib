//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef buildings_h
#define buildings_h

private mapping BuildingBlueprints = ([
    "unbuilt keep":([
        "type": "keep",
        "dimensions": "3x3",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;9m",
                "24-bit": "\x1b[0;38;2;200;0;0m"
            ]),
        ]),
        "components":([
            "KEEP    1":([
                "ascii": ".........",
                "unicode": "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7"
                    "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7",
            ]),
            "KEEP    2":([
                "ascii": ".       .",
                "unicode": "\xe2\x88\xb7       \xe2\x88\xb7",
            ]),
            "KEEP    3":([
                "ascii": ".       .",
                "unicode": "\xe2\x88\xb7       \xe2\x88\xb7",
            ]),
            "KEEP    4":([
                "ascii": ".       .",
                "unicode": "\xe2\x88\xb7       \xe2\x88\xb7",
            ]),
            "KEEP    5":([
                "ascii": ".........",
                "unicode": "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7"
                    "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7",
            ]),
        ]),
    ]),
]);

#endif
