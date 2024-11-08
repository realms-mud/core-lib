//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef moon_phases_h
#define moon_phases_h

private mapping moonPhases = ([
    0: "new moon",
    1: "new moon",
    2: "new moon",
    3: "waxing crescent",
    4: "waxing crescent",
    5: "waxing crescent",
    6: "waxing crescent",
    7: "first quarter",
    8: "first quarter",
    9: "first quarter",
    10: "waxing gibbous",
    11: "waxing gibbous",
    12: "waxing gibbous",
    13: "waxing gibbous",
    14: "full moon",
    15: "full moon",
    16: "full moon",
    17: "waning gibbous",
    18: "waning gibbous",
    19: "waning gibbous",
    20: "waning gibbous",
    21: "last quarter",
    22: "last quarter",
    23: "last quarter",
    24: "waning crescent",
    25: "waning crescent",
    26: "waning crescent",
    27: "waning crescent",
]);

private mapping moonLightLevel = ([
    "new moon": 1,
    "waxing crescent": 2,
    "first quarter": 3,
    "waxing gibbous": 4,
    "full moon": 5,
    "waning gibbous": 4,
    "last quarter": 3,
    "waning crescent": 2,
]);

#endif
