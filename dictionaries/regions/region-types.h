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
            "deer": 15,
            "coyote": 10,
            "boar": 10,
            "bear": 5,
            "wolf": 5,
            "panther": 2,
            "mountain lion": 2,
            "wolverine": 1,
            "ruffian": 10,
            "hunter": 10,
            "keeper of the night": 10,
            "knight of the storm": 5,
            "zombie": 5,
            "skeleton": 5,
            "warg": 5,
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
