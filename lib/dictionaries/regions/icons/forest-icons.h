//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef forestIcons_h
#define forestIcons_h

private mapping ForestIcons = ([ 
    "deciduous forest 1": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;245m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;245m",
            "24-bit": "\x1b[0;38;2;138;138;138m"
        ]),
        "ascii": ({ ({ "|", " ", " ", }), 
            ({ "|", " ", " ", }), 
            ({ "+", "=", "+", }) }),
        "unicode" : ({ ({ "\u2554", "\u2550", "\u2569" }),
            ({ "\u2551", "\u2591", "\u2591" }),
            ({ "\u255a", "\u2550", "\u2566" }) })
    ]),
]);

#endif
