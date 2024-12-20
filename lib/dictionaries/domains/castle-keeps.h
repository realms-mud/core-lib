//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef castleKeeps_h
#define castleKeeps_h

private mapping CastleKeeps = ([
    "unbuilt keep":([
        "type": "keep",
        "display name": "Unbuilt Keep",
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
                "unicode": "\u2237\u2237\u2237\u2237"
                    "\u2237\u2237\u2237\u2237\u2237",
            ]),
            "KEEP    2":([
                "ascii": ".       .",
                "unicode": "\u2237       \u2237",
            ]),
            "KEEP    3":([
                "ascii": ".       .",
                "unicode": "\u2237       \u2237",
            ]),
            "KEEP    4":([
                "ascii": ".       .",
                "unicode": "\u2237       \u2237",
            ]),
            "KEEP    5":([
                "ascii": ".........",
                "unicode": "\u2237\u2237\u2237\u2237"
                    "\u2237\u2237\u2237\u2237\u2237",
            ]),
        ]),
    ]),

    "small wooden keep":([
        "type": "keep",
        "display name": "Small Wooden Keep",
        "dimensions": "3x3",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;32m",
                "8-bit": "\x1b[0;38;5;29m",
                "24-bit": "\x1b[0;38;2;1;121;111m",
            ]),
            "roof":([
                "3-bit": "\x1b[0;42m",
                "8-bit": "\x1b[0;48;5;29;38;5;0m",
                "24-bit": "\x1b[0;48;2;0;30;0;38;2;1;121;111m",
            ]),
        ]),
        "construction": ([
            "duration": 600,
            "materials": ([
                "main wooden keep": ([ "wood": 400, "metal": 10, "textile": 0 ]),
                "wooden battlement": ([ "wood": 50, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "carpenter": 5,
                "foreman": 1,
                "blacksmith": 1,
                "architect": 1,
            ]),
        ]),
        "components":([
            "KEEP    1":([
                "ascii": "+-------+",
                "unicode": "\u250c\u2500\u2500\u2500"
                    "\u2500\u2500\u2500\u2500\u2510",
            ]),
            "KEEP    2":([
                "ascii": "|       |",
                "unicode": "\u2502\u2591\u2591\u2591"
                    "\u2591\u2591\u2591\u2591\u2502",
            ]),
            "KEEP    3":([
                "ascii": "|       |",
                "unicode": "\u2502\u2591\u2591\u2591"
                    "\u2591\u2591\u2591\u2591\u2502",
            ]),
            "KEEP    4":([
                "ascii": "|       |",
                "unicode": "\u2502\u2591\u2591\u2591"
                    "\u2591\u2591\u2591\u2591\u2502",
            ]),
            "KEEP    5":([
                "ascii": "+-------+",
                "unicode": "\u2514\u2500\u2500\u2500"
                    "\u2500\u2500\u2500\u2500\u2518",
            ]),
        ]),
    ]),

    "wooden keep":([
        "type": "keep",
        "display name": "Wooden Keep",
        "dimensions":"3x3",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;32m",
                "8-bit": "\x1b[0;38;5;29m",
                "24-bit": "\x1b[0;38;2;1;121;111m",
            ]),
            "roof":([
                "3-bit": "\x1b[0;42m",
                "8-bit": "\x1b[0;48;5;29;38;5;0m",
                "24-bit": "\x1b[0;48;2;0;30;0;38;2;1;121;111m",
            ]),
        ]),
        "construction": ([
            "duration": 900,
            "materials": ([
                "main wooden keep": ([ "wood": 400, "metal": 10, "textile": 0 ]),
                "central wooden tower": ([ "wood": 300, "metal": 10, "textile": 0 ]),
                "wooden battlement": ([ "wood": 75, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "carpenter": 10,
                "foreman": 1,
                "blacksmith": 1,
                "architect": 1,
            ]),
        ]),
        "components":([ 
            "KEEP    1":([
                "ascii": "+~~~~~~~+",
                "unicode": "\u250f\u2501\u2501\u2501"
                    "\u2501\u2501\u2501\u2501\u2513",
            ]),
            "KEEP    2":([
                "ascii": "|       |",
                "unicode": "\u2503\u2591\u2591\u2591"
                    "\u2591\u2591\u2591\u2591\u2503",
            ]),
            "KEEP    3":([
                "ascii": "|       |",
                "unicode": "\u2503\u2591\u2591\u2591"
                    "\u2591\u2591\u2591\u2591\u2503",
            ]),
            "KEEP    4":([
                "ascii": "|       |",
                "unicode": "\u2503\u2591\u2591\u2591"
                    "\u2591\u2591\u2591\u2591\u2503",
            ]),
            "KEEP    5":([
                "ascii": "+~~~~~~~+",
                "unicode": "\u2517\u2501\u2501\u2501"
                    "\u2501\u2501\u2501\u2501\u251b",
            ]),
        ]),
    ]),

    "small stone keep":([
        "type": "keep",
        "display name": "Small Stone Keep",
        "dimensions":"3x3",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;36m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
            "roof":([
                "3-bit": "\x1b[0;46m",
                "8-bit": "\x1b[0;48;5;103;38;5;116m",
                "24-bit": "\x1b[0;48;2;112;128;144;38;2;90,90,90m",
            ]),
        ]),
        "construction": ([
            "duration": 600,
            "materials": ([
                "main stone keep": ([ "stone": 400, "wood": 50, "metal": 10, "textile": 0 ]),
                "stone battlement": ([ "stone": 75, "wood": 25, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "stonemason": 5,
                "carpenter": 2,
                "foreman": 1,
                "blacksmith": 1,
                "architect": 1,
            ]),
        ]),
        "components":([ 
            "KEEP    1":([
                "ascii": "+=======+",
                "unicode": "\u250f\u2501\u2501\u2501"
                    "\u2501\u2501\u2501\u2501\u2513",
            ]),
            "KEEP    2":([
                "ascii": "|       |",
                "unicode": "\u2503\u2591\u2591\u2591"
                    "\u2591\u2591\u2591\u2591\u2503",
            ]),
            "KEEP    3":([
                "ascii": "|       |",
                "unicode": "\u2503\u2591\u2591\u2591"
                    "\u2591\u2591\u2591\u2591\u2503",
            ]),
            "KEEP    4":([
                "ascii": "|       |",
                "unicode": "\u2503\u2591\u2591\u2591"
                    "\u2591\u2591\u2591\u2591\u2503",
            ]),
            "KEEP    5":([
                "ascii": "+=======+",
                "unicode": "\u2517\u2501\u2501\u2501"
                    "\u2501\u2501\u2501\u2501\u251b",
            ]),
        ]),
    ]),

    "stone keep":([
        "type": "keep",
        "display name": "Stone Keep",
        "dimensions":"3x3",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;36m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
            "roof":([
                "3-bit": "\x1b[0;30;1m",
                "8-bit": "\x1b[0;48;5;103;38;5;116m",
                "24-bit": "\x1b[0;48;2;112;128;144;38;2;90,90,90m",
            ]),
        ]),
        "construction": ([
            "duration": 1000,
            "materials": ([
                "main stone keep": ([ "stone": 400, "wood": 50, "metal": 10, "textile": 0 ]),
                "central stone tower": ([ "stone": 300, "wood": 50, "metal": 10, "textile": 0 ]),
                "stone battlement": ([ "stone": 75, "wood": 25, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "stonemason": 10,
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "architect": 1,
            ]),
        ]),
        "components":([ 
            "KEEP    1":([
                "ascii": "+=======+",
                "unicode": "\u2554\u2550\u2550\u2550"
                    "\u2550\u2550\u2550\u2550\u2557",
            ]),
            "KEEP    2":([
                "ascii": "| +---+ |",
                "unicode": "\u2551 \u250f\u2501"
                    "\u2501\u2501\u2513 \u2551",
            ]),
            "KEEP    3":([
                "ascii": "| |   | |",
                "unicode": "\u2551 \u2503roof\u2591"
                    "\u2591\u2591default\u2503 \u2551",
            ]),
            "KEEP    4":([
                "ascii": "| +---+ |",
                "unicode": "\u2551 \u2517\u2501"
                    "\u2501\u2501\u251b \u2551",
            ]),
            "KEEP    5":([
                "ascii": "+=======+",
                "unicode": "\u255a\u2550\u2550\u2550"
                    "\u2550\u2550\u2550\u2550\u255d",
            ]),
        ]),
    ]),
]);

#endif
