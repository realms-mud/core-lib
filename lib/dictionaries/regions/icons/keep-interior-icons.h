//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef keepInteriorIcons_h
#define keepInteriorIcons_h

private mapping KeepInteriorIcons = ([
    // Hallways
    "keep interior east-west hallway": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
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
    "keep interior east-west hallway north entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
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
    "keep interior east-west hallway south entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
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
    "keep interior east-west hallway north-south entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
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
    "keep interior north-south hallway": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
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
    "keep interior north-south hallway east entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
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
    "keep interior north-south hallway west entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
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
    "keep interior north-south hallway east-west entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
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
    "keep interior 4-way hallway": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
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
    "keep interior south alcove": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
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
    "keep interior north alcove": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "+", "=", "+", }),
            ({ "|", "#floor# ", "|", }),
            ({ "|", "#floor# ", "|", }) }),
        "unicode": ({ ({ "\xe2\x95\x94", "\xe2\x95\x90", "\xe2\x95\x97" }),
            ({ "\xe2\x95\x91", "#floor#\xe2\x96\x91", "\xe2\x95\x91" }),
            ({ "\xe2\x95\x91", "#floor#\xe2\x96\x91", "\xe2\x95\x91" }) })
    ]),
    "keep interior west alcove": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
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
    "keep interior east alcove": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
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
    "keep interior west T-intersection": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
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
    "keep interior west T-intersection east entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#floor# ", "+", }),
            ({ "#floor# ", "#floor# ", "#floor# ", }),
            ({ "+", "#floor# ", "+", }) }),
        "unicode": ({ ({ "\xe2\x95\x9d", "#floor#\xe2\x96\x91", "\xe2\x95\x9a" }),
            ({ "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91" }),
            ({ "\xe2\x95\x97", "#floor#\xe2\x96\x91", "\xe2\x95\x94" }) })
    ]),
    "keep interior east T-intersection": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
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
    "keep interior east T-intersection west entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#floor# ", "+", }),
            ({ "#floor# ", "#floor# ", "#floor# ", }),
            ({ "+", "#floor# ", "+", }) }),
        "unicode": ({ ({ "\xe2\x95\x9d", "#floor#\xe2\x96\x91", "\xe2\x95\x9a" }),
            ({ "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91" }),
            ({ "\xe2\x95\x97", "#floor#\xe2\x96\x91", "\xe2\x95\x94" }) })
    ]),
    "keep interior south T-intersection": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
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
    "keep interior south T-intersection north entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#door#/", "+", }),
            ({ "#floor# ", "#floor# ", "#floor# ", }),
            ({ "+", "#floor# ", "+", }) }),
        "unicode": ({ ({ "\xe2\x95\x9d", "#door#\xe2\x96\x94", "\xe2\x95\x9a" }),
            ({ "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91" }),
            ({ "\xe2\x95\x97", "#floor#\xe2\x96\x91", "\xe2\x95\x94" }) })
    ]),
    "keep interior north T-intersection": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
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
            ({ "=", "=", "=", }) }),
        "unicode": ({ ({ "\xe2\x95\x9d", "#floor#\xe2\x96\x91", "\xe2\x95\x9a" }),
            ({ "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91" }),
            ({ "\xe2\x95\x90", "\xe2\x95\x90", "\xe2\x95\x90" }) })
    ]),
    "keep interior north T-intersection south entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#floor# ", "+", }),
            ({ "#floor# ", "#floor# ", "#floor# ", }),
            ({ "+", "#floor# ", "+", }) }),
        "unicode": ({ ({ "\xe2\x95\x9d", "#floor#\xe2\x96\x91", "\xe2\x95\x9a" }),
            ({ "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91" }),
            ({ "\xe2\x95\x97", "#floor#\xe2\x96\x91", "\xe2\x95\x94" }) })
    ]),
    "keep interior north entry alcove": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
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
    "keep interior north-east entry alcove": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
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
    "keep interior north-west entry alcove": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#door#\\", "+", }),
            ({ "#door#/", "#floor# ", "|", }),
            ({ "|", "#floor# ", "|", }) }),
        "unicode": ({ ({ "\xe2\x95\xac", "#door#\xe2\x96\x94", "\xe2\x95\xac" }),
            ({ "#door#\xe2\x94\x83", "#floor#\xe2\x96\x91", "\xe2\x95\x91" }),
            ({ "\xe2\x95\xa3", "#floor#\xe2\x96\x91", "\xe2\x95\x91" }) })
    ]),
    "keep interior north-east-west entry alcove": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#door#\\", "+", }),
            ({ "#door#/", "#floor# ", "#door#/", }),
            ({ "|", "#floor# ", "|", }) }),
        "unicode": ({ ({ "\xe2\x95\xac", "#door#\xe2\x96\x94", "\xe2\x95\xac" }),
            ({ "#door#\xe2\x94\x83", "#floor#\xe2\x96\x91", "#door#\xe2\x94\x83" }),
            ({ "\xe2\x95\xa3", "#floor#\xe2\x96\x91", "\xe2\x95\xa0" }) })
    ]),
    "keep interior north alcove west entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "+", "+", }),
            ({ "#door#/", "#floor# ", "|", }),
            ({ "+", "#floor# ", "|", }) }),
        "unicode": ({ ({ "\xe2\x95\xac", "\xe2\x95\x90", "\xe2\x95\x97" }),
            ({ "#door#\xe2\x94\x83", "#floor#\xe2\x96\x91", "\xe2\x95\x91" }),
            ({ "\xe2\x95\xac", "#floor#\xe2\x96\x91", "\xe2\x95\x91" }) })
    ]),
    "keep interior north alcove east entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "+", "+", }),
            ({ "|", "#floor# ", "#door#/", }),
            ({ "|", "#floor# ", "|", }) }),
        "unicode": ({ ({ "\xe2\x95\x94", "\xe2\x95\x90", "\xe2\x95\xac" }),
            ({ "\xe2\x95\x91", "#floor#\xe2\x96\x91", "#door#\xe2\x94\x83" }),
            ({ "\xe2\x95\x91", "#floor#\xe2\x96\x91", "\xe2\x95\xac" }) })
    ]),
    "keep interior north alcove east-west entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "+", "+", }),
            ({ "#door#/", "#floor# ", "#door#/", }),
            ({ "|", "#floor# ", "|", }) }),
        "unicode": ({ ({ "\xe2\x95\xac", "\xe2\x95\x90", "\xe2\x95\xac" }),
            ({ "#door#\xe2\x94\x83", "#floor#\xe2\x96\x91", "#door#\xe2\x94\x83" }),
            ({ "\xe2\x95\xac", "#floor#\xe2\x96\x91", "\xe2\x95\xac" }) })
    ]),
    "keep interior south entry alcove": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
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
    "keep interior south-east entry alcove": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
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
    "keep interior south-west entry alcove": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
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
    "keep interior south-east-west entry alcove": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
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
    "keep interior south alcove west entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#floor# ", "|", }),
            ({ "#door#/", "#floor# ", "|", }),
            ({ "+", "-", "+", }) }),
        "unicode": ({ ({ "\xe2\x95\xac", "#floor#\xe2\x96\x91", "\xe2\x95\x91" }),
            ({ "#door#\xe2\x94\x83", "#floor#\xe2\x96\x91", "\xe2\x95\x91" }),
            ({ "\xe2\x95\xac", "\xe2\x95\x90", "\xe2\x95\x9d" }) })
    ]),
    "keep interior south alcove east entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "|", "#floor# ", "|", }),
            ({ "|", "#floor# ", "#door#/", }),
            ({ "+", "-", "+", }) }),
        "unicode": ({ ({ "\xe2\x95\x91", "#floor#\xe2\x96\x91", "\xe2\x95\xac" }),
            ({ "\xe2\x95\x91", "#floor#\xe2\x96\x91", "#door#\xe2\x94\x83" }),
            ({ "\xe2\x95\x9a", "\xe2\x95\x90", "\xe2\x95\xac" }) })
    ]),
    "keep interior south alcove east-west entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "|", "#floor# ", "|", }),
            ({ "#door#/", "#floor# ", "#door#/", }),
            ({ "+", "=", "+", }) }),
        "unicode": ({ ({ "\xe2\x95\xac", "#floor#\xe2\x96\x91", "\xe2\x95\xac" }),
            ({ "#door#\xe2\x94\x83", "#floor#\xe2\x96\x91", "#door#\xe2\x94\x83" }),
            ({ "\xe2\x95\xac", "\xe2\x95\x90", "\xe2\x95\xac" }) })
    ]),
    "keep interior west entry alcove": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
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
    "keep interior west-north entry alcove": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#door#\\", "=", }),
            ({ "#door#/", "#floor# ", "#floor# ", }),
            ({ "+", "=", "=", }) }),
        "unicode": ({ ({ "\xe2\x95\xac", "#door#\xe2\x96\x94", "\xe2\x95\xa9" }),
            ({ "#door#\xe2\x94\x83", "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", }),
            ({ "\xe2\x95\xac", "\xe2\x95\x90", "\xe2\x95\x90" }) })
    ]),
    "keep interior west-south entry alcove": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "=", "=", }),
            ({ "#door#/", "#floor# ", "#floor# ", }),
            ({ "+", "#door#\\", "=", }) }),
        "unicode": ({ ({ "\xe2\x95\xac", "\xe2\x95\x90", "\xe2\x95\x90" }),
            ({ "#door#\xe2\x94\x83", "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91" }),
            ({ "\xe2\x95\xac", "#door#\xe2\x96\x81", "\xe2\x95\xa6" }) })
    ]),
    "keep interior west-south-north entry alcove": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#door#\\", "=", }),
            ({ "#door#/", "#floor# ", "#floor# ", }),
            ({ "+", "#door#\\", "=", }) }),
        "unicode": ({ ({ "\xe2\x95\xac", "#door#\xe2\x96\x94", "\xe2\x95\xa9" }),
            ({ "#door#\xe2\x94\x83", "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91" }),
            ({ "\xe2\x95\xac", "#door#\xe2\x96\x81", "\xe2\x95\xa6" }) })
    ]),
    "keep interior west alcove north entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#door#/", "+", }),
            ({ "|", "#floor# ", "#floor# ", }),
            ({ "+", "=", "=", }) }),
        "unicode": ({ ({ "\xe2\x95\xac", "#door#\xe2\x96\x94", "\xe2\x95\xa9" }),
            ({ "\xe2\x95\x91", "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91" }),
            ({ "\xe2\x95\x9a", "\xe2\x95\x90", "\xe2\x95\x90" }) })
    ]),
    "keep interior west alcove": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "=", "=", }),
            ({ "|", "#floor# ", "#floor# ", }),
            ({ "+", "#door#/", "+" }) }),
        "unicode": ({ ({ "\xe2\x95\x94", "\xe2\x95\x90", "\xe2\x95\x90" }),
            ({ "\xe2\x95\x91", "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91" }),
            ({ "\xe2\x95\xac", "#door#\xe2\x96\x81", "\xe2\x95\xa6" }) })
    ]),
    "keep interior west alcove north-south entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
            "ascii": ({ ({ "+", "#door#/", "+" }),
            ({ "|", "#floor# ", "#floor# ", }),
            ({ "+", "#door#/", "+" }) }),
        "unicode": ({ ({ "\xe2\x95\xac", "#door#\xe2\x96\x94", "\xe2\x95\xa9" }),
            ({ "\xe2\x95\x91", "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91" }),
            ({ "\xe2\x95\x9a", "\xe2\x95\x90", "\xe2\x95\x90" }) })
    ]),
    "keep interior east entry alcove": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
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
    "keep interior east-south entry alcove": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
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
    "keep interior east-north entry alcove": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#door#\\", "=", }),
            ({ "#floor# ", "#floor# ", "#door#/", }),
            ({ "+", "=", "=", }) }),
        "unicode": ({ ({ "\xe2\x95\xa9", "#door#\xe2\x96\x94", "\xe2\x95\xac", }),
            ({ "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", "#door#\xe2\x94\x83", }),
            ({ "\xe2\x95\x90", "\xe2\x95\x90", "\xe2\x95\xac", }) })
    ]),
    "keep interior east-south-north entry alcove": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#door#\\", "+", }),
            ({ "#floor# ", "#floor# ", "#door#/", }),
            ({ "+", "#door#\\", "=", }) }),
        "unicode": ({ ({ "\xe2\x95\xa9", "#door#\xe2\x96\x94", "\xe2\x95\xac", }),
            ({ "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", "#door#\xe2\x94\x83", }),
            ({ "\xe2\x95\xa6", "#door#\xe2\x96\x81","\xe2\x95\xac", }) })
    ]),
    "keep interior east alcove north entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#door#\\", "+" }),
            ({ "#floor# ", "#floor# ", "|", }),
            ({ "=", "=", "+", }) }),
        "unicode": ({ ({ "\xe2\x95\xa9", "#door#\xe2\x96\x94", "\xe2\x95\xac" }),
            ({ "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", "\xe2\x95\x91" }),
            ({ "\xe2\x95\xa6", "#door#\xe2\x96\x81","\xe2\x95\xac" }) })
    ]),
    "keep interior east alcove south entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "=", "=", "+", }),
            ({ "#floor# ", "#floor# ", "|", }),
            ({ "+", "#door#\\", "+", }) }),
        "unicode": ({ ({ "\xe2\x95\x90", "\xe2\x95\x90", "\xe2\x95\x97" }),
            ({ "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", "\xe2\x95\x91" }),
            ({ "\xe2\x95\xa6", "#door#\xe2\x96\x81","\xe2\x95\xac" }) })
    ]),
    "keep interior east alcove north-south entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#door#\\", "+", }),
            ({ "#floor# ", "#floor# ", "|", }),
            ({ "+", "#door#\\", "+", }) }),
        "unicode": ({ ({ "\xe2\x95\xa9", "#door#\xe2\x96\x94", "\xe2\x95\xac" }),
            ({ "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", "\xe2\x95\x91" }),
            ({ "\xe2\x95\xa6", "#door#\xe2\x96\x81","\xe2\x95\xac" }) })
    ]),
    "keep interior north-west corner hallway": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
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
    "keep interior north-west corner hallway south entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
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
    "keep interior north-west corner hallway east entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
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
    "keep interior north-west corner hallway south-east entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
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
    "keep interior south-west corner hallway": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
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
    "keep interior south-west corner hallway north entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
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
    "keep interior south-west corner hallway east entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
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
    "keep interior south-west corner hallway north-east entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
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
    "keep interior north-east corner hallway": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
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
    "keep interior north-east corner hallway west entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
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
    "keep interior north-east corner hallway south entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
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
    "keep interior north-east corner hallway south-west entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
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
    "keep interior south-east corner hallway": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
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
    "keep interior south-east corner hallway west entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
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
    "keep interior south-east corner hallway north entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
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
    "keep interior south-east corner hallway north-west entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
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
    "keep interior southeast corner": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
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
    "keep interior southeast corner south entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
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
    "keep interior southeast corner east entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
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
    "keep interior southeast corner south-east entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
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
    "keep interior northeast corner": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
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
    "keep interior northeast corner north entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
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
    "keep interior northeast corner east entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
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
    "keep interior northeast corner north-east entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
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
    "keep interior southwest corner": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
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
    "keep interior southwest corner west entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
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
    "keep interior southwest corner south entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
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
    "keep interior southwest corner south-west entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
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
    "keep interior northwest corner": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
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
    "keep interior northwest corner west entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
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
    "keep interior northwest corner north entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
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
    "keep interior northwest corner north-west entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
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
    "keep interior west wall": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
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
    "keep interior west wall entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
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
    "keep interior east wall": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
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
    "keep interior east wall entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
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
    "keep interior north wall": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
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
    "keep interior north wall entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
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
    "keep interior south wall": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
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
    "keep interior south wall entry": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
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
   "keep interior floor": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
            "icons": ([
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ])
            ])
        ]),
        "ascii": ({ ({ "#floor# ", "#floor# ", "#floor# ", }),
            ({ "#floor# ", "#floor# ", "#floor# ", }),
            ({ "#floor# ", "#floor# ", "#floor# ", }) }),
        "unicode": ({ ({ "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91" }),
            ({ "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91" }),
            ({ "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91" }) })
    ]),
   "keep interior courtyard": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
            "icons": ([
                "grass":([
                    "none": "",
                    "3-bit": "\x1b[0;32m",
                    "8-bit": "\x1b[0;38;5;22m",
                    "24-bit": "\x1b[0;38;2;30;50;20m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "#grass# ", "#grass# ", "#grass# ", }),
            ({ "#grass# ", "#grass# ", "#grass# ", }),
            ({ "#grass# ", "#grass# ", "#grass# ", }) }),
        "unicode": ({ ({ "#grass#\xe2\x96\x91", "#grass#\xe2\x96\x91", "#grass#\xe2\x96\x91" }),
            ({ "#grass#\xe2\x96\x91", "#grass#\xe2\x96\x91", "#grass#\xe2\x96\x91" }),
            ({ "#grass#\xe2\x96\x91", "#grass#\xe2\x96\x91", "#grass#\xe2\x96\x91" }) })
    ]),
   "keep interior courtyard with path": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
            "icons": ([
                "floor":([
                    "none":"",
                        "3-bit" : "\x1b[0;31m",
                        "8-bit" : "\x1b[0;38;5;234m",
                        "24-bit" : "\x1b[0;38;2;28;36;28m",
                ]),
                "grass":([
                    "none": "",
                    "3-bit": "\x1b[0;32m",
                    "8-bit": "\x1b[0;38;5;22m",
                    "24-bit": "\x1b[0;38;2;30;50;20m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "#grass# ", "#floor# ", "#grass# ", }),
            ({ "#floor# ", "#floor# ", "#floor# ", }),
            ({ "#grass# ", "#floor# ", "#grass# ", }) }),
        "unicode": ({ ({ "#grass#\xe2\x96\x91", "#floor#\xe2\x96\x91", "#grass#\xe2\x96\x91" }),
            ({ "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91" }),
            ({ "#grass#\xe2\x96\x91", "#floor#\xe2\x96\x91", "#grass#\xe2\x96\x91" }) })
    ]),

    "keep interior courtyard with pillar": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
            "icons": ([
                "grass":([
                    "none": "",
                    "3-bit": "\x1b[0;32m",
                    "8-bit": "\x1b[0;38;5;22m",
                    "24-bit": "\x1b[0;38;2;30;50;20m",
                ]),
                "pillar":([
                    "none": "",
                    "3-bit": "\x1b[0;36;1m",
                    "8-bit": "\x1b[0;38;5;243;1m",
                    "24-bit": "\x1b[0;38;2;118;118;128;1m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "#grass# ", "#grass# ", "#grass# ", }),
            ({ "#grass# ", "#pillar#+", "#grass# ", }),
            ({ "#grass# ", "#grass# ", "#grass# ", }) }),
        "unicode": ({ ({ "#grass#\xe2\x96\x91", "#grass#\xe2\x96\x91", "#grass#\xe2\x96\x91" }),
            ({ "#grass#\xe2\x96\x91", "#pillar#\xe2\x97\x8e", "#grass#\xe2\x96\x91" }),
            ({ "#grass#\xe2\x96\x91", "#grass#\xe2\x96\x91", "#grass#\xe2\x96\x91" }) })
    ]),
    "keep interior-to-exterior north-south hallway west exit": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
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
    "keep interior-to-exterior north-south hallway east exit": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
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
            ({ "#floor# ", "#floor# ", "|", }),
            ({ "|", "#floor# ", "|", }) }),
        "unicode": ({ ({ "\xe2\x95\xa8", "#floor#\xe2\x96\x91", "\xe2\x95\x91" }),
            ({ "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", "\xe2\x95\x91" }),
            ({ "\xe2\x95\xa5", "#floor#\xe2\x96\x91", "\xe2\x95\x91" }) })
    ]),
    "keep interior-to-exterior east-west hallway south exit": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
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
            ({ "\xe2\x95\xa1", "#floor#\xe2\x96\x91", "\xe2\x95\x9e" }) })
    ]),
    "keep interior-to-exterior north-corner hallway east exit": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
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
    "keep interior-to-exterior north-corner hallway west exit": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
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
            ({ "|", "#floor# ", "|", }) }),
        "unicode": ({ ({ "\xe2\x95\xa6", "\xe2\x95\x90", "\xe2\x95\x97" }),
            ({ "#floor#\xe2\x96\x91", "#floor#\xe2\x96\x91", "\xe2\x95\x91" }),
            ({ "\xe2\x95\xa5", "#floor#\xe2\x96\x91", "\xe2\x95\x91" }) })
    ]),

    // Other locations
    "keep interior south gatehouse": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
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
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
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
    "keep interior large staired entrance right": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
            "icons": ([
                "pillar":([
                    "none": "",
                    "3-bit": "\x1b[0;36;1m",
                    "8-bit": "\x1b[0;38;5;243;1m",
                    "24-bit": "\x1b[0;38;2;118;118;128;1m",
                ]),
                "stairs":([
                    "none": "",
                    "3-bit": "\x1b[0;31;1m",
                    "8-bit": "\x1b[0;38;5;237m",
                    "24-bit": "\x1b[0;38;2;40;42;45m",
                ]),
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;23m",
                    "24-bit": "\x1b[0;38;2;8;10;12m",
                ]),
                "floor2":([
                    "none": "",
                    "3-bit": "\x1b[0;30;1m",
                    "8-bit": "\x1b[0;38;5;23m",
                    "24-bit": "\x1b[0;38;2;8;12;8m",
                ]),
                "grass":([
                    "none": "",
                    "3-bit": "\x1b[0;32m",
                    "8-bit": "\x1b[0;38;5;22m",
                    "24-bit": "\x1b[0;38;2;30;50;20m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "#grass# ", "#grass# ", "#grass# ", }),
            ({ "#floor# ", "#floor2# ", "#floor# ", }),
            ({ "#stairs#-", "#stairs#-", "#pillar#+", }) }),
        "unicode": ({ ({ "#grass#\xe2\x96\x91", "#grass#\xe2\x96\x91", "#grass#\xe2\x96\x91" }),
            ({ "#floor#\xe2\x96\x85", "#floor2#\xe2\x96\x85", "#floor#\xe2\x96\x85" }),
            ({ "#stairs#\xe2\x8c\xb8", "#stairs#\xe2\x8c\xb8", "#pillar#\xe2\x8e\x8a" }) })
    ]),
    "keep interior large staired entrance left": ([
        "colors": ([
            "none": "",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;86;92;86m",
            "icons": ([
                "stairs":([
                    "none": "",
                    "3-bit": "\x1b[0;31;1m",
                    "8-bit": "\x1b[0;38;5;237m",
                    "24-bit": "\x1b[0;38;2;40;42;45m",
                ]),
                "floor":([
                    "none": "",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;23m",
                    "24-bit": "\x1b[0;38;2;8;10;12m",
                ]),
                "floor2":([
                    "none": "",
                    "3-bit": "\x1b[0;30;1m",
                    "8-bit": "\x1b[0;38;5;23m",
                    "24-bit": "\x1b[0;38;2;8;12;8m",
                ]),
                "grass":([
                    "none": "",
                    "3-bit": "\x1b[0;32m",
                    "8-bit": "\x1b[0;38;5;22m",
                    "24-bit": "\x1b[0;38;2;30;50;20m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "#grass# ", "#grass# ", "#grass# ", }),
            ({ "#floor# ", "#floor2# ", "#floor# ", }),
            ({ "#stairs#-", "#stairs#-", "#stairs#-", }) }),
        "unicode": ({ ({ "#grass#\xe2\x96\x91", "#grass#\xe2\x96\x91", "#grass#\xe2\x96\x91" }),
            ({ "#floor2#\xe2\x96\x85", "#floor#\xe2\x96\x85", "#floor2#\xe2\x96\x85" }),
            ({ "#stairs#\xe2\x8c\xb8", "#stairs#\xe2\x8c\xb8", "#stairs#\xe2\x8c\xb8" }) })
    ]),
]);

#endif
