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
        "construction": ([
            "duration": 100,
            "materials": ([
                "wooden wall": ([ "wood": 100, "metal": 5 ]),
            ]),
            "workers": ([
                "carpenter": 5,
                "foreman": 1,
                "blacksmith": 1,
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
        "construction": ([
            "duration": 200,
            "materials": ([
                "wooden wall": ([ "wood": 100, "metal": 5, "textile": 0 ]),
                "wooden battlement": ([ "wood":25, "metal": 5, "textile": 0 ]),
                "rampart": ([ "wood": 0, "stone": 0 ]),
            ]),
            "workers": ([
                "carpenter": 8,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 1,
                "engineer": 1,
                "architect": 1,
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
        "construction": ([
            "duration": 250,
            "materials": ([
                "stone wall": ([ "stone": 100, "wood": 10, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 8,
                "engineer": 1,
                "architect": 1,
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
        "construction": ([
            "duration": 360,
            "materials": ([
                "stone bulwark": ([ "stone": 250, "wood": 50, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 10,
                "engineer": 1,
                "architect": 1,
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
        "construction": ([
            "duration": 400,
            "materials": ([
                "stone talus": ([ "stone": 300, "wood": 50, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 10,
                "engineer": 1,
                "architect": 1,
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
        "construction": ([
            "duration": 360,
            "materials": ([
                "stone bulwark": ([ "stone": 250, "wood": 50, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
                "rampart": ([ "stone": 0, "wood": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 10,
                "engineer": 1,
                "architect": 1,
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
        "construction": ([
            "duration": 480,
            "materials": ([
                "stone wall": ([ "stone": 100, "wood": 10, "metal": 5, "textile": 0 ]),
                "stone bulwark": ([ "stone": 450, "wood": 50, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
                "rampart": ([ "stone": 0, "wood": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 10,
                "engineer": 1,
                "architect": 1,
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

    "pallisade eastern north wall":([
        "type": "eastern north wall",
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
        "construction": ([
            "duration": 100,
            "materials": ([
                "wooden wall": ([ "wood": 100, "metal": 5 ]),
            ]),
            "workers": ([
                "carpenter": 5,
                "foreman": 1,
                "blacksmith": 1,
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

    "wooden rampart eastern north wall":([
        "type": "eastern north wall",
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
        "construction": ([
            "duration": 200,
            "materials": ([
                "wooden wall": ([ "wood": 100, "metal": 5, "textile": 0 ]),
                "wooden battlement": ([ "wood":25, "metal": 5, "textile": 0 ]),
                "rampart": ([ "stone": 0, "wood": 0 ]),
            ]),
            "workers": ([
                "carpenter": 8,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 1,
                "engineer": 1,
                "architect": 1,
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
        "construction": ([
            "duration": 250,
            "materials": ([
                "stone wall": ([ "stone": 100, "wood": 10, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
                "rampart": ([ "stone": 0, "wood": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 8,
                "engineer": 1,
                "architect": 1,
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

    "eastern north bulwark":([
        "type": "eastern north wall",
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
        "construction": ([
            "duration": 360,
            "materials": ([
                "stone bulwark": ([ "stone": 250, "wood": 50, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 10,
                "engineer": 1,
                "architect": 1,
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

    "talus eastern north wall":([
        "type": "eastern north wall",
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
        "construction": ([
            "duration": 400,
            "materials": ([
                "stone talus": ([ "stone": 300, "wood": 50, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 10,
                "engineer": 1,
                "architect": 1,
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

    "eastern north rampart":([
        "type": "eastern north wall",
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
        "construction": ([
            "duration": 360,
            "materials": ([
                "stone bulwark": ([ "stone": 250, "wood": 50, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
                "rampart": ([ "stone": 0, "wood": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 10,
                "engineer": 1,
                "architect": 1,
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

    "eastern north bastion":([
        "type": "eastern north wall",
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
        "construction": ([
            "duration": 480,
            "materials": ([
                "stone wall": ([ "stone": 100, "wood": 10, "metal": 5, "textile": 0 ]),
                "stone bulwark": ([ "stone": 450, "wood": 50, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
                "rampart": ([ "stone": 0, "wood": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 10,
                "engineer": 1,
                "architect": 1,
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

    "pallisade western south wall":([
        "type": "western south wall",
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
        "construction": ([
            "duration": 100,
            "materials": ([
                "wooden wall": ([ "wood": 100, "metal": 5 ]),
            ]),
            "workers": ([
                "carpenter": 5,
                "foreman": 1,
                "blacksmith": 1,
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

    "wooden rampart western south wall":([
        "type": "western south wall",
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
        "construction": ([
            "duration": 200,
            "materials": ([
                "wooden wall": ([ "wood": 100, "metal": 5, "textile": 0 ]),
                "wooden battlement": ([ "wood":25, "metal": 5, "textile": 0 ]),
                "rampart": ([ "stone": 0, "wood": 0 ]),
            ]),
            "workers": ([
                "carpenter": 8,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 1,
                "engineer": 1,
                "architect": 1,
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
        "construction": ([
            "duration": 250,
            "materials": ([
                "stone wall": ([ "stone": 100, "wood": 10, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
                "rampart": ([ "stone": 0, "wood": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 8,
                "engineer": 1,
                "architect": 1,
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

    "western south bulwark":([
        "type": "western south wall",
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
        "construction": ([
            "duration": 360,
            "materials": ([
                "stone bulwark": ([ "stone": 250, "wood": 50, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 10,
                "engineer": 1,
                "architect": 1,
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

    "talus western south wall":([
        "type": "western south wall",
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
        "construction": ([
            "duration": 400,
            "materials": ([
                "stone talus": ([ "stone": 300, "wood": 50, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 10,
                "engineer": 1,
                "architect": 1,
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

    "western south rampart":([
        "type": "western south wall",
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
        "construction": ([
            "duration": 360,
            "materials": ([
                "stone bulwark": ([ "stone": 250, "wood": 50, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
                "rampart": ([ "stone": 0, "wood": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 10,
                "engineer": 1,
                "architect": 1,
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

    "western south bastion":([
        "type": "western south wall",
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
        "construction": ([
            "duration": 360,
            "materials": ([
                "stone wall": ([ "stone": 100, "wood": 10, "metal": 5, "textile": 0 ]),
                "stone bulwark": ([ "stone": 250, "wood": 50, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
                "rampart": ([ "stone": 0, "wood": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 10,
                "engineer": 1,
                "architect": 1,
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

    "pallisade eastern south wall":([
        "type": "eastern south wall",
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
        "construction": ([
            "duration": 100,
            "materials": ([
                "wooden wall": ([ "wood": 100, "metal": 5 ]),
            ]),
            "workers": ([
                "carpenter": 5,
                "foreman": 1,
                "blacksmith": 1,
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

    "wooden rampart eastern south wall":([
        "type": "eastern south wall",
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
        "construction": ([
            "duration": 200,
            "materials": ([
                "wooden wall": ([ "wood": 100, "metal": 5, "textile": 0 ]),
                "wooden battlement": ([ "wood":25, "metal": 5, "textile": 0 ]),
                "rampart": ([ "stone": 0, "wood": 0 ]),
            ]),
            "workers": ([
                "carpenter": 8,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 1,
                "engineer": 1,
                "architect": 1,
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
        "construction": ([
            "duration": 250,
            "materials": ([
                "stone wall": ([ "stone": 100, "wood": 10, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
                "rampart": ([ "stone": 0, "wood": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 8,
                "engineer": 1,
                "architect": 1,
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

    "eastern south bulwark":([
        "type": "eastern south wall",
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
        "construction": ([
            "duration": 360,
            "materials": ([
                "stone bulwark": ([ "stone": 250, "wood": 50, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 10,
                "engineer": 1,
                "architect": 1,
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

    "talus eastern south wall":([
        "type": "eastern south wall",
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
        "construction": ([
            "duration": 400,
            "materials": ([
                "stone talus": ([ "stone": 300, "wood": 50, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 10,
                "engineer": 1,
                "architect": 1,
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

    "eastern south rampart":([
        "type": "eastern south wall",
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
        "construction": ([
            "duration": 360,
            "materials": ([
                "stone bulwark": ([ "stone": 250, "wood": 50, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
                "rampart": ([ "stone": 0, "wood": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 10,
                "engineer": 1,
                "architect": 1,
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

    "eastern south bastion":([
        "type": "eastern south wall",
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
        "construction": ([
            "duration": 360,
            "materials": ([
                "stone wall": ([ "stone": 100, "wood": 10, "metal": 5, "textile": 0 ]),
                "stone bulwark": ([ "stone": 250, "wood": 50, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
                "rampart": ([ "stone": 0, "wood": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 10,
                "engineer": 1,
                "architect": 1,
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

    "pallisade northern west wall":([
        "type": "northern west wall",
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
        "construction": ([
            "duration": 100,
            "materials": ([
                "wooden wall": ([ "wood": 100, "metal": 5 ]),
            ]),
            "workers": ([
                "carpenter": 5,
                "foreman": 1,
                "blacksmith": 1,
            ]),
        ]),
        "components":([
            "NWI": ([
                "ascii": "  |",
                "unicode":  "  \xe2\x95\x91",
            ]),
        ]),
    ]),

    "wooden rampart northern west wall":([
        "type": "northern west wall",
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
        "construction": ([
            "duration": 200,
            "materials": ([
                "wooden wall": ([ "wood": 100, "metal": 5, "textile": 0 ]),
                "wooden battlement": ([ "wood":25, "metal": 5, "textile": 0 ]),
                "rampart": ([ "stone": 0, "wood": 0 ]),
            ]),
            "workers": ([
                "carpenter": 8,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 1,
                "engineer": 1,
                "architect": 1,
            ]),
        ]),
        "components":([
            "NWI": ([
                "ascii": " | ",
                "unicode":  "  \xe2\x95\x91",
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
        "construction": ([
            "duration": 250,
            "materials": ([
                "stone wall": ([ "stone": 100, "wood": 10, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 8,
                "engineer": 1,
                "architect": 1,
            ]),
        ]),
        "components":([
            "NWI": ([
                "ascii": " | ",
                "unicode":  "  \xe2\x95\x91",
            ]),
        ]),
    ]),

    "northern west bulwark":([
        "type": "northern west wall",
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
        "construction": ([
            "duration": 360,
            "materials": ([
                "stone bulwark": ([ "stone": 250, "wood": 50, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 10,
                "engineer": 1,
                "architect": 1,
            ]),
        ]),
        "components":([
            "NWI": ([
                "ascii": " | ",
                "unicode":  "  \xe2\x95\x91",
            ]),
        ]),
    ]),

    "talus northern west wall":([
        "type": "northern west wall",
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
        "construction": ([
            "duration": 400,
            "materials": ([
                "stone talus": ([ "stone": 300, "wood": 50, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 10,
                "engineer": 1,
                "architect": 1,
            ]),
        ]),
        "components":([
            "NWI": ([
                "ascii": " | ",
                "unicode":  "  \xe2\x95\x91",
            ]),
        ]),
    ]),

    "northern west rampart":([
        "type": "northern west wall",
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
        "construction": ([
            "duration": 360,
            "materials": ([
                "stone bulwark": ([ "stone": 250, "wood": 50, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
                "rampart": ([ "stone": 0, "wood": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 10,
                "engineer": 1,
                "architect": 1,
            ]),
        ]),
        "components":([
            "NWI": ([
                "ascii": " | ",
                "unicode":  "  \xe2\x95\x91",
            ]),
        ]),
    ]),

    "northern west bastion":([
        "type": "northern west wall",
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
        "construction": ([
            "duration": 480,
            "materials": ([
                "stone wall": ([ "stone": 100, "wood": 10, "metal": 5, "textile": 0 ]),
                "stone bulwark": ([ "stone": 450, "wood": 50, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
                "rampart": ([ "stone": 0, "wood": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 10,
                "engineer": 1,
                "architect": 1,
            ]),
        ]),
        "components":([
            "NWI": ([
                "ascii": " | ",
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

    "pallisade southern west wall":([
        "type": "southern west wall",
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
        "construction": ([
            "duration": 100,
            "materials": ([
                "wooden wall": ([ "wood": 100, "metal": 5 ]),
            ]),
            "workers": ([
                "carpenter": 5,
                "foreman": 1,
                "blacksmith": 1,
            ]),
        ]),
        "components":([
            "SWI": ([
                "ascii": " | ",
                "unicode":  "  \xe2\x95\x91",
            ]),
        ]),
    ]),

    "wooden rampart southern west wall":([
        "type": "southern west wall",
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
        "construction": ([
            "duration": 200,
            "materials": ([
                "wooden wall": ([ "wood": 100, "metal": 5, "textile": 0 ]),
                "wooden battlement": ([ "wood":25, "metal": 5, "textile": 0 ]),
                "rampart": ([ "stone": 0, "wood": 0 ]),
            ]),
            "workers": ([
                "carpenter": 8,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 1,
                "engineer": 1,
                "architect": 1,
            ]),
        ]),
        "components":([
            "SWI": ([
                "ascii": " | ",
                "unicode":  "  \xe2\x95\x91",
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
        "construction": ([
            "duration": 250,
            "materials": ([
                "stone wall": ([ "stone": 100, "wood": 10, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 8,
                "engineer": 1,
                "architect": 1,
            ]),
        ]),
        "components":([
            "SWI": ([
                "ascii": " | ",
                "unicode":  "  \xe2\x95\x91",
            ]),
        ]),
    ]),

    "southern west bulwark":([
        "type": "southern west wall",
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
        "construction": ([
            "duration": 360,
            "materials": ([
                "stone bulwark": ([ "stone": 250, "wood": 50, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 10,
                "engineer": 1,
                "architect": 1,
            ]),
        ]),
        "components":([
            "SWI": ([
                "ascii": " | ",
                "unicode":  "  \xe2\x95\x91",
            ]),
        ]),
    ]),

    "talus southern west wall":([
        "type": "southern west wall",
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
        "construction": ([
            "duration": 400,
            "materials": ([
                "stone talus": ([ "stone": 300, "wood": 50, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 10,
                "engineer": 1,
                "architect": 1,
            ]),
        ]),
        "components":([
            "SWI": ([
                "ascii": " | ",
                "unicode":  "  \xe2\x95\x91",
            ]),
        ]),
    ]),

    "southern west rampart":([
        "type": "southern west wall",
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
        "construction": ([
            "duration": 360,
            "materials": ([
                "stone bulwark": ([ "stone": 250, "wood": 50, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
                "rampart": ([ "stone": 0, "wood": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 10,
                "engineer": 1,
                "architect": 1,
            ]),
        ]),
        "components":([
            "SWI": ([
                "ascii": " | ",
                "unicode":  "  \xe2\x95\x91",
            ]),
        ]),
    ]),

    "southern west bastion":([
        "type": "southern west wall",
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
        "construction": ([
            "duration": 480,
            "materials": ([
                "stone wall": ([ "stone": 100, "wood": 10, "metal": 5, "textile": 0 ]),
                "stone bulwark": ([ "stone": 450, "wood": 50, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
                "rampart": ([ "stone": 0, "wood": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 10,
                "engineer": 1,
                "architect": 1,
            ]),
        ]),
        "components":([
            "SWI": ([
                "ascii": " | ",
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

    "pallisade northern east wall":([
        "type": "northern east wall",
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
        "construction": ([
            "duration": 100,
            "materials": ([
                "wooden wall": ([ "wood": 100, "metal": 5 ]),
            ]),
            "workers": ([
                "carpenter": 5,
                "foreman": 1,
                "blacksmith": 1,
            ]),
        ]),
        "components":([
            "NEI": ([
                "ascii": " | ",
                "unicode":  "\xe2\x95\x91  ",
            ]),
        ]),
    ]),

    "wooden rampart northern east wall":([
        "type": "northern east wall",
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
        "construction": ([
            "duration": 200,
            "materials": ([
                "wooden wall": ([ "wood": 100, "metal": 5, "textile": 0 ]),
                "wooden battlement": ([ "wood":25, "metal": 5, "textile": 0 ]),
                "rampart": ([ "stone": 0, "wood": 0 ]),
            ]),
            "workers": ([
                "carpenter": 8,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 1,
                "engineer": 1,
                "architect": 1,
            ]),
        ]),
        "components":([
            "NEI": ([
                "ascii": " | ",
                "unicode":  "\xe2\x95\x91  ",
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
        "construction": ([
            "duration": 250,
            "materials": ([
                "stone wall": ([ "stone": 100, "wood": 10, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 8,
                "engineer": 1,
                "architect": 1,
            ]),
        ]),
        "components":([
            "NEI": ([
                "ascii": " | ",
                "unicode":  "\xe2\x95\x91  ",
            ]),
        ]),
    ]),

    "northern east bulwark":([
        "type": "northern east wall",
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
        "construction": ([
            "duration": 360,
            "materials": ([
                "stone bulwark": ([ "stone": 250, "wood": 50, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 10,
                "engineer": 1,
                "architect": 1,
            ]),
        ]),
        "components":([
            "NEI": ([
                "ascii": " | ",
                "unicode":  "\xe2\x95\x91  ",
            ]),
        ]),
    ]),

    "talus northern east wall":([
        "type": "northern east wall",
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
        "construction": ([
            "duration": 400,
            "materials": ([
                "stone talus": ([ "stone": 300, "wood": 50, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 10,
                "engineer": 1,
                "architect": 1,
            ]),
        ]),
        "components":([
            "NEI": ([
                "ascii": " | ",
                "unicode":  "\xe2\x95\x91  ",
            ]),
        ]),
    ]),

    "northern east rampart":([
        "type": "northern east wall",
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
        "construction": ([
            "duration": 360,
            "materials": ([
                "stone bulwark": ([ "stone": 250, "wood": 50, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
                "rampart": ([ "stone": 0, "wood": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 10,
                "engineer": 1,
                "architect": 1,
            ]),
        ]),
        "components":([
            "NEI": ([
                "ascii": " | ",
                "unicode":  "\xe2\x95\x91  ",
            ]),
        ]),
    ]),

    "northern east bastion":([
        "type": "northern east wall",
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
        "construction": ([
            "duration": 480,
            "materials": ([
                "stone wall": ([ "stone": 100, "wood": 10, "metal": 5, "textile": 0 ]),
                "stone bulwark": ([ "stone": 450, "wood": 50, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
                "rampart": ([ "stone": 0, "wood": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 10,
                "engineer": 1,
                "architect": 1,
            ]),
        ]),
        "components":([
            "NEI": ([
                "ascii": " | ",
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

    "pallisade southern east wall":([
        "type": "southern east wall",
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
        "construction": ([
            "duration": 100,
            "materials": ([
                "wooden wall": ([ "wood": 100, "metal": 5 ]),
            ]),
            "workers": ([
                "carpenter": 5,
                "foreman": 1,
                "blacksmith": 1,
            ]),
        ]),
        "components":([
            "SEI": ([
                "ascii": " | ",
                "unicode":  "\xe2\x95\x91  ",
            ]),
        ]),
    ]),

    "wooden rampart southern east wall":([
        "type": "southern east wall",
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
        "construction": ([
            "duration": 200,
            "materials": ([
                "wooden wall": ([ "wood": 100, "metal": 5, "textile": 0 ]),
                "wooden battlement": ([ "wood":25, "metal": 5, "textile": 0 ]),
                "rampart": ([ "stone": 0, "wood": 0 ]),
            ]),
            "workers": ([
                "carpenter": 8,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 1,
                "engineer": 1,
                "architect": 1,
            ]),
        ]),
        "components":([
            "SEI": ([
                "ascii": " | ",
                "unicode":  "\xe2\x95\x91  ",
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
        "construction": ([
            "duration": 250,
            "materials": ([
                "stone wall": ([ "stone": 100, "wood": 10, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 8,
                "engineer": 1,
                "architect": 1,
            ]),
        ]),
        "components":([
            "SEI": ([
                "ascii": " | ",
                "unicode":  "\xe2\x95\x91  ",
            ]),
        ]),
    ]),

    "southern east bulwark":([
        "type": "southern east wall",
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
        "construction": ([
            "duration": 360,
            "materials": ([
                "stone bulwark": ([ "stone": 250, "wood": 50, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 10,
                "engineer": 1,
                "architect": 1,
            ]),
        ]),
        "components":([
            "SEI": ([
                "ascii": " | ",
                "unicode":  "\xe2\x95\x91  ",
            ]),
        ]),
    ]),

    "talus southern east wall":([
        "type": "southern east wall",
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
        "construction": ([
            "duration": 400,
            "materials": ([
                "stone talus": ([ "stone": 300, "wood": 50, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 10,
                "engineer": 1,
                "architect": 1,
            ]),
        ]),
        "components":([
            "SEI": ([
                "ascii": " | ",
                "unicode":  "\xe2\x95\x91  ",
            ]),
        ]),
    ]),

    "southern east rampart":([
        "type": "southern east wall",
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
        "construction": ([
            "duration": 360,
            "materials": ([
                "stone bulwark": ([ "stone": 250, "wood": 50, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
                "rampart": ([ "stone": 0, "wood": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 10,
                "engineer": 1,
                "architect": 1,
            ]),
        ]),
        "components":([
            "SEI": ([
                "ascii": " | ",
                "unicode":  "\xe2\x95\x91  ",
            ]),
        ]),
    ]),

    "southern east bastion":([
        "type": "southern east wall",
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
        "construction": ([
            "duration": 480,
            "materials": ([
                "stone wall": ([ "stone": 100, "wood": 10, "metal": 5, "textile": 0 ]),
                "stone bulwark": ([ "stone": 450, "wood": 50, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
                "rampart": ([ "stone": 0, "wood": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 10,
                "engineer": 1,
                "architect": 1,
            ]),
        ]),
        "components":([
            "SEI": ([
                "ascii": " | ",
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

    "pallisade western north castle wall":([
        "type": "western north castle wall",
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
        "construction": ([
            "duration": 100,
            "materials": ([
                "wooden wall": ([ "wood": 100, "metal": 5 ]),
            ]),
            "workers": ([
                "carpenter": 5,
                "foreman": 1,
                "blacksmith": 1,
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

    "wooden rampart western north castle wall":([
        "type": "western north castle wall",
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
        "construction": ([
            "duration": 200,
            "materials": ([
                "wooden wall": ([ "wood": 100, "metal": 5, "textile": 0 ]),
                "wooden battlement": ([ "wood":25, "metal": 5, "textile": 0 ]),
                "rampart": ([ "stone": 0, "wood": 0 ]),
            ]),
            "workers": ([
                "carpenter": 8,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 1,
                "engineer": 1,
                "architect": 1,
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

    "stone western north castle wall":([
        "type": "western north castle wall",
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
        "construction": ([
            "duration": 250,
            "materials": ([
                "stone wall": ([ "stone": 100, "wood": 10, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 8,
                "engineer": 1,
                "architect": 1,
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

    "western north castle bulwark":([
        "type": "western north castle wall",
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
        "construction": ([
            "duration": 360,
            "materials": ([
                "stone bulwark": ([ "stone": 250, "wood": 50, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 10,
                "engineer": 1,
                "architect": 1,
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

    "talus western north castle wall":([
        "type": "western north castle wall",
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
        "construction": ([
            "duration": 400,
            "materials": ([
                "stone talus": ([ "stone": 300, "wood": 50, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 10,
                "engineer": 1,
                "architect": 1,
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

    "western north castle rampart":([
        "type": "western north castle wall",
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
        "construction": ([
            "duration": 360,
            "materials": ([
                "stone bulwark": ([ "stone": 250, "wood": 50, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
                "rampart": ([ "stone": 0, "wood": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 10,
                "engineer": 1,
                "architect": 1,
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

    "western north castle bastion":([
        "type": "western north castle wall",
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
        "construction": ([
            "duration": 480,
            "materials": ([
                "stone wall": ([ "stone": 100, "wood": 10, "metal": 5, "textile": 0 ]),
                "stone bulwark": ([ "stone": 450, "wood": 50, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
                "rampart": ([ "stone": 0, "wood": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 10,
                "engineer": 1,
                "architect": 1,
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

    "pallisade eastern north castle wall":([
        "type": "eastern north castle wall",
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
        "construction": ([
            "duration": 100,
            "materials": ([
                "wooden wall": ([ "wood": 100, "metal": 5 ]),
            ]),
            "workers": ([
                "carpenter": 5,
                "foreman": 1,
                "blacksmith": 1,
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

    "wooden rampart eastern north castle wall":([
        "type": "eastern north castle wall",
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
        "construction": ([
            "duration": 200,
            "materials": ([
                "wooden wall": ([ "wood": 100, "metal": 5, "textile": 0 ]),
                "wooden battlement": ([ "wood":25, "metal": 5, "textile": 0 ]),
                "rampart": ([ "stone": 0, "wood": 0 ]),
            ]),
            "workers": ([
                "carpenter": 8,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 1,
                "engineer": 1,
                "architect": 1,
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

    "stone eastern north castle wall":([
        "type": "eastern north castle wall",
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
        "construction": ([
            "duration": 250,
            "materials": ([
                "stone wall": ([ "stone": 100, "wood": 10, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 8,
                "engineer": 1,
                "architect": 1,
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

    "eastern north castle bulwark":([
        "type": "eastern north castle wall",
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
        "construction": ([
            "duration": 360,
            "materials": ([
                "stone bulwark": ([ "stone": 250, "wood": 50, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 10,
                "engineer": 1,
                "architect": 1,
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

    "talus eastern north castle wall":([
        "type": "eastern north castle wall",
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
        "construction": ([
            "duration": 400,
            "materials": ([
                "stone talus": ([ "stone": 300, "wood": 50, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 10,
                "engineer": 1,
                "architect": 1,
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

    "eastern north castle rampart":([
        "type": "eastern north castle wall",
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
        "construction": ([
            "duration": 360,
            "materials": ([
                "stone bulwark": ([ "stone": 250, "wood": 50, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
                "rampart": ([ "stone": 0, "wood": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 10,
                "engineer": 1,
                "architect": 1,
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

    "eastern north castle bastion":([
        "type": "eastern north castle wall",
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
        "construction": ([
            "duration": 480,
            "materials": ([
                "stone wall": ([ "stone": 100, "wood": 10, "metal": 5, "textile": 0 ]),
                "stone bulwark": ([ "stone": 450, "wood": 50, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
                "rampart": ([ "stone": 0, "wood": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 10,
                "engineer": 1,
                "architect": 1,
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

    "pallisade western south castle wall":([
        "type": "western south castle wall",
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
        "construction": ([
            "duration": 100,
            "materials": ([
                "wooden wall": ([ "wood": 100, "metal": 5 ]),
            ]),
            "workers": ([
                "carpenter": 5,
                "foreman": 1,
                "blacksmith": 1,
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

    "wooden rampart western south castle wall":([
        "type": "western south castle wall",
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
        "construction": ([
            "duration": 200,
            "materials": ([
                "wooden wall": ([ "wood": 100, "metal": 5, "textile": 0 ]),
                "wooden battlement": ([ "wood":25, "metal": 5, "textile": 0 ]),
                "rampart": ([ "stone": 0, "wood": 0 ]),
            ]),
            "workers": ([
                "carpenter": 8,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 1,
                "engineer": 1,
                "architect": 1,
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

    "stone western south castle wall":([
        "type": "western south castle wall",
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
        "construction": ([
            "duration": 250,
            "materials": ([
                "stone wall": ([ "stone": 100, "wood": 10, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 8,
                "engineer": 1,
                "architect": 1,
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

    "western south castle bulwark":([
        "type": "western south castle wall",
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
        "construction": ([
            "duration": 360,
            "materials": ([
                "stone bulwark": ([ "stone": 250, "wood": 50, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 10,
                "engineer": 1,
                "architect": 1,
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

    "talus western south castle wall":([
        "type": "western south castle wall",
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
        "construction": ([
            "duration": 400,
            "materials": ([
                "stone talus": ([ "stone": 300, "wood": 50, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 10,
                "engineer": 1,
                "architect": 1,
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

    "western south castle rampart":([
        "type": "western south castle wall",
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
        "construction": ([
            "duration": 360,
            "materials": ([
                "stone bulwark": ([ "stone": 250, "wood": 50, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
                "rampart": ([ "stone": 0, "wood": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 10,
                "engineer": 1,
                "architect": 1,
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

    "western south castle bastion":([
        "type": "western south castle wall",
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
        "construction": ([
            "duration": 480,
            "materials": ([
                "stone wall": ([ "stone": 100, "wood": 10, "metal": 5, "textile": 0 ]),
                "stone bulwark": ([ "stone": 450, "wood": 50, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
                "rampart": ([ "stone": 0, "wood": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 10,
                "engineer": 1,
                "architect": 1,
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

    "pallisade eastern south castle wall":([
        "type": "eastern south castle wall",
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
        "construction": ([
            "duration": 100,
            "materials": ([
                "wooden wall": ([ "wood": 100, "metal": 5 ]),
            ]),
            "workers": ([
                "carpenter": 5,
                "foreman": 1,
                "blacksmith": 1,
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

    "wooden rampart eastern south castle wall":([
        "type": "eastern south castle wall",
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
        "construction": ([
            "duration": 200,
            "materials": ([
                "wooden wall": ([ "wood": 100, "metal": 5, "textile": 0 ]),
                "wooden battlement": ([ "wood":25, "metal": 5, "textile": 0 ]),
                "rampart": ([ "stone": 0, "wood": 0 ]),
            ]),
            "workers": ([
                "carpenter": 8,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 1,
                "engineer": 1,
                "architect": 1,
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

    "stone eastern south castle wall":([
        "type": "eastern south castle wall",
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
        "construction": ([
            "duration": 250,
            "materials": ([
                "stone wall": ([ "stone": 100, "wood": 10, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 8,
                "engineer": 1,
                "architect": 1,
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

    "eastern south castle bulwark":([
        "type": "eastern south castle wall",
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
        "construction": ([
            "duration": 360,
            "materials": ([
                "stone bulwark": ([ "stone": 250, "wood": 50, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 10,
                "engineer": 1,
                "architect": 1,
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

    "talus eastern south castle wall":([
        "type": "eastern south castle wall",
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
        "construction": ([
            "duration": 400,
            "materials": ([
                "stone talus": ([ "stone": 300, "wood": 50, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 10,
                "engineer": 1,
                "architect": 1,
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

    "eastern south castle rampart":([
        "type": "eastern south castle wall",
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
        "construction": ([
            "duration": 360,
            "materials": ([
                "stone bulwark": ([ "stone": 250, "wood": 50, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
                "rampart": ([ "stone": 0, "wood": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 10,
                "engineer": 1,
                "architect": 1,
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

    "eastern south castle bastion":([
        "type": "eastern south castle wall",
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
        "construction": ([
            "duration": 480,
            "materials": ([
                "stone wall": ([ "stone": 100, "wood": 10, "metal": 5, "textile": 0 ]),
                "stone bulwark": ([ "stone": 450, "wood": 50, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
                "rampart": ([ "stone": 0, "wood": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 10,
                "engineer": 1,
                "architect": 1,
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

    "pallisade northern west castle wall":([
        "type": "northern west castle wall",
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
        "construction": ([
            "duration": 100,
            "materials": ([
                "wooden wall": ([ "wood": 100, "metal": 5 ]),
            ]),
            "workers": ([
                "carpenter": 5,
                "foreman": 1,
                "blacksmith": 1,
            ]),
        ]),
        "components":([
            "NWX": ([
                "ascii": " | ",
                "unicode":  " \xe2\x95\x91 ",
            ]),
        ]),
    ]),

    "wooden rampart northern west castle wall":([
        "type": "northern west castle wall",
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
        "construction": ([
            "duration": 200,
            "materials": ([
                "wooden wall": ([ "wood": 100, "metal": 5, "textile": 0 ]),
                "wooden battlement": ([ "wood":25, "metal": 5, "textile": 0 ]),
                "rampart": ([ "stone": 0, "wood": 0 ]),
            ]),
            "workers": ([
                "carpenter": 8,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 1,
                "engineer": 1,
                "architect": 1,
            ]),
        ]),
        "components":([
            "NWX": ([
                "ascii": " | ",
                "unicode":  " \xe2\x95\x91 ",
            ]),
        ]),
    ]),

    "stone northern west castle wall":([
        "type": "northern west castle wall",
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
        "construction": ([
            "duration": 250,
            "materials": ([
                "stone wall": ([ "stone": 100, "wood": 10, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 8,
                "engineer": 1,
                "architect": 1,
            ]),
        ]),
        "components":([
            "NWX": ([
                "ascii": " | ",
                "unicode":  " \xe2\x95\x91 ",
            ]),
        ]),
    ]),

    "northern west castle bulwark":([
        "type": "northern west castle wall",
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
        "construction": ([
            "duration": 360,
            "materials": ([
                "stone bulwark": ([ "stone": 250, "wood": 50, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 10,
                "engineer": 1,
                "architect": 1,
            ]),
        ]),
        "components":([
            "NWX": ([
                "ascii": " | ",
                "unicode":  " \xe2\x95\x91 ",
            ]),
        ]),
    ]),

    "talus northern west castle wall":([
        "type": "northern west castle wall",
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
        "construction": ([
            "duration": 400,
            "materials": ([
                "stone talus": ([ "stone": 300, "wood": 50, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 10,
                "engineer": 1,
                "architect": 1,
            ]),
        ]),
        "components":([
            "NWX": ([
                "ascii": " | ",
                "unicode":  " \xe2\x95\x91 ",
            ]),
        ]),
    ]),

    "northern west castle rampart":([
        "type": "northern west castle wall",
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
        "construction": ([
            "duration": 360,
            "materials": ([
                "stone bulwark": ([ "stone": 250, "wood": 50, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
                "rampart": ([ "stone": 0, "wood": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 10,
                "engineer": 1,
                "architect": 1,
            ]),
        ]),
        "components":([
            "NWX": ([
                "ascii": " | ",
                "unicode":  " \xe2\x95\x91 ",
            ]),
        ]),
    ]),

    "northern west castle bastion":([
        "type": "northern west castle wall",
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
        "construction": ([
            "duration": 480,
            "materials": ([
                "stone wall": ([ "stone": 100, "wood": 10, "metal": 5, "textile": 0 ]),
                "stone bulwark": ([ "stone": 450, "wood": 50, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
                "rampart": ([ "stone": 0, "wood": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 10,
                "engineer": 1,
                "architect": 1,
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

    "pallisade southern west castle wall":([
        "type": "southern west castle wall",
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
        "construction": ([
            "duration": 100,
            "materials": ([
                "wooden wall": ([ "wood": 100, "metal": 5 ]),
            ]),
            "workers": ([
                "carpenter": 5,
                "foreman": 1,
                "blacksmith": 1,
            ]),
        ]),
        "components":([
            "SWX": ([
                "ascii": " | ",
                "unicode":  " \xe2\x95\x91 ",
            ]),
        ]),
    ]),

    "wooden rampart southern west castle wall":([
        "type": "southern west castle wall",
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
        "construction": ([
            "duration": 200,
            "materials": ([
                "wooden wall": ([ "wood": 100, "metal": 5, "textile": 0 ]),
                "wooden battlement": ([ "wood":25, "metal": 5, "textile": 0 ]),
                "rampart": ([ "stone": 0, "wood": 0 ]),
            ]),
            "workers": ([
                "carpenter": 8,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 1,
                "engineer": 1,
                "architect": 1,
            ]),
        ]),
        "components":([
            "SWX": ([
                "ascii": " | ",
                "unicode":  " \xe2\x95\x91 ",
            ]),
        ]),
    ]),

    "stone southern west castle wall":([
        "type": "southern west castle wall",
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
        "construction": ([
            "duration": 250,
            "materials": ([
                "stone wall": ([ "stone": 100, "wood": 10, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 8,
                "engineer": 1,
                "architect": 1,
            ]),
        ]),
        "components":([
            "SWX": ([
                "ascii": " | ",
                "unicode":  " \xe2\x95\x91 ",
            ]),
        ]),
    ]),

    "southern west castle bulwark":([
        "type": "southern west castle wall",
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
        "construction": ([
            "duration": 360,
            "materials": ([
                "stone bulwark": ([ "stone": 250, "wood": 50, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 10,
                "engineer": 1,
                "architect": 1,
            ]),
        ]),
        "components":([
            "SWX": ([
                "ascii": " | ",
                "unicode":  " \xe2\x95\x91 ",
            ]),
        ]),
    ]),

    "talus southern west castle wall":([
        "type": "southern west castle wall",
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
        "construction": ([
            "duration": 400,
            "materials": ([
                "stone talus": ([ "stone": 300, "wood": 50, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 10,
                "engineer": 1,
                "architect": 1,
            ]),
        ]),
        "components":([
            "SWX": ([
                "ascii": " | ",
                "unicode":  " \xe2\x95\x91 ",
            ]),
        ]),
    ]),

    "southern west castle rampart":([
        "type": "southern west castle wall",
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
        "construction": ([
            "duration": 360,
            "materials": ([
                "stone bulwark": ([ "stone": 250, "wood": 50, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
                "rampart": ([ "stone": 0, "wood": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 10,
                "engineer": 1,
                "architect": 1,
            ]),
        ]),
        "components":([
            "SWX": ([
                "ascii": " | ",
                "unicode":  " \xe2\x95\x91 ",
            ]),
        ]),
    ]),

    "southern west castle bastion":([
        "type": "southern west castle wall",
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
        "construction": ([
            "duration": 480,
            "materials": ([
                "stone wall": ([ "stone": 100, "wood": 10, "metal": 5, "textile": 0 ]),
                "stone bulwark": ([ "stone": 450, "wood": 50, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
                "rampart": ([ "stone": 0, "wood": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 10,
                "engineer": 1,
                "architect": 1,
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

    "pallisade northern east castle wall":([
        "type": "northern east castle wall",
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
        "construction": ([
            "duration": 100,
            "materials": ([
                "wooden wall": ([ "wood": 100, "metal": 5 ]),
            ]),
            "workers": ([
                "carpenter": 5,
                "foreman": 1,
                "blacksmith": 1,
            ]),
        ]),
        "components":([
            "NEX": ([
                "ascii": " | ",
                "unicode":  " \xe2\x95\x91 ",
            ]),
        ]),
    ]),

    "wooden rampart northern east castle wall":([
        "type": "northern east castle wall",
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
        "construction": ([
            "duration": 200,
            "materials": ([
                "wooden wall": ([ "wood": 100, "metal": 5, "textile": 0 ]),
                "wooden battlement": ([ "wood":25, "metal": 5, "textile": 0 ]),
                "rampart": ([ "stone": 0, "wood": 0 ]),
            ]),
            "workers": ([
                "carpenter": 8,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 1,
                "engineer": 1,
                "architect": 1,
            ]),
        ]),
        "components":([
            "NEX": ([
                "ascii": " | ",
                "unicode":  " \xe2\x95\x91 ",
            ]),
        ]),
    ]),

    "stone northern east castle wall":([
        "type": "northern east castle wall",
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
        "construction": ([
            "duration": 250,
            "materials": ([
                "stone wall": ([ "stone": 100, "wood": 10, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 8,
                "engineer": 1,
                "architect": 1,
            ]),
        ]),
        "components":([
            "NEX": ([
                "ascii": " | ",
                "unicode":  " \xe2\x95\x91 ",
            ]),
        ]),
    ]),

    "northern east castle bulwark":([
        "type": "northern east castle wall",
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
        "construction": ([
            "duration": 360,
            "materials": ([
                "stone bulwark": ([ "stone": 250, "wood": 50, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 10,
                "engineer": 1,
                "architect": 1,
            ]),
        ]),
        "components":([
            "NEX": ([
                "ascii": " | ",
                "unicode":  " \xe2\x95\x91 ",
            ]),
        ]),
    ]),

    "talus northern east castle wall":([
        "type": "northern east castle wall",
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
        "construction": ([
            "duration": 400,
            "materials": ([
                "stone talus": ([ "stone": 300, "wood": 50, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 10,
                "engineer": 1,
                "architect": 1,
            ]),
        ]),
        "components":([
            "NEX": ([
                "ascii": " | ",
                "unicode":  " \xe2\x95\x91 ",
            ]),
        ]),
    ]),

    "northern east castle rampart":([
        "type": "northern east castle wall",
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
        "construction": ([
            "duration": 360,
            "materials": ([
                "stone bulwark": ([ "stone": 250, "wood": 50, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
                "rampart": ([ "stone": 0, "wood": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 10,
                "engineer": 1,
                "architect": 1,
            ]),
        ]),
        "components":([
            "NEX": ([
                "ascii": " | ",
                "unicode":  " \xe2\x95\x91 ",
            ]),
        ]),
    ]),

    "northern east castle bastion":([
        "type": "northern east castle wall",
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
        "construction": ([
            "duration": 480,
            "materials": ([
                "stone wall": ([ "stone": 100, "wood": 10, "metal": 5, "textile": 0 ]),
                "stone bulwark": ([ "stone": 450, "wood": 50, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
                "rampart": ([ "stone": 0, "wood": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 10,
                "engineer": 1,
                "architect": 1,
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

    "pallisade southern east castle wall":([
        "type": "southern east castle wall",
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
        "construction": ([
            "duration": 100,
            "materials": ([
                "wooden wall": ([ "wood": 100, "metal": 5 ]),
            ]),
            "workers": ([
                "carpenter": 5,
                "foreman": 1,
                "blacksmith": 1,
            ]),
        ]),
        "components":([
            "SEX": ([
                "ascii": " | ",
                "unicode":  " \xe2\x95\x91 ",
            ]),
        ]),
    ]),

    "wooden rampart southern east castle wall":([
        "type": "southern east castle wall",
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
        "construction": ([
            "duration": 200,
            "materials": ([
                "wooden wall": ([ "wood": 100, "metal": 5, "textile": 0 ]),
                "wooden battlement": ([ "wood":25, "metal": 5, "textile": 0 ]),
                "rampart": ([ "stone": 0, "wood": 0 ]),
            ]),
            "workers": ([
                "carpenter": 8,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 1,
                "engineer": 1,
                "architect": 1,
            ]),
        ]),
        "components":([
            "SEX": ([
                "ascii": " | ",
                "unicode":  " \xe2\x95\x91 ",
            ]),
        ]),
    ]),

    "stone southern east castle wall":([
        "type": "southern east castle wall",
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
        "construction": ([
            "duration": 250,
            "materials": ([
                "stone wall": ([ "stone": 100, "wood": 10, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 8,
                "engineer": 1,
                "architect": 1,
            ]),
        ]),
        "components":([
            "SEX": ([
                "ascii": " | ",
                "unicode":  " \xe2\x95\x91 ",
            ]),
        ]),
    ]),

    "southern east castle bulwark":([
        "type": "southern east castle wall",
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
        "construction": ([
            "duration": 360,
            "materials": ([
                "stone bulwark": ([ "stone": 250, "wood": 50, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 10,
                "engineer": 1,
                "architect": 1,
            ]),
        ]),
        "components":([
            "SEX": ([
                "ascii": " | ",
                "unicode":  " \xe2\x95\x91 ",
            ]),
        ]),
    ]),

    "talus southern east castle wall":([
        "type": "southern east castle wall",
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
        "construction": ([
            "duration": 400,
            "materials": ([
                "stone talus": ([ "stone": 300, "wood": 50, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 10,
                "engineer": 1,
                "architect": 1,
            ]),
        ]),
        "components":([
            "SEX": ([
                "ascii": " | ",
                "unicode":  " \xe2\x95\x91 ",
            ]),
        ]),
    ]),

    "southern east castle rampart":([
        "type": "southern east castle wall",
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
        "construction": ([
            "duration": 360,
            "materials": ([
                "stone bulwark": ([ "stone": 250, "wood": 50, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
                "rampart": ([ "stone": 0, "wood": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 10,
                "engineer": 1,
                "architect": 1,
            ]),
        ]),
        "components":([
            "SEX": ([
                "ascii": " | ",
                "unicode":  " \xe2\x95\x91 ",
            ]),
        ]),
    ]),

    "southern east castle bastion":([
        "type": "southern east castle wall",
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
        "construction": ([
            "duration": 480,
            "materials": ([
                "stone wall": ([ "stone": 100, "wood": 10, "metal": 5, "textile": 0 ]),
                "stone bulwark": ([ "stone": 450, "wood": 50, "metal": 5, "textile": 0 ]),
                "stone battlement": ([ "stone":25, "wood": 10, "metal": 5, "textile": 0 ]),
                "rampart": ([ "stone": 0, "wood": 0 ]),
            ]),
            "workers": ([
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "stonemason": 10,
                "engineer": 1,
                "architect": 1,
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
