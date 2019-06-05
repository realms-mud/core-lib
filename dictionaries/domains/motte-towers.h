//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
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
                "unicode": "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7"
                    "\xe2\x88\xb7\xe2\x88\xb7",
            ]),
            "NWMTR2": ([
                "ascii":".    .",
                "unicode": "\xe2\x88\xb7    \xe2\x88\xb7",
            ]),
            "NWMTR3": ([
                "ascii":".     ",
                "unicode": "\xe2\x88\xb7     ",
            ]),
            "NWMTR4": ([
                "ascii":"..    ",
                "unicode": "\xe2\x88\xb7\xe2\x88\xb7    ",
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
            "NWMTR1": ([
                "ascii":"+----+",
                "unicode": "\xe2\x95\x94\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x97",
            ]),
            "NWMTR2": ([
                "ascii":"|    |",
                "unicode": "\xe2\x95\x91    \xe2\x95\xa0",
            ]),
            "NWMTR3": ([
                "ascii":"|     ",
                "unicode": "\xe2\x95\x91    \xe2\x94\x82",
            ]),
            "NWMTR4": ([
                "ascii":"+-    ",
                "unicode": "\xe2\x95\x9a\xe2\x95\x90\xe2\x95\xa6\xe2\x94\x80"
                    "\xe2\x94\x80\xe2\x94\x98",
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
            "NWMTR1": ([
                "ascii":"+====+",
                "unicode": "\xe2\x95\x94\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x97",
            ]),
            "NWMTR2": ([
                "ascii":"|    |",
                "unicode": "\xe2\x95\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91"
                    "\xe2\x96\x91\xe2\x95\xa0",
            ]),
            "NWMTR3": ([
                "ascii":"|     ",
                "unicode": "\xe2\x95\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91"
                    "\xe2\x96\x91\xe2\x94\x82",
            ]),
            "NWMTR4": ([
                "ascii":"+=    ",
                "unicode": "\xe2\x95\x9a\xe2\x95\x90\xe2\x95\xa6\xe2\x94\x80"
                    "\xe2\x94\x80\xe2\x94\x98",
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
            "NWMTR1": ([
                "ascii":"+====+",
                "unicode": "\xe2\x95\x94\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x97",
            ]),
            "NWMTR2": ([
                "ascii":"|+archer--default+|",
                "unicode": "\xe2\x95\x91\xe2\x94\x8farcher\xe2\x86\xa5\xe2\x86\xa5"
                    "default\xe2\x94\x93\xe2\x95\xa0",
            ]),
            "NWMTR3": ([
                "ascii":"|+--+ ",
                "unicode": "\xe2\x95\x91\xe2\x94\x97\xe2\x94\x81\xe2\x94\x81"
                    "\xe2\x94\x9b\xe2\x94\x82",
            ]),
            "NWMTR4": ([
                "ascii":"+=    ",
                "unicode": "\xe2\x95\x9a\xe2\x95\x90\xe2\x95\xa6\xe2\x94\x80"
                    "\xe2\x94\x80\xe2\x94\x98",
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
            "NWMTR1": ([
                "ascii":"+====+",
                "unicode": "\xe2\x95\x94\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x97",
            ]),
            "NWMTR2": ([
                "ascii":"|+ballista~~default+|",
                "unicode": "\xe2\x95\x91\xe2\x95\xadballista\xe2\x87\xad\xe2\x87\xad"
                    "default\xe2\x95\xae\xe2\x95\xa0",
            ]),
            "NWMTR3": ([
                "ascii":"|+~~+ ",
                "unicode": "\xe2\x95\x91\xe2\x95\xb0\xe2\x94\x80\xe2\x94\x80"
                    "\xe2\x95\xaf\xe2\x94\x82",
            ]),
            "NWMTR4": ([
                "ascii":"+=    ",
                "unicode": "\xe2\x95\x9a\xe2\x95\x90\xe2\x95\xa6\xe2\x94\x80"
                    "\xe2\x94\x80\xe2\x94\x98",
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
            "NWMTR1": ([
                "ascii":"+====+",
                "unicode": "\xe2\x95\x94\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x97",
            ]),
            "NWMTR2": ([
                "ascii":"|+catapult~~default+|",
                "unicode": "\xe2\x95\x91\xe2\x94\x8fcatapult\xe2\x87\xaf\xe2\x86\xad"
                    "default\xe2\x94\x93\xe2\x95\xa0",
            ]),
            "NWMTR3": ([
                "ascii":"|+~~+ ",
                "unicode": "\xe2\x95\x91\xe2\x94\x97\xe2\x94\x81\xe2\x94\x81"
                    "\xe2\x94\x9b\xe2\x94\x82",
            ]),
            "NWMTR4": ([
                "ascii":"+=    ",
                "unicode": "\xe2\x95\x9a\xe2\x95\x90\xe2\x95\xa6\xe2\x94\x80"
                    "\xe2\x94\x80\xe2\x94\x98",
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
            "NWMTR1": ([
                "ascii":"+====+",
                "unicode": "\xe2\x95\x94\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x97",
            ]),
            "NWMTR2": ([
                "ascii":"|+trebuchet~~default+|",
                "unicode": "\xe2\x95\x91\xe2\x94\x8ftrebuchet\xe2\x87\xaf\xe2\x87\xb2"
                    "default\xe2\x94\x93\xe2\x95\xa0",
            ]),
            "NWMTR3": ([
                "ascii":"|+~~+ ",
                "unicode": "\xe2\x95\x91\xe2\x94\x97\xe2\x94\x81\xe2\x94\x81"
                    "\xe2\x94\x9b\xe2\x94\x82",
            ]),
            "NWMTR4": ([
                "ascii":"+=    ",
                "unicode": "\xe2\x95\x9a\xe2\x95\x90\xe2\x95\xa6\xe2\x94\x80"
                    "\xe2\x94\x80\xe2\x94\x98",
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
            "NWMTR1": ([
                "ascii":"+====+",
                "unicode": "\xe2\x95\x94\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x97",
            ]),
            "NWMTR2": ([
                "ascii":"|+mage~~default+|",
                "unicode": "\xe2\x95\x91\xe2\x94\x8fmage\xe2\x8b\x90\xe2\x8b\x91"
                    "default\xe2\x94\x93\xe2\x95\xa0",
            ]),
            "NWMTR3": ([
                "ascii":"|+~~+ ",
                "unicode": "\xe2\x95\x91\xe2\x94\x97\xe2\x94\x81\xe2\x94\x81"
                    "\xe2\x94\x9b\xe2\x94\x82",
            ]),
            "NWMTR4": ([
                "ascii":"+=    ",
                "unicode": "\xe2\x95\x9a\xe2\x95\x90\xe2\x95\xa6\xe2\x94\x80"
                    "\xe2\x94\x80\xe2\x94\x98",
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
                "unicode": "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7",
            ]),
            "NT2": ([
                "ascii": ". .",
                "unicode": "\xe2\x88\xb7 \xe2\x88\xb7",
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
            "NT1": ([
                "ascii": "+-+",
                "unicode": "\xe2\x95\x94\xe2\x95\x90\xe2\x95\x97",
            ]),
            "NT2": ([
                "ascii": "+ +",
                "unicode": "\xe2\x95\x9d \xe2\x95\x9a",
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
            "NT1": ([
                "ascii": "+=+",
                "unicode": "\xe2\x95\x94\xe2\x95\x90\xe2\x95\x97",
            ]),
            "NT2": ([
                "ascii": "+ +",
                "unicode": "\xe2\x95\x9d\xe2\x96\x91\xe2\x95\x9a",
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
            "NT1": ([
                "ascii": "+gate-default+",
                "unicode": "\xe2\x95\x94gate\xe2\x94\x84default\xe2\x95\x97",
            ]),
            "NT2": ([
                "ascii": "+ +",
                "unicode": "\xe2\x95\x9d\xe2\x96\x91\xe2\x95\x9a",
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
            "NT1": ([
                "ascii": "+archer-default+",
                "unicode": "\xe2\x95\x94archer\xe2\x86\xa5default\xe2\x95\x97",
            ]),
            "NT2": ([
                "ascii": "+ +",
                "unicode": "\xe2\x95\x9d\xe2\x96\x91\xe2\x95\x9a",
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
            "NT1": ([
                "ascii": "+ballista-default+",
                "unicode": "\xe2\x95\x94ballista\xe2\x87\xaddefault\xe2\x95\x97",
            ]),
            "NT2": ([
                "ascii": "+ +",
                "unicode": "\xe2\x95\x9d\xe2\x96\x91\xe2\x95\x9a",
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
                "unicode": "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7"
                    "\xe2\x88\xb7\xe2\x88\xb7",
            ]),
            "NEMTR2": ([
                "ascii":".    .",
                "unicode": "\xe2\x88\xb7    \xe2\x88\xb7",
            ]),
            "NEMTR3": ([
                "ascii":"     .",
                "unicode": "     \xe2\x88\xb7",
            ]),
            "NEMTR4": ([
                "ascii":"    ..",
                "unicode": "    \xe2\x88\xb7\xe2\x88\xb7",
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
            "NEMTR1": ([
                "ascii":"+====+",
                "unicode": "\xe2\x95\x94\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x97",
            ]),
            "NEMTR2": ([
                "ascii":"|    |",
                "unicode": "\xe2\x95\xa3    \xe2\x95\x91",
            ]),
            "NEMTR3": ([
                "ascii":"     |",
                "unicode": "\xe2\x94\x82    \xe2\x95\x91",
            ]),
            "NEMTR4": ([
                "ascii":"    =+",
                "unicode": "\xe2\x94\x94\xe2\x94\x80\xe2\x94\x80\xe2\x95\xa6"
                    "\xe2\x95\x90\xe2\x95\x9d",
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
            "NEMTR1": ([
                "ascii":"+====+",
                "unicode": "\xe2\x95\x94\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x97",
            ]),
            "NEMTR2": ([
                "ascii":"|    |",
                "unicode": "\xe2\x95\xa3\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91"
                    "\xe2\x96\x91\xe2\x95\x91",
            ]),
            "NEMTR3": ([
                "ascii":"     |",
                "unicode": "\xe2\x94\x82\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91"
                    "\xe2\x96\x91\xe2\x95\x91",
            ]),
            "NEMTR4": ([
                "ascii":"    =+",
                "unicode": "\xe2\x94\x94\xe2\x94\x80\xe2\x94\x80\xe2\x95\xa6"
                    "\xe2\x95\x90\xe2\x95\x9d",
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
            "NEMTR1": ([
                "ascii":"+====+",
                "unicode": "\xe2\x95\x94\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x97",
            ]),
            "NEMTR2": ([
                "ascii":"|+archer--default+|",
                "unicode": "\xe2\x95\xa3\xe2\x94\x8farcher\xe2\x86\xa5\xe2\x86\xa5"
                    "default\xe2\x94\x93\xe2\x95\x91",
            ]),
            "NEMTR3": ([
                "ascii":" +--+|",
                "unicode": "\xe2\x94\x82\xe2\x94\x97\xe2\x94\x81\xe2\x94\x81"
                    "\xe2\x94\x9b\xe2\x95\x91",
            ]),
            "NEMTR4": ([
                "ascii":"    =+",
                "unicode": "\xe2\x94\x94\xe2\x94\x80\xe2\x94\x80\xe2\x95\xa6"
                    "\xe2\x95\x90\xe2\x95\x9d",
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
            "NEMTR1": ([
                "ascii":"+====+",
                "unicode": "\xe2\x95\x94\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x97",
            ]),
            "NEMTR2": ([
                "ascii":"|+ballista~~default+|",
                "unicode": "\xe2\x95\xa3\xe2\x95\xadballista\xe2\x87\xad\xe2\x87\xad"
                    "default\xe2\x95\xae\xe2\x95\x91",
            ]),
            "NEMTR3": ([
                "ascii":" +~~+|",
                "unicode": "\xe2\x94\x82\xe2\x95\xb0\xe2\x94\x80\xe2\x94\x80"
                    "\xe2\x95\xaf\xe2\x95\x91",
            ]),
            "NEMTR4": ([
                "ascii":"    =+",
                "unicode": "\xe2\x94\x94\xe2\x94\x80\xe2\x94\x80\xe2\x95\xa6"
                    "\xe2\x95\x90\xe2\x95\x9d",
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
            "NEMTR1": ([
                "ascii":"+====+",
                "unicode": "\xe2\x95\x94\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x97",
            ]),
            "NEMTR2": ([
                "ascii":"|+catapult~~default+|",
                "unicode": "\xe2\x95\xa3\xe2\x94\x8fcatapult\xe2\x87\xaf\xe2\x86\xad"
                    "default\xe2\x94\x93\xe2\x95\x91",
            ]),
            "NEMTR3": ([
                "ascii":" +~~+|",
                "unicode": "\xe2\x94\x82\xe2\x94\x97\xe2\x94\x81\xe2\x94\x81"
                    "\xe2\x94\x9b\xe2\x95\x91",
            ]),
            "NEMTR4": ([
                "ascii":"    =+",
                "unicode": "\xe2\x94\x94\xe2\x94\x80\xe2\x94\x80\xe2\x95\xa6"
                    "\xe2\x95\x90\xe2\x95\x9d",
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
            "NEMTR1": ([
                "ascii":"+====+",
                "unicode": "\xe2\x95\x94\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x97",
            ]),
            "NEMTR2": ([
                "ascii":"|+trebuchet~~default+|",
                "unicode": "\xe2\x95\xa3\xe2\x94\x8ftrebuchet\xe2\x87\xaf\xe2\x87\xb2"
                    "default\xe2\x94\x93\xe2\x95\x91",
            ]),
            "NEMTR3": ([
                "ascii":" +~~+|",
                "unicode": "\xe2\x94\x82\xe2\x94\x97\xe2\x94\x81\xe2\x94\x81"
                    "\xe2\x94\x9b\xe2\x95\x91",
            ]),
            "NEMTR4": ([
                "ascii":"    =+",
                "unicode": "\xe2\x94\x94\xe2\x94\x80\xe2\x94\x80\xe2\x95\xa6"
                    "\xe2\x95\x90\xe2\x95\x9d",
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
            "NEMTR1": ([
                "ascii":"+====+",
                "unicode": "\xe2\x95\x94\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x97",
            ]),
            "NEMTR2": ([
                "ascii":"|+mage~~default+|",
                "unicode": "\xe2\x95\xa3\xe2\x94\x8fmage\xe2\x8b\x90\xe2\x8b\x91"
                    "default\xe2\x94\x93\xe2\x95\x91",
            ]),
            "NEMTR3": ([
                "ascii":" +~~+|",
                "unicode": "\xe2\x94\x82\xe2\x94\x97\xe2\x94\x81\xe2\x94\x81"
                    "\xe2\x94\x9b\xe2\x95\x91",
            ]),
            "NEMTR4": ([
                "ascii":"    =+",
                "unicode": "\xe2\x94\x94\xe2\x94\x80\xe2\x94\x80\xe2\x95\xa6"
                    "\xe2\x95\x90\xe2\x95\x9d",
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
                "unicode": "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7",
            ]),
            "WM2": ([
                "ascii": "...",
                "unicode": "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7",
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
            "WM1": ([
                "ascii": "+-+",
                "unicode": "\xe2\x95\x94\xe2\x95\x90\xe2\x95\x9d",
            ]),
            "WM2": ([
                "ascii": "+-+",
                "unicode": "\xe2\x95\x9a\xe2\x95\x90\xe2\x95\x97",
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
            "WM1": ([
                "ascii": "+-+",
                "unicode": "\xe2\x95\x94\xe2\x95\x90\xe2\x95\x9d",
            ]),
            "WM2": ([
                "ascii": "+-+",
                "unicode": "\xe2\x95\x9a\xe2\x95\x90\xe2\x95\x97",
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
            "WM1": ([
                "ascii": "gate+default-+",
                "unicode": "gate\xe2\x95\x92default\xe2\x95\x90\xe2\x95\x9d",
            ]),
            "WM2": ([
                "ascii": "gate+default-+",
                "unicode": "gate\xe2\x95\x98default\xe2\x95\x90\xe2\x95\x97",
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
            "WM1": ([
                "ascii": "archer+default-+",
                "unicode": "\xe2\x95\x94archer\xe2\x87\xb2default\xe2\x95\x9d",
            ]),
            "WM2": ([
                "ascii": "archer+default-+",
                "unicode": "\xe2\x95\x9a\xe2\x95\x90\xe2\x95\x97",
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
            "WM1": ([
                "ascii": "ballista+default-+",
                "unicode": "\xe2\x95\x94ballista\xe2\x87\xaddefault\xe2\x95\x9d",
            ]),
            "WM2": ([
                "ascii": "ballista+default-+",
                "unicode": "\xe2\x95\x9a\xe2\x95\x90\xe2\x95\x97",
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
                "unicode": "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7",
            ]),
            "EM2": ([
                "ascii": "...",
                "unicode": "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7",
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
            "EM1": ([
                "ascii": "+-+",
                "unicode": "\xe2\x95\x9a\xe2\x95\x90\xe2\x95\x97",
            ]),
            "EM2": ([
                "ascii": "+-+",
                "unicode": "\xe2\x95\x94\xe2\x95\x90\xe2\x95\x9d",
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
            "EM1": ([
                "ascii": "+-+",
                "unicode": "\xe2\x95\x9a\xe2\x95\x90\xe2\x95\x97",
            ]),
            "EM2": ([
                "ascii": "+-+",
                "unicode": "\xe2\x95\x94\xe2\x95\x90\xe2\x95\x9d",
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
            "EM1": ([
                "ascii": "+-gate+default",
                "unicode": "\xe2\x95\x9a\xe2\x95\x90gate\xe2\x95\x95default",
            ]),
            "EM2": ([
                "ascii": "+-gate+default",
                "unicode": "\xe2\x95\x94\xe2\x95\x90gate\xe2\x95\x9bdefault",
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
            "EM1": ([
                "ascii": "+-archer+default",
                "unicode": "\xe2\x95\x9aarcher\xe2\x87\xb2default\xe2\x95\x97",
            ]),
            "EM2": ([
                "ascii": "+-archer+default",
                "unicode": "\xe2\x95\x94\xe2\x95\x90\xe2\x95\x9d",
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
            "EM1": ([
                "ascii": "+-ballista+default",
                "unicode": "\xe2\x95\x9aballista\xe2\x87\xaddefault\xe2\x95\x97",
            ]),
            "EM2": ([
                "ascii": "+-ballista+default",
                "unicode": "\xe2\x95\x94\xe2\x95\x90\xe2\x95\x9d",
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
                "unicode": "\xe2\x88\xb7\xe2\x88\xb7    ",
            ]),
            "SWMTR2": ([
                "ascii":".     ",
                "unicode": "\xe2\x88\xb7     ",
            ]),
            "SWMTR3": ([
                "ascii":".    .",
                "unicode": "\xe2\x88\xb7    \xe2\x88\xb7",
            ]),
            "SWMTR4": ([
                "ascii":"......",
                "unicode": "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7"
                    "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7",
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
            "SWMTR1": ([
                "ascii":"+-    ",
                "unicode": "\xe2\x95\x94\xe2\x95\x90\xe2\x95\xa9\xe2\x94\x80"
                    "\xe2\x94\x80\xe2\x94\x90",
            ]),
            "SWMTR2": ([
                "ascii":"|     ",
                "unicode": "\xe2\x95\x91    \xe2\x94\x82",
            ]),
            "SWMTR3": ([
                "ascii":"|    |",
                "unicode": "\xe2\x95\x91    \xe2\x95\xa0",
            ]),
            "SWMTR4": ([
                "ascii": "+----+",
                "unicode": "\xe2\x95\x9a\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x9d",
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
            "SWMTR1": ([
                "ascii":"+=    ",
                "unicode": "\xe2\x95\x94\xe2\x95\x90\xe2\x95\xa9\xe2\x94\x80"
                    "\xe2\x94\x80\xe2\x94\x90",
            ]),
            "SWMTR2": ([
                "ascii":"|     ",
                "unicode": "\xe2\x95\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91"
                    "\xe2\x96\x91\xe2\x94\x82",
            ]),
            "SWMTR3": ([
                "ascii":"|    |",
                "unicode": "\xe2\x95\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91"
                    "\xe2\x96\x91\xe2\x95\xa0",
            ]),
            "SWMTR4": ([
                "ascii": "+====+",
                "unicode": "\xe2\x95\x9a\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x9d",
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
            "SWMTR1": ([
                "ascii":"+=    ",
                "unicode": "\xe2\x95\x94\xe2\x95\x90\xe2\x95\xa9\xe2\x94\x80"
                    "\xe2\x94\x80\xe2\x94\x90",
            ]),
            "SWMTR2": ([
                "ascii":"|+--+ ",
                "unicode": "\xe2\x95\x91\xe2\x94\x8f\xe2\x94\x81\xe2\x94\x81"
                    "\xe2\x94\x93\xe2\x94\x82",
            ]),
            "SWMTR3": ([
                "ascii":"|+archer--default+|",
                "unicode": "\xe2\x95\x91\xe2\x94\x97archer\xe2\x86\xa7\xe2\x86\xa7"
                    "default\xe2\x94\x9b\xe2\x95\xa0",
            ]),
            "SWMTR4": ([
                "ascii": "+====+",
                "unicode": "\xe2\x95\x9a\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x9d",
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
            "SWMTR1": ([
                "ascii":"+=    ",
                "unicode": "\xe2\x95\x94\xe2\x95\x90\xe2\x95\xa9\xe2\x94\x80"
                    "\xe2\x94\x80\xe2\x94\x90",
            ]),
            "SWMTR2": ([
                "ascii":"|+~~+ ",
                "unicode": "\xe2\x95\x91\xe2\x94\x8f\xe2\x94\x81\xe2\x94\x81"
                    "\xe2\x94\x93\xe2\x94\x82",
            ]),
            "SWMTR3": ([
                "ascii":"|+ballista~~default+|",
                "unicode": "\xe2\x95\x91\xe2\x94\x97ballista\xe2\x87\xa9\xe2\x87\xa9"
                    "default\xe2\x94\x9b\xe2\x95\xa0",
            ]),
            "SWMTR4": ([
                "ascii": "+====+",
                "unicode": "\xe2\x95\x9a\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x9d",
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
            "SWMTR1": ([
                "ascii":"+=    ",
                "unicode": "\xe2\x95\x94\xe2\x95\x90\xe2\x95\xa9\xe2\x94\x80"
                    "\xe2\x94\x80\xe2\x94\x90",
            ]),
            "SWMTR2": ([
                "ascii":"|+~~+ ",
                "unicode": "\xe2\x95\x91\xe2\x94\x8f\xe2\x94\x81\xe2\x94\x81"
                    "\xe2\x94\x93\xe2\x94\x82",
            ]),
            "SWMTR3": ([
                "ascii":"|+catapult~~default+|",
                "unicode": "\xe2\x95\x91\xe2\x94\x97catapult\xe2\x87\xaf\xe2\x86\xad"
                    "default\xe2\x94\x9b\xe2\x95\xa0",
            ]),
            "SWMTR4": ([
                "ascii": "+====+",
                "unicode": "\xe2\x95\x9a\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x9d",
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
            "SWMTR1": ([
                "ascii":"+=    ",
                "unicode": "\xe2\x95\x94\xe2\x95\x90\xe2\x95\xa9\xe2\x94\x80"
                    "\xe2\x94\x80\xe2\x94\x90",
            ]),
            "SWMTR2": ([
                "ascii":"|+~~+ ",
                "unicode": "\xe2\x95\x91\xe2\x94\x8f\xe2\x94\x81\xe2\x94\x81"
                    "\xe2\x94\x93\xe2\x94\x82",
            ]),
            "SWMTR3": ([
                "ascii":"|+trebuchet~~default+|",
                "unicode": "\xe2\x95\x91\xe2\x94\x97trebuchet\xe2\x87\xaf\xe2\x87\xb2"
                    "default\xe2\x94\x9b\xe2\x95\xa0",
            ]),
            "SWMTR4": ([
                "ascii": "+====+",
                "unicode": "\xe2\x95\x9a\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x9d",
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
            "SWMTR1": ([
                "ascii":"+=    ",
                "unicode": "\xe2\x95\x94\xe2\x95\x90\xe2\x95\xa9\xe2\x94\x80"
                    "\xe2\x94\x80\xe2\x94\x90",
            ]),
            "SWMTR2": ([
                "ascii":"|+~~+ ",
                "unicode": "\xe2\x95\x91\xe2\x94\x8f\xe2\x94\x81\xe2\x94\x81"
                    "\xe2\x94\x93\xe2\x94\x82",
            ]),
            "SWMTR3": ([
                "ascii":"|+mage~~default+|",
                "unicode": "\xe2\x95\x91\xe2\x94\x97mage\xe2\x8b\x90\xe2\x8b\x91"
                    "default\xe2\x94\x9b\xe2\x95\xa0",
            ]),
            "SWMTR4": ([
                "ascii": "+====+",
                "unicode": "\xe2\x95\x9a\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x9d",
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
                "unicode": "\xe2\x88\xb7 \xe2\x88\xb7",
            ]),
            "ST2": ([
                "ascii": "...",
                "unicode": "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7",
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
            "ST1": ([
                "ascii": "+ +",
                "unicode": "\xe2\x95\x97 \xe2\x95\x94",
            ]),
            "ST2": ([
                "ascii": "+-+",
                "unicode": "\xe2\x95\x9a\xe2\x95\x90\xe2\x95\x9d",
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
            "ST1": ([
                "ascii": "+ +",
                "unicode": "\xe2\x95\x97\xe2\x96\x91\xe2\x95\x94",
            ]),
            "ST2": ([
                "ascii": "+-+",
                "unicode": "\xe2\x95\x9a\xe2\x95\x90\xe2\x95\x9d",
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
            "ST1": ([
                "ascii": "+ +",
                "unicode": "\xe2\x95\x97\xe2\x96\x91\xe2\x95\x94",
            ]),
            "ST2": ([
                "ascii": "+gate-default+",
                "unicode": "\xe2\x95\x9agate\xe2\x94\x84default\xe2\x95\x9d",
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
            "ST1": ([
                "ascii": "+ +",
                "unicode": "\xe2\x95\x97\xe2\x96\x91\xe2\x95\x94",
            ]),
            "ST2": ([
                "ascii": "+archer-default+",
                "unicode": "\xe2\x95\x9aarcher\xe2\x86\xa7default\xe2\x95\x9d",
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
            "ST1": ([
                "ascii": "+ +",
                "unicode": "\xe2\x95\x97\xe2\x96\x91\xe2\x95\x94",
            ]),
            "ST2": ([
                "ascii": "+ballista-default+",
                "unicode": "\xe2\x95\x9aballista\xe2\x87\xa9default\xe2\x95\x9d",
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
                "unicode": "    \xe2\x88\xb7\xe2\x88\xb7",
            ]),
            "SEMTR2": ([
                "ascii":"     .",
                "unicode": "     \xe2\x88\xb7",
            ]),
            "SEMTR3": ([
                "ascii":".    .",
                "unicode": "\xe2\x88\xb7    \xe2\x88\xb7",
            ]),
            "SEMTR4": ([
                "ascii":"......",
                "unicode": "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7"
                    "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7",
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
            "SEMTR1": ([
                "ascii":"    -+",
                "unicode": "\xe2\x94\x8c\xe2\x94\x80\xe2\x94\x80\xe2\x95\xa9"
                    "\xe2\x95\x90\xe2\x95\x97",
            ]),
            "SEMTR2": ([
                "ascii":"     |",
                "unicode": "\xe2\x94\x82    \xe2\x95\x91",
            ]),
            "SEMTR3": ([
                "ascii":"|    |",
                "unicode": "\xe2\x95\xa3    \xe2\x95\x91",
            ]),
            "SEMTR4": ([
                "ascii": "+----+",
                "unicode": "\xe2\x95\x9a\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x9d",
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
            "SEMTR1": ([
                "ascii":"    =+",
                "unicode": "\xe2\x94\x8c\xe2\x94\x80\xe2\x94\x80\xe2\x95\xa9"
                    "\xe2\x95\x90\xe2\x95\x97",
            ]),
            "SEMTR2": ([
                "ascii":"     |",
                "unicode": "\xe2\x94\x82\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91"
                    "\xe2\x96\x91\xe2\x95\x91",
            ]),
            "SEMTR3": ([
                "ascii":"|    |",
                "unicode": "\xe2\x95\xa3\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91"
                    "\xe2\x96\x91\xe2\x95\x91",
            ]),
            "SEMTR4": ([
                "ascii": "+====+",
                "unicode": "\xe2\x95\x9a\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x9d",
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
            "SEMTR1": ([
                "ascii":"    =+",
                "unicode": "\xe2\x94\x8c\xe2\x94\x80\xe2\x94\x80\xe2\x95\xa9"
                    "\xe2\x95\x90\xe2\x95\x97",
            ]),
            "SEMTR2": ([
                "ascii":" +--+|",
                "unicode": "\xe2\x94\x82\xe2\x94\x8f\xe2\x94\x81\xe2\x94\x81"
                    "\xe2\x94\x93\xe2\x95\x91",
            ]),
            "SEMTR3": ([
                "ascii":"|+archer--default+|",
                "unicode": "\xe2\x95\xa3\xe2\x94\x97archer\xe2\x86\xa7\xe2\x86\xa7"
                    "default\xe2\x94\x9b\xe2\x95\x91",
            ]),
            "SEMTR4": ([
                "ascii": "+====+",
                "unicode": "\xe2\x95\x9a\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x9d",
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
            "SEMTR1": ([
                "ascii":"    =+",
                "unicode": "\xe2\x94\x8c\xe2\x94\x80\xe2\x94\x80\xe2\x95\xa9"
                    "\xe2\x95\x90\xe2\x95\x97",
            ]),
            "SEMTR2": ([
                "ascii":" +~~+|",
                "unicode": "\xe2\x94\x82\xe2\x94\x8f\xe2\x94\x81\xe2\x94\x81"
                    "\xe2\x94\x93\xe2\x95\x91",
            ]),
            "SEMTR3": ([
                "ascii":"|+ballista~~default+|",
                "unicode": "\xe2\x95\xa3\xe2\x94\x97ballista\xe2\x87\xa9\xe2\x87\xa9"
                    "default\xe2\x94\x9b\xe2\x95\x91",
            ]),
            "SEMTR4": ([
                "ascii": "+====+",
                "unicode": "\xe2\x95\x9a\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x9d",
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
            "SEMTR1": ([
                "ascii":"    =+",
                "unicode": "\xe2\x94\x8c\xe2\x94\x80\xe2\x94\x80\xe2\x95\xa9"
                    "\xe2\x95\x90\xe2\x95\x97",
            ]),
            "SEMTR2": ([
                "ascii":" +~~+|",
                "unicode": "\xe2\x94\x82\xe2\x94\x8f\xe2\x94\x81\xe2\x94\x81"
                    "\xe2\x94\x93\xe2\x95\x91",
            ]),
            "SEMTR3": ([
                "ascii":"|+catapult~~default+|",
                "unicode": "\xe2\x95\xa3\xe2\x94\x97catapult\xe2\x87\xaf\xe2\x86\xad"
                    "default\xe2\x94\x9b\xe2\x95\x91",
            ]),
            "SEMTR4": ([
                "ascii": "+====+",
                "unicode": "\xe2\x95\x9a\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x9d",
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
            "SEMTR1": ([
                "ascii":"    =+",
                "unicode": "\xe2\x94\x8c\xe2\x94\x80\xe2\x94\x80\xe2\x95\xa9"
                    "\xe2\x95\x90\xe2\x95\x97",
            ]),
            "SEMTR2": ([
                "ascii":" +~~+|",
                "unicode": "\xe2\x94\x82\xe2\x94\x8f\xe2\x94\x81\xe2\x94\x81"
                    "\xe2\x94\x93\xe2\x95\x91",
            ]),
            "SEMTR3": ([
                "ascii":"|+trebuchet~~default+|",
                "unicode": "\xe2\x95\xa3\xe2\x94\x97trebuchet\xe2\x87\xaf\xe2\x87\xb2"
                    "default\xe2\x94\x9b\xe2\x95\x91",
            ]),
            "SEMTR4": ([
                "ascii": "+====+",
                "unicode": "\xe2\x95\x9a\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x9d",
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
            "SEMTR1": ([
                "ascii":"    =+",
                "unicode": "\xe2\x94\x8c\xe2\x94\x80\xe2\x94\x80\xe2\x95\xa9"
                    "\xe2\x95\x90\xe2\x95\x97",
            ]),
            "SEMTR2": ([
                "ascii":" +~~+|",
                "unicode": "\xe2\x94\x82\xe2\x94\x8f\xe2\x94\x81\xe2\x94\x81"
                    "\xe2\x94\x93\xe2\x95\x91",
            ]),
            "SEMTR3": ([
                "ascii":"|+mage~~default+|",
                "unicode": "\xe2\x95\xa3\xe2\x94\x97mage\xe2\x8b\x90\xe2\x8b\x91"
                    "default\xe2\x94\x9b\xe2\x95\x91",
            ]),
            "SEMTR4": ([
                "ascii": "+====+",
                "unicode": "\xe2\x95\x9a\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90"
                    "\xe2\x95\x90\xe2\x95\x9d",
            ]),
        ]),
    ]),
]);

#endif
