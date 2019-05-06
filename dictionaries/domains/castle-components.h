//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

/*
mapping swapstuff = ([
"KEEP    1": "\xe2\x94\x8c\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80"
"\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x90",
"KEEP    2":  "\xe2\x94\x82\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91"
"\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x94\x82",
"KEEP    3": "\xe2\x94\x83\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x94\x83",
"KEEP    4": "\xe2\x94\x83\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x94\x83",
"KEEP    5": "\xe2\x94\x94\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80"
"\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x98",
"MMM": "   ",
"NWX": "  \xe2\x95\x91",
"NEX": "\xe2\x95\x91  ",
"SWX": "  \xe2\x95\x91",
"SEX": "\xe2\x95\x91  ",
"NWI": "  \xe2\x95\x91",
"NEI": "\xe2\x95\x91  ",
"WC1": "\xe2\x95\x94\xe2\x95\x90\xe2\x95\x9d",
"WC2": "\xe2\x95\x91  ",
"WC3": "\xe2\x95\x91  ",
"WC4": "\xe2\x95\x91  ",
"WC5": "\xe2\x95\x91  ",
"WC6": "\xe2\x95\x9a\xe2\x95\x90\xe2\x95\x97",
"WM1": "\xe2\x95\x94\xe2\x95\x90\xe2\x95\x9d",
"WM2": "\xe2\x95\x9a\xe2\x95\x90\xe2\x95\x97",
"EM1": "\xe2\x95\x9a\xe2\x95\x90\xe2\x95\x97",
"EM2": "\xe2\x95\x94\xe2\x95\x90\xe2\x95\x9d",
"EC1": "\xe2\x95\x9a\xe2\x95\x90\xe2\x95\x97",
"EC2": "  \xe2\x95\x91",
"EC3": "  \xe2\x95\x91",
"EC4": "  \xe2\x95\x91",
"EC5": "  \xe2\x95\x91",
"EC6": "\xe2\x95\x94\xe2\x95\x90\xe2\x95\x9d",
"NWCTR1": "\xe2\x95\x94\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x97",
"NWCTR2": "\xe2\x95\x91    \xe2\x95\x91",
"NWCTR3": "\xe2\x95\x91    \xe2\x95\x91",
"NWCTR4": "\xe2\x95\x9a\xe2\x95\x90\xe2\x95\xa6\xe2\x95\x90\xe2\x95\x90\xe2\x95\x9d",
"NECTR1": "\xe2\x95\x94\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x97",
"NECTR2": "\xe2\x95\x91    \xe2\x95\x91",
"NECTR3": "\xe2\x95\x91    \xe2\x95\x91",
"NECTR4": "\xe2\x95\x9a\xe2\x95\x90\xe2\x95\x90\xe2\x95\xa6\xe2\x95\x90\xe2\x95\x9d",
"NCATOWER1": "\xe2\x95\x94\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x97",
"NCATOWER2": "\xe2\x95\x91       \xe2\x95\x91",
"NCATOWER3": "\xe2\x95\x9a\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x9d",
"NWCASTLEWALL": "\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90",
"NECASTLEWALL": "\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90",
"SWCASTLEWALL": "\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90",
"SECASTLEWALL": "\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90",
"NT1": "\xe2\x95\x94\xe2\x95\x90\xe2\x95\x97",
"NT2": "\xe2\x95\x9d \xe2\x95\x9a",
"NWMWAL": "\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90",
"NEMWAL": "\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90",
"NWMTR1": "\xe2\x95\x94\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x97",
"NWMTR2": "\xe2\x95\x91    \xe2\x95\x9a",
"NWMTR3": "\xe2\x95\x91     ",
"NWMTR4": "\xe2\x95\x9a\xe2\x95\x90\xe2\x95\x97  ",
"NEMTR1": "\xe2\x95\x94\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x97",
"NEMTR2": "\xe2\x95\x9d    \xe2\x95\x91",
"NEMTR3": "     \xe2\x95\x91",
"NEMTR4": "    \xe2\x95\x94\xe2\x95\x90\xe2\x95\x9d",
"SWMWAL": "\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90",
"SEMWAL": "\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90",
"SWMTR1": "\xe2\x95\x94\xe2\x95\x90\xe2\x95\x9d  ",
"SWMTR2": "\xe2\x95\x91     ",
"SWMTR3": "\xe2\x95\x91    \xe2\x95\x94",
"SWMTR4": "\xe2\x95\x9a\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x9d",
"SEMTR1": "    \xe2\x95\x9a\xe2\x95\x90\xe2\x95\x97",
"SEMTR2": "     \xe2\x95\x91",
"SEMTR3": "\xe2\x95\x97    \xe2\x95\x91",
"SEMTR4": "\xe2\x95\x9a\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x9d",
"ST1": "\xe2\x95\x97 \xe2\x95\x94",
"ST2": "\xe2\x95\x9a\xe2\x95\x90\xe2\x95\x9d",
"SWCTR1": "\xe2\x95\x94\xe2\x95\x90\xe2\x95\xa9\xe2\x95\x90\xe2\x95\x90\xe2\x95\x97",
"SWCTR2": "\xe2\x95\x91    \xe2\x95\x91",
"SWCTR3": "\xe2\x95\x91    \xe2\x95\x91",
"SWCTR4": "\xe2\x95\x9a\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x9d",
"SECTR1": "\xe2\x95\x94\xe2\x95\x90\xe2\x95\x90\xe2\x95\xa9\xe2\x95\x90\xe2\x95\x97",
"SECTR2": "\xe2\x95\x91    \xe2\x95\x91",
"SECTR3": "\xe2\x95\x91    \xe2\x95\x91",
"SECTR4": "\xe2\x95\x9a\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x9d",
"SCATOWER1": "\xe2\x95\x94\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x97",
"SCATOWER2": "\xe2\x95\x91       \xe2\x95\x91",
"SCATOWER3": "\xe2\x95\x9a\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x9d",

]);*/
private mapping CastleComponents = ([
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

    "small wooden keep":([
        "type": "keep",
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
        "components":([
            "KEEP    1":([
                "ascii": "+-------+",
                "unicode": "\xe2\x94\x8c\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80"
                    "\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x90",
            ]),
            "KEEP    2":([
                "ascii": "|       |",
                "unicode": "\xe2\x94\x82\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91"
                    "\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x94\x82",
            ]),
            "KEEP    3":([
                "ascii": "|       |",
                "unicode": "\xe2\x94\x82\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91"
                    "\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x94\x82",
            ]),
            "KEEP    4":([
                "ascii": "|       |",
                "unicode": "\xe2\x94\x82\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91"
                    "\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x94\x82",
            ]),
            "KEEP    5":([
                "ascii": "+-------+",
                "unicode": "\xe2\x94\x94\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80"
                    "\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x98",
            ]),
        ]),
    ]),

    "wooden keep":([
        "type": "keep",
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
        "components":([ 
            "KEEP    1":([
                "ascii": "+~~~~~~~+",
                "unicode": "\xe2\x94\x8f\xe2\x94\x81\xe2\x94\x81\xe2\x94\x81"
                    "\xe2\x94\x81\xe2\x94\x81\xe2\x94\x81\xe2\x94\x81\xe2\x94\x93",
            ]),
            "KEEP    2":([
                "ascii": "|       |",
                "unicode": "\xe2\x94\x83\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91"
                    "\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x94\x83",
            ]),
            "KEEP    3":([
                "ascii": "|       |",
                "unicode": "\xe2\x94\x83\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91"
                    "\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x94\x83",
            ]),
            "KEEP    4":([
                "ascii": "|       |",
                "unicode": "\xe2\x94\x83\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91"
                    "\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x94\x83",
            ]),
            "KEEP    5":([
                "ascii": "+~~~~~~~+",
                "unicode": "\xe2\x94\x97\xe2\x94\x81\xe2\x94\x81\xe2\x94\x81"
                    "\xe2\x94\x81\xe2\x94\x81\xe2\x94\x81\xe2\x94\x81\xe2\x94\x9b",
            ]),
        ]),
    ]),

    "small stone keep":([
        "type": "keep",
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
        "components":([ 
            "KEEP    1":([
                "ascii": "+=======+",
                "unicode": "\xe2\x94\x8f\xe2\x94\x81\xe2\x94\x81\xe2\x94\x81"
                    "\xe2\x94\x81\xe2\x94\x81\xe2\x94\x81\xe2\x94\x81\xe2\x94\x93",
            ]),
            "KEEP    2":([
                "ascii": "|       |",
                "unicode": "\xe2\x94\x83\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91"
                    "\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x94\x83",
            ]),
            "KEEP    3":([
                "ascii": "|       |",
                "unicode": "\xe2\x94\x83\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91"
                    "\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x94\x83",
            ]),
            "KEEP    4":([
                "ascii": "|       |",
                "unicode": "\xe2\x94\x83\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91"
                    "\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x94\x83",
            ]),
            "KEEP    5":([
                "ascii": "+=======+",
                "unicode": "\xe2\x94\x97\xe2\x94\x81\xe2\x94\x81\xe2\x94\x81"
                    "\xe2\x94\x81\xe2\x94\x81\xe2\x94\x81\xe2\x94\x81\xe2\x94\x9b",
            ]),
        ]),
    ]),

    "stone keep":([
        "type": "keep",
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
        "components":([ 
            "KEEP    1":([
                "ascii": "+=======+",
                "unicode": "\xe2\x94\x8f\xe2\x94\x81\xe2\x94\x81\xe2\x94\x81"
                    "\xe2\x94\x81\xe2\x94\x81\xe2\x94\x81\xe2\x94\x81\xe2\x94\x93",
            ]),
            "KEEP    2":([
                "ascii": "| +---+ |",
                "unicode": "\xe2\x94\x83\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91"
                    "\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x94\x83",
            ]),
            "KEEP    3":([
                "ascii": "| |   | |",
                "unicode": "\xe2\x94\x83\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91"
                    "\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x94\x83",
            ]),
            "KEEP    4":([
                "ascii": "| +---+ |",
                "unicode": "\xe2\x94\x83\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91"
                    "\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x94\x83",
            ]),
            "KEEP    5":([
                "ascii": "+=======+",
                "unicode": "\xe2\x94\x97\xe2\x94\x81\xe2\x94\x81\xe2\x94\x81"
                    "\xe2\x94\x81\xe2\x94\x81\xe2\x94\x81\xe2\x94\x81\xe2\x94\x9b",
            ]),
        ]),
    ]),

    "unbuilt northwest tower":([
        "type": "northwest tower",
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

    "unbuilt north tower":([
        "type": "north tower",
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

    "unbuilt northeast tower":([
        "type": "northeast tower",
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

    "unbuilt west tower":([
        "type": "west tower",
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

    "unbuilt east tower":([
        "type": "east tower",
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

    "unbuilt southwest tower":([
        "type": "southwest tower",
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

    "unbuilt south tower":([
        "type": "south tower",
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

    "unbuilt southeast tower":([
        "type": "southeast tower",
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

    "unbuilt western north wall":([
        "type": "western north wall",
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

    "unbuilt eastern north wall":([
        "type": "eastern north wall",
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

    "unbuilt western south wall":([
        "type": "western south wall",
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

    "unbuilt eastern south wall":([
        "type": "eastern south wall",
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

    "unbuilt northern west wall":([
        "type": "northern west wall",
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

    "unbuilt southern west wall":([
        "type": "southern west wall",
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

    "unbuilt northern east wall":([
        "type": "northern east wall",
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

    "unbuilt southern east wall":([
        "type": "southern east wall",
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

    "unbuilt moat":([
        "type": "moat",
        "dimensions": "17x15",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;9m",
                "24-bit": "\x1b[0;38;2;200;0;0m"
            ]),
        ]),
        "components":([
            "MMM": ([
                "ascii": "   ",
                "unicode": "   ",
            ]),
            "WSM": ([
                "ascii": "   ",
                "unicode": "   ",
            ]),
            "ESM": ([
                "ascii": "   ",
                "unicode": "   ",
            ]),
        ]),
    ]),

    "simple moat":([
        "type": "moat",
        "dimensions": "17x15",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;44;30m",
                "8-bit": "\x1b[0;48;5;20;38;5;14m",
                "3-bit": "\x1b[0;48;2;0;0;180;38;2;0,190,255m",
            ]),
        ]),
        "components":([
            "MMM": ([
                "ascii": "~~~",
                "unicode": "\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91",
            ]),
            "WSM": ([
                "ascii": "  ~",
                "unicode": " \xe2\x96\x91\xe2\x96\x91",
            ]),
            "ESM": ([
                "ascii": "~  ",
                "unicode": "\xe2\x96\x91\xe2\x96\x91 ",
            ]),
        ]),
    ]),

    "unbuilt northwest castle tower":([
        "type": "northwest castle tower",
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

    "unbuilt northeast castle tower":([
        "type": "northeast castle tower",
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

    "unbuilt southwest castle tower":([
        "type": "southwest castle tower",
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

    "unbuilt southeast castle tower":([
        "type": "southeast castle tower",
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

    "unbuilt western north castle wall":([
        "type": "western north castle wall",
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

    "unbuilt eastern north castle wall":([
        "type": "eastern north castle wall",
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

    "unbuilt western south castle wall":([
        "type": "western south castle wall",
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

    "unbuilt eastern south castle wall":([
        "type": "eastern south castle wall",
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

    "unbuilt northern west castle wall":([
        "type": "northern west castle wall",
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

    "unbuilt southern west castle wall":([
        "type": "southern west castle wall",
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

    "unbuilt northern east castle wall":([
        "type": "northern east castle wall",
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

    "unbuilt southern east castle wall":([
        "type": "southern east castle wall",
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

    "unbuilt north castle tower":([
        "type": "north castle tower",
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

    "unbuilt south castle tower":([
        "type": "south castle tower",
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

    "unbuilt west castle tower":([
        "type": "west castle tower",
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

    "unbuilt east castle tower":([
        "type": "east castle tower",
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
]);
