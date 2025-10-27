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
    ]),
    "cave": ([
        "min width": 20,
        "max width": 25,
        "min height": 15,
        "max height": 18,
        "base type": "cave interior",
        "room types": ([
            0: ([ "name": "wall", "icon": "wall" ]),
            1: ([ "name": "corridor", "icon": "base+name" ]),
            2: ([ "name": "chamber", "icon": "base+name" ]),
            3: ([ "name": "crystal chamber", "icon": "base+name" ]),
            4: ([ "name": "entry", "icon": "base+name" ]),
        ])
    ]),
    
    "mine": ([
        "min width": 18,
        "max width": 22,
        "min height": 12,
        "max height": 14,
        "base type": "mine interior",
        "room types": ([
            0: ([ "name": "wall", "icon": "wall" ]),
            1: ([ "name": "shaft", "icon": "base+name" ]),
            2: ([ "name": "mining chamber", "icon": "base+name" ]),
            3: ([ "name": "ore deposit", "icon": "base+name" ]),
            4: ([ "name": "entry", "icon": "base+name" ]),
        ])
    ]),
    
    "dungeon": ([
        "min width": 18,
        "max width": 20,
        "min height": 13,
        "max height": 15,
        "base type": "dungeon interior",
        "room types": ([
            0: ([ "name": "wall", "icon": "wall" ]),
            1: ([ "name": "corridor", "icon": "base+name" ]),
            2: ([ "name": "cell", "icon": "base+name" ]),
            3: ([ "name": "torture chamber", "icon": "base+name" ]),
            4: ([ "name": "entry", "icon": "base+name" ]),
        ])
    ])
]);

#endif
