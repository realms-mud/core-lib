//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef floor_plans_h
#define floor_plans_h

private mapping FloorPlans = ([
    "shop 1": ([
        "type": "shop",
        "x dimension": 2,
        "y dimension": 2,
        "rooms": ({ 
            ([
                "x": 0,
                "y": 0,
                "name": "0x0",
                "is placed": 1,
                "room type": "room",
                "exits" : ([
                    "north": "0x1",
                    "east": "1x0"
                ])
            ]),
            ([
                "x": 0,
                "y": 1,
                "name": "0x1",
                "is placed": 1,
                "room type": "room",
                "exits" : ([
                    "south": "0x0",
                    "east": "1x1"
                ])
            ]),
            ([
                "x": 1,
                "y": 0,
                "name": "1x0",
                "is placed": 1,
                "room type": "room",
                "exits" : ([
                    "north": "1x1",
                    "west": "0x0"
                ])
            ]),
            ([
                "x": 1,
                "y": 1,
                "name": "1x1",
                "is placed": 1,
                "room type": "room",
                "exits" : ([
                    "south": "1x0",
                    "west": "0x1"
                ])
            ]),
        }),
        "decorators": ({ })
    ])
]);

#endif
