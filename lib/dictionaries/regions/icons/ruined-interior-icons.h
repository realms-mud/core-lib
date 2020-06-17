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

    // Hallways
    "ruined interior east-west hallway": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "=", "=", "=", }),
            ({ "#floor# ", "#floor# ", "#floor# ", }),
            ({ "=", "=", "=", }) }),
        "unicode": ({ ({ "\xe2\x95\x90", "\xe2\x95\x90", "\xe2\x95\x90" }),
            ({ "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91" }),
            ({ "\xe2\x95\x90", "\xe2\x95\x90", "\xe2\x95\x90" }) })
    ]),
    "ruined interior east-west hallway north entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;36m",
                    "8-bit": "\x1b[0;38;5;236m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#door#\\", "+", }),
            ({ "#floor# ", "#floor# ", "#floor# ", }),
            ({ "=", "=", "=", }) }),
        "unicode": ({ ({ "\xe2\x95\xa9", "#door#\xe2\x96\x94", "\xe2\x95\xa9" }),
            ({ "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91" }),
            ({ "\xe2\x95\x90", "\xe2\x95\x90", "\xe2\x95\x90" }) })
    ]),
    "ruined interior east-west hallway south entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;36m",
                    "8-bit": "\x1b[0;38;5;236m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "=", "=", "=", }),
            ({ "#floor# ", "#floor# ", "#floor# ", }),
            ({ "+", "#door#\\", "+", }) }),
        "unicode": ({ ({ "\xe2\x95\x90", "\xe2\x95\x90", "\xe2\x95\x90" }),
            ({ "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91" }),
            ({ "\xe2\x95\xa6", "#door#\xe2\x96\x81", "\xe2\x95\xa6" }) })
    ]),
    "ruined interior east-west hallway north-south entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;36m",
                    "8-bit": "\x1b[0;38;5;236m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#door#\\", "+", }),
            ({ "#floor# ", "#floor# ", "#floor# ", }),
            ({ "+", "#door#\\", "+", }) }),
        "unicode": ({ ({ "\xe2\x95\xa9", "#door#\xe2\x96\x94", "\xe2\x95\xa9" }),
            ({ "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91" }),
            ({ "\xe2\x95\xa6", "#door#\xe2\x96\x81", "\xe2\x95\xa6" }) })
    ]),
    "ruined interior north-south hallway": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "|", "#floor# ", "|", }),
            ({ "|", "#floor# ", "|", }),
            ({ "|", "#floor# ", "|", }) }),
        "unicode": ({ ({ "\xe2\x95\x91", "#floor#\xe2\x96\x91", "\xe2\x95\x91" }),
            ({ "\xe2\x95\x91", "#floor#\xe2\x96\x91", "\xe2\x95\x91" }),
            ({ "\xe2\x95\x91", "#floor#\xe2\x96\x91", "\xe2\x95\x91" }) })
    ]),
    "ruined interior north-south hallway east entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;36m",
                    "8-bit": "\x1b[0;38;5;236m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "|", "#floor# ", "+", }),
            ({ "|", "#floor# ", "#door#/", }),
            ({ "|", "#floor# ", "+", }) }),
        "unicode": ({ ({ "\xe2\x95\x91", "#floor#\xe2\x96\x91", "\xe2\x95\xa0" }),
            ({ "\xe2\x95\x91", "#floor#\xe2\x96\x91", "#door#\xe2\x94\x83" }),
            ({ "\xe2\x95\x91", "#floor#\xe2\x96\x91", "\xe2\x95\xa0" }) })
    ]),
    "ruined interior north-south hallway west entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;36m",
                    "8-bit": "\x1b[0;38;5;236m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#floor# ", "|", }),
            ({ "#door#/", "#floor# ", "|", }),
            ({ "+", "#floor# ", "|", }) }),
        "unicode": ({ ({ "\xe2\x95\xa3", "#floor#\xe2\x96\x91", "\xe2\x95\x91" }),
            ({ "#door#\xe2\x94\x83", "#floor#\xe2\x96\x91", "\xe2\x95\x91" }),
            ({ "\xe2\x95\xa3", "#floor#\xe2\x96\x91", "\xe2\x95\x91" }) })
    ]),
    "ruined interior north-south hallway east-west entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;36m",
                    "8-bit": "\x1b[0;38;5;236m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#floor# ", "+", }),
            ({ "#door#/", "#floor# ", "#door#/", }),
            ({ "+", "#floor# ", "+", }) }),
        "unicode": ({ ({ "\xe2\x95\xa3", "#floor#\xe2\x96\x91", "\xe2\x95\xa0" }),
            ({ "#door#\xe2\x94\x83", "#floor#\xe2\x96\x91", "#door#\xe2\x94\x83" }),
            ({ "\xe2\x95\xa3", "#floor#\xe2\x96\x91", "\xe2\x95\xa0" }) })
    ]),
    "ruined interior 4-way hallway": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "+", "#floor# ", "+", }),
            ({ "#floor# ", "#floor# ", "#floor# ", }),
            ({ "+", "#floor# ", "+", }) }),
        "unicode": ({ ({ "\xe2\x95\x9d", "#floor#\xe2\x96\x91", "\xe2\x95\x9a" }),
            ({ "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91" }),
            ({ "\xe2\x95\x97", "#floor#\xe2\x96\x91", "\xe2\x95\x94" }) })
    ]),
    "ruined interior south alcove": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "|", "#floor# ", "|", }),
            ({ "|", "#floor# ", "|", }),
            ({ "+", "=", "+", }) }),
        "unicode": ({ ({ "\xe2\x95\x91", "#floor#\xe2\x96\x91", "\xe2\x95\x91" }),
            ({ "\xe2\x95\x91", "#floor#\xe2\x96\x91", "\xe2\x95\x91" }),
            ({ "\xe2\x95\x9a", "\xe2\x95\x90", "\xe2\x95\x9d" }) })
    ]),
    "ruined interior north alcove": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "+", "+", "+", }),
            ({ "|", "#floor# ", "|", }),
            ({ "|", "#floor# ", "|", }) }),
        "unicode": ({ ({ "\xe2\x95\x94", "\xe2\x95\x90", "\xe2\x95\x97" }),
            ({ "\xe2\x95\x91", "#floor#\xe2\x96\x91", "\xe2\x95\x91" }),
            ({ "\xe2\x95\x91", "#floor#\xe2\x96\x91", "\xe2\x95\x91" }) })
    ]),
    "ruined interior east alcove": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "+", "=", "=", }),
            ({ "|", "#floor# ", "#floor# ", }),
            ({ "+", "=", "=", }) }),
        "unicode": ({ ({ "\xe2\x95\x94", "\xe2\x95\x90", "\xe2\x95\x90" }),
            ({ "\xe2\x95\x91", "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91" }),
            ({ "\xe2\x95\x9a", "\xe2\x95\x90", "\xe2\x95\x90" }) })
    ]),
    "ruined interior west alcove": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "=", "=", "+", }),
            ({ "#floor# ", "#floor# ", "|", }),
            ({ "=", "=", "+", }) }),
        "unicode": ({ ({ "\xe2\x95\x90", "\xe2\x95\x90", "\xe2\x95\x97" }),
            ({ "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", "\xe2\x95\x91" }),
            ({ "\xe2\x95\x90", "\xe2\x95\x90", "\xe2\x95\x9d" }) })
    ]),
    "ruined interior west T-intersection": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "+", "#floor# ", "|", }),
            ({ "#floor# ", "#floor# ", "|", }),
            ({ "+", "#floor# ", "|", }) }),
        "unicode": ({ ({ "\xe2\x95\x9d", "#floor#\xe2\x96\x91", "\xe2\x95\x91" }),
            ({ "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", "\xe2\x95\x91" }),
            ({ "\xe2\x95\x97", "#floor#\xe2\x96\x91", "\xe2\x95\x91" }) })
    ]),
    "ruined interior east T-intersection": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "|", "#floor# ", "+", }),
            ({ "|", "#floor# ", "#floor# ", }),
            ({ "|", "#floor# ", "+", }) }),
        "unicode": ({ ({ "\xe2\x95\x91", "#floor#\xe2\x96\x91", "\xe2\x95\x9a" }),
            ({ "\xe2\x95\x91", "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91" }),
            ({ "\xe2\x95\x91", "#floor#\xe2\x96\x91", "\xe2\x95\x94" }) })
    ]),
    "ruined interior south T-intersection": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "=", "=", "=", }),
            ({ "#floor# ", "#floor# ", "#floor# ", }),
            ({ "+", "#floor# ", "+", }) }),
        "unicode": ({ ({ "\xe2\x95\x90", "\xe2\x95\x90", "\xe2\x95\x90" }),
            ({ "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91" }),
            ({ "\xe2\x95\x97", "#floor#\xe2\x96\x91", "\xe2\x95\x94" }) })
    ]),
    "ruined interior north T-intersection": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "=", "=", "=", }),
            ({ "#floor# ", "#floor# ", "#floor# ", }),
            ({ "+", "#floor# ", "+", }) }),
        "unicode": ({ ({ "\xe2\x95\x9d", "#floor#\xe2\x96\x91", "\xe2\x95\x9a" }),
            ({ "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91" }),
            ({ "\xe2\x95\x90", "\xe2\x95\x90", "\xe2\x95\x90" }) })
    ]),
    "ruined interior north entry alcove": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;36m",
                    "8-bit": "\x1b[0;38;5;236m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#door#\\", "+", }),
            ({ "|", "#floor# ", "|", }),
            ({ "|", "#floor# ", "|", }) }),
        "unicode": ({ ({ "\xe2\x95\xac", "#door#\xe2\x96\x94", "\xe2\x95\xac" }),
            ({ "\xe2\x95\x91", "#floor#\xe2\x96\x91", "\xe2\x95\x91" }),
            ({ "\xe2\x95\x91", "#floor#\xe2\x96\x91", "\xe2\x95\x91" }) })
    ]),
    "ruined interior north-east entry alcove": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;36m",
                    "8-bit": "\x1b[0;38;5;236m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#door#\\", "+", }),
            ({ "|", "#floor# ", "#door#/", }),
            ({ "|", "#floor# ", "|", }) }),
        "unicode": ({ ({ "\xe2\x95\xac", "#door#\xe2\x96\x94", "\xe2\x95\xac" }),
            ({ "\xe2\x95\x91", "#floor#\xe2\x96\x91", "#door#\xe2\x94\x83" }),
            ({ "\xe2\x95\x91", "#floor#\xe2\x96\x91", "\xe2\x95\xa0" }) })
    ]),
    "ruined interior north-west entry alcove": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;36m",
                    "8-bit": "\x1b[0;38;5;236m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#door#\\", "+", }),
            ({ "|", "#floor# ", "#door#/", }),
            ({ "|", "#floor# ", "|", }) }),
        "unicode": ({ ({ "\xe2\x95\xac", "#door#\xe2\x96\x94", "\xe2\x95\xac" }),
            ({ "#door#\xe2\x94\x83", "#floor#\xe2\x96\x91", "\xe2\x95\x91" }),
            ({ "\xe2\x95\xa3", "#floor#\xe2\x96\x91", "\xe2\x95\x91" }) })
    ]),
    "ruined interior north-east-west entry alcove": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;36m",
                    "8-bit": "\x1b[0;38;5;236m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#door#\\", "+", }),
            ({ "|", "#floor# ", "#door#/", }),
            ({ "|", "#floor# ", "|", }) }),
        "unicode": ({ ({ "\xe2\x95\xac", "#door#\xe2\x96\x94", "\xe2\x95\xac" }),
            ({ "#door#\xe2\x94\x83", "#floor#\xe2\x96\x91", "#door#\xe2\x94\x83" }),
            ({ "\xe2\x95\xa3", "#floor#\xe2\x96\x91", "\xe2\x95\xa0" }) })
    ]),
    "ruined interior south entry alcove": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;36m",
                    "8-bit": "\x1b[0;38;5;236m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "|", "#floor# ", "|", }),
            ({ "|", "#floor# ", "|", }),
            ({ "+", "#door#/", "+", }), }),
        "unicode": ({ ({ "\xe2\x95\x91", "#floor#\xe2\x96\x91", "\xe2\x95\x91" }),
            ({ "\xe2\x95\x91", "#floor#\xe2\x96\x91", "\xe2\x95\x91" }),
            ({ "\xe2\x95\xac", "#door#\xe2\x96\x81", "\xe2\x95\xac" }), })
    ]),
    "ruined interior south-east entry alcove": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;36m",
                    "8-bit": "\x1b[0;38;5;236m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "|", "#floor# ", "|", }),
            ({ "|", "#floor# ", "#door#/", }),
            ({ "+", "#door#/", "+", }), }),
        "unicode": ({ ({ "\xe2\x95\x91", "#floor#\xe2\x96\x91", "\xe2\x95\xa0" }),
            ({ "\xe2\x95\x91", "#floor#\xe2\x96\x91", "#door#\xe2\x94\x83" }),
            ({ "\xe2\x95\xac", "#door#\xe2\x96\x81", "\xe2\x95\xac" }), })
    ]),
    "ruined interior south-west entry alcove": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;36m",
                    "8-bit": "\x1b[0;38;5;236m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "|", "#floor# ", "|", }),
            ({ "#door#/", "#floor# ", "|", }),
            ({ "+", "#door#/", "+", }), }),
        "unicode": ({ ({ "\xe2\x95\xa3", "#floor#\xe2\x96\x91", "\xe2\x95\x91" }),
            ({ "#door#\xe2\x94\x83", "#floor#\xe2\x96\x91", "\xe2\x95\x91" }),
            ({ "\xe2\x95\xac", "#door#\xe2\x96\x81", "\xe2\x95\xac" }), })
    ]),
    "ruined interior south-east-west entry alcove": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;36m",
                    "8-bit": "\x1b[0;38;5;236m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "|", "#floor# ", "|", }),
            ({ "#door#/", "#floor# ", "#door#/", }),
            ({ "+", "#door#/", "+", }), }),
        "unicode": ({ ({ "\xe2\x95\xa3", "#floor#\xe2\x96\x91", "\xe2\x95\xa0" }),
            ({ "#door#\xe2\x94\x83", "#floor#\xe2\x96\x91", "#door#\xe2\x94\x83" }),
            ({ "\xe2\x95\xac", "#door#\xe2\x96\x81", "\xe2\x95\xac" }), })
    ]),
    "ruined interior east entry alcove": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;36m",
                    "8-bit": "\x1b[0;38;5;236m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "=", "=", }),
            ({ "#door#/", "#floor# ", "#floor# ", }),
            ({ "+", "=", "=", }) }),
        "unicode": ({ ({ "\xe2\x95\xac", "\xe2\x95\x90", "\xe2\x95\x90" }),
            ({ "#door#\xe2\x94\x83", "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91" }),
            ({ "\xe2\x95\xac", "\xe2\x95\x90", "\xe2\x95\x90" }) })
    ]),
    "ruined interior east-north entry alcove": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;36m",
                    "8-bit": "\x1b[0;38;5;236m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#door#\\", "=", }),
            ({ "#floor# ", "#floor# ", "#door#/", }),
            ({ "+", "=", "=", }) }),
        "unicode": ({ ({ "\xe2\x95\xac", "#door#\xe2\x96\x94", "\xe2\x95\xa9" }),
            ({ "#door#\xe2\x94\x83", "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", }),
            ({ "\xe2\x95\xac", "\xe2\x95\x90", "\xe2\x95\x90" }) })
    ]),
    "ruined interior east-south entry alcove": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;36m",
                    "8-bit": "\x1b[0;38;5;236m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "=", "=", }),
            ({ "#floor# ", "#floor# ", "#door#/", }),
            ({ "+", "#door#\\", "=", }) }),
        "unicode": ({ ({ "\xe2\x95\xac", "\xe2\x95\x90", "\xe2\x95\x90" }),
            ({ "#door#\xe2\x94\x83", "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91" }),
            ({ "\xe2\x95\xac", "#door#\xe2\x96\x81", "\xe2\x95\xa6" }) })
    ]),
    "ruined interior east-south-north entry alcove": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;36m",
                    "8-bit": "\x1b[0;38;5;236m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#door#\\", "=", }),
            ({ "#floor# ", "#floor# ", "#door#/", }),
            ({ "+", "#door#\\", "=", }) }),
        "unicode": ({ ({ "\xe2\x95\xac", "#door#\xe2\x96\x94", "\xe2\x95\xa9" }),
            ({ "#door#\xe2\x94\x83", "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91" }),
            ({ "\xe2\x95\xac", "#door#\xe2\x96\x81", "\xe2\x95\xa6" }) })
    ]),
    "ruined interior west entry alcove": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;36m",
                    "8-bit": "\x1b[0;38;5;236m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "=", "=", }),
            ({ "#floor# ", "#floor# ", "#door#/", }),
            ({ "+", "=", "=", }) }),
        "unicode": ({ ({ "\xe2\x95\x90", "\xe2\x95\x90", "\xe2\x95\xac", }),
            ({ "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", "#door#\xe2\x94\x83", }),
            ({ "\xe2\x95\x90", "\xe2\x95\x90","\xe2\x95\xac", }) })
    ]),
    "ruined interior west-south entry alcove": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;36m",
                    "8-bit": "\x1b[0;38;5;236m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "=", "=", }),
            ({ "#floor# ", "#floor# ", "#door#/", }),
            ({ "+", "#door#\\", "=", }) }),
        "unicode": ({ ({ "\xe2\x95\x90", "\xe2\x95\x90", "\xe2\x95\xac", }),
            ({ "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", "#door#\xe2\x94\x83", }),
            ({ "\xe2\x95\xa6", "#door#\xe2\x96\x81","\xe2\x95\xac", }) })
    ]),
    "ruined interior west-north entry alcove": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;36m",
                    "8-bit": "\x1b[0;38;5;236m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#door\\", "=", }),
            ({ "#floor# ", "#floor# ", "#door#/", }),
            ({ "+", "=", "=", }) }),
        "unicode": ({ ({ "\xe2\x95\xa9", "#door#\xe2\x96\x94", "\xe2\x95\xac", }),
            ({ "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", "#door#\xe2\x94\x83", }),
            ({ "\xe2\x95\x90", "\xe2\x95\x90", "\xe2\x95\xac", }) })
    ]),
    "ruined interior west-south-north entry alcove": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;36m",
                    "8-bit": "\x1b[0;38;5;236m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "=", "=", }),
            ({ "#floor# ", "#floor# ", "#door#/", }),
            ({ "+", "#door#\\", "=", }) }),
        "unicode": ({ ({ "\xe2\x95\xa9", "#door#\xe2\x96\x94", "\xe2\x95\xac", }),
            ({ "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", "#door#\xe2\x94\x83", }),
            ({ "\xe2\x95\xa6", "#door#\xe2\x96\x81","\xe2\x95\xac", }) })
    ]),
    "ruined interior north-west corner hallway": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "+", "#floor# ", "|", }),
            ({ "#floor# ", "#floor# ", "|", }),
            ({ "-", "-", "+", }) }),
        "unicode": ({ ({ "\xe2\x95\x9d", "#floor#\xe2\x96\x91", "\xe2\x95\x91" }),
            ({ "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", "\xe2\x95\x91" }),
            ({ "\xe2\x95\x90", "\xe2\x95\x90", "\xe2\x95\x9d" }) })
    ]),
    "ruined interior north-west corner hallway south entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;36m",
                    "8-bit": "\x1b[0;38;5;236m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#floor# ", "|", }),
            ({ "#floor# ", "#floor# ", "|", }),
            ({ "-", "#door#/", "+", }) }),
        "unicode": ({ ({ "\xe2\x95\x9d", "#floor#\xe2\x96\x91", "\xe2\x95\x91" }),
            ({ "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", "\xe2\x95\x91" }),
            ({ "\xe2\x95\x97", "#door#\xe2\x96\x81", "\xe2\x95\xa3" }) })
    ]),
    "ruined interior north-west corner hallway east entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;36m",
                    "8-bit": "\x1b[0;38;5;236m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#floor# ", "|", }),
            ({ "#floor# ", "#floor# ", "#door#/", }),
            ({ "-", "-", "+", }) }),
        "unicode": ({ ({ "\xe2\x95\x9d", "#floor#\xe2\x96\x91", "\xe2\x95\xa0" }),
            ({ "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", "#door#\xe2\x94\x83" }),
            ({ "\xe2\x95\x90", "\xe2\x95\x90", "\xe2\x95\xa9" }) })
    ]),
    "ruined interior north-west corner hallway south-east entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;36m",
                    "8-bit": "\x1b[0;38;5;236m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#floor# ", "|", }),
            ({ "#floor# ", "#floor# ", "#door#/", }),
            ({ "-", "#door#/", "+", }) }),
        "unicode": ({ ({ "\xe2\x95\x9d", "#floor#\xe2\x96\x91", "\xe2\x95\xa0" }),
            ({ "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", "#door#\xe2\x94\x83" }),
            ({ "\xe2\x95\x97", "#door#\xe2\x96\x81", "\xe2\x95\xac" }) })
    ]),
    "ruined interior south-west corner hallway": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "-", "-", "+", }),
            ({ "#floor# ", "#floor# ", "|", }),
            ({ "+", "#floor# ", "|", }) }),
        "unicode": ({ ({ "\xe2\x95\x90", "\xe2\x95\x90", "\xe2\x95\x97" }),
            ({ "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", "\xe2\x95\x91" }),
            ({ "\xe2\x95\x97", "#floor#\xe2\x96\x91", "\xe2\x95\x91" }) })
    ]),
    "ruined interior south-west corner hallway north entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;36m",
                    "8-bit": "\x1b[0;38;5;236m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#door#/", "+", }),
            ({ "#floor# ", "#floor# ", "|", }),
            ({ "+", "#floor# ", "+", }) }),
        "unicode": ({ ({ "\xe2\x95\xa9", "#door#\xe2\x96\x94","\xe2\x95\xa3" }),
            ({ "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", "\xe2\x95\x91" }),
            ({ "\xe2\x95\x97", "#floor#\xe2\x96\x91", "\xe2\x95\x91" }) })
    ]),
    "ruined interior south-west corner hallway east entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;36m",
                    "8-bit": "\x1b[0;38;5;236m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "-", "-", "+" }),
            ({ "#floor# ", "#floor# ", "#door#/", }),
            ({ "+", "#floor# ", "|", }) }),
        "unicode": ({ ({ "\xe2\x95\x90", "\xe2\x95\x90","\xe2\x95\xa6" }),
            ({ "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", "#door#\xe2\x94\x83" }),
            ({ "\xe2\x95\x97", "#floor#\xe2\x96\x91", "\xe2\x95\xa0" }) })
    ]),
    "ruined interior south-west corner hallway north-east entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;36m",
                    "8-bit": "\x1b[0;38;5;236m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#door#/", "+", }),
            ({ "#floor# ", "#floor# ", "#door#/", }),
            ({ "+", "#floor# ", "+", }) }),
        "unicode": ({ ({ "\xe2\x95\xa9", "#door#\xe2\x96\x94","\xe2\x95\xac" }),
            ({ "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", "#door#\xe2\x94\x83" }),
            ({ "\xe2\x95\x97", "#floor#\xe2\x96\x91", "\xe2\x95\xa0" }) })
    ]),
    "ruined interior north-east corner hallway": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "|", "#floor# ", "+", }),
            ({ "|", "#floor# ", "#floor# ", }),
            ({ "-", "-", "+", }) }),
        "unicode": ({ ({ "\xe2\x95\x91", "#floor#\xe2\x96\x91", "\xe2\x95\x9a" }),
            ({ "\xe2\x95\x91", "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", }),
            ({ "\xe2\x95\x9a", "\xe2\x95\x90", "\xe2\x95\x90" }) })
    ]),
    "ruined interior north-east corner hallway west entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;36m",
                    "8-bit": "\x1b[0;38;5;236m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#floor# ", "+", }),
            ({ "#door#\\", "#floor# ", "#floor# ", }),
            ({ "-", "-", "+", }) }),
        "unicode": ({ ({ "\xe2\x95\xa3", "#floor#\xe2\x96\x91", "\xe2\x95\x9a" }),
            ({ "#door#\xe2\x94\x83", "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", }),
            ({ "\xe2\x95\xa9", "\xe2\x95\x90", "\xe2\x95\x90" }) })
    ]),
    "ruined interior north-east corner hallway south entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;36m",
                    "8-bit": "\x1b[0;38;5;236m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "|", "#floor# ", "+", }),
            ({ "|", "#floor# ", "#floor# ", }),
            ({ "-", "#door#/", "+", }) }),
        "unicode": ({ ({ "\xe2\x95\x91", "#floor#\xe2\x96\x91", "\xe2\x95\x9a" }),
            ({ "\xe2\x95\x91", "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", }),
            ({ "\xe2\x95\xa0", "#door#\xe2\x96\x81", "\xe2\x95\xa6" }) })
    ]),
    "ruined interior north-east corner hallway south-west entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;36m",
                    "8-bit": "\x1b[0;38;5;236m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#floor# ", "+", }),
            ({ "#door#\\", "#floor# ", "#floor# ", }),
            ({ "+", "#door#/", "+", }) }),
        "unicode": ({ ({ "\xe2\x95\xa3", "#floor#\xe2\x96\x91", "\xe2\x95\x9a" }),
            ({ "#door#\xe2\x94\x83", "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", }),
            ({ "\xe2\x95\xac", "#door#\xe2\x96\x81", "\xe2\x95\xa6" }) })
    ]),
    "ruined interior south-east corner hallway": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "+", "-", "-", }),
            ({ "|", "#floor# ", "#floor# ", }),
            ({ "|", "#floor# ", "+", }) }),
        "unicode": ({ ({ "\xe2\x95\x94", "\xe2\x95\x90", "\xe2\x95\x90" }),
            ({ "\xe2\x95\x91", "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91" }),
            ({ "\xe2\x95\x91", "#floor#\xe2\x96\x91", "\xe2\x95\x94" }) })
    ]),
    "ruined interior south-east corner hallway west entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;36m",
                    "8-bit": "\x1b[0;38;5;236m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "-", "-", }),
            ({ "#door#\\", "#floor# ", "#floor# ", }),
            ({ "+", "#floor# ", "+", }) }),
        "unicode": ({ ({ "\xe2\x95\xa6", "\xe2\x95\x90", "\xe2\x95\x90" }),
            ({ "#door#\xe2\x94\x83", "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", }),
            ({ "\xe2\x95\xa3", "#floor#\xe2\x96\x91", "\xe2\x95\x94" }) })
    ]),
    "ruined interior south-east corner hallway north entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;36m",
                    "8-bit": "\x1b[0;38;5;236m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#door#\\", "+", }),
            ({ "|", "#floor# ", "#floor# ", }),
            ({ "|", "#floor# ", "+", }) }),
        "unicode": ({ ({ "\xe2\x95\xa0", "#door#\xe2\x96\x94","\xe2\x95\xa9" }),
            ({ "\xe2\x95\x91", "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91" }),
            ({ "\xe2\x95\x91", "#floor#\xe2\x96\x91", "\xe2\x95\x94" }) })
    ]),
    "ruined interior south-east corner hallway north-west entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;36m",
                    "8-bit": "\x1b[0;38;5;236m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#door#\\", "+", }),
            ({ "#door#\\", "#floor# ", "#floor# ", }),
            ({ "+", "#floor# ", "+", }) }),
        "unicode": ({ ({ "\xe2\x95\xac", "#door#\xe2\x96\x94", "\xe2\x95\xa9" }),
            ({ "#door#\xe2\x94\x83", "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", }),
            ({ "\xe2\x95\xa3", "#floor#\xe2\x96\x91", "\xe2\x95\x94" }) })
    ]),

    // Large Rooms
    "ruined interior southeast corner": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "#floor# ", "#floor# ", "|", }),
            ({ "#floor# ", "#floor# ", "|", }),
            ({ "-", "-", "+", }) }),
        "unicode": ({ ({ "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", "\xe2\x95\x91" }),
            ({ "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", "\xe2\x95\x91" }),
            ({ "\xe2\x95\x90", "\xe2\x95\x90", "\xe2\x95\x9d" }) })
    ]),
    "ruined interior southeast corner south entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;36m",
                    "8-bit": "\x1b[0;38;5;236m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "#floor# ", "#floor# ", "|", }),
            ({ "#floor# ", "#floor# ", "|", }),
            ({ "-", "#door#/", "+", }) }),
        "unicode": ({ ({ "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", "\xe2\x95\x91" }),
            ({ "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", "\xe2\x95\x91" }),
            ({ "\xe2\x95\x97", "#door#\xe2\x96\x81", "\xe2\x95\xa3" }) })
    ]),
    "ruined interior southeast corner east entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;36m",
                    "8-bit": "\x1b[0;38;5;236m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "#floor# ", "#floor# ", "|", }),
            ({ "#floor# ", "#floor# ", "#door#/", }),
            ({ "-", "-", "+", }) }),
        "unicode": ({ ({ "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", "\xe2\x95\xa0" }),
            ({ "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", "#door#\xe2\x94\x83" }),
            ({ "\xe2\x95\x90", "\xe2\x95\x90", "\xe2\x95\xa9" }) })
    ]),
    "ruined interior southeast corner south-east entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;36m",
                    "8-bit": "\x1b[0;38;5;236m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "#floor# ", "#floor# ", "|", }),
            ({ "#floor# ", "#floor# ", "#door#/", }),
            ({ "-", "#door#/", "+", }) }),
        "unicode": ({ ({ "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", "\xe2\x95\xa0" }),
            ({ "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", "#door#\xe2\x94\x83" }),
            ({ "\xe2\x95\x97", "#door#\xe2\x96\x81", "\xe2\x95\xac" }) })
    ]),
    "ruined interior northeast corner": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "-", "-", "+", }),
            ({ "#floor# ", "#floor# ", "|", }),
            ({ "#floor# ", "#floor# ", "|", }) }),
        "unicode": ({ ({ "\xe2\x95\x90", "\xe2\x95\x90", "\xe2\x95\x97" }),
            ({ "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", "\xe2\x95\x91" }),
            ({ "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", "\xe2\x95\x91" }) })
    ]),
    "ruined interior northeast corner north entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;36m",
                    "8-bit": "\x1b[0;38;5;236m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#door#/", "+", }),
            ({ "#floor# ", "#floor# ", "|", }),
            ({ "#floor# ", "#floor# ", "+", }) }),
        "unicode": ({ ({ "\xe2\x95\xa9", "#door#\xe2\x96\x94","\xe2\x95\xa3" }),
            ({ "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", "\xe2\x95\x91" }),
            ({ "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", "\xe2\x95\x91" }) })
    ]),
    "ruined interior northeast corner east entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;36m",
                    "8-bit": "\x1b[0;38;5;236m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "-", "-", "+", }),
            ({ "#floor# ", "#floor# ", "#door#/", }),
            ({ "#floor# ", "#floor# ", "|", }) }),
        "unicode": ({ ({ "\xe2\x95\x90", "\xe2\x95\x90","\xe2\x95\xa6" }),
            ({ "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", "#door#\xe2\x94\x83" }),
            ({ "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", "\xe2\x95\xa0" }) })
    ]),
    "ruined interior northeast corner north-east entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;36m",
                    "8-bit": "\x1b[0;38;5;236m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#door#/", "+", }),
            ({ "#floor# ", "#floor# ", "#door#/", }),
            ({ "#floor# ", "#floor# ", "+", }) }),
        "unicode": ({ ({ "\xe2\x95\xa9", "#door#\xe2\x96\x94","\xe2\x95\xac" }),
            ({ "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", "#door#\xe2\x94\x83" }),
            ({ "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", "\xe2\x95\xa0" }) })
    ]),
    "ruined interior southwest corner": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "|", "#floor# ", "#floor# ", }),
            ({ "|", "#floor# ", "#floor# ", }),
            ({ "-", "-", "+", }) }),
        "unicode": ({ ({ "\xe2\x95\x91", "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91" }),
            ({ "\xe2\x95\x91", "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", }),
            ({ "\xe2\x95\x9a", "\xe2\x95\x90", "\xe2\x95\x90" }) })
    ]),
    "ruined interior southwest corner west entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;36m",
                    "8-bit": "\x1b[0;38;5;236m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#floor# ", "#floor# ", }),
            ({ "#door#\\", "#floor# ", "#floor# ", }),
            ({ "-", "-", "+", }) }),
        "unicode": ({ ({ "\xe2\x95\xa3", "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91" }),
            ({ "#door#\xe2\x94\x83", "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", }),
            ({ "\xe2\x95\xa9", "\xe2\x95\x90", "\xe2\x95\x90" }) })
    ]),
    "ruined interior southwest corner south entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;36m",
                    "8-bit": "\x1b[0;38;5;236m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "|", "#floor# ", "#floor# ", }),
            ({ "|", "#floor# ", "#floor# ", }),
            ({ "-", "#door#/", "+", }) }),
        "unicode": ({ ({ "\xe2\x95\x91", "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91" }),
            ({ "\xe2\x95\x91", "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", }),
            ({ "\xe2\x95\xa0", "#door#\xe2\x96\x81", "\xe2\x95\xa6" }) })
    ]),
    "ruined interior southwest corner south-west entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;36m",
                    "8-bit": "\x1b[0;38;5;236m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#floor# ", "#floor# ", }),
            ({ "#door#\\", "#floor# ", "#floor# ", }),
            ({ "+", "#door#/", "+", }) }),
        "unicode": ({ ({ "\xe2\x95\xa3", "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91" }),
            ({ "#door#\xe2\x94\x83", "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", }),
            ({ "\xe2\x95\xac", "#door#\xe2\x96\x81", "\xe2\x95\xa6" }) })
    ]),
    "ruined interior northwest corner": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "+", "-", "-", }),
            ({ "|", "#floor# ", "#floor# ", }),
            ({ "|", "#floor# ", "#floor# ", }) }),
        "unicode": ({ ({ "\xe2\x95\x94", "\xe2\x95\x90", "\xe2\x95\x90" }),
            ({ "\xe2\x95\x91", "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91" }),
            ({ "\xe2\x95\x91", "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91" }) })
    ]),
    "ruined interior northwest corner west entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;36m",
                    "8-bit": "\x1b[0;38;5;236m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "-", "-", }),
            ({ "#door#\\", "#floor# ", "#floor# ", }),
            ({ "+", "#floor# ", "#floor# ", }) }),
        "unicode": ({ ({ "\xe2\x95\xa6", "\xe2\x95\x90", "\xe2\x95\x90" }),
            ({ "#door#\xe2\x94\x83", "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", }),
            ({ "\xe2\x95\xa3", "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91" }) })
    ]),
    "ruined interior northwest corner north entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;36m",
                    "8-bit": "\x1b[0;38;5;236m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#door#\\", "+", }),
            ({ "|", "#floor# ", "#floor# ", }),
            ({ "|", "#floor# ", "#floor# ", }) }),
        "unicode": ({ ({ "\xe2\x95\xa0", "#door#\xe2\x96\x94","\xe2\x95\xa9" }),
            ({ "\xe2\x95\x91", "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91" }),
            ({ "\xe2\x95\x91", "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91" }) })
    ]),
    "ruined interior northwest corner north-west entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;36m",
                    "8-bit": "\x1b[0;38;5;236m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#door#\\", "+", }),
            ({ "#door#\\", "#floor# ", "#floor# ", }),
            ({ "+", "#floor# ", "#floor# ", }) }),
        "unicode": ({ ({ "\xe2\x95\xac", "#door#\xe2\x96\x94", "\xe2\x95\xa9" }),
            ({ "#door#\xe2\x94\x83", "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", }),
            ({ "\xe2\x95\xa3", "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91" }) })
    ]),
    "ruined interior west wall": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "|", "#floor# ", "#floor# ", }),
            ({ "|", "#floor# ", "#floor# ", }),
            ({ "|", "#floor# ", "#floor# ", }) }),
        "unicode": ({ ({ "\xe2\x95\x91", "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91" }),
            ({ "\xe2\x95\x91", "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91" }),
            ({ "\xe2\x95\x91", "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91" }) })
    ]),
    "ruined interior west wall entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;36m",
                    "8-bit": "\x1b[0;38;5;236m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#floor# ", "#floor# " }),
            ({ "#door#/", "#floor# ", "#floor# " }),
            ({ "+", "#floor# ", "#floor# " }) }),
        "unicode": ({ ({ "\xe2\x95\xa3", "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91" }),
            ({ "#door#\xe2\x94\x83", "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91" }),
            ({ "\xe2\x95\xa3", "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91" }) })
    ]),
    "ruined interior east wall": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "#floor# ", "#floor# ", "|" }),
            ({ "#floor# ", "#floor# ", "|" }),
            ({ "#floor# ", "#floor# ", "|" }) }),
        "unicode": ({ ({ "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", "\xe2\x95\x91" }),
            ({ "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", "\xe2\x95\x91" }),
            ({ "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", "\xe2\x95\x91" }) })
    ]),
    "ruined interior east wall entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;36m",
                    "8-bit": "\x1b[0;38;5;236m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "#floor# ", "#floor# ", "+", }),
            ({ "#floor# ", "#floor# ", "#door#/", }),
            ({ "#floor# ", "#floor# ", "+", }) }),
        "unicode": ({ ({ "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", "\xe2\x95\xa0" }),
            ({ "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", "#door#\xe2\x94\x83" }),
            ({ "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", "\xe2\x95\xa0" }) })
    ]),
    "ruined interior north wall": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "=", "=", "=", }),
            ({ "#floor# ", "#floor# ", "#floor# ", }),
            ({ "#floor# ", "#floor# ", "#floor# ", }) }),
        "unicode": ({ ({ "\xe2\x95\x90", "\xe2\x95\x90", "\xe2\x95\x90" }),
            ({ "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91" }),
            ({ "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91" }) })
    ]),
    "ruined interior north wall entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;36m",
                    "8-bit": "\x1b[0;38;5;236m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#door#\\", "+", }),
            ({ "#floor# ", "#floor# ", "#floor# ", }),
            ({ "#floor# ", "#floor# ", "#floor# ", }) }),
        "unicode": ({ ({ "\xe2\x95\xa9", "#door#\xe2\x96\x94", "\xe2\x95\xa9" }),
            ({ "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91" }),
            ({ "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91" }) })
    ]),
    "ruined interior south wall": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "#floor# ", "#floor# ", "#floor# ", }),
            ({ "#floor# ", "#floor# ", "#floor# ", }),
            ({ "=", "=", "=", }) }),
        "unicode": ({ ({ "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91" }),
            ({ "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91" }),
            ({ "\xe2\x95\x90", "\xe2\x95\x90", "\xe2\x95\x90" }) })
    ]),
    "ruined interior south wall entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;36m",
                    "8-bit": "\x1b[0;38;5;236m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "#floor# ", "#floor# ", "#floor# ", }),
            ({ "#floor# ", "#floor# ", "#floor# ", }),
            ({ "+", "#door#\\", "+", }) }),
        "unicode": ({ ({ "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91" }),
            ({ "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91" }),
            ({ "\xe2\x95\xa6", "#door#\xe2\x96\x81", "\xe2\x95\xa6" }) })
    ]),
    "ruined interior-to-exterior north-south hallway west exit": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "|", "#floor# ", "|", }),
            ({ "|", "#floor# ", "#floor# ", }),
            ({ "|", "#floor# ", "|", }) }),
        "unicode": ({ ({ "\xe2\x95\x91", "#floor#\xe2\x96\x91", "\xe2\x95\xa8" }),
            ({ "\xe2\x95\x91", "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91" }),
            ({ "\xe2\x95\x91", "#floor#\xe2\x96\x91", "\xe2\x95\xa5" }) })
    ]),
    "ruined interior-to-exterior north-corner hallway west exit": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "+", "=", "=", }),
            ({ "|", "#floor# ", "#floor# ", }),
            ({ "|", "#floor# ", "|", }) }),
        "unicode": ({ ({ "\xe2\x95\x94", "\xe2\x95\x90", "\xe2\x95\xa6" }),
            ({ "\xe2\x95\x91", "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91" }),
            ({ "\xe2\x95\x91", "#floor#\xe2\x96\x91", "\xe2\x95\xa5" }) })
    ]),

]);

#endif
