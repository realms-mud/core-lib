//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef times_of_day_h
#define times_of_day_h

private mapping timesOfDay = ([
    "midnight":([
        "winter": 60,
        "spring": 60,
        "summer": 60,
        "autumn": 60,
        "next": "late night"
    ]),
    "late night":([
        "winter": 390,
        "spring": 330,
        "summer": 270,
        "autumn": 330,
        "next": "dawn"
    ]),
    "dawn":([
        "winter": 450,
        "spring": 390,
        "summer": 330,
        "autumn": 390,
        "next": "morning"
    ]),
    "morning":([
        "winter": 660,
        "spring": 660,
        "summer": 660,
        "autumn": 660,
        "next": "noon"
    ]),
    "noon":([
        "winter": 720,
        "spring": 720,
        "summer": 720,
        "autumn": 720,
        "next": "afternoon"
    ]),
    "afternoon":([
        "winter": 930,
        "spring": 990,
        "summer": 1050,
        "autumn": 990,
        "next": "evening"
    ]),
    "evening":([
        "winter": 1050,
        "spring": 1110,
        "summer": 1170,
        "autumn": 1110,
        "next": "dusk"
    ]),
    "dusk":([
        "winter": 1110,
        "spring": 1170,
        "summer": 1230,
        "autumn": 1170,
        "next": "night"
    ]),
    "night":([
        "winter": 1440,
        "spring": 1440,
        "summer": 1440,
        "autumn": 1440,
        "next": "midnight"
    ])
]);

#endif
