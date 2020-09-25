//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef castleTowers_h
#define castleTowers_h

private mapping CastleTowers = ([
    "unbuilt northwest castle tower":([
        "type": "northwest castle tower",
        "display name": "Unbuilt Tower",
        "dimensions": "2x2",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;9m",
                "24-bit": "\x1b[0;38;2;200;0;0m"
            ]),
        ]),
        "components":([
            "NWCTR1": ([
                "ascii":"......",
                "unicode": "\u2237\u2237\u2237\u2237"
                    "\u2237\u2237",
            ]),
            "NWCTR2": ([
                "ascii":".    .",
                "unicode": "\u2237    \u2237",
            ]),
            "NWCTR3": ([
                "ascii":".     ",
                "unicode": "\u2237     ",
            ]),
            "NWCTR4": ([
                "ascii":"..    ",
                "unicode": "\u2237\u2237    ",
            ]),
        ]),
    ]),

    "ruined northwest castle tower":([
        "type": "northwest castle tower",
        "display name": "Ruined Tower",
        "dimensions": "2x2",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;9m",
                "24-bit": "\x1b[0;38;2;200;0;0m"
            ]),
        ]),
        "components":([
            "NWCTR1": ([
                "ascii":"......",
                "unicode": "\u2237\u2237\u2237\u2237"
                    "\u2237\u2237",
            ]),
            "NWCTR2": ([
                "ascii":".    .",
                "unicode": "\u2237    \u2237",
            ]),
            "NWCTR3": ([
                "ascii":".     ",
                "unicode": "\u2237     ",
            ]),
            "NWCTR4": ([
                "ascii":"..    ",
                "unicode": "\u2237\u2237    ",
            ]),
        ]),
    ]),

    "basic northwest castle tower":([
        "type": "northwest castle tower",
        "display name": "Basic Tower",
        "dimensions": "2x2",
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
                "stone tower": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
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
            "NWCTR1": ([
                "ascii":"+----+",
                "unicode": "\u2554\u2550\u2550\u2550"
                    "\u2550\u2557",
            ]),
            "NWCTR2": ([
                "ascii":"|    |",
                "unicode": "\u2551    \u2560",
            ]),
            "NWCTR3": ([
                "ascii":"|     ",
                "unicode": "\u2551    \u2502",
            ]),
            "NWCTR4": ([
                "ascii":"+-    ",
                "unicode": "\u255a\u2566\u2500\u2500"
                    "\u2500\u2518",
            ]),
        ]),
    ]),

    "tall northwest castle tower":([
        "type": "northwest castle tower",
        "display name": "Tall Tower",
        "dimensions": "2x2",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;36m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
        ]),
        "construction": ([
            "duration": 600,
            "materials": ([
                "stone tower": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "stone tower second level": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
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
            "NWCTR1": ([
                "ascii":"+====+",
                "unicode": "\u2554\u2550\u2550\u2550"
                    "\u2550\u2557",
            ]),
            "NWCTR2": ([
                "ascii":"|    |",
                "unicode": "\u2551\u2591\u2591\u2591"
                    "\u2591\u2560",
            ]),
            "NWCTR3": ([
                "ascii":"|     ",
                "unicode": "\u2551\u2591\u2591\u2591"
                    "\u2591\u2502",
            ]),
            "NWCTR4": ([
                "ascii":"+=    ",
                "unicode": "\u255a\u2566\u2500\u2500"
                    "\u2500\u2518",
            ]),
        ]),
    ]),

    "archer's northwest castle tower":([
        "type": "northwest castle tower",
        "display name": "Archer's Tower",
        "dimensions": "2x2",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;36m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
            "archer":([
                "3-bit": "\x1b[0;33m",
                "8-bit": "\x1b[0;38;5;199m",
                "24-bit": "\x1b[0;38;2;100;20;100m"
            ]),
        ]),
        "construction": ([
            "duration": 800,
            "materials": ([
                "stone tower": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "stone tower second level": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "archer level": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "stone battlement": ([ "stone": 75, "wood": 25, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "stonemason": 8,
                "carpenter": 2,
                "foreman": 1,
                "blacksmith": 1,
                "architect": 1,
            ]),
        ]),
        "components":([
            "NWCTR1": ([
                "ascii":"+====+",
                "unicode": "\u2554\u2550\u2550\u2550"
                    "\u2550\u2557",
            ]),
            "NWCTR2": ([
                "ascii":"|+archer--default+|",
                "unicode": "\u2551\u250farcher\u21a5\u21a5"
                    "default\u2513\u2560",
            ]),
            "NWCTR3": ([
                "ascii":"|+--+ ",
                "unicode": "\u2551\u2517\u2501\u2501"
                    "\u251b\u2502",
            ]),
            "NWCTR4": ([
                "ascii":"+=    ",
                "unicode": "\u255a\u2566\u2500\u2500"
                    "\u2500\u2518",
            ]),
        ]),
    ]),

    "ballista northwest castle tower":([
        "type": "northwest castle tower",
        "display name": "Ballista Tower",
        "dimensions": "2x2",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;36m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
            "ballista":([
                "3-bit": "\x1b[0;32m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
        ]),
        "construction": ([
            "duration": 840,
            "materials": ([
                "stone tower": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "stone tower second level": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "ballista platform": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "stone battlement": ([ "stone": 75, "wood": 25, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "stonemason": 8,
                "carpenter": 2,
                "foreman": 1,
                "blacksmith": 1,
                "architect": 1,
                "engineer": 1,
            ]),
        ]),
        "components":([
            "NWCTR1": ([
                "ascii":"+====+",
                "unicode": "\u2554\u2550\u2550\u2550"
                    "\u2550\u2557",
            ]),
            "NWCTR2": ([
                "ascii":"|+ballista~~default+|",
                "unicode": "\u2551\u256dballista\u21ed\u21ed"
                    "default\u256e\u2560",
            ]),
            "NWCTR3": ([
                "ascii":"|+~~+ ",
                "unicode": "\u2551\u2570\u2500\u2500"
                    "\u256f\u2502",
            ]),
            "NWCTR4": ([
                "ascii":"+=    ",
                "unicode": "\u255a\u2566\u2500\u2500"
                    "\u2500\u2518",
            ]),
        ]),
    ]),

    "catapult northwest castle tower":([
        "type": "northwest castle tower",
        "display name": "Catapult Tower",
        "dimensions": "2x2",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;36m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
            "catapult":([
                "3-bit": "\x1b[0;32m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
        ]),
        "construction": ([
            "duration": 880,
            "materials": ([
                "stone tower": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "stone tower second level": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "catapult platform": ([ "stone": 250, "wood": 75, "metal": 10, "textile": 0 ]),
                "stone battlement": ([ "stone": 75, "wood": 25, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "stonemason": 8,
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "architect": 1,
                "engineer": 2,
            ]),
        ]),
        "components":([
            "NWCTR1": ([
                "ascii":"+====+",
                "unicode": "\u2554\u2550\u2550\u2550"
                    "\u2550\u2557",
            ]),
            "NWCTR2": ([
                "ascii":"|+catapult~~default+|",
                "unicode": "\u2551\u250fcatapult\u21ef\u21ad"
                    "default\u2513\u2560",
            ]),
            "NWCTR3": ([
                "ascii":"|+~~+ ",
                "unicode": "\u2551\u2517\u2501\u2501"
                    "\u251b\u2502",
            ]),
            "NWCTR4": ([
                "ascii":"+=    ",
                "unicode": "\u255a\u2566\u2500\u2500"
                    "\u2500\u2518",
            ]),
        ]),
    ]),

    "trebuchet northwest castle tower":([
        "type": "northwest castle tower",
        "display name": "Trebuchet Tower",
        "dimensions": "2x2",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;36m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
            "trebuchet":([
                "3-bit": "\x1b[0;32m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
        ]),
        "construction": ([
            "duration": 960,
            "materials": ([
                "stone tower": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "stone tower second level": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "trebuchet platform": ([ "stone": 350, "wood": 100, "metal": 25, "textile": 0 ]),
                "stone battlement": ([ "stone": 75, "wood": 25, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "stonemason": 10,
                "carpenter": 5,
                "foreman": 1,
                "blacksmith": 1,
                "architect": 1,
                "engineer": 3,
            ]),
        ]),
        "components":([
            "NWCTR1": ([
                "ascii":"+====+",
                "unicode": "\u2554\u2550\u2550\u2550"
                    "\u2550\u2557",
            ]),
            "NWCTR2": ([
                "ascii":"|+trebuchet~~default+|",
                "unicode": "\u2551\u250ftrebuchet\u21ef\u21f2"
                    "default\u2513\u2560",
            ]),
            "NWCTR3": ([
                "ascii":"|+~~+ ",
                "unicode": "\u2551\u2517\u2501\u2501"
                    "\u251b\u2502",
            ]),
            "NWCTR4": ([
                "ascii":"+=    ",
                "unicode": "\u255a\u2566\u2500\u2500"
                    "\u2500\u2518",
            ]),
        ]),
    ]),

    "mage northwest castle tower":([
        "type": "northwest castle tower",
        "display name": "Mage Tower",
        "dimensions": "2x2",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;36m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
            "mage":([
                "3-bit": "\x1b[0;34;1m",
                "8-bit": "\x1b[0;38;5;20;1m",
                "24-bit": "\x1b[0;38;2;60;20;190;1m"
            ]),
        ]),
        "construction": ([
            "duration": 1024,
            "materials": ([
                "stone tower": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "stone tower second level": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "mage tower addition": ([ "stone": 350, "wood": 100, "metal": 25, "textile": 0, "crystal": 10 ]),
                "stone battlement": ([ "stone": 75, "wood": 25, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "stonemason": 10,
                "carpenter": 5,
                "foreman": 1,
                "blacksmith": 1,
                "architect": 1,
                "engineer": 2,
                "arcane craftsman": 5
            ]),
        ]),
        "components":([
            "NWCTR1": ([
                "ascii":"+====+",
                "unicode": "\u2554\u2550\u2550\u2550"
                    "\u2550\u2557",
            ]),
            "NWCTR2": ([
                "ascii":"|+mage~~default+|",
                "unicode": "\u2551\u250fmage\u22d0\u22d1"
                    "default\u2513\u2560",
            ]),
            "NWCTR3": ([
                "ascii":"|+~~+ ",
                "unicode": "\u2551\u2517\u2501\u2501"
                    "\u251b\u2502",
            ]),
            "NWCTR4": ([
                "ascii":"+=    ",
                "unicode": "\u255a\u2566\u2500\u2500"
                    "\u2500\u2518",
            ]),
        ]),
    ]),

    "unbuilt northeast castle tower":([
        "type": "northeast castle tower",
        "display name": "Unbuilt Tower",
        "dimensions": "2x2",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;9m",
                "24-bit": "\x1b[0;38;2;200;0;0m"
            ]),
        ]),
        "components":([
            "NECTR1": ([
                "ascii":"......",
                "unicode": "\u2237\u2237\u2237\u2237"
                    "\u2237\u2237",
            ]),
            "NECTR2": ([
                "ascii":".    .",
                "unicode": "\u2237    \u2237",
            ]),
            "NECTR3": ([
                "ascii":"     .",
                "unicode": "     \u2237",
            ]),
            "NECTR4": ([
                "ascii":"    ..",
                "unicode": "    \u2237\u2237",
            ]),
        ]),
    ]),

    "basic northeast castle tower":([
        "type": "northeast castle tower",
        "display name": "Basic Tower",
        "dimensions": "2x2",
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
                "stone tower": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
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
            "NECTR1": ([
                "ascii":"+====+",
                "unicode": "\u2554\u2550\u2550\u2550"
                    "\u2550\u2557",
            ]),
            "NECTR2": ([
                "ascii":"|    |",
                "unicode": "\u2563    \u2551",
            ]),
            "NECTR3": ([
                "ascii":"     |",
                "unicode": "\u2502    \u2551",
            ]),
            "NECTR4": ([
                "ascii":"    =+",
                "unicode": "\u2514\u2500\u2500\u2500"
                    "\u2566\u255d",
            ]),
        ]),
    ]),

    "tall northeast castle tower":([
        "type": "northeast castle tower",
        "display name": "Tall Tower",
        "dimensions": "2x2",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;36m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
        ]),
        "construction": ([
            "duration": 600,
            "materials": ([
                "stone tower": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "stone tower second level": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
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
            "NECTR1": ([
                "ascii":"+====+",
                "unicode": "\u2554\u2550\u2550\u2550"
                    "\u2550\u2557",
            ]),
            "NECTR2": ([
                "ascii":"|    |",
                "unicode": "\u2563\u2591\u2591\u2591"
                    "\u2591\u2551",
            ]),
            "NECTR3": ([
                "ascii":"     |",
                "unicode": "\u2502\u2591\u2591\u2591"
                    "\u2591\u2551",
            ]),
            "NECTR4": ([
                "ascii":"    =+",
                "unicode": "\u2514\u2500\u2500\u2500"
                    "\u2566\u255d",
            ]),
        ]),
    ]),

    "archer's northeast castle tower":([
        "type": "northeast castle tower",
        "display name": "Archer's Tower",
        "dimensions": "2x2",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;36m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
            "archer":([
                "3-bit": "\x1b[0;33m",
                "8-bit": "\x1b[0;38;5;199m",
                "24-bit": "\x1b[0;38;2;100;20;100m"
            ]),
        ]),
        "construction": ([
            "duration": 800,
            "materials": ([
                "stone tower": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "stone tower second level": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "archer level": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "stone battlement": ([ "stone": 75, "wood": 25, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "stonemason": 8,
                "carpenter": 2,
                "foreman": 1,
                "blacksmith": 1,
                "architect": 1,
            ]),
        ]),
        "components":([
            "NECTR1": ([
                "ascii":"+====+",
                "unicode": "\u2554\u2550\u2550\u2550"
                    "\u2550\u2557",
            ]),
            "NECTR2": ([
                "ascii":"|+archer--default+|",
                "unicode": "\u2563\u250farcher\u21a5\u21a5"
                    "default\u2513\u2551",
            ]),
            "NECTR3": ([
                "ascii":" +--+|",
                "unicode": "\u2502\u2517\u2501\u2501"
                    "\u251b\u2551",
            ]),
            "NECTR4": ([
                "ascii":"    =+",
                "unicode": "\u2514\u2500\u2500\u2500"
                    "\u2566\u255d",
            ]),
        ]),
    ]),

    "ballista northeast castle tower":([
        "type": "northeast castle tower",
        "display name": "Ballista Tower",
        "dimensions": "2x2",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;36m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
            "ballista":([
                "3-bit": "\x1b[0;32m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
        ]),
        "construction": ([
            "duration": 840,
            "materials": ([
                "stone tower": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "stone tower second level": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "ballista platform": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "stone battlement": ([ "stone": 75, "wood": 25, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "stonemason": 8,
                "carpenter": 2,
                "foreman": 1,
                "blacksmith": 1,
                "architect": 1,
                "engineer": 1,
            ]),
        ]),
        "components":([
            "NECTR1": ([
                "ascii":"+====+",
                "unicode": "\u2554\u2550\u2550\u2550"
                    "\u2550\u2557",
            ]),
            "NECTR2": ([
                "ascii":"|+ballista~~default+|",
                "unicode": "\u2563\u256dballista\u21ed\u21ed"
                    "default\u256e\u2551",
            ]),
            "NECTR3": ([
                "ascii":" +~~+|",
                "unicode": "\u2502\u2570\u2500\u2500"
                    "\u256f\u2551",
            ]),
            "NECTR4": ([
                "ascii":"    =+",
                "unicode": "\u2514\u2500\u2500\u2500"
                    "\u2566\u255d",
            ]),
        ]),
    ]),

    "catapult northeast castle tower":([
        "type": "northeast castle tower",
        "display name": "Catapult Tower",
        "dimensions": "2x2",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;36m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
            "catapult":([
                "3-bit": "\x1b[0;32m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
        ]),
        "construction": ([
            "duration": 880,
            "materials": ([
                "stone tower": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "stone tower second level": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "catapult platform": ([ "stone": 250, "wood": 75, "metal": 10, "textile": 0 ]),
                "stone battlement": ([ "stone": 75, "wood": 25, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "stonemason": 8,
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "architect": 1,
                "engineer": 2,
            ]),
        ]),
        "components":([
            "NECTR1": ([
                "ascii":"+====+",
                "unicode": "\u2554\u2550\u2550\u2550"
                    "\u2550\u2557",
            ]),
            "NECTR2": ([
                "ascii":"|+catapult~~default+|",
                "unicode": "\u2563\u250fcatapult\u21ef\u21ad"
                    "default\u2513\u2551",
            ]),
            "NECTR3": ([
                "ascii":" +~~+|",
                "unicode": "\u2502\u2517\u2501\u2501"
                    "\u251b\u2551",
            ]),
            "NECTR4": ([
                "ascii":"    =+",
                "unicode": "\u2514\u2500\u2500\u2500"
                    "\u2566\u255d",
            ]),
        ]),
    ]),

    "trebuchet northeast castle tower":([
        "type": "northeast castle tower",
        "display name": "Trebuchet Tower",
        "dimensions": "2x2",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;36m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
            "trebuchet":([
                "3-bit": "\x1b[0;32m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
        ]),
        "construction": ([
            "duration": 960,
            "materials": ([
                "stone tower": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "stone tower second level": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "trebuchet platform": ([ "stone": 350, "wood": 100, "metal": 25, "textile": 0 ]),
                "stone battlement": ([ "stone": 75, "wood": 25, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "stonemason": 10,
                "carpenter": 5,
                "foreman": 1,
                "blacksmith": 1,
                "architect": 1,
                "engineer": 3,
            ]),
        ]),
        "components":([
            "NECTR1": ([
                "ascii":"+====+",
                "unicode": "\u2554\u2550\u2550\u2550"
                    "\u2550\u2557",
            ]),
            "NECTR2": ([
                "ascii":"|+trebuchet~~default+|",
                "unicode": "\u2563\u250ftrebuchet\u21ef\u21f2"
                    "default\u2513\u2551",
            ]),
            "NECTR3": ([
                "ascii":" +~~+|",
                "unicode": "\u2502\u2517\u2501\u2501"
                    "\u251b\u2551",
            ]),
            "NECTR4": ([
                "ascii":"    =+",
                "unicode": "\u2514\u2500\u2500\u2500"
                    "\u2566\u255d",
            ]),
        ]),
    ]),

    "mage northeast castle tower":([
        "type": "northeast castle tower",
        "display name": "Mage Tower",
        "dimensions": "2x2",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;36m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
            "mage":([
                "3-bit": "\x1b[0;34;1m",
                "8-bit": "\x1b[0;38;5;20;1m",
                "24-bit": "\x1b[0;38;2;60;20;190;1m"
            ]),
        ]),
        "construction": ([
            "duration": 1024,
            "materials": ([
                "stone tower": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "stone tower second level": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "mage tower addition": ([ "stone": 350, "wood": 100, "metal": 25, "textile": 0, "crystal": 10 ]),
                "stone battlement": ([ "stone": 75, "wood": 25, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "stonemason": 10,
                "carpenter": 5,
                "foreman": 1,
                "blacksmith": 1,
                "architect": 1,
                "engineer": 2,
                "arcane craftsman": 5
            ]),
        ]),
        "components":([
            "NECTR1": ([
                "ascii":"+====+",
                "unicode": "\u2554\u2550\u2550\u2550"
                    "\u2550\u2557",
            ]),
            "NECTR2": ([
                "ascii":"|+mage~~default+|",
                "unicode": "\u2563\u250fmage\u22d0\u22d1"
                    "default\u2513\u2551",
            ]),
            "NECTR3": ([
                "ascii":" +~~+|",
                "unicode": "\u2502\u2517\u2501\u2501"
                    "\u251b\u2551",
            ]),
            "NECTR4": ([
                "ascii":"    =+",
                "unicode": "\u2514\u2500\u2500\u2500"
                    "\u2566\u255d",
            ]),
        ]),
    ]),

    "unbuilt southwest castle tower":([
        "type": "southwest castle tower",
        "display name": "Unbuilt Tower",
        "dimensions": "2x2",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;9m",
                "24-bit": "\x1b[0;38;2;200;0;0m"
            ]),
        ]),
        "components":([
            "SWCTR1": ([
                "ascii":"..    ",
                "unicode": "\u2237\u2237    ",
            ]),
            "SWCTR2": ([
                "ascii":".     ",
                "unicode": "\u2237     ",
            ]),
            "SWCTR3": ([
                "ascii":".    .",
                "unicode": "\u2237    \u2237",
            ]),
            "SWCTR4": ([
                "ascii":"......",
                "unicode": "\u2237\u2237\u2237"
                    "\u2237\u2237\u2237",
            ]),
        ]),
    ]),

    "basic southwest castle tower":([
        "type": "southwest castle tower",
        "display name": "Basic Tower",
        "dimensions": "2x2",
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
                "stone tower": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
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
            "SWCTR1": ([
                "ascii":"+-    ",
                "unicode": "\u2554\u2569\u2500\u2500"
                    "\u2500\u2510",
            ]),
            "SWCTR2": ([
                "ascii":"|     ",
                "unicode": "\u2551    \u2502",
            ]),
            "SWCTR3": ([
                "ascii":"|    |",
                "unicode": "\u2551    \u2560",
            ]),
            "SWCTR4": ([
                "ascii": "+----+",
                "unicode": "\u255a\u2550\u2550\u2550"
                    "\u2550\u255d",
            ]),
        ]),
    ]),

    "tall southwest castle tower":([
        "type": "southwest castle tower",
        "display name": "Tall Tower",
        "dimensions": "2x2",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;36m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
        ]),
        "construction": ([
            "duration": 600,
            "materials": ([
                "stone tower": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "stone tower second level": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
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
            "SWCTR1": ([
                "ascii":"+=    ",
                "unicode": "\u2554\u2569\u2500\u2500"
                    "\u2500\u2510",
            ]),
            "SWCTR2": ([
                "ascii":"|     ",
                "unicode": "\u2551\u2591\u2591\u2591"
                    "\u2591\u2502",
            ]),
            "SWCTR3": ([
                "ascii":"|    |",
                "unicode": "\u2551\u2591\u2591\u2591"
                    "\u2591\u2560",
            ]),
            "SWCTR4": ([
                "ascii": "+====+",
                "unicode": "\u255a\u2550\u2550\u2550"
                    "\u2550\u255d",
            ]),
        ]),
    ]),

    "archer's southwest castle tower":([
        "type": "southwest castle tower",
        "display name": "Archer's Tower",
        "dimensions": "2x2",
        "feature description": "a stout, three story tower with many locations "
            "upon the battlements manned by archers",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;36m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
            "archer":([
                "3-bit": "\x1b[0;33m",
                "8-bit": "\x1b[0;38;5;199m",
                "24-bit": "\x1b[0;38;2;100;20;100m"
            ]),
        ]),
        "construction": ([
            "duration": 800,
            "materials": ([
                "stone tower": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "stone tower second level": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "archer level": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "stone battlement": ([ "stone": 75, "wood": 25, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "stonemason": 8,
                "carpenter": 2,
                "foreman": 1,
                "blacksmith": 1,
                "architect": 1,
            ]),
        ]),
        "components":([
            "SWCTR1": ([
                "ascii":"+=    ",
                "unicode": "\u2554\u2569\u2500\u2500"
                    "\u2500\u2510",
            ]),
            "SWCTR2": ([
                "ascii":"|+--+ ",
                "unicode": "\u2551\u250f\u2501\u2501"
                    "\u2513\u2502",
            ]),
            "SWCTR3": ([
                "ascii":"|+archer--default+|",
                "unicode": "\u2551\u2517archer\u21a7\u21a7"
                    "default\u251b\u2560",
            ]),
            "SWCTR4": ([
                "ascii": "+====+",
                "unicode": "\u255a\u2550\u2550\u2550"
                    "\u2550\u255d",
            ]),
        ]),
    ]),

    "ballista southwest castle tower":([
        "type": "southwest castle tower",
        "display name": "Ballista Tower",
        "dimensions": "2x2",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;36m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
            "ballista":([
                "3-bit": "\x1b[0;32m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
        ]),
        "construction": ([
            "duration": 840,
            "materials": ([
                "stone tower": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "stone tower second level": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "ballista platform": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "stone battlement": ([ "stone": 75, "wood": 25, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "stonemason": 8,
                "carpenter": 2,
                "foreman": 1,
                "blacksmith": 1,
                "architect": 1,
                "engineer": 1,
            ]),
        ]),
        "components":([
            "SWCTR1": ([
                "ascii":"+=    ",
                "unicode": "\u2554\u2569\u2500\u2500"
                    "\u2500\u2510",
            ]),
            "SWCTR2": ([
                "ascii":"|+~~+ ",
                "unicode": "\u2551\u250f\u2501\u2501"
                    "\u2513\u2502",
            ]),
            "SWCTR3": ([
                "ascii":"|+ballista~~default+|",
                "unicode": "\u2551\u2517ballista\u21e9\u21e9"
                    "default\u251b\u2560",
            ]),
            "SWCTR4": ([
                "ascii": "+====+",
                "unicode": "\u255a\u2550\u2550\u2550"
                    "\u2550\u255d",
            ]),
        ]),
    ]),

    "catapult southwest castle tower":([
        "type": "southwest castle tower",
        "display name": "Catapult Tower",
        "dimensions": "2x2",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;36m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
            "catapult":([
                "3-bit": "\x1b[0;32m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
        ]),
        "construction": ([
            "duration": 880,
            "materials": ([
                "stone tower": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "stone tower second level": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "catapult platform": ([ "stone": 250, "wood": 75, "metal": 10, "textile": 0 ]),
                "stone battlement": ([ "stone": 75, "wood": 25, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "stonemason": 8,
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "architect": 1,
                "engineer": 2,
            ]),
        ]),
        "components":([
            "SWCTR1": ([
                "ascii":"+=    ",
                "unicode": "\u2554\u2569\u2500\u2500"
                    "\u2500\u2510",
            ]),
            "SWCTR2": ([
                "ascii":"|+~~+ ",
                "unicode": "\u2551\u250f\u2501\u2501"
                    "\u2513\u2502",
            ]),
            "SWCTR3": ([
                "ascii":"|+catapult~~default+|",
                "unicode": "\u2551\u2517catapult\u21ef\u21ad"
                    "default\u251b\u2560",
            ]),
            "SWCTR4": ([
                "ascii": "+====+",
                "unicode": "\u255a\u2550\u2550\u2550"
                    "\u2550\u255d",
            ]),
        ]),
    ]),

    "trebuchet southwest castle tower":([
        "type": "southwest castle tower",
        "display name": "Trebuchet Tower",
        "dimensions": "2x2",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;36m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
            "trebuchet":([
                "3-bit": "\x1b[0;32m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
        ]),
        "construction": ([
            "duration": 960,
            "materials": ([
                "stone tower": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "stone tower second level": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "trebuchet platform": ([ "stone": 350, "wood": 100, "metal": 25, "textile": 0 ]),
                "stone battlement": ([ "stone": 75, "wood": 25, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "stonemason": 10,
                "carpenter": 5,
                "foreman": 1,
                "blacksmith": 1,
                "architect": 1,
                "engineer": 3,
            ]),
        ]),
        "components":([
            "SWCTR1": ([
                "ascii":"+=    ",
                "unicode": "\u2554\u2569\u2500\u2500"
                    "\u2500\u2510",
            ]),
            "SWCTR2": ([
                "ascii":"|+~~+ ",
                "unicode": "\u2551\u250f\u2501\u2501"
                    "\u2513\u2502",
            ]),
            "SWCTR3": ([
                "ascii":"|+trebuchet~~default+|",
                "unicode": "\u2551\u2517trebuchet\u21ef\u21f2"
                    "default\u251b\u2560",
            ]),
            "SWCTR4": ([
                "ascii": "+====+",
                "unicode": "\u255a\u2550\u2550\u2550"
                    "\u2550\u255d",
            ]),
        ]),
    ]),

    "mage southwest castle tower":([
        "type": "southwest castle tower",
        "display name": "Mage Tower",
        "dimensions": "2x2",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;36m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
            "mage":([
                "3-bit": "\x1b[0;34;1m",
                "8-bit": "\x1b[0;38;5;20;1m",
                "24-bit": "\x1b[0;38;2;60;20;190;1m"
            ]),
        ]),
        "construction": ([
            "duration": 1024,
            "materials": ([
                "stone tower": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "stone tower second level": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "mage tower addition": ([ "stone": 350, "wood": 100, "metal": 25, "textile": 0, "crystal": 10 ]),
                "stone battlement": ([ "stone": 75, "wood": 25, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "stonemason": 10,
                "carpenter": 5,
                "foreman": 1,
                "blacksmith": 1,
                "architect": 1,
                "engineer": 2,
                "arcane craftsman": 5
            ]),
        ]),
        "components":([
            "SWCTR1": ([
                "ascii":"+=    ",
                "unicode": "\u2554\u2569\u2500\u2500"
                    "\u2500\u2510",
            ]),
            "SWCTR2": ([
                "ascii":"|+~~+ ",
                "unicode": "\u2551\u250f\u2501\u2501"
                    "\u2513\u2502",
            ]),
            "SWCTR3": ([
                "ascii":"|+mage~~default+|",
                "unicode": "\u2551\u2517mage\u22d0\u22d1"
                    "default\u251b\u2560",
            ]),
            "SWCTR4": ([
                "ascii": "+====+",
                "unicode": "\u255a\u2550\u2550\u2550"
                    "\u2550\u255d",
            ]),
        ]),
    ]),

    "unbuilt southeast castle tower":([
        "type": "southeast castle tower",
        "display name": "Unbuilt Tower",
        "dimensions": "2x2",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;9m",
                "24-bit": "\x1b[0;38;2;200;0;0m"
            ]),
        ]),
        "components":([
            "SECTR1": ([
                "ascii":"    ..",
                "unicode": "    \u2237\u2237",
            ]),
            "SECTR2": ([
                "ascii":"     .",
                "unicode": "     \u2237",
            ]),
            "SECTR3": ([
                "ascii":".    .",
                "unicode": "\u2237    \u2237",
            ]),
            "SECTR4": ([
                "ascii":"......",
                "unicode": "\u2237\u2237\u2237"
                    "\u2237\u2237\u2237",
            ]),
        ]),
    ]),

    "basic southeast castle tower":([
        "type": "southeast castle tower",
        "display name": "Basic Tower",
        "dimensions": "2x2",
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
                "stone tower": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
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
            "SECTR1": ([
                "ascii":"    -+",
                "unicode": "\u250c\u2500\u2500\u2500"
                    "\u2569\u2557",
            ]),
            "SECTR2": ([
                "ascii":"     |",
                "unicode": "\u2502    \u2551",
            ]),
            "SECTR3": ([
                "ascii":"|    |",
                "unicode": "\u2563    \u2551",
            ]),
            "SECTR4": ([
                "ascii": "+----+",
                "unicode": "\u255a\u2550\u2550\u2550"
                    "\u2550\u255d",
            ]),
        ]),
    ]),

    "tall southeast castle tower":([
        "type": "southeast castle tower",
        "display name": "Tall Tower",
        "dimensions": "2x2",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;36m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
        ]),
        "construction": ([
            "duration": 600,
            "materials": ([
                "stone tower": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "stone tower second level": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
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
            "SECTR1": ([
                "ascii":"    =+",
                "unicode": "\u250c\u2500\u2500\u2500"
                    "\u2569\u2557",
            ]),
            "SECTR2": ([
                "ascii":"     |",
                "unicode": "\u2502\u2591\u2591\u2591"
                    "\u2591\u2551",
            ]),
            "SECTR3": ([
                "ascii":"|    |",
                "unicode": "\u2563\u2591\u2591\u2591"
                    "\u2591\u2551",
            ]),
            "SECTR4": ([
                "ascii": "+====+",
                "unicode": "\u255a\u2550\u2550\u2550"
                    "\u2550\u255d",
            ]),
        ]),
    ]),

    "archer's southeast castle tower":([
        "type": "southeast castle tower",
        "display name": "Archer's Tower",
        "dimensions": "2x2",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;36m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
            "archer":([
                "3-bit": "\x1b[0;33m",
                "8-bit": "\x1b[0;38;5;199m",
                "24-bit": "\x1b[0;38;2;100;20;100m"
            ]),
        ]),
        "construction": ([
            "duration": 800,
            "materials": ([
                "stone tower": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "stone tower second level": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "archer level": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "stone battlement": ([ "stone": 75, "wood": 25, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "stonemason": 8,
                "carpenter": 2,
                "foreman": 1,
                "blacksmith": 1,
                "architect": 1,
            ]),
        ]),
        "components":([
            "SECTR1": ([
                "ascii":"    =+",
                "unicode": "\u250c\u2500\u2500\u2500"
                    "\u2569\u2557",
            ]),
            "SECTR2": ([
                "ascii":" +--+|",
                "unicode": "\u2502\u250f\u2501\u2501"
                    "\u2513\u2551",
            ]),
            "SECTR3": ([
                "ascii":"|+archer~~default+|",
                "unicode": "\u2563\u2517archer\u21a7\u21a7"
                    "default\u251b\u2551",
            ]),
            "SECTR4": ([
                "ascii": "+====+",
                "unicode": "\u255a\u2550\u2550\u2550"
                    "\u2550\u255d",
            ]),
        ]),
    ]),

    "ballista southeast castle tower":([
        "type": "southeast castle tower",
        "display name": "Ballista Tower",
        "dimensions": "2x2",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;36m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
            "ballista":([
                "3-bit": "\x1b[0;32m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
        ]),
        "construction": ([
            "duration": 840,
            "materials": ([
                "stone tower": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "stone tower second level": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "ballista platform": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "stone battlement": ([ "stone": 75, "wood": 25, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "stonemason": 8,
                "carpenter": 2,
                "foreman": 1,
                "blacksmith": 1,
                "architect": 1,
                "engineer": 1,
            ]),
        ]),
        "components":([
            "SECTR1": ([
                "ascii":"    =+",
                "unicode": "\u250c\u2500\u2500\u2500"
                    "\u2569\u2557",
            ]),
            "SECTR2": ([
                "ascii":" +~~+|",
                "unicode": "\u2502\u250f\u2501\u2501"
                    "\u2513\u2551",
            ]),
            "SECTR3": ([
                "ascii":"|+ballista~~default+|",
                "unicode": "\u2563\u2517ballista\u21e9\u21e9"
                    "default\u251b\u2551",
            ]),
            "SECTR4": ([
                "ascii": "+====+",
                "unicode": "\u255a\u2550\u2550\u2550"
                    "\u2550\u255d",
            ]),
        ]),
    ]),

    "catapult southeast castle tower":([
        "type": "southeast castle tower",
        "display name": "Catapult Tower",
        "dimensions": "2x2",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;36m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
            "catapult":([
                "3-bit": "\x1b[0;32m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
        ]),
        "construction": ([
            "duration": 880,
            "materials": ([
                "stone tower": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "stone tower second level": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "catapult platform": ([ "stone": 250, "wood": 75, "metal": 10, "textile": 0 ]),
                "stone battlement": ([ "stone": 75, "wood": 25, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "stonemason": 8,
                "carpenter": 3,
                "foreman": 1,
                "blacksmith": 1,
                "architect": 1,
                "engineer": 2,
            ]),
        ]),
        "components":([
            "SECTR1": ([
                "ascii":"    =+",
                "unicode": "\u250c\u2500\u2500\u2500"
                    "\u2569\u2557",
            ]),
            "SECTR2": ([
                "ascii":" +~~+|",
                "unicode": "\u2502\u250f\u2501\u2501"
                    "\u2513\u2551",
            ]),
            "SECTR3": ([
                "ascii":"|+catapult~~default+|",
                "unicode": "\u2563\u2517catapult\u21ef\u21ad"
                    "default\u251b\u2551",
            ]),
            "SECTR4": ([
                "ascii": "+====+",
                "unicode": "\u255a\u2550\u2550\u2550"
                    "\u2550\u255d",
            ]),
        ]),
    ]),

    "trebuchet southeast castle tower":([
        "type": "southeast castle tower",
        "display name": "Trebuchet Tower",
        "dimensions": "2x2",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;36m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
            "trebuchet":([
                "3-bit": "\x1b[0;32m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
        ]),
        "construction": ([
            "duration": 960,
            "materials": ([
                "stone tower": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "stone tower second level": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "trebuchet platform": ([ "stone": 350, "wood": 100, "metal": 25, "textile": 0 ]),
                "stone battlement": ([ "stone": 75, "wood": 25, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "stonemason": 10,
                "carpenter": 5,
                "foreman": 1,
                "blacksmith": 1,
                "architect": 1,
                "engineer": 3,
            ]),
        ]),
        "components":([
            "SECTR1": ([
                "ascii":"    =+",
                "unicode": "\u250c\u2500\u2500\u2500"
                    "\u2569\u2557",
            ]),
            "SECTR2": ([
                "ascii":" +~~+|",
                "unicode": "\u2502\u250f\u2501\u2501"
                    "\u2513\u2551",
            ]),
            "SECTR3": ([
                "ascii":"|+trebuchet~~default+|",
                "unicode": "\u2563\u2517trebuchet\u21ef\u21f2"
                    "default\u251b\u2551",
            ]),
            "SECTR4": ([
                "ascii": "+====+",
                "unicode": "\u255a\u2550\u2550\u2550"
                    "\u2550\u255d",
            ]),
        ]),
    ]),

    "mage southeast castle tower":([
        "type": "southeast castle tower",
        "display name": "Mage Tower",
        "dimensions": "2x2",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;36m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
            "mage":([
                "3-bit": "\x1b[0;34;1m",
                "8-bit": "\x1b[0;38;5;20;1m",
                "24-bit": "\x1b[0;38;2;60;20;190;1m"
            ]),
        ]),
        "construction": ([
            "duration": 1024,
            "materials": ([
                "stone tower": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "stone tower second level": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "mage tower addition": ([ "stone": 350, "wood": 100, "metal": 25, "textile": 0, "crystal": 10 ]),
                "stone battlement": ([ "stone": 75, "wood": 25, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "stonemason": 10,
                "carpenter": 5,
                "foreman": 1,
                "blacksmith": 1,
                "architect": 1,
                "engineer": 2,
                "arcane craftsman": 5
            ]),
        ]),
        "components":([
            "SECTR1": ([
                "ascii":"    =+",
                "unicode": "\u250c\u2500\u2500\u2500"
                    "\u2569\u2557",
            ]),
            "SECTR2": ([
                "ascii":" +~~+|",
                "unicode": "\u2502\u250f\u2501\u2501"
                    "\u2513\u2551",
            ]),
            "SECTR3": ([
                "ascii":"|+mage~~default+|",
                "unicode": "\u2563\u2517mage\u22d0\u22d1"
                    "default\u251b\u2551",
            ]),
            "SECTR4": ([
                "ascii": "+====+",
                "unicode": "\u255a\u2550\u2550\u2550"
                    "\u2550\u255d",
            ]),
        ]),
    ]),

    "unbuilt north castle tower":([
        "type": "north castle tower",
        "display name": "Unbuilt Tower",
        "dimensions": "3x2",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;9m",
                "24-bit": "\x1b[0;38;2;200;0;0m"
            ]),
        ]),
        "components":([
            "NCATOWER1": ([
                "ascii": ".........",
                "unicode": "\u2237\u2237\u2237"
                    "\u2237\u2237\u2237"
                    "\u2237\u2237\u2237",
            ]),
            "NCATOWER2": ([
                "ascii": ".       .",
                "unicode": "\u2237       \u2237",
            ]),
            "NCATOWER3": ([
                "ascii": ".........",
                "unicode": "\u2237\u2237\u2237"
                    "\u2237\u2237\u2237"
                    "\u2237\u2237\u2237",
            ]),
        ]),
    ]),

    "basic north castle tower":([
        "type": "north castle tower",
        "display name": "Basic Tower",
        "dimensions": "3x2",
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
                "stone tower": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
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
            "NCATOWER1": ([
                "ascii": "+=======+",
                "unicode": "\u2554\u2550\u2550"
                    "\u2550\u2550\u2550\u2550"
                    "\u2550\u2557",
            ]),
            "NCATOWER2": ([
                "ascii": "|       |",
                "unicode": "\u2563       \u2560",
            ]),
            "NCATOWER3": ([
                "ascii": "+=======+",
                "unicode": "\u255a\u2550\u2550"
                    "\u2550\u2550\u2550\u2550"
                    "\u2550\u255d",
            ]),
        ]),
    ]),

    "tall north castle tower":([
        "type": "north castle tower",
        "display name": "Tall Tower",
        "dimensions": "3x2",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;36m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
        ]),
        "construction": ([
            "duration": 600,
            "materials": ([
                "stone tower": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "stone tower second level": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
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
            "NCATOWER1": ([
                "ascii": "+=======+",
                "unicode": "\u2554\u2550\u2550"
                    "\u2550\u2550\u2550\u2550"
                    "\u2550\u2557",
            ]),
            "NCATOWER2": ([
                "ascii": "|       |",
                "unicode": "\u2563\u2591\u2591\u2591"
                    "\u2591\u2591\u2591\u2591"
                    "\u2560",
            ]),
            "NCATOWER3": ([
                "ascii": "+=======+",
                "unicode": "\u255a\u2550\u2550"
                    "\u2550\u2550\u2550\u2550"
                    "\u2550\u255d",
            ]),
        ]),
    ]),

    "archer's north castle tower":([
        "type": "north castle tower",
        "display name": "Archer's Tower",
        "dimensions": "3x2",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;36m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
            "archer":([
                "3-bit": "\x1b[0;33;1m",
                "8-bit": "\x1b[0;38;5;199;1m",
                "24-bit": "\x1b[0;38;2;100;20;100;1m"
            ]),
        ]),
        "construction": ([
            "duration": 800,
            "materials": ([
                "stone tower": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "stone tower second level": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "archer level": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "stone battlement": ([ "stone": 75, "wood": 25, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "stonemason": 8,
                "carpenter": 2,
                "foreman": 1,
                "blacksmith": 1,
                "architect": 1,
            ]),
        ]),
        "components":([
            "NCATOWER1": ([
                "ascii": "+=======+",
                "unicode": "\u2554\u2550\u2550"
                    "\u2550\u2550\u2550\u2550"
                    "\u2550\u2557",
            ]),
            "NCATOWER2": ([
                "ascii": "| archerx x xdefault |",
                "unicode": "\u2563 archer\u21a5 \u21a5 "
                    "\u21a5default \u2560",
            ]),
            "NCATOWER3": ([
                "ascii": "+=======+",
                "unicode": "\u255a\u2550\u2550"
                    "\u2550\u2550\u2550\u2550"
                    "\u2550\u255d",
            ]),
        ]),
    ]),

    "ballista north castle tower":([
        "type": "north castle tower",
        "display name": "Ballista Tower",
        "dimensions": "3x2",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;36m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
            "ballista":([
                "3-bit": "\x1b[0;33m",
                "8-bit": "\x1b[0;38;5;199m",
                "24-bit": "\x1b[0;38;2;100;20;100m"
            ]),
        ]),
        "construction": ([
            "duration": 840,
            "materials": ([
                "stone tower": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "stone tower second level": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "ballista platform": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "stone battlement": ([ "stone": 75, "wood": 25, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "stonemason": 8,
                "carpenter": 2,
                "foreman": 1,
                "blacksmith": 1,
                "architect": 1,
                "engineer": 1,
            ]),
        ]),
        "components":([
            "NCATOWER1": ([
                "ascii": "+=======+",
                "unicode": "\u2554\u2550\u2550"
                    "\u2550\u2550\u2550\u2550"
                    "\u2550\u2557",
            ]),
            "NCATOWER2": ([
                "ascii": "| ballistax   xdefault |",
                "unicode": "\u2563 ballista\u21ed   "
                    "\u21eddefault \u2560",
            ]),
            "NCATOWER3": ([
                "ascii": "+=======+",
                "unicode": "\u255a\u2550\u2550"
                    "\u2550\u2550\u2550\u2550"
                    "\u2550\u255d",
            ]),
        ]),
    ]),

    "gate north castle tower":([
        "type": "north castle tower",
        "display name": "Gatehouse",
        "dimensions": "3x2",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;36m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
            "archer":([
                "3-bit": "\x1b[0;33;1m",
                "8-bit": "\x1b[0;38;5;199;1m",
                "24-bit": "\x1b[0;38;2;100;20;100;1m"
            ]),
            "gate":([
                "3-bit": "\x1b[0;32;1m",
                "8-bit": "\x1b[0;38;5;103;1m",
                "24-bit": "\x1b[0;38;2;112;128;144;1m",
            ]),
        ]),
        "construction": ([
            "duration": 960,
            "materials": ([
                "stone tower": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "stone tower second level": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "gatehouse": ([ "stone": 400, "wood": 150, "metal": 75, "textile": 0 ]),
                "stone battlement": ([ "stone": 75, "wood": 25, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "stonemason": 10,
                "carpenter": 5,
                "foreman": 1,
                "blacksmith": 1,
                "architect": 1,
                "engineer": 2,
            ]),
        ]),
        "components":([
            "NCATOWER1": ([
                "ascii": "+==---==+",
                "unicode": "\u2554\u2550\u2550"
                    "gate\u2504\u2504\u2504default"
                    "\u2550\u2550\u2557",
            ]),
            "NCATOWER2": ([
                "ascii": "| archerx x xdefault |",
                "unicode": "\u2563 archer\u21a5 \u21a5 "
                    "\u21a5default \u2560",
            ]),
            "NCATOWER3": ([
                "ascii": "+=======+",
                "unicode": "\u255a\u2550\u2550"
                    "\u2550\u2550\u2550\u2550"
                    "\u2550\u255d",
            ]),
        ]),
    ]),

    "unbuilt south castle tower":([
        "type": "south castle tower",
        "display name": "Unbuilt Tower",
        "dimensions": "3x2",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;9m",
                "24-bit": "\x1b[0;38;2;200;0;0m"
            ]),
        ]),
        "components":([
            "SCATOWER1": ([
                "ascii": ".........",
                "unicode": "\u2237\u2237\u2237"
                    "\u2237\u2237\u2237"
                    "\u2237\u2237\u2237",
            ]),
            "SCATOWER2": ([
                "ascii": ".       .",
                "unicode": "\u2237       \u2237",
            ]),
            "SCATOWER3": ([
                "ascii": ".........",
                "unicode": "\u2237\u2237\u2237"
                    "\u2237\u2237\u2237"
                    "\u2237\u2237\u2237",
            ]),
        ]),
    ]),

    "basic south castle tower":([
        "type": "south castle tower",
        "display name": "Basic Tower",
        "dimensions": "3x2",
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
                "stone tower": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
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
            "SCATOWER1": ([
                "ascii": "+=======+",
                "unicode": "\u2554\u2550\u2550"
                    "\u2550\u2550\u2550\u2550"
                    "\u2550\u2557",
            ]),
            "SCATOWER2": ([
                "ascii": "|       |",
                "unicode": "\u2563       \u2560",
            ]),
            "SCATOWER3": ([
                "ascii": "+=======+",
                "unicode": "\u255a\u2550\u2550"
                    "\u2550\u2550\u2550\u2550"
                    "\u2550\u255d",
            ]),
        ]),
    ]),

    "tall south castle tower":([
        "type": "south castle tower",
        "display name": "Tall Tower",
        "dimensions": "3x2",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;36m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
        ]),
        "construction": ([
            "duration": 600,
            "materials": ([
                "stone tower": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "stone tower second level": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
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
            "SCATOWER1": ([
                "ascii": "+=======+",
                "unicode": "\u2554\u2550\u2550"
                    "\u2550\u2550\u2550\u2550"
                    "\u2550\u2557",
            ]),
            "SCATOWER2": ([
                "ascii": "|       |",
                "unicode": "\u2563\u2591\u2591\u2591"
                    "\u2591\u2591\u2591\u2591"
                    "\u2560",
            ]),
            "SCATOWER3": ([
                "ascii": "+=======+",
                "unicode": "\u255a\u2550\u2550"
                    "\u2550\u2550\u2550\u2550"
                    "\u2550\u255d",
            ]),
        ]),
    ]),

    "archer's south castle tower":([
        "type": "south castle tower",
        "display name": "Archer's Tower",
        "dimensions": "3x2",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;36m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
            "archer":([
                "3-bit": "\x1b[0;33;1m",
                "8-bit": "\x1b[0;38;5;199;1m",
                "24-bit": "\x1b[0;38;2;100;20;100;1m"
            ]),
        ]),
        "construction": ([
            "duration": 800,
            "materials": ([
                "stone tower": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "stone tower second level": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "archer level": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "stone battlement": ([ "stone": 75, "wood": 25, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "stonemason": 8,
                "carpenter": 2,
                "foreman": 1,
                "blacksmith": 1,
                "architect": 1,
            ]),
        ]),
        "components":([
            "SCATOWER1": ([
                "ascii": "+=======+",
                "unicode": "\u2554\u2550\u2550"
                    "\u2550\u2550\u2550\u2550"
                    "\u2550\u2557",
            ]),
            "SCATOWER2": ([
                "ascii": "| archerx x xdefault |",
                "unicode": "\u2563 archer\u21a7 \u21a7 "
                    "\u21a7default \u2560",
            ]),
            "SCATOWER3": ([
                "ascii": "+=======+",
                "unicode": "\u255a\u2550\u2550"
                    "\u2550\u2550\u2550\u2550"
                    "\u2550\u255d",
            ]),
        ]),
    ]),

    "ballista south castle tower":([
        "type": "south castle tower",
        "display name": "Ballista Tower",
        "dimensions": "3x2",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;36m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
            "ballista":([
                "3-bit": "\x1b[0;33m",
                "8-bit": "\x1b[0;38;5;199m",
                "24-bit": "\x1b[0;38;2;100;20;100m"
            ]),
        ]),
        "construction": ([
            "duration": 840,
            "materials": ([
                "stone tower": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "stone tower second level": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "ballista platform": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "stone battlement": ([ "stone": 75, "wood": 25, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "stonemason": 8,
                "carpenter": 2,
                "foreman": 1,
                "blacksmith": 1,
                "architect": 1,
                "engineer": 1,
            ]),
        ]),
        "components":([
            "SCATOWER1": ([
                "ascii": "+=======+",
                "unicode": "\u2554\u2550\u2550"
                    "\u2550\u2550\u2550\u2550"
                    "\u2550\u2557",
            ]),
            "SCATOWER2": ([
                "ascii": "| ballistax   xdefault |",
                "unicode": "\u2563 ballista\u21e9   "
                    "\u21e9default \u2560",
            ]),
            "SCATOWER3": ([
                "ascii": "+=======+",
                "unicode": "\u255a\u2550\u2550"
                    "\u2550\u2550\u2550\u2550"
                    "\u2550\u255d",
            ]),
        ]),
    ]),

    "gate south castle tower":([
        "type": "south castle tower",
        "display name": "Gatehouse",
        "dimensions": "3x2",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;36m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
            "archer":([
                "3-bit": "\x1b[0;33;1m",
                "8-bit": "\x1b[0;38;5;199;1m",
                "24-bit": "\x1b[0;38;2;100;20;100;1m"
            ]),
            "gate":([
                "3-bit": "\x1b[0;32;1m",
                "8-bit": "\x1b[0;38;5;103;1m",
                "24-bit": "\x1b[0;38;2;112;128;144;1m",
            ]),
        ]),
        "construction": ([
            "duration": 960,
            "materials": ([
                "stone tower": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "stone tower second level": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "gatehouse": ([ "stone": 400, "wood": 150, "metal": 75, "textile": 0 ]),
                "stone battlement": ([ "stone": 75, "wood": 25, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "stonemason": 10,
                "carpenter": 5,
                "foreman": 1,
                "blacksmith": 1,
                "architect": 1,
                "engineer": 2,
            ]),
        ]),
        "components":([
            "SCATOWER1": ([
                "ascii": "+==---==+",
                "unicode": "\u2554\u2550\u2550"
                    "\u2550\u2550\u2550\u2550"
                    "\u2550\u2557",
            ]),
            "SCATOWER2": ([
                "ascii": "| archerx x xdefault |",
                "unicode": "\u2563 archer\u21a7 \u21a7 "
                    "\u21a7default \u2560",
            ]),
            "SCATOWER3": ([
                "ascii": "+=======+",
                "unicode": "\u255a\u2550\u2550"
                    "gate\u2504\u2504\u2504default"
                    "\u2550\u2550\u255d",
            ]),
        ]),
    ]),

    "unbuilt west castle tower":([
        "type": "west castle tower",
        "display name": "Unbuilt Tower",
        "dimensions": "3x2",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;9m",
                "24-bit": "\x1b[0;38;2;200;0;0m"
            ]),
        ]),
        "components":([
            "WCT1": ([
                "ascii": "....",
                "unicode": "\u2237\u2237\u2237\u2237",
            ]),
            "WCT2": ([
                "ascii": ".  .",
                "unicode": "\u2237  \u2237",
            ]),
            "WCT3": ([
                "ascii": ".  .",
                "unicode": "\u2237  \u2237",
            ]),
            "WCT4": ([
                "ascii": ".  .",
                "unicode": "\u2237  \u2237",
            ]),
            "WCT5": ([
                "ascii": ".  .",
                "unicode": "\u2237  \u2237",
            ]),
            "WCT6": ([
                "ascii": "....",
                "unicode": "\u2237\u2237\u2237\u2237",
            ]),
        ]),
    ]),

    "basic west castle tower":([
        "type": "west castle tower",
        "display name": "Basic Tower",
        "dimensions": "3x2",
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
                "stone tower": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
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
            "WCT1": ([
                "ascii": "+==+",
                "unicode": "\u2554\u2569\u2550\u2557",
            ]),
            "WCT2": ([
                "ascii": "|  |",
                "unicode": "\u2551  \u2551",
            ]),
            "WCT3": ([
                "ascii": "|  |",
                "unicode": "\u2551  \u2551",
            ]),
            "WCT4": ([
                "ascii": "|  |",
                "unicode": "\u2551  \u2551",
            ]),
            "WCT5": ([
                "ascii": "|  |",
                "unicode": "\u2551  \u2551",
            ]),
            "WCT6": ([
                "ascii": "+==+",
                "unicode": "\u255a\u2566\u2550\u255d",
            ]),
        ]),
    ]),

    "tall west castle tower":([
        "type": "west castle tower",
        "display name": "Tall Tower",
        "dimensions": "3x2",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;36m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
        ]),
        "construction": ([
            "duration": 600,
            "materials": ([
                "stone tower": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "stone tower second level": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
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
            "WCT1": ([
                "ascii": "+==+",
                "unicode": "\u2554\u2569\u2550\u2557",
            ]),
            "WCT2": ([
                "ascii": "|  |",
                "unicode": "\u2551\u2591\u2591\u2551",
            ]),
            "WCT3": ([
                "ascii": "|  |",
                "unicode": "\u2551\u2591\u2591\u2551",
            ]),
            "WCT4": ([
                "ascii": "|  |",
                "unicode": "\u2551\u2591\u2591\u2551",
            ]),
            "WCT5": ([
                "ascii": "|  |",
                "unicode": "\u2551\u2591\u2591\u2551",
            ]),
            "WCT6": ([
                "ascii": "+==+",
                "unicode": "\u255a\u2566\u2550\u255d",
            ]),
        ]),
    ]),

    "archer's west castle tower":([
        "type": "west castle tower",
        "display name": "Archer's Tower",
        "dimensions": "3x2",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;36m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
            "archer":([
                "3-bit": "\x1b[0;33;1m",
                "8-bit": "\x1b[0;38;5;199;1m",
                "24-bit": "\x1b[0;38;2;100;20;100;1m"
            ]),
        ]),
        "construction": ([
            "duration": 800,
            "materials": ([
                "stone tower": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "stone tower second level": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "archer level": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "stone battlement": ([ "stone": 75, "wood": 25, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "stonemason": 8,
                "carpenter": 2,
                "foreman": 1,
                "blacksmith": 1,
                "architect": 1,
            ]),
        ]),
        "components":([
            "WCT1": ([
                "ascii": "+==+",
                "unicode": "\u2554\u2569\u2550\u2557",
            ]),
            "WCT2": ([
                "ascii": "|archerxdefault |",
                "unicode": "\u2551 archer\u21a4default\u2551",
            ]),
            "WCT3": ([
                "ascii": "|  |",
                "unicode": "\u2551archer\u21a4default \u2551",
            ]),
            "WCT4": ([
                "ascii": "|  |",
                "unicode": "\u2551archer\u21a4default \u2551",
            ]),
            "WCT5": ([
                "ascii": "|archerxdefault |",
                "unicode": "\u2551 archer\u21a4default\u2551",
            ]),
            "WCT6": ([
                "ascii": "+==+",
                "unicode": "\u255a\u2566\u2550\u255d",
            ]),
        ]),
    ]),

    "ballista west castle tower":([
        "type": "west castle tower",
        "display name": "Ballista Tower",
        "dimensions": "3x2",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;36m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
            "ballista":([
                "3-bit": "\x1b[0;33m",
                "8-bit": "\x1b[0;38;5;199m",
                "24-bit": "\x1b[0;38;2;100;20;100m"
            ]),
        ]),
        "construction": ([
            "duration": 840,
            "materials": ([
                "stone tower": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "stone tower second level": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "ballista platform": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "stone battlement": ([ "stone": 75, "wood": 25, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "stonemason": 8,
                "carpenter": 2,
                "foreman": 1,
                "blacksmith": 1,
                "architect": 1,
                "engineer": 1,
            ]),
        ]),
        "components":([
            "WCT1": ([
                "ascii": "+==+",
                "unicode": "\u2554\u2569\u2550\u2557",
            ]),
            "WCT2": ([
                "ascii": "|ballistaxdefault |",
                "unicode": "\u2551ballista\u21eddefault \u2551",
            ]),
            "WCT3": ([
                "ascii": "|  |",
                "unicode": "\u2551  \u2551",
            ]),
            "WCT4": ([
                "ascii": "|  |",
                "unicode": "\u2551  \u2551",
            ]),
            "WCT5": ([
                "ascii": "|ballistaxdefault |",
                "unicode": "\u2551ballista\u21eddefault \u2551",
            ]),
            "WCT6": ([
                "ascii": "+==+",
                "unicode": "\u255a\u2566\u2550\u255d",
            ]),
        ]),
    ]),

    "gate west castle tower":([
        "type": "west castle tower",
        "display name": "Gatehouse",
        "dimensions": "3x2",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;36m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
            "archer":([
                "3-bit": "\x1b[0;33;1m",
                "8-bit": "\x1b[0;38;5;199;1m",
                "24-bit": "\x1b[0;38;2;100;20;100;1m"
            ]),
            "gate":([
                "3-bit": "\x1b[0;32;1m",
                "8-bit": "\x1b[0;38;5;103;1m",
                "24-bit": "\x1b[0;38;2;112;128;144;1m",
            ]),
        ]),
        "construction": ([
            "duration": 960,
            "materials": ([
                "stone tower": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "stone tower second level": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "gatehouse": ([ "stone": 400, "wood": 150, "metal": 75, "textile": 0 ]),
                "stone battlement": ([ "stone": 75, "wood": 25, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "stonemason": 10,
                "carpenter": 5,
                "foreman": 1,
                "blacksmith": 1,
                "architect": 1,
                "engineer": 2,
            ]),
        ]),
        "components":([
            "WCT1": ([
                "ascii": "+==+",
                "unicode": "\u2554\u2569\u2550\u2557",
            ]),
            "WCT2": ([
                "ascii": "|archerxdefault |",
                "unicode": "\u2551 archer\u21a4default\u2551",
            ]),
            "WCT3": ([
                "ascii": "gate|default  |",
                "unicode": "gate\u250aarcher\u21a4default \u2551",
            ]),
            "WCT4": ([
                "ascii": "gate|default  |",
                "unicode": "gate\u250aarcher\u21a4default \u2551",
            ]),
            "WCT5": ([
                "ascii": "|archerxdefault |",
                "unicode": "\u2551 archer\u21a4default\u2551",
            ]),
            "WCT6": ([
                "ascii": "+==+",
                "unicode": "\u255a\u2566\u2550\u255d",
            ]),
        ]),
    ]),

    "unbuilt east castle tower":([
        "type": "east castle tower",
        "display name": "Unbuilt Tower",
        "dimensions": "3x2",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;9m",
                "24-bit": "\x1b[0;38;2;200;0;0m"
            ]),
        ]),
        "components":([
            "ECT1": ([
                "ascii": "....",
                "unicode": "\u2237\u2237\u2237\u2237",
            ]),
            "ECT2": ([
                "ascii": ".  .",
                "unicode": "\u2237  \u2237",
            ]),
            "ECT3": ([
                "ascii": ".  .",
                "unicode": "\u2237  \u2237",
            ]),
            "ECT4": ([
                "ascii": ".  .",
                "unicode": "\u2237  \u2237",
            ]),
            "ECT5": ([
                "ascii": ".  .",
                "unicode": "\u2237  \u2237",
            ]),
            "ECT6": ([
                "ascii": "....",
                "unicode": "\u2237\u2237\u2237\u2237",
            ]),
        ]),
    ]),

    "basic east castle tower":([
        "type": "east castle tower",
        "display name": "Basic Tower",
        "dimensions": "3x2",
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
                "stone tower": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
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
            "ECT1": ([
                "ascii": "+==+",
                "unicode": "\u2554\u2550\u2569\u2557",
            ]),
            "ECT2": ([
                "ascii": "|  |",
                "unicode": "\u2551  \u2551",
            ]),
            "ECT3": ([
                "ascii": "|  |",
                "unicode": "\u2551  \u2551",
            ]),
            "ECT4": ([
                "ascii": "|  |",
                "unicode": "\u2551  \u2551",
            ]),
            "ECT5": ([
                "ascii": "|  |",
                "unicode": "\u2551  \u2551",
            ]),
            "ECT6": ([
                "ascii": "+==+",
                "unicode": "\u255a\u2550\u2566\u255d",
            ]),
        ]),
    ]),

    "tall east castle tower":([
        "type": "east castle tower",
        "display name": "Tall Tower",
        "dimensions": "3x2",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;36m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
        ]),
        "construction": ([
            "duration": 600,
            "materials": ([
                "stone tower": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "stone tower second level": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
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
            "ECT1": ([
                "ascii": "+==+",
                "unicode": "\u2554\u2550\u2569\u2557",
            ]),
            "ECT2": ([
                "ascii": "|  |",
                "unicode": "\u2551\u2591\u2591\u2551",
            ]),
            "ECT3": ([
                "ascii": "|  |",
                "unicode": "\u2551\u2591\u2591\u2551",
            ]),
            "ECT4": ([
                "ascii": "|  |",
                "unicode": "\u2551\u2591\u2591\u2551",
            ]),
            "ECT5": ([
                "ascii": "|  |",
                "unicode": "\u2551\u2591\u2591\u2551",
            ]),
            "ECT6": ([
                "ascii": "+==+",
                "unicode": "\u255a\u2550\u2566\u255d",
            ]),
        ]),
    ]),

    "archer's east castle tower":([
        "type": "east castle tower",
        "display name": "Archer's Tower",
        "dimensions": "3x2",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;36m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
            "archer":([
                "3-bit": "\x1b[0;33;1m",
                "8-bit": "\x1b[0;38;5;199;1m",
                "24-bit": "\x1b[0;38;2;100;20;100;1m"
            ]),
        ]),
        "construction": ([
            "duration": 800,
            "materials": ([
                "stone tower": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "stone tower second level": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "archer level": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "stone battlement": ([ "stone": 75, "wood": 25, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "stonemason": 8,
                "carpenter": 2,
                "foreman": 1,
                "blacksmith": 1,
                "architect": 1,
            ]),
        ]),
        "components":([
            "ECT1": ([
                "ascii": "+==+",
                "unicode": "\u2554\u2550\u2569\u2557",
            ]),
            "ECT2": ([
                "ascii": "|archerxdefault |",
                "unicode": "\u2551archer\u21a6default \u2551",
            ]),
            "ECT3": ([
                "ascii": "|  |",
                "unicode": "\u2551 archer\u21a6default\u2551",
            ]),
            "ECT4": ([
                "ascii": "|  |",
                "unicode": "\u2551 archer\u21a6default\u2551",
            ]),
            "ECT5": ([
                "ascii": "|archerxdefault |",
                "unicode": "\u2551archer\u21a6default \u2551",
            ]),
            "ECT6": ([
                "ascii": "+==+",
                "unicode": "\u255a\u2550\u2566\u255d",
            ]),
        ]),
    ]),

    "ballista east castle tower":([
        "type": "east castle tower",
        "display name": "Ballista Tower",
        "dimensions": "3x2",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;36m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
            "ballista":([
                "3-bit": "\x1b[0;33m",
                "8-bit": "\x1b[0;38;5;199m",
                "24-bit": "\x1b[0;38;2;100;20;100m"
            ]),
        ]),
        "construction": ([
            "duration": 840,
            "materials": ([
                "stone tower": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "stone tower second level": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "ballista platform": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "stone battlement": ([ "stone": 75, "wood": 25, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "stonemason": 8,
                "carpenter": 2,
                "foreman": 1,
                "blacksmith": 1,
                "architect": 1,
                "engineer": 1,
            ]),
        ]),
        "components":([
            "ECT1": ([
                "ascii": "+==+",
                "unicode": "\u2554\u2550\u2569\u2557",
            ]),
            "ECT2": ([
                "ascii": "|ballistaxdefault |",
                "unicode": "\u2551 ballista\u21eddefault\u2551",
            ]),
            "ECT3": ([
                "ascii": "|  |",
                "unicode": "\u2551  \u2551",
            ]),
            "ECT4": ([
                "ascii": "|  |",
                "unicode": "\u2551  \u2551",
            ]),
            "ECT5": ([
                "ascii": "|ballistaxdefault |",
                "unicode": "\u2551 ballista\u21eddefault\u2551",
            ]),
            "ECT6": ([
                "ascii": "+==+",
                "unicode": "\u255a\u2550\u2566\u255d",
            ]),
        ]),
    ]),

    "gate east castle tower":([
        "type": "east castle tower",
        "display name": "Gatehouse",
        "dimensions": "3x2",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;36m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
            ]),
            "archer":([
                "3-bit": "\x1b[0;33;1m",
                "8-bit": "\x1b[0;38;5;199;1m",
                "24-bit": "\x1b[0;38;2;100;20;100;1m"
            ]),
            "gate":([
                "3-bit": "\x1b[0;32;1m",
                "8-bit": "\x1b[0;38;5;103;1m",
                "24-bit": "\x1b[0;38;2;112;128;144;1m",
            ]),
        ]),
        "construction": ([
            "duration": 960,
            "materials": ([
                "stone tower": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "stone tower second level": ([ "stone": 250, "wood": 50, "metal": 10, "textile": 0 ]),
                "gatehouse": ([ "stone": 400, "wood": 150, "metal": 75, "textile": 0 ]),
                "stone battlement": ([ "stone": 75, "wood": 25, "metal": 5, "textile": 0 ]),
            ]),
            "workers": ([
                "stonemason": 10,
                "carpenter": 5,
                "foreman": 1,
                "blacksmith": 1,
                "architect": 1,
                "engineer": 2,
            ]),
        ]),
        "components":([
            "ECT1": ([
                "ascii": "+==+",
                "unicode": "\u2554\u2550\u2569\u2557",
            ]),
            "ECT2": ([
                "ascii": "| archerxdefault|",
                "unicode": "\u2551archer\u21a6default \u2551",
            ]),
            "ECT3": ([
                "ascii": "|  gate|default",
                "unicode": "\u2551 archer\u21a6defaultgate\u250a",
            ]),
            "ECT4": ([
                "ascii": "|  gate|default",
                "unicode": "\u2551 archer\u21a6defaultgate\u250a",
            ]),
            "ECT5": ([
                "ascii": "| archerxdefault|",
                "unicode": "\u2551archer\u21a6default \u2551",
            ]),
            "ECT6": ([
                "ascii": "+==+",
                "unicode": "\u255a\u2550\u2566\u255d",
            ]),
        ]),
    ]),
]);

#endif
