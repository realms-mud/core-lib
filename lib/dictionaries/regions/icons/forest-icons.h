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
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;245m",
            "24-bit": "\x1b[0;38;2;138;138;138m"
        ]),
        "ascii": ({ ({ "|", " ", " ", }), 
            ({ "|", " ", " ", }), 
            ({ "+", "=", "+", }) }),
        "unicode" : ({ ({ "\xe2\x95\x94", "\xe2\x95\x90", "\xe2\x95\xa9" }),
            ({ "\xe2\x95\x91", "\xe2\x96\x91", "\xe2\x96\x91" }),
            ({ "\xe2\x95\x9a", "\xe2\x95\x90", "\xe2\x95\xa6" }) })
    ]),
]);

#endif
