//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef regionTypes_h
#define regionTypes_h

#include "/lib//dictionaries/regions/terrain.h"
#include "/lib//dictionaries/regions/trees.h"

protected mapping RegionTypes = ([
    "forest": ([
        "terrain": "/lib/environment/terrain/forest.c",
        "path type": "/lib/environment/features/paths/path.c",
        "potential features": Trees + Terrain,
        "potential items": ([ ]),
        "potential objects": ({ }),
        "settlement chance": 15,
        "settlement size": 12,
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
        "terrain": "/lib/environment/terrain/forest-hill.c",
        "potential features": Trees + Terrain,
        "path type": "/lib/environment/features/paths/path.c",
        "potential items": ([ ]),
        "potential objects": ({ }),
        "settlement chance": 15,
        "settlement size": 12,
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
    "mountainous forest":([
        "terrain": "/lib/environment/terrain/forest-mountain.c",
        "potential features": Trees + Terrain,
        "path type": "/lib/environment/features/paths/path.c",
        "potential items": ([ ]),
        "potential objects": ({ }),
        "settlement chance": 15,
        "settlement size": 12,
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

    "city":([
        "terrain":"/lib/environment/terrain/city.c",
        "potential features" : ([]),
        "path type" : "/lib/environment/features/paths/road.c",
        "potential items" : ([]),
        "potential objects" : ({ }),
        "settlement chance" : 0,
        "settlement size" : 0,
        "potential encounters" : ([
        ])
    ]),

    "rural":([
        "terrain":"/lib/environment/terrain/farmland.c",
        "potential features" : ([]),
        "path type" : "/lib/environment/features/paths/road.c",
        "potential items" : ([]),
        "potential objects" : ({ }),
        "settlement chance" : 0,
        "settlement size" : 0,
        "potential encounters" : ([
        ])
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
        "interior": "/lib/environment/interiors/crypt.c",
        "potential features": ([ ]),
        "potential items": ([ ]),
        "potential objects": ({ }),
        "settlement chance": 0,
        "settlement size": 0,
        "potential encounters": ([
            "ghoul": 20,
            "ghast": 15,
            "lich": 1,
            "mohrg": 10,
            "mummy": 8,
            "rat": 5,
            "shadow": 10,
            "skeleton": 100,
            "spectre": 35,
            "giant spider": 5,
            "vampire": 5,
            "wight": 25,
            "zombie": 75,
            "wraith": 6,
            "dracolich": 1,
            "keeper of the night": 5,
        ])
    ]),

    "dry cavern":([

    ]),

    "wet cavern":([

    ]),

    "ice":([

    ]),

    "dungeon": ([

    ]),

    "mine":([

    ]),

    "limestone building":([
        "interior": "/lib/environment/interiors/limestone-interior-shop.c",
        "potential features": ([ ]),
        "potential items": ([ "lighting": ([ "window": 10, ]) ]),
        "potential objects": ({ }),
        "settlement chance": 0,
        "settlement size": 0,
        "potential encounters": ([ ])
    ]),

    "granite building":([
        "interior": "/lib/environment/interiors/grainte-interior-shop.c",
        "potential features": ([ ]),
        "potential items": ([ "lighting": ([ "window": 10, ]) ]),
        "potential objects": ({ }),
        "settlement chance": 0,
        "settlement size": 0,
        "potential encounters": ([ ])
    ]),

    "brick building":([
        "interior": "/lib/environment/interiors/brick-interior-shop.c",
        "potential features": ([ ]),
        "potential items": ([ "lighting": ([ "window": 10, ]) ]),
        "potential objects": ({ }),
        "settlement chance": 0,
        "settlement size": 0,
        "potential encounters": ([ ])
    ]),

    "wooden building":([
        "interior": "/lib/environment/interiors/wooden-interior-shop.c",
        "potential features": ([ ]),
        "potential items": ([ "lighting": ([ "window": 10, ]) ]),
        "potential objects": ({ }),
        "settlement chance": 0,
        "settlement size": 0,
        "potential encounters": ([ ])
    ]),

    "opulent building":([
        "interior": "/lib/environment/interiors/opulent-shop.c",
        "potential features": ([ ]),
        "potential items": ([ "lighting": ([ "window": 10, ]) ]),
        "potential objects": ({ }),
        "settlement chance": 0,
        "settlement size": 0,
        "potential encounters": ([ ])
    ]),

    "stone keep":([

    ]),

    "wooden keep":([

    ]),

    "palace":([

    ]),

    "stone castle":([

    ]),

    "wooden castle":([

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
