//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef castles_h
#define castles_h

protected mapping CastleBlueprints = ([
    "keep":([
        "type": "keep",
        "dimensions": "3x3",
        "description": "",
        "layout": ({
            "   KEEP    1   ",
            "   KEEP    2   ",
            "   KEEP    3   ",
            "   KEEP    4   ",
            "   KEEP    5   ",
        }),
        "components":([
            "keep":([
                "type":"keep",
                "display name": "Keep",
                "sort order": 1,
                "description": ""
            ]),
        ]),
    ]),

    "motte and bailey":([
        "type": "motte and bailey",
        "dimensions":"7x7",
        "description": "",
        "layout": ({
            "NWMTR1      NT1      NEMTR1",
            "NWMTR2NWMWALNT2NEMWALNEMTR2",
            "NWMTR3NW1         NE1NEMTR3",
            "NWMTR4NW2         NE2NEMTR4",
            "NWIWB1               EB1NEI",
            "NWIWB2   KEEP    1   EB2NEI",
            "NWIWB3   KEEP    2   EB3NEI",
            "WM1      KEEP    3      EM1",
            "WM2      KEEP    4      EM2",
            "SWIWB4   KEEP    5   EB4SEI",
            "SWIWB5               EB5SEI",
            "SWIWB6               EB6SEI",
            "SWMTR1SW1         SE1SEMTR1",
            "SWMTR2SW2         SE2SEMTR2",
            "SWMTR3SWMWALST1SEMWALSEMTR3",
            "SWMTR4      ST2      SEMTR4",
        }),
        "components":([ 
            "keep":([
                "type":"keep",
                "display name": "Keep",
                "sort order": 1,
                "description": ""
            ]),
            "northwest tower": ([
                "type":"tower",
                "display name": "Northwest Tower",
                "sort order": 1,
                "description": ""
            ]),
            "northwest building": ([
                "type":"building",
                "display name": "Northwest Building",
                "sort order": 1,
                "description": ""
            ]),
            "north tower": ([
                "type":"tower",
                "display name": "North Tower",
                "sort order": 2,
                "description": ""
            ]),
            "northeast building": ([
                "type":"building",
                "display name": "Northeast Building",
                "sort order": 2,
                "description": ""
            ]),
            "northeast tower": ([
                "type":"tower",
                "display name": "Northeast Tower",
                "sort order": 3,
                "description": ""
            ]),
            "first western building": ([
                "type":"building",
                "display name": "West Building 1",
                "sort order": 3,
                "description": ""
            ]),
            "second western building": ([
                "type":"building",
                "display name": "West Building 2",
                "sort order": 4,
                "description": ""
            ]),
            "west tower": ([
                "type":"tower",
                "display name": "West Tower",
                "sort order": 4,
                "description": ""
            ]),
            "first eastern building": ([
                "type":"building",
                "display name": "East Building 1",
                "sort order": 5,
                "description": ""
            ]),
            "second eastern building": ([
                "type":"building",
                "display name": "East Building 2",
                "sort order": 6,
                "description": ""
            ]),
            "east tower": ([
                "type":"tower",
                "display name": "East Tower",
                "sort order": 5,
                "description": ""
            ]),
            "southwest tower": ([
                "type":"tower",
                "display name": "Southwest Tower",
                "sort order": 6,
                "description": ""
            ]),
            "southwest building": ([
                "type":"building",
                "display name": "Southwest Building",
                "sort order": 7,
                "description": ""
            ]),
            "south tower": ([
                "type":"tower",
                "display name": "South Tower",
                "sort order": 7,
                "description": ""
            ]),
            "southeast building": ([
                "type":"building",
                "display name": "Southeast Building",
                "sort order": 8,
                "description": ""
            ]),
            "southeast tower": ([
                "type":"tower",
                "display name": "Southeast Tower",
                "sort order": 8,
                "description": ""
            ]),
            "western north wall": ([
                "type":"wall",
                "display name": "North Inner Wall W",
                "sort order": 1,
                "description": ""
            ]),
            "eastern north wall": ([
                "type":"wall",
                "display name": "North Inner Wall E",
                "sort order": 2,
                "description": ""
            ]),
            "northern west wall": ([
                "type":"wall",
                "display name": "West Inner Wall N",
                "sort order": 3,
                "description": ""
            ]),
            "southern west wall": ([
                "type":"wall",
                "display name": "West Inner Wall S",
                "sort order": 4,
                "description": ""
            ]),
            "northern east wall": ([
                "type":"wall",
                "display name": "East Inner Wall N",
                "sort order": 5,
                "description": ""
            ]),
            "southern east wall": ([
                "type":"wall",
                "display name": "East Inner Wall S",
                "sort order": 6,
                "description": ""
            ]),
            "western south wall": ([
                "type":"wall",
                "display name": "South Inner Wall W",
                "sort order": 7,
                "description": ""
            ]),
            "eastern south wall": ([
                "type":"wall",
                "display name": "South Inner Wall E",
                "sort order": 8,
                "description": ""
            ]),
        ]),
    ]),

    "castle":([
        "dimensions":"17x15",
        "description": "",
        "layout": ({
            "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM",
            "WSMNWCTR1            NCATOWER1            NECTR1ESM",
            "WSMNWCTR2NWCASTLEWALLNCATOWER2NECASTLEWALLNECTR2ESM",
            "WSMNWCTR3NC1         NCATOWER3         NC3NECTR3ESM",
            "WSMNWCTR4NC2                           NC4NECTR4ESM",
            "WSMNWXWC1   NWMTR1      NT1      NEMTR1   EC1NEXESM",
            "WSMNWXWC2   NWMTR2NWMWALNT2NEMWALNEMTR2   EC2NEXESM",
            "WSMNWXWC3   NWMTR3NW1         NE1NEMTR3   EC3NEXESM",
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
            "WSMSWXWC4   SWMTR2SW2         SE2SEMTR2   EC4SEXESM",
            "WSMSWXWC5   SWMTR3SWMWALST1SEMWALSEMTR3   EC5SEXESM",
            "WSMSWXWC6   SWMTR4      ST2      SEMTR4   EC6SEXESM",
            "WSMSWCTR1SC1                           SC3SECTR1ESM",
            "WSMSWCTR2SC2         SCATOWER1         SC4SECTR2ESM",
            "WSMSWCTR3SWCASTLEWALLSCATOWER2SECASTLEWALLSECTR3ESM",
            "WSMSWCTR4            SCATOWER3            SECTR4ESM",
            "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM",
        }),
        "components":([
            "keep":([
                "type":"keep",
                "display name": "Keep",
                "sort order": 1,
                "description": ""
            ]),
            "northwest tower": ([
                "type":"tower",
                "display name": "Northwest Tower",
                "sort order": 1,
                "description": ""
            ]),
            "northwest building": ([
                "type":"building",
                "display name": "Northwest Building",
                "sort order": 1,
                "description": ""
            ]),
            "north tower": ([
                "type":"tower",
                "display name": "North Tower",
                "sort order": 2,
                "description": ""
            ]),
            "northeast building": ([
                "type":"building",
                "display name": "Northeast Building",
                "sort order": 2,
                "description": ""
            ]),
            "northeast tower": ([
                "type":"tower",
                "display name": "Northeast Tower",
                "sort order": 3,
                "description": ""
            ]),
            "first western building": ([
                "type":"building",
                "display name": "West Building 1",
                "sort order": 3,
                "description": ""
            ]),
            "second western building": ([
                "type":"building",
                "display name": "West Building 2",
                "sort order": 4,
                "description": ""
            ]),
            "west tower": ([
                "type":"tower",
                "display name": "West Tower",
                "sort order": 4,
                "description": ""
            ]),
            "first eastern building": ([
                "type":"building",
                "display name": "East Building 1",
                "sort order": 5,
                "description": ""
            ]),
            "second eastern building": ([
                "type":"building",
                "display name": "East Building 2",
                "sort order": 6,
                "description": ""
            ]),
            "east tower": ([
                "type":"tower",
                "display name": "East Tower",
                "sort order": 5,
                "description": ""
            ]),
            "southwest tower": ([
                "type":"tower",
                "display name": "Southwest Tower",
                "sort order": 6,
                "description": ""
            ]),
            "southwest building": ([
                "type":"building",
                "display name": "Southwest Building",
                "sort order": 7,
                "description": ""
            ]),
            "south tower": ([
                "type":"tower",
                "display name": "South Tower",
                "sort order": 7,
                "description": ""
            ]),
            "southeast building": ([
                "type":"building",
                "display name": "Southeast Building",
                "sort order": 8,
                "description": ""
            ]),
            "southeast tower": ([
                "type":"tower",
                "display name": "Southeast Tower",
                "sort order": 8,
                "description": ""
            ]),
            "western north wall": ([
                "type":"wall",
                "display name": "North Inner Wall W",
                "sort order": 1,
                "description": ""
            ]),
            "eastern north wall": ([
                "type":"wall",
                "display name": "North Inner Wall E",
                "sort order": 2,
                "description": ""
            ]),
            "northern west wall": ([
                "type":"wall",
                "display name": "West Inner Wall N",
                "sort order": 3,
                "description": ""
            ]),
            "southern west wall": ([
                "type":"wall",
                "display name": "West Inner Wall S",
                "sort order": 4,
                "description": ""
            ]),
            "northern east wall": ([
                "type":"wall",
                "display name": "East Inner Wall N",
                "sort order": 5,
                "description": ""
            ]),
            "southern east wall": ([
                "type":"wall",
                "display name": "East Inner Wall S",
                "sort order": 6,
                "description": ""
            ]),
            "western south wall": ([
                "type":"wall",
                "display name": "South Inner Wall W",
                "sort order": 7,
                "description": ""
            ]),
            "eastern south wall": ([
                "type":"wall",
                "display name": "South Inner Wall E",
                "sort order": 8,
                "description": ""
            ]),
            "moat": ([
                "type":"moat",
                "display name": "Moat",
                "sort order": 1,
                "description": ""
            ]),
            "northwest castle tower": ([
                "type":"tower",
                "display name": "Outer Tower (NW)",
                "sort order": 9,
                "description": ""
            ]),
            "north castle tower": ([
                "type":"tower",
                "display name": "Outer Tower (N)",
                "sort order": 10,
                "description": ""
            ]),
            "northeast castle tower": ([
                "type":"tower",
                "display name": "Outer Tower (NE)",
                "sort order": 11,
                "description": ""
            ]),
            "west castle tower": ([
                "type":"tower",
                "display name": "Outer Tower (W)",
                "sort order": 12,
                "description": ""
            ]),
            "east castle tower": ([
                "type":"tower",
                "display name": "Outer Tower (E)",
                "sort order": 13,
                "description": ""
            ]),
            "southwest castle tower": ([
                "type":"tower",
                "display name": "Outer Tower (SW)",
                "sort order": 14,
                "description": ""
            ]),
            "south castle tower": ([
                "type":"tower",
                "display name": "Outer Tower (S)",
                "sort order": 15,
                "description": ""
            ]),
            "southeast castle tower": ([
                "type":"tower",
                "display name": "Outer Tower (SE)",
                "sort order": 16,
                "description": ""
            ]),
            "western north castle wall": ([
                "type":"wall",
                "display name": "North Outer Wall W",
                "sort order": 9,
                "description": ""
            ]),
            "eastern north castle wall": ([
                "type":"wall",
                "display name": "North Outer Wall E",
                "sort order": 10,
                "description": ""
            ]),
            "northern west castle wall": ([
                "type":"wall",
                "display name": "West Outer Wall N",
                "sort order": 11,
                "description": ""
            ]),
            "southern west castle wall": ([
                "type":"wall",
                "display name": "West Outer Wall S",
                "sort order": 12,
                "description": ""
            ]),
            "northern east castle wall": ([
                "type":"wall",
                "display name": "East Outer Wall N",
                "sort order": 13,
                "description": ""
            ]),
            "southern east castle wall": ([
                "type":"wall",
                "display name": "East Outer Wall S",
                "sort order": 14,
                "description": ""
            ]),
            "western south castle wall": ([
                "type":"wall",
                "display name": "South Outer Wall W",
                "sort order": 15,
                "description": ""
            ]),
            "eastern south castle wall": ([
                "type":"wall",
                "display name": "South Outer Wall E",
                "sort order": 16,
                "description": ""
            ]),
            "northwest castle building": ([
                "type":"building",
                "display name": "NW Castle Building",
                "sort order": 9,
                "description": ""
            ]),       
            "northeast castle building": ([
                "type":"building",
                "display name": "NE Castle Building",
                "sort order": 10,
                "description": ""
            ]),       
            "first western castle building": ([
                "type":"building",
                "display name": "W Castle Building 1",
                "sort order": 11,
                "description": ""
            ]),       
            "second western castle building": ([
                "type":"building",
                "display name": "W Castle Building 2",
                "sort order": 12,
                "description": ""
            ]),       
            "first eastern castle building": ([
                "type":"building",
                "display name": "E Castle Building 1",
                "sort order": 13,
                "description": ""
            ]),       
            "second eastern castle building": ([
                "type":"building",
                "display name": "E Castle Building 2",
                "sort order": 14,
                "description": ""
            ]),       
            "southwest castle building": ([
                "type":"building",
                "display name": "SW Castle Building",
                "sort order": 15,
                "description": ""
            ]),       
            "southeast castle building": ([
                "type":"building",
                "display name": "SE Castle Building",
                "sort order": 16,
                "description": ""
            ]),       
        ]),
    ]),
]);

#endif
