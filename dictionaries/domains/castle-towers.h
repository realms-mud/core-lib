//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
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
                "unicode": "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7"
                    "\xe2\x88\xb7\xe2\x88\xb7",
            ]),
            "NWCTR2": ([
                "ascii":".    .",
                "unicode": "\xe2\x88\xb7    \xe2\x88\xb7",
            ]),
            "NWCTR3": ([
                "ascii":".     ",
                "unicode": "\xe2\x88\xb7     ",
            ]),
            "NWCTR4": ([
                "ascii":"..    ",
                "unicode": "\xe2\x88\xb7\xe2\x88\xb7    ",
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
				"stone battlement": ([ "stone": 75, "wood": 25, "metal": 5 ]),
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
                "unicode": "\xe2\x95\x94\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x97",
            ]),
            "NWCTR2": ([
                "ascii":"|    |",
                "unicode": "\xe2\x95\x91    \xe2\x95\xa0",
            ]),
            "NWCTR3": ([
                "ascii":"|     ",
                "unicode": "\xe2\x95\x91    \xe2\x94\x82",
            ]),
            "NWCTR4": ([
                "ascii":"+-    ",
                "unicode": "\xe2\x95\x9a\xe2\x95\xa6\xe2\x94\x80\xe2\x94\x80"
                    "\xe2\x94\x80\xe2\x94\x98",
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
				"stone battlement": ([ "stone": 75, "wood": 25, "metal": 5 ]),
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
                "unicode": "\xe2\x95\x94\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x97",
            ]),
            "NWCTR2": ([
                "ascii":"|    |",
                "unicode": "\xe2\x95\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91"
                    "\xe2\x96\x91\xe2\x95\xa0",
            ]),
            "NWCTR3": ([
                "ascii":"|     ",
                "unicode": "\xe2\x95\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91"
                    "\xe2\x96\x91\xe2\x94\x82",
            ]),
            "NWCTR4": ([
                "ascii":"+=    ",
                "unicode": "\xe2\x95\x9a\xe2\x95\xa6\xe2\x94\x80\xe2\x94\x80"
                    "\xe2\x94\x80\xe2\x94\x98",
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
				"stone battlement": ([ "stone": 75, "wood": 25, "metal": 5 ]),
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
                "unicode": "\xe2\x95\x94\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x97",
            ]),
            "NWCTR2": ([
                "ascii":"|+archer--default+|",
                "unicode": "\xe2\x95\x91\xe2\x94\x8farcher\xe2\x86\xa5\xe2\x86\xa5"
                    "default\xe2\x94\x93\xe2\x95\xa0",
            ]),
            "NWCTR3": ([
                "ascii":"|+--+ ",
                "unicode": "\xe2\x95\x91\xe2\x94\x97\xe2\x94\x81\xe2\x94\x81"
                    "\xe2\x94\x9b\xe2\x94\x82",
            ]),
            "NWCTR4": ([
                "ascii":"+=    ",
                "unicode": "\xe2\x95\x9a\xe2\x95\xa6\xe2\x94\x80\xe2\x94\x80"
                    "\xe2\x94\x80\xe2\x94\x98",
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
				"stone battlement": ([ "stone": 75, "wood": 25, "metal": 5 ]),
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
                "unicode": "\xe2\x95\x94\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x97",
            ]),
            "NWCTR2": ([
                "ascii":"|+ballista~~default+|",
                "unicode": "\xe2\x95\x91\xe2\x95\xadballista\xe2\x87\xad\xe2\x87\xad"
                    "default\xe2\x95\xae\xe2\x95\xa0",
            ]),
            "NWCTR3": ([
                "ascii":"|+~~+ ",
                "unicode": "\xe2\x95\x91\xe2\x95\xb0\xe2\x94\x80\xe2\x94\x80"
                    "\xe2\x95\xaf\xe2\x94\x82",
            ]),
            "NWCTR4": ([
                "ascii":"+=    ",
                "unicode": "\xe2\x95\x9a\xe2\x95\xa6\xe2\x94\x80\xe2\x94\x80"
                    "\xe2\x94\x80\xe2\x94\x98",
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
				"stone battlement": ([ "stone": 75, "wood": 25, "metal": 5 ]),
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
                "unicode": "\xe2\x95\x94\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x97",
            ]),
            "NWCTR2": ([
                "ascii":"|+catapult~~default+|",
                "unicode": "\xe2\x95\x91\xe2\x94\x8fcatapult\xe2\x87\xaf\xe2\x86\xad"
                    "default\xe2\x94\x93\xe2\x95\xa0",
            ]),
            "NWCTR3": ([
                "ascii":"|+~~+ ",
                "unicode": "\xe2\x95\x91\xe2\x94\x97\xe2\x94\x81\xe2\x94\x81"
                    "\xe2\x94\x9b\xe2\x94\x82",
            ]),
            "NWCTR4": ([
                "ascii":"+=    ",
                "unicode": "\xe2\x95\x9a\xe2\x95\xa6\xe2\x94\x80\xe2\x94\x80"
                    "\xe2\x94\x80\xe2\x94\x98",
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
				"stone battlement": ([ "stone": 75, "wood": 25, "metal": 5 ]),
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
                "unicode": "\xe2\x95\x94\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x97",
            ]),
            "NWCTR2": ([
                "ascii":"|+trebuchet~~default+|",
                "unicode": "\xe2\x95\x91\xe2\x94\x8ftrebuchet\xe2\x87\xaf\xe2\x87\xb2"
                    "default\xe2\x94\x93\xe2\x95\xa0",
            ]),
            "NWCTR3": ([
                "ascii":"|+~~+ ",
                "unicode": "\xe2\x95\x91\xe2\x94\x97\xe2\x94\x81\xe2\x94\x81"
                    "\xe2\x94\x9b\xe2\x94\x82",
            ]),
            "NWCTR4": ([
                "ascii":"+=    ",
                "unicode": "\xe2\x95\x9a\xe2\x95\xa6\xe2\x94\x80\xe2\x94\x80"
                    "\xe2\x94\x80\xe2\x94\x98",
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
				"mage tower addition": ([ "stone": 350, "wood": 100, "metal": 25, "textile": 0 ]),
				"stone battlement": ([ "stone": 75, "wood": 25, "metal": 5 ]),
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
                "unicode": "\xe2\x95\x94\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x97",
            ]),
            "NWCTR2": ([
                "ascii":"|+mage~~default+|",
                "unicode": "\xe2\x95\x91\xe2\x94\x8fmage\xe2\x8b\x90\xe2\x8b\x91"
                    "default\xe2\x94\x93\xe2\x95\xa0",
            ]),
            "NWCTR3": ([
                "ascii":"|+~~+ ",
                "unicode": "\xe2\x95\x91\xe2\x94\x97\xe2\x94\x81\xe2\x94\x81"
                    "\xe2\x94\x9b\xe2\x94\x82",
            ]),
            "NWCTR4": ([
                "ascii":"+=    ",
                "unicode": "\xe2\x95\x9a\xe2\x95\xa6\xe2\x94\x80\xe2\x94\x80"
                    "\xe2\x94\x80\xe2\x94\x98",
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
                "unicode": "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7"
                    "\xe2\x88\xb7\xe2\x88\xb7",
            ]),
            "NECTR2": ([
                "ascii":".    .",
                "unicode": "\xe2\x88\xb7    \xe2\x88\xb7",
            ]),
            "NECTR3": ([
                "ascii":"     .",
                "unicode": "     \xe2\x88\xb7",
            ]),
            "NECTR4": ([
                "ascii":"    ..",
                "unicode": "    \xe2\x88\xb7\xe2\x88\xb7",
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
				"stone battlement": ([ "stone": 75, "wood": 25, "metal": 5 ]),
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
                "unicode": "\xe2\x95\x94\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x97",
            ]),
            "NECTR2": ([
                "ascii":"|    |",
                "unicode": "\xe2\x95\xa3    \xe2\x95\x91",
            ]),
            "NECTR3": ([
                "ascii":"     |",
                "unicode": "\xe2\x94\x82    \xe2\x95\x91",
            ]),
            "NECTR4": ([
                "ascii":"    =+",
                "unicode": "\xe2\x94\x94\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80"
                    "\xe2\x95\xa6\xe2\x95\x9d",
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
				"stone battlement": ([ "stone": 75, "wood": 25, "metal": 5 ]),
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
                "unicode": "\xe2\x95\x94\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x97",
            ]),
            "NECTR2": ([
                "ascii":"|    |",
                "unicode": "\xe2\x95\xa3\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91"
                    "\xe2\x96\x91\xe2\x95\x91",
            ]),
            "NECTR3": ([
                "ascii":"     |",
                "unicode": "\xe2\x94\x82\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91"
                    "\xe2\x96\x91\xe2\x95\x91",
            ]),
            "NECTR4": ([
                "ascii":"    =+",
                "unicode": "\xe2\x94\x94\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80"
                    "\xe2\x95\xa6\xe2\x95\x9d",
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
				"stone battlement": ([ "stone": 75, "wood": 25, "metal": 5 ]),
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
                "unicode": "\xe2\x95\x94\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x97",
            ]),
            "NECTR2": ([
                "ascii":"|+archer--default+|",
                "unicode": "\xe2\x95\xa3\xe2\x94\x8farcher\xe2\x86\xa5\xe2\x86\xa5"
                    "default\xe2\x94\x93\xe2\x95\x91",
            ]),
            "NECTR3": ([
                "ascii":" +--+|",
                "unicode": "\xe2\x94\x82\xe2\x94\x97\xe2\x94\x81\xe2\x94\x81"
                    "\xe2\x94\x9b\xe2\x95\x91",
            ]),
            "NECTR4": ([
                "ascii":"    =+",
                "unicode": "\xe2\x94\x94\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80"
                    "\xe2\x95\xa6\xe2\x95\x9d",
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
				"stone battlement": ([ "stone": 75, "wood": 25, "metal": 5 ]),
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
                "unicode": "\xe2\x95\x94\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x97",
            ]),
            "NECTR2": ([
                "ascii":"|+ballista~~default+|",
                "unicode": "\xe2\x95\xa3\xe2\x95\xadballista\xe2\x87\xad\xe2\x87\xad"
                    "default\xe2\x95\xae\xe2\x95\x91",
            ]),
            "NECTR3": ([
                "ascii":" +~~+|",
                "unicode": "\xe2\x94\x82\xe2\x95\xb0\xe2\x94\x80\xe2\x94\x80"
                    "\xe2\x95\xaf\xe2\x95\x91",
            ]),
            "NECTR4": ([
                "ascii":"    =+",
                "unicode": "\xe2\x94\x94\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80"
                    "\xe2\x95\xa6\xe2\x95\x9d",
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
				"stone battlement": ([ "stone": 75, "wood": 25, "metal": 5 ]),
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
                "unicode": "\xe2\x95\x94\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x97",
            ]),
            "NECTR2": ([
                "ascii":"|+catapult~~default+|",
                "unicode": "\xe2\x95\xa3\xe2\x94\x8fcatapult\xe2\x87\xaf\xe2\x86\xad"
                    "default\xe2\x94\x93\xe2\x95\x91",
            ]),
            "NECTR3": ([
                "ascii":" +~~+|",
                "unicode": "\xe2\x94\x82\xe2\x94\x97\xe2\x94\x81\xe2\x94\x81"
                    "\xe2\x94\x9b\xe2\x95\x91",
            ]),
            "NECTR4": ([
                "ascii":"    =+",
                "unicode": "\xe2\x94\x94\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80"
                    "\xe2\x95\xa6\xe2\x95\x9d",
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
				"stone battlement": ([ "stone": 75, "wood": 25, "metal": 5 ]),
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
                "unicode": "\xe2\x95\x94\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x97",
            ]),
            "NECTR2": ([
                "ascii":"|+trebuchet~~default+|",
                "unicode": "\xe2\x95\xa3\xe2\x94\x8ftrebuchet\xe2\x87\xaf\xe2\x87\xb2"
                    "default\xe2\x94\x93\xe2\x95\x91",
            ]),
            "NECTR3": ([
                "ascii":" +~~+|",
                "unicode": "\xe2\x94\x82\xe2\x94\x97\xe2\x94\x81\xe2\x94\x81"
                    "\xe2\x94\x9b\xe2\x95\x91",
            ]),
            "NECTR4": ([
                "ascii":"    =+",
                "unicode": "\xe2\x94\x94\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80"
                    "\xe2\x95\xa6\xe2\x95\x9d",
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
				"mage tower addition": ([ "stone": 350, "wood": 100, "metal": 25, "textile": 0 ]),
				"stone battlement": ([ "stone": 75, "wood": 25, "metal": 5 ]),
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
                "unicode": "\xe2\x95\x94\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x97",
            ]),
            "NECTR2": ([
                "ascii":"|+mage~~default+|",
                "unicode": "\xe2\x95\xa3\xe2\x94\x8fmage\xe2\x8b\x90\xe2\x8b\x91"
                    "default\xe2\x94\x93\xe2\x95\x91",
            ]),
            "NECTR3": ([
                "ascii":" +~~+|",
                "unicode": "\xe2\x94\x82\xe2\x94\x97\xe2\x94\x81\xe2\x94\x81"
                    "\xe2\x94\x9b\xe2\x95\x91",
            ]),
            "NECTR4": ([
                "ascii":"    =+",
                "unicode": "\xe2\x94\x94\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80"
                    "\xe2\x95\xa6\xe2\x95\x9d",
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
                "unicode": "\xe2\x88\xb7\xe2\x88\xb7    ",
            ]),
            "SWCTR2": ([
                "ascii":".     ",
                "unicode": "\xe2\x88\xb7     ",
            ]),
            "SWCTR3": ([
                "ascii":".    .",
                "unicode": "\xe2\x88\xb7    \xe2\x88\xb7",
            ]),
            "SWCTR4": ([
                "ascii":"......",
                "unicode": "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7"
                    "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7",
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
				"stone battlement": ([ "stone": 75, "wood": 25, "metal": 5 ]),
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
                "unicode": "\xe2\x95\x94\xe2\x95\xa9\xe2\x94\x80\xe2\x94\x80"
                    "\xe2\x94\x80\xe2\x94\x90",
            ]),
            "SWCTR2": ([
                "ascii":"|     ",
                "unicode": "\xe2\x95\x91    \xe2\x94\x82",
            ]),
            "SWCTR3": ([
                "ascii":"|    |",
                "unicode": "\xe2\x95\x91    \xe2\x95\xa0",
            ]),
            "SWCTR4": ([
                "ascii": "+----+",
                "unicode": "\xe2\x95\x9a\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x9d",
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
				"stone battlement": ([ "stone": 75, "wood": 25, "metal": 5 ]),
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
                "unicode": "\xe2\x95\x94\xe2\x95\xa9\xe2\x94\x80\xe2\x94\x80"
                    "\xe2\x94\x80\xe2\x94\x90",
            ]),
            "SWCTR2": ([
                "ascii":"|     ",
                "unicode": "\xe2\x95\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91"
                    "\xe2\x96\x91\xe2\x94\x82",
            ]),
            "SWCTR3": ([
                "ascii":"|    |",
                "unicode": "\xe2\x95\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91"
                    "\xe2\x96\x91\xe2\x95\xa0",
            ]),
            "SWCTR4": ([
                "ascii": "+====+",
                "unicode": "\xe2\x95\x9a\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x9d",
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
				"stone battlement": ([ "stone": 75, "wood": 25, "metal": 5 ]),
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
                "unicode": "\xe2\x95\x94\xe2\x95\xa9\xe2\x94\x80\xe2\x94\x80"
                    "\xe2\x94\x80\xe2\x94\x90",
            ]),
            "SWCTR2": ([
                "ascii":"|+--+ ",
                "unicode": "\xe2\x95\x91\xe2\x94\x8f\xe2\x94\x81\xe2\x94\x81"
                    "\xe2\x94\x93\xe2\x94\x82",
            ]),
            "SWCTR3": ([
                "ascii":"|+archer--default+|",
                "unicode": "\xe2\x95\x91\xe2\x94\x97archer\xe2\x86\xa7\xe2\x86\xa7"
                    "default\xe2\x94\x9b\xe2\x95\xa0",
            ]),
            "SWCTR4": ([
                "ascii": "+====+",
                "unicode": "\xe2\x95\x9a\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x9d",
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
				"stone battlement": ([ "stone": 75, "wood": 25, "metal": 5 ]),
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
                "unicode": "\xe2\x95\x94\xe2\x95\xa9\xe2\x94\x80\xe2\x94\x80"
                    "\xe2\x94\x80\xe2\x94\x90",
            ]),
            "SWCTR2": ([
                "ascii":"|+~~+ ",
                "unicode": "\xe2\x95\x91\xe2\x94\x8f\xe2\x94\x81\xe2\x94\x81"
                    "\xe2\x94\x93\xe2\x94\x82",
            ]),
            "SWCTR3": ([
                "ascii":"|+ballista~~default+|",
                "unicode": "\xe2\x95\x91\xe2\x94\x97ballista\xe2\x87\xa9\xe2\x87\xa9"
                    "default\xe2\x94\x9b\xe2\x95\xa0",
            ]),
            "SWCTR4": ([
                "ascii": "+====+",
                "unicode": "\xe2\x95\x9a\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x9d",
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
				"stone battlement": ([ "stone": 75, "wood": 25, "metal": 5 ]),
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
                "unicode": "\xe2\x95\x94\xe2\x95\xa9\xe2\x94\x80\xe2\x94\x80"
                    "\xe2\x94\x80\xe2\x94\x90",
            ]),
            "SWCTR2": ([
                "ascii":"|+~~+ ",
                "unicode": "\xe2\x95\x91\xe2\x94\x8f\xe2\x94\x81\xe2\x94\x81"
                    "\xe2\x94\x93\xe2\x94\x82",
            ]),
            "SWCTR3": ([
                "ascii":"|+catapult~~default+|",
                "unicode": "\xe2\x95\x91\xe2\x94\x97catapult\xe2\x87\xaf\xe2\x86\xad"
                    "default\xe2\x94\x9b\xe2\x95\xa0",
            ]),
            "SWCTR4": ([
                "ascii": "+====+",
                "unicode": "\xe2\x95\x9a\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x9d",
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
				"stone battlement": ([ "stone": 75, "wood": 25, "metal": 5 ]),
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
                "unicode": "\xe2\x95\x94\xe2\x95\xa9\xe2\x94\x80\xe2\x94\x80"
                    "\xe2\x94\x80\xe2\x94\x90",
            ]),
            "SWCTR2": ([
                "ascii":"|+~~+ ",
                "unicode": "\xe2\x95\x91\xe2\x94\x8f\xe2\x94\x81\xe2\x94\x81"
                    "\xe2\x94\x93\xe2\x94\x82",
            ]),
            "SWCTR3": ([
                "ascii":"|+trebuchet~~default+|",
                "unicode": "\xe2\x95\x91\xe2\x94\x97trebuchet\xe2\x87\xaf\xe2\x87\xb2"
                    "default\xe2\x94\x9b\xe2\x95\xa0",
            ]),
            "SWCTR4": ([
                "ascii": "+====+",
                "unicode": "\xe2\x95\x9a\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x9d",
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
				"mage tower addition": ([ "stone": 350, "wood": 100, "metal": 25, "textile": 0 ]),
				"stone battlement": ([ "stone": 75, "wood": 25, "metal": 5 ]),
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
                "unicode": "\xe2\x95\x94\xe2\x95\xa9\xe2\x94\x80\xe2\x94\x80"
                    "\xe2\x94\x80\xe2\x94\x90",
            ]),
            "SWCTR2": ([
                "ascii":"|+~~+ ",
                "unicode": "\xe2\x95\x91\xe2\x94\x8f\xe2\x94\x81\xe2\x94\x81"
                    "\xe2\x94\x93\xe2\x94\x82",
            ]),
            "SWCTR3": ([
                "ascii":"|+mage~~default+|",
                "unicode": "\xe2\x95\x91\xe2\x94\x97mage\xe2\x8b\x90\xe2\x8b\x91"
                    "default\xe2\x94\x9b\xe2\x95\xa0",
            ]),
            "SWCTR4": ([
                "ascii": "+====+",
                "unicode": "\xe2\x95\x9a\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x9d",
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
                "unicode": "    \xe2\x88\xb7\xe2\x88\xb7",
            ]),
            "SECTR2": ([
                "ascii":"     .",
                "unicode": "     \xe2\x88\xb7",
            ]),
            "SECTR3": ([
                "ascii":".    .",
                "unicode": "\xe2\x88\xb7    \xe2\x88\xb7",
            ]),
            "SECTR4": ([
                "ascii":"......",
                "unicode": "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7"
                    "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7",
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
				"stone battlement": ([ "stone": 75, "wood": 25, "metal": 5 ]),
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
                "unicode": "\xe2\x94\x8c\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80"
                    "\xe2\x95\xa9\xe2\x95\x97",
            ]),
            "SECTR2": ([
                "ascii":"     |",
                "unicode": "\xe2\x94\x82    \xe2\x95\x91",
            ]),
            "SECTR3": ([
                "ascii":"|    |",
                "unicode": "\xe2\x95\xa3    \xe2\x95\x91",
            ]),
            "SECTR4": ([
                "ascii": "+----+",
                "unicode": "\xe2\x95\x9a\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x9d",
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
				"stone battlement": ([ "stone": 75, "wood": 25, "metal": 5 ]),
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
                "unicode": "\xe2\x94\x8c\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80"
                    "\xe2\x95\xa9\xe2\x95\x97",
            ]),
            "SECTR2": ([
                "ascii":"     |",
                "unicode": "\xe2\x94\x82\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91"
                    "\xe2\x96\x91\xe2\x95\x91",
            ]),
            "SECTR3": ([
                "ascii":"|    |",
                "unicode": "\xe2\x95\xa3\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91"
                    "\xe2\x96\x91\xe2\x95\x91",
            ]),
            "SECTR4": ([
                "ascii": "+====+",
                "unicode": "\xe2\x95\x9a\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x9d",
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
				"stone battlement": ([ "stone": 75, "wood": 25, "metal": 5 ]),
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
                "unicode": "\xe2\x94\x8c\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80"
                    "\xe2\x95\xa9\xe2\x95\x97",
            ]),
            "SECTR2": ([
                "ascii":" +--+|",
                "unicode": "\xe2\x94\x82\xe2\x94\x8f\xe2\x94\x81\xe2\x94\x81"
                    "\xe2\x94\x93\xe2\x95\x91",
            ]),
            "SECTR3": ([
                "ascii":"|+archer~~default+|",
                "unicode": "\xe2\x95\xa3\xe2\x94\x97archer\xe2\x86\xa7\xe2\x86\xa7"
                    "default\xe2\x94\x9b\xe2\x95\x91",
            ]),
            "SECTR4": ([
                "ascii": "+====+",
                "unicode": "\xe2\x95\x9a\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x9d",
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
				"stone battlement": ([ "stone": 75, "wood": 25, "metal": 5 ]),
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
                "unicode": "\xe2\x94\x8c\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80"
                    "\xe2\x95\xa9\xe2\x95\x97",
            ]),
            "SECTR2": ([
                "ascii":" +~~+|",
                "unicode": "\xe2\x94\x82\xe2\x94\x8f\xe2\x94\x81\xe2\x94\x81"
                    "\xe2\x94\x93\xe2\x95\x91",
            ]),
            "SECTR3": ([
                "ascii":"|+ballista~~default+|",
                "unicode": "\xe2\x95\xa3\xe2\x94\x97ballista\xe2\x87\xa9\xe2\x87\xa9"
                    "default\xe2\x94\x9b\xe2\x95\x91",
            ]),
            "SECTR4": ([
                "ascii": "+====+",
                "unicode": "\xe2\x95\x9a\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x9d",
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
				"stone battlement": ([ "stone": 75, "wood": 25, "metal": 5 ]),
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
                "unicode": "\xe2\x94\x8c\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80"
                    "\xe2\x95\xa9\xe2\x95\x97",
            ]),
            "SECTR2": ([
                "ascii":" +~~+|",
                "unicode": "\xe2\x94\x82\xe2\x94\x8f\xe2\x94\x81\xe2\x94\x81"
                    "\xe2\x94\x93\xe2\x95\x91",
            ]),
            "SECTR3": ([
                "ascii":"|+catapult~~default+|",
                "unicode": "\xe2\x95\xa3\xe2\x94\x97catapult\xe2\x87\xaf\xe2\x86\xad"
                    "default\xe2\x94\x9b\xe2\x95\x91",
            ]),
            "SECTR4": ([
                "ascii": "+====+",
                "unicode": "\xe2\x95\x9a\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x9d",
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
				"stone battlement": ([ "stone": 75, "wood": 25, "metal": 5 ]),
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
                "unicode": "\xe2\x94\x8c\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80"
                    "\xe2\x95\xa9\xe2\x95\x97",
            ]),
            "SECTR2": ([
                "ascii":" +~~+|",
                "unicode": "\xe2\x94\x82\xe2\x94\x8f\xe2\x94\x81\xe2\x94\x81"
                    "\xe2\x94\x93\xe2\x95\x91",
            ]),
            "SECTR3": ([
                "ascii":"|+trebuchet~~default+|",
                "unicode": "\xe2\x95\xa3\xe2\x94\x97trebuchet\xe2\x87\xaf\xe2\x87\xb2"
                    "default\xe2\x94\x9b\xe2\x95\x91",
            ]),
            "SECTR4": ([
                "ascii": "+====+",
                "unicode": "\xe2\x95\x9a\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x9d",
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
				"mage tower addition": ([ "stone": 350, "wood": 100, "metal": 25, "textile": 0 ]),
				"stone battlement": ([ "stone": 75, "wood": 25, "metal": 5 ]),
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
                "unicode": "\xe2\x94\x8c\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80"
                    "\xe2\x95\xa9\xe2\x95\x97",
            ]),
            "SECTR2": ([
                "ascii":" +~~+|",
                "unicode": "\xe2\x94\x82\xe2\x94\x8f\xe2\x94\x81\xe2\x94\x81"
                    "\xe2\x94\x93\xe2\x95\x91",
            ]),
            "SECTR3": ([
                "ascii":"|+mage~~default+|",
                "unicode": "\xe2\x95\xa3\xe2\x94\x97mage\xe2\x8b\x90\xe2\x8b\x91"
                    "default\xe2\x94\x9b\xe2\x95\x91",
            ]),
            "SECTR4": ([
                "ascii": "+====+",
                "unicode": "\xe2\x95\x9a\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x9d",
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
                "unicode": "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7"
                    "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7"
                    "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7",
            ]),
            "NCATOWER2": ([
                "ascii": ".       .",
                "unicode": "\xe2\x88\xb7       \xe2\x88\xb7",
            ]),
            "NCATOWER3": ([
                "ascii": ".........",
                "unicode": "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7"
                    "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7"
                    "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7",
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
				"stone battlement": ([ "stone": 75, "wood": 25, "metal": 5 ]),
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
                "unicode": "\xe2\x95\x94\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x97",
            ]),
            "NCATOWER2": ([
                "ascii": "|       |",
                "unicode": "\xe2\x95\xa3       \xe2\x95\xa0",
            ]),
            "NCATOWER3": ([
                "ascii": "+=======+",
                "unicode": "\xe2\x95\x9a\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x9d",
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
				"stone battlement": ([ "stone": 75, "wood": 25, "metal": 5 ]),
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
                "unicode": "\xe2\x95\x94\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x97",
            ]),
            "NCATOWER2": ([
                "ascii": "|       |",
                "unicode": "\xe2\x95\xa3\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91"
                    "\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91"
                    "\xe2\x95\xa0",
            ]),
            "NCATOWER3": ([
                "ascii": "+=======+",
                "unicode": "\xe2\x95\x9a\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x9d",
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
				"stone battlement": ([ "stone": 75, "wood": 25, "metal": 5 ]),
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
                "unicode": "\xe2\x95\x94\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x97",
            ]),
            "NCATOWER2": ([
                "ascii": "| archerx x xdefault |",
                "unicode": "\xe2\x95\xa3 archer\xe2\x86\xa5 \xe2\x86\xa5 "
                    "\xe2\x86\xa5default \xe2\x95\xa0",
            ]),
            "NCATOWER3": ([
                "ascii": "+=======+",
                "unicode": "\xe2\x95\x9a\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x9d",
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
				"stone battlement": ([ "stone": 75, "wood": 25, "metal": 5 ]),
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
                "unicode": "\xe2\x95\x94\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x97",
            ]),
            "NCATOWER2": ([
                "ascii": "| ballistax   xdefault |",
                "unicode": "\xe2\x95\xa3 ballista\xe2\x87\xad   "
                    "\xe2\x87\xaddefault \xe2\x95\xa0",
            ]),
            "NCATOWER3": ([
                "ascii": "+=======+",
                "unicode": "\xe2\x95\x9a\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x9d",
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
				"stone battlement": ([ "stone": 75, "wood": 25, "metal": 5 ]),
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
                "unicode": "\xe2\x95\x94\xe2\x95\x90\xe2\x95\x90"
                    "gate\xe2\x94\x84\xe2\x94\x84\xe2\x94\x84default"
                    "\xe2\x95\x90\xe2\x95\x90\xe2\x95\x97",
            ]),
            "NCATOWER2": ([
                "ascii": "| archerx x xdefault |",
                "unicode": "\xe2\x95\xa3 archer\xe2\x86\xa5 \xe2\x86\xa5 "
                    "\xe2\x86\xa5default \xe2\x95\xa0",
            ]),
            "NCATOWER3": ([
                "ascii": "+=======+",
                "unicode": "\xe2\x95\x9a\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x9d",
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
                "unicode": "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7"
                    "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7"
                    "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7",
            ]),
            "SCATOWER2": ([
                "ascii": ".       .",
                "unicode": "\xe2\x88\xb7       \xe2\x88\xb7",
            ]),
            "SCATOWER3": ([
                "ascii": ".........",
                "unicode": "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7"
                    "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7"
                    "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7",
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
				"stone battlement": ([ "stone": 75, "wood": 25, "metal": 5 ]),
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
                "unicode": "\xe2\x95\x94\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x97",
            ]),
            "SCATOWER2": ([
                "ascii": "|       |",
                "unicode": "\xe2\x95\xa3       \xe2\x95\xa0",
            ]),
            "SCATOWER3": ([
                "ascii": "+=======+",
                "unicode": "\xe2\x95\x9a\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x9d",
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
				"stone battlement": ([ "stone": 75, "wood": 25, "metal": 5 ]),
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
                "unicode": "\xe2\x95\x94\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x97",
            ]),
            "SCATOWER2": ([
                "ascii": "|       |",
                "unicode": "\xe2\x95\xa3\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91"
                    "\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91"
                    "\xe2\x95\xa0",
            ]),
            "SCATOWER3": ([
                "ascii": "+=======+",
                "unicode": "\xe2\x95\x9a\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x9d",
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
				"stone battlement": ([ "stone": 75, "wood": 25, "metal": 5 ]),
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
                "unicode": "\xe2\x95\x94\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x97",
            ]),
            "SCATOWER2": ([
                "ascii": "| archerx x xdefault |",
                "unicode": "\xe2\x95\xa3 archer\xe2\x86\xa7 \xe2\x86\xa7 "
                    "\xe2\x86\xa7default \xe2\x95\xa0",
            ]),
            "SCATOWER3": ([
                "ascii": "+=======+",
                "unicode": "\xe2\x95\x9a\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x9d",
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
				"stone battlement": ([ "stone": 75, "wood": 25, "metal": 5 ]),
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
                "unicode": "\xe2\x95\x94\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x97",
            ]),
            "SCATOWER2": ([
                "ascii": "| ballistax   xdefault |",
                "unicode": "\xe2\x95\xa3 ballista\xe2\x87\xa9   "
                    "\xe2\x87\xa9default \xe2\x95\xa0",
            ]),
            "SCATOWER3": ([
                "ascii": "+=======+",
                "unicode": "\xe2\x95\x9a\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x9d",
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
				"stone battlement": ([ "stone": 75, "wood": 25, "metal": 5 ]),
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
                "unicode": "\xe2\x95\x94\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x97",
            ]),
            "SCATOWER2": ([
                "ascii": "| archerx x xdefault |",
                "unicode": "\xe2\x95\xa3 archer\xe2\x86\xa7 \xe2\x86\xa7 "
                    "\xe2\x86\xa7default \xe2\x95\xa0",
            ]),
            "SCATOWER3": ([
                "ascii": "+=======+",
                "unicode": "\xe2\x95\x9a\xe2\x95\x90\xe2\x95\x90"
                    "gate\xe2\x94\x84\xe2\x94\x84\xe2\x94\x84default"
                    "\xe2\x95\x90\xe2\x95\x90\xe2\x95\x9d",
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
                "unicode": "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7",
            ]),
            "WCT2": ([
                "ascii": ".  .",
                "unicode": "\xe2\x88\xb7  \xe2\x88\xb7",
            ]),
            "WCT3": ([
                "ascii": ".  .",
                "unicode": "\xe2\x88\xb7  \xe2\x88\xb7",
            ]),
            "WCT4": ([
                "ascii": ".  .",
                "unicode": "\xe2\x88\xb7  \xe2\x88\xb7",
            ]),
            "WCT5": ([
                "ascii": ".  .",
                "unicode": "\xe2\x88\xb7  \xe2\x88\xb7",
            ]),
            "WCT6": ([
                "ascii": "....",
                "unicode": "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7",
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
				"stone battlement": ([ "stone": 75, "wood": 25, "metal": 5 ]),
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
                "unicode": "\xe2\x95\x94\xe2\x95\xa9\xe2\x95\x90\xe2\x95\x97",
            ]),
            "WCT2": ([
                "ascii": "|  |",
                "unicode": "\xe2\x95\x91  \xe2\x95\x91",
            ]),
            "WCT3": ([
                "ascii": "|  |",
                "unicode": "\xe2\x95\x91  \xe2\x95\x91",
            ]),
            "WCT4": ([
                "ascii": "|  |",
                "unicode": "\xe2\x95\x91  \xe2\x95\x91",
            ]),
            "WCT5": ([
                "ascii": "|  |",
                "unicode": "\xe2\x95\x91  \xe2\x95\x91",
            ]),
            "WCT6": ([
                "ascii": "+==+",
                "unicode": "\xe2\x95\x9a\xe2\x95\xa6\xe2\x95\x90\xe2\x95\x9d",
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
				"stone battlement": ([ "stone": 75, "wood": 25, "metal": 5 ]),
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
                "unicode": "\xe2\x95\x94\xe2\x95\xa9\xe2\x95\x90\xe2\x95\x97",
            ]),
            "WCT2": ([
                "ascii": "|  |",
                "unicode": "\xe2\x95\x91\xe2\x96\x91\xe2\x96\x91\xe2\x95\x91",
            ]),
            "WCT3": ([
                "ascii": "|  |",
                "unicode": "\xe2\x95\x91\xe2\x96\x91\xe2\x96\x91\xe2\x95\x91",
            ]),
            "WCT4": ([
                "ascii": "|  |",
                "unicode": "\xe2\x95\x91\xe2\x96\x91\xe2\x96\x91\xe2\x95\x91",
            ]),
            "WCT5": ([
                "ascii": "|  |",
                "unicode": "\xe2\x95\x91\xe2\x96\x91\xe2\x96\x91\xe2\x95\x91",
            ]),
            "WCT6": ([
                "ascii": "+==+",
                "unicode": "\xe2\x95\x9a\xe2\x95\xa6\xe2\x95\x90\xe2\x95\x9d",
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
				"stone battlement": ([ "stone": 75, "wood": 25, "metal": 5 ]),
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
                "unicode": "\xe2\x95\x94\xe2\x95\xa9\xe2\x95\x90\xe2\x95\x97",
            ]),
            "WCT2": ([
                "ascii": "|archerxdefault |",
                "unicode": "\xe2\x95\x91 archer\xe2\x86\xa4default\xe2\x95\x91",
            ]),
            "WCT3": ([
                "ascii": "|  |",
                "unicode": "\xe2\x95\x91archer\xe2\x86\xa4default \xe2\x95\x91",
            ]),
            "WCT4": ([
                "ascii": "|  |",
                "unicode": "\xe2\x95\x91archer\xe2\x86\xa4default \xe2\x95\x91",
            ]),
            "WCT5": ([
                "ascii": "|archerxdefault |",
                "unicode": "\xe2\x95\x91 archer\xe2\x86\xa4default\xe2\x95\x91",
            ]),
            "WCT6": ([
                "ascii": "+==+",
                "unicode": "\xe2\x95\x9a\xe2\x95\xa6\xe2\x95\x90\xe2\x95\x9d",
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
				"stone battlement": ([ "stone": 75, "wood": 25, "metal": 5 ]),
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
                "unicode": "\xe2\x95\x94\xe2\x95\xa9\xe2\x95\x90\xe2\x95\x97",
            ]),
            "WCT2": ([
                "ascii": "|ballistaxdefault |",
                "unicode": "\xe2\x95\x91ballista\xe2\x87\xaddefault \xe2\x95\x91",
            ]),
            "WCT3": ([
                "ascii": "|  |",
                "unicode": "\xe2\x95\x91  \xe2\x95\x91",
            ]),
            "WCT4": ([
                "ascii": "|  |",
                "unicode": "\xe2\x95\x91  \xe2\x95\x91",
            ]),
            "WCT5": ([
                "ascii": "|ballistaxdefault |",
                "unicode": "\xe2\x95\x91ballista\xe2\x87\xaddefault \xe2\x95\x91",
            ]),
            "WCT6": ([
                "ascii": "+==+",
                "unicode": "\xe2\x95\x9a\xe2\x95\xa6\xe2\x95\x90\xe2\x95\x9d",
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
				"stone battlement": ([ "stone": 75, "wood": 25, "metal": 5 ]),
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
                "unicode": "\xe2\x95\x94\xe2\x95\xa9\xe2\x95\x90\xe2\x95\x97",
            ]),
            "WCT2": ([
                "ascii": "|archerxdefault |",
                "unicode": "\xe2\x95\x91 archer\xe2\x86\xa4default\xe2\x95\x91",
            ]),
            "WCT3": ([
                "ascii": "gate|default  |",
                "unicode": "gate\xe2\x94\x8aarcher\xe2\x86\xa4default \xe2\x95\x91",
            ]),
            "WCT4": ([
                "ascii": "gate|default  |",
                "unicode": "gate\xe2\x94\x8aarcher\xe2\x86\xa4default \xe2\x95\x91",
            ]),
            "WCT5": ([
                "ascii": "|archerxdefault |",
                "unicode": "\xe2\x95\x91 archer\xe2\x86\xa4default\xe2\x95\x91",
            ]),
            "WCT6": ([
                "ascii": "+==+",
                "unicode": "\xe2\x95\x9a\xe2\x95\xa6\xe2\x95\x90\xe2\x95\x9d",
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
                "unicode": "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7",
            ]),
            "ECT2": ([
                "ascii": ".  .",
                "unicode": "\xe2\x88\xb7  \xe2\x88\xb7",
            ]),
            "ECT3": ([
                "ascii": ".  .",
                "unicode": "\xe2\x88\xb7  \xe2\x88\xb7",
            ]),
            "ECT4": ([
                "ascii": ".  .",
                "unicode": "\xe2\x88\xb7  \xe2\x88\xb7",
            ]),
            "ECT5": ([
                "ascii": ".  .",
                "unicode": "\xe2\x88\xb7  \xe2\x88\xb7",
            ]),
            "ECT6": ([
                "ascii": "....",
                "unicode": "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7",
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
				"stone battlement": ([ "stone": 75, "wood": 25, "metal": 5 ]),
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
                "unicode": "\xe2\x95\x94\xe2\x95\x90\xe2\x95\xa9\xe2\x95\x97",
            ]),
            "ECT2": ([
                "ascii": "|  |",
                "unicode": "\xe2\x95\x91  \xe2\x95\x91",
            ]),
            "ECT3": ([
                "ascii": "|  |",
                "unicode": "\xe2\x95\x91  \xe2\x95\x91",
            ]),
            "ECT4": ([
                "ascii": "|  |",
                "unicode": "\xe2\x95\x91  \xe2\x95\x91",
            ]),
            "ECT5": ([
                "ascii": "|  |",
                "unicode": "\xe2\x95\x91  \xe2\x95\x91",
            ]),
            "ECT6": ([
                "ascii": "+==+",
                "unicode": "\xe2\x95\x9a\xe2\x95\x90\xe2\x95\xa6\xe2\x95\x9d",
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
				"stone battlement": ([ "stone": 75, "wood": 25, "metal": 5 ]),
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
                "unicode": "\xe2\x95\x94\xe2\x95\x90\xe2\x95\xa9\xe2\x95\x97",
            ]),
            "ECT2": ([
                "ascii": "|  |",
                "unicode": "\xe2\x95\x91\xe2\x96\x91\xe2\x96\x91\xe2\x95\x91",
            ]),
            "ECT3": ([
                "ascii": "|  |",
                "unicode": "\xe2\x95\x91\xe2\x96\x91\xe2\x96\x91\xe2\x95\x91",
            ]),
            "ECT4": ([
                "ascii": "|  |",
                "unicode": "\xe2\x95\x91\xe2\x96\x91\xe2\x96\x91\xe2\x95\x91",
            ]),
            "ECT5": ([
                "ascii": "|  |",
                "unicode": "\xe2\x95\x91\xe2\x96\x91\xe2\x96\x91\xe2\x95\x91",
            ]),
            "ECT6": ([
                "ascii": "+==+",
                "unicode": "\xe2\x95\x9a\xe2\x95\x90\xe2\x95\xa6\xe2\x95\x9d",
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
				"stone battlement": ([ "stone": 75, "wood": 25, "metal": 5 ]),
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
                "unicode": "\xe2\x95\x94\xe2\x95\x90\xe2\x95\xa9\xe2\x95\x97",
            ]),
            "ECT2": ([
                "ascii": "|archerxdefault |",
                "unicode": "\xe2\x95\x91archer\xe2\x86\xa6default \xe2\x95\x91",
            ]),
            "ECT3": ([
                "ascii": "|  |",
                "unicode": "\xe2\x95\x91 archer\xe2\x86\xa6default\xe2\x95\x91",
            ]),
            "ECT4": ([
                "ascii": "|  |",
                "unicode": "\xe2\x95\x91 archer\xe2\x86\xa6default\xe2\x95\x91",
            ]),
            "ECT5": ([
                "ascii": "|archerxdefault |",
                "unicode": "\xe2\x95\x91archer\xe2\x86\xa6default \xe2\x95\x91",
            ]),
            "ECT6": ([
                "ascii": "+==+",
                "unicode": "\xe2\x95\x9a\xe2\x95\x90\xe2\x95\xa6\xe2\x95\x9d",
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
				"stone battlement": ([ "stone": 75, "wood": 25, "metal": 5 ]),
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
                "unicode": "\xe2\x95\x94\xe2\x95\x90\xe2\x95\xa9\xe2\x95\x97",
            ]),
            "ECT2": ([
                "ascii": "|ballistaxdefault |",
                "unicode": "\xe2\x95\x91 ballista\xe2\x87\xaddefault\xe2\x95\x91",
            ]),
            "ECT3": ([
                "ascii": "|  |",
                "unicode": "\xe2\x95\x91  \xe2\x95\x91",
            ]),
            "ECT4": ([
                "ascii": "|  |",
                "unicode": "\xe2\x95\x91  \xe2\x95\x91",
            ]),
            "ECT5": ([
                "ascii": "|ballistaxdefault |",
                "unicode": "\xe2\x95\x91 ballista\xe2\x87\xaddefault\xe2\x95\x91",
            ]),
            "ECT6": ([
                "ascii": "+==+",
                "unicode": "\xe2\x95\x9a\xe2\x95\x90\xe2\x95\xa6\xe2\x95\x9d",
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
				"stone battlement": ([ "stone": 75, "wood": 25, "metal": 5 ]),
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
                "unicode": "\xe2\x95\x94\xe2\x95\x90\xe2\x95\xa9\xe2\x95\x97",
            ]),
            "ECT2": ([
                "ascii": "| archerxdefault|",
                "unicode": "\xe2\x95\x91archer\xe2\x86\xa6default \xe2\x95\x91",
            ]),
            "ECT3": ([
                "ascii": "|  gate|default",
                "unicode": "\xe2\x95\x91 archer\xe2\x86\xa6defaultgate\xe2\x94\x8a",
            ]),
            "ECT4": ([
                "ascii": "|  gate|default",
                "unicode": "\xe2\x95\x91 archer\xe2\x86\xa6defaultgate\xe2\x94\x8a",
            ]),
            "ECT5": ([
                "ascii": "| archerxdefault|",
                "unicode": "\xe2\x95\x91archer\xe2\x86\xa6default \xe2\x95\x91",
            ]),
            "ECT6": ([
                "ascii": "+==+",
                "unicode": "\xe2\x95\x9a\xe2\x95\x90\xe2\x95\xa6\xe2\x95\x9d",
            ]),
        ]),
    ]),
]);

#endif
