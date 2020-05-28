//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef ruinedInteriorIcons_h
#define ruinedInteriorIcons_h

private mapping RuinedInteriorIcons = ([
    "ruined interior south gatehouse": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "pillar":([
                    "none": "",
                    "3-bit": "\x1b[0;36;1m",
                    "8-bit": "\x1b[0;38;5;243;1m",
                    "24-bit": "\x1b[0;38;2;118;118;128;1m",
                ]),
                "portcullis":([
                    "none": "",
                    "3-bit": "\x1b[0;31;1m",
                    "8-bit": "\x1b[0;38;5;238m",
                    "24-bit": "\x1b[0;38;2;72;38;38m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;36m",
                    "8-bit": "\x1b[0;38;5;236m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "#pillar#+", " ", "#pillar#+", }),
            ({ "+", "#portcullis#-", "+", }),
            ({ "+", "#door#-", "+", }) }),
        "unicode": ({ ({ "#pillar#\xe2\x97\x8e", " ", "#pillar#\xe2\x97\x8e" }),
            ({ "\xe2\x95\x94", "#portcullis#\xe2\x95\x8c", "\xe2\x95\x97" }),
            ({ "\xe2\x95\xac", "#door#\xe2\x96\x81", "\xe2\x95\xac" }) })
    ]),
]);

#endif
