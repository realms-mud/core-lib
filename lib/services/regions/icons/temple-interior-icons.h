//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef templeInteriorIcons_h
#define templeInteriorIcons_h

private mapping TempleInteriorIcons = ([
    // Basic hallways and T-intersections
    "temple interior west T-intersection": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
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
    "temple interior west T-intersection east entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;220m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;220m",
                    "24-bit": "\x1b[0;38;2;218;165;32m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#floor# ", "+", }),
            ({ "#floor# ", "#floor# ", "#door#/", }),
            ({ "+", "#floor# ", "+", }) }),
        "unicode": ({ ({ "\u255d", "#floor#\u2591", "\u255a" }),
            ({ "#floor#\u2591", "#floor#\u2591", "#door#\u2503" }),
            ({ "\u2557", "#floor#\u2591", "\u2554" }) })
    ]),
    "temple interior east T-intersection": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
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
    "temple interior east T-intersection west entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;220m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;220m",
                    "24-bit": "\x1b[0;38;2;218;165;32m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#floor# ", "+", }),
            ({ "#door#/", "#floor# ", "#floor# ", }),
            ({ "+", "#floor# ", "+", }) }),
        "unicode": ({ ({ "\u255d", "#floor#\u2591", "\u255a" }),
            ({ "#door#\u2503", "#floor#\u2591", "#floor#\u2591" }),
            ({ "\u2557", "#floor#\u2591", "\u2554" }) })
    ]),
    "temple interior south T-intersection": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
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
    "temple interior south T-intersection north entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;220m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;220m",
                    "24-bit": "\x1b[0;38;2;218;165;32m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#door#\\", "+", }),
            ({ "#floor# ", "#floor# ", "#floor# ", }),
            ({ "+", "#floor# ", "+", }) }),
        "unicode": ({ ({ "\u255d", "#door#\u2594", "\u255a" }),
            ({ "#floor#\u2591", "#floor#\u2591", "#floor#\u2591" }),
            ({ "\u2557", "#floor#\u2591", "\u2554" }) })
    ]),
    "temple interior north T-intersection": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
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
    "temple interior north T-intersection south entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;220m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;220m",
                    "24-bit": "\x1b[0;38;2;218;165;32m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#floor# ", "+", }),
            ({ "#floor# ", "#floor# ", "#floor# ", }),
            ({ "+", "#door#\\", "+", }) }),
        "unicode": ({ ({ "\u255d", "#floor#\u2591", "\u255a" }),
            ({ "#floor#\u2591", "#floor#\u2591", "#floor#\u2591" }),
            ({ "\u2557", "#door#\u2581", "\u2554" }) })
    ]),
    "temple interior north-west corner hallway": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "+", "#floor# ", "|", }),
            ({ "#floor# ", "#floor# ", "|", }),
            ({ "=", "=", "+", }) }),
        "unicode": ({ ({ "\u255d", "#floor#\u2591", "\u2551" }),
            ({ "#floor#\u2591", "#floor#\u2591", "\u2551" }),
            ({ "\u2550", "\u2550", "\u255d" }) })
    ]),
    "temple interior north-west corner hallway south entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;220m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;220m",
                    "24-bit": "\x1b[0;38;2;218;165;32m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#floor# ", "|", }),
            ({ "#floor# ", "#floor# ", "|", }),
            ({ "=", "#door#\\", "+", }) }),
        "unicode": ({ ({ "\u255d", "#floor#\u2591", "\u2551" }),
            ({ "#floor#\u2591", "#floor#\u2591", "\u2551" }),
            ({ "\u2557", "#door#\u2581", "\u2563" }) })
    ]),
    "temple interior north-west corner hallway east entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;220m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;220m",
                    "24-bit": "\x1b[0;38;2;218;165;32m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#floor# ", "+", }),
            ({ "#floor# ", "#floor# ", "#door#/", }),
            ({ "=", "=", "+", }) }),
        "unicode": ({ ({ "\u255d", "#floor#\u2591", "\u2560" }),
            ({ "#floor#\u2591", "#floor#\u2591", "#door#\u2503" }),
            ({ "\u2550", "\u2550", "\u2569" }) })
    ]),
    "temple interior north-west corner hallway south-east entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;220m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;220m",
                    "24-bit": "\x1b[0;38;2;218;165;32m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#floor# ", "+", }),
            ({ "#floor# ", "#floor# ", "#door#/", }),
            ({ "=", "#door#\\", "+", }) }),
        "unicode": ({ ({ "\u255d", "#floor#\u2591", "\u2560" }),
            ({ "#floor#\u2591", "#floor#\u2591", "#door#\u2503" }),
            ({ "\u2557", "#door#\u2581", "\u256c" }) })
    ]),
    "temple interior south-west corner hallway": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "=", "=", "+", }),
            ({ "#floor# ", "#floor# ", "|", }),
            ({ "+", "#floor# ", "|", }) }),
        "unicode": ({ ({ "\u2550", "\u2550", "\u2557" }),
            ({ "#floor#\u2591", "#floor#\u2591", "\u2551" }),
            ({ "\u2557", "#floor#\u2591", "\u2551" }) })
    ]),
    "temple interior south-west corner hallway north entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;220m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;220m",
                    "24-bit": "\x1b[0;38;2;218;165;32m",
                ])
            ])
        ]),
        "ascii": ({ ({ "=", "#door#\\", "+", }),
            ({ "#floor# ", "#floor# ", "|", }),
            ({ "+", "#floor# ", "|", }) }),
        "unicode": ({ ({ "\u2569", "#door#\u2594","\u2563" }),
            ({ "#floor#\u2591", "#floor#\u2591", "\u2551" }),
            ({ "\u2557", "#floor#\u2591", "\u2551" }) })
    ]),
    "temple interior south-west corner hallway east entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;220m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;220m",
                    "24-bit": "\x1b[0;38;2;218;165;32m",
                ])
            ])
        ]),
        "ascii": ({ ({ "=", "=", "+", }),
            ({ "#floor# ", "#floor# ", "#door#/", }),
            ({ "+", "#floor# ", "|", }) }),
        "unicode": ({ ({ "\u2550", "\u2550","\u2566" }),
            ({ "#floor#\u2591", "#floor#\u2591", "#door#\u2503" }),
            ({ "\u2557", "#floor#\u2591", "\u2560" }) })
    ]),
    "temple interior south-west corner hallway north-east entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;220m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;220m",
                    "24-bit": "\x1b[0;38;2;218;165;32m",
                ])
            ])
        ]),
        "ascii": ({ ({ "=", "#door#\\", "+", }),
            ({ "#floor# ", "#floor# ", "#door#/", }),
            ({ "+", "#floor# ", "|", }) }),
        "unicode": ({ ({ "\u2569", "#door#\u2594","\u256c" }),
            ({ "#floor#\u2591", "#floor#\u2591", "#door#\u2503" }),
            ({ "\u2557", "#floor#\u2591", "\u2560" }) })
    ]),
    "temple interior north-east corner hallway": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "|", "#floor# ", "+", }),
            ({ "|", "#floor# ", "#floor# ", }),
            ({ "=", "=", "+", }) }),
        "unicode": ({ ({ "\u2551", "#floor#\u2591", "\u255a" }),
            ({ "\u2551", "#floor#\u2591", "#floor#\u2591", }),
            ({ "\u255a", "\u2550", "\u2550" }) })
    ]),
    "temple interior north-east corner hallway west entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;220m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;220m",
                    "24-bit": "\x1b[0;38;2;218;165;32m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#floor# ", "+", }),
            ({ "#door#/", "#floor# ", "#floor# ", }),
            ({ "=", "=", "+", }) }),
        "unicode": ({ ({ "\u2563", "#floor#\u2591", "\u255a" }),
            ({ "#door#\u2503", "#floor#\u2591", "#floor#\u2591", }),
            ({ "\u2569", "\u2550", "\u2550" }) })
    ]),
    "temple interior north-east corner hallway south entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;220m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;220m",
                    "24-bit": "\x1b[0;38;2;218;165;32m",
                ])
            ])
        ]),
        "ascii": ({ ({ "|", "#floor# ", "+", }),
            ({ "|", "#floor# ", "#floor# ", }),
            ({ "=", "#door#\\", "+", }) }),
        "unicode": ({ ({ "\u2551", "#floor#\u2591", "\u255a" }),
            ({ "\u2551", "#floor#\u2591", "#floor#\u2591", }),
            ({ "\u2560", "#door#\u2581", "\u2566" }) })
    ]),
    "temple interior north-east corner hallway south-west entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;220m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;220m",
                    "24-bit": "\x1b[0;38;2;218;165;32m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#floor# ", "+", }),
            ({ "#door#/", "#floor# ", "#floor# ", }),
            ({ "=", "#door#\\", "+", }) }),
        "unicode": ({ ({ "\u2563", "#floor#\u2591", "\u255a" }),
            ({ "#door#\u2503", "#floor#\u2591", "#floor#\u2591", }),
            ({ "\u256c", "#door#\u2581", "\u2566" }) })
    ]),
    "temple interior south-east corner hallway": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "=", "=", "+", }),
            ({ "#floor# ", "#floor# ", "|", }),
            ({ "+", "#floor# ", "|", }) }),
        "unicode": ({ ({ "\u2554", "\u2550", "\u2550" }),
            ({ "#floor#\u2591", "#floor#\u2591", "\u2551" }),
            ({ "\u2551", "#floor#\u2591", "\u2554" }) })
    ]),
    "temple interior south-east corner hallway west entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;220m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;220m",
                    "24-bit": "\x1b[0;38;2;218;165;32m",
                ])
            ])
        ]),
        "ascii": ({ ({ "=", "=", "+", }),
            ({ "#door#/", "#floor# ", "|", }),
            ({ "+", "#floor# ", "|", }) }),
        "unicode": ({ ({ "\u2566", "\u2550", "\u2550" }),
            ({ "#door#\u2503", "#floor#\u2591", "\u2551" }),
            ({ "\u2563", "#floor#\u2591", "\u2554" }) })
    ]),
    "temple interior south-east corner hallway north entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;220m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;220m",
                    "24-bit": "\x1b[0;38;2;218;165;32m",
                ])
            ])
        ]),
        "ascii": ({ ({ "=", "#door#\\", "+", }),
            ({ "#floor# ", "#floor# ", "|", }),
            ({ "+", "#floor# ", "|", }) }),
        "unicode": ({ ({ "\u2560", "#door#\u2594","\u2569" }),
            ({ "#floor#\u2591", "#floor#\u2591", "\u2551" }),
            ({ "\u2551", "#floor#\u2591", "\u2554" }) })
    ]),
    "temple interior south-east corner hallway north-west entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;220m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;220m",
                    "24-bit": "\x1b[0;38;2;218;165;32m",
                ])
            ])
        ]),
        "ascii": ({ ({ "=", "#door#\\", "+", }),
            ({ "#door#/", "#floor# ", "|", }),
            ({ "+", "#floor# ", "|", }) }),
        "unicode": ({ ({ "\u256c", "#door#\u2594", "\u2569" }),
            ({ "#door#\u2503", "#floor#\u2591", "\u2551" }),
            ({ "\u2563", "#floor#\u2591", "\u2554" }) })
    ]),

    // North alcove variants
    "temple interior north entry alcove": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;220m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;220m",
                    "24-bit": "\x1b[0;38;2;218;165;32m",
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
    "temple interior north-east entry alcove": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;220m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;220m",
                    "24-bit": "\x1b[0;38;2;218;165;32m",
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
    "temple interior north-west entry alcove": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;220m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;220m",
                    "24-bit": "\x1b[0;38;2;218;165;32m",
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
    "temple interior north-east-west entry alcove": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;220m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;220m",
                    "24-bit": "\x1b[0;38;2;218;165;32m",
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
    "temple interior north alcove west entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;220m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;220m",
                    "24-bit": "\x1b[0;38;2;218;165;32m",
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
    "temple interior north alcove east entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;220m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;220m",
                    "24-bit": "\x1b[0;38;2;218;165;32m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "+", "+", }),
            ({ "|", "#floor# ", "#door#/", }),
            ({ "|", "#floor# ", "+", }) }),
        "unicode": ({ ({ "\u2554", "\u2550", "\u256c" }),
            ({ "\u2551", "#floor#\u2591", "#door#\u2503" }),
            ({ "\u2551", "#floor#\u2591", "\u256c" }) })
    ]),
    "temple interior north alcove east-west entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;220m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;220m",
                    "24-bit": "\x1b[0;38;2;218;165;32m",
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

    // South alcove variants
    "temple interior south entry alcove": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;220m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;220m",
                    "24-bit": "\x1b[0;38;2;218;165;32m",
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
    "temple interior south-east entry alcove": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;220m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;220m",
                    "24-bit": "\x1b[0;38;2;218;165;32m",
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
    "temple interior south-west entry alcove": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;220m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;220m",
                    "24-bit": "\x1b[0;38;2;218;165;32m",
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
    "temple interior south-east-west entry alcove": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;220m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;220m",
                    "24-bit": "\x1b[0;38;2;218;165;32m",
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
    "temple interior south alcove west entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;220m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;220m",
                    "24-bit": "\x1b[0;38;2;218;165;32m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#floor# ", "|", }),
            ({ "#door#/", "#floor# ", "|", }),
            ({ "+", "=", "+", }) }),
        "unicode": ({ ({ "\u256c", "#floor#\u2591", "\u2551" }),
            ({ "#door#\u2503", "#floor#\u2591", "\u2551" }),
            ({ "\u256c", "\u2550", "\u255d" }) })
    ]),
    "temple interior south alcove east entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;220m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;220m",
                    "24-bit": "\x1b[0;38;2;218;165;32m",
                ])
            ])
        ]),
        "ascii": ({ ({ "|", "#floor# ", "+", }),
            ({ "|", "#floor# ", "#door#/", }),
            ({ "+", "=", "+", }) }),
        "unicode": ({ ({ "\u2551", "#floor#\u2591", "\u256c" }),
            ({ "\u2551", "#floor#\u2591", "#door#\u2503" }),
            ({ "\u255a", "\u2550", "\u256c" }) })
    ]),
    "temple interior south alcove east-west entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;220m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;220m",
                    "24-bit": "\x1b[0;38;2;218;165;32m",
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

    // West alcove variants
    "temple interior west entry alcove": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;220m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;220m",
                    "24-bit": "\x1b[0;38;2;218;165;32m",
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
    "temple interior west-north entry alcove": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;220m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;220m",
                    "24-bit": "\x1b[0;38;2;218;165;32m",
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
    "temple interior west-south entry alcove": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;220m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;220m",
                    "24-bit": "\x1b[0;38;2;218;165;32m",
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
    "temple interior west-south-north entry alcove": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;220m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;220m",
                    "24-bit": "\x1b[0;38;2;218;165;32m",
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
    "temple interior west alcove north entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;220m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;220m",
                    "24-bit": "\x1b[0;38;2;218;165;32m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#door#\\", "+", }),
            ({ "|", "#floor# ", "#floor# ", }),
            ({ "+", "=", "=", }) }),
        "unicode": ({ ({ "\u256c", "#door#\u2594", "\u2569" }),
            ({ "\u2551", "#floor#\u2591", "#floor#\u2591" }),
            ({ "\u255a", "\u2550", "\u2550" }) })
    ]),
    "temple interior west alcove south entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;220m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;220m",
                    "24-bit": "\x1b[0;38;2;218;165;32m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "=", "=", }),
            ({ "|", "#floor# ", "#floor# ", }),
            ({ "+", "#door#\\", "+", }) }),
        "unicode": ({ ({ "\u2554", "\u2550", "\u2550" }),
            ({ "\u2551", "#floor#\u2591", "#floor#\u2591" }),
            ({ "\u256c", "#door#\u2581", "\u2566" }) })
    ]),
    "temple interior west alcove north-south entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;220m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;220m",
                    "24-bit": "\x1b[0;38;2;218;165;32m",
                ])
            ])
        ]),
            "ascii": ({ ({ "+", "#door#\\", "+" }),
            ({ "|", "#floor# ", "#floor# ", }),
            ({ "+", "#door#\\", "+" }) }),
        "unicode": ({ ({ "\u256c", "#door#\u2594", "\u2569" }),
            ({ "\u2551", "#floor#\u2591", "#floor#\u2591" }),
            ({ "\u255a", "\u2550", "\u2550" }) })
    ]),
    "temple interior south-east corner hallway west entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;220m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;220m",
                    "24-bit": "\x1b[0;38;2;218;165;32m",
                ])
            ])
        ]),
        "ascii": ({ ({ "=", "=", "+", }),
            ({ "#door#/", "#floor# ", "|", }),
            ({ "+", "#floor# ", "|", }) }),
        "unicode": ({ ({ "\u2566", "\u2550", "\u2550" }),
            ({ "#door#\u2503", "#floor#\u2591", "\u2551" }),
            ({ "\u2563", "#floor#\u2591", "\u2554" }) })
    ]),
    "temple interior south-east corner hallway north entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;220m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;220m",
                    "24-bit": "\x1b[0;38;2;218;165;32m",
                ])
            ])
        ]),
        "ascii": ({ ({ "=", "#door#\\", "+", }),
            ({ "#floor# ", "#floor# ", "|", }),
            ({ "+", "#floor# ", "|", }) }),
        "unicode": ({ ({ "\u2560", "#door#\u2594","\u2569" }),
            ({ "#floor#\u2591", "#floor#\u2591", "\u2551" }),
            ({ "\u2551", "#floor#\u2591", "\u2554" }) })
    ]),
    "temple interior south-east corner hallway north-west entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;220m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;220m",
                    "24-bit": "\x1b[0;38;2;218;165;32m",
                ])
            ])
        ]),
        "ascii": ({ ({ "=", "#door#\\", "+", }),
            ({ "#door#/", "#floor# ", "|", }),
            ({ "+", "#floor# ", "|", }) }),
        "unicode": ({ ({ "\u256c", "#door#\u2594", "\u2569" }),
            ({ "#door#\u2503", "#floor#\u2591", "\u2551" }),
            ({ "\u2563", "#floor#\u2591", "\u2554" }) })
    ]),

    // East alcove variants
    "temple interior east entry alcove": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;220m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;220m",
                    "24-bit": "\x1b[0;38;2;218;165;32m",
                ])
            ])
        ]),
        "ascii": ({ ({ "=", "=", "+", }),
            ({ "#floor# ", "#floor# ", "#door#/", }),
            ({ "=", "=", "+", }) }),
        "unicode": ({ ({ "\u2550", "\u2550", "\u256c", }),
            ({ "#floor#\u2591", "#floor#\u2591", "#door#\u2503", }),
            ({ "\u2550", "\u2550","\u256c", }) })
    ]),
    "temple interior east-south entry alcove": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;220m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;220m",
                    "24-bit": "\x1b[0;38;2;218;165;32m",
                ])
            ])
        ]),
        "ascii": ({ ({ "=", "=", "+", }),
            ({ "#floor# ", "#floor# ", "#door#/", }),
            ({ "+", "#door#\\", "=", }) }),
        "unicode": ({ ({ "\u2550", "\u2550", "\u256c", }),
            ({ "#floor#\u2591", "#floor#\u2591", "#door#\u2503", }),
            ({ "\u2566", "#door#\u2581","\u256c", }) })
    ]),
    "temple interior east-north entry alcove": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;220m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;220m",
                    "24-bit": "\x1b[0;38;2;218;165;32m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#door#\\", "=", }),
            ({ "#floor# ", "#floor# ", "#door#/", }),
            ({ "=", "=", "+", }) }),
        "unicode": ({ ({ "\u2569", "#door#\u2594", "\u256c", }),
            ({ "#floor#\u2591", "#floor#\u2591", "#door#\u2503", }),
            ({ "\u2550", "\u2550", "\u256c", }) })
    ]),
    "temple interior east-south-north entry alcove": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;220m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;220m",
                    "24-bit": "\x1b[0;38;2;218;165;32m",
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
    "temple interior east alcove north entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;220m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;220m",
                    "24-bit": "\x1b[0;38;2;218;165;32m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#door#\\", "+", }),
            ({ "#floor# ", "#floor# ", "|", }),
            ({ "=", "=", "+", }) }),
        "unicode": ({ ({ "\u2569", "#door#\u2594", "\u256c" }),
            ({ "#floor#\u2591", "#floor#\u2591", "\u2551" }),
            ({ "\u2566", "#door#\u2581","\u256c" }) })
    ]),
    "temple interior east alcove south entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;220m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;220m",
                    "24-bit": "\x1b[0;38;2;218;165;32m",
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
    "temple interior east alcove north-south entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;220m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;220m",
                    "24-bit": "\x1b[0;38;2;218;165;32m",
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

    // Large room corners
    "temple interior southeast corner": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "#floor# ", "#floor# ", "|", }),
            ({ "#floor# ", "#floor# ", "|", }),
            ({ "=", "=", "+", }) }),
        "unicode": ({ ({ "#floor#\u2591", "#floor#\u2591", "\u2551" }),
            ({ "#floor#\u2591", "#floor#\u2591", "\u2551" }),
            ({ "\u2550", "\u2550", "\u255d" }) })
    ]),
    "temple interior southeast corner south entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;220m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;220m",
                    "24-bit": "\x1b[0;38;2;218;165;32m",
                ])
            ])
        ]),
        "ascii": ({ ({ "#floor# ", "#floor# ", "|", }),
            ({ "#floor# ", "#floor# ", "|", }),
            ({ "=", "#door#\\", "+", }) }),
        "unicode": ({ ({ "#floor#\u2591", "#floor#\u2591", "\u2551" }),
            ({ "#floor#\u2591", "#floor#\u2591", "\u2551" }),
            ({ "\u2557", "#door#\u2581", "\u2563" }) })
    ]),
    "temple interior southeast corner east entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;220m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;220m",
                    "24-bit": "\x1b[0;38;2;218;165;32m",
                ])
            ])
        ]),
        "ascii": ({ ({ "#floor# ", "#floor# ", "|", }),
            ({ "#floor# ", "#floor# ", "#door#/", }),
            ({ "=", "=", "+", }) }),
        "unicode": ({ ({ "#floor#\u2591", "#floor#\u2591", "\u2560" }),
            ({ "#floor#\u2591", "#floor#\u2591", "#door#\u2503" }),
            ({ "\u2550", "\u2550", "\u2569" }) })
    ]),
    "temple interior southeast corner south-east entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;220m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;220m",
                    "24-bit": "\x1b[0;38;2;218;165;32m",
                ])
            ])
        ]),
        "ascii": ({ ({ "#floor# ", "#floor# ", "|", }),
            ({ "#floor# ", "#floor# ", "#door#/", }),
            ({ "=", "#door#\\", "+", }) }),
        "unicode": ({ ({ "#floor#\u2591", "#floor#\u2591", "\u2560" }),
            ({ "#floor#\u2591", "#floor#\u2591", "#door#\u2503" }),
            ({ "\u2557", "#door#\u2581", "\u256c" }) })
    ]),
    "temple interior northeast corner": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "=", "=", "+", }),
            ({ "#floor# ", "#floor# ", "|", }),
            ({ "#floor# ", "#floor# ", "|", }) }),
        "unicode": ({ ({ "\u2550", "\u2550", "\u2557" }),
            ({ "#floor#\u2591", "#floor#\u2591", "\u2551" }),
            ({ "#floor#\u2591", "#floor#\u2591", "\u2551" }) })
    ]),
    "temple interior northeast corner north entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;220m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;220m",
                    "24-bit": "\x1b[0;38;2;218;165;32m",
                ])
            ])
        ]),
        "ascii": ({ ({ "=", "#door#\\", "+", }),
            ({ "#floor# ", "#floor# ", "|", }),
            ({ "#floor# ", "#floor# ", "|", }) }),
        "unicode": ({ ({ "\u2569", "#door#\u2594","\u2563" }),
            ({ "#floor#\u2591", "#floor#\u2591", "\u2551" }),
            ({ "#floor#\u2591", "#floor#\u2591", "\u2551" }) })
    ]),
    "temple interior northeast corner east entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;220m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;220m",
                    "24-bit": "\x1b[0;38;2;218;165;32m",
                ])
            ])
        ]),
        "ascii": ({ ({ "=", "=", "+", }),
            ({ "#floor# ", "#floor# ", "#door#/", }),
            ({ "#floor# ", "#floor# ", "|", }) }),
        "unicode": ({ ({ "\u2550", "\u2550","\u2566" }),
            ({ "#floor#\u2591", "#floor#\u2591", "#door#\u2503" }),
            ({ "#floor#\u2591", "#floor#\u2591", "\u2560" }) })
    ]),
    "temple interior northeast corner north-east entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;220m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;220m",
                    "24-bit": "\x1b[0;38;2;218;165;32m",
                ])
            ])
        ]),
        "ascii": ({ ({ "=", "#door#\\", "+", }),
            ({ "#floor# ", "#floor# ", "#door#/", }),
            ({ "#floor# ", "#floor# ", "|", }) }),
        "unicode": ({ ({ "\u2569", "#door#\u2594","\u256c" }),
            ({ "#floor#\u2591", "#floor#\u2591", "#door#\u2503" }),
            ({ "#floor#\u2591", "#floor#\u2591", "\u2560" }) })
    ]),
    "temple interior southwest corner": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "|", "#floor# ", "#floor# ", }),
            ({ "|", "#floor# ", "#floor# ", }),
            ({ "=", "=", "+", }) }),
        "unicode": ({ ({ "\u2551", "#floor#\u2591", "#floor#\u2591" }),
            ({ "\u2551", "#floor#\u2591", "#floor#\u2591", }),
            ({ "\u255a", "\u2550", "\u2550" }) })
    ]),
    "temple interior southwest corner west entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;220m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;220m",
                    "24-bit": "\x1b[0;38;2;218;165;32m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#floor# ", "#floor# ", }),
            ({ "#door#/", "#floor# ", "#floor# ", }),
            ({ "=", "=", "+", }) }),
        "unicode": ({ ({ "\u2563", "#floor#\u2591", "#floor#\u2591" }),
            ({ "#door#\u2503", "#floor#\u2591", "#floor#\u2591", }),
            ({ "\u2569", "\u2550", "\u2550" }) })
    ]),
    "temple interior southwest corner south entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;220m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;220m",
                    "24-bit": "\x1b[0;38;2;218;165;32m",
                ])
            ])
        ]),
        "ascii": ({ ({ "|", "#floor# ", "#floor# ", }),
            ({ "|", "#floor# ", "#floor# ", }),
            ({ "=", "#door#\\", "+", }) }),
        "unicode": ({ ({ "\u2551", "#floor#\u2591", "#floor#\u2591" }),
            ({ "\u2551", "#floor#\u2591", "#floor#\u2591", }),
            ({ "\u2560", "#door#\u2581", "\u2566" }) })
    ]),
    "temple interior southwest corner south-west entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;220m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;220m",
                    "24-bit": "\x1b[0;38;2;218;165;32m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#floor# ", "#floor# ", }),
            ({ "#door#/", "#floor# ", "#floor# ", }),
            ({ "=", "#door#\\", "+", }) }),
        "unicode": ({ ({ "\u2563", "#floor#\u2591", "#floor#\u2591" }),
            ({ "#door#\u2503", "#floor#\u2591", "#floor#\u2591", }),
            ({ "\u256c", "#door#\u2581", "\u2566" }) })
    ]),
    "temple interior northwest corner": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "=", "=", "+", }),
            ({ "|", "#floor# ", "#floor# ", }),
            ({ "|", "#floor# ", "#floor# ", }) }),
        "unicode": ({ ({ "\u2554", "\u2550", "\u2550" }),
            ({ "\u2551", "#floor#\u2591", "#floor#\u2591" }),
            ({ "\u2551", "#floor#\u2591", "#floor#\u2591" }) })
    ]),
    "temple interior northwest corner west entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;220m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;220m",
                    "24-bit": "\x1b[0;38;2;218;165;32m",
                ])
            ])
        ]),
        "ascii": ({ ({ "=", "=", "+", }),
            ({ "#door#/", "#floor# ", "#floor# ", }),
            ({ "+", "#floor# ", "#floor# ", }) }),
        "unicode": ({ ({ "\u2566", "\u2550", "\u2550" }),
            ({ "#door#\u2503", "#floor#\u2591", "#floor#\u2591", }),
            ({ "\u2563", "#floor#\u2591", "#floor#\u2591" }) })
    ]),
    "temple interior northwest corner north entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;220m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;220m",
                    "24-bit": "\x1b[0;38;2;218;165;32m",
                ])
            ])
        ]),
        "ascii": ({ ({ "=", "#door#\\", "+", }),
            ({ "|", "#floor# ", "#floor# ", }),
            ({ "|", "#floor# ", "#floor# ", }) }),
        "unicode": ({ ({ "\u2560", "#door#\u2594","\u2569" }),
            ({ "\u2551", "#floor#\u2591", "#floor#\u2591" }),
            ({ "\u2551", "#floor#\u2591", "#floor#\u2591" }) })
    ]),
    "temple interior northwest corner north-west entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;220m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;220m",
                    "24-bit": "\x1b[0;38;2;218;165;32m",
                ])
            ])
        ]),
        "ascii": ({ ({ "=", "#door#\\", "+", }),
            ({ "#door#/", "#floor# ", "#floor# ", }),
            ({ "+", "#floor# ", "#floor# ", }) }),
        "unicode": ({ ({ "\u256c", "#door#\u2594", "\u2569" }),
            ({ "#door#\u2503", "#floor#\u2591", "#floor#\u2591", }),
            ({ "\u2563", "#floor#\u2591", "#floor#\u2591" }) })
    ]),
    // Large room walls
    "temple interior south wall": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
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
    "temple interior south wall south entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;220m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;220m",
                    "24-bit": "\x1b[0;38;2;218;165;32m",
                ])
            ])
        ]),
        "ascii": ({ ({ "#floor# ", "#floor# ", "#floor# ", }),
            ({ "#floor# ", "#floor# ", "#floor# ", }),
            ({ "=", "#door#\\", "=", }) }),
        "unicode": ({ ({ "#floor#\u2591", "#floor#\u2591", "#floor#\u2591" }),
            ({ "#floor#\u2591", "#floor#\u2591", "#floor#\u2591" }),
            ({ "\u2557", "#door#\u2581", "\u2554" }) })
    ]),
    "temple interior north wall": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
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
    "temple interior north wall north entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;220m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;220m",
                    "24-bit": "\x1b[0;38;2;218;165;32m",
                ])
            ])
        ]),
        "ascii": ({ ({ "=", "#door#\\", "=", }),
            ({ "#floor# ", "#floor# ", "#floor# ", }),
            ({ "#floor# ", "#floor# ", "#floor# ", }) }),
        "unicode": ({ ({ "\u255d", "#door#\u2594", "\u255a" }),
            ({ "#floor#\u2591", "#floor#\u2591", "#floor#\u2591" }),
            ({ "#floor#\u2591", "#floor#\u2591", "#floor#\u2591" }) })
    ]),
    "temple interior east wall": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "#floor# ", "#floor# ", "|", }),
            ({ "#floor# ", "#floor# ", "|", }),
            ({ "#floor# ", "#floor# ", "|", }) }),
        "unicode": ({ ({ "#floor#\u2591", "#floor#\u2591", "\u2551" }),
            ({ "#floor#\u2591", "#floor#\u2591", "\u2551" }),
            ({ "#floor#\u2591", "#floor#\u2591", "\u2551" }) })
    ]),
    "temple interior east wall east entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;220m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;220m",
                    "24-bit": "\x1b[0;38;2;218;165;32m",
                ])
            ])
        ]),
        "ascii": ({ ({ "#floor# ", "#floor# ", "|", }),
            ({ "#floor# ", "#floor# ", "#door#/", }),
            ({ "#floor# ", "#floor# ", "|", }) }),
        "unicode": ({ ({ "#floor#\u2591", "#floor#\u2591", "\u2560" }),
            ({ "#floor#\u2591", "#floor#\u2591", "#door#\u2503" }),
            ({ "#floor#\u2591", "#floor#\u2591", "\u2560" }) })
    ]),
    "temple interior west wall": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
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
    "temple interior west wall west entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;220m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;220m",
                    "24-bit": "\x1b[0;38;2;218;165;32m",
                ])
            ])
        ]),
        "ascii": ({ ({ "|", "#floor# ", "#floor# ", }),
            ({ "#door#/", "#floor# ", "#floor# ", }),
            ({ "|", "#floor# ", "#floor# ", }) }),
        "unicode": ({ ({ "\u2563", "#floor#\u2591", "#floor#\u2591" }),
            ({ "#door#\u2503", "#floor#\u2591", "#floor#\u2591" }),
            ({ "\u2563", "#floor#\u2591", "#floor#\u2591" }) })
    ]),

    // Basic hallways (already defined earlier)
    "temple interior east-west hallway": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
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
    "temple interior east-west hallway north entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;220m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;220m",
                    "24-bit": "\x1b[0;38;2;218;165;32m",
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
    "temple interior east-west hallway south entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;220m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;220m",
                    "24-bit": "\x1b[0;38;2;218;165;32m",
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
    "temple interior east-west hallway north-south entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;220m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;220m",
                    "24-bit": "\x1b[0;38;2;218;165;32m",
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
    "temple interior north-south hallway": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
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
    "temple interior north-south hallway east entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;220m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;220m",
                    "24-bit": "\x1b[0;38;2;218;165;32m",
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
    "temple interior north-south hallway west entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;220m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;220m",
                    "24-bit": "\x1b[0;38;2;218;165;32m",
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
    "temple interior north-south hallway east-west entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;220m",
                    "3-bit": "\x1b[0;33m",
                    "8-bit": "\x1b[0;38;5;220m",
                    "24-bit": "\x1b[0;38;2;218;165;32m",
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
    "temple interior 4-way hallway": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
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
    "temple interior south alcove": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
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
    "temple interior north alcove": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
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
    "temple interior west alcove": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
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
    "temple interior east alcove": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
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
    "temple interior floor": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
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
    "temple interior sanctuary": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;250m",
            "24-bit": "\x1b[0;38;2;230;230;240m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;248m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;248m",
                    "24-bit": "\x1b[0;38;2;210;210;220m",
                ]),
                "altar":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;220m",
                    "3-bit": "\x1b[0;33;1m",
                    "8-bit": "\x1b[0;38;5;220m",
                    "24-bit": "\x1b[0;38;2;218;165;32m",
                ])
            ])
        ]),
        "ascii": ({ ({ "#floor# ", "#floor# ", "#floor# ", }),
            ({ "#floor# ", "#altar#+", "#floor# ", }),
            ({ "#floor# ", "#floor# ", "#floor# ", }) }),
        "unicode": ({ ({ "#floor#\u2591", "#floor#\u2591", "#floor#\u2591" }),
            ({ "#floor#\u2591", "#altar#\u2720", "#floor#\u2591" }),
            ({ "#floor#\u2591", "#floor#\u2591", "#floor#\u2591" }) })
    ]),
]);

#endif