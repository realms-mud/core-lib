//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef floor_plans_h
#define floor_plans_h

private mapping FloorPlans = ([
    "shop 1": ([
        "type": "wooden shop",
        "interior": "/lib/environment/interiors/wood-interior-shop.c",
        "door": "/lib/environment/doors/door.c",
        "key": 0,
        "x dimension": 4,
        "y dimension": 4,
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
                ]),
                "doors": ({ "north" }),
                "entry for": ({ "north", "east" })
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
                ]),
                "doors": ({ "south", "east" }),
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
                ]),
                "doors": ({ "west" }),
                "entry for": ({ "south", "west" })
            ]),
        }),
        "decorators": ({ })
    ]),
    "shop 2": ([
        "type": "limestone shop",
        "interior": "/lib/environment/interiors/limestone-interior-shop.c",
        "door": "/lib/environment/doors/door.c",
        "key": 0,
        "x dimension": 4,
        "y dimension": 4,
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
                ]),
                "doors": ({ "north" }),
                "entry for": ({ "north", "east" })
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
                ]),
                "doors": ({ "south", "east" }),
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
                ]),
                "doors": ({ "west" }),
                "entry for": ({ "south", "west" })
            ]),
        }),
        "decorators": ({ })
    ]),
    "guild 1": ([
        "type": "guild",
        "interior": "/lib/environment/interiors/limestone-interior-shop.c",
        "door": "/lib/environment/doors/door.c",
        "key": 0,
        "x dimension": 4,
        "y dimension": 4,
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
                ]),
                "doors": ({ "north" }),
                "entry for": ({ "north", "east" })
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
                ]),
                "doors": ({ "south", "east" }),
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
                ]),
                "doors": ({ "west" }),
                "entry for": ({ "south", "west" })
            ]),
        }),
        "decorators": ({ })
    ]),
    "inn 1": ([
        "type": "inn",
        "interior": "/lib/environment/interiors/wood-interior-shop.c",
        "door": "/lib/environment/doors/door.c",
        "key": 0,
        "x dimension": 4,
        "y dimension": 4,
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
                ]),
                "doors": ({ "north" }),
                "entry for": ({ "north", "east" })
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
                ]),
                "doors": ({ "south", "east" }),
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
                ]),
                "doors": ({ "west" }),
                "entry for": ({ "south", "west" })
            ]),
        }),
        "decorators": ({ })
    ]),
    "trade 1": ([
        "type": "trade",
        "interior": "/lib/environment/interiors/wood-interior-shop.c",
        "door": "/lib/environment/doors/door.c",
        "key": 0,
        "x dimension": 4,
        "y dimension": 4,
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
                ]),
                "doors": ({ "north" }),
                "entry for": ({ "north", "east" })
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
                ]),
                "doors": ({ "south", "east" }),
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
                ]),
                "doors": ({ "west" }),
                "entry for": ({ "south", "west" })
            ]),
        }),
        "decorators": ({ })
    ]),
    "church 1": ([
        "type": "church",
        "interior": "/lib/environment/interiors/wood-interior-shop.c",
        "door": "/lib/environment/doors/door.c",
        "key": 0,
        "x dimension": 4,
        "y dimension": 4,
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
                ]),
                "doors": ({ "north" }),
                "entry for": ({ "north", "east" })
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
                ]),
                "doors": ({ "south", "east" }),
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
                ]),
                "doors": ({ "west" }),
                "entry for": ({ "south", "west" })
            ]),
        }),
        "decorators": ({ })
    ]),
    "stable 1": ([
        "type": "stable",
        "interior": "/lib/environment/interiors/wood-interior-shop.c",
        "door": "/lib/environment/doors/door.c",
        "key": 0,
        "x dimension": 4,
        "y dimension": 4,
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
                ]),
                "doors": ({ "north" }),
                "entry for": ({ "north", "east" })
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
                ]),
                "doors": ({ "south", "east" }),
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
                ]),
                "doors": ({ "west" }),
                "entry for": ({ "south", "west" })
            ]),
        }),
        "decorators": ({ })
    ]),

]);

#endif
