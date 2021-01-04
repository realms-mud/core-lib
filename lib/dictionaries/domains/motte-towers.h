//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef motteTowers_h
#define motteTowers_h

private mapping MotteTowers = ([
    "unbuilt northwest tower":([
        "type": "northwest tower",
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
            "NWMTR1": ([
                "ascii":"......",
                "unicode": "\u2237\u2237\u2237\u2237"
                    "\u2237\u2237",
            ]),
            "NWMTR2": ([
                "ascii":".    .",
                "unicode": "\u2237    \u2237",
            ]),
            "NWMTR3": ([
                "ascii":".     ",
                "unicode": "\u2237     ",
            ]),
            "NWMTR4": ([
                "ascii":"..    ",
                "unicode": "\u2237\u2237    ",
            ]),
        ]),
    ]),

    "basic northwest tower":([
        "type": "northwest tower",
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
            "NWMTR1": ([
                "ascii":"+----+",
                "unicode": "\u2554\u2550\u2550\u2550"
                    "\u2550\u2557",
            ]),
            "NWMTR2": ([
                "ascii":"|    |",
                "unicode": "\u2551    \u2560",
            ]),
            "NWMTR3": ([
                "ascii":"|     ",
                "unicode": "\u2551    \u2502",
            ]),
            "NWMTR4": ([
                "ascii":"+-    ",
                "unicode": "\u255a\u2550\u2566\u2500"
                    "\u2500\u2518",
            ]),
        ]),
    ]),

    "tall northwest tower":([
        "type": "northwest tower",
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
            "NWMTR1": ([
                "ascii":"+====+",
                "unicode": "\u2554\u2550\u2550\u2550"
                    "\u2550\u2557",
            ]),
            "NWMTR2": ([
                "ascii":"|    |",
                "unicode": "\u2551\u2591\u2591\u2591"
                    "\u2591\u2560",
            ]),
            "NWMTR3": ([
                "ascii":"|     ",
                "unicode": "\u2551\u2591\u2591\u2591"
                    "\u2591\u2502",
            ]),
            "NWMTR4": ([
                "ascii":"+=    ",
                "unicode": "\u255a\u2550\u2566\u2500"
                    "\u2500\u2518",
            ]),
        ]),
    ]),

    "archer's northwest tower":([
        "type": "northwest tower",
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
            "NWMTR1": ([
                "ascii":"+====+",
                "unicode": "\u2554\u2550\u2550\u2550"
                    "\u2550\u2557",
            ]),
            "NWMTR2": ([
                "ascii":"|+archer--default+|",
                "unicode": "\u2551\u250farcher\u21a5\u21a5"
                    "default\u2513\u2560",
            ]),
            "NWMTR3": ([
                "ascii":"|+--+ ",
                "unicode": "\u2551\u2517\u2501\u2501"
                    "\u251b\u2502",
            ]),
            "NWMTR4": ([
                "ascii":"+=    ",
                "unicode": "\u255a\u2550\u2566\u2500"
                    "\u2500\u2518",
            ]),
        ]),
    ]),

    "ballista northwest tower":([
        "type": "northwest tower",
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
            "NWMTR1": ([
                "ascii":"+====+",
                "unicode": "\u2554\u2550\u2550\u2550"
                    "\u2550\u2557",
            ]),
            "NWMTR2": ([
                "ascii":"|+ballista~~default+|",
                "unicode": "\u2551\u256dballista\u21ed\u21ed"
                    "default\u256e\u2560",
            ]),
            "NWMTR3": ([
                "ascii":"|+~~+ ",
                "unicode": "\u2551\u2570\u2500\u2500"
                    "\u256f\u2502",
            ]),
            "NWMTR4": ([
                "ascii":"+=    ",
                "unicode": "\u255a\u2550\u2566\u2500"
                    "\u2500\u2518",
            ]),
        ]),
    ]),

    "catapult northwest tower":([
        "type": "northwest tower",
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
            "NWMTR1": ([
                "ascii":"+====+",
                "unicode": "\u2554\u2550\u2550\u2550"
                    "\u2550\u2557",
            ]),
            "NWMTR2": ([
                "ascii":"|+catapult~~default+|",
                "unicode": "\u2551\u250fcatapult\u21ef\u21ad"
                    "default\u2513\u2560",
            ]),
            "NWMTR3": ([
                "ascii":"|+~~+ ",
                "unicode": "\u2551\u2517\u2501\u2501"
                    "\u251b\u2502",
            ]),
            "NWMTR4": ([
                "ascii":"+=    ",
                "unicode": "\u255a\u2550\u2566\u2500"
                    "\u2500\u2518",
            ]),
        ]),
    ]),

    "trebuchet northwest tower":([
        "type": "northwest tower",
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
            "NWMTR1": ([
                "ascii":"+====+",
                "unicode": "\u2554\u2550\u2550\u2550"
                    "\u2550\u2557",
            ]),
            "NWMTR2": ([
                "ascii":"|+trebuchet~~default+|",
                "unicode": "\u2551\u250ftrebuchet\u21ef\u21f2"
                    "default\u2513\u2560",
            ]),
            "NWMTR3": ([
                "ascii":"|+~~+ ",
                "unicode": "\u2551\u2517\u2501\u2501"
                    "\u251b\u2502",
            ]),
            "NWMTR4": ([
                "ascii":"+=    ",
                "unicode": "\u255a\u2550\u2566\u2500"
                    "\u2500\u2518",
            ]),
        ]),
    ]),

    "mage northwest tower":([
        "type": "northwest tower",
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
            "NWMTR1": ([
                "ascii":"+====+",
                "unicode": "\u2554\u2550\u2550\u2550"
                    "\u2550\u2557",
            ]),
            "NWMTR2": ([
                "ascii":"|+mage~~default+|",
                "unicode": "\u2551\u250fmage\u22d0\u22d1"
                    "default\u2513\u2560",
            ]),
            "NWMTR3": ([
                "ascii":"|+~~+ ",
                "unicode": "\u2551\u2517\u2501\u2501"
                    "\u251b\u2502",
            ]),
            "NWMTR4": ([
                "ascii":"+=    ",
                "unicode": "\u255a\u2550\u2566\u2500"
                    "\u2500\u2518",
            ]),
        ]),
    ]),

    "unbuilt north tower":([
        "type": "north tower",
        "display name": "Unbuilt Tower",
        "dimensions": "1x1",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;9m",
                "24-bit": "\x1b[0;38;2;200;0;0m"
            ]),
        ]),
        "components":([
            "NT1": ([
                "ascii": "...",
                "unicode": "\u2237\u2237\u2237",
            ]),
            "NT2": ([
                "ascii": ". .",
                "unicode": "\u2237 \u2237",
            ]),
        ]),
    ]),

    "basic north tower":([
        "type": "north tower",
        "display name": "Basic Tower",
        "dimensions": "1x1",
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
            "NT1": ([
                "ascii": "+-+",
                "unicode": "\u2554\u2550\u2557",
            ]),
            "NT2": ([
                "ascii": "+ +",
                "unicode": "\u255d \u255a",
            ]),
        ]),
    ]),

    "tall north tower":([
        "type": "north tower",
        "display name": "Tall Tower",
        "dimensions": "1x1",
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
            "NT1": ([
                "ascii": "+=+",
                "unicode": "\u2554\u2550\u2557",
            ]),
            "NT2": ([
                "ascii": "+ +",
                "unicode": "\u255d\u2591\u255a",
            ]),
        ]),
    ]),

    "gate north tower":([
        "type": "north tower",
        "display name": "Gatehouse",
        "dimensions": "1x1",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;36m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
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
            "NT1": ([
                "ascii": "+gate-default+",
                "unicode": "\u2554gate\u2504default\u2557",
            ]),
            "NT2": ([
                "ascii": "+ +",
                "unicode": "\u255d\u2591\u255a",
            ]),
        ]),
    ]),

    "archer's north tower":([
        "type": "north tower",
        "display name": "Archer's Tower",
        "dimensions": "1x1",
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
            "NT1": ([
                "ascii": "+archer-default+",
                "unicode": "\u2554archer\u21a5default\u2557",
            ]),
            "NT2": ([
                "ascii": "+ +",
                "unicode": "\u255d\u2591\u255a",
            ]),
        ]),
    ]),

    "ballista north tower":([
        "type": "north tower",
        "display name": "Ballista Tower",
        "dimensions": "1x1",
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
            "NT1": ([
                "ascii": "+ballista-default+",
                "unicode": "\u2554ballista\u21eddefault\u2557",
            ]),
            "NT2": ([
                "ascii": "+ +",
                "unicode": "\u255d\u2591\u255a",
            ]),
        ]),
    ]),

    "unbuilt northeast tower":([
        "type": "northeast tower",
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
            "NEMTR1": ([
                "ascii":"......",
                "unicode": "\u2237\u2237\u2237\u2237"
                    "\u2237\u2237",
            ]),
            "NEMTR2": ([
                "ascii":".    .",
                "unicode": "\u2237    \u2237",
            ]),
            "NEMTR3": ([
                "ascii":"     .",
                "unicode": "     \u2237",
            ]),
            "NEMTR4": ([
                "ascii":"    ..",
                "unicode": "    \u2237\u2237",
            ]),
        ]),
    ]),

    "basic northeast tower":([
        "type": "northeast tower",
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
            "NEMTR1": ([
                "ascii":"+====+",
                "unicode": "\u2554\u2550\u2550\u2550"
                    "\u2550\u2557",
            ]),
            "NEMTR2": ([
                "ascii":"|    |",
                "unicode": "\u2563    \u2551",
            ]),
            "NEMTR3": ([
                "ascii":"     |",
                "unicode": "\u2502    \u2551",
            ]),
            "NEMTR4": ([
                "ascii":"    =+",
                "unicode": "\u2514\u2500\u2500\u2566"
                    "\u2550\u255d",
            ]),
        ]),
    ]),

    "tall northeast tower":([
        "type": "northeast tower",
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
            "NEMTR1": ([
                "ascii":"+====+",
                "unicode": "\u2554\u2550\u2550\u2550"
                    "\u2550\u2557",
            ]),
            "NEMTR2": ([
                "ascii":"|    |",
                "unicode": "\u2563\u2591\u2591\u2591"
                    "\u2591\u2551",
            ]),
            "NEMTR3": ([
                "ascii":"     |",
                "unicode": "\u2502\u2591\u2591\u2591"
                    "\u2591\u2551",
            ]),
            "NEMTR4": ([
                "ascii":"    =+",
                "unicode": "\u2514\u2500\u2500\u2566"
                    "\u2550\u255d",
            ]),
        ]),
    ]),

    "archer's northeast tower":([
        "type": "northeast tower",
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
            "NEMTR1": ([
                "ascii":"+====+",
                "unicode": "\u2554\u2550\u2550\u2550"
                    "\u2550\u2557",
            ]),
            "NEMTR2": ([
                "ascii":"|+archer--default+|",
                "unicode": "\u2563\u250farcher\u21a5\u21a5"
                    "default\u2513\u2551",
            ]),
            "NEMTR3": ([
                "ascii":" +--+|",
                "unicode": "\u2502\u2517\u2501\u2501"
                    "\u251b\u2551",
            ]),
            "NEMTR4": ([
                "ascii":"    =+",
                "unicode": "\u2514\u2500\u2500\u2566"
                    "\u2550\u255d",
            ]),
        ]),
    ]),

    "ballista northeast tower":([
        "type": "northeast tower",
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
            "NEMTR1": ([
                "ascii":"+====+",
                "unicode": "\u2554\u2550\u2550\u2550"
                    "\u2550\u2557",
            ]),
            "NEMTR2": ([
                "ascii":"|+ballista~~default+|",
                "unicode": "\u2563\u256dballista\u21ed\u21ed"
                    "default\u256e\u2551",
            ]),
            "NEMTR3": ([
                "ascii":" +~~+|",
                "unicode": "\u2502\u2570\u2500\u2500"
                    "\u256f\u2551",
            ]),
            "NEMTR4": ([
                "ascii":"    =+",
                "unicode": "\u2514\u2500\u2500\u2566"
                    "\u2550\u255d",
            ]),
        ]),
    ]),

    "catapult northeast tower":([
        "type": "northeast tower",
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
            "NEMTR1": ([
                "ascii":"+====+",
                "unicode": "\u2554\u2550\u2550\u2550"
                    "\u2550\u2557",
            ]),
            "NEMTR2": ([
                "ascii":"|+catapult~~default+|",
                "unicode": "\u2563\u250fcatapult\u21ef\u21ad"
                    "default\u2513\u2551",
            ]),
            "NEMTR3": ([
                "ascii":" +~~+|",
                "unicode": "\u2502\u2517\u2501\u2501"
                    "\u251b\u2551",
            ]),
            "NEMTR4": ([
                "ascii":"    =+",
                "unicode": "\u2514\u2500\u2500\u2566"
                    "\u2550\u255d",
            ]),
        ]),
    ]),

    "trebuchet northeast tower":([
        "type": "northeast tower",
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
            "NEMTR1": ([
                "ascii":"+====+",
                "unicode": "\u2554\u2550\u2550\u2550"
                    "\u2550\u2557",
            ]),
            "NEMTR2": ([
                "ascii":"|+trebuchet~~default+|",
                "unicode": "\u2563\u250ftrebuchet\u21ef\u21f2"
                    "default\u2513\u2551",
            ]),
            "NEMTR3": ([
                "ascii":" +~~+|",
                "unicode": "\u2502\u2517\u2501\u2501"
                    "\u251b\u2551",
            ]),
            "NEMTR4": ([
                "ascii":"    =+",
                "unicode": "\u2514\u2500\u2500\u2566"
                    "\u2550\u255d",
            ]),
        ]),
    ]),

    "mage northeast tower":([
        "type": "northeast tower",
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
            "NEMTR1": ([
                "ascii":"+====+",
                "unicode": "\u2554\u2550\u2550\u2550"
                    "\u2550\u2557",
            ]),
            "NEMTR2": ([
                "ascii":"|+mage~~default+|",
                "unicode": "\u2563\u250fmage\u22d0\u22d1"
                    "default\u2513\u2551",
            ]),
            "NEMTR3": ([
                "ascii":" +~~+|",
                "unicode": "\u2502\u2517\u2501\u2501"
                    "\u251b\u2551",
            ]),
            "NEMTR4": ([
                "ascii":"    =+",
                "unicode": "\u2514\u2500\u2500\u2566"
                    "\u2550\u255d",
            ]),
        ]),
    ]),

    "unbuilt west tower":([
        "type": "west tower",
        "display name": "Unbuilt Tower",
        "dimensions": "1x1",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;9m",
                "24-bit": "\x1b[0;38;2;200;0;0m"
            ]),
        ]),
        "components":([
            "WM1": ([
                "ascii": "...",
                "unicode": "\u2237\u2237\u2237",
            ]),
            "WM2": ([
                "ascii": "...",
                "unicode": "\u2237\u2237\u2237",
            ]),
        ]),
    ]),

    "basic west tower":([
        "type": "west tower",
        "display name": "Basic Tower",
        "dimensions": "1x1",
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
            "WM1": ([
                "ascii": "+-+",
                "unicode": "\u2554\u2550\u255d",
            ]),
            "WM2": ([
                "ascii": "+-+",
                "unicode": "\u255a\u2550\u2557",
            ]),
        ]),
    ]),

    "tall west tower":([
        "type": "west tower",
        "display name": "Tall Tower",
        "dimensions": "1x1",
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
            "WM1": ([
                "ascii": "+-+",
                "unicode": "\u2554\u2550\u255d",
            ]),
            "WM2": ([
                "ascii": "+-+",
                "unicode": "\u255a\u2550\u2557",
            ]),
        ]),
    ]),

    "gate west tower":([
        "type": "west tower",
        "display name": "Gatehouse",
        "dimensions": "1x1",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;36m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
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
            "WM1": ([
                "ascii": "gate+default-+",
                "unicode": "gate\u2552default\u2550\u255d",
            ]),
            "WM2": ([
                "ascii": "gate+default-+",
                "unicode": "gate\u2558default\u2550\u2557",
            ]),
        ]),
    ]),

    "archer's west tower":([
        "type": "west tower",
        "display name": "Archer's Tower",
        "dimensions": "1x1",
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
            "WM1": ([
                "ascii": "archer+default-+",
                "unicode": "\u2554archer\u21f2default\u255d",
            ]),
            "WM2": ([
                "ascii": "archer+default-+",
                "unicode": "\u255a\u2550\u2557",
            ]),
        ]),
    ]),

    "ballista west tower":([
        "type": "west tower",
        "display name": "Ballista Tower",
        "dimensions": "1x1",
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
            "WM1": ([
                "ascii": "ballista+default-+",
                "unicode": "\u2554ballista\u21eddefault\u255d",
            ]),
            "WM2": ([
                "ascii": "ballista+default-+",
                "unicode": "\u255a\u2550\u2557",
            ]),
        ]),
    ]),

    "unbuilt east tower":([
        "type": "east tower",
        "display name": "Unbuilt Tower",
        "dimensions": "1x1",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;9m",
                "24-bit": "\x1b[0;38;2;200;0;0m"
            ]),
        ]),
        "components":([
            "EM1": ([
                "ascii": "...",
                "unicode": "\u2237\u2237\u2237",
            ]),
            "EM2": ([
                "ascii": "...",
                "unicode": "\u2237\u2237\u2237",
            ]),
        ]),
    ]),

    "basic east tower":([
        "type": "east tower",
        "display name": "Basic Tower",
        "dimensions": "1x1",
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
            "EM1": ([
                "ascii": "+-+",
                "unicode": "\u255a\u2550\u2557",
            ]),
            "EM2": ([
                "ascii": "+-+",
                "unicode": "\u2554\u2550\u255d",
            ]),
        ]),
    ]),

    "tall east tower":([
        "type": "east tower",
        "display name": "Tall Tower",
        "dimensions": "1x1",
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
            "EM1": ([
                "ascii": "+-+",
                "unicode": "\u255a\u2550\u2557",
            ]),
            "EM2": ([
                "ascii": "+-+",
                "unicode": "\u2554\u2550\u255d",
            ]),
        ]),
    ]),

    "gate east tower":([
        "type": "east tower",
        "display name": "Gatehouse",
        "dimensions": "1x1",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;36m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
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
            "EM1": ([
                "ascii": "+-gate+default",
                "unicode": "\u255a\u2550gate\u2555default",
            ]),
            "EM2": ([
                "ascii": "+-gate+default",
                "unicode": "\u2554\u2550gate\u255bdefault",
            ]),
        ]),
    ]),

    "archer's east tower":([
        "type": "east tower",
        "display name": "Archer's Tower",
        "dimensions": "1x1",
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
            "EM1": ([
                "ascii": "+-archer+default",
                "unicode": "\u255aarcher\u21f2default\u2557",
            ]),
            "EM2": ([
                "ascii": "+-archer+default",
                "unicode": "\u2554\u2550\u255d",
            ]),
        ]),
    ]),

    "ballista east tower":([
        "type": "east tower",
        "display name": "Ballista Tower",
        "dimensions": "1x1",
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
            "EM1": ([
                "ascii": "+-ballista+default",
                "unicode": "\u255aballista\u21eddefault\u2557",
            ]),
            "EM2": ([
                "ascii": "+-ballista+default",
                "unicode": "\u2554\u2550\u255d",
            ]),
        ]),
    ]),

    "unbuilt southwest tower":([
        "type": "southwest tower",
        "display name": "Unbuilt Tower",
        "dimensions": "1x1",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;9m",
                "24-bit": "\x1b[0;38;2;200;0;0m"
            ]),
        ]),
        "components":([
            "SWMTR1": ([
                "ascii":"..    ",
                "unicode": "\u2237\u2237    ",
            ]),
            "SWMTR2": ([
                "ascii":".     ",
                "unicode": "\u2237     ",
            ]),
            "SWMTR3": ([
                "ascii":".    .",
                "unicode": "\u2237    \u2237",
            ]),
            "SWMTR4": ([
                "ascii":"......",
                "unicode": "\u2237\u2237\u2237"
                    "\u2237\u2237\u2237",
            ]),
        ]),
    ]),

    "basic southwest tower":([
        "type": "southwest tower",
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
            "SWMTR1": ([
                "ascii":"+-    ",
                "unicode": "\u2554\u2550\u2569\u2500"
                    "\u2500\u2510",
            ]),
            "SWMTR2": ([
                "ascii":"|     ",
                "unicode": "\u2551    \u2502",
            ]),
            "SWMTR3": ([
                "ascii":"|    |",
                "unicode": "\u2551    \u2560",
            ]),
            "SWMTR4": ([
                "ascii": "+----+",
                "unicode": "\u255a\u2550\u2550\u2550"
                    "\u2550\u255d",
            ]),
        ]),
    ]),

    "tall southwest tower":([
        "type": "southwest tower",
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
            "SWMTR1": ([
                "ascii":"+=    ",
                "unicode": "\u2554\u2550\u2569\u2500"
                    "\u2500\u2510",
            ]),
            "SWMTR2": ([
                "ascii":"|     ",
                "unicode": "\u2551\u2591\u2591\u2591"
                    "\u2591\u2502",
            ]),
            "SWMTR3": ([
                "ascii":"|    |",
                "unicode": "\u2551\u2591\u2591\u2591"
                    "\u2591\u2560",
            ]),
            "SWMTR4": ([
                "ascii": "+====+",
                "unicode": "\u255a\u2550\u2550\u2550"
                    "\u2550\u255d",
            ]),
        ]),
    ]),

    "archer's southwest tower":([
        "type": "southwest tower",
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
            "SWMTR1": ([
                "ascii":"+=    ",
                "unicode": "\u2554\u2550\u2569\u2500"
                    "\u2500\u2510",
            ]),
            "SWMTR2": ([
                "ascii":"|+--+ ",
                "unicode": "\u2551\u250f\u2501\u2501"
                    "\u2513\u2502",
            ]),
            "SWMTR3": ([
                "ascii":"|+archer--default+|",
                "unicode": "\u2551\u2517archer\u21a7\u21a7"
                    "default\u251b\u2560",
            ]),
            "SWMTR4": ([
                "ascii": "+====+",
                "unicode": "\u255a\u2550\u2550\u2550"
                    "\u2550\u255d",
            ]),
        ]),
    ]),

    "ballista southwest tower":([
        "type": "southwest tower",
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
            "SWMTR1": ([
                "ascii":"+=    ",
                "unicode": "\u2554\u2550\u2569\u2500"
                    "\u2500\u2510",
            ]),
            "SWMTR2": ([
                "ascii":"|+~~+ ",
                "unicode": "\u2551\u250f\u2501\u2501"
                    "\u2513\u2502",
            ]),
            "SWMTR3": ([
                "ascii":"|+ballista~~default+|",
                "unicode": "\u2551\u2517ballista\u21e9\u21e9"
                    "default\u251b\u2560",
            ]),
            "SWMTR4": ([
                "ascii": "+====+",
                "unicode": "\u255a\u2550\u2550\u2550"
                    "\u2550\u255d",
            ]),
        ]),
    ]),

    "catapult southwest tower":([
        "type": "southwest tower",
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
            "SWMTR1": ([
                "ascii":"+=    ",
                "unicode": "\u2554\u2550\u2569\u2500"
                    "\u2500\u2510",
            ]),
            "SWMTR2": ([
                "ascii":"|+~~+ ",
                "unicode": "\u2551\u250f\u2501\u2501"
                    "\u2513\u2502",
            ]),
            "SWMTR3": ([
                "ascii":"|+catapult~~default+|",
                "unicode": "\u2551\u2517catapult\u21ef\u21ad"
                    "default\u251b\u2560",
            ]),
            "SWMTR4": ([
                "ascii": "+====+",
                "unicode": "\u255a\u2550\u2550\u2550"
                    "\u2550\u255d",
            ]),
        ]),
    ]),

    "trebuchet southwest tower":([
        "type": "southwest tower",
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
            "SWMTR1": ([
                "ascii":"+=    ",
                "unicode": "\u2554\u2550\u2569\u2500"
                    "\u2500\u2510",
            ]),
            "SWMTR2": ([
                "ascii":"|+~~+ ",
                "unicode": "\u2551\u250f\u2501\u2501"
                    "\u2513\u2502",
            ]),
            "SWMTR3": ([
                "ascii":"|+trebuchet~~default+|",
                "unicode": "\u2551\u2517trebuchet\u21ef\u21f2"
                    "default\u251b\u2560",
            ]),
            "SWMTR4": ([
                "ascii": "+====+",
                "unicode": "\u255a\u2550\u2550\u2550"
                    "\u2550\u255d",
            ]),
        ]),
    ]),

    "mage southwest tower":([
        "type": "southwest tower",
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
            "SWMTR1": ([
                "ascii":"+=    ",
                "unicode": "\u2554\u2550\u2569\u2500"
                    "\u2500\u2510",
            ]),
            "SWMTR2": ([
                "ascii":"|+~~+ ",
                "unicode": "\u2551\u250f\u2501\u2501"
                    "\u2513\u2502",
            ]),
            "SWMTR3": ([
                "ascii":"|+mage~~default+|",
                "unicode": "\u2551\u2517mage\u22d0\u22d1"
                    "default\u251b\u2560",
            ]),
            "SWMTR4": ([
                "ascii": "+====+",
                "unicode": "\u255a\u2550\u2550\u2550"
                    "\u2550\u255d",
            ]),
        ]),
    ]),

    "unbuilt south tower":([
        "type": "south tower",
        "display name": "Unbuilt Tower",
        "dimensions": "1x1",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;9m",
                "24-bit": "\x1b[0;38;2;200;0;0m"
            ]),
        ]),
        "components":([
            "ST1": ([
                "ascii": ". .",
                "unicode": "\u2237 \u2237",
            ]),
            "ST2": ([
                "ascii": "...",
                "unicode": "\u2237\u2237\u2237",
            ]),
        ]),
    ]),

    "basic south tower":([
        "type": "south tower",
        "display name": "Basic Tower",
        "dimensions": "1x1",
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
            "ST1": ([
                "ascii": "+ +",
                "unicode": "\u2557 \u2554",
            ]),
            "ST2": ([
                "ascii": "+-+",
                "unicode": "\u255a\u2550\u255d",
            ]),
        ]),
    ]),

    "tall south tower":([
        "type": "south tower",
        "display name": "Tall Tower",
        "dimensions": "1x1",
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
            "ST1": ([
                "ascii": "+ +",
                "unicode": "\u2557\u2591\u2554",
            ]),
            "ST2": ([
                "ascii": "+-+",
                "unicode": "\u255a\u2550\u255d",
            ]),
        ]),
    ]),

    "gate south tower":([
        "type": "south tower",
        "display name": "Gatehouse",
        "dimensions": "1x1",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;36m",
                "8-bit": "\x1b[0;38;5;103m",
                "24-bit": "\x1b[0;38;2;112;128;144m",
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
            "ST1": ([
                "ascii": "+ +",
                "unicode": "\u2557\u2591\u2554",
            ]),
            "ST2": ([
                "ascii": "+gate-default+",
                "unicode": "\u255agate\u2504default\u255d",
            ]),
        ]),
    ]),

    "archer's south tower":([
        "type": "south tower",
        "display name": "Archer's Tower",
        "dimensions": "1x1",
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
            "ST1": ([
                "ascii": "+ +",
                "unicode": "\u2557\u2591\u2554",
            ]),
            "ST2": ([
                "ascii": "+archer-default+",
                "unicode": "\u255aarcher\u21a7default\u255d",
            ]),
        ]),
    ]),

    "ballista south tower":([
        "type": "south tower",
        "display name": "Ballista Tower",
        "dimensions": "1x1",
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
            "ST1": ([
                "ascii": "+ +",
                "unicode": "\u2557\u2591\u2554",
            ]),
            "ST2": ([
                "ascii": "+ballista-default+",
                "unicode": "\u255aballista\u21e9default\u255d",
            ]),
        ]),
    ]),

    "unbuilt southeast tower":([
        "type": "southeast tower",
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
            "SEMTR1": ([
                "ascii":"    ..",
                "unicode": "    \u2237\u2237",
            ]),
            "SEMTR2": ([
                "ascii":"     .",
                "unicode": "     \u2237",
            ]),
            "SEMTR3": ([
                "ascii":".    .",
                "unicode": "\u2237    \u2237",
            ]),
            "SEMTR4": ([
                "ascii":"......",
                "unicode": "\u2237\u2237\u2237"
                    "\u2237\u2237\u2237",
            ]),
        ]),
    ]),

    "basic southeast tower":([
        "type": "southeast tower",
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
            "SEMTR1": ([
                "ascii":"    -+",
                "unicode": "\u250c\u2500\u2500\u2569"
                    "\u2550\u2557",
            ]),
            "SEMTR2": ([
                "ascii":"     |",
                "unicode": "\u2502    \u2551",
            ]),
            "SEMTR3": ([
                "ascii":"|    |",
                "unicode": "\u2563    \u2551",
            ]),
            "SEMTR4": ([
                "ascii": "+----+",
                "unicode": "\u255a\u2550\u2550\u2550"
                    "\u2550\u255d",
            ]),
        ]),
    ]),

    "tall southeast tower":([
        "type": "southeast tower",
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
            "SEMTR1": ([
                "ascii":"    =+",
                "unicode": "\u250c\u2500\u2500\u2569"
                    "\u2550\u2557",
            ]),
            "SEMTR2": ([
                "ascii":"     |",
                "unicode": "\u2502\u2591\u2591\u2591"
                    "\u2591\u2551",
            ]),
            "SEMTR3": ([
                "ascii":"|    |",
                "unicode": "\u2563\u2591\u2591\u2591"
                    "\u2591\u2551",
            ]),
            "SEMTR4": ([
                "ascii": "+====+",
                "unicode": "\u255a\u2550\u2550\u2550"
                    "\u2550\u255d",
            ]),
        ]),
    ]),

    "archer's southeast tower":([
        "type": "southeast tower",
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
            "SEMTR1": ([
                "ascii":"    =+",
                "unicode": "\u250c\u2500\u2500\u2569"
                    "\u2550\u2557",
            ]),
            "SEMTR2": ([
                "ascii":" +--+|",
                "unicode": "\u2502\u250f\u2501\u2501"
                    "\u2513\u2551",
            ]),
            "SEMTR3": ([
                "ascii":"|+archer--default+|",
                "unicode": "\u2563\u2517archer\u21a7\u21a7"
                    "default\u251b\u2551",
            ]),
            "SEMTR4": ([
                "ascii": "+====+",
                "unicode": "\u255a\u2550\u2550\u2550"
                    "\u2550\u255d",
            ]),
        ]),
    ]),

    "ballista southeast tower":([
        "type": "southeast tower",
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
            "SEMTR1": ([
                "ascii":"    =+",
                "unicode": "\u250c\u2500\u2500\u2569"
                    "\u2550\u2557",
            ]),
            "SEMTR2": ([
                "ascii":" +~~+|",
                "unicode": "\u2502\u250f\u2501\u2501"
                    "\u2513\u2551",
            ]),
            "SEMTR3": ([
                "ascii":"|+ballista~~default+|",
                "unicode": "\u2563\u2517ballista\u21e9\u21e9"
                    "default\u251b\u2551",
            ]),
            "SEMTR4": ([
                "ascii": "+====+",
                "unicode": "\u255a\u2550\u2550\u2550"
                    "\u2550\u255d",
            ]),
        ]),
    ]),

    "catapult southeast tower":([
        "type": "southeast tower",
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
            "SEMTR1": ([
                "ascii":"    =+",
                "unicode": "\u250c\u2500\u2500\u2569"
                    "\u2550\u2557",
            ]),
            "SEMTR2": ([
                "ascii":" +~~+|",
                "unicode": "\u2502\u250f\u2501\u2501"
                    "\u2513\u2551",
            ]),
            "SEMTR3": ([
                "ascii":"|+catapult~~default+|",
                "unicode": "\u2563\u2517catapult\u21ef\u21ad"
                    "default\u251b\u2551",
            ]),
            "SEMTR4": ([
                "ascii": "+====+",
                "unicode": "\u255a\u2550\u2550\u2550"
                    "\u2550\u255d",
            ]),
        ]),
    ]),

    "trebuchet southeast tower":([
        "type": "southeast tower",
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
            "SEMTR1": ([
                "ascii":"    =+",
                "unicode": "\u250c\u2500\u2500\u2569"
                    "\u2550\u2557",
            ]),
            "SEMTR2": ([
                "ascii":" +~~+|",
                "unicode": "\u2502\u250f\u2501\u2501"
                    "\u2513\u2551",
            ]),
            "SEMTR3": ([
                "ascii":"|+trebuchet~~default+|",
                "unicode": "\u2563\u2517trebuchet\u21ef\u21f2"
                    "default\u251b\u2551",
            ]),
            "SEMTR4": ([
                "ascii": "+====+",
                "unicode": "\u255a\u2550\u2550\u2550"
                    "\u2550\u255d",
            ]),
        ]),
    ]),

    "mage southeast tower":([
        "type": "southeast tower",
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
            "SEMTR1": ([
                "ascii":"    =+",
                "unicode": "\u250c\u2500\u2500\u2569"
                    "\u2550\u2557",
            ]),
            "SEMTR2": ([
                "ascii":" +~~+|",
                "unicode": "\u2502\u250f\u2501\u2501"
                    "\u2513\u2551",
            ]),
            "SEMTR3": ([
                "ascii":"|+mage~~default+|",
                "unicode": "\u2563\u2517mage\u22d0\u22d1"
                    "default\u251b\u2551",
            ]),
            "SEMTR4": ([
                "ascii": "+====+",
                "unicode": "\u255a\u2550\u2550\u2550"
                    "\u2550\u255d",
            ]),
        ]),
    ]),
]);

#endif
