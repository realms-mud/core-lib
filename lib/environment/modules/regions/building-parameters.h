//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef buildingParameters_h
#define buildingParameters_h

#include "building-room-types.h"

protected mapping buildingParameters = ([
    "temple": ([
        "base type": "temple interior",
        "room types": roomTypes,
        "min width": 18,
        "max width": 25,
        "min height": 9,
        "max height": 11,
        "min room size": 4,
        "complexity": 4,
        "special room": 3,
        "outdoor room": 5,
        "has courtyard": 1
    ]),
    "keep": ([
        "base type": "keep interior",
        "room types": roomTypes,
        "min width": 20,
        "max width": 25,
        "min height": 10,
        "max height": 12,
        "min room size": 5,
        "complexity": 4,
        "special room": 6,
        "outdoor room": 5,
        "secondary outdoor": 7,
        "has courtyard": 1
    ]),
    "crypt": ([
        "base type": "crypt interior",
        "room types": roomTypes,
        "min width": 15,
        "max width": 25,
        "min height": 8,
        "max height": 11,
        "min room size": 4,
        "complexity": 3,
        "special room": 3,
        "outdoor room": 5,
        "has courtyard": 0
    ]),
    "ruins": ([
        "base type": "ruined interior",
        "room types": roomTypes,
        "min width": 18,
        "max width": 25,
        "min height": 9,
        "max height": 11,
        "min room size": 4,
        "complexity": 4,
        "special room": 3,
        "outdoor room": 5,
        "secondary special": 6,
        "has courtyard": 1,
        "ruined": 1
    ])
]);

#endif
