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
            "white-tail deer": 100,
            "mule deer": 35,
            "moose": 25,
            "red fox": 25,
            "gray fox": 25,
            "kit fox": 25,
            "coyote": 75,
            "boar": 50,
            "black bear": 45,
            "brown bear": 25,
            "timber wolf": 50,
            "gray wolf": 20,
            "red wolf": 25,
            "panther": 10,
            "mountain lion": 10,
            "wolverine": 10,
            "ruffian": 250,
            "outlaw": 150,
            "hunter": 75,
            "keeper of the night": 50,
            "knight of the storm": 35,
            "zombie": 50,
            "skeleton": 50,
            "undead": 1,
            "warg": 40,
            "dragon": 1,
            "creature": 1,
        ])
    ]),
    "keeper's temple":([
        "terrain": "/lib/environment/terrain/keepers-temple.c",
        "potential features": ([ ]),
        "potential items": ([ ]),
        "potential objects": ({ }),
        "potential encounters": ([
            "keeper of the night": 75,
            "zombie": 40,
            "skeleton": 40
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
