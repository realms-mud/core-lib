//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef regionTypes_h
#define regionTypes_h

#include "/lib//dictionaries/regions/trees.h"

protected mapping RegionTypes = ([
    "forest":([
        "terrain": "/lib/environment/terrain/forest.c",
        "potential features": Trees,
        "potential items": ([ ]),
        "potential objects": ({ }),
        "potential encounters": ([
            "deer": 100,
            "coyote": 75,
            "boar": 50,
            "bear": 45,
            "wolf": 50,
            "panther": 10,
            "mountain lion": 10,
            "wolverine": 10,
            "ruffian": 200,
            "outlaw": 100,
            "hunter": 75,
            "keeper of the night": 50,
            "knight of the storm": 35,
            "zombie": 40,
            "skeleton": 40,
            "undead": 1,
            "warg": 40,
            "dragon": 1,
            "creature": 1,
        ])
    ]),

    "hilly forest":([

    ]),
    "mountainous forest":([

    ]),

    "city":([

    ]),

    "rural":([

    ]),

    "hilly rural":([

    ]),

    "forest village":([

    ]),

    "riverside village":([

    ]),

    "riverside city":([

    ]),

    "riverside forest":([

    ]),

    "rocky lakeside forest":([

    ]),

    "sandy lakeside forest":([

    ]),

    "rocky lakeside":([

    ]),

    "sandy lakeside":([

    ]),

    "lakeside village":([

    ]),

    "lakeside city":([

    ]),

    "desert":([

    ]),

    "desert oasis":([

    ]),

    "plains":([

    ]),

    "hilly plains":([

    ]),

    "swamp":([

    ]),

    "mountains":([

    ]),

    "rocky shoreline":([

    ]),

    "tundra":([

    ]),

    "crypt":([

    ]),

    "dry cavern":([

    ]),

    "wet cavern":([

    ]),

    "ice":([

    ]),

    "dungeon":([

    ]),

    "mine":([

    ]),

    "keep":([

    ]),

    "palace":([

    ]),

    "castle":([

    ]),

    "dwarven mines":([

    ]),

    "dwarven keep":([

    ]),

    "elvish forest":([

    ]),

    "wasteland":([

    ]),

]);

#endif
