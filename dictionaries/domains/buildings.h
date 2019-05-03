//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private string *castleLayout = ({
    "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM",
    "WSMNWCTR1            NCATOWER1            NECTR1ESM",
    "WSMNWCTR2NWCASTLEWALLNCATOWER2NECASTLEWALLNECTR2ESM",
    "WSMNWCTR3            NCATOWER3            NECTR3ESM",
    "WSMNWCTR4                                 NECTR4ESM",
    "WSMNWX      NWMTR1      NT1      NEMTR1      NEXESM",
    "WSMNWX      NWMTR2NWMWALNT2NEMWALNEMTR2      NEXESM",
    "WSMNWX      NWMTR3NW1         NE1NEMTR3      NEXESM",
    "WSMNWX      NWMTR4NW2         NE2NEMTR4      NEXESM",
    "WSMNWX      NWIWB1               EB1NEI      NEXESM",
    "WSMWCT1     NWIWB2   KEEP    1   EB2NEI     ECT1ESM",
    "WSMWCT2     NWIWB3   KEEP    2   EB3NEI     ECT2ESM",
    "WSMWCT3     WM1      KEEP    3      EM1     ECT3ESM",
    "WSMWCT4     WM2      KEEP    4      EM2     ECT4ESM",
    "WSMWCT5     SWIWB4   KEEP    5   EB4SEI     ECT5ESM",
    "WSMWCT6     SWIWB5               EB5SEI     ECT6ESM",
    "WSMSWX      SWIWB6               EB6SEI      SEXESM",
    "WSMSWX      SWMTR1SW1         SE1SEMTR1      SEXESM",
    "WSMSWX      SWMTR2SW2         SE2SEMTR2      SEXESM",
    "WSMSWX      SWMTR3SWMWALST1SEMWALSEMTR3      SEXESM",
    "WSMSWX      SWMTR4      ST2      SEMTR4      SEXESM",
    "WSMSWCTR1                                 SECTR1ESM",
    "WSMSWCTR2            SCATOWER1            SECTR2ESM",
    "WSMSWCTR3SWCASTLEWALLSCATOWER2SECASTLEWALLSECTR3ESM",
    "WSMSWCTR4            SCATOWER3            SECTR4ESM",
    "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM",
    });

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
private mapping BuildingBlueprints = ([
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
            "keep":([
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
            "keep":([
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
            "keep":([
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
            "keep":([
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
    ]),
    "motte and bailey":([
        "dimensions":"7x7",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;124m",
                "24-bit": "\x1b[0;38;2;150,0,0m",
            ]),
        ]),
        "components":([ 
            "keep":([
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
            "northwest tower": ([
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
            "northwest building": ([
                "NW1": ([
                    "ascii": ".?.",
                    "unicode": "\xe2\x94\x8a\xe2\x81\x87\xe2\x94\x8a",
                ]),
                "NW2": ([
                    "ascii": "...",
                    "unicode": "\xe2\x94\x94\xe2\x94\x88\xe2\x94\x98",
                ]),
            ]),
            "north tower": ([
                "NT1": ([
                    "ascii": "...",
                    "unicode": "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7",
                ]),
                "NT2": ([
                    "ascii": ". .",
                    "unicode": "\xe2\x88\xb7 \xe2\x88\xb7",
                ]),
            ]),
            "northeast building": ([
                "NE1": ([
                    "ascii": ".?.",
                    "unicode": "\xe2\x94\x8a\xe2\x81\x87\xe2\x94\x8a",
                ]),
                "NE2": ([
                    "ascii": "...",
                    "unicode": "\xe2\x94\x94\xe2\x94\x88\xe2\x94\x98",
                ]),
            ]),
            "northeast tower": ([
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
            "first western building":  ([
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
            "second western building": ([
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
            "west tower": ([
                "WM1": ([
                    "ascii": "...",
                    "unicode": "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7",
                ]),
                "WM2": ([
                    "ascii": "...",
                    "unicode": "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7",
                ]),
            ]),
            "first eastern building": ([
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
            "second eastern building": ([
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
            "east tower": ([
                "EM1": ([
                    "ascii": "...",
                    "unicode": "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7",
                ]),
                "EM2": ([
                    "ascii": "...",
                    "unicode": "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7",
                ]),
            ]),
            "southwest tower": ([
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
            "southwest building": ([
                "SW1": ([
                    "ascii": "...",
                    "unicode": "\xe2\x94\x8c\xe2\x94\x88\xe2\x94\x90",
                ]),
                "SW2": ([
                    "ascii": ".?.",
                    "unicode": "\xe2\x94\x8a\xe2\x81\x87\xe2\x94\x8a",
                ]),
            ]),
            "south tower":  ([
                "ST1": ([
                    "ascii": ". .",
                    "unicode": "\xe2\x88\xb7 \xe2\x88\xb7",
                ]),
                "ST2": ([
                    "ascii": "...",
                    "unicode": "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7",
                ]),
            ]),
            "southeast building": ([
                "SE1": ([
                    "ascii": "...",
                    "unicode": "\xe2\x94\x8c\xe2\x94\x88\xe2\x94\x90",
                ]),
                "SE2": ([
                    "ascii": ".?.",
                    "unicode": "\xe2\x94\x8a\xe2\x81\x87\xe2\x94\x8a",
                ]),
            ]),
            "southeast tower": ([
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
            "western north wall": ([
                "NWMWAL": ([
                    "ascii": "......",
                    "unicode": "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7"
                        "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7",
                ]),
            ]),
            "eastern north wall": ([
                "NEMWAL": ([
                    "ascii": "......",
                    "unicode": "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7"
                        "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7",
                ]),
            ]),
            "western south wall": ([
                "SWMWAL": ([
                    "ascii": "......",
                    "unicode": "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7"
                        "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7",
                ]),
            ]),
            "eastern south wall": ([
                "SEMWAL": ([
                    "ascii": "......",
                    "unicode": "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7"
                        "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7",
                ]),
            ]),
            "northern west wall": ([
                "NWI": ([
                    "ascii": " . ",
                    "unicode":  " \xe2\x88\xb7 ",
                ]),
            ]),
            "southern west wall": ([
                "SWI": ([
                    "ascii": " . ",
                    "unicode":  " \xe2\x88\xb7 ",
                ]),
            ]),
            "northern east wall": ([
                "NEI": ([
                    "ascii": " . ",
                    "unicode":  " \xe2\x88\xb7 ",
                ]),
            ]),
            "southern east wall": ([
                "SEI": ([
                    "ascii": " . ",
                    "unicode":  " \xe2\x88\xb7 ",
                ]),
            ]),
        ]),
    ]),
    "castle":([
        "dimensions":"17x15",
        "description": "",
        "colors": ([
            "default":([
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;124m",
                "3-bit": "\x1b[0;38;2;150,0,0m",
            ]),
            "moat":([
                "3-bit": "\x1b[0;44;30m",
                "8-bit": "\x1b[0;48;5;20;38;5;14m",
                "3-bit": "\x1b[0;48;2;0;0;180;38;2;0,190,255m",
            ]),
        ]),
        "components":([
            "moat":([
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
            "northwest castle tower": ([
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
            "northeast castle tower": ([
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
            "southwest castle tower": ([
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
            "southeast castle tower": ([
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
            "western north castle wall": ([
                "NWCASTLEWALL": ([
                    "ascii": "............",
                    "unicode": "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7"
                        "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7"
                        "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7"
                        "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7",
                ]),
            ]),
            "eastern north castle wall": ([
                "NECASTLEWALL": ([
                    "ascii": "............",
                    "unicode": "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7"
                        "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7"
                        "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7"
                        "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7",
                ]),
            ]),
            "western south castle wall": ([
                "SWCASTLEWALL": ([
                    "ascii": "............",
                    "unicode": "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7"
                        "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7"
                        "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7"
                        "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7",
                ]),
            ]),
            "eastern south castle wall": ([
                "SECASTLEWALL": ([
                    "ascii": "............",
                    "unicode": "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7"
                        "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7"
                        "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7"
                        "\xe2\x88\xb7\xe2\x88\xb7\xe2\x88\xb7",
                ]),
            ]),
            "northern west castle wall": ([
                "NWX": ([
                    "ascii": " . ",
                    "unicode":  " \xe2\x88\xb7 ",
                ]),
            ]),
            "southern west castle wall": ([
                "SWX": ([
                    "ascii": " . ",
                    "unicode":  " \xe2\x88\xb7 ",
                ]),
            ]),
            "northern east casle wall": ([
                "NEX": ([
                    "ascii": " . ",
                    "unicode":  " \xe2\x88\xb7 ",
                ]),
            ]),
            "southern east castle wall": ([
                "SEX": ([
                    "ascii": " . ",
                    "unicode":  " \xe2\x88\xb7 ",
                ]),
            ]),
            "north castle tower": ([
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
            "south castle tower": ([
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
            "west castle tower": ([
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
            "east castle tower": ([
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
    ]),
]);
