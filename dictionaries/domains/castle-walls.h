//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef castleWalls_h
#define castleWalls_h

private mapping CastleWalls = ([
    "unbuilt western north wall":([
        "type": "western north wall",
        "display name": "Unbuilt Wall",
        "dimensions": "1x2",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;9m",
                "24-bit": "\x1b[0;38;2;200;0;0m"
            ]),
        ]),
        "components":([
            "NWMWAL": ([
                "ascii": "......",
                "unicode": "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7"
                    "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7",
            ]),
        ]),
    ]),

    "pallisade western north wall":([
        "type": "western north wall",
        "display name": "Wooden Pallisade",
        "dimensions": "1x2",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;36m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
        ]),
        "components":([
            "NWMWAL": ([
                "ascii": "======",
                "unicode": "\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x90",
            ]),
        ]),
    ]),

    "wooden rampart western north wall":([
        "type": "western north wall",
        "display name": "Wooden Rampart",
        "dimensions": "1x2",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;36m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
        ]),
        "components":([
            "NWMWAL": ([
                "ascii": "======",
                "unicode": "\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x90",
            ]),
        ]),
    ]),

    "stone western north wall":([
        "type": "western north wall",
        "display name": "Simple Stone Wall",
        "dimensions": "1x2",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;36m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
        ]),
        "components":([
            "NWMWAL": ([
                "ascii": "======",
                "unicode": "\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x90",
            ]),
        ]),
    ]),

    "western north bulwark":([
        "type": "western north wall",
        "display name": "Stone Bulwark",
        "dimensions": "1x2",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;36m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
        ]),
        "components":([
            "NWMWAL": ([
                "ascii": "======",
                "unicode": "\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x90",
            ]),
        ]),
    ]),

    "talus western north wall":([
        "type": "western north wall",
        "display name": "Stone Wall (Talus)",
        "dimensions": "1x2",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;36m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
        ]),
        "components":([
            "NWMWAL": ([
                "ascii": "======",
                "unicode": "\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x90",
            ]),
        ]),
    ]),

    "western north rampart":([
        "type": "western north wall",
        "display name": "Stone Rampart",
        "dimensions": "1x2",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;36m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
        ]),
        "components":([
            "NWMWAL": ([
                "ascii": "======",
                "unicode": "\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x90",
            ]),
        ]),
    ]),

    "western north bastion":([
        "type": "western north wall",
        "display name": "Stone Bastion",
        "dimensions": "1x2",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;36m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
        ]),
        "components":([
            "NWMWAL": ([
                "ascii": "======",
                "unicode": "\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x90",
            ]),
        ]),
    ]),

    "unbuilt eastern north wall":([
        "type": "eastern north wall",
        "display name": "Unbuilt Wall",
        "dimensions": "1x2",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;9m",
                "24-bit": "\x1b[0;38;2;200;0;0m"
            ]),
        ]),
        "components":([
            "NEMWAL": ([
                "ascii": "......",
                "unicode": "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7"
                    "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7",
            ]),
        ]),
    ]),

    "stone eastern north wall":([
        "type": "eastern north wall",
        "display name": "Simple Stone Wall",
        "dimensions": "1x2",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;36m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
        ]),
        "components":([
            "NEMWAL": ([
                "ascii": "======",
                "unicode": "\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x90",
            ]),
        ]),
    ]),

    "unbuilt western south wall":([
        "type": "western south wall",
        "display name": "Unbuilt Wall",
        "dimensions": "1x2",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;9m",
                "24-bit": "\x1b[0;38;2;200;0;0m"
            ]),
        ]),
        "components":([
            "SWMWAL": ([
                "ascii": "......",
                "unicode": "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7"
                    "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7",
            ]),
        ]),
    ]),

    "stone western south wall":([
        "type": "western south wall",
        "display name": "Simple Stone Wall",
        "dimensions": "1x2",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;36m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
        ]),
        "components":([
            "SWMWAL": ([
                "ascii": "======",
                "unicode": "\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x90",
            ]),
        ]),
    ]),

    "unbuilt eastern south wall":([
        "type": "eastern south wall",
        "display name": "Unbuilt Wall",
        "dimensions": "1x2",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;9m",
                "24-bit": "\x1b[0;38;2;200;0;0m"
            ]),
        ]),
        "components":([
            "SEMWAL": ([
                "ascii": "......",
                "unicode": "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7"
                    "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7",
            ]),
        ]),
    ]),

    "stone eastern south wall":([
        "type": "eastern south wall",
        "display name": "Simple Stone Wall",
        "dimensions": "1x2",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;36m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
        ]),
        "components":([
            "SEMWAL": ([
                "ascii": "======",
                "unicode": "\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x90",
            ]),
        ]),
    ]),

    "unbuilt northern west wall":([
        "type": "northern west wall",
        "display name": "Unbuilt Wall",
        "dimensions": "1x2",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;9m",
                "24-bit": "\x1b[0;38;2;200;0;0m"
            ]),
        ]),
        "components":([
            "NWI": ([
                "ascii": " . ",
                "unicode":  " \xe2\x88\xb7 ",
            ]),
        ]),
    ]),

    "stone northern west wall":([
        "type": "northern west wall",
        "display name": "Simple Stone Wall",
        "dimensions": "1x2",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;36m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
        ]),
        "components":([
            "NWI": ([
                "ascii": "  |",
                "unicode":  "  \xe2\x95\x91",
            ]),
        ]),
    ]),

    "unbuilt southern west wall":([
        "type": "southern west wall",
        "display name": "Unbuilt Wall",
        "dimensions": "1x2",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;9m",
                "24-bit": "\x1b[0;38;2;200;0;0m"
            ]),
        ]),
        "components":([
            "SWI": ([
                "ascii": " . ",
                "unicode":  " \xe2\x88\xb7 ",
            ]),
        ]),
    ]),

    "stone southern west wall":([
        "type": "southern west wall",
        "display name": "Simple Stone Wall",
        "dimensions": "1x2",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;36m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
        ]),
        "components":([
            "SWI": ([
                "ascii": "  |",
                "unicode":  "  \xe2\x95\x91",
            ]),
        ]),
    ]),

    "unbuilt northern east wall":([
        "type": "northern east wall",
        "display name": "Unbuilt Wall",
        "dimensions": "1x2",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;9m",
                "24-bit": "\x1b[0;38;2;200;0;0m"
            ]),
        ]),
        "components":([
            "NEI": ([
                "ascii": " . ",
                "unicode":  " \xe2\x88\xb7 ",
            ]),
        ]),
    ]),

    "stone northern east wall":([
        "type": "northern east wall",
        "display name": "Simple Stone Wall",
        "dimensions": "1x2",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;36m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
        ]),
        "components":([
            "NEI": ([
                "ascii": "|  ",
                "unicode":  "\xe2\x95\x91  ",
            ]),
        ]),
    ]),

    "unbuilt southern east wall":([
        "type": "southern east wall",
        "display name": "Unbuilt Wall",
        "dimensions": "1x2",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;9m",
                "24-bit": "\x1b[0;38;2;200;0;0m"
            ]),
        ]),
        "components":([
            "SEI": ([
                "ascii": " . ",
                "unicode":  " \xe2\x88\xb7 ",
            ]),
        ]),
    ]),

    "stone southern east wall":([
        "type": "southern east wall",
        "display name": "Simple Stone Wall",
        "dimensions": "1x2",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;36m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
        ]),
        "components":([
            "SEI": ([
                "ascii": "|  ",
                "unicode":  "\xe2\x95\x91  ",
            ]),
        ]),
    ]),

    "unbuilt western north castle wall":([
        "type": "western north castle wall",
        "display name": "Unbuilt Wall",
        "dimensions": "1x4",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;9m",
                "24-bit": "\x1b[0;38;2;200;0;0m"
            ]),
        ]),
        "components":([
            "NWCASTLEWALL": ([
                "ascii": "............",
                "unicode": "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7"
                    "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7"
                    "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7"
                    "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7",
            ]),
        ]),
    ]),

    "stone western north castle wall":([
        "type": "western north castle wall",
        "display name": "Simple Stone Wall",
        "dimensions": "1x4",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;36m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
        ]),
        "components":([
            "NWCASTLEWALL": ([
                "ascii": "============",
                "unicode": "\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90",
            ]),
        ]),
    ]),

    "unbuilt eastern north castle wall":([
        "type": "eastern north castle wall",
        "display name": "Unbuilt Wall",
        "dimensions": "1x4",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;9m",
                "24-bit": "\x1b[0;38;2;200;0;0m"
            ]),
        ]),
        "components":([
            "NECASTLEWALL": ([
                "ascii": "............",
                "unicode": "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7"
                    "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7"
                    "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7"
                    "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7",
            ]),
        ]),
    ]),

    "stone eastern north castle wall":([
        "type": "eastern north castle wall",
        "display name": "Simple Stone Wall",
        "dimensions": "1x4",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;36m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
        ]),
        "components":([
            "NECASTLEWALL": ([
                "ascii": "============",
                "unicode": "\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90",
            ]),
        ]),
    ]),

    "unbuilt western south castle wall":([
        "type": "western south castle wall",
        "display name": "Unbuilt Wall",
        "dimensions": "1x4",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;9m",
                "24-bit": "\x1b[0;38;2;200;0;0m"
            ]),
        ]),
        "components":([
            "SWCASTLEWALL": ([
                "ascii": "............",
                "unicode": "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7"
                    "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7"
                    "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7"
                    "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7",
            ]),
        ]),
    ]),

    "stone western south castle wall":([
        "type": "western south castle wall",
        "display name": "Simple Stone Wall",
        "dimensions": "1x4",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;36m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
        ]),
        "components":([
            "SWCASTLEWALL": ([
                "ascii": "============",
                "unicode": "\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90",
            ]),
        ]),
    ]),

    "unbuilt eastern south castle wall":([
        "type": "eastern south castle wall",
        "display name": "Unbuilt Wall",
        "dimensions": "1x4",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;9m",
                "24-bit": "\x1b[0;38;2;200;0;0m"
            ]),
        ]),
        "components":([
            "SECASTLEWALL": ([
                "ascii": "............",
                "unicode": "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7"
                    "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7"
                    "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7"
                    "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7",
            ]),
        ]),
    ]),

    "stone eastern south castle wall":([
        "type": "eastern south castle wall",
        "display name": "Simple Stone Wall",
        "dimensions": "1x4",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;36m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
        ]),
        "components":([
            "SECASTLEWALL": ([
                "ascii": "============",
                "unicode": "\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90",
            ]),
        ]),
    ]),

    "unbuilt northern west castle wall":([
        "type": "northern west castle wall",
        "display name": "Unbuilt Wall",
        "dimensions": "1x3",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;9m",
                "24-bit": "\x1b[0;38;2;200;0;0m"
            ]),
        ]),
        "components":([
            "NWX": ([
                "ascii": " . ",
                "unicode":  " \xe2\x88\xb7 ",
            ]),
        ]),
    ]),

    "stone northern west castle wall":([
        "type": "northern west castle wall",
        "display name": "Simple Stone Wall",
        "dimensions": "1x3",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;36m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
        ]),
        "components":([
            "NWX": ([
                "ascii": " | ",
                "unicode":  " \xe2\x95\x91 ",
            ]),
        ]),
    ]),

    "unbuilt southern west castle wall":([
        "type": "southern west castle wall",
        "display name": "Unbuilt Wall",
        "dimensions": "1x3",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;9m",
                "24-bit": "\x1b[0;38;2;200;0;0m"
            ]),
        ]),
        "components":([
            "SWX": ([
                "ascii": " . ",
                "unicode":  " \xe2\x88\xb7 ",
            ]),
        ]),
    ]),

    "stone southern west castle wall":([
        "type": "southern west castle wall",
        "display name": "Simple Stone Wall",
        "dimensions": "1x3",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;36m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
        ]),
        "components":([
            "SWX": ([
                "ascii": " | ",
                "unicode":  " \xe2\x95\x91 ",
            ]),
        ]),
    ]),

    "unbuilt northern east castle wall":([
        "type": "northern east castle wall",
        "display name": "Unbuilt Wall",
        "dimensions": "1x3",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;9m",
                "24-bit": "\x1b[0;38;2;200;0;0m"
            ]),
        ]),
        "components":([
            "NEX": ([
                "ascii": " . ",
                "unicode":  " \xe2\x88\xb7 ",
            ]),
        ]),
    ]),

    "stone northern east castle wall": ([
        "type": "northern east castle wall",
        "display name": "Simple Stone Wall",
        "dimensions": "1x3",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;36m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
        ]),
        "components":([
            "NEX": ([
                "ascii": " | ",
                "unicode":  " \xe2\x95\x91 ",
            ]),
        ]),
    ]),

    "unbuilt southern east castle wall":([
        "type": "southern east castle wall",
        "display name": "Unbuilt Wall",
        "dimensions": "1x3",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;9m",
                "24-bit": "\x1b[0;38;2;200;0;0m"
            ]),
        ]),
        "components":([
            "SEX": ([
                "ascii": " . ",
                "unicode":  " \xe2\x88\xb7 ",
            ]),
        ]),
    ]),

    "stone southern east castle wall":([
        "type": "southern east castle wall",
        "display name": "Simple Stone Wall",
        "dimensions": "1x3",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;36m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
        ]),
        "components":([
            "SEX": ([
                "ascii": " | ",
                "unicode":  " \xe2\x95\x91 ",
            ]),
        ]),
    ]),
]);

#endif
