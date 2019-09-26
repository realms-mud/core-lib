//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef settlements_h
#define settlements_h

private mapping Settlements = ([ 
    "settlement 1":([
        "type": "forest",
        "terrain": "forest-clearing",
        "x dimension": 4,
        "y dimension": 3,
        "size": 12,
        "layout": ([
            0:([
                0: ([ 
                    "type": "building", 
                    "path": "buildings/shops/blacksmith.c",
                    "exits": ([ 
                        "north": ({ 0, 1 }) 
                    ])
                ]),
                1: ([ 
                    "type": "path", 
                    "path": "features/paths/road.c",
                    "exits": ([ 
                        "south": ({ 0, 0 }), 
                        "north" : ({ 2, 0 }),
                        "east": ({ 1, 1 })
                    ]),
                    "buildings": ([
                        "north": "buildings/shops/general-shop.c",
                        "south": "buildings/shops/blacksmith.c"
                    ]),
                ]),
                2: ([ 
                    "type": "building", 
                    "path": "buildings/shops/general-shop.c",
                    "exits": ([ 
                        "south": ({ 0, 1 }), 
                    ])
                ]),
            ]),
            1:([
                0: ([ 
                    "type": "building", 
                    "path": "buildings/trades/guild-hall.c",
                    "exits": ([ 
                        "north" : ({ 1, 1 }),
                    ])
                ]),
                1: ([ 
                    "type": "path", 
                    "path": "features/paths/road.c",
                    "exits": ([ 
                        "south": ({ 1, 0 }), 
                        "north" : ({ 1, 2 }),
                        "east": ({ 2, 1 }),
                        "west": ({ 0, 1 })
                    ]),
                    "buildings": ([
                        "north": "buildings/shops/inn.c",
                        "south": "buildings/shops/guild-hall.c"
                    ]),
                ]),
                2: ([ 
                    "type": "building", 
                    "path": "buildings/shops/inn.c",
                    "exits": ([ 
                        "south": ({ 1, 1 }), 
                    ])
                ]),
            ]),
            2:([
                0: ([ 
                    "type": "building", 
                    "path": "buildings/trades/lumber-mill.c",
                    "exits": ([ 
                        "north" : ({ 2, 1 }),
                    ])
                ]),
                1: ([ 
                    "type": "path", 
                    "path": "features/paths/road.c",
                    "exits": ([ 
                        "south": ({ 2, 0 }), 
                        "north" : ({ 2, 2 }),
                        "east": ({ 3, 1 }),
                        "west": ({ 1, 1 })
                    ]),
                    "buildings": ([
                        "south": "buildings/shops/lumber-mill.c"
                    ]),
                ]),
                2: ([ 
                    "type": "path", 
                    "path": "features/paths/road.c",
                    "exits": ([ 
                        "south": ({ 2, 1 }), 
                    ]),
                    "buildings": ([
                        "east": "buildings/shops/stable.c",
                        "west": "buildings/shops/inn.c"
                    ]),
                ]),
            ]),
            3:([
                0: ([ 
                    "type": "building", 
                    "path": "buildings/religious/church.c",
                    "exits": ([ 
                        "north" : ({ 3, 1 }),
                    ])
                ]),
                1: ([ 
                    "type": "path", 
                    "path": "features/paths/road.c",
                    "exits": ([ 
                        "south": ({ 3, 0 }), 
                        "north" : ({ 3, 2 }),
                        "west": ({ 2, 1 })
                    ]),
                    "buildings": ([
                        "north": "buildings/shops/stable.c",
                        "south": "buildings/shops/church.c"
                    ]),
                ]),
                2: ([ 
                    "type": "building", 
                    "path": "buildings/trades/stable.c",
                    "exits": ([ 
                        "south": ({ 3, 1 }), 
                    ]),
                ]),
            ]),
        ]),
    ]),
    "settlement 2":([
        "type": "forest",
        "terrain": "forest-clearing",
        "x dimension": 4,
        "y dimension": 3,
        "size": 12,
        "layout": ([
            0:([
                0: ([ 
                    "type": "building", 
                    "path": "buildings/shops/swordsmith.c",
                    "exits": ([ 
                        "north": ({ 0, 1 }) 
                    ])
                ]),
                1: ([ 
                    "type": "path", 
                    "path": "features/paths/road.c",
                    "exits": ([ 
                        "south": ({ 0, 0 }), 
                        "north" : ({ 2, 0 }),
                        "east": ({ 1, 1 })
                    ]),
                    "buildings": ([
                        "north": "buildings/shops/general-shop.c",
                        "south": "buildings/shops/swordsmith.c"
                    ]),
                ]),
                2: ([ 
                    "type": "building", 
                    "path": "buildings/shops/general-shop.c",
                    "exits": ([ 
                        "south": ({ 0, 1 }), 
                    ])
                ]),
            ]),
            1:([
                0: ([ 
                    "type": "building", 
                    "path": "buildings/trades/guild-hall.c",
                    "exits": ([ 
                        "north" : ({ 1, 1 }),
                    ])
                ]),
                1: ([ 
                    "type": "path", 
                    "path": "features/paths/road.c",
                    "exits": ([ 
                        "south": ({ 1, 0 }), 
                        "north" : ({ 1, 2 }),
                        "east": ({ 2, 1 }),
                        "west": ({ 0, 1 })
                    ]),
                    "buildings": ([
                        "north": "buildings/shops/inn.c",
                        "south": "buildings/shops/guild-hall.c"
                    ]),
                ]),
                2: ([ 
                    "type": "building", 
                    "path": "buildings/shops/inn.c",
                    "exits": ([ 
                        "south": ({ 1, 1 }), 
                    ])
                ]),
            ]),
            2:([
                0: ([ 
                    "type": "building", 
                    "path": "buildings/trades/lumber-mill.c",
                    "exits": ([ 
                        "north" : ({ 2, 1 }),
                    ])
                ]),
                1: ([ 
                    "type": "path", 
                    "path": "features/paths/road.c",
                    "exits": ([ 
                        "south": ({ 2, 0 }), 
                        "north" : ({ 2, 2 }),
                        "east": ({ 3, 1 }),
                        "west": ({ 1, 1 })
                    ]),
                    "buildings": ([
                        "south": "buildings/shops/lumber-mill.c"
                    ]),
                ]),
                2: ([ 
                    "type": "path", 
                    "path": "features/paths/road.c",
                    "exits": ([ 
                        "south": ({ 2, 1 }), 
                    ]),
                    "buildings": ([
                        "east": "buildings/shops/stable.c",
                        "west": "buildings/shops/inn.c"
                    ]),
                ]),
            ]),
            3:([
                0: ([ 
                    "type": "building", 
                    "path": "buildings/religious/church.c",
                    "exits": ([ 
                        "north" : ({ 3, 1 }),
                    ])
                ]),
                1: ([ 
                    "type": "path", 
                    "path": "features/paths/road.c",
                    "exits": ([ 
                        "south": ({ 3, 0 }), 
                        "north" : ({ 3, 2 }),
                        "west": ({ 2, 1 })
                    ]),
                    "buildings": ([
                        "north": "buildings/shops/stable.c",
                        "south": "buildings/shops/church.c"
                    ]),
                ]),
                2: ([ 
                    "type": "building", 
                    "path": "buildings/trades/stable.c",
                    "exits": ([ 
                        "south": ({ 3, 1 }), 
                    ]),
                ]),
            ]),
        ]),
    ]),
    "settlement 3":([
        "type": "forest",
        "terrain": "forest-clearing",
        "x dimension": 3,
        "y dimension": 3,
        "size": 9,
        "layout": ([
            0:([
                0: ([ 
                    "type": "building", 
                    "path": "buildings/shops/blacksmith.c",
                    "exits": ([ 
                        "north": ({ 0, 1 }) 
                    ])
                ]),
                1: ([ 
                    "type": "path", 
                    "path": "features/paths/road.c",
                    "exits": ([ 
                        "south": ({ 0, 0 }), 
                        "north" : ({ 2, 0 }),
                        "east": ({ 1, 1 })
                    ]),
                    "buildings": ([
                        "north": "buildings/shops/general-shop.c",
                        "south": "buildings/shops/blacksmith.c"
                    ]),
                ]),
                2: ([ 
                    "type": "building", 
                    "path": "buildings/shops/general-shop.c",
                    "exits": ([ 
                        "south": ({ 0, 1 }), 
                    ])
                ]),
            ]),
            1:([
                0: ([ 
                    "type": "building", 
                    "path": "buildings/trades/inn.c",
                    "exits": ([ 
                        "north" : ({ 1, 1 }),
                    ])
                ]),
                1: ([ 
                    "type": "path", 
                    "path": "features/paths/road.c",
                    "exits": ([ 
                        "south": ({ 1, 0 }), 
                        "north" : ({ 1, 2 }),
                        "east": ({ 2, 1 }),
                        "west": ({ 0, 1 })
                    ]),
                    "buildings": ([
                        "east": "buildings/religious/church.c",
                        "south": "buildings/shops/inn.c"
                    ]),
                ]),
                2: ([ 
                    "type": "path", 
                    "path": "features/paths/road.c",
                    "exits": ([ 
                        "south": ({ 1, 1 }),
                        "east": ({ 2, 1 }),
                    ]),
                    "buildings": ([
                        "west": "buildings/shops/general-shop.c",
                        "east": "buildings/shops/stable.c"
                    ]),
                ]),
            ]),
            2:([
                0: ([ 
                    "type": "none", 
                ]),
                1: ([ 
                    "type": "building", 
                    "path": "buildings/religious/church.c",
                    "exits": ([ 
                        "west": ({ 1, 1 }), 
                    ]),
                ]),
                2: ([ 
                    "type": "building", 
                    "path": "buildings/trades/stable.c",
                    "exits": ([ 
                        "west" : ({ 1, 2 }),
                    ])
                ]),
            ]),
        ]),
    ]),
]);

#endif
