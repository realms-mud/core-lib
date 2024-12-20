//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private mapping pilonDisplay = ([
    "green":([
        "character":([
            "unicode": "\u229b",
            "ascii": "="
        ]),
        "color":([
            "grayscale": "\x1b[0;38;5;251;1m",
            "3-bit": "\x1b[0;32;1m",
            "8-bit": "\x1b[0;38;5;28;1m",
            "24-bit": "\x1b[0;38;2;0;180;0;1m"
        ]),
    ]),
    "default":([
        "character":([
            "unicode": "\u229b",
            "ascii": "-"
        ]),
        "color":([
            "grayscale": "\x1b[0;38;5;244;1m",
            "3-bit": "\x1b[0;35;6m",
            "8-bit": "\x1b[0;38;5;244;1m",
            "24-bit": "\x1b[0;38;2;120;120;120;1m"
        ]),
    ]),
]);

private string currentTest = "none";
private int platesCanBePressed = 0;
