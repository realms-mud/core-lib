//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef ruinedInteriorIcons_h
#define ruinedInteriorIcons_h

private mapping RuinedInteriorIcons = ([
    // Hallways
    "ruined interior east-west hallway": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "=", "=", "=", }),
            ({ "#floor# ", "#floor# ", "#floor# ", }),
            ({ "=", "=", "=", }) }),
        "unicode": ({ ({ "\u2550", "\u2550", "\u2550" }),
            ({ "#floor#\u2591", "#floor#\u2591", "#floor#\u2591" }),
            ({ "\u2550", "\u2550", "\u2550" }) })
    ]),
    "ruined interior east-west hallway north entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;251m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#door#\\", "+", }),
            ({ "#floor# ", "#floor# ", "#floor# ", }),
            ({ "=", "=", "=", }) }),
        "unicode": ({ ({ "\u2569", "#door#\u2594", "\u2569" }),
            ({ "#floor#\u2591", "#floor#\u2591", "#floor#\u2591" }),
            ({ "\u2550", "\u2550", "\u2550" }) })
    ]),
    "ruined interior east-west hallway south entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;251m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "=", "=", "=", }),
            ({ "#floor# ", "#floor# ", "#floor# ", }),
            ({ "+", "#door#\\", "+", }) }),
        "unicode": ({ ({ "\u2550", "\u2550", "\u2550" }),
            ({ "#floor#\u2591", "#floor#\u2591", "#floor#\u2591" }),
            ({ "\u2566", "#door#\u2581", "\u2566" }) })
    ]),
    "ruined interior east-west hallway north-south entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;251m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#door#\\", "+", }),
            ({ "#floor# ", "#floor# ", "#floor# ", }),
            ({ "+", "#door#\\", "+", }) }),
        "unicode": ({ ({ "\u2569", "#door#\u2594", "\u2569" }),
            ({ "#floor#\u2591", "#floor#\u2591", "#floor#\u2591" }),
            ({ "\u2566", "#door#\u2581", "\u2566" }) })
    ]),
    "ruined interior north-south hallway": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "|", "#floor# ", "|", }),
            ({ "|", "#floor# ", "|", }),
            ({ "|", "#floor# ", "|", }) }),
        "unicode": ({ ({ "\u2551", "#floor#\u2591", "\u2551" }),
            ({ "\u2551", "#floor#\u2591", "\u2551" }),
            ({ "\u2551", "#floor#\u2591", "\u2551" }) })
    ]),
    "ruined interior north-south hallway east entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;251m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "|", "#floor# ", "+", }),
            ({ "|", "#floor# ", "#door#/", }),
            ({ "|", "#floor# ", "+", }) }),
        "unicode": ({ ({ "\u2551", "#floor#\u2591", "\u2560" }),
            ({ "\u2551", "#floor#\u2591", "#door#\u2503" }),
            ({ "\u2551", "#floor#\u2591", "\u2560" }) })
    ]),
    "ruined interior north-south hallway west entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;251m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#floor# ", "|", }),
            ({ "#door#/", "#floor# ", "|", }),
            ({ "+", "#floor# ", "|", }) }),
        "unicode": ({ ({ "\u2563", "#floor#\u2591", "\u2551" }),
            ({ "#door#\u2503", "#floor#\u2591", "\u2551" }),
            ({ "\u2563", "#floor#\u2591", "\u2551" }) })
    ]),
    "ruined interior north-south hallway east-west entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;251m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#floor# ", "+", }),
            ({ "#door#/", "#floor# ", "#door#/", }),
            ({ "+", "#floor# ", "+", }) }),
        "unicode": ({ ({ "\u2563", "#floor#\u2591", "\u2560" }),
            ({ "#door#\u2503", "#floor#\u2591", "#door#\u2503" }),
            ({ "\u2563", "#floor#\u2591", "\u2560" }) })
    ]),
    "ruined interior 4-way hallway": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "+", "#floor# ", "+", }),
            ({ "#floor# ", "#floor# ", "#floor# ", }),
            ({ "+", "#floor# ", "+", }) }),
        "unicode": ({ ({ "\u255d", "#floor#\u2591", "\u255a" }),
            ({ "#floor#\u2591", "#floor#\u2591", "#floor#\u2591" }),
            ({ "\u2557", "#floor#\u2591", "\u2554" }) })
    ]),
    "ruined interior south alcove": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "|", "#floor# ", "|", }),
            ({ "|", "#floor# ", "|", }),
            ({ "+", "=", "+", }) }),
        "unicode": ({ ({ "\u2551", "#floor#\u2591", "\u2551" }),
            ({ "\u2551", "#floor#\u2591", "\u2551" }),
            ({ "\u255a", "\u2550", "\u255d" }) })
    ]),
    "ruined interior north alcove": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "+", "=", "+", }),
            ({ "|", "#floor# ", "|", }),
            ({ "|", "#floor# ", "|", }) }),
        "unicode": ({ ({ "\u2554", "\u2550", "\u2557" }),
            ({ "\u2551", "#floor#\u2591", "\u2551" }),
            ({ "\u2551", "#floor#\u2591", "\u2551" }) })
    ]),
    "ruined interior west alcove": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "+", "=", "=", }),
            ({ "|", "#floor# ", "#floor# ", }),
            ({ "+", "=", "=", }) }),
        "unicode": ({ ({ "\u2554", "\u2550", "\u2550" }),
            ({ "\u2551", "#floor#\u2591", "#floor#\u2591" }),
            ({ "\u255a", "\u2550", "\u2550" }) })
    ]),
    "ruined interior east alcove": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "=", "=", "+", }),
            ({ "#floor# ", "#floor# ", "|", }),
            ({ "=", "=", "+", }) }),
        "unicode": ({ ({ "\u2550", "\u2550", "\u2557" }),
            ({ "#floor#\u2591", "#floor#\u2591", "\u2551" }),
            ({ "\u2550", "\u2550", "\u255d" }) })
    ]),
    "ruined interior west T-intersection": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "+", "#floor# ", "|", }),
            ({ "#floor# ", "#floor# ", "|", }),
            ({ "+", "#floor# ", "|", }) }),
        "unicode": ({ ({ "\u255d", "#floor#\u2591", "\u2551" }),
            ({ "#floor#\u2591", "#floor#\u2591", "\u2551" }),
            ({ "\u2557", "#floor#\u2591", "\u2551" }) })
    ]),
    "ruined interior west T-intersection east entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;251m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#floor# ", "+", }),
            ({ "#floor# ", "#floor# ", "#floor# ", }),
            ({ "+", "#floor# ", "+", }) }),
        "unicode": ({ ({ "\u255d", "#floor#\u2591", "\u255a" }),
            ({ "#floor#\u2591", "#floor#\u2591", "#floor#\u2591" }),
            ({ "\u2557", "#floor#\u2591", "\u2554" }) })
    ]),
    "ruined interior east T-intersection": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "|", "#floor# ", "+", }),
            ({ "|", "#floor# ", "#floor# ", }),
            ({ "|", "#floor# ", "+", }) }),
        "unicode": ({ ({ "\u2551", "#floor#\u2591", "\u255a" }),
            ({ "\u2551", "#floor#\u2591", "#floor#\u2591" }),
            ({ "\u2551", "#floor#\u2591", "\u2554" }) })
    ]),
    "ruined interior east T-intersection west entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;251m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#floor# ", "+", }),
            ({ "#floor# ", "#floor# ", "#floor# ", }),
            ({ "+", "#floor# ", "+", }) }),
        "unicode": ({ ({ "\u255d", "#floor#\u2591", "\u255a" }),
            ({ "#floor#\u2591", "#floor#\u2591", "#floor#\u2591" }),
            ({ "\u2557", "#floor#\u2591", "\u2554" }) })
    ]),
    "ruined interior south T-intersection": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "=", "=", "=", }),
            ({ "#floor# ", "#floor# ", "#floor# ", }),
            ({ "+", "#floor# ", "+", }) }),
        "unicode": ({ ({ "\u2550", "\u2550", "\u2550" }),
            ({ "#floor#\u2591", "#floor#\u2591", "#floor#\u2591" }),
            ({ "\u2557", "#floor#\u2591", "\u2554" }) })
    ]),
    "ruined interior south T-intersection north entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;251m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#door#/", "+", }),
            ({ "#floor# ", "#floor# ", "#floor# ", }),
            ({ "+", "#floor# ", "+", }) }),
        "unicode": ({ ({ "\u255d", "#door#\u2594", "\u255a" }),
            ({ "#floor#\u2591", "#floor#\u2591", "#floor#\u2591" }),
            ({ "\u2557", "#floor#\u2591", "\u2554" }) })
    ]),
    "ruined interior north T-intersection": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "+", "#floor# ", "+", }),
            ({ "#floor# ", "#floor# ", "#floor# ", }),
            ({ "=", "=", "=", }) }),
        "unicode": ({ ({ "\u255d", "#floor#\u2591", "\u255a" }),
            ({ "#floor#\u2591", "#floor#\u2591", "#floor#\u2591" }),
            ({ "\u2550", "\u2550", "\u2550" }) })
    ]),
    "ruined interior north T-intersection south entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;251m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#floor# ", "+", }),
            ({ "#floor# ", "#floor# ", "#floor# ", }),
            ({ "+", "#floor# ", "+", }) }),
        "unicode": ({ ({ "\u255d", "#floor#\u2591", "\u255a" }),
            ({ "#floor#\u2591", "#floor#\u2591", "#floor#\u2591" }),
            ({ "\u2557", "#floor#\u2591", "\u2554" }) })
    ]),
    "ruined interior north entry alcove": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;251m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#door#\\", "+", }),
            ({ "|", "#floor# ", "|", }),
            ({ "|", "#floor# ", "|", }) }),
        "unicode": ({ ({ "\u256c", "#door#\u2594", "\u256c" }),
            ({ "\u2551", "#floor#\u2591", "\u2551" }),
            ({ "\u2551", "#floor#\u2591", "\u2551" }) })
    ]),
    "ruined interior north-east entry alcove": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;251m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#door#\\", "+", }),
            ({ "|", "#floor# ", "#door#/", }),
            ({ "|", "#floor# ", "|", }) }),
        "unicode": ({ ({ "\u256c", "#door#\u2594", "\u256c" }),
            ({ "\u2551", "#floor#\u2591", "#door#\u2503" }),
            ({ "\u2551", "#floor#\u2591", "\u2560" }) })
    ]),
    "ruined interior north-west entry alcove": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;251m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#door#\\", "+", }),
            ({ "#door#/", "#floor# ", "|", }),
            ({ "|", "#floor# ", "|", }) }),
        "unicode": ({ ({ "\u256c", "#door#\u2594", "\u256c" }),
            ({ "#door#\u2503", "#floor#\u2591", "\u2551" }),
            ({ "\u2563", "#floor#\u2591", "\u2551" }) })
    ]),
    "ruined interior north-east-west entry alcove": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;251m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#door#\\", "+", }),
            ({ "#door#/", "#floor# ", "#door#/", }),
            ({ "|", "#floor# ", "|", }) }),
        "unicode": ({ ({ "\u256c", "#door#\u2594", "\u256c" }),
            ({ "#door#\u2503", "#floor#\u2591", "#door#\u2503" }),
            ({ "\u2563", "#floor#\u2591", "\u2560" }) })
    ]),
    "ruined interior north alcove west entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;251m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "+", "+", }),
            ({ "#door#/", "#floor# ", "|", }),
            ({ "+", "#floor# ", "|", }) }),
        "unicode": ({ ({ "\u256c", "\u2550", "\u2557" }),
            ({ "#door#\u2503", "#floor#\u2591", "\u2551" }),
            ({ "\u256c", "#floor#\u2591", "\u2551" }) })
    ]),
    "ruined interior north alcove east entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;251m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "+", "+", }),
            ({ "|", "#floor# ", "#door#/", }),
            ({ "|", "#floor# ", "|", }) }),
        "unicode": ({ ({ "\u2554", "\u2550", "\u256c" }),
            ({ "\u2551", "#floor#\u2591", "#door#\u2503" }),
            ({ "\u2551", "#floor#\u2591", "\u256c" }) })
    ]),
    "ruined interior north alcove east-west entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;251m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "+", "+", }),
            ({ "#door#/", "#floor# ", "#door#/", }),
            ({ "|", "#floor# ", "|", }) }),
        "unicode": ({ ({ "\u256c", "\u2550", "\u256c" }),
            ({ "#door#\u2503", "#floor#\u2591", "#door#\u2503" }),
            ({ "\u256c", "#floor#\u2591", "\u256c" }) })
    ]),
    "ruined interior south entry alcove": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;251m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "|", "#floor# ", "|", }),
            ({ "|", "#floor# ", "|", }),
            ({ "+", "#door#/", "+", }), }),
        "unicode": ({ ({ "\u2551", "#floor#\u2591", "\u2551" }),
            ({ "\u2551", "#floor#\u2591", "\u2551" }),
            ({ "\u256c", "#door#\u2581", "\u256c" }), })
    ]),
    "ruined interior south-east entry alcove": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;251m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "|", "#floor# ", "|", }),
            ({ "|", "#floor# ", "#door#/", }),
            ({ "+", "#door#/", "+", }), }),
        "unicode": ({ ({ "\u2551", "#floor#\u2591", "\u2560" }),
            ({ "\u2551", "#floor#\u2591", "#door#\u2503" }),
            ({ "\u256c", "#door#\u2581", "\u256c" }), })
    ]),
    "ruined interior south-west entry alcove": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;251m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "|", "#floor# ", "|", }),
            ({ "#door#/", "#floor# ", "|", }),
            ({ "+", "#door#/", "+", }), }),
        "unicode": ({ ({ "\u2563", "#floor#\u2591", "\u2551" }),
            ({ "#door#\u2503", "#floor#\u2591", "\u2551" }),
            ({ "\u256c", "#door#\u2581", "\u256c" }), })
    ]),
    "ruined interior south-east-west entry alcove": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;251m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "|", "#floor# ", "|", }),
            ({ "#door#/", "#floor# ", "#door#/", }),
            ({ "+", "#door#/", "+", }), }),
        "unicode": ({ ({ "\u2563", "#floor#\u2591", "\u2560" }),
            ({ "#door#\u2503", "#floor#\u2591", "#door#\u2503" }),
            ({ "\u256c", "#door#\u2581", "\u256c" }), })
    ]),
    "ruined interior south alcove west entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;251m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#floor# ", "|", }),
            ({ "#door#/", "#floor# ", "|", }),
            ({ "+", "-", "+", }) }),
        "unicode": ({ ({ "\u256c", "#floor#\u2591", "\u2551" }),
            ({ "#door#\u2503", "#floor#\u2591", "\u2551" }),
            ({ "\u256c", "\u2550", "\u255d" }) })
    ]),
    "ruined interior south alcove east entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;251m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "|", "#floor# ", "|", }),
            ({ "|", "#floor# ", "#door#/", }),
            ({ "+", "-", "+", }) }),
        "unicode": ({ ({ "\u2551", "#floor#\u2591", "\u256c" }),
            ({ "\u2551", "#floor#\u2591", "#door#\u2503" }),
            ({ "\u255a", "\u2550", "\u256c" }) })
    ]),
    "ruined interior south alcove east-west entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;251m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "|", "#floor# ", "|", }),
            ({ "#door#/", "#floor# ", "#door#/", }),
            ({ "+", "=", "+", }) }),
        "unicode": ({ ({ "\u256c", "#floor#\u2591", "\u256c" }),
            ({ "#door#\u2503", "#floor#\u2591", "#door#\u2503" }),
            ({ "\u256c", "\u2550", "\u256c" }) })
    ]),
    "ruined interior west entry alcove": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;251m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "=", "=", }),
            ({ "#door#/", "#floor# ", "#floor# ", }),
            ({ "+", "=", "=", }) }),
        "unicode": ({ ({ "\u256c", "\u2550", "\u2550" }),
            ({ "#door#\u2503", "#floor#\u2591", "#floor#\u2591" }),
            ({ "\u256c", "\u2550", "\u2550" }) })
    ]),
    "ruined interior west-north entry alcove": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;251m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#door#\\", "=", }),
            ({ "#door#/", "#floor# ", "#floor# ", }),
            ({ "+", "=", "=", }) }),
        "unicode": ({ ({ "\u256c", "#door#\u2594", "\u2569" }),
            ({ "#door#\u2503", "#floor#\u2591", "#floor#\u2591", }),
            ({ "\u256c", "\u2550", "\u2550" }) })
    ]),
    "ruined interior west-south entry alcove": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;251m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "=", "=", }),
            ({ "#door#/", "#floor# ", "#floor# ", }),
            ({ "+", "#door#\\", "=", }) }),
        "unicode": ({ ({ "\u256c", "\u2550", "\u2550" }),
            ({ "#door#\u2503", "#floor#\u2591", "#floor#\u2591" }),
            ({ "\u256c", "#door#\u2581", "\u2566" }) })
    ]),
    "ruined interior west-south-north entry alcove": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;251m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#door#\\", "=", }),
            ({ "#door#/", "#floor# ", "#floor# ", }),
            ({ "+", "#door#\\", "=", }) }),
        "unicode": ({ ({ "\u256c", "#door#\u2594", "\u2569" }),
            ({ "#door#\u2503", "#floor#\u2591", "#floor#\u2591" }),
            ({ "\u256c", "#door#\u2581", "\u2566" }) })
    ]),
    "ruined interior west alcove north entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;251m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#door#/", "+", }),
            ({ "|", "#floor# ", "#floor# ", }),
            ({ "+", "=", "=", }) }),
        "unicode": ({ ({ "\u256c", "#door#\u2594", "\u2569" }),
            ({ "\u2551", "#floor#\u2591", "#floor#\u2591" }),
            ({ "\u255a", "\u2550", "\u2550" }) })
    ]),
    "ruined interior west alcove": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;251m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "=", "=", }),
            ({ "|", "#floor# ", "#floor# ", }),
            ({ "+", "#door#/", "+" }) }),
        "unicode": ({ ({ "\u2554", "\u2550", "\u2550" }),
            ({ "\u2551", "#floor#\u2591", "#floor#\u2591" }),
            ({ "\u256c", "#door#\u2581", "\u2566" }) })
    ]),
    "ruined interior west alcove north-south entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;251m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
            "ascii": ({ ({ "+", "#door#/", "+" }),
            ({ "|", "#floor# ", "#floor# ", }),
            ({ "+", "#door#/", "+" }) }),
        "unicode": ({ ({ "\u256c", "#door#\u2594", "\u2569" }),
            ({ "\u2551", "#floor#\u2591", "#floor#\u2591" }),
            ({ "\u255a", "\u2550", "\u2550" }) })
    ]),
    "ruined interior east entry alcove": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;251m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "=", "=", }),
            ({ "#floor# ", "#floor# ", "#door#/", }),
            ({ "+", "=", "=", }) }),
        "unicode": ({ ({ "\u2550", "\u2550", "\u256c", }),
            ({ "#floor#\u2591", "#floor#\u2591", "#door#\u2503", }),
            ({ "\u2550", "\u2550","\u256c", }) })
    ]),
    "ruined interior east-south entry alcove": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;251m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "=", "=", }),
            ({ "#floor# ", "#floor# ", "#door#/", }),
            ({ "+", "#door#\\", "=", }) }),
        "unicode": ({ ({ "\u2550", "\u2550", "\u256c", }),
            ({ "#floor#\u2591", "#floor#\u2591", "#door#\u2503", }),
            ({ "\u2566", "#door#\u2581","\u256c", }) })
    ]),
    "ruined interior east-north entry alcove": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;251m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#door#\\", "=", }),
            ({ "#floor# ", "#floor# ", "#door#/", }),
            ({ "+", "=", "=", }) }),
        "unicode": ({ ({ "\u2569", "#door#\u2594", "\u256c", }),
            ({ "#floor#\u2591", "#floor#\u2591", "#door#\u2503", }),
            ({ "\u2550", "\u2550", "\u256c", }) })
    ]),
    "ruined interior east-south-north entry alcove": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;251m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#door#\\", "+", }),
            ({ "#floor# ", "#floor# ", "#door#/", }),
            ({ "+", "#door#\\", "=", }) }),
        "unicode": ({ ({ "\u2569", "#door#\u2594", "\u256c", }),
            ({ "#floor#\u2591", "#floor#\u2591", "#door#\u2503", }),
            ({ "\u2566", "#door#\u2581","\u256c", }) })
    ]),
    "ruined interior east alcove north entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;251m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#door#\\", "+" }),
            ({ "#floor# ", "#floor# ", "|", }),
            ({ "=", "=", "+", }) }),
        "unicode": ({ ({ "\u2569", "#door#\u2594", "\u256c" }),
            ({ "#floor#\u2591", "#floor#\u2591", "\u2551" }),
            ({ "\u2566", "#door#\u2581","\u256c" }) })
    ]),
    "ruined interior east alcove south entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;251m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "=", "=", "+", }),
            ({ "#floor# ", "#floor# ", "|", }),
            ({ "+", "#door#\\", "+", }) }),
        "unicode": ({ ({ "\u2550", "\u2550", "\u2557" }),
            ({ "#floor#\u2591", "#floor#\u2591", "\u2551" }),
            ({ "\u2566", "#door#\u2581","\u256c" }) })
    ]),
    "ruined interior east alcove north-south entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;251m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#door#\\", "+", }),
            ({ "#floor# ", "#floor# ", "|", }),
            ({ "+", "#door#\\", "+", }) }),
        "unicode": ({ ({ "\u2569", "#door#\u2594", "\u256c" }),
            ({ "#floor#\u2591", "#floor#\u2591", "\u2551" }),
            ({ "\u2566", "#door#\u2581","\u256c" }) })
    ]),
    "ruined interior north-west corner hallway": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "+", "#floor# ", "|", }),
            ({ "#floor# ", "#floor# ", "|", }),
            ({ "-", "-", "+", }) }),
        "unicode": ({ ({ "\u255d", "#floor#\u2591", "\u2551" }),
            ({ "#floor#\u2591", "#floor#\u2591", "\u2551" }),
            ({ "\u2550", "\u2550", "\u255d" }) })
    ]),
    "ruined interior north-west corner hallway south entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;251m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#floor# ", "|", }),
            ({ "#floor# ", "#floor# ", "|", }),
            ({ "-", "#door#/", "+", }) }),
        "unicode": ({ ({ "\u255d", "#floor#\u2591", "\u2551" }),
            ({ "#floor#\u2591", "#floor#\u2591", "\u2551" }),
            ({ "\u2557", "#door#\u2581", "\u2563" }) })
    ]),
    "ruined interior north-west corner hallway east entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;251m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#floor# ", "|", }),
            ({ "#floor# ", "#floor# ", "#door#/", }),
            ({ "-", "-", "+", }) }),
        "unicode": ({ ({ "\u255d", "#floor#\u2591", "\u2560" }),
            ({ "#floor#\u2591", "#floor#\u2591", "#door#\u2503" }),
            ({ "\u2550", "\u2550", "\u2569" }) })
    ]),
    "ruined interior north-west corner hallway south-east entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;251m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#floor# ", "|", }),
            ({ "#floor# ", "#floor# ", "#door#/", }),
            ({ "-", "#door#/", "+", }) }),
        "unicode": ({ ({ "\u255d", "#floor#\u2591", "\u2560" }),
            ({ "#floor#\u2591", "#floor#\u2591", "#door#\u2503" }),
            ({ "\u2557", "#door#\u2581", "\u256c" }) })
    ]),
    "ruined interior south-west corner hallway": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "-", "-", "+", }),
            ({ "#floor# ", "#floor# ", "|", }),
            ({ "+", "#floor# ", "|", }) }),
        "unicode": ({ ({ "\u2550", "\u2550", "\u2557" }),
            ({ "#floor#\u2591", "#floor#\u2591", "\u2551" }),
            ({ "\u2557", "#floor#\u2591", "\u2551" }) })
    ]),
    "ruined interior south-west corner hallway north entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;251m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#door#/", "+", }),
            ({ "#floor# ", "#floor# ", "|", }),
            ({ "+", "#floor# ", "+", }) }),
        "unicode": ({ ({ "\u2569", "#door#\u2594","\u2563" }),
            ({ "#floor#\u2591", "#floor#\u2591", "\u2551" }),
            ({ "\u2557", "#floor#\u2591", "\u2551" }) })
    ]),
    "ruined interior south-west corner hallway east entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;251m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "-", "-", "+" }),
            ({ "#floor# ", "#floor# ", "#door#/", }),
            ({ "+", "#floor# ", "|", }) }),
        "unicode": ({ ({ "\u2550", "\u2550","\u2566" }),
            ({ "#floor#\u2591", "#floor#\u2591", "#door#\u2503" }),
            ({ "\u2557", "#floor#\u2591", "\u2560" }) })
    ]),
    "ruined interior south-west corner hallway north-east entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;251m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#door#/", "+", }),
            ({ "#floor# ", "#floor# ", "#door#/", }),
            ({ "+", "#floor# ", "+", }) }),
        "unicode": ({ ({ "\u2569", "#door#\u2594","\u256c" }),
            ({ "#floor#\u2591", "#floor#\u2591", "#door#\u2503" }),
            ({ "\u2557", "#floor#\u2591", "\u2560" }) })
    ]),
    "ruined interior north-east corner hallway": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "|", "#floor# ", "+", }),
            ({ "|", "#floor# ", "#floor# ", }),
            ({ "-", "-", "+", }) }),
        "unicode": ({ ({ "\u2551", "#floor#\u2591", "\u255a" }),
            ({ "\u2551", "#floor#\u2591", "#floor#\u2591", }),
            ({ "\u255a", "\u2550", "\u2550" }) })
    ]),
    "ruined interior north-east corner hallway west entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;251m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#floor# ", "+", }),
            ({ "#door#\\", "#floor# ", "#floor# ", }),
            ({ "-", "-", "+", }) }),
        "unicode": ({ ({ "\u2563", "#floor#\u2591", "\u255a" }),
            ({ "#door#\u2503", "#floor#\u2591", "#floor#\u2591", }),
            ({ "\u2569", "\u2550", "\u2550" }) })
    ]),
    "ruined interior north-east corner hallway south entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;251m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "|", "#floor# ", "+", }),
            ({ "|", "#floor# ", "#floor# ", }),
            ({ "-", "#door#/", "+", }) }),
        "unicode": ({ ({ "\u2551", "#floor#\u2591", "\u255a" }),
            ({ "\u2551", "#floor#\u2591", "#floor#\u2591", }),
            ({ "\u2560", "#door#\u2581", "\u2566" }) })
    ]),
    "ruined interior north-east corner hallway south-west entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;251m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#floor# ", "+", }),
            ({ "#door#\\", "#floor# ", "#floor# ", }),
            ({ "+", "#door#/", "+", }) }),
        "unicode": ({ ({ "\u2563", "#floor#\u2591", "\u255a" }),
            ({ "#door#\u2503", "#floor#\u2591", "#floor#\u2591", }),
            ({ "\u256c", "#door#\u2581", "\u2566" }) })
    ]),
    "ruined interior south-east corner hallway": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "+", "-", "-", }),
            ({ "|", "#floor# ", "#floor# ", }),
            ({ "|", "#floor# ", "+", }) }),
        "unicode": ({ ({ "\u2554", "\u2550", "\u2550" }),
            ({ "\u2551", "#floor#\u2591", "#floor#\u2591" }),
            ({ "\u2551", "#floor#\u2591", "\u2554" }) })
    ]),
    "ruined interior south-east corner hallway west entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;251m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "-", "-", }),
            ({ "#door#\\", "#floor# ", "#floor# ", }),
            ({ "+", "#floor# ", "+", }) }),
        "unicode": ({ ({ "\u2566", "\u2550", "\u2550" }),
            ({ "#door#\u2503", "#floor#\u2591", "#floor#\u2591", }),
            ({ "\u2563", "#floor#\u2591", "\u2554" }) })
    ]),
    "ruined interior south-east corner hallway north entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;251m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#door#\\", "+", }),
            ({ "|", "#floor# ", "#floor# ", }),
            ({ "|", "#floor# ", "+", }) }),
        "unicode": ({ ({ "\u2560", "#door#\u2594","\u2569" }),
            ({ "\u2551", "#floor#\u2591", "#floor#\u2591" }),
            ({ "\u2551", "#floor#\u2591", "\u2554" }) })
    ]),
    "ruined interior south-east corner hallway north-west entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;251m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#door#\\", "+", }),
            ({ "#door#\\", "#floor# ", "#floor# ", }),
            ({ "+", "#floor# ", "+", }) }),
        "unicode": ({ ({ "\u256c", "#door#\u2594", "\u2569" }),
            ({ "#door#\u2503", "#floor#\u2591", "#floor#\u2591", }),
            ({ "\u2563", "#floor#\u2591", "\u2554" }) })
    ]),

    // Large Rooms
    "ruined interior southeast corner": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "#floor# ", "#floor# ", "|", }),
            ({ "#floor# ", "#floor# ", "|", }),
            ({ "-", "-", "+", }) }),
        "unicode": ({ ({ "#floor#\u2591", "#floor#\u2591", "\u2551" }),
            ({ "#floor#\u2591", "#floor#\u2591", "\u2551" }),
            ({ "\u2550", "\u2550", "\u255d" }) })
    ]),
    "ruined interior southeast corner south entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;251m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "#floor# ", "#floor# ", "|", }),
            ({ "#floor# ", "#floor# ", "|", }),
            ({ "-", "#door#/", "+", }) }),
        "unicode": ({ ({ "#floor#\u2591", "#floor#\u2591", "\u2551" }),
            ({ "#floor#\u2591", "#floor#\u2591", "\u2551" }),
            ({ "\u2557", "#door#\u2581", "\u2563" }) })
    ]),
    "ruined interior southeast corner east entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;251m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "#floor# ", "#floor# ", "|", }),
            ({ "#floor# ", "#floor# ", "#door#/", }),
            ({ "-", "-", "+", }) }),
        "unicode": ({ ({ "#floor#\u2591", "#floor#\u2591", "\u2560" }),
            ({ "#floor#\u2591", "#floor#\u2591", "#door#\u2503" }),
            ({ "\u2550", "\u2550", "\u2569" }) })
    ]),
    "ruined interior southeast corner south-east entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;251m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "#floor# ", "#floor# ", "|", }),
            ({ "#floor# ", "#floor# ", "#door#/", }),
            ({ "-", "#door#/", "+", }) }),
        "unicode": ({ ({ "#floor#\u2591", "#floor#\u2591", "\u2560" }),
            ({ "#floor#\u2591", "#floor#\u2591", "#door#\u2503" }),
            ({ "\u2557", "#door#\u2581", "\u256c" }) })
    ]),
    "ruined interior northeast corner": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "-", "-", "+", }),
            ({ "#floor# ", "#floor# ", "|", }),
            ({ "#floor# ", "#floor# ", "|", }) }),
        "unicode": ({ ({ "\u2550", "\u2550", "\u2557" }),
            ({ "#floor#\u2591", "#floor#\u2591", "\u2551" }),
            ({ "#floor#\u2591", "#floor#\u2591", "\u2551" }) })
    ]),
    "ruined interior northeast corner north entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;251m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#door#/", "+", }),
            ({ "#floor# ", "#floor# ", "|", }),
            ({ "#floor# ", "#floor# ", "+", }) }),
        "unicode": ({ ({ "\u2569", "#door#\u2594","\u2563" }),
            ({ "#floor#\u2591", "#floor#\u2591", "\u2551" }),
            ({ "#floor#\u2591", "#floor#\u2591", "\u2551" }) })
    ]),
    "ruined interior northeast corner east entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;251m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "-", "-", "+", }),
            ({ "#floor# ", "#floor# ", "#door#/", }),
            ({ "#floor# ", "#floor# ", "|", }) }),
        "unicode": ({ ({ "\u2550", "\u2550","\u2566" }),
            ({ "#floor#\u2591", "#floor#\u2591", "#door#\u2503" }),
            ({ "#floor#\u2591", "#floor#\u2591", "\u2560" }) })
    ]),
    "ruined interior northeast corner north-east entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;251m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#door#/", "+", }),
            ({ "#floor# ", "#floor# ", "#door#/", }),
            ({ "#floor# ", "#floor# ", "+", }) }),
        "unicode": ({ ({ "\u2569", "#door#\u2594","\u256c" }),
            ({ "#floor#\u2591", "#floor#\u2591", "#door#\u2503" }),
            ({ "#floor#\u2591", "#floor#\u2591", "\u2560" }) })
    ]),
    "ruined interior southwest corner": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "|", "#floor# ", "#floor# ", }),
            ({ "|", "#floor# ", "#floor# ", }),
            ({ "-", "-", "+", }) }),
        "unicode": ({ ({ "\u2551", "#floor#\u2591", "#floor#\u2591" }),
            ({ "\u2551", "#floor#\u2591", "#floor#\u2591", }),
            ({ "\u255a", "\u2550", "\u2550" }) })
    ]),
    "ruined interior southwest corner west entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;251m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#floor# ", "#floor# ", }),
            ({ "#door#\\", "#floor# ", "#floor# ", }),
            ({ "-", "-", "+", }) }),
        "unicode": ({ ({ "\u2563", "#floor#\u2591", "#floor#\u2591" }),
            ({ "#door#\u2503", "#floor#\u2591", "#floor#\u2591", }),
            ({ "\u2569", "\u2550", "\u2550" }) })
    ]),
    "ruined interior southwest corner south entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;251m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "|", "#floor# ", "#floor# ", }),
            ({ "|", "#floor# ", "#floor# ", }),
            ({ "-", "#door#/", "+", }) }),
        "unicode": ({ ({ "\u2551", "#floor#\u2591", "#floor#\u2591" }),
            ({ "\u2551", "#floor#\u2591", "#floor#\u2591", }),
            ({ "\u2560", "#door#\u2581", "\u2566" }) })
    ]),
    "ruined interior southwest corner south-west entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;251m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#floor# ", "#floor# ", }),
            ({ "#door#\\", "#floor# ", "#floor# ", }),
            ({ "+", "#door#/", "+", }) }),
        "unicode": ({ ({ "\u2563", "#floor#\u2591", "#floor#\u2591" }),
            ({ "#door#\u2503", "#floor#\u2591", "#floor#\u2591", }),
            ({ "\u256c", "#door#\u2581", "\u2566" }) })
    ]),
    "ruined interior northwest corner": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "+", "-", "-", }),
            ({ "|", "#floor# ", "#floor# ", }),
            ({ "|", "#floor# ", "#floor# ", }) }),
        "unicode": ({ ({ "\u2554", "\u2550", "\u2550" }),
            ({ "\u2551", "#floor#\u2591", "#floor#\u2591" }),
            ({ "\u2551", "#floor#\u2591", "#floor#\u2591" }) })
    ]),
    "ruined interior northwest corner west entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;251m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "-", "-", }),
            ({ "#door#\\", "#floor# ", "#floor# ", }),
            ({ "+", "#floor# ", "#floor# ", }) }),
        "unicode": ({ ({ "\u2566", "\u2550", "\u2550" }),
            ({ "#door#\u2503", "#floor#\u2591", "#floor#\u2591", }),
            ({ "\u2563", "#floor#\u2591", "#floor#\u2591" }) })
    ]),
    "ruined interior northwest corner north entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;251m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#door#\\", "+", }),
            ({ "|", "#floor# ", "#floor# ", }),
            ({ "|", "#floor# ", "#floor# ", }) }),
        "unicode": ({ ({ "\u2560", "#door#\u2594","\u2569" }),
            ({ "\u2551", "#floor#\u2591", "#floor#\u2591" }),
            ({ "\u2551", "#floor#\u2591", "#floor#\u2591" }) })
    ]),
    "ruined interior northwest corner north-west entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;251m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#door#\\", "+", }),
            ({ "#door#\\", "#floor# ", "#floor# ", }),
            ({ "+", "#floor# ", "#floor# ", }) }),
        "unicode": ({ ({ "\u256c", "#door#\u2594", "\u2569" }),
            ({ "#door#\u2503", "#floor#\u2591", "#floor#\u2591", }),
            ({ "\u2563", "#floor#\u2591", "#floor#\u2591" }) })
    ]),
    "ruined interior west wall": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "|", "#floor# ", "#floor# ", }),
            ({ "|", "#floor# ", "#floor# ", }),
            ({ "|", "#floor# ", "#floor# ", }) }),
        "unicode": ({ ({ "\u2551", "#floor#\u2591", "#floor#\u2591" }),
            ({ "\u2551", "#floor#\u2591", "#floor#\u2591" }),
            ({ "\u2551", "#floor#\u2591", "#floor#\u2591" }) })
    ]),
    "ruined interior west wall entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;251m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#floor# ", "#floor# " }),
            ({ "#door#/", "#floor# ", "#floor# " }),
            ({ "+", "#floor# ", "#floor# " }) }),
        "unicode": ({ ({ "\u2563", "#floor#\u2591", "#floor#\u2591" }),
            ({ "#door#\u2503", "#floor#\u2591", "#floor#\u2591" }),
            ({ "\u2563", "#floor#\u2591", "#floor#\u2591" }) })
    ]),
    "ruined interior east wall": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "#floor# ", "#floor# ", "|" }),
            ({ "#floor# ", "#floor# ", "|" }),
            ({ "#floor# ", "#floor# ", "|" }) }),
        "unicode": ({ ({ "#floor#\u2591", "#floor#\u2591", "\u2551" }),
            ({ "#floor#\u2591", "#floor#\u2591", "\u2551" }),
            ({ "#floor#\u2591", "#floor#\u2591", "\u2551" }) })
    ]),
    "ruined interior east wall entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;251m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "#floor# ", "#floor# ", "+", }),
            ({ "#floor# ", "#floor# ", "#door#/", }),
            ({ "#floor# ", "#floor# ", "+", }) }),
        "unicode": ({ ({ "#floor#\u2591", "#floor#\u2591", "\u2560" }),
            ({ "#floor#\u2591", "#floor#\u2591", "#door#\u2503" }),
            ({ "#floor#\u2591", "#floor#\u2591", "\u2560" }) })
    ]),
    "ruined interior north wall": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "=", "=", "=", }),
            ({ "#floor# ", "#floor# ", "#floor# ", }),
            ({ "#floor# ", "#floor# ", "#floor# ", }) }),
        "unicode": ({ ({ "\u2550", "\u2550", "\u2550" }),
            ({ "#floor#\u2591", "#floor#\u2591", "#floor#\u2591" }),
            ({ "#floor#\u2591", "#floor#\u2591", "#floor#\u2591" }) })
    ]),
    "ruined interior north wall entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;251m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#door#\\", "+", }),
            ({ "#floor# ", "#floor# ", "#floor# ", }),
            ({ "#floor# ", "#floor# ", "#floor# ", }) }),
        "unicode": ({ ({ "\u2569", "#door#\u2594", "\u2569" }),
            ({ "#floor#\u2591", "#floor#\u2591", "#floor#\u2591" }),
            ({ "#floor#\u2591", "#floor#\u2591", "#floor#\u2591" }) })
    ]),
    "ruined interior south wall": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "#floor# ", "#floor# ", "#floor# ", }),
            ({ "#floor# ", "#floor# ", "#floor# ", }),
            ({ "=", "=", "=", }) }),
        "unicode": ({ ({ "#floor#\u2591", "#floor#\u2591", "#floor#\u2591" }),
            ({ "#floor#\u2591", "#floor#\u2591", "#floor#\u2591" }),
            ({ "\u2550", "\u2550", "\u2550" }) })
    ]),
    "ruined interior south wall entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;251m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "#floor# ", "#floor# ", "#floor# ", }),
            ({ "#floor# ", "#floor# ", "#floor# ", }),
            ({ "+", "#door#\\", "+", }) }),
        "unicode": ({ ({ "#floor#\u2591", "#floor#\u2591", "#floor#\u2591" }),
            ({ "#floor#\u2591", "#floor#\u2591", "#floor#\u2591" }),
            ({ "\u2566", "#door#\u2581", "\u2566" }) })
    ]),
   "ruined interior floor": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ])
            ])
        ]),
        "ascii": ({ ({ "#floor# ", "#floor# ", "#floor# ", }),
            ({ "#floor# ", "#floor# ", "#floor# ", }),
            ({ "#floor# ", "#floor# ", "#floor# ", }) }),
        "unicode": ({ ({ "#floor#\u2591", "#floor#\u2591", "#floor#\u2591" }),
            ({ "#floor#\u2591", "#floor#\u2591", "#floor#\u2591" }),
            ({ "#floor#\u2591", "#floor#\u2591", "#floor#\u2591" }) })
    ]),
   "ruined interior courtyard": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "grass":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;236m",
                    "3-bit": "\x1b[0;32m",
                    "8-bit": "\x1b[0;38;5;22m",
                    "24-bit": "\x1b[0;38;2;30;50;20m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "#grass# ", "#grass# ", "#grass# ", }),
            ({ "#grass# ", "#grass# ", "#grass# ", }),
            ({ "#grass# ", "#grass# ", "#grass# ", }) }),
        "unicode": ({ ({ "#grass#\u2591", "#grass#\u2591", "#grass#\u2591" }),
            ({ "#grass#\u2591", "#grass#\u2591", "#grass#\u2591" }),
            ({ "#grass#\u2591", "#grass#\u2591", "#grass#\u2591" }) })
    ]),
   "ruined interior courtyard with path": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none":"",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit" : "\x1b[0;31m",
                    "8-bit" : "\x1b[0;38;5;234m",
                    "24-bit" : "\x1b[0;38;2;28;36;28m",
                ]),
                "grass":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;236m",
                    "3-bit": "\x1b[0;32m",
                    "8-bit": "\x1b[0;38;5;22m",
                    "24-bit": "\x1b[0;38;2;30;50;20m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "#grass# ", "#floor# ", "#grass# ", }),
            ({ "#floor# ", "#floor# ", "#floor# ", }),
            ({ "#grass# ", "#floor# ", "#grass# ", }) }),
        "unicode": ({ ({ "#grass#\u2591", "#floor#\u2591", "#grass#\u2591" }),
            ({ "#floor#\u2591", "#floor#\u2591", "#floor#\u2591" }),
            ({ "#grass#\u2591", "#floor#\u2591", "#grass#\u2591" }) })
    ]),

    "ruined interior courtyard with pillar": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "grass":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;236m",
                    "3-bit": "\x1b[0;32m",
                    "8-bit": "\x1b[0;38;5;22m",
                    "24-bit": "\x1b[0;38;2;30;50;20m",
                ]),
                "pillar":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;243;1m",
                    "3-bit": "\x1b[0;36;1m",
                    "8-bit": "\x1b[0;38;5;243;1m",
                    "24-bit": "\x1b[0;38;2;118;118;128;1m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "#grass# ", "#grass# ", "#grass# ", }),
            ({ "#grass# ", "#pillar#+", "#grass# ", }),
            ({ "#grass# ", "#grass# ", "#grass# ", }) }),
        "unicode": ({ ({ "#grass#\u2591", "#grass#\u2591", "#grass#\u2591" }),
            ({ "#grass#\u2591", "#pillar#\u25ce", "#grass#\u2591" }),
            ({ "#grass#\u2591", "#grass#\u2591", "#grass#\u2591" }) })
    ]),
    "ruined interior-to-exterior north-south hallway west exit": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "|", "#floor# ", "|", }),
            ({ "|", "#floor# ", "#floor# ", }),
            ({ "|", "#floor# ", "|", }) }),
        "unicode": ({ ({ "\u2551", "#floor#\u2591", "\u2568" }),
            ({ "\u2551", "#floor#\u2591", "#floor#\u2591" }),
            ({ "\u2551", "#floor#\u2591", "\u2565" }) })
    ]),
    "ruined interior-to-exterior north-south hallway east exit": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "|", "#floor# ", "|", }),
            ({ "#floor# ", "#floor# ", "|", }),
            ({ "|", "#floor# ", "|", }) }),
        "unicode": ({ ({ "\u2568", "#floor#\u2591", "\u2551" }),
            ({ "#floor#\u2591", "#floor#\u2591", "\u2551" }),
            ({ "\u2565", "#floor#\u2591", "\u2551" }) })
    ]),
    "ruined interior-to-exterior east-west hallway south exit": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "=", "=", "=", }),
            ({ "#floor# ", "#floor# ", "#floor# ", }),
            ({ "+", "#floor# ", "+", }) }),
        "unicode": ({ ({ "\u2550", "\u2550", "\u2550" }),
            ({ "#floor#\u2591", "#floor#\u2591", "#floor#\u2591" }),
            ({ "\u2561", "#floor#\u2591", "\u255e" }) })
    ]),
    "ruined interior-to-exterior north-corner hallway east exit": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "+", "=", "=", }),
            ({ "|", "#floor# ", "#floor# ", }),
            ({ "|", "#floor# ", "|", }) }),
        "unicode": ({ ({ "\u2554", "\u2550", "\u2566" }),
            ({ "\u2551", "#floor#\u2591", "#floor#\u2591" }),
            ({ "\u2551", "#floor#\u2591", "\u2565" }) })
    ]),
    "ruined interior-to-exterior north-corner hallway west exit": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;28;36;28m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "=", "=", "+", }),
            ({ "#floor# ", "#floor# ", "|", }),
            ({ "|", "#floor# ", "|", }) }),
        "unicode": ({ ({ "\u2566", "\u2550", "\u2557" }),
            ({ "#floor#\u2591", "#floor#\u2591", "\u2551" }),
            ({ "\u2565", "#floor#\u2591", "\u2551" }) })
    ]),

    // Other locations
    "ruined interior south gatehouse": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "pillar":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;243;1m",
                    "3-bit": "\x1b[0;36;1m",
                    "8-bit": "\x1b[0;38;5;243;1m",
                    "24-bit": "\x1b[0;38;2;118;118;128;1m",
                ]),
                "portcullis":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;238m",
                    "3-bit": "\x1b[0;31;1m",
                    "8-bit": "\x1b[0;38;5;238m",
                    "24-bit": "\x1b[0;38;2;72;38;38m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;251m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;100m",
                    "24-bit": "\x1b[0;38;2;102;102;38m",
                ])
            ])
        ]),
        "ascii": ({ ({ "#pillar#+", " ", "#pillar#+", }),
            ({ "+", "#portcullis#-", "+", }),
            ({ "+", "#door#-", "+", }) }),
        "unicode": ({ ({ "#pillar#\u25ce", " ", "#pillar#\u25ce" }),
            ({ "\u2554", "#portcullis#\u254c", "\u2557" }),
            ({ "\u256c", "#door#\u2581", "\u256c" }) })
    ]),
    "ruined interior large staired entrance right": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "pillar":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;243;1m",
                    "3-bit": "\x1b[0;36;1m",
                    "8-bit": "\x1b[0;38;5;243;1m",
                    "24-bit": "\x1b[0;38;2;118;118;128;1m",
                ]),
                "stairs":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;237m",
                    "3-bit": "\x1b[0;31;1m",
                    "8-bit": "\x1b[0;38;5;237m",
                    "24-bit": "\x1b[0;38;2;40;42;45m",
                ]),
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;8;10;12m",
                ]),
                "floor2":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;240m",
                    "3-bit": "\x1b[0;30;1m",
                    "8-bit": "\x1b[0;38;5;23m",
                    "24-bit": "\x1b[0;38;2;8;12;8m",
                ]),
                "grass":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;236m",
                    "3-bit": "\x1b[0;32m",
                    "8-bit": "\x1b[0;38;5;22m",
                    "24-bit": "\x1b[0;38;2;30;50;20m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "#grass# ", "#grass# ", "#grass# ", }),
            ({ "#floor# ", "#floor2# ", "#floor# ", }),
            ({ "#stairs#-", "#stairs#-", "#pillar#+", }) }),
        "unicode": ({ ({ "#grass#\u2591", "#grass#\u2591", "#grass#\u2591" }),
            ({ "#floor#\u2585", "#floor2#\u2585", "#floor#\u2585" }),
            ({ "#stairs#\u2338", "#stairs#\u2338", "#pillar#\u238a" }) })
    ]),
    "ruined interior large staired entrance left": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;235m",
            "24-bit": "\x1b[0;38;2;56;62;56m",
            "icons": ([
                "stairs":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;237m",
                    "3-bit": "\x1b[0;31;1m",
                    "8-bit": "\x1b[0;38;5;237m",
                    "24-bit": "\x1b[0;38;2;40;42;45m",
                ]),
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;234m",
                    "3-bit": "\x1b[0;31m",
                    "8-bit": "\x1b[0;38;5;234m",
                    "24-bit": "\x1b[0;38;2;8;10;12m",
                ]),
                "floor2":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;240m",
                    "3-bit": "\x1b[0;30;1m",
                    "8-bit": "\x1b[0;38;5;23m",
                    "24-bit": "\x1b[0;38;2;8;12;8m",
                ]),
                "grass":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;236m",
                    "3-bit": "\x1b[0;32m",
                    "8-bit": "\x1b[0;38;5;22m",
                    "24-bit": "\x1b[0;38;2;30;50;20m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "#grass# ", "#grass# ", "#grass# ", }),
            ({ "#floor# ", "#floor2# ", "#floor# ", }),
            ({ "#stairs#-", "#stairs#-", "#stairs#-", }) }),
        "unicode": ({ ({ "#grass#\u2591", "#grass#\u2591", "#grass#\u2591" }),
            ({ "#floor2#\u2585", "#floor#\u2585", "#floor2#\u2585" }),
            ({ "#stairs#\u2338", "#stairs#\u2338", "#stairs#\u2338" }) })
    ]),
    "ruined interior amethyst floor": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;233m",
            "3-bit": "\x1b[0;30m",
            "8-bit": "\x1b[0;38;5;233m",
            "24-bit": "\x1b[0;38;2;26;20;26m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;236m",
                    "3-bit": "\x1b[0;35m",
                    "8-bit": "\x1b[0;38;5;53m",
                    "24-bit": "\x1b[0;38;2;96;0;102m",
                ])
            ])
        ]),
        "ascii": ({ ({ "#floor#:", "#floor#:", "#floor#:", }),
            ({ "#floor#:", "#floor#:", "#floor#:", }),
            ({ "#floor#:", "#floor#:", "#floor#:", }) }),
        "unicode": ({ ({ "#floor#\u2591", "#floor#\u2591", "#floor#\u2591" }),
            ({ "#floor#\u2591", "#floor#\u2591", "#floor#\u2591" }),
            ({ "#floor#\u2591", "#floor#\u2591", "#floor#\u2591" }) })
    ]),
    "ruined interior amethyst floor west south": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;233m",
            "3-bit": "\x1b[0;30m",
            "8-bit": "\x1b[0;38;5;233m",
            "24-bit": "\x1b[0;38;2;26;20;26m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;236m",
                    "3-bit": "\x1b[0;35m",
                    "8-bit": "\x1b[0;38;5;53m",
                    "24-bit": "\x1b[0;38;2;96;0;102m",
                ])
            ])
        ]),
        "ascii": ({ ({ "#floor#:", "#floor#:", "#floor#:", }),
            ({ " ", " ", "#floor#:", }),
            ({ "#floor#:", " ", "#floor#:", }) }),
        "unicode": ({ ({ "#floor#\u2591", "#floor#\u2591", "#floor#\u2591" }),
            ({ "\u2591", "\u2591", "#floor#\u2591" }),
            ({ "#floor#\u2591", "\u2591", "#floor#\u2591" }) })
    ]),
    "ruined interior amethyst floor west east": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;233m",
            "3-bit": "\x1b[0;30m",
            "8-bit": "\x1b[0;38;5;233m",
            "24-bit": "\x1b[0;38;2;26;20;26m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;236m",
                    "3-bit": "\x1b[0;35m",
                    "8-bit": "\x1b[0;38;5;53m",
                    "24-bit": "\x1b[0;38;2;96;0;102m",
                ])
            ])
        ]),
        "ascii": ({ ({ "#floor#:", "#floor#:", "#floor#:", }),
            ({ " ", " ", " ", }),
            ({ "#floor#:", "#floor#:", "#floor#:", }) }),
        "unicode": ({ ({ "#floor#\u2591", "#floor#\u2591", "#floor#\u2591" }),
            ({ "\u2591", "\u2591", "\u2591" }),
            ({ "#floor#\u2591", "#floor#\u2591", "#floor#\u2591" }) })
    ]),
    "ruined interior amethyst floor west north": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;233m",
            "3-bit": "\x1b[0;30m",
            "8-bit": "\x1b[0;38;5;233m",
            "24-bit": "\x1b[0;38;2;26;20;26m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;236m",
                    "3-bit": "\x1b[0;35m",
                    "8-bit": "\x1b[0;38;5;53m",
                    "24-bit": "\x1b[0;38;2;96;0;102m",
                ])
            ])
        ]),
        "ascii": ({ ({ "#floor#:", " ", "#floor#:", }),
            ({ " ", " ", "#floor#:", }),
            ({ "#floor#:", "#floor#:", "#floor#:", }) }),
        "unicode": ({ ({ "#floor#\u2591", "\u2591", "#floor#\u2591" }),
            ({ "\u2591", "\u2591", "#floor#\u2591" }),
            ({ "#floor#\u2591", "#floor#\u2591", "#floor#\u2591" }) })
    ]),
    "ruined interior amethyst floor west east south": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;233m",
            "3-bit": "\x1b[0;30m",
            "8-bit": "\x1b[0;38;5;233m",
            "24-bit": "\x1b[0;38;2;26;20;26m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;236m",
                    "3-bit": "\x1b[0;35m",
                    "8-bit": "\x1b[0;38;5;53m",
                    "24-bit": "\x1b[0;38;2;96;0;102m",
                ])
            ])
        ]),
        "ascii": ({ ({ "#floor#:", "#floor#:", "#floor#:", }),
            ({ " ", " ", " ", }),
            ({ "#floor#:", " ", "#floor#:", }) }),
        "unicode": ({ ({ "#floor#\u2591", "#floor#\u2591", "#floor#\u2591" }),
            ({ "\u2591", "\u2591", "\u2591" }),
            ({ "#floor#\u2591", "\u2591", "#floor#\u2591" }) })
    ]),
    "ruined interior amethyst floor west east north": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;233m",
            "3-bit": "\x1b[0;30m",
            "8-bit": "\x1b[0;38;5;233m",
            "24-bit": "\x1b[0;38;2;26;20;26m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;236m",
                    "3-bit": "\x1b[0;35m",
                    "8-bit": "\x1b[0;38;5;53m",
                    "24-bit": "\x1b[0;38;2;96;0;102m",
                ])
            ])
        ]),
        "ascii": ({ ({ "#floor#:", " ", "#floor#:", }),
            ({ " ", " ", " ", }),
            ({ "#floor#:", "#floor#:", "#floor#:", }) }),
        "unicode": ({ ({ "#floor#\u2591", "\u2591", "#floor#\u2591" }),
            ({ "\u2591", "\u2591", "\u2591" }),
            ({ "#floor#\u2591", "#floor#\u2591", "#floor#\u2591" }) })
    ]),
    "ruined interior amethyst floor west east north south": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;233m",
            "3-bit": "\x1b[0;30m",
            "8-bit": "\x1b[0;38;5;233m",
            "24-bit": "\x1b[0;38;2;26;20;26m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;236m",
                    "3-bit": "\x1b[0;35m",
                    "8-bit": "\x1b[0;38;5;53m",
                    "24-bit": "\x1b[0;38;2;96;0;102m",
                ])
            ])
        ]),
        "ascii": ({ ({ "#floor#:", " ", "#floor#:", }),
            ({ " ", " ", " ", }),
            ({ "#floor#:", " ", "#floor#:", }) }),
        "unicode": ({ ({ "#floor#\u2591", "\u2591", "#floor#\u2591" }),
            ({ "\u2591", "\u2591", "\u2591" }),
            ({ "#floor#\u2591", "\u2591", "#floor#\u2591" }) })
    ]),
    "ruined interior amethyst floor east north": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;233m",
            "3-bit": "\x1b[0;30m",
            "8-bit": "\x1b[0;38;5;233m",
            "24-bit": "\x1b[0;38;2;26;20;26m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;236m",
                    "3-bit": "\x1b[0;35m",
                    "8-bit": "\x1b[0;38;5;53m",
                    "24-bit": "\x1b[0;38;2;96;0;102m",
                ])
            ])
        ]),
        "ascii": ({ ({ "#floor#:", " ", "#floor#:", }),
            ({ "#floor#:", " ", " ", }),
            ({ "#floor#:", "#floor#:", "#floor#:", }) }),
        "unicode": ({ ({ "#floor#\u2591", "\u2591", "#floor#\u2591" }),
            ({ "#floor#\u2591", "\u2591", "\u2591" }),
            ({ "#floor#\u2591", "#floor#\u2591", "#floor#\u2591" }) })
    ]),
    "ruined interior amethyst floor east south": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;233m",
            "3-bit": "\x1b[0;30m",
            "8-bit": "\x1b[0;38;5;233m",
            "24-bit": "\x1b[0;38;2;26;20;26m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;236m",
                    "3-bit": "\x1b[0;35m",
                    "8-bit": "\x1b[0;38;5;53m",
                    "24-bit": "\x1b[0;38;2;96;0;102m",
                ])
            ])
        ]),
        "ascii": ({ ({ "#floor#:", "#floor#:", "#floor#:", }),
            ({ "#floor#:", " ", " ", }),
            ({ "#floor#:", " ", "#floor#:", }) }),
        "unicode": ({ ({ "#floor#\u2591", "#floor#\u2591", "#floor#\u2591" }),
            ({ "#floor#\u2591", "\u2591", "\u2591" }),
            ({ "#floor#\u2591", "\u2591", "#floor#\u2591" }) })
    ]),
    "ruined interior amethyst floor east north south": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;233m",
            "3-bit": "\x1b[0;30m",
            "8-bit": "\x1b[0;38;5;233m",
            "24-bit": "\x1b[0;38;2;26;20;26m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;236m",
                    "3-bit": "\x1b[0;35m",
                    "8-bit": "\x1b[0;38;5;53m",
                    "24-bit": "\x1b[0;38;2;96;0;102m",
                ])
            ])
        ]),
        "ascii": ({ ({ "#floor#:", " ", "#floor#:", }),
            ({ "#floor#:", " ", " ", }),
            ({ "#floor#:", " ", "#floor#:", }) }),
        "unicode": ({ ({ "#floor#\u2591", "\u2591", "#floor#\u2591" }),
            ({ "#floor#\u2591", "\u2591", "\u2591" }),
            ({ "#floor#\u2591", "\u2591", "#floor#\u2591" }) })
    ]),
    "ruined interior amethyst floor north south": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;233m",
            "3-bit": "\x1b[0;30m",
            "8-bit": "\x1b[0;38;5;233m",
            "24-bit": "\x1b[0;38;2;26;20;26m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;236m",
                    "3-bit": "\x1b[0;35m",
                    "8-bit": "\x1b[0;38;5;53m",
                    "24-bit": "\x1b[0;38;2;96;0;102m",
                ])
            ])
        ]),
        "ascii": ({ ({ "#floor#:", " ", "#floor#:", }),
            ({ "#floor#:", " ", "#floor#:", }),
            ({ "#floor#:", " ", "#floor#:", }) }),
        "unicode": ({ ({ "#floor#\u2591", "\u2591", "#floor#\u2591" }),
            ({ "#floor#\u2591", "\u2591", "#floor#\u2591" }),
            ({ "#floor#\u2591", "\u2591", "#floor#\u2591" }) })
    ]),

]);

#endif
