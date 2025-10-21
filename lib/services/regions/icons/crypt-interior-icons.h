//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef cryptInteriorIcons_h
#define cryptInteriorIcons_h

private mapping CryptInteriorIcons = ([
    // Basic Hallways
    "crypt interior east-west hallway": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;58;58;62m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;235m",
                    "3-bit": "\x1b[0;30m",
                    "8-bit": "\x1b[0;38;5;235m",
                    "24-bit": "\x1b[0;38;2;38;38;42m",
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
    "crypt interior east-west hallway north entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;58;58;62m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;235m",
                    "3-bit": "\x1b[0;30m",
                    "8-bit": "\x1b[0;38;5;235m",
                    "24-bit": "\x1b[0;38;2;38;38;42m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;240m",
                    "3-bit": "\x1b[0;30;1m",
                    "8-bit": "\x1b[0;38;5;240m",
                    "24-bit": "\x1b[0;38;2;58;52;46m",
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
    "crypt interior east-west hallway south entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;58;58;62m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;235m",
                    "3-bit": "\x1b[0;30m",
                    "8-bit": "\x1b[0;38;5;235m",
                    "24-bit": "\x1b[0;38;2;38;38;42m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;240m",
                    "3-bit": "\x1b[0;30;1m",
                    "8-bit": "\x1b[0;38;5;240m",
                    "24-bit": "\x1b[0;38;2;58;52;46m",
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
    "crypt interior east-west hallway north-south entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;58;58;62m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;235m",
                    "3-bit": "\x1b[0;30m",
                    "8-bit": "\x1b[0;38;5;235m",
                    "24-bit": "\x1b[0;38;2;38;38;42m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;240m",
                    "3-bit": "\x1b[0;30;1m",
                    "8-bit": "\x1b[0;38;5;240m",
                    "24-bit": "\x1b[0;38;2;58;52;46m",
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
    "crypt interior north-south hallway": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;58;58;62m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;235m",
                    "3-bit": "\x1b[0;30m",
                    "8-bit": "\x1b[0;38;5;235m",
                    "24-bit": "\x1b[0;38;2;38;38;42m",
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
    "crypt interior north-south hallway east entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;58;58;62m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;235m",
                    "3-bit": "\x1b[0;30m",
                    "8-bit": "\x1b[0;38;5;235m",
                    "24-bit": "\x1b[0;38;2;38;38;42m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;240m",
                    "3-bit": "\x1b[0;30;1m",
                    "8-bit": "\x1b[0;38;5;240m",
                    "24-bit": "\x1b[0;38;2;58;52;46m",
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
    "crypt interior north-south hallway west entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;58;58;62m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;235m",
                    "3-bit": "\x1b[0;30m",
                    "8-bit": "\x1b[0;38;5;235m",
                    "24-bit": "\x1b[0;38;2;38;38;42m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;240m",
                    "3-bit": "\x1b[0;30;1m",
                    "8-bit": "\x1b[0;38;5;240m",
                    "24-bit": "\x1b[0;38;2;58;52;46m",
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
    "crypt interior north-south hallway east-west entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;58;58;62m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;235m",
                    "3-bit": "\x1b[0;30m",
                    "8-bit": "\x1b[0;38;5;235m",
                    "24-bit": "\x1b[0;38;2;38;38;42m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;240m",
                    "3-bit": "\x1b[0;30;1m",
                    "8-bit": "\x1b[0;38;5;240m",
                    "24-bit": "\x1b[0;38;2;58;52;46m",
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
    "crypt interior 4-way hallway": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;58;58;62m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;235m",
                    "3-bit": "\x1b[0;30m",
                    "8-bit": "\x1b[0;38;5;235m",
                    "24-bit": "\x1b[0;38;2;38;38;42m",
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

    // Simple Alcoves
    "crypt interior south alcove": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;58;58;62m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;235m",
                    "3-bit": "\x1b[0;30m",
                    "8-bit": "\x1b[0;38;5;235m",
                    "24-bit": "\x1b[0;38;2;38;38;42m",
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
    "crypt interior north alcove": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;58;58;62m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;235m",
                    "3-bit": "\x1b[0;30m",
                    "8-bit": "\x1b[0;38;5;235m",
                    "24-bit": "\x1b[0;38;2;38;38;42m",
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
    "crypt interior west alcove": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;58;58;62m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;235m",
                    "3-bit": "\x1b[0;30m",
                    "8-bit": "\x1b[0;38;5;235m",
                    "24-bit": "\x1b[0;38;2;38;38;42m",
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
    "crypt interior east alcove": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;58;58;62m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;235m",
                    "3-bit": "\x1b[0;30m",
                    "8-bit": "\x1b[0;38;5;235m",
                    "24-bit": "\x1b[0;38;2;38;38;42m",
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

    // T-Intersections
    "crypt interior west T-intersection": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;58;58;62m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;235m",
                    "3-bit": "\x1b[0;30m",
                    "8-bit": "\x1b[0;38;5;235m",
                    "24-bit": "\x1b[0;38;2;38;38;42m",
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
    "crypt interior west T-intersection east entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;58;58;62m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;235m",
                    "3-bit": "\x1b[0;30m",
                    "8-bit": "\x1b[0;38;5;235m",
                    "24-bit": "\x1b[0;38;2;38;38;42m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;240m",
                    "3-bit": "\x1b[0;30;1m",
                    "8-bit": "\x1b[0;38;5;240m",
                    "24-bit": "\x1b[0;38;2;58;52;46m",
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
    "crypt interior east T-intersection": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;58;58;62m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;235m",
                    "3-bit": "\x1b[0;30m",
                    "8-bit": "\x1b[0;38;5;235m",
                    "24-bit": "\x1b[0;38;2;38;38;42m",
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
    "crypt interior east T-intersection west entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;58;58;62m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;235m",
                    "3-bit": "\x1b[0;30m",
                    "8-bit": "\x1b[0;38;5;235m",
                    "24-bit": "\x1b[0;38;2;38;38;42m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;240m",
                    "3-bit": "\x1b[0;30;1m",
                    "8-bit": "\x1b[0;38;5;240m",
                    "24-bit": "\x1b[0;38;2;58;52;46m",
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
    "crypt interior south T-intersection": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;58;58;62m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;235m",
                    "3-bit": "\x1b[0;30m",
                    "8-bit": "\x1b[0;38;5;235m",
                    "24-bit": "\x1b[0;38;2;38;38;42m",
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
    "crypt interior south T-intersection north entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;58;58;62m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;235m",
                    "3-bit": "\x1b[0;30m",
                    "8-bit": "\x1b[0;38;5;235m",
                    "24-bit": "\x1b[0;38;2;38;38;42m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;240m",
                    "3-bit": "\x1b[0;30;1m",
                    "8-bit": "\x1b[0;38;5;240m",
                    "24-bit": "\x1b[0;38;2;58;52;46m",
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
    "crypt interior north T-intersection": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;58;58;62m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;235m",
                    "3-bit": "\x1b[0;30m",
                    "8-bit": "\x1b[0;38;5;235m",
                    "24-bit": "\x1b[0;38;2;38;38;42m",
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
    "crypt interior north T-intersection south entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;58;58;62m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;235m",
                    "3-bit": "\x1b[0;30m",
                    "8-bit": "\x1b[0;38;5;235m",
                    "24-bit": "\x1b[0;38;2;38;38;42m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;240m",
                    "3-bit": "\x1b[0;30;1m",
                    "8-bit": "\x1b[0;38;5;240m",
                    "24-bit": "\x1b[0;38;2;58;52;46m",
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

    // Floor tiles
    "crypt interior floor": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;58;58;62m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;235m",
                    "3-bit": "\x1b[0;30m",
                    "8-bit": "\x1b[0;38;5;235m",
                    "24-bit": "\x1b[0;38;2;38;38;42m",
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
    "crypt interior burial chamber": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;58;58;62m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;235m",
                    "3-bit": "\x1b[0;30m",
                    "8-bit": "\x1b[0;38;5;235m",
                    "24-bit": "\x1b[0;38;2;38;38;42m",
                ]),
                "tomb":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;242m",
                    "3-bit": "\x1b[0;37m",
                    "8-bit": "\x1b[0;38;5;242m",
                    "24-bit": "\x1b[0;38;2;88;88;92m",
                ])
            ])
        ]),
        "ascii": ({ ({ "#floor# ", "#floor# ", "#floor# ", }),
            ({ "#floor# ", "#tomb#[]", "#floor# ", }),
            ({ "#floor# ", "#floor# ", "#floor# ", }) }),
        "unicode": ({ ({ "#floor#\u2591", "#floor#\u2591", "#floor#\u2591" }),
            ({ "#floor#\u2591", "#tomb#\u2637", "#floor#\u2591" }),
            ({ "#floor#\u2591", "#floor#\u2591", "#floor#\u2591" }) })
    ]),

    "crypt interior north entry alcove": ([
        "colors":([
            "none":"",
            "grayscale" : "\x1b[0;38;5;237m",
            "3-bit" : "\x1b[0;30;1m",
            "8-bit" : "\x1b[0;38;5;237m",
            "24-bit" : "\x1b[0;38;2;58;58;62m",
            "icons" : ([
                "floor":([
                    "none":"",
                    "grayscale" : "\x1b[0;38;5;235m",
                    "3-bit" : "\x1b[0;30m",
                    "8-bit" : "\x1b[0;38;5;235m",
                    "24-bit" : "\x1b[0;38;2;38;38;42m",
                ]),
                "door":([
                    "none":"",
                    "grayscale" : "\x1b[0;38;5;240m",
                    "3-bit" : "\x1b[0;30;1m",
                    "8-bit" : "\x1b[0;38;5;240m",
                    "24-bit" : "\x1b[0;38;2;58;52;46m",
                ])
            ])
        ]),
            "ascii": ({ ({ "+", "#door#\\", "+", }),
                ({ "|", "#floor# ", "|", }),
                ({ "|", "#floor# ", "|", }) }),
            "unicode" : ({ ({ "\u256c", "#door#\u2594", "\u256c" }),
                ({ "\u2551", "#floor#\u2591", "\u2551" }),
                ({ "\u2551", "#floor#\u2591", "\u2551" }) })
    ]),
    "crypt interior north-east entry alcove": ([
        "colors":([
            "none":"",
            "grayscale" : "\x1b[0;38;5;237m",
            "3-bit" : "\x1b[0;30;1m",
            "8-bit" : "\x1b[0;38;5;237m",
            "24-bit" : "\x1b[0;38;2;58;58;62m",
            "icons" : ([
                "floor":([
                    "none":"",
                    "grayscale" : "\x1b[0;38;5;235m",
                    "3-bit" : "\x1b[0;30m",
                    "8-bit" : "\x1b[0;38;5;235m",
                    "24-bit" : "\x1b[0;38;2;38;38;42m",
                ]),
                "door":([
                    "none":"",
                    "grayscale" : "\x1b[0;38;5;240m",
                    "3-bit" : "\x1b[0;30;1m",
                    "8-bit" : "\x1b[0;38;5;240m",
                    "24-bit" : "\x1b[0;38;2;58;52;46m",
                ])
            ])
        ]),
            "ascii": ({ ({ "+", "#door#\\", "+", }),
                ({ "|", "#floor# ", "#door#/", }),
                ({ "|", "#floor# ", "|", }) }),
            "unicode" : ({ ({ "\u256c", "#door#\u2594", "\u256c" }),
                ({ "\u2551", "#floor#\u2591", "#door#\u2503" }),
                ({ "\u2551", "#floor#\u2591", "\u2560" }) })
    ]),
    "crypt interior north-west entry alcove": ([
        "colors":([
            "none":"",
            "grayscale" : "\x1b[0;38;5;237m",
            "3-bit" : "\x1b[0;30;1m",
            "8-bit" : "\x1b[0;38;5;237m",
            "24-bit" : "\x1b[0;38;2;58;58;62m",
            "icons" : ([
                "floor":([
                    "none":"",
                    "grayscale" : "\x1b[0;38;5;235m",
                    "3-bit" : "\x1b[0;30m",
                    "8-bit" : "\x1b[0;38;5;235m",
                    "24-bit" : "\x1b[0;38;2;38;38;42m",
                ]),
                "door":([
                    "none":"",
                    "grayscale" : "\x1b[0;38;5;240m",
                    "3-bit" : "\x1b[0;30;1m",
                    "8-bit" : "\x1b[0;38;5;240m",
                    "24-bit" : "\x1b[0;38;2;58;52;46m",
                ])
            ])
        ]),
            "ascii": ({ ({ "+", "#door#\\", "+", }),
                ({ "#door#/", "#floor# ", "|", }),
                ({ "|", "#floor# ", "|", }) }),
            "unicode" : ({ ({ "\u256c", "#door#\u2594", "\u256c" }),
                ({ "#door#\u2503", "#floor#\u2591", "\u2551" }),
                ({ "\u2563", "#floor#\u2591", "\u2551" }) })
    ]),
    "crypt interior north-east-west entry alcove": ([
        "colors":([
            "none":"",
            "grayscale" : "\x1b[0;38;5;237m",
            "3-bit" : "\x1b[0;30;1m",
            "8-bit" : "\x1b[0;38;5;237m",
            "24-bit" : "\x1b[0;38;2;58;58;62m",
            "icons" : ([
                "floor":([
                    "none":"",
                    "grayscale" : "\x1b[0;38;5;235m",
                    "3-bit" : "\x1b[0;30m",
                    "8-bit" : "\x1b[0;38;5;235m",
                    "24-bit" : "\x1b[0;38;2;38;38;42m",
                ]),
                "door":([
                    "none":"",
                    "grayscale" : "\x1b[0;38;5;240m",
                    "3-bit" : "\x1b[0;30;1m",
                    "8-bit" : "\x1b[0;38;5;240m",
                    "24-bit" : "\x1b[0;38;2;58;52;46m",
                ])
            ])
        ]),
            "ascii": ({ ({ "+", "#door#\\", "+", }),
                ({ "#door#/", "#floor# ", "#door#/", }),
                ({ "|", "#floor# ", "|", }) }),
            "unicode" : ({ ({ "\u256c", "#door#\u2594", "\u256c" }),
                ({ "#door#\u2503", "#floor#\u2591", "#door#\u2503" }),
                ({ "\u2563", "#floor#\u2591", "\u2560" }) })
    ]),
    "crypt interior north alcove west entry": ([
        "colors":([
            "none":"",
            "grayscale" : "\x1b[0;38;5;237m",
            "3-bit" : "\x1b[0;30;1m",
            "8-bit" : "\x1b[0;38;5;237m",
            "24-bit" : "\x1b[0;38;2;58;58;62m",
            "icons" : ([
                "floor":([
                    "none":"",
                    "grayscale" : "\x1b[0;38;5;235m",
                    "3-bit" : "\x1b[0;30m",
                    "8-bit" : "\x1b[0;38;5;235m",
                    "24-bit" : "\x1b[0;38;2;38;38;42m",
                ]),
                "door":([
                    "none":"",
                    "grayscale" : "\x1b[0;38;5;240m",
                    "3-bit" : "\x1b[0;30;1m",
                    "8-bit" : "\x1b[0;38;5;240m",
                    "24-bit" : "\x1b[0;38;2;58;52;46m",
                ])
            ])
        ]),
            "ascii": ({ ({ "+", "+", "+", }),
                ({ "#door#/", "#floor# ", "|", }),
                ({ "+", "#floor# ", "|", }) }),
            "unicode" : ({ ({ "\u256c", "\u2550", "\u2557" }),
                ({ "#door#\u2503", "#floor#\u2591", "\u2551" }),
                ({ "\u256c", "#floor#\u2591", "\u2551" }) })
    ]),
    "crypt interior north alcove east entry": ([
        "colors":([
            "none":"",
            "grayscale" : "\x1b[0;38;5;237m",
            "3-bit" : "\x1b[0;30;1m",
            "8-bit" : "\x1b[0;38;5;237m",
            "24-bit" : "\x1b[0;38;2;58;58;62m",
            "icons" : ([
                "floor":([
                    "none":"",
                    "grayscale" : "\x1b[0;38;5;235m",
                    "3-bit" : "\x1b[0;30m",
                    "8-bit" : "\x1b[0;38;5;235m",
                    "24-bit" : "\x1b[0;38;2;38;38;42m",
                ]),
                "door":([
                    "none":"",
                    "grayscale" : "\x1b[0;38;5;240m",
                    "3-bit" : "\x1b[0;30;1m",
                    "8-bit" : "\x1b[0;38;5;240m",
                    "24-bit" : "\x1b[0;38;2;58;52;46m",
                ])
            ])
        ]),
            "ascii": ({ ({ "+", "+", "+", }),
                ({ "|", "#floor# ", "#door#/", }),
                ({ "|", "#floor# ", "+", }) }),
            "unicode" : ({ ({ "\u2554", "\u2550", "\u256c" }),
                ({ "\u2551", "#floor#\u2591", "#door#\u2503" }),
                ({ "\u2551", "#floor#\u2591", "\u256c" }) })
    ]),
    "crypt interior north alcove east-west entry": ([
        "colors":([
            "none":"",
            "grayscale" : "\x1b[0;38;5;237m",
            "3-bit" : "\x1b[0;30;1m",
            "8-bit" : "\x1b[0;38;5;237m",
            "24-bit" : "\x1b[0;38;2;58;58;62m",
            "icons" : ([
                "floor":([
                    "none":"",
                    "grayscale" : "\x1b[0;38;5;235m",
                    "3-bit" : "\x1b[0;30m",
                    "8-bit" : "\x1b[0;38;5;235m",
                    "24-bit" : "\x1b[0;38;2;38;38;42m",
                ]),
                "door":([
                    "none":"",
                    "grayscale" : "\x1b[0;38;5;240m",
                    "3-bit" : "\x1b[0;30;1m",
                    "8-bit" : "\x1b[0;38;5;240m",
                    "24-bit" : "\x1b[0;38;2;58;52;46m",
                ])
            ])
        ]),
            "ascii": ({ ({ "+", "+", "+", }),
                ({ "#door#/", "#floor# ", "#door#/", }),
                ({ "|", "#floor# ", "|", }) }),
            "unicode" : ({ ({ "\u256c", "\u2550", "\u256c" }),
                ({ "#door#\u2503", "#floor#\u2591", "#door#\u2503" }),
                ({ "\u256c", "#floor#\u2591", "\u256c" }) })
    ]),

    // South Alcove Variants
    "crypt interior south entry alcove": ([
        "colors":([
            "none":"",
            "grayscale" : "\x1b[0;38;5;237m",
            "3-bit" : "\x1b[0;30;1m",
            "8-bit" : "\x1b[0;38;5;237m",
            "24-bit" : "\x1b[0;38;2;58;58;62m",
            "icons" : ([
                "floor":([
                    "none":"",
                    "grayscale" : "\x1b[0;38;5;235m",
                    "3-bit" : "\x1b[0;30m",
                    "8-bit" : "\x1b[0;38;5;235m",
                    "24-bit" : "\x1b[0;38;2;38;38;42m",
                ]),
                "door":([
                    "none":"",
                    "grayscale" : "\x1b[0;38;5;240m",
                    "3-bit" : "\x1b[0;30;1m",
                    "8-bit" : "\x1b[0;38;5;240m",
                    "24-bit" : "\x1b[0;38;2;58;52;46m",
                ])
            ])
        ]),
            "ascii": ({ ({ "|", "#floor# ", "|", }),
                ({ "|", "#floor# ", "|", }),
                ({ "+", "#door#\\", "+", }), }),
            "unicode" : ({ ({ "\u2551", "#floor#\u2591", "\u2551" }),
                ({ "\u2551", "#floor#\u2591", "\u2551" }),
                ({ "\u256c", "#door#\u2581", "\u256c" }), })
    ]),
    "crypt interior south-east entry alcove": ([
        "colors":([
            "none":"",
            "grayscale" : "\x1b[0;38;5;237m",
            "3-bit" : "\x1b[0;30;1m",
            "8-bit" : "\x1b[0;38;5;237m",
            "24-bit" : "\x1b[0;38;2;58;58;62m",
            "icons" : ([
                "floor":([
                    "none":"",
                    "grayscale" : "\x1b[0;38;5;235m",
                    "3-bit" : "\x1b[0;30m",
                    "8-bit" : "\x1b[0;38;5;235m",
                    "24-bit" : "\x1b[0;38;2;38;38;42m",
                ]),
                "door":([
                    "none":"",
                    "grayscale" : "\x1b[0;38;5;240m",
                    "3-bit" : "\x1b[0;30;1m",
                    "8-bit" : "\x1b[0;38;5;240m",
                    "24-bit" : "\x1b[0;38;2;58;52;46m",
                ])
            ])
        ]),
            "ascii": ({ ({ "|", "#floor# ", "|", }),
                ({ "|", "#floor# ", "#door#/", }),
                ({ "+", "#door#\\", "+", }), }),
            "unicode" : ({ ({ "\u2551", "#floor#\u2591", "\u2560" }),
                ({ "\u2551", "#floor#\u2591", "#door#\u2503" }),
                ({ "\u256c", "#door#\u2581", "\u256c" }), })
    ]),
    "crypt interior south-west entry alcove": ([
        "colors":([
            "none":"",
            "grayscale" : "\x1b[0;38;5;237m",
            "3-bit" : "\x1b[0;30;1m",
            "8-bit" : "\x1b[0;38;5;237m",
            "24-bit" : "\x1b[0;38;2;58;58;62m",
            "icons" : ([
                "floor":([
                    "none":"",
                    "grayscale" : "\x1b[0;38;5;235m",
                    "3-bit" : "\x1b[0;30m",
                    "8-bit" : "\x1b[0;38;5;235m",
                    "24-bit" : "\x1b[0;38;2;38;38;42m",
                ]),
                "door":([
                    "none":"",
                    "grayscale" : "\x1b[0;38;5;240m",
                    "3-bit" : "\x1b[0;30;1m",
                    "8-bit" : "\x1b[0;38;5;240m",
                    "24-bit" : "\x1b[0;38;2;58;52;46m",
                ])
            ])
        ]),
            "ascii": ({ ({ "|", "#floor# ", "|", }),
                ({ "#door#/", "#floor# ", "|", }),
                ({ "+", "#door#\\", "+", }), }),
            "unicode" : ({ ({ "\u2563", "#floor#\u2591", "\u2551" }),
                ({ "#door#\u2503", "#floor#\u2591", "\u2551" }),
                ({ "\u256c", "#door#\u2581", "\u256c" }), })
    ]),
    "crypt interior south-east-west entry alcove": ([
        "colors":([
            "none":"",
            "grayscale" : "\x1b[0;38;5;237m",
            "3-bit" : "\x1b[0;30;1m",
            "8-bit" : "\x1b[0;38;5;237m",
            "24-bit" : "\x1b[0;38;2;58;58;62m",
            "icons" : ([
                "floor":([
                    "none":"",
                    "grayscale" : "\x1b[0;38;5;235m",
                    "3-bit" : "\x1b[0;30m",
                    "8-bit" : "\x1b[0;38;5;235m",
                    "24-bit" : "\x1b[0;38;2;38;38;42m",
                ]),
                "door":([
                    "none":"",
                    "grayscale" : "\x1b[0;38;5;240m",
                    "3-bit" : "\x1b[0;30;1m",
                    "8-bit" : "\x1b[0;38;5;240m",
                    "24-bit" : "\x1b[0;38;2;58;52;46m",
                ])
            ])
        ]),
            "ascii": ({ ({ "|", "#floor# ", "|", }),
                ({ "#door#/", "#floor# ", "#door#/", }),
                ({ "+", "#door#\\", "+", }), }),
            "unicode" : ({ ({ "\u2563", "#floor#\u2591", "\u2560" }),
                ({ "#door#\u2503", "#floor#\u2591", "#door#\u2503" }),
                ({ "\u256c", "#door#\u2581", "\u256c" }), })
    ]),
    "crypt interior south alcove west entry": ([
        "colors":([
            "none":"",
            "grayscale" : "\x1b[0;38;5;237m",
            "3-bit" : "\x1b[0;30;1m",
            "8-bit" : "\x1b[0;38;5;237m",
            "24-bit" : "\x1b[0;38;2;58;58;62m",
            "icons" : ([
                "floor":([
                    "none":"",
                    "grayscale" : "\x1b[0;38;5;235m",
                    "3-bit" : "\x1b[0;30m",
                    "8-bit" : "\x1b[0;38;5;235m",
                    "24-bit" : "\x1b[0;38;2;38;38;42m",
                ]),
                "door":([
                    "none":"",
                    "grayscale" : "\x1b[0;38;5;240m",
                    "3-bit" : "\x1b[0;30;1m",
                    "8-bit" : "\x1b[0;38;5;240m",
                    "24-bit" : "\x1b[0;38;2;58;52;46m",
                ])
            ])
        ]),
            "ascii": ({ ({ "+", "#floor# ", "|", }),
                ({ "#door#/", "#floor# ", "|", }),
                ({ "+", "=", "+", }) }),
            "unicode" : ({ ({ "\u256c", "#floor#\u2591", "\u2551" }),
                ({ "#door#\u2503", "#floor#\u2591", "\u2551" }),
                ({ "\u256c", "\u2550", "\u255d" }) })
    ]),
    "crypt interior south alcove east entry": ([
        "colors":([
            "none":"",
            "grayscale" : "\x1b[0;38;5;237m",
            "3-bit" : "\x1b[0;30;1m",
            "8-bit" : "\x1b[0;38;5;237m",
            "24-bit" : "\x1b[0;38;2;58;58;62m",
            "icons" : ([
                "floor":([
                    "none":"",
                    "grayscale" : "\x1b[0;38;5;235m",
                    "3-bit" : "\x1b[0;30m",
                    "8-bit" : "\x1b[0;38;5;235m",
                    "24-bit" : "\x1b[0;38;2;38;38;42m",
                ]),
                "door":([
                    "none":"",
                    "grayscale" : "\x1b[0;38;5;240m",
                    "3-bit" : "\x1b[0;30;1m",
                    "8-bit" : "\x1b[0;38;5;240m",
                    "24-bit" : "\x1b[0;38;2;58;52;46m",
                ])
            ])
        ]),
            "ascii": ({ ({ "|", "#floor# ", "+", }),
                ({ "|", "#floor# ", "#door#/", }),
                ({ "+", "=", "+", }) }),
            "unicode" : ({ ({ "\u2551", "#floor#\u2591", "\u256c" }),
                ({ "\u2551", "#floor#\u2591", "#door#\u2503" }),
                ({ "\u255a", "\u2550", "\u256c" }) })
    ]),
    "crypt interior south alcove east-west entry": ([
        "colors":([
            "none":"",
            "grayscale" : "\x1b[0;38;5;237m",
            "3-bit" : "\x1b[0;30;1m",
            "8-bit" : "\x1b[0;38;5;237m",
            "24-bit" : "\x1b[0;38;2;58;58;62m",
            "icons" : ([
                "floor":([
                    "none":"",
                    "grayscale" : "\x1b[0;38;5;235m",
                    "3-bit" : "\x1b[0;30m",
                    "8-bit" : "\x1b[0;38;5;235m",
                    "24-bit" : "\x1b[0;38;2;38;38;42m",
                ]),
                "door":([
                    "none":"",
                    "grayscale" : "\x1b[0;38;5;240m",
                    "3-bit" : "\x1b[0;30;1m",
                    "8-bit" : "\x1b[0;38;5;240m",
                    "24-bit" : "\x1b[0;38;2;58;52;46m",
                ])
            ])
        ]),
            "ascii": ({ ({ "|", "#floor# ", "|", }),
                ({ "#door#/", "#floor# ", "#door#/", }),
                ({ "+", "=", "+", }) }),
            "unicode" : ({ ({ "\u256c", "#floor#\u2591", "\u256c" }),
                ({ "#door#\u2503", "#floor#\u2591", "#door#\u2503" }),
                ({ "\u256c", "\u2550", "\u256c" }) })
    ]),

    // West Alcove Variants
    "crypt interior west entry alcove": ([
        "colors":([
            "none":"",
            "grayscale" : "\x1b[0;38;5;237m",
            "3-bit" : "\x1b[0;30;1m",
            "8-bit" : "\x1b[0;38;5;237m",
            "24-bit" : "\x1b[0;38;2;58;58;62m",
            "icons" : ([
                "floor":([
                    "none":"",
                    "grayscale" : "\x1b[0;38;5;235m",
                    "3-bit" : "\x1b[0;30m",
                    "8-bit" : "\x1b[0;38;5;235m",
                    "24-bit" : "\x1b[0;38;2;38;38;42m",
                ]),
                "door":([
                    "none":"",
                    "grayscale" : "\x1b[0;38;5;240m",
                    "3-bit" : "\x1b[0;30;1m",
                    "8-bit" : "\x1b[0;38;5;240m",
                    "24-bit" : "\x1b[0;38;2;58;52;46m",
                ])
            ])
        ]),
            "ascii": ({ ({ "+", "=", "=", }),
                ({ "#door#/", "#floor# ", "#floor# ", }),
                ({ "+", "=", "=", }) }),
            "unicode" : ({ ({ "\u256c", "\u2550", "\u2550" }),
                ({ "#door#\u2503", "#floor#\u2591", "#floor#\u2591" }),
                ({ "\u256c", "\u2550", "\u2550" }) })
    ]),
    "crypt interior west-north entry alcove": ([
        "colors":([
            "none":"",
            "grayscale" : "\x1b[0;38;5;237m",
            "3-bit" : "\x1b[0;30;1m",
            "8-bit" : "\x1b[0;38;5;237m",
            "24-bit" : "\x1b[0;38;2;58;58;62m",
            "icons" : ([
                "floor":([
                    "none":"",
                    "grayscale" : "\x1b[0;38;5;235m",
                    "3-bit" : "\x1b[0;30m",
                    "8-bit" : "\x1b[0;38;5;235m",
                    "24-bit" : "\x1b[0;38;2;38;38;42m",
                ]),
                "door":([
                    "none":"",
                    "grayscale" : "\x1b[0;38;5;240m",
                    "3-bit" : "\x1b[0;30;1m",
                    "8-bit" : "\x1b[0;38;5;240m",
                    "24-bit" : "\x1b[0;38;2;58;52;46m",
                ])
            ])
        ]),
            "ascii": ({ ({ "+", "#door#\\", "=", }),
                ({ "#door#/", "#floor# ", "#floor# ", }),
                ({ "+", "=", "=", }) }),
            "unicode" : ({ ({ "\u256c", "#door#\u2594", "\u2569" }),
                ({ "#door#\u2503", "#floor#\u2591", "#floor#\u2591", }),
                ({ "\u256c", "\u2550", "\u2550" }) })
    ]),
    "crypt interior west-south entry alcove": ([
        "colors":([
            "none":"",
            "grayscale" : "\x1b[0;38;5;237m",
            "3-bit" : "\x1b[0;30;1m",
            "8-bit" : "\x1b[0;38;5;237m",
            "24-bit" : "\x1b[0;38;2;58;58;62m",
            "icons" : ([
                "floor":([
                    "none":"",
                    "grayscale" : "\x1b[0;38;5;235m",
                    "3-bit" : "\x1b[0;30m",
                    "8-bit" : "\x1b[0;38;5;235m",
                    "24-bit" : "\x1b[0;38;2;38;38;42m",
                ]),
                "door":([
                    "none":"",
                    "grayscale" : "\x1b[0;38;5;240m",
                    "3-bit" : "\x1b[0;30;1m",
                    "8-bit" : "\x1b[0;38;5;240m",
                    "24-bit" : "\x1b[0;38;2;58;52;46m",
                ])
            ])
        ]),
            "ascii": ({ ({ "+", "=", "=", }),
                ({ "#door#/", "#floor# ", "#floor# ", }),
                ({ "+", "#door#\\", "=", }) }),
            "unicode" : ({ ({ "\u256c", "\u2550", "\u2550" }),
                ({ "#door#\u2503", "#floor#\u2591", "#floor#\u2591" }),
                ({ "\u256c", "#door#\u2581", "\u2566" }) })
    ]),
    "crypt interior west-south-north entry alcove": ([
        "colors":([
            "none":"",
            "grayscale" : "\x1b[0;38;5;237m",
            "3-bit" : "\x1b[0;30;1m",
            "8-bit" : "\x1b[0;38;5;237m",
            "24-bit" : "\x1b[0;38;2;58;58;62m",
            "icons" : ([
                "floor":([
                    "none":"",
                    "grayscale" : "\x1b[0;38;5;235m",
                    "3-bit" : "\x1b[0;30m",
                    "8-bit" : "\x1b[0;38;5;235m",
                    "24-bit" : "\x1b[0;38;2;38;38;42m",
                ]),
                "door":([
                    "none":"",
                    "grayscale" : "\x1b[0;38;5;240m",
                    "3-bit" : "\x1b[0;30;1m",
                    "8-bit" : "\x1b[0;38;5;240m",
                    "24-bit" : "\x1b[0;38;2;58;52;46m",
                ])
            ])
        ]),
            "ascii": ({ ({ "+", "#door#\\", "=", }),
                ({ "#door#/", "#floor# ", "#floor# ", }),
                ({ "+", "#door#\\", "=", }) }),
            "unicode" : ({ ({ "\u256c", "#door#\u2594", "\u2569" }),
                ({ "#door#\u2503", "#floor#\u2591", "#floor#\u2591" }),
                ({ "\u256c", "#door#\u2581", "\u2566" }) })
    ]),
    "crypt interior west alcove north entry": ([
        "colors":([
            "none":"",
            "grayscale" : "\x1b[0;38;5;237m",
            "3-bit" : "\x1b[0;30;1m",
            "8-bit" : "\x1b[0;38;5;237m",
            "24-bit" : "\x1b[0;38;2;58;58;62m",
            "icons" : ([
                "floor":([
                    "none":"",
                    "grayscale" : "\x1b[0;38;5;235m",
                    "3-bit" : "\x1b[0;30m",
                    "8-bit" : "\x1b[0;38;5;235m",
                    "24-bit" : "\x1b[0;38;2;38;38;42m",
                ]),
                "door":([
                    "none":"",
                    "grayscale" : "\x1b[0;38;5;240m",
                    "3-bit" : "\x1b[0;30;1m",
                    "8-bit" : "\x1b[0;38;5;240m",
                    "24-bit" : "\x1b[0;38;2;58;52;46m",
                ])
            ])
        ]),
            "ascii": ({ ({ "+", "#door#\\", "+", }),
                ({ "|", "#floor# ", "#floor# ", }),
                ({ "+", "=", "=", }) }),
            "unicode" : ({ ({ "\u256c", "#door#\u2594", "\u2569" }),
                ({ "\u2551", "#floor#\u2591", "#floor#\u2591" }),
                ({ "\u255a", "\u2550", "\u2550" }) })
    ]),
    "crypt interior west alcove south entry": ([
        "colors":([
            "none":"",
            "grayscale" : "\x1b[0;38;5;237m",
            "3-bit" : "\x1b[0;30;1m",
            "8-bit" : "\x1b[0;38;5;237m",
            "24-bit" : "\x1b[0;38;2;58;58;62m",
            "icons" : ([
                "floor":([
                    "none":"",
                    "grayscale" : "\x1b[0;38;5;235m",
                    "3-bit" : "\x1b[0;30m",
                    "8-bit" : "\x1b[0;38;5;235m",
                    "24-bit" : "\x1b[0;38;2;38;38;42m",
                ]),
                "door":([
                    "none":"",
                    "grayscale" : "\x1b[0;38;5;240m",
                    "3-bit" : "\x1b[0;30;1m",
                    "8-bit" : "\x1b[0;38;5;240m",
                    "24-bit" : "\x1b[0;38;2;58;52;46m",
                ])
            ])
        ]),
            "ascii": ({ ({ "+", "=", "=", }),
                ({ "|", "#floor# ", "#floor# ", }),
                ({ "+", "#door#\\", "+", }) }),
            "unicode" : ({ ({ "\u2554", "\u2550", "\u2550" }),
                ({ "\u2551", "#floor#\u2591", "#floor#\u2591" }),
                ({ "\u256c", "#door#\u2581", "\u2566" }) })
    ]),
    "crypt interior west alcove north-south entry": ([
        "colors":([
            "none":"",
            "grayscale" : "\x1b[0;38;5;237m",
            "3-bit" : "\x1b[0;30;1m",
            "8-bit" : "\x1b[0;38;5;237m",
            "24-bit" : "\x1b[0;38;2;58;58;62m",
            "icons" : ([
                "floor":([
                    "none":"",
                    "grayscale" : "\x1b[0;38;5;235m",
                    "3-bit" : "\x1b[0;30m",
                    "8-bit" : "\x1b[0;38;5;235m",
                    "24-bit" : "\x1b[0;38;2;38;38;42m",
                ]),
                "door":([
                    "none":"",
                    "grayscale" : "\x1b[0;38;5;240m",
                    "3-bit" : "\x1b[0;30;1m",
                    "8-bit" : "\x1b[0;38;5;240m",
                    "24-bit" : "\x1b[0;38;2;58;52;46m",
                ])
            ])
        ]),
            "ascii": ({ ({ "+", "#door#\\", "+" }),
            ({ "|", "#floor# ", "#floor# ", }),
            ({ "+", "#door#\\", "+" }) }),
            "unicode" : ({ ({ "\u256c", "#door#\u2594", "\u2569" }),
                ({ "\u2551", "#floor#\u2591", "#floor#\u2591" }),
                ({ "\u255a", "\u2550", "\u2550" }) })
    ]),

    // East Alcove Variants
    "crypt interior east entry alcove": ([
        "colors":([
            "none":"",
            "grayscale" : "\x1b[0;38;5;237m",
            "3-bit" : "\x1b[0;30;1m",
            "8-bit" : "\x1b[0;38;5;237m",
            "24-bit" : "\x1b[0;38;2;58;58;62m",
            "icons" : ([
                "floor":([
                    "none":"",
                    "grayscale" : "\x1b[0;38;5;235m",
                    "3-bit" : "\x1b[0;30m",
                    "8-bit" : "\x1b[0;38;5;235m",
                    "24-bit" : "\x1b[0;38;2;38;38;42m",
                ]),
                "door":([
                    "none":"",
                    "grayscale" : "\x1b[0;38;5;240m",
                    "3-bit" : "\x1b[0;30;1m",
                    "8-bit" : "\x1b[0;38;5;240m",
                    "24-bit" : "\x1b[0;38;2;58;52;46m",
                ])
            ])
        ]),
            "ascii": ({ ({ "=", "=", "+", }),
                ({ "#floor# ", "#floor# ", "#door#/", }),
                ({ "=", "=", "+", }) }),
            "unicode" : ({ ({ "\u2550", "\u2550", "\u256c", }),
                ({ "#floor#\u2591", "#floor#\u2591", "#door#\u2503", }),
                ({ "\u2550", "\u2550","\u256c", }) })
    ]),
    "crypt interior east-south entry alcove": ([
        "colors":([
            "none":"",
            "grayscale" : "\x1b[0;38;5;237m",
            "3-bit" : "\x1b[0;30;1m",
            "8-bit" : "\x1b[0;38;5;237m",
            "24-bit" : "\x1b[0;38;2;58;58;62m",
            "icons" : ([
                "floor":([
                    "none":"",
                    "grayscale" : "\x1b[0;38;5;235m",
                    "3-bit" : "\x1b[0;30m",
                    "8-bit" : "\x1b[0;38;5;235m",
                    "24-bit" : "\x1b[0;38;2;38;38;42m",
                ]),
                "door":([
                    "none":"",
                    "grayscale" : "\x1b[0;38;5;240m",
                    "3-bit" : "\x1b[0;30;1m",
                    "8-bit" : "\x1b[0;38;5;240m",
                    "24-bit" : "\x1b[0;38;2;58;52;46m",
                ])
            ])
        ]),
            "ascii": ({ ({ "=", "=", "+", }),
                ({ "#floor# ", "#floor# ", "#door#/", }),
                ({ "+", "#door#\\", "=", }) }),
            "unicode" : ({ ({ "\u2550", "\u2550", "\u256c", }),
                ({ "#floor#\u2591", "#floor#\u2591", "#door#\u2503", }),
                ({ "\u2566", "#door#\u2581","\u256c", }) })
    ]),
    "crypt interior east-north entry alcove": ([
        "colors":([
            "none":"",
            "grayscale" : "\x1b[0;38;5;237m",
            "3-bit" : "\x1b[0;30;1m",
            "8-bit" : "\x1b[0;38;5;237m",
            "24-bit" : "\x1b[0;38;2;58;58;62m",
            "icons" : ([
                "floor":([
                    "none":"",
                    "grayscale" : "\x1b[0;38;5;235m",
                    "3-bit" : "\x1b[0;30m",
                    "8-bit" : "\x1b[0;38;5;235m",
                    "24-bit" : "\x1b[0;38;2;38;38;42m",
                ]),
                "door":([
                    "none":"",
                    "grayscale" : "\x1b[0;38;5;240m",
                    "3-bit" : "\x1b[0;30;1m",
                    "8-bit" : "\x1b[0;38;5;240m",
                    "24-bit" : "\x1b[0;38;2;58;52;46m",
                ])
            ])
        ]),
            "ascii": ({ ({ "+", "#door#\\", "=", }),
                ({ "#floor# ", "#floor# ", "#door#/", }),
                ({ "=", "=", "+", }) }),
            "unicode" : ({ ({ "\u2569", "#door#\u2594", "\u256c", }),
                ({ "#floor#\u2591", "#floor#\u2591", "#door#\u2503", }),
                ({ "\u2550", "\u2550", "\u256c", }) })
    ]),
    "crypt interior east-south-north entry alcove": ([
        "colors":([
            "none":"",
            "grayscale" : "\x1b[0;38;5;237m",
            "3-bit" : "\x1b[0;30;1m",
            "8-bit" : "\x1b[0;38;5;237m",
            "24-bit" : "\x1b[0;38;2;58;58;62m",
            "icons" : ([
                "floor":([
                    "none":"",
                    "grayscale" : "\x1b[0;38;5;235m",
                    "3-bit" : "\x1b[0;30m",
                    "8-bit" : "\x1b[0;38;5;235m",
                    "24-bit" : "\x1b[0;38;2;38;38;42m",
                ]),
                "door":([
                    "none":"",
                    "grayscale" : "\x1b[0;38;5;240m",
                    "3-bit" : "\x1b[0;30;1m",
                    "8-bit" : "\x1b[0;38;5;240m",
                    "24-bit" : "\x1b[0;38;2;58;52;46m",
                ])
            ])
        ]),
            "ascii": ({ ({ "+", "#door#\\", "+", }),
                ({ "#floor# ", "#floor# ", "#door#/", }),
                ({ "+", "#door#\\", "=", }) }),
            "unicode" : ({ ({ "\u2569", "#door#\u2594", "\u256c", }),
                ({ "#floor#\u2591", "#floor#\u2591", "#door#\u2503", }),
                ({ "\u2566", "#door#\u2581","\u256c", }) })
    ]),
    "crypt interior east alcove north entry": ([
        "colors":([
            "none":"",
            "grayscale" : "\x1b[0;38;5;237m",
            "3-bit" : "\x1b[0;30;1m",
            "8-bit" : "\x1b[0;38;5;237m",
            "24-bit" : "\x1b[0;38;2;58;58;62m",
            "icons" : ([
                "floor":([
                    "none":"",
                    "grayscale" : "\x1b[0;38;5;235m",
                    "3-bit" : "\x1b[0;30m",
                    "8-bit" : "\x1b[0;38;5;235m",
                    "24-bit" : "\x1b[0;38;2;38;38;42m",
                ]),
                "door":([
                    "none":"",
                    "grayscale" : "\x1b[0;38;5;240m",
                    "3-bit" : "\x1b[0;30;1m",
                    "8-bit" : "\x1b[0;38;5;240m",
                    "24-bit" : "\x1b[0;38;2;58;52;46m",
                ])
            ])
        ]),
            "ascii": ({ ({ "+", "#door#\\", "+", }),
                ({ "#floor# ", "#floor# ", "|", }),
                ({ "=", "=", "+", }) }),
            "unicode" : ({ ({ "\u2569", "#door#\u2594", "\u256c" }),
                ({ "#floor#\u2591", "#floor#\u2591", "\u2551" }),
                ({ "\u2566", "#door#\u2581","\u256c" }) })
    ]),
    "crypt interior east alcove south entry": ([
        "colors":([
            "none":"",
            "grayscale" : "\x1b[0;38;5;237m",
            "3-bit" : "\x1b[0;30;1m",
            "8-bit" : "\x1b[0;38;5;237m",
            "24-bit" : "\x1b[0;38;2;58;58;62m",
            "icons" : ([
                "floor":([
                    "none":"",
                    "grayscale" : "\x1b[0;38;5;235m",
                    "3-bit" : "\x1b[0;30m",
                    "8-bit" : "\x1b[0;38;5;235m",
                    "24-bit" : "\x1b[0;38;2;38;38;42m",
                ]),
                "door":([
                    "none":"",
                    "grayscale" : "\x1b[0;38;5;240m",
                    "3-bit" : "\x1b[0;30;1m",
                    "8-bit" : "\x1b[0;38;5;240m",
                    "24-bit" : "\x1b[0;38;2;58;52;46m",
                ])
            ])
        ]),
            "ascii": ({ ({ "=", "=", "+", }),
                ({ "#floor# ", "#floor# ", "|", }),
                ({ "+", "#door#\\", "+", }) }),
            "unicode" : ({ ({ "\u2550", "\u2550", "\u2557" }),
                ({ "#floor#\u2591", "#floor#\u2591", "\u2551" }),
                ({ "\u2566", "#door#\u2581","\u256c" }) })
    ]),
    "crypt interior east alcove north-south entry": ([
        "colors":([
            "none":"",
            "grayscale" : "\x1b[0;38;5;237m",
            "3-bit" : "\x1b[0;30;1m",
            "8-bit" : "\x1b[0;38;5;237m",
            "24-bit" : "\x1b[0;38;2;58;58;62m",
            "icons" : ([
                "floor":([
                    "none":"",
                    "grayscale" : "\x1b[0;38;5;235m",
                    "3-bit" : "\x1b[0;30m",
                    "8-bit" : "\x1b[0;38;5;235m",
                    "24-bit" : "\x1b[0;38;2;38;38;42m",
                ]),
                "door":([
                    "none":"",
                    "grayscale" : "\x1b[0;38;5;240m",
                    "3-bit" : "\x1b[0;30;1m",
                    "8-bit" : "\x1b[0;38;5;240m",
                    "24-bit" : "\x1b[0;38;2;58;52;46m",
                ])
            ])
        ]),
            "ascii": ({ ({ "+", "#door#\\", "+", }),
                ({ "#floor# ", "#floor# ", "|", }),
                ({ "+", "#door#\\", "+", }) }),
            "unicode" : ({ ({ "\u2569", "#door#\u2594", "\u256c" }),
                ({ "#floor#\u2591", "#floor#\u2591", "\u2551" }),
                ({ "\u2566", "#door#\u2581","\u256c" }) })
    ]),

    // Corner Hallways
    "crypt interior north-west corner hallway": ([
        "colors":([
            "none":"",
            "grayscale" : "\x1b[0;38;5;237m",
            "3-bit" : "\x1b[0;30;1m",
            "8-bit" : "\x1b[0;38;5;237m",
            "24-bit" : "\x1b[0;38;2;58;58;62m",
            "icons" : ([
                "floor":([
                    "none":"",
                    "grayscale" : "\x1b[0;38;5;235m",
                    "3-bit" : "\x1b[0;30m",
                    "8-bit" : "\x1b[0;38;5;235m",
                    "24-bit" : "\x1b[0;38;2;38;38;42m",
                ]),
            ])
        ]),
            "ascii": ({ ({ "+", "#floor# ", "|", }),
                ({ "#floor# ", "#floor# ", "|", }),
                ({ "=", "=", "+", }) }),
            "unicode" : ({ ({ "\u255d", "#floor#\u2591", "\u2551" }),
                ({ "#floor#\u2591", "#floor#\u2591", "\u2551" }),
                ({ "\u2550", "\u2550", "\u255d" }) })
    ]),
    "crypt interior north-west corner hallway south entry": ([
        "colors":([
            "none":"",
            "grayscale" : "\x1b[0;38;5;237m",
            "3-bit" : "\x1b[0;30;1m",
            "8-bit" : "\x1b[0;38;5;237m",
            "24-bit" : "\x1b[0;38;2;58;58;62m",
            "icons" : ([
                "floor":([
                    "none":"",
                    "grayscale" : "\x1b[0;38;5;235m",
                    "3-bit" : "\x1b[0;30m",
                    "8-bit" : "\x1b[0;38;5;235m",
                    "24-bit" : "\x1b[0;38;2;38;38;42m",
                ]),
                "door":([
                    "none":"",
                    "grayscale" : "\x1b[0;38;5;240m",
                    "3-bit" : "\x1b[0;30;1m",
                    "8-bit" : "\x1b[0;38;5;240m",
                    "24-bit" : "\x1b[0;38;2;58;52;46m",
                ])
            ])
        ]),
            "ascii": ({ ({ "+", "#floor# ", "|", }),
                ({ "#floor# ", "#floor# ", "|", }),
                ({ "=", "#door#\\", "+", }) }),
            "unicode" : ({ ({ "\u255d", "#floor#\u2591", "\u2551" }),
                ({ "#floor#\u2591", "#floor#\u2591", "\u2551" }),
                ({ "\u2557", "#door#\u2581", "\u2563" }) })
    ]),
    "crypt interior north-west corner hallway east entry": ([
        "colors":([
            "none":"",
            "grayscale" : "\x1b[0;38;5;237m",
            "3-bit" : "\x1b[0;30;1m",
            "8-bit" : "\x1b[0;38;5;237m",
            "24-bit" : "\x1b[0;38;2;58;58;62m",
            "icons" : ([
                "floor":([
                    "none":"",
                    "grayscale" : "\x1b[0;38;5;235m",
                    "3-bit" : "\x1b[0;30m",
                    "8-bit" : "\x1b[0;38;5;235m",
                    "24-bit" : "\x1b[0;38;2;38;38;42m",
                ]),
                "door":([
                    "none":"",
                    "grayscale" : "\x1b[0;38;5;240m",
                    "3-bit" : "\x1b[0;30;1m",
                    "8-bit" : "\x1b[0;38;5;240m",
                    "24-bit" : "\x1b[0;38;2;58;52;46m",
                ])
            ])
        ]),
            "ascii": ({ ({ "+", "#floor# ", "+", }),
                ({ "#floor# ", "#floor# ", "#door#/", }),
                ({ "=", "=", "+", }) }),
            "unicode" : ({ ({ "\u255d", "#floor#\u2591", "\u2560" }),
                ({ "#floor#\u2591", "#floor#\u2591", "#door#\u2503" }),
                ({ "\u2550", "\u2550", "\u2569" }) })
    ]),
    "crypt interior north-west corner hallway south-east entry": ([
        "colors":([
            "none":"",
            "grayscale" : "\x1b[0;38;5;237m",
            "3-bit" : "\x1b[0;30;1m",
            "8-bit" : "\x1b[0;38;5;237m",
            "24-bit" : "\x1b[0;38;2;58;58;62m",
            "icons" : ([
                "floor":([
                    "none":"",
                    "grayscale" : "\x1b[0;38;5;235m",
                    "3-bit" : "\x1b[0;30m",
                    "8-bit" : "\x1b[0;38;5;235m",
                    "24-bit" : "\x1b[0;38;2;38;38;42m",
                ]),
                "door":([
                    "none":"",
                    "grayscale" : "\x1b[0;38;5;240m",
                    "3-bit" : "\x1b[0;30;1m",
                    "8-bit" : "\x1b[0;38;5;240m",
                    "24-bit" : "\x1b[0;38;2;58;52;46m",
                ])
            ])
        ]),
            "ascii": ({ ({ "+", "#floor# ", "+", }),
                ({ "#floor# ", "#floor# ", "#door#/", }),
                ({ "=", "#door#\\", "+", }) }),
            "unicode" : ({ ({ "\u255d", "#floor#\u2591", "\u2560" }),
                ({ "#floor#\u2591", "#floor#\u2591", "#door#\u2503" }),
                ({ "\u2557", "#door#\u2581", "\u256c" }) })
    ]),
    "crypt interior south-west corner hallway": ([
        "colors":([
            "none":"",
            "grayscale" : "\x1b[0;38;5;237m",
            "3-bit" : "\x1b[0;30;1m",
            "8-bit" : "\x1b[0;38;5;237m",
            "24-bit" : "\x1b[0;38;2;58;58;62m",
            "icons" : ([
                "floor":([
                    "none":"",
                    "grayscale" : "\x1b[0;38;5;235m",
                    "3-bit" : "\x1b[0;30m",
                    "8-bit" : "\x1b[0;38;5;235m",
                    "24-bit" : "\x1b[0;38;2;38;38;42m",
                ]),
            ])
        ]),
            "ascii": ({ ({ "=", "=", "+", }),
                ({ "#floor# ", "#floor# ", "|", }),
                ({ "+", "#floor# ", "|", }) }),
            "unicode" : ({ ({ "\u2550", "\u2550", "\u2557" }),
                ({ "#floor#\u2591", "#floor#\u2591", "\u2551" }),
                ({ "\u2557", "#floor#\u2591", "\u2551" }) })
    ]),
    "crypt interior south-west corner hallway north entry": ([
        "colors":([
            "none":"",
            "grayscale" : "\x1b[0;38;5;237m",
            "3-bit" : "\x1b[0;30;1m",
            "8-bit" : "\x1b[0;38;5;237m",
            "24-bit" : "\x1b[0;38;2;58;58;62m",
            "icons" : ([
                "floor":([
                    "none":"",
                    "grayscale" : "\x1b[0;38;5;235m",
                    "3-bit" : "\x1b[0;30m",
                    "8-bit" : "\x1b[0;38;5;235m",
                    "24-bit" : "\x1b[0;38;2;38;38;42m",
                ]),
                "door":([
                    "none":"",
                    "grayscale" : "\x1b[0;38;5;240m",
                    "3-bit" : "\x1b[0;30;1m",
                    "8-bit" : "\x1b[0;38;5;240m",
                    "24-bit" : "\x1b[0;38;2;58;52;46m",
                ])
            ])
        ]),
            "ascii": ({ ({ "+", "#door#\\", "+", }),
                ({ "#floor# ", "#floor# ", "|", }),
                ({ "+", "#floor# ", "|", }) }),
            "unicode" : ({ ({ "\u2569", "#door#\u2594","\u2563" }),
                ({ "#floor#\u2591", "#floor#\u2591", "\u2551" }),
                ({ "\u2557", "#floor#\u2591", "\u2551" }) })
    ]),
    "crypt interior south-west corner hallway east entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;58;58;62m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;235m",
                    "3-bit": "\x1b[0;30m",
                    "8-bit": "\x1b[0;38;5;235m",
                    "24-bit": "\x1b[0;38;2;38;38;42m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;240m",
                    "3-bit": "\x1b[0;30;1m",
                    "8-bit": "\x1b[0;38;5;240m",
                    "24-bit": "\x1b[0;38;2;58;52;46m",
                ])
            ])
        ]),
        "ascii": ({ ({ "=", "=", "+", }),
            ({ "#floor# ", "#floor# ", "#door#/", }),
            ({ "+", "#floor# ", "|", }) }),
        "unicode": ({ ({ "\u2550", "\u2550", "\u2566" }),
            ({ "#floor#\u2591", "#floor#\u2591", "#door#\u2503" }),
            ({ "\u2557", "#floor#\u2591", "\u2551" }) })
    ]),
    "crypt interior south-west corner hallway north-east entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;58;58;62m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;235m",
                    "3-bit": "\x1b[0;30m",
                    "8-bit": "\x1b[0;38;5;235m",
                    "24-bit": "\x1b[0;38;2;38;38;42m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;240m",
                    "3-bit": "\x1b[0;30;1m",
                    "8-bit": "\x1b[0;38;5;240m",
                    "24-bit": "\x1b[0;38;2;58;52;46m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#door#\\", "+", }),
            ({ "#floor# ", "#floor# ", "#door#/", }),
            ({ "+", "#floor# ", "|", }) }),
        "unicode": ({ ({ "\u2569", "#door#\u2594", "\u256c" }),
            ({ "#floor#\u2591", "#floor#\u2591", "#door#\u2503" }),
            ({ "\u2557", "#floor#\u2591", "\u2551" }) })
    ]),
    "crypt interior north-east corner hallway": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;58;58;62m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;235m",
                    "3-bit": "\x1b[0;30m",
                    "8-bit": "\x1b[0;38;5;235m",
                    "24-bit": "\x1b[0;38;2;38;38;42m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "|", "#floor# ", "+", }),
            ({ "|", "#floor# ", "#floor# ", }),
            ({ "=", "=", "+", }) }),
        "unicode": ({ ({ "\u2551", "#floor#\u2591", "\u255a" }),
            ({ "\u2551", "#floor#\u2591", "#floor#\u2591" }),
            ({ "\u255a", "\u2550", "\u2550" }) })
    ]),
    "crypt interior north-east corner hallway west entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;58;58;62m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;235m",
                    "3-bit": "\x1b[0;30m",
                    "8-bit": "\x1b[0;38;5;235m",
                    "24-bit": "\x1b[0;38;2;38;38;42m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;240m",
                    "3-bit": "\x1b[0;30;1m",
                    "8-bit": "\x1b[0;38;5;240m",
                    "24-bit": "\x1b[0;38;2;58;52;46m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#floor# ", "+", }),
            ({ "#door#/", "#floor# ", "#floor# ", }),
            ({ "=", "=", "+", }) }),
        "unicode": ({ ({ "\u2563", "#floor#\u2591", "\u255a" }),
            ({ "#door#\u2503", "#floor#\u2591", "#floor#\u2591" }),
            ({ "\u2569", "\u2550", "\u2550" }) })
    ]),
    "crypt interior north-east corner hallway south entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;58;58;62m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;235m",
                    "3-bit": "\x1b[0;30m",
                    "8-bit": "\x1b[0;38;5;235m",
                    "24-bit": "\x1b[0;38;2;38;38;42m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;240m",
                    "3-bit": "\x1b[0;30;1m",
                    "8-bit": "\x1b[0;38;5;240m",
                    "24-bit": "\x1b[0;38;2;58;52;46m",
                ])
            ])
        ]),
        "ascii": ({ ({ "|", "#floor# ", "+", }),
            ({ "|", "#floor# ", "#floor# ", }),
            ({ "=", "#door#\\", "+", }) }),
        "unicode": ({ ({ "\u2551", "#floor#\u2591", "\u255a" }),
            ({ "\u2551", "#floor#\u2591", "#floor#\u2591" }),
            ({ "\u2560", "#door#\u2581", "\u2566" }) })
    ]),
    "crypt interior north-east corner hallway south-west entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;58;58;62m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;235m",
                    "3-bit": "\x1b[0;30m",
                    "8-bit": "\x1b[0;38;5;235m",
                    "24-bit": "\x1b[0;38;2;38;38;42m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;240m",
                    "3-bit": "\x1b[0;30;1m",
                    "8-bit": "\x1b[0;38;5;240m",
                    "24-bit": "\x1b[0;38;2;58;52;46m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#floor# ", "+", }),
            ({ "#door#/", "#floor# ", "#floor# ", }),
            ({ "+", "#door#\\", "+", }) }),
        "unicode": ({ ({ "\u2563", "#floor#\u2591", "\u255a" }),
            ({ "#door#\u2503", "#floor#\u2591", "#floor#\u2591" }),
            ({ "\u256c", "#door#\u2581", "\u2566" }) })
    ]),
    "crypt interior south-east corner hallway": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;58;58;62m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;235m",
                    "3-bit": "\x1b[0;30m",
                    "8-bit": "\x1b[0;38;5;235m",
                    "24-bit": "\x1b[0;38;2;38;38;42m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "+", "=", "=", }),
            ({ "|", "#floor# ", "#floor# ", }),
            ({ "|", "#floor# ", "+", }) }),
        "unicode": ({ ({ "\u2554", "\u2550", "\u2550" }),
            ({ "\u2551", "#floor#\u2591", "#floor#\u2591" }),
            ({ "\u2551", "#floor#\u2591", "\u2554" }) })
    ]),
    "crypt interior south-east corner hallway west entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;58;58;62m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;235m",
                    "3-bit": "\x1b[0;30m",
                    "8-bit": "\x1b[0;38;5;235m",
                    "24-bit": "\x1b[0;38;2;38;38;42m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;240m",
                    "3-bit": "\x1b[0;30;1m",
                    "8-bit": "\x1b[0;38;5;240m",
                    "24-bit": "\x1b[0;38;2;58;52;46m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "=", "=", }),
            ({ "#door#/", "#floor# ", "#floor# ", }),
            ({ "+", "#floor# ", "+", }) }),
        "unicode": ({ ({ "\u2566", "\u2550", "\u2550" }),
            ({ "#door#\u2503", "#floor#\u2591", "#floor#\u2591" }),
            ({ "\u2563", "#floor#\u2591", "\u2554" }) })
    ]),
    "crypt interior south-east corner hallway north entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;58;58;62m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;235m",
                    "3-bit": "\x1b[0;30m",
                    "8-bit": "\x1b[0;38;5;235m",
                    "24-bit": "\x1b[0;38;2;38;38;42m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;240m",
                    "3-bit": "\x1b[0;30;1m",
                    "8-bit": "\x1b[0;38;5;240m",
                    "24-bit": "\x1b[0;38;2;58;52;46m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#door#\\", "+", }),
            ({ "|", "#floor# ", "#floor# ", }),
            ({ "|", "#floor# ", "+", }) }),
        "unicode": ({ ({ "\u2560", "#door#\u2594", "\u2569" }),
            ({ "\u2551", "#floor#\u2591", "#floor#\u2591" }),
            ({ "\u2551", "#floor#\u2591", "\u2554" }) })
    ]),
    "crypt interior south-east corner hallway north-west entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;58;58;62m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;235m",
                    "3-bit": "\x1b[0;30m",
                    "8-bit": "\x1b[0;38;5;235m",
                    "24-bit": "\x1b[0;38;2;38;38;42m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;240m",
                    "3-bit": "\x1b[0;30;1m",
                    "8-bit": "\x1b[0;38;5;240m",
                    "24-bit": "\x1b[0;38;2;58;52;46m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#door#\\", "+", }),
            ({ "#door#/", "#floor# ", "#floor# ", }),
            ({ "+", "#floor# ", "+", }) }),
        "unicode": ({ ({ "\u256c", "#door#\u2594", "\u2569" }),
            ({ "#door#\u2503", "#floor#\u2591", "#floor#\u2591" }),
            ({ "\u2563", "#floor#\u2591", "\u2554" }) })
    ]),

    // Large Room Components
    "crypt interior southeast corner": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;58;58;62m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;235m",
                    "3-bit": "\x1b[0;30m",
                    "8-bit": "\x1b[0;38;5;235m",
                    "24-bit": "\x1b[0;38;2;38;38;42m",
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
    "crypt interior southeast corner south entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;58;58;62m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;235m",
                    "3-bit": "\x1b[0;30m",
                    "8-bit": "\x1b[0;38;5;235m",
                    "24-bit": "\x1b[0;38;2;38;38;42m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;240m",
                    "3-bit": "\x1b[0;30;1m",
                    "8-bit": "\x1b[0;38;5;240m",
                    "24-bit": "\x1b[0;38;2;58;52;46m",
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
    "crypt interior southeast corner east entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;58;58;62m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;235m",
                    "3-bit": "\x1b[0;30m",
                    "8-bit": "\x1b[0;38;5;235m",
                    "24-bit": "\x1b[0;38;2;38;38;42m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;240m",
                    "3-bit": "\x1b[0;30;1m",
                    "8-bit": "\x1b[0;38;5;240m",
                    "24-bit": "\x1b[0;38;2;58;52;46m",
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
    "crypt interior southeast corner south-east entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;58;58;62m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;235m",
                    "3-bit": "\x1b[0;30m",
                    "8-bit": "\x1b[0;38;5;235m",
                    "24-bit": "\x1b[0;38;2;38;38;42m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;240m",
                    "3-bit": "\x1b[0;30;1m",
                    "8-bit": "\x1b[0;38;5;240m",
                    "24-bit": "\x1b[0;38;2;58;52;46m",
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
    "crypt interior northeast corner": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;58;58;62m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;235m",
                    "3-bit": "\x1b[0;30m",
                    "8-bit": "\x1b[0;38;5;235m",
                    "24-bit": "\x1b[0;38;2;38;38;42m",
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
    "crypt interior northeast corner north entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;58;58;62m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;235m",
                    "3-bit": "\x1b[0;30m",
                    "8-bit": "\x1b[0;38;5;235m",
                    "24-bit": "\x1b[0;38;2;38;38;42m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;240m",
                    "3-bit": "\x1b[0;30;1m",
                    "8-bit": "\x1b[0;38;5;240m",
                    "24-bit": "\x1b[0;38;2;58;52;46m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#door#\\", "+", }),
            ({ "#floor# ", "#floor# ", "|", }),
            ({ "#floor# ", "#floor# ", "|", }) }),
        "unicode": ({ ({ "\u2569", "#door#\u2594", "\u2563" }),
            ({ "#floor#\u2591", "#floor#\u2591", "\u2551" }),
            ({ "#floor#\u2591", "#floor#\u2591", "\u2551" }) })
    ]),
    "crypt interior northeast corner east entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;58;58;62m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;235m",
                    "3-bit": "\x1b[0;30m",
                    "8-bit": "\x1b[0;38;5;235m",
                    "24-bit": "\x1b[0;38;2;38;38;42m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;240m",
                    "3-bit": "\x1b[0;30;1m",
                    "8-bit": "\x1b[0;38;5;240m",
                    "24-bit": "\x1b[0;38;2;58;52;46m",
                ])
            ])
        ]),
        "ascii": ({ ({ "=", "=", "+", }),
            ({ "#floor# ", "#floor# ", "#door#/", }),
            ({ "#floor# ", "#floor# ", "|", }) }),
        "unicode": ({ ({ "\u2550", "\u2550", "\u2566" }),
            ({ "#floor#\u2591", "#floor#\u2591", "#door#\u2503" }),
            ({ "#floor#\u2591", "#floor#\u2591", "\u2560" }) })
    ]),
    "crypt interior northeast corner north-east entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;58;58;62m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;235m",
                    "3-bit": "\x1b[0;30m",
                    "8-bit": "\x1b[0;38;5;235m",
                    "24-bit": "\x1b[0;38;2;38;38;42m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;240m",
                    "3-bit": "\x1b[0;30;1m",
                    "8-bit": "\x1b[0;38;5;240m",
                    "24-bit": "\x1b[0;38;2;58;52;46m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#door#\\", "+", }),
            ({ "#floor# ", "#floor# ", "#door#/", }),
            ({ "#floor# ", "#floor# ", "|", }) }),
        "unicode": ({ ({ "\u2569", "#door#\u2594", "\u256c" }),
            ({ "#floor#\u2591", "#floor#\u2591", "#door#\u2503" }),
            ({ "#floor#\u2591", "#floor#\u2591", "\u2560" }) })
    ]),
    "crypt interior southwest corner": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;58;58;62m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;235m",
                    "3-bit": "\x1b[0;30m",
                    "8-bit": "\x1b[0;38;5;235m",
                    "24-bit": "\x1b[0;38;2;38;38;42m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "|", "#floor# ", "#floor# ", }),
            ({ "|", "#floor# ", "#floor# ", }),
            ({ "=", "=", "+", }) }),
        "unicode": ({ ({ "\u2551", "#floor#\u2591", "#floor#\u2591" }),
            ({ "\u2551", "#floor#\u2591", "#floor#\u2591" }),
            ({ "\u255a", "\u2550", "\u2550" }) })
    ]),
    "crypt interior southwest corner west entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;58;58;62m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;235m",
                    "3-bit": "\x1b[0;30m",
                    "8-bit": "\x1b[0;38;5;235m",
                    "24-bit": "\x1b[0;38;2;38;38;42m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;240m",
                    "3-bit": "\x1b[0;30;1m",
                    "8-bit": "\x1b[0;38;5;240m",
                    "24-bit": "\x1b[0;38;2;58;52;46m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#floor# ", "#floor# ", }),
            ({ "#door#/", "#floor# ", "#floor# ", }),
            ({ "=", "=", "+", }) }),
        "unicode": ({ ({ "\u2563", "#floor#\u2591", "#floor#\u2591" }),
            ({ "#door#\u2503", "#floor#\u2591", "#floor#\u2591" }),
            ({ "\u2569", "\u2550", "\u2550" }) })
    ]),
    "crypt interior southwest corner south entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;58;58;62m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;235m",
                    "3-bit": "\x1b[0;30m",
                    "8-bit": "\x1b[0;38;5;235m",
                    "24-bit": "\x1b[0;38;2;38;38;42m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;240m",
                    "3-bit": "\x1b[0;30;1m",
                    "8-bit": "\x1b[0;38;5;240m",
                    "24-bit": "\x1b[0;38;2;58;52;46m",
                ])
            ])
        ]),
        "ascii": ({ ({ "|", "#floor# ", "#floor# ", }),
            ({ "|", "#floor# ", "#floor# ", }),
            ({ "=", "#door#\\", "+", }) }),
        "unicode": ({ ({ "\u2551", "#floor#\u2591", "#floor#\u2591" }),
            ({ "\u2551", "#floor#\u2591", "#floor#\u2591" }),
            ({ "\u2560", "#door#\u2581", "\u2566" }) })
    ]),
    "crypt interior southwest corner south-west entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;58;58;62m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;235m",
                    "3-bit": "\x1b[0;30m",
                    "8-bit": "\x1b[0;38;5;235m",
                    "24-bit": "\x1b[0;38;2;38;38;42m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;240m",
                    "3-bit": "\x1b[0;30;1m",
                    "8-bit": "\x1b[0;38;5;240m",
                    "24-bit": "\x1b[0;38;2;58;52;46m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#floor# ", "#floor# ", }),
            ({ "#door#/", "#floor# ", "#floor# ", }),
            ({ "+", "#door#\\", "+", }) }),
        "unicode": ({ ({ "\u2563", "#floor#\u2591", "#floor#\u2591" }),
            ({ "#door#\u2503", "#floor#\u2591", "#floor#\u2591" }),
            ({ "\u256c", "#door#\u2581", "\u2566" }) })
    ]),
    "crypt interior northwest corner": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;58;58;62m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;235m",
                    "3-bit": "\x1b[0;30m",
                    "8-bit": "\x1b[0;38;5;235m",
                    "24-bit": "\x1b[0;38;2;38;38;42m",
                ]),
            ])
        ]),
        "ascii": ({ ({ "+", "=", "=", }),
            ({ "|", "#floor# ", "#floor# ", }),
            ({ "|", "#floor# ", "#floor# ", }) }),
        "unicode": ({ ({ "\u2554", "\u2550", "\u2550" }),
            ({ "\u2551", "#floor#\u2591", "#floor#\u2591" }),
            ({ "\u2551", "#floor#\u2591", "#floor#\u2591" }) })
    ]),
    "crypt interior northwest corner west entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;58;58;62m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;235m",
                    "3-bit": "\x1b[0;30m",
                    "8-bit": "\x1b[0;38;5;235m",
                    "24-bit": "\x1b[0;38;2;38;38;42m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;240m",
                    "3-bit": "\x1b[0;30;1m",
                    "8-bit": "\x1b[0;38;5;240m",
                    "24-bit": "\x1b[0;38;2;58;52;46m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "=", "=", }),
            ({ "#door#/", "#floor# ", "#floor# ", }),
            ({ "+", "#floor# ", "#floor# ", }) }),
        "unicode": ({ ({ "\u2566", "\u2550", "\u2550" }),
            ({ "#door#\u2503", "#floor#\u2591", "#floor#\u2591" }),
            ({ "\u2563", "#floor#\u2591", "#floor#\u2591" }) })
    ]),
    "crypt interior northwest corner north entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;58;58;62m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;235m",
                    "3-bit": "\x1b[0;30m",
                    "8-bit": "\x1b[0;38;5;235m",
                    "24-bit": "\x1b[0;38;2;38;38;42m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;240m",
                    "3-bit": "\x1b[0;30;1m",
                    "8-bit": "\x1b[0;38;5;240m",
                    "24-bit": "\x1b[0;38;2;58;52;46m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#door#\\", "=", }),
            ({ "|", "#floor# ", "#floor# ", }),
            ({ "|", "#floor# ", "#floor# ", }) }),
        "unicode": ({ ({ "\u2566", "#door#\u2594", "\u2569" }),
            ({ "\u2551", "#floor#\u2591", "#floor#\u2591" }),
            ({ "\u2551", "#floor#\u2591", "#floor#\u2591" }) })
    ]),
    "crypt interior northwest corner north-west entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;58;58;62m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;235m",
                    "3-bit": "\x1b[0;30m",
                    "8-bit": "\x1b[0;38;5;235m",
                    "24-bit": "\x1b[0;38;2;38;38;42m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;240m",
                    "3-bit": "\x1b[0;30;1m",
                    "8-bit": "\x1b[0;38;5;240m",
                    "24-bit": "\x1b[0;38;2;58;52;46m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#door#\\", "=", }),
            ({ "#door#/", "#floor# ", "#floor# ", }),
            ({ "+", "#floor# ", "#floor# ", }) }),
        "unicode": ({ ({ "\u256c", "#door#\u2594", "\u2569" }),
            ({ "#door#\u2503", "#floor#\u2591", "#floor#\u2591" }),
            ({ "\u2563", "#floor#\u2591", "#floor#\u2591" }) })
    ]),

    // Wall edges
    "crypt interior south wall": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;58;58;62m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;235m",
                    "3-bit": "\x1b[0;30m",
                    "8-bit": "\x1b[0;38;5;235m",
                    "24-bit": "\x1b[0;38;2;38;38;42m",
                ])
            ])
        ]),
        "ascii": ({ ({ "#floor# ", "#floor# ", "#floor# ", }),
            ({ "#floor# ", "#floor# ", "#floor# ", }),
            ({ "=", "=", "=", }) }),
        "unicode": ({ ({ "#floor#\u2591", "#floor#\u2591", "#floor#\u2591" }),
            ({ "#floor#\u2591", "#floor#\u2591", "#floor#\u2591" }),
            ({ "\u2550", "\u2550", "\u2550" }) })
    ]),
    "crypt interior south wall south entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;58;58;62m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;235m",
                    "3-bit": "\x1b[0;30m",
                    "8-bit": "\x1b[0;38;5;235m",
                    "24-bit": "\x1b[0;38;2;38;38;42m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;240m",
                    "3-bit": "\x1b[0;30;1m",
                    "8-bit": "\x1b[0;38;5;240m",
                    "24-bit": "\x1b[0;38;2;58;52;46m",
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
    "crypt interior north wall": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;58;58;62m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;235m",
                    "3-bit": "\x1b[0;30m",
                    "8-bit": "\x1b[0;38;5;235m",
                    "24-bit": "\x1b[0;38;2;38;38;42m",
                ])
            ])
        ]),
        "ascii": ({ ({ "=", "=", "=", }),
            ({ "#floor# ", "#floor# ", "#floor# ", }),
            ({ "#floor# ", "#floor# ", "#floor# ", }) }),
        "unicode": ({ ({ "\u2550", "\u2550", "\u2550" }),
            ({ "#floor#\u2591", "#floor#\u2591", "#floor#\u2591" }),
            ({ "#floor#\u2591", "#floor#\u2591", "#floor#\u2591" }) })
    ]),
    "crypt interior north wall north entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;58;58;62m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;235m",
                    "3-bit": "\x1b[0;30m",
                    "8-bit": "\x1b[0;38;5;235m",
                    "24-bit": "\x1b[0;38;2;38;38;42m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;240m",
                    "3-bit": "\x1b[0;30;1m",
                    "8-bit": "\x1b[0;38;5;240m",
                    "24-bit": "\x1b[0;38;2;58;52;46m",
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
    "crypt interior west wall": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;58;58;62m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;235m",
                    "3-bit": "\x1b[0;30m",
                    "8-bit": "\x1b[0;38;5;235m",
                    "24-bit": "\x1b[0;38;2;38;38;42m",
                ])
            ])
        ]),
        "ascii": ({ ({ "|", "#floor# ", "#floor# ", }),
            ({ "|", "#floor# ", "#floor# ", }),
            ({ "|", "#floor# ", "#floor# ", }) }),
        "unicode": ({ ({ "\u2551", "#floor#\u2591", "#floor#\u2591" }),
            ({ "\u2551", "#floor#\u2591", "#floor#\u2591" }),
            ({ "\u2551", "#floor#\u2591", "#floor#\u2591" }) })
    ]),
    "crypt interior west wall west entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;58;58;62m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;235m",
                    "3-bit": "\x1b[0;30m",
                    "8-bit": "\x1b[0;38;5;235m",
                    "24-bit": "\x1b[0;38;2;38;38;42m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;240m",
                    "3-bit": "\x1b[0;30;1m",
                    "8-bit": "\x1b[0;38;5;240m",
                    "24-bit": "\x1b[0;38;2;58;52;46m",
                ])
            ])
        ]),
        "ascii": ({ ({ "+", "#floor# ", "#floor# ", }),
            ({ "#door#/", "#floor# ", "#floor# ", }),
            ({ "+", "#floor# ", "#floor# ", }) }),
        "unicode": ({ ({ "\u2563", "#floor#\u2591", "#floor#\u2591" }),
            ({ "#door#\u2503", "#floor#\u2591", "#floor#\u2591" }),
            ({ "\u2563", "#floor#\u2591", "#floor#\u2591" }) })
    ]),
    "crypt interior east wall": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;58;58;62m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;235m",
                    "3-bit": "\x1b[0;30m",
                    "8-bit": "\x1b[0;38;5;235m",
                    "24-bit": "\x1b[0;38;2;38;38;42m",
                ])
            ])
        ]),
        "ascii": ({ ({ "#floor# ", "#floor# ", "|", }),
            ({ "#floor# ", "#floor# ", "|", }),
            ({ "#floor# ", "#floor# ", "|", }) }),
        "unicode": ({ ({ "#floor#\u2591", "#floor#\u2591", "\u2551" }),
            ({ "#floor#\u2591", "#floor#\u2591", "\u2551" }),
            ({ "#floor#\u2591", "#floor#\u2591", "\u2551" }) })
    ]),
    "crypt interior east wall east entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;58;58;62m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;235m",
                    "3-bit": "\x1b[0;30m",
                    "8-bit": "\x1b[0;38;5;235m",
                    "24-bit": "\x1b[0;38;2;38;38;42m",
                ]),
                "door":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;240m",
                    "3-bit": "\x1b[0;30;1m",
                    "8-bit": "\x1b[0;38;5;240m",
                    "24-bit": "\x1b[0;38;2;58;52;46m",
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

    // Entry points
    "crypt interior entry": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;58;58;62m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;235m",
                    "3-bit": "\x1b[0;30m",
                    "8-bit": "\x1b[0;38;5;235m",
                    "24-bit": "\x1b[0;38;2;38;38;42m",
                ]),
                "entry":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;250m",
                    "3-bit": "\x1b[0;37;1m",
                    "8-bit": "\x1b[0;38;5;250m",
                    "24-bit": "\x1b[0;38;2;180;180;180m",
                ])
            ])
        ]),
        "ascii": ({ ({ "#floor# ", "#floor# ", "#floor# ", }),
            ({ "#floor# ", "#entry#E ", "#floor# ", }),
            ({ "#floor# ", "#floor# ", "#floor# ", }) }),
        "unicode": ({ ({ "#floor#\u2591", "#floor#\u2591", "#floor#\u2591" }),
            ({ "#floor#\u2591", "#entry#\u2261", "#floor#\u2591" }),
            ({ "#floor#\u2591", "#floor#\u2591", "#floor#\u2591" }) })
    ]),
    "crypt interior entry north": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;58;58;62m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;235m",
                    "3-bit": "\x1b[0;30m",
                    "8-bit": "\x1b[0;38;5;235m",
                    "24-bit": "\x1b[0;38;2;38;38;42m",
                ]),
                "entry":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;250m",
                    "3-bit": "\x1b[0;37;1m",
                    "8-bit": "\x1b[0;38;5;250m",
                    "24-bit": "\x1b[0;38;2;180;180;180m",
                ])
            ])
        ]),
        "ascii": ({ ({ "=", "=", "=", }),
            ({ "#floor# ", "#entry#E ", "#floor# ", }),
            ({ "#floor# ", "#floor# ", "#floor# ", }) }),
        "unicode": ({ ({ "\u2550", "\u2550", "\u2550" }),
            ({ "#floor#\u2591", "#entry#\u2261", "#floor#\u2591" }),
            ({ "#floor#\u2591", "#floor#\u2591", "#floor#\u2591" }) })
    ]),
    "crypt interior entry south": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;58;58;62m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;235m",
                    "3-bit": "\x1b[0;30m",
                    "8-bit": "\x1b[0;38;5;235m",
                    "24-bit": "\x1b[0;38;2;38;38;42m",
                ]),
                "entry":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;250m",
                    "3-bit": "\x1b[0;37;1m",
                    "8-bit": "\x1b[0;38;5;250m",
                    "24-bit": "\x1b[0;38;2;180;180;180m",
                ])
            ])
        ]),
        "ascii": ({ ({ "#floor# ", "#floor# ", "#floor# ", }),
            ({ "#floor# ", "#entry#E ", "#floor# ", }),
            ({ "=", "=", "=", }) }),
        "unicode": ({ ({ "#floor#\u2591", "#floor#\u2591", "#floor#\u2591" }),
            ({ "#floor#\u2591", "#entry#\u2261", "#floor#\u2591" }),
            ({ "\u2550", "\u2550", "\u2550" }) })
    ]),
    "crypt interior entry east": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;58;58;62m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;235m",
                    "3-bit": "\x1b[0;30m",
                    "8-bit": "\x1b[0;38;5;235m",
                    "24-bit": "\x1b[0;38;2;38;38;42m",
                ]),
                "entry":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;250m",
                    "3-bit": "\x1b[0;37;1m",
                    "8-bit": "\x1b[0;38;5;250m",
                    "24-bit": "\x1b[0;38;2;180;180;180m",
                ])
            ])
        ]),
        "ascii": ({ ({ "#floor# ", "#floor# ", "|", }),
            ({ "#floor# ", "#entry#E ", "|", }),
            ({ "#floor# ", "#floor# ", "|", }) }),
        "unicode": ({ ({ "#floor#\u2591", "#floor#\u2591", "\u2551" }),
            ({ "#floor#\u2591", "#entry#\u2261", "\u2551" }),
            ({ "#floor#\u2591", "#floor#\u2591", "\u2551" }) })
    ]),
    "crypt interior entry west": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;58;58;62m",
            "icons": ([
                "floor":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;235m",
                    "3-bit": "\x1b[0;30m",
                    "8-bit": "\x1b[0;38;5;235m",
                    "24-bit": "\x1b[0;38;2;38;38;42m",
                ]),
                "entry":([
                    "none": "",
                    "grayscale": "\x1b[0;38;5;250m",
                    "3-bit": "\x1b[0;37;1m",
                    "8-bit": "\x1b[0;38;5;250m",
                    "24-bit": "\x1b[0;38;2;180;180;180m",
                ])
            ])
        ]),
        "ascii": ({ ({ "|", "#floor# ", "#floor# ", }),
            ({ "|", "#entry#E ", "#floor# ", }),
            ({ "|", "#floor# ", "#floor# ", }) }),
        "unicode": ({ ({ "\u2551", "#floor#\u2591", "#floor#\u2591" }),
            ({ "\u2551", "#entry#\u2261", "#floor#\u2591" }),
            ({ "\u2551", "#floor#\u2591", "#floor#\u2591" }) })
    ]),

    // Walls (solid)
    "crypt interior wall": ([
        "colors": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;237m",
            "24-bit": "\x1b[0;38;2;58;58;62m",
        ]),
        "ascii": ({ ({ "#", "#", "#", }),
            ({ "#", "#", "#", }),
            ({ "#", "#", "#", }) }),
        "unicode": ({ ({ "\u2588", "\u2588", "\u2588" }),
            ({ "\u2588", "\u2588", "\u2588" }),
            ({ "\u2588", "\u2588", "\u2588" }) })
    ]),
]);

#endif
